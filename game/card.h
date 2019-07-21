#ifndef CARD_H
#define CARD_H
#include <string>

Class Card {
	std::string cardName;
	int cost;

public:
	Card(std::string cardName, int cost);

	int attack(int i, int p); // use minion i to attact player, return damage
	int attack(int i, int p, int j); // use minion i to attact minion j, return damage
	void play(int i); // play the ith card, minion, ritual, spell
	void play(int i, int p); // play the ith card on player p's ritual
	void play(int i, int p, int t); // play the ith card on on player p's minion t
	void use(int i); // use minion i
	void use(int i, int p); // use minion i on player p's ritual
	void use(int i, int p, int t); // use minion i on player p's minion t

	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};

#endif