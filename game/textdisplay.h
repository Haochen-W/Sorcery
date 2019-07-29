#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include "display.h"
#include "exception.h"

class TextDisplay: public outputDisplay {
public:
	TextDisplay();
	~TextDisplay() = default;

	void displayBoard() override;
	void displayHand(Player * player) override;
	void displayMagic(Player * player) override;
	void inspectCard(Player * player, int i) override;
	void endgame(Player * player) override;
};

#endif
