#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>

class Card {
	std::string cardName;
	int cost;

public:
	Card(std::string cardName, int cost);

	virtual int minionAttack(); // return damage, override in minion only
	virtual int minionAttack(Card * minioni); // attack ith minion, override in minion only
	virtual Card * playCard() = 0; // return minion / ritual, and place it into minion slot
	virtual void playCard(Card * target) = 0; 
	virtual void useMinion(); // override in minion only
	virtual void useMinion(Card * target); // override in minion only

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};

#endif
