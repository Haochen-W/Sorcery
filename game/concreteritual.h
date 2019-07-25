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
	void triggereffect(Player * playedby, Player * opponent, std::shared_ptr<Card> c) override;
};


class Auraofpower : public Ritual {
public:
	Auraofpower(); 
	~Auraofpower() = default;

	std::vector<std::string> getoutput() override;
	void triggereffect(Player * playedby, Player * opponent, std::shared_ptr<Card> c) override;
};


class Standstill : public Ritual {
public:
	Standstill(); 
	~Standstill() = default;

	std::vector<std::string> getoutput() override;
	void triggereffect(Player * playedby, Player * opponent, std::shared_ptr<Card> c) override;
};

#endif
