#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <ctime>
#include "player.h"
#include "display.h"
#include "textdisplay.h"
#include "graphicdisplay.h"
#include "exception.h"
using namespace std;

int myrandom (int i) {
	return std::rand()%i;
}

int main(int argc, char const *argv[]){
	// command line arguments
	bool initState = false;
	bool testingState = false;
	bool graphicsState = false;
	bool textsState = true;
	bool deck1State = false;
	bool deck2State = false;
	ifstream initfile;
	ifstream deck1file;
	ifstream deck2file;

	// command line argument
	for(int i = 1; i < argc; i++){
		if(string(argv[i]) == "-init") {
			initState = true;
			initfile.open(argv[i + 1]);
			i += 1; // skip the next argument
		} else if(string(argv[i]) == "-testing"){
			testingState = true;
		} else if(string(argv[i]) == "-graphics"){
			graphicsState = true;
		} else if(string(argv[i]) == "-deck1"){
			deck1State = true;
			deck1file.open(argv[i + 1]);
			i += 1; // skip the next argument
		} else if(string(argv[i]) == "-deck2"){
			deck2State = true;
			deck2file.open(argv[i + 1]);
			i += 1; // skip the next argument
		} else if(string(argv[i]) == "-disabletext"){
			textsState = false;
		}
	}

	string playername1;
	string playername2;
	string cmd;

	cout << "Welcome to Sorcery!" << endl;

	// read in player names
	cout << "Player 1: ";
	if(initState && initfile >> playername1){
		cout << playername1 << endl;
	} else {
		cin >> playername1;
	}
	cout << "Player 2: ";
	if(initState && initfile >> playername1){
		cout << playername2 << endl;
	} else {
		cin >> playername2;
	}
	
	// create players and displays
	vector<shared_ptr<Player>> players;
	vector<shared_ptr<outputDisplay>> displays;

	shared_ptr<Player> p1 = make_shared<Player>(playername1, 1);
	shared_ptr<Player> p2 = make_shared<Player>(playername2, 2);
	players.emplace_back(p1);
	players.emplace_back(p2);
	
	if(textsState){
		shared_ptr<TextDisplay> td = make_shared<TextDisplay>();
		displays.emplace_back(td);
	}

	if(graphicsState){
		shared_ptr<GraphicDisplay> gd = make_shared<GraphicDisplay>();
		displays.emplace_back(gd);
	}

	for(int i = 0; i < displays.size(); i++){
		players[0]->attach(displays[i].get());
		players[1]->attach(displays[i].get());
	}

	players[0]->notifyObservers();
	players[1]->notifyObservers();
	int currentPlayer = 0;
	int nextPlayer = 1;

	// load card
	if(!deck1State) deck1file.open("default.deck");
	if(!deck2State) deck2file.open("default.deck");

	string card;
	while(getline(deck1file, card)){
		players[0]->loadDeck(card);
	}
	while(getline(deck2file, card)){
		players[1]->loadDeck(card);
	}

	if (!testingState){
		std::srand(unsigned (std::time(0)));
		std::random_shuffle(players[0]->getdeck().begin(), players[0]->getdeck().end(), myrandom);
		std::random_shuffle(players[1]->getdeck().begin(), players[1]->getdeck().end(), myrandom);
	}
	
	// load hand
	for(int i = 0; i < 5; i++){
		players[0]->drawcard();
		players[1]->drawcard();
	}
	
	// start player1's turn
	cout << "Player " << players[currentPlayer]->getplayerNum() << "'s turn!"<< endl;
	players[currentPlayer]->gainMagic();
	for(int i = 0; i < displays.size(); i++){
		displays[i]->displayBoard();
		displays[i]->displayMagic(players[currentPlayer].get());
		displays[i]->displayHand(players[currentPlayer].get());
	}

	// enter game loop, change cin >> cmd to getline
	while (true){
		if (!(getline(initfile, cmd))){
			getline(cin, cmd);
		}
		istringstream scmd{cmd};
		scmd >> cmd;

		// display help message
		if (cmd == "help"){
			ifstream helpfile{"help.txt"};
			string s;
			while(getline(helpfile, s)){
				cout << s << endl;
			}
		} 
		// end current player's turn
		else if (cmd == "end"){
			players[currentPlayer]->trigger(GameStage::endTurn, nullptr, players[nextPlayer].get());
			currentPlayer = (currentPlayer == 0) ? 1 : 0;
			nextPlayer = (nextPlayer == 0) ? 1 : 0;

			// start next player's turn
			cout << "Player" << players[currentPlayer]->getplayerNum() << "'s turn!"<< endl;
			players[currentPlayer]->gainMagic();
			players[currentPlayer]->gainaction();
			try {
				players[currentPlayer]->drawcard();
			} 
			catch(ExceedMaximum &e){}
			players[currentPlayer]->trigger(GameStage::startTurn, nullptr, players[nextPlayer].get());
			for(int i = 0; i < displays.size(); i++){
				displays[i]->displayBoard();
				displays[i]->displayMagic(players[currentPlayer].get());
				displays[i]->displayHand(players[currentPlayer].get());
			}
		} 
		// end game
		else if (cmd == "quit"){
			cout << "Bye!" << endl;
			// delete anything if needed
			return 0;
		} 
		// draw a card
		else if (cmd == "draw" && testingState == true){
			try {
				players[currentPlayer]->drawcard();
				for(int i = 0; i < displays.size(); i++){
					displays[i]->displayHand(players[currentPlayer].get());
				}
			} 
			catch(ExceedMaximum &e){
				cerr << e.getErrorMessage() << endl;
			}
		} 
		// disgard i: disgard the ith card in hand
		else if (cmd == "disgard" && testingState == true){
			// only available in testing mode

		} 
		// attack i: minion i to attack opposing player
		// attack i j: minion i to attact opposing player's minion j
		else if (cmd == "attack"){ 
			int i,j;
			scmd >> i;
			if(!(scmd >> j)){ 
				try{
					players[currentPlayer]->attack(i, players[nextPlayer].get());
					for(int i = 0; i < displays.size(); i++){
						displays[i]->displayBoard();
						displays[i]->displayMagic(players[currentPlayer].get());
						displays[i]->displayHand(players[currentPlayer].get());
					}
				}
				catch(InvalidPosition &e){
					cerr << e.getErrorMessage() << endl;
				}
				catch(InvalidMove &e){
					cerr << e.getErrorMessage() << endl;
				}
			} else {
				try{
					players[currentPlayer]->attack(i, players[nextPlayer].get(), j);
					for(int i = 0; i < displays.size(); i++){
						displays[i]->displayBoard();
						displays[i]->displayMagic(players[currentPlayer].get());
						displays[i]->displayHand(players[currentPlayer].get());
					}
				}
				catch(InvalidPosition &e){
					cerr << e.getErrorMessage() << endl;
				}
				catch(InvalidMove &e){
					cerr << e.getErrorMessage() << endl;
				}
			}
		} 
		else if (cmd == "play"){
			int i, p, t;
			scmd >> i;
			if(!(scmd >> p)){
				// play i: play minion, ritual, spell with no target
				try{
					players[currentPlayer]->play(i, players[nextPlayer].get(), testingState);
					for(int i = 0; i < displays.size(); i++){
						displays[i]->displayBoard();
						displays[i]->displayMagic(players[currentPlayer].get());
						displays[i]->displayHand(players[currentPlayer].get());
					}
				}
				catch(InvalidPosition &e){
					cerr << e.getErrorMessage() << endl;
				}
				catch(InvalidMove &e){
					cerr << e.getErrorMessage() << endl;
				}
			} 
			else {
				if(scmd >> t){
					// play i p t: play enchantment, spell on minion
					if(p == players[currentPlayer]->getplayerNum()){
						try {
							players[currentPlayer]->play(i, players[nextPlayer].get(), t, true, testingState);
							for(int i = 0; i < displays.size(); i++){
								displays[i]->displayBoard();
								displays[i]->displayMagic(players[currentPlayer].get());
								displays[i]->displayHand(players[currentPlayer].get());
							}
						}
						catch(InvalidPosition &e){
							cerr << e.getErrorMessage() << endl;
						}
						catch(InvalidMove &e){
							cerr << e.getErrorMessage() << endl;
						}
					} else {
						try {
							players[currentPlayer]->play(i, players[nextPlayer].get(), t, false, testingState);
							for(int i = 0; i < displays.size(); i++){
								displays[i]->displayBoard();
								displays[i]->displayMagic(players[currentPlayer].get());
								displays[i]->displayHand(players[currentPlayer].get());
							}
						}
						catch(InvalidPosition &e){
							cerr << e.getErrorMessage() << endl;
						}
						catch(InvalidMove &e){
							cerr << e.getErrorMessage() << endl;
						}
					}
				} else {
					// play i p r: play enchantment, spell on ritual
					if(p == players[currentPlayer]->getplayerNum()){
						try {
							players[currentPlayer]->play(i, players[nextPlayer].get(), true, true, testingState);
							for(int i = 0; i < displays.size(); i++){
								displays[i]->displayBoard();
								displays[i]->displayMagic(players[currentPlayer].get());
								displays[i]->displayHand(players[currentPlayer].get());
							}
						}
						catch(InvalidPosition &e){
							cerr << e.getErrorMessage() << endl;
						}
						catch(InvalidMove &e){
							cerr << e.getErrorMessage() << endl;
						}
					} else {
						try {
							players[currentPlayer]->play(i, players[nextPlayer].get(), false, true, testingState);
							for(int i = 0; i < displays.size(); i++){
								displays[i]->displayBoard();
								displays[i]->displayMagic(players[currentPlayer].get());
								displays[i]->displayHand(players[currentPlayer].get());
							}
						}
						catch(InvalidPosition &e){
							cerr << e.getErrorMessage() << endl;
						}
						catch(InvalidMove &e){
							cerr << e.getErrorMessage() << endl;
						}
					}
				}
			}
		} 
		else if (cmd == "use"){
			int i, p, t;
			scmd >> i;
			if(!(scmd >> p)){
				// use i: use minion
				if(p == players[currentPlayer]->getplayerNum()){
						try {
							players[currentPlayer]->use(i, players[nextPlayer].get(), testingState);
						}
						catch(InvalidPosition &e){
							cerr << e.getErrorMessage() << endl;
						}
						catch(InvalidMove &e){
							cerr << e.getErrorMessage() << endl;
						}
						catch(ExceedMaximum &e){
							cerr << e.getErrorMessage() << endl;
						}
					} else {
						try {
							players[currentPlayer]->use(i, players[nextPlayer].get(), testingState);
						}
						catch(InvalidPosition &e){
							cerr << e.getErrorMessage() << endl;
						}
						catch(InvalidMove &e){
							cerr << e.getErrorMessage() << endl;
						}
						catch(ExceedMaximum &e){
							cerr << e.getErrorMessage() << endl;
						}
					}
			} else {
				scmd >> t;
				// use i p t: use minion on minion
				if(p == players[currentPlayer]->getplayerNum()){
						try {
							players[currentPlayer]->use(i, players[nextPlayer].get(), t, true, testingState);
						}
						catch(InvalidPosition &e){
							cerr << e.getErrorMessage() << endl;
						}
						catch(InvalidMove &e){
							cerr << e.getErrorMessage() << endl;
						}
					} else {
						try {
							players[currentPlayer]->use(i, players[nextPlayer].get(), t, false, testingState);
						}
						catch(InvalidPosition &e){
							cerr << e.getErrorMessage() << endl;
						}
						catch(InvalidMove &e){
							cerr << e.getErrorMessage() << endl;
						}
					}
			}
		} 
		// inspect i: display minion i
		else if (cmd == "inspect"){
			int i;
			scmd >> i;
			try{
				for(int i = 0; i < displays.size(); i++){
					displays[i]->inspectCard(players[currentPlayer].get(), i);
				}
			}
			catch(InvalidPosition &e){
				cerr << e.getErrorMessage() << endl;
			}
		} 
		// hand: display hand
		else if (cmd == "hand"){
			for(int i = 0; i < displays.size(); i++){
				displays[i]->displayHand(players[currentPlayer].get());
			}
		} 
		// board: display board
		else if (cmd == "board"){
			for(int i = 0; i < displays.size(); i++){
				displays[i]->displayBoard();
			}
		}
		if (players[0]->die() && !(players[1]->die())){
			for(int i = 0; i < displays.size(); i++){
				displays[i]->endgame(players[1].get());
			}
		} else if (players[1]->die() && !(players[0]->die())){
			for(int i = 0; i < displays.size(); i++){
				displays[i]->endgame(players[0].get());
			}
		} else if (players[1]->die() && players[0]->die()){
			// for(int i = 0; i < displays.size(); i++){
			// 	displays[i]->tie();
			// }
		}
	}
	return 0;
}
