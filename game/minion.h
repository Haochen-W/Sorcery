#ifndef MINION_H
#define MINION_H
#include <string>
#include <iostream>
#include "card.h"

class Minion : public Card {
protected:
	int attackval;
	int defenceval;
	int abilityCost;
	int action;

public:
	Minion(std::string cardName, int cost, int attackval, int defenceval, int abilityCost);
	~Minion() = default;

	// getter and setter
	int getattackval() override;
	int getdefenceval() override;
	int getabilityCost() override;
	int getaction() override;
	void setattackval(int nattackval) override;
	void setdefenceval(int ndefenceval) override;
	void setabilityCost(int nabilityCost);
	void setaction(int naction) override;

	void minionAttack(Player * target) override;
	void minionAttack(Player * target, int i) override; // call mbeattack on target minion
	void playCard(Player * playedby, Player * opponent, int i) override; // place the minion into minion slot
	// void playCard(Player * playedby, Card * target) override; // do nothing
	void useMinion(Player * playedby, Player * opponent, std::shared_ptr<Card> c) override;
	void useMinion(Player * playedby, Player * opponent) override;

	void takeDamage(int damage) override;// cause damage on minion
	void toGraveyard(Player * p, int i) override;
	bool miniondead() override;

	void gainaction() override;
	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};

#endif
