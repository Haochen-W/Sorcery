#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>

// declaration
Class Card;

Class Player {
	std::string playerName;
	int life;
	int magic;
	std::vector<Card *> deck;
	std::vector<Card *> hand;
	std::vector<Card *> minionSlot;
	std::vector<Card *> graveyard;
	Card * activeRitual;

public:
	Player(std::string playerName);
	~Player();

	void drawCard(); // draws a card from deck, add to hand, check if hand is full
	void disgard(int i); // erase ith card in hand
	void attack(int i, player * p); // use minion i to attack player
	void attack(int i, player * p, int j); // use minion i to attack minion j
	void play(int i); // play the ith card, minion, ritual, spell
	void play(int i, player * p); // play the ith card on player p's ritual
	void play(int i, player * p, int t); // play the ith card on on player p's minion t
	void use(int i); // use minion i
	void use(int i, player * p); // use minion i on player p's ritual
	void use(int i, player * p, int t); // use minion i on player p's minion t

	bool die();
	void gainMagic();
	void beAttacked(int damage);
	// notify?

	// for inspect i, displayHand
	// friend std::ostream &operator<<(std::ostream &out, const Card * c);

	// void displayBoard();
};

#endif
