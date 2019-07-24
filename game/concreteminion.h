#ifndef CONCRETEMINION_H
#define CONCRETEMINION_H
#include <string>
#include <iostream>
#include "minion.h"

class Airelemental : public Minion {
public:
	Airelemental();
	~Airelemental();

	std::vector<std::string> getoutput() override;

	// void useMinion(Player * playedby, Player * target) override;
	// void useMinion(Player * playedby, Card * target) override;

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);

	// friend Minion;
};


// class Earthelemental : public Minion {
// public:
// 	Earthelemental();

// 	std::vector<std::string> getoutput() override;

// 	void useMinion(Player * playedby, Player * target) override;
// 	void useMinion(Player * playedby, Card * target) override;

// 	// inspect i, hand
// 	// friend std::ostream &operator<<(std::ostream &out, const Card c);

// 	// friend Minion;
// };


// class Bonegolem : public Minion {
// public:
// 	Bonegolem();

// 	std::vector<std::string> getoutput() override;

// 	void useMinion(Player * playedby, Player * target) override;
// 	void useMinion(Player * playedby, Card * target) override;

// 	// inspect i, hand
// 	// friend std::ostream &operator<<(std::ostream &out, const Card c);

// 	// friend Minion;
// };


// class Fireelemental : public Minion {
// public:
// 	Fireelemental();

// 	std::vector<std::string> getoutput() override;

// 	void useMinion(Player * playedby, Player * target) override;
// 	void useMinion(Player * playedby, Card * target) override;

// 	// inspect i, hand
// 	// friend std::ostream &operator<<(std::ostream &out, const Card c);

// 	// friend Minion;
// };


// class Potionseller : public Minion {
// public:
// 	Potionseller(); 

// 	std::vector<std::string> getoutput() override;

// 	void useMinion(Player * playedby, Player * target) override;
// 	void useMinion(Player * playedby, Card * target) override;

// 	// inspect i, hand
// 	// friend std::ostream &operator<<(std::ostream &out, const Card c);

// 	// friend Minion;
// };


// class Novicepyromancer : public Minion {
// public:
// 	Novicepyromancer(); 

// 	std::vector<std::string> getoutput() override;

// 	void useMinion(Player * playedby, Player * target) override;
// 	void useMinion(Player * playedby, Card * target) override;

// 	// inspect i, hand
// 	// friend std::ostream &operator<<(std::ostream &out, const Card c);

// 	// friend Minion;
// };


// class Apprenticesummoner : public Minion {
// public:
// 	Apprenticesummoner(); 

// 	std::vector<std::string> getoutput() override;

// 	void useMinion(Player * playedby, Player * target) override;
// 	void useMinion(Player * playedby, Card * target) override;

// 	// inspect i, hand
// 	// friend std::ostream &operator<<(std::ostream &out, const Card c);

// 	// friend Minion;
// };


// class Mastersummoner : public Minion {
// public:
// 	Mastersummoner();

// 	std::vector<std::string> getoutput() override;

// 	void useMinion(Player * playedby, Player * target) override;
// 	void useMinion(Player * playedby, Card * target) override;

// 	// inspect i, hand
// 	// friend std::ostream &operator<<(std::ostream &out, const Card c);

// 	// friend Minion;
// };


#endif
