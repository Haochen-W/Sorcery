#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include <iostream>
#include <string>
#include <memory>
#include "observer.h"
#include "ascii_graphics.h"
#include "exception.h"

extern const int maxMagic;
extern const int heroPowerCost;
extern const int maxLife;
extern const int initialMagic;
extern const int maxMinionNum;
extern const int maxHandNum;

// declaration
class Card;
class Minion;
class TextDisplay;

enum class GameStage{startTurn, endTurn, curNewMinion, oppNewMinion, minionLeave};

class Player{
	std::string playerName;
	std::string hero;
	int playerNum;
	int life;
	int magic;
	int round;
	int hattackval;
	bool heropowerState;
	int heropowercost;
	bool first;
	std::vector<Observer *> observers;
	std::vector<std::shared_ptr<Card>> deck;
	std::vector<std::shared_ptr<Card>> hand;
	std::vector<std::shared_ptr<Card>> minionslot;
	std::vector<std::shared_ptr<Card>> graveyard;
	std::vector<std::shared_ptr<Card>> activeRitual;
	std::vector<std::string> playerCard;

public:
	Player(std::string playerName, int playerNum, std::string hero, bool first);
	virtual ~Player() = default;

	// getter and setter
	std::string & gethero();
	int getplayerNum() const;
	int getlife() const;
	int getmagic() const;
	int getround() const;
	int gethattackval() const;
	bool getheropowerState() const;
	int getheropowercost() const;
	bool getfirst() const;
	std::vector<std::shared_ptr<Card>> & getdeck();
	std::vector<std::shared_ptr<Card>> & gethand();
	std::vector<std::shared_ptr<Card>> & getminionslot();
	std::vector<std::shared_ptr<Card>> & getgraveyard();
	std::vector<std::shared_ptr<Card>> & getactiveRitual();
	std::vector<std::string> getplayerCard();

	void setlife (int nlife);
	void setmagic (int nmagic);
	void sethattackval (int nhattackval);
	void setheropowerState (bool nheropowerState);
	void setheropowercost(int nheropowercost);
	void setfirst(bool nfirst);
	// heropowers
	void useHeropower(Player * opponent, bool testing);
	void useHeropower(Player * opponent, bool onme, bool testing);
	void useHeropower(Player * opponent, int t, bool onme, bool testing);

	// subject
	void attach(Observer *o);
	void notifyObservers();

	void loadDeck(std::string card); // load deck
	void drawcard(); // draws a card from deck, add to hand
	void discard(int i); // erase ith card in hand, use in testing mode
	void attack(int i, Player * p); // use minion i to attack player
	void attack(int i, Player * p, int j); // use minion i to attack minion j
	void play(int i, Player * opponent, bool testing); // play the ith card, place minion, place ritual, spell effect
	void play(int i, Player * opponent, int t, bool onme, bool testing); // play the ith card on on a player's minion t
	void playonRitual(int i, Player * opponent, bool onme, bool testing); // targeting on a ritual
	void trigger(GameStage state, std::shared_ptr<Card> m, Player * opponent);
	void use(int i, Player * opponent, bool testing); // use minion i
	void use(int i, Player * opponent, int t, bool onme, bool testing); // use minion i on player p's minion t
	void initTurn();
	bool die();
	void gainMagic();
	void gainOneMagicForce();
	void nextRound();
	void gainAction();
	void gainCoin();
	double evalState(Player * opponent); // evaluate how advantage the situation is for the player
};
#endif
