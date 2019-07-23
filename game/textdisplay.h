#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"

class TextDisplay: public Observer { // observer of the player
	std::vector<std::vector<std::string>> displayPlayer;
	std::vector<std::vector<std::string>> displayMinionSlot;
	std::vector<std::vector<std::string>> displayHand;


public:
	TextDisplay(); // attach player1 and player2
	void notify(Subject & whoNotified) override;

	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
