#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include "subject.h"

// declaration
class Card;

class Player : public Subject {
	std::string playerName;
	int playerNum;
	int life;
	int magic;
	std::vector<Card *> deck;
	std::vector<Card *> hand;
	std::vector<Card *> minionslot;
	std::vector<Card *> graveyard;
	Card * activeRitual;
	std::vector<std::string> playerCard;

public:
	Player(std::string playerName, int playerNum);
	// ~Player();

	int getplayerNum() const;
	int getlife() const;
	int getmagic() const;
	std::vector<Card *> & getdeck() const;
	std::vector<Card *> & gethand() const;
	std::vector<Card *> & getminionslot() const;
	std::vector<Card *> & getgraveyard() const;
	Card * getactiveRitual() const;
	std::vector<std::string> getplayerCard() const;

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
	// void loadDeck();
	// void beAttacked(int damage);
	
	// notify?

	// for inspect i, displayHand
	// friend std::ostream &operator<<(std::ostream &out, const Card * c);

	// void displayBoard();
};

#endif
