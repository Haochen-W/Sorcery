#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
#include "player.h"

// class Player;

class Card {
	std::string cardName;
	int cost;

public:
	Card(std::string cardName, int cost);
	virtual ~Card() = default;

	// getter and setter
	int getcost();
	void setcost(int ncost);
	std::string getcardName();
	
	virtual std::vector<std::string> getoutput() = 0;

	// pure virtual
	virtual void playCard(Player * playedby, Player * opponent, int i); // return minion / ritual, and place it into minion slot

	// for minions
	virtual int getattackval();
	virtual int getdefenceval();
	virtual void setattackval(int nattackval);
	virtual void setdefenceval(int ndefenceval);
	virtual void minionAttack(Player * target); // override in minion only
	virtual void minionAttack(Player * target, int i); // attack ith minion, override in minion only
	virtual void takeDamage(int damage); // been attacked, override in minions 
	virtual bool miniondead(); // return if a minion is dead, override in minions only
	virtual int getaction(); // return action minion only
	virtual void setaction(int naction); // set minion's action, override in minions only
	virtual void gainaction(); // set minion's action to 1
	virtual void toGraveyard(Player * p, int i);

	virtual void triggereffect(Player * playedby, std::shared_ptr<Card> c); // call ritual's or minion trigger effect

	
	// virtual void playCard(Player * playedby, Card * target) = 0; 
	// virtual void useMinion(Player * playedby, Player * target); // override in minion only
	// virtual void useMinion(Player * playedby, Card * target); // override in minion only

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};

#endif
