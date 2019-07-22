#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include "observer.h"

class TextDisplay: public Observer { // observer of the player
	// std::vector<std::string> display ???

public:
	TextDisplay(); // attach player1 and player2 ??
	void notify(Subject & whoNotified) override;

	// friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
