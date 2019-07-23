#include "textdisplay.h"
#include "ascii_graphics.h"

TextDisplay::TextDisplay(Player * player, int playerNum){
	displayPlayer.emplace_back(CARD_TEMPLATE_BORDER);
	displayPlayer.emplace_back(CARD_TEMPLATE_EMPTY);
	displayPlayer.emplace_back(player->getplayercard());
	displayPlayer.emplace_back(CARD_TEMPLATE_EMPTY);
	displayPlayer.emplace_back(CARD_TEMPLATE_BORDER);

	displayMinionSlot.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot.emplace_back(CARD_TEMPLATE_BORDER);
}


TextDisplay::notify(Subject & whoNotified){
	if(whoNotified.getritual()) displayPlayer[0] = (whoNotified.getritual())->getoutput();
	displayPlayer[2] = whoNotified.getplayercard();
	if(!(whoNotified.getgraveyard()).empty) displayPlayer[4] = ((whoNotified.getgraveyard()).back())->getoutput();

	for(int i = 0; i < whoNotified.getnumminions(); i++){
		displayMinionSlot[i] = ((whoNotified.getminionslot())[i])->getoutput();
	}
	for(int i = whoNotified.getnumminions(); i < 5; i++){
		displayMinionSlot[i] = CARD_TEMPLATE_BORDER;
	}
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td){
	
}

