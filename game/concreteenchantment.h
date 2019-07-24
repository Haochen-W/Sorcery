#ifndef CONCRETEENCHANTMENT_H
#define CONCRETEENCHANTMENT_H
#include <string>
#include <iostream>
#include "enchantment.h"

class Giantstrength : public Enchantment {
public:
	Giantstrength();

	std::vector<std::string> getoutput() override;

	void playCard(Player * playedby, Player * target) override;
	void playCard(Player * playedby, Card * target) override;

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};


class Enrage : public Enchantment {
public:
	Enrage();

	std::vector<std::string> getoutput() override;

	void playCard(Player * playedby, Player * target) override;
	void playCard(Player * playedby, Card * target) override;

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};


class Haste : public Enchantment {
public:
	Haste();

	std::vector<std::string> getoutput() override;

	void playCard(Player * playedby, Player * target) override;
	void playCard(Player * playedby, Card * target) override;

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};


class Magicfatigue : public Enchantment {
public:
	Magicfatigue();

	std::vector<std::string> getoutput() override;

	void playCard(Player * playedby, Player * target) override;
	void playCard(Player * playedby, Card * target) override;

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};


class Silence : public Enchantment {
public:
	Silence();

	std::vector<std::string> getoutput() override;

	void playCard(Player * playedby, Player * target) override;
	void playCard(Player * playedby, Card * target) override;

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};

#endif
