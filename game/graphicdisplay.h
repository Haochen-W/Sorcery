#ifndef GRAPHICDISPLAY_H
#define GRAPHICDISPLAY_H
#include "display.h"
#include "exception.h"
#include "window.h"

class GraphicDisplay: public outputDisplay {
	Xwindow w{1400,1000}; // horizontal, vertical

public:
	GraphicDisplay();
	~GraphicDisplay() = default;

	void displayBoard() override;
	void displayHand(Player * player) override;
	void displayMagic(Player * player) override;
	void inspectCard(Player * player, int i) override;
};

#endif
