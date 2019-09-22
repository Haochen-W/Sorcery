#ifndef CONCRETESPELL_H
#define CONCRETESPELL_H
#include <string>
#include <iostream>
#include "spell.h"

class Banish : public Spell {
public:
	Banish();
	~Banish() = default;

	std::vector<std::string> getoutput() override;
	void playCardonRitual(Player * playedby, Player * opponent, int i, bool onme) override;
	void playCard(Player * playedby, Player * opponent, int i, bool onme, int t) override;
};

class Unsummon : public Spell {
public:
	Unsummon(); 
	~Unsummon() = default;

	std::vector<std::string> getoutput() override;
	void playCard(Player * playedby, Player * opponent, int i, bool onme, int t) override;
};


class Recharge : public Spell {
public:
	Recharge(); 
	~Recharge() = default;

	std::vector<std::string> getoutput() override;
	void playCard(Player * playedby, Player * opponent, int i) override;
};


class Disenchant : public Spell {
public:
	Disenchant(); 
	~Disenchant() = default;

	std::vector<std::string> getoutput() override;
	void playCard(Player * playedby, Player * opponent, int i, bool onme, int t) override;
};


class Raisedead : public Spell {
public:
	Raisedead(); 
	~Raisedead() = default;

	std::vector<std::string> getoutput() override;
	void playCard(Player * playedby, Player * opponent, int i) override;
};


class Blizzard : public Spell {
public:
	Blizzard();
	~Blizzard() = default;

	std::vector<std::string> getoutput() override;
	void playCard(Player * playedby, Player * opponent, int i) override;
};


class Coin : public Spell {
public: 
	Coin();
	~Coin() = default;

	std::vector<std::string> getoutput() override;
	void playCard(Player * playedby, Player * opponent, int i) override;
};

#endif
