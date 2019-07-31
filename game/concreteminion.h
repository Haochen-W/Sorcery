#ifndef CONCRETEMINION_H
#define CONCRETEMINION_H
#include <string>
#include <iostream>
#include "minion.h"

class Airelemental : public Minion {
public:
	Airelemental();
	~Airelemental() = default;

	std::vector<std::string> getoutput() override;
};


class Earthelemental : public Minion {
public:
	Earthelemental();
	~Earthelemental() = default;

	std::vector<std::string> getoutput() override;
};


class Bonegolem : public Minion {
public:
	Bonegolem();
	~Bonegolem() = default;

	std::vector<std::string> getoutput() override;
	void triggereffect(Player * playedby, Player * opponent, Card * c) override;
};


class Fireelemental : public Minion {
public:
	Fireelemental();
	~Fireelemental() = default;

	std::vector<std::string> getoutput() override;
	void triggereffect(Player * playedby, Player * opponent, Card * c) override;
};


class Potionseller : public Minion {
public:
	Potionseller(); 
	~Potionseller()= default;

	std::vector<std::string> getoutput() override;
	void triggereffect(Player * playedby, Player * opponent, Card * c) override;
};


class Novicepyromancer : public Minion {
public:
	Novicepyromancer(); 
	~Novicepyromancer()= default; 

	std::vector<std::string> getoutput() override;
	void useMinion(Player * playedby, Player * opponent, Card * c, int t) override;
};


class Apprenticesummoner : public Minion {
public:
	Apprenticesummoner(); 
	~Apprenticesummoner()= default; 

	std::vector<std::string> getoutput() override;
	void useMinion(Player * playedby, Player * opponent) override;
};


class Mastersummoner : public Minion {
public:
	Mastersummoner();
	~Mastersummoner()= default;

	std::vector<std::string> getoutput() override;
	void useMinion(Player * playedby, Player * opponent) override;
};


#endif
