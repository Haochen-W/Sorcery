#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <ctime>
#include <memory>
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
	bool heroState = true;
	bool notfirst = false;
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
		} else if(string(argv[i]) == "-disableheropower"){
			heroState = false;
		} else {
			cerr << "Invalid command line argument entered" << endl;
			return 1;
		}
	}

	string playername1;
	string playername2;
	string hero1 = "Sorcery";
	string hero2 = "Sorcery";
	string cmd;
	char c;

	cout << "Welcome to Sorcery!" << endl;

	// read in player names
	cout << "Player 1: ";
	if(initState && initfile >> playername1){
		cout << playername1 << endl;
	} else {
		cin >> playername1;
	}

	if(heroState && testingState){
		cout << "Please choose your hero from the following list: " << endl;
		cout << "(Please enter \"Mage\", \"Hunter\", \"Paladin\", \"Warlock\", or \"Druid\")" << endl;
		ifstream herofile{"hero.txt"};
		string s;
		while(getline(herofile, s)){
			cout << s << endl;
		}

		if(initState && initfile >> hero1){
			cout << hero1 << endl;
		} else {
			cin >> hero1;
		}
	}
	// randomize heroes
	if (heroState && !(testingState)){
		std::srand(unsigned (std::time(0)));
		int rand = std::rand() % 6;
		if (rand == 0) {
			hero1 = "Mage";
			cout << "You are now a Mage. Your hero power is deal 1 damage to any target." << endl;
		} else if (rand == 1) {
			hero1 = "Hunter";
			cout << "You are now a Hunter. Your hero power is deal 2 damage to opponent player." << endl;
		} else if (rand == 2) {
			hero1 = "Paladin";
			cout << "You are now a Paladin. Your hero power is summon a 1/1 Air Elemental." << endl;
		} else if (rand == 3) {
			hero1 = "Warrior";
			cout << "You are now a Warrior. Your hero power is add 2 health to your hero." << endl;
		} else if (rand == 4) {
			hero1 = "Warlock";
			cout << "You are now a Warlock. Your hero power is draw a card and take 2 damage." << endl;
		} else if (rand == 5) {
			hero1 = "Druid";
			cout << "You are now a Druid. Your hero power is +1 attack this turn and add 1 health to your hero." << endl;
		}
	}

	cout << "Player 2: ";
	if(initState && initfile >> playername2){
		cout << playername2 << endl;
	} else {
		cin >> playername2;
	}

	if (heroState && !(testingState)){
		std::srand(unsigned (std::time(0)));
		int rand = std::rand() % 6;
		if (rand == 0) {
			hero2 = "Mage";
			cout << "You are now a Mage. Your hero power is deal 1 damage to any target." << endl;
		} else if (rand == 1) {
			hero2 = "Hunter";
			cout << "You are now a Hunter. Your hero power is deal 2 damage to opponent player." << endl;
		} else if (rand == 2) {
			hero2 = "Paladin";
			cout << "You are now a Paladin. Your hero power is summon a 1/1 Air Elemental." << endl;
		} else if (rand == 3) {
			hero2 = "Warrior";
			cout << "You are now a Warrior. Your hero power is add 2 health to your hero." << endl;
		} else if (rand == 4) {
			hero2 = "Warlock";
			cout << "You are now a Warlock. Your hero power is draw a card and take 2 damage." << endl;
		} else if (rand == 5) {
			hero2 = "Druid";
			cout << "You are now a Druid. Your hero power is +1 attack this turn and add 1 health to your hero." << endl;
		}
	}

	if(heroState && testingState){
		cout << "Please choose your hero from the following list: " << endl;
		cout << "(Please enter \"Mage\", \"Hunter\", \"Paladin\", \"Warlock\", or \"Druid\")" << endl;
		ifstream herofile{"hero.txt"};
		string s;
		while(getline(herofile, s)){
			cout << s << endl;
		}

		if(initState && initfile >> hero2){
			cout << hero2 << endl;
		} else {
			cin >> hero2;
		}
	}
	
	// create players and displays
	vector<shared_ptr<Player>> players;
	vector<shared_ptr<outputDisplay>> displays;

	shared_ptr<Player> p1 = make_shared<Player>(playername1, 1, hero1);
	shared_ptr<Player> p2 = make_shared<Player>(playername2, 2, hero2);
	players.emplace_back(p1);
	players.emplace_back(p2);
	
	// setting up graphics
	if(textsState){
		shared_ptr<TextDisplay> td = make_shared<TextDisplay>();
		displays.emplace_back(td);
	}

	if(graphicsState){
		shared_ptr<GraphicDisplay> gd = make_shared<GraphicDisplay>();
		displays.emplace_back(gd);
	}

	for(unsigned int i = 0; i < displays.size(); i++){
		players[0]->attach(displays[i].get());
		players[1]->attach(displays[i].get());
	}

	// tracking playing order
	int currentPlayer = 0;
	int nextPlayer = 0;

	// randomize playing order
	if (!testingState){
		std::srand(unsigned (std::time(0)));
		int rand = std::rand() % 2;
		if (rand == 0){
			currentPlayer = 0;
			nextPlayer = 1;
		} else {
			currentPlayer = 1;
			nextPlayer = 0;
		}
	} else {
		currentPlayer = 0;
		nextPlayer = 1;
	}
	
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

	// randomize the deck
	if (!testingState){
		std::srand(unsigned (std::time(0)));
		std::random_shuffle(players[0]->getdeck().begin(), players[0]->getdeck().end(), myrandom);
		std::random_shuffle(players[1]->getdeck().begin(), players[1]->getdeck().end(), myrandom);
	}
	
	// load hand
	for(int i = 0; i < 3; i++){
		try{
			players[0]->drawcard();
		} catch (ExceedMaximum &e){}
		try{
			players[1]->drawcard();
		} catch (ExceedMaximum &e){}
	}

	// player who plays second gets a coin
	players[nextPlayer]->gainCoin();
	
	// start first player's turn
	players[currentPlayer]->gainMagic();
	players[0]->notifyObservers();
	players[1]->notifyObservers();
	for(unsigned int i = 0; i < displays.size(); i++){
		displays[i]->displayBoard();
	}

	cout << "Player " << players[currentPlayer]->getplayerNum() << "'s turn!"<< endl;
	for(unsigned int i = 0; i < displays.size(); i++){
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
			players[currentPlayer]->initTurn();
			players[currentPlayer]->trigger(GameStage::startTurn, nullptr, players[nextPlayer].get());
			for(unsigned int i = 0; i < displays.size(); i++){
				displays[i]->displayBoard();
			}

			cout << "Player " << players[currentPlayer]->getplayerNum() << "'s turn!"<< endl;
			for(unsigned int i = 0; i < displays.size(); i++){
				displays[i]->displayMagic(players[currentPlayer].get());
				displays[i]->displayHand(players[currentPlayer].get());
			}
		} 
		// end game
		else if (cmd == "quit"){
			cout << "Bye!" << endl;
			return 0;
		} 
		// draw a card
		else if (cmd == "draw" && testingState == true){
			try {
				players[currentPlayer]->drawcard();
				for(unsigned int i = 0; i < displays.size(); i++){
					displays[i]->displayHand(players[currentPlayer].get());
				}
			} 
			catch(ExceedMaximum &e){
				cerr << e.getErrorMessage() << endl;
			}
		} 
		// discard i: discard the ith card in hand
		else if (cmd == "discard" && testingState == true){
			int i;
			scmd >> i;
			try{
				players[currentPlayer]->discard(i);
				for(unsigned int i = 0; i < displays.size(); i++){
					displays[i]->displayBoard();
					displays[i]->displayMagic(players[currentPlayer].get());
					displays[i]->displayHand(players[currentPlayer].get());
				}
			}
			catch(InvalidPosition &e){
				cerr << e.getErrorMessage() << endl;
			}
		} 
		// attack i: minion i to attack opposing player
		// attack i j: minion i to attact opposing player's minion j
		else if (cmd == "attack"){ 
			int i,j;
			scmd >> i;
			if(!(scmd >> j)){ 
				try{
					players[currentPlayer]->attack(i, players[nextPlayer].get());
					for(unsigned int i = 0; i < displays.size(); i++){
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
					for(unsigned int i = 0; i < displays.size(); i++){
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
					std::cout << "main: " << players[currentPlayer] ->getmagic() << std::endl;
					for(unsigned int i = 0; i < displays.size(); i++){
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
				catch(ExceedMaximum &e){
					cerr << e.getErrorMessage() << endl;
				}
			} 
			else {
				if(scmd >> t){
					// play i p t: play enchantment, spell on minion
					if(p == players[currentPlayer]->getplayerNum()){
						try {
							players[currentPlayer]->play(i, players[nextPlayer].get(), t, true, testingState);
							for(unsigned int i = 0; i < displays.size(); i++){
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
						catch(ExceedMaximum &e){
							cerr << e.getErrorMessage() << endl;
						}
					} else {
						try {
							players[currentPlayer]->play(i, players[nextPlayer].get(), t, false, testingState);
							for(unsigned int i = 0; i < displays.size(); i++){
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
						catch(ExceedMaximum &e){
							cerr << e.getErrorMessage() << endl;
						}
					}
				} else {
					// play i p r: play enchantment, spell on ritual
					if(p == players[currentPlayer]->getplayerNum()){
						try {
							players[currentPlayer]->playonRitual(i, players[nextPlayer].get(), true, testingState);
							for(unsigned int i = 0; i < displays.size(); i++){
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
						catch(ExceedMaximum &e){
							cerr << e.getErrorMessage() << endl;
						}
					} else {
						try {
							players[currentPlayer]->playonRitual(i, players[nextPlayer].get(), false, testingState);
							for(unsigned int i = 0; i < displays.size(); i++){
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
						catch(ExceedMaximum &e){
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
				try{
					players[currentPlayer]->use(i, players[nextPlayer].get(), testingState);
					for(unsigned int i = 0; i < displays.size(); i++){
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
				catch(ExceedMaximum &e){
					cerr << e.getErrorMessage() << endl;
				}
			} else {
				if(scmd >> t){
					// use i p t: use minion on minion
					if(p == players[currentPlayer]->getplayerNum()){
						try {
							players[currentPlayer]->use(i, players[nextPlayer].get(), t, true, testingState);
							for(unsigned int i = 0; i < displays.size(); i++){
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
						catch(ExceedMaximum &e){
							cerr << e.getErrorMessage() << endl;
						}
					} else {
						try {
							players[currentPlayer]->use(i, players[nextPlayer].get(), t, false, testingState);
							for(unsigned int i = 0; i < displays.size(); i++){
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
						catch(ExceedMaximum &e){
							cerr << e.getErrorMessage() << endl;
						}
					}
				}
			}
		} 
		// inspect i: display minion i
		else if (cmd == "inspect"){
			int i;
			scmd >> i;
			try{
				for(unsigned int k = 0; k < displays.size(); k++){
					displays[k]->inspectCard(players[currentPlayer].get(), i);
				}
			}
			catch(InvalidPosition &e){
				cerr << e.getErrorMessage() << endl;
			}
		} 
		// hand: display hand
		else if (cmd == "hand"){
			for(unsigned int i = 0; i < displays.size(); i++){
				displays[i]->displayHand(players[currentPlayer].get());
			}
		} 
		// board: display board
		else if (cmd == "board"){
			for(unsigned int i = 0; i < displays.size(); i++){
				displays[i]->displayBoard();
			}
		}
		else if (cmd == "usepower" && heroState == true) {
			int p, t;
			if(!(scmd >> p)){
				try{
					players[currentPlayer]->useHeropower(players[nextPlayer].get(), testingState);
					for(unsigned int i = 0; i < displays.size(); i++){
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
				catch(ExceedMaximum &e){
					cerr << e.getErrorMessage() << endl;
				}
			} else if(!(scmd >> t)){
				if(p == players[currentPlayer]->getplayerNum()){
					try{
						players[currentPlayer]->useHeropower(players[nextPlayer].get(), true, testingState);
						for(unsigned int i = 0; i < displays.size(); i++){
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
					catch(ExceedMaximum &e){
						cerr << e.getErrorMessage() << endl;
					}
				} else {
					try{
						players[currentPlayer]->useHeropower(players[nextPlayer].get(), false, testingState);
						for(unsigned int i = 0; i < displays.size(); i++){
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
					catch(ExceedMaximum &e){
						cerr << e.getErrorMessage() << endl;
					}
				}
			} else {
				if(p == players[currentPlayer]->getplayerNum()){
					try{
						players[currentPlayer]->useHeropower(players[nextPlayer].get(), t, true, testingState);
						for(unsigned int i = 0; i < displays.size(); i++){
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
					catch(ExceedMaximum &e){
						cerr << e.getErrorMessage() << endl;
					}
				} else {
					try{
						players[currentPlayer]->useHeropower(players[nextPlayer].get(), t, false, testingState);
						for(unsigned int i = 0; i < displays.size(); i++){
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
					catch(ExceedMaximum &e){
						cerr << e.getErrorMessage() << endl;
					}
				}
			}
		}
		else {
			if (notfirst){
				cout << "Invalid Command Entered." << endl;
				continue;
			}
			notfirst = true;
		}
		if (players[0]->die() && !(players[1]->die())){
			for(unsigned int i = 0; i < displays.size(); i++){
				displays[i]->endgame(players[1].get());
			}
			cin >> c;
			break;
		} else if (players[1]->die() && !(players[0]->die())){
			for(unsigned int i = 0; i < displays.size(); i++){
				displays[i]->endgame(players[0].get());
			}
			cin >> c;
			break;
		} else if (players[1]->die() && players[0]->die()){
			for(unsigned int i = 0; i < displays.size(); i++){
				displays[i]->tie();
			}
			cin >> c;
			break;
		}
	}
	return 0;
}
