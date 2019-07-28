#ifndef CONCRETEENCHANTMENT_H
#define CONCRETEENCHANTMENT_H
#include <string>
#include <iostream>
#include "enchantment.h"

class Giantstrength : public Enchantment {
public:
	Giantstrength(Minion * component);
	~Giantstrength() = default;

	std::vector<std::string> getoutput() override;
	void playCard(Player * playedby, Player * opponent, int i, bool onme, int t) override;
};


class Enrage : public Enchantment {
public:
	Enrage(Minion * component);
	~Enrage() = default;

	std::vector<std::string> getoutput() override;
	void playCard(Player * playedby, Player * opponent, int i, bool onme, int t) override;

	// void playCard(Player * playedby, Player * target) override;
	// void playCard(Player * playedby, Card * target) override;
};


class Haste : public Enchantment {
public:
	Haste(Minion * component);
	~Haste() = default;

	std::vector<std::string> getoutput() override;
	void playCard(Player * playedby, Player * opponent, int i, bool onme, int t) override;

	// void playCard(Player * playedby, Player * target) override;
	// void playCard(Player * playedby, Card * target) override;
};


class Magicfatigue : public Enchantment {
public:
	Magicfatigue(Minion * component);
	~Magicfatigue() = default;

	std::vector<std::string> getoutput() override;
	void playCard(Player * playedby, Player * opponent, int i, bool onme, int t) override;

	// void playCard(Player * playedby, Player * target) override;
	// void playCard(Player * playedby, Card * target) override;
};


class Silence : public Enchantment {
public:
	Silence(Minion * component);
	~Silence() = default;

	std::vector<std::string> getoutput() override;
	void playCard(Player * playedby, Player * opponent, int i, bool onme, int t) override;

	// void playCard(Player * playedby, Player * target) override;
	// void playCard(Player * playedby, Card * target) override;
};

#endif
