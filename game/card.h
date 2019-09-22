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

	// playcard, to be overwritten
	virtual void playCard(Player * playedby, Player * opponent, int i); // place minion, ritual
	virtual void playCard(Player * playedby, Player * opponent, int i, bool onme, int t); // play ith card on t's minion
	virtual void playCardonRitual(Player * playedby, Player * opponent, int i, bool onme); // play ith card on ritual

	// for minions
	virtual int getattackval() const;
	virtual int getdefenceval() const;
	virtual int getabilityCost() const;
	virtual int getaction() const;
	virtual int getactioneachturn() const;
	virtual std::vector<std::string> & getEnchantmentadded();
	virtual bool getcanuse() const;

	virtual void setattackval(int nattackval);
	virtual void setdefenceval(int ndefenceval);
	virtual void setabilityCost(int nabilityCost);
	virtual void setaction(int naction);
	virtual void setactioneachturn(int nactioneachturn);
	virtual void setcanuse(bool ncanuse);

	virtual void minionAttack(Player * target); // attack player
	virtual void minionAttack(Player * target, int i); // attack ith minion
	virtual void takeDamage(int damage); // been attacked
	virtual bool miniondead(); // return if a minion is dead
	virtual void gainAction(); // set minion's action each turn
	virtual void disenchantall();
	virtual void toGraveyard(Player * p, int i);
	virtual void triggereffect(Player * playedby, Player * opponent, Card * c); // call ritual's or minion trigger effect
	virtual void useMinion(Player * playedby, Player * opponent);
	virtual void useMinion(Player * playedby, Player * opponent, Card * c, int i); 

	// for rituals
	virtual int getcharge () const;
	virtual void setcharge (int ncharge);
};

#endif
