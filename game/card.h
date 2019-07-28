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
	virtual void playCard(Player * playedby, Player * opponent, int i); // place minion, ritual
	virtual void playCard(Player * playedby, Player * opponent, int i, bool onme, int t); // play ith card on t's minion
	virtual void playCard(Player * playedby, Player * opponent, int i, bool onme, bool ritual); // play ith card on ritual

	// for minions
	virtual int getattackval();
	virtual int getdefenceval();
	virtual int getabilityCost();
	virtual int getaction(); // return action minion only
	virtual int getactioneachturn();
	virtual std::vector<std::string> & getEnchantmentadded();
	virtual bool getcanuse();

	virtual void setattackval(int nattackval);
	virtual void setdefenceval(int ndefenceval);
	virtual void setcanuse(bool ncanuse);
	virtual void setabilityCost(int nabilityCost);
	virtual void setaction(int naction); // set minion's action, override in minions only

	virtual void setactioneachturn(int nactioneachturn);

	virtual void minionAttack(Player * target); // override in minion only
	virtual void minionAttack(Player * target, int i); // attack ith minion, override in minion only
	virtual void takeDamage(int damage); // been attacked, override in minions 
	virtual bool miniondead(); // return if a minion is dead, override in minions only

	virtual void gainaction(); // set minion's action to 1
	virtual void toGraveyard(Player * p, int i);

	virtual void triggereffect(Player * playedby, Player * opponent, Card * c); // call ritual's or minion trigger effect

	virtual void playCard(Player * playedby, Card * target); // target on
	virtual void useMinion(Player * playedby, Player * opponent);
	virtual void useMinion(Player * playedby, Player * opponent, Card * c); 

	// for rituals
	virtual int getcharge ();
	virtual void setcharge (int ncharge);
};

#endif
