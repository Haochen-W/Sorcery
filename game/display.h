#ifndef DISPLAY_H
#define DISPLAY_H
#include <vector>
#include "observer.h"
#include "player.h"
#include "card.h"
#include "exception.h"
#include "ascii_graphics.h"

class outputDisplay: public Observer { // observer of the player
protected:
	std::vector<std::vector<std::string>> displayPlayer1;
	std::vector<std::vector<std::string>> displayMinionSlot1;
	std::vector<std::vector<std::string>> displayHand1;
	std::string displayMagic1;
	std::vector<std::vector<std::string>> displayPlayer2;
	std::vector<std::vector<std::string>> displayMinionSlot2;
	std::vector<std::vector<std::string>> displayHand2;
	std::string displayMagic2;

public:
	outputDisplay();
	~outputDisplay() = default;
	void notify(Player & whoNotified) override;

	virtual void displayBoard() = 0;
	virtual void displayHand(Player * player) = 0;
	virtual void displayMagic(Player * player) = 0;
	virtual void inspectCard(Player * player, int i) = 0;
};

#endif
