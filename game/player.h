#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include "subject.h"
#include "ascii_graphics.h"

// declaration
class Card;

class Player : public Subject {
	std::string playerName;
	int playerNum;
	int life;
	int magic;
	std::vector<std::shared_ptr<Card>> deck;
	std::vector<std::shared_ptr<Card>> hand;
	std::vector<std::shared_ptr<Card>> minionslot;
	std::vector<std::shared_ptr<Card>> graveyard;
	std::shared_ptr<Card> activeRitual;
	std::vector<std::string> playerCard;

public:
	Player(std::string playerName, int playerNum);
	// ~Player();

	int getplayerNum();
	int getlife();
	int getmagic();
	std::vector<std::shared_ptr<Card>> & getdeck();
	std::vector<std::shared_ptr<Card>> & gethand();
	std::vector<std::shared_ptr<Card>> & getminionslot();
	std::vector<std::shared_ptr<Card>> & getgraveyard();
	std::shared_ptr<Card> getactiveRitual();
	std::vector<std::string> getplayerCard();

	// void drawcard(); // draws a card from deck, add to hand, check if hand is full
	// void disgard(int i); // erase ith card in hand
	// void attack(int i, Player * p); // use minion i to attack player
	// void attack(int i, Player * p, int j); // use minion i to attack minion j
	// void play(int i); // play the ith card, minion, ritual, spell
	// void play(int i, Player * p); // play the ith card on player p's ritual
	// void play(int i, Player * p, int t); // play the ith card on on player p's minion t
	// void use(int i); // use minion i
	// void use(int i, Player * p); // use minion i on player p's ritual
	// void use(int i, Player * p, int t); // use minion i on player p's minion t

	// bool die();
	// void gainMagic();
	void loadDeck(std::string card);
	// void beAttacked(int damage);
	
	// notify?

	// for inspect i, displayHand
	// friend std::ostream &operator<<(std::ostream &out, const Card * c);

	// void displayBoard();
};

#endif
