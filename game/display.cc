#include "display.h"

outputDisplay::outputDisplay(){
	displayPlayer1.emplace_back(CARD_TEMPLATE_BORDER);
	displayPlayer1.emplace_back(CARD_TEMPLATE_EMPTY);
	displayPlayer1.emplace_back(PLAYER_1_TEMPLATE);
	displayPlayer1.emplace_back(CARD_TEMPLATE_EMPTY);
	displayPlayer1.emplace_back(CARD_TEMPLATE_BORDER);

	displayMinionSlot1.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot1.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot1.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot1.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot1.emplace_back(CARD_TEMPLATE_BORDER);

	displayHand1.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand1.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand1.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand1.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand1.emplace_back(CARD_TEMPLATE_BORDER);

	displayMagic1 = "o o ";

	displayPlayer2.emplace_back(CARD_TEMPLATE_BORDER);
	displayPlayer2.emplace_back(CARD_TEMPLATE_EMPTY);
	displayPlayer2.emplace_back(PLAYER_2_TEMPLATE);
	displayPlayer2.emplace_back(CARD_TEMPLATE_EMPTY);
	displayPlayer2.emplace_back(CARD_TEMPLATE_BORDER);

	displayMinionSlot2.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot2.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot2.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot2.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot2.emplace_back(CARD_TEMPLATE_BORDER);

	displayHand2.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand2.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand2.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand2.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand2.emplace_back(CARD_TEMPLATE_BORDER);

	displayMagic2 = "o o ";

}


void outputDisplay::notify(Player & whoNotified){
	if(whoNotified.getplayerNum() == 1){
		// update player row
		if(whoNotified.getactiveRitual().size() != 0) displayPlayer1[0] = (whoNotified.getactiveRitual()[0])->getoutput();
		displayPlayer1[2] = whoNotified.getplayerCard();
		if(!(whoNotified.getgraveyard()).empty()) displayPlayer1[4] = ((whoNotified.getgraveyard()).back())->getoutput();

		// update minion slot
		for(int i = 0; i < (whoNotified.getminionslot()).size(); i++){
			displayMinionSlot1[i] = ((whoNotified.getminionslot())[i])->getoutput();
		}
		for(int i = (whoNotified.getminionslot()).size(); i < 5; i++){
			displayMinionSlot1[i] = CARD_TEMPLATE_BORDER;
		}

		// update hand
		for(int i = 0; i < (whoNotified.gethand()).size(); i++){
			displayHand1[i] = ((whoNotified.gethand())[i])->getoutput();
		}
		for(int i = (whoNotified.gethand()).size(); i < 5; i++){
			displayHand1[i] = CARD_TEMPLATE_BORDER;
		}

	} else if(whoNotified.getplayerNum() == 2){
		// update player row
		if(whoNotified.getactiveRitual().size() != 0) displayPlayer2[0] = (whoNotified.getactiveRitual()[0])->getoutput();
		displayPlayer2[2] = whoNotified.getplayerCard();
		if(!(whoNotified.getgraveyard()).empty()) displayPlayer2[4] = ((whoNotified.getgraveyard()).back())->getoutput();
		
		// update minion slot
		for(int i = 0; i < (whoNotified.getminionslot()).size(); i++){
			displayMinionSlot2[i] = ((whoNotified.getminionslot())[i])->getoutput();
		}
		for(int i = (whoNotified.getminionslot()).size(); i < 5; i++){
			displayMinionSlot2[i] = CARD_TEMPLATE_BORDER;
		}
		
		// update hand
		for(int i = 0; i < (whoNotified.gethand()).size(); i++){
			displayHand2[i] = ((whoNotified.gethand())[i])->getoutput();
		}
		for(int i = (whoNotified.gethand()).size(); i < 5; i++){
			displayHand2[i] = CARD_TEMPLATE_BORDER;
		}
	}
}
