#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <vector>
#include "window.h"
#include "ascii_graphics.h"

class GraphicsDisplay{
	Xwindow w{1400, 750}; // horizontal, vertical
	std::vector<std::vector<std::string>> displayPlayer1;
	std::vector<std::vector<std::string>> displayMinionSlot1;
	std::vector<std::vector<std::string>> displayHand1;
	std::string displayMagic1;
	std::vector<std::vector<std::string>> displayPlayer2;
	std::vector<std::vector<std::string>> displayMinionSlot2;
	std::vector<std::vector<std::string>> displayHand2;
	std::string displayMagic2;

public:
	GraphicsDisplay();
	// void notify(Subject<Info, State> &whoNotified) override;
};
#endif
