#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <vector>
#include "observer.h"
#include "player.h"
#include "card.h"
#include "exception.h"

class TextDisplay: public Observer { // observer of the player
	std::vector<std::vector<std::string>> displayPlayer1;
	std::vector<std::vector<std::string>> displayMinionSlot1;
	std::vector<std::vector<std::string>> displayHand1;
	std::string displayMagic1;
	std::vector<std::vector<std::string>> displayPlayer2;
	std::vector<std::vector<std::string>> displayMinionSlot2;
	std::vector<std::vector<std::string>> displayHand2;
	std::string displayMagic2;

public:
	TextDisplay();
	void notify(Player & whoNotified) override;

	void displayBoard();
	void displayHand(Player * player);
	void displayMagic(Player * player);
	void inspectCard(Player * player, int i);
};

#endif
