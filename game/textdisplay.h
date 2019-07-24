#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"

class TextDisplay: public Observer { // observer of the player
	std::vector<std::vector<std::string>> displayPlayer1;
	std::vector<std::vector<std::string>> displayMinionSlot1;
	std::vector<std::vector<std::string>> displayHand1;
	std::vector<std::vector<std::string>> displayPlayer2;
	std::vector<std::vector<std::string>> displayMinionSlot2;
	std::vector<std::vector<std::string>> displayHand2;

public:
	TextDisplay();
	void notify(Subject & whoNotified) override;

	void displayBoard();
	void displayHand(Player * player);
	void inspectCard(Player * player, int i);
};

#endif
