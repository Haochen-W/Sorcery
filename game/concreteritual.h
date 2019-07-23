#ifndef CONCRETERITUAL_H
#define CONCRETERITUAL_H
#include <string>
#include <iostream>
#include "ritual.h"

class Darkritual : public Ritual {
public:
	Darkritual();

	std::vector<std::string> & getoutput() override;

	void playCard(Player * playedby, Player * target) override;
	void playCard(Player * playedby, Card * target) override;

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};


class Auraofpower : public Ritual {
public:
	Auraofpower(); 

	std::vector<std::string> & getoutput() override;

	void playCard(Player * playedby, Player * target) override;
	void playCard(Player * playedby, Card * target) override;

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};


class Standstill : public Ritual {
public:
	Standstill(); 

	std::vector<std::string> & getoutput() override;

	void playCard(Player * playedby, Player * target) override;
	void playCard(Player * playedby, Card * target) override;

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};

#endif
