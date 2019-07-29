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
	int actioneachturn;
	std::vector<std::string> Enchantmentadded;
	bool canuse;

public:
	Minion(std::string cardName, int cost, int attackval, int defenceval, int abilityCost);
	~Minion() = default;

	// getter and setter
	int getattackval() const override;
	int getdefenceval() const override;
	int getabilityCost() const override;
	int getaction() const override;
	int getactioneachturn() const override;
	std::vector<std::string> & getEnchantmentadded() override;
	bool getcanuse() const override;

	void setattackval(int nattackval) override;
	void setdefenceval(int ndefenceval) override;
	void setabilityCost(int nabilityCost) override;
	void setaction(int naction) override;
	void setactioneachturn(int nactioneachturn) override;
	void setcanuse(bool ncanuse) override;

	void minionAttack(Player * target) override;
	void minionAttack(Player * target, int i) override; // attack the ith minion
	void playCard(Player * playedby, Player * opponent, int i) override; // place the minion into minion slot
	void useMinion(Player * playedby, Player * opponent, Card * c) override;
	void useMinion(Player * playedby, Player * opponent) override;

	void takeDamage(int damage) override;// cause damage on minion
	void toGraveyard(Player * p, int i) override;
	bool miniondead() override;

	void gainaction() override;
	void disenchantall() override;
};

#endif
