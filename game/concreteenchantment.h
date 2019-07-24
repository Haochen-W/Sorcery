#ifndef CONCRETEENCHANTMENT_H
#define CONCRETEENCHANTMENT_H
#include <string>
#include <iostream>
#include "enchantment.h"

class Giantstrength : public Enchantment {
public:
	Giantstrength();
	~Giantstrength() = default;

	std::vector<std::string> getoutput() override;

	// void playCard(Player * playedby, Player * target) override;
	// void playCard(Player * playedby, Card * target) override;
};


class Enrage : public Enchantment {
public:
	Enrage();
	~Enrage() = default;

	std::vector<std::string> getoutput() override;

	// void playCard(Player * playedby, Player * target) override;
	// void playCard(Player * playedby, Card * target) override;
};


class Haste : public Enchantment {
public:
	Haste();
	~Haste() = default;

	std::vector<std::string> getoutput() override;

	// void playCard(Player * playedby, Player * target) override;
	// void playCard(Player * playedby, Card * target) override;
};


class Magicfatigue : public Enchantment {
public:
	Magicfatigue();
	~Magicfatigue() = default;

	std::vector<std::string> getoutput() override;

	// void playCard(Player * playedby, Player * target) override;
	// void playCard(Player * playedby, Card * target) override;
};


class Silence : public Enchantment {
public:
	Silence();
	~Silence() = default;

	std::vector<std::string> getoutput() override;

	// void playCard(Player * playedby, Player * target) override;
	// void playCard(Player * playedby, Card * target) override;
};

#endif
