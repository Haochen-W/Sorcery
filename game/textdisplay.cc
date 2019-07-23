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


void TextDisplay::notify(Subject & whoNotified){
	if(whoNotified.getritual()) displayPlayer[0] = (whoNotified.getritual())->getoutput();
	displayPlayer[2] = whoNotified.getplayercard();
	if(!(whoNotified.getgraveyard()).empty) displayPlayer[4] = ((whoNotified.getgraveyard()).back())->getoutput();

	for(int i = 0; i < (whoNotified.getminionslot()).size(); i++){
		displayMinionSlot[i] = ((whoNotified.getminionslot())[i])->getoutput();
	}
	for(int i = (whoNotified.getminionslot()).size(); i < 5; i++){
		displayMinionSlot[i] = CARD_TEMPLATE_BORDER;
	}

	for(int i = 0; i < (whoNotified.gethand()).size(); i++){
		displayHand[i] = ((whoNotified.gethand())[i])->getoutput();
	}
	for(int i = (whoNotified.gethand()).size(); i < 5; i++){
		displayHand[i] = CARD_TEMPLATE_BORDER;
	}
}

// outputboard
// outputhand

std::ostream &operator<<(std::ostream &out, const TextDisplay &td){

}

