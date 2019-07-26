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
	void playCard(Player * playedby, Player * opponent, int i, bool onme, bool ritual) override;
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
	void playCard(Player * playedby, Player * opponent, int i, bool onme, bool ritual) override;

	// void playCard(Player * playedby, Player * target) override;
	// void playCard(Player * playedby, Card * target) override;
};


class Disenchant : public Spell {
public:
	Disenchant(); 
	~Disenchant() = default;

	std::vector<std::string> getoutput() override;
	void playCard(Player * playedby, Player * opponent, int i, bool onme, int t) override;

	// void playCard(Player * playedby, Player * target) override;
	// void playCard(Player * playedby, Card * target) override;
};


class Raisedead : public Spell {
public:
	Raisedead(); 
	~Raisedead() = default;

	std::vector<std::string> getoutput() override;
	void playCard(Player * playedby, Player * opponent, int i, bool onme, bool ritual) override;

	// void playCard(Player * playedby, Player * target) override;
	// void playCard(Player * playedby, Card * target) override;
};


class Blizzard : public Spell {
public:
	Blizzard();
	~Blizzard() = default;

	std::vector<std::string> getoutput() override;
	void playCard(Player * playedby, Player * opponent, int i, bool onme, int t) override;
	// void playCard(Player * playedby, Player * target) override;
	// void playCard(Player * playedby, Card * target) override;
};

#endif
