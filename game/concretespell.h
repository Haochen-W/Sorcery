#ifndef CONCRETESPELL_H
#define CONCRETESPELL_H
#include <string>
#include <iostream>
#include "spell.h"

class Banish : public Spell {
public:
	Banish();

	std::vector<std::string> & getoutput() override;

	void playCard(Player * playedby, Player * target) override;
	void playCard(Player * playedby, Card * target) override;

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};


class Unsummon : public Spell {
public:
	Unsummon(); 

	std::vector<std::string> & getoutput() override;

	void playCard(Player * playedby, Player * target) override;
	void playCard(Player * playedby, Card * target) override;

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};


class Recharge : public Spell {
public:
	Recharge(); 

	std::vector<std::string> & getoutput() override;

	void playCard(Player * playedby, Player * target) override;
	void playCard(Player * playedby, Card * target) override;

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};


class Disenchant : public Spell {
public:
	Disenchant(); 

	std::vector<std::string> & getoutput() override;

	void playCard(Player * playedby, Player * target) override;
	void playCard(Player * playedby, Card * target) override;

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};


class Raisedead : public Spell {
public:
	Raisedead(); 

	std::vector<std::string> & getoutput() override;

	void playCard(Player * playedby, Player * target) override;
	void playCard(Player * playedby, Card * target) override;

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};


class Blizzard : public Spell {
public:
	Blizzard();

	std::vector<std::string> & getoutput() override;

	void playCard(Player * playedby, Player * target) override;
	void playCard(Player * playedby, Card * target) override;

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};

#endif
