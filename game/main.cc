#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "player.h"
#include "textdisplay.h"
#include "exception.h"
using namespace std;

int main(int argc, char const *argv[]){
	// command line arguments
	bool initState = false;
	bool testingState = false;
	bool graphicsState = false;
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
	
	// create players and textdisplay
	vector<Player *> players;
	TextDisplay td{};
	players.emplace_back(new Player{playername1, 1});
	players.emplace_back(new Player{playername2, 2});
	players[0]->attach(&td);
	players[1]->attach(&td);
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

	// load hand
	for(int i = 0; i < 5; i++){
		players[0]->drawcard();
		players[1]->drawcard();
	}

	// start player1's turn
	cout << "Player " << players[currentPlayer]->getplayerNum() << "'s turn!"<< endl;
	players[currentPlayer]->gainMagic();
	td.displayMagic(players[currentPlayer]);
	td.displayHand(players[currentPlayer]);

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
			currentPlayer = (currentPlayer == 0) ? 1 : 0;
			nextPlayer = (nextPlayer == 0) ? 1 : 0;

			// start next player's turn
			cout << "Player" << players[currentPlayer]->getplayerNum() << "'s turn!"<< endl;
			players[currentPlayer]->gainMagic();
			try {
				players[currentPlayer]->drawcard();
			} 
			catch(ExceedMaximum &e){}
			td.displayMagic(players[currentPlayer]);
			td.displayHand(players[currentPlayer]);
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
				td.displayHand(players[currentPlayer]);
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
					players[currentPlayer]->attack(i, players[nextPlayer]);
				}
				catch(InvalidPosition &e){
					cerr << e.getErrorMessage() << endl;
				}
			} else {
				try{
					players[currentPlayer]->attack(i, players[nextPlayer], j);
				}
				catch(InvalidPosition &e){
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
					players[currentPlayer]->play(i);
					td.displayMagic(players[currentPlayer]);
					td.displayHand(players[currentPlayer]);
				}
				catch(InvalidPosition &e){
					cerr << e.getErrorMessage() << endl;
				}
			} 
			// else {
			// 	if(scmd >> t){
			// 		// play enchantment, spell on minion
			// 		players[currentPlayer]->play(i, players[currentPlayer], t);
			// 	} else {
			// 		// play enchantment, spell on ritual
			// 		players[currentPlayer]->play(i, players[currentPlayer]);
			// 	}
			// }
		} 
		else if (cmd == "use"){
			// int i, p, t;
			// scmd >> i;
			// if(!(scmd >> p)){
			// 	// use i: use minion
			// 	players[currentPlayer]->use(i);
			// } else {
			// 	if(scmd >> t){
			// 		// use i p t: use minion on minion
			// 		players[currentPlayer]->use(i, players[currentPlayer], t);
			// 	} else {
			// 		// use i p r: use minion on ritual
			// 		players[currentPlayer]->use(i, players[currentPlayer]);
			// 	}
			// }
		} 
		// inspect i: display minion i
		else if (cmd == "inspect"){
			int i;
			scmd >> i;
			try{
				td.inspectCard(players[currentPlayer], i);
			}
			catch(InvalidPosition &e){
				cerr << e.getErrorMessage() << endl;
			}
		} 
		// hand: display hand
		else if (cmd == "hand"){
			td.displayHand(players[currentPlayer]);
		} 
		// board: display board
		else if (cmd == "board"){
			td.displayBoard();
		}
	}
	return 0;
}
