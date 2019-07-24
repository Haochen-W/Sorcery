#ifndef CONCRETERITUAL_H
#define CONCRETERITUAL_H
#include <string>
#include <iostream>
#include "ritual.h"

class Darkritual : public Ritual {
public:
	Darkritual();
	~Darkritual() = default;

	std::vector<std::string> getoutput() override;

	// void playCard(Player * playedby, Player * target) override;
	// void playCard(Player * playedby, Card * target) override;
};


class Auraofpower : public Ritual {
public:
	Auraofpower(); 
	~Auraofpower() = default;

	std::vector<std::string> getoutput() override;

	// void playCard(Player * playedby, Player * target) override;
	// void playCard(Player * playedby, Card * target) override;
};


class Standstill : public Ritual {
public:
	Standstill(); 
	~Standstill() = default;

	std::vector<std::string> getoutput() override;

	// void playCard(Player * playedby, Player * target) override;
	// void playCard(Player * playedby, Card * target) override;
};

#endif
