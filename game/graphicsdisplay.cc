#include <sstream>
#include <string>
#include "graphicsdisplay.h"

GraphicsDisplay::GraphicsDisplay(){
	// displayPlayer1.emplace_back(CARD_TEMPLATE_BORDER);
	// displayPlayer1.emplace_back(CARD_TEMPLATE_EMPTY);
	// displayPlayer1.emplace_back(PLAYER_1_TEMPLATE);
	// displayPlayer1.emplace_back(CARD_TEMPLATE_EMPTY);
	// displayPlayer1.emplace_back(CARD_TEMPLATE_BORDER);

	// displayMinionSlot1.emplace_back(CARD_TEMPLATE_BORDER);
	// displayMinionSlot1.emplace_back(CARD_TEMPLATE_BORDER);
	// displayMinionSlot1.emplace_back(CARD_TEMPLATE_BORDER);
	// displayMinionSlot1.emplace_back(CARD_TEMPLATE_BORDER);
	// displayMinionSlot1.emplace_back(CARD_TEMPLATE_BORDER);

	// displayHand1.emplace_back(CARD_TEMPLATE_BORDER);
	// displayHand1.emplace_back(CARD_TEMPLATE_BORDER);
	// displayHand1.emplace_back(CARD_TEMPLATE_BORDER);
	// displayHand1.emplace_back(CARD_TEMPLATE_BORDER);
	// displayHand1.emplace_back(CARD_TEMPLATE_BORDER);

	// displayMagic1 = "o o ";

	// displayPlayer2.emplace_back(CARD_TEMPLATE_BORDER);
	// displayPlayer2.emplace_back(CARD_TEMPLATE_EMPTY);
	// displayPlayer2.emplace_back(PLAYER_2_TEMPLATE);
	// displayPlayer2.emplace_back(CARD_TEMPLATE_EMPTY);
	// displayPlayer2.emplace_back(CARD_TEMPLATE_BORDER);

	// displayMinionSlot2.emplace_back(CARD_TEMPLATE_BORDER);
	// displayMinionSlot2.emplace_back(CARD_TEMPLATE_BORDER);
	// displayMinionSlot2.emplace_back(CARD_TEMPLATE_BORDER);
	// displayMinionSlot2.emplace_back(CARD_TEMPLATE_BORDER);
	// displayMinionSlot2.emplace_back(CARD_TEMPLATE_BORDER);

	// displayHand2.emplace_back(CARD_TEMPLATE_BORDER);
	// displayHand2.emplace_back(CARD_TEMPLATE_BORDER);
	// displayHand2.emplace_back(CARD_TEMPLATE_BORDER);
	// displayHand2.emplace_back(CARD_TEMPLATE_BORDER);
	// displayHand2.emplace_back(CARD_TEMPLATE_BORDER);

	// displayMagic2 = "o o ";

	// std::ostringstream s;
	// w.fillRectangle(10, 10, 1350, 530, Xwindow::White);
	// w.fillRectangle(20, 20, 1300, 2, Xwindow::Black);

	// // first row
	// for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
	// 	w.drawString(20, 40 + i * 10, EXTERNAL_BORDER_CHAR_UP_DOWN);
	// 	for(int j = 0; j < 5; j++){
	// 		w.drawString(44 + j * 264, 40 + i * 10, displayPlayer1[j][i]);
	// 	}
	// 	w.drawString(1320, 40 + i * 10, EXTERNAL_BORDER_CHAR_UP_DOWN);
	// }
	// // second row
	// for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
	// 	w.drawString(20, 155 + i * 10, EXTERNAL_BORDER_CHAR_UP_DOWN);
	// 	for(int j = 0; j < 5; j++){
	// 		w.drawString(44 + j * 264, 155 + i * 10, displayMinionSlot1[j][i]);
	// 	}
	// 	w.drawString(1320, 155 + i * 10, EXTERNAL_BORDER_CHAR_UP_DOWN);
	// }

	// w.fillRectangle(20, 270, 1300, 2, Xwindow::Black);
	// w.fillRectangle(20, 280, 1300, 2, Xwindow::Black);

	// // third row
	// for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
	// 	w.drawString(20, 310 + i * 10, EXTERNAL_BORDER_CHAR_UP_DOWN);
	// 	for(int j = 0; j < 5; j++){
	// 		w.drawString(44 + j * 264, 310 + i * 10, displayMinionSlot2[j][i]);
	// 	}
	// 	w.drawString(1320, 310 + i * 10, EXTERNAL_BORDER_CHAR_UP_DOWN);
	// }
	// // fourth row
	// for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
	// 	w.drawString(20, 425 + i * 10, EXTERNAL_BORDER_CHAR_UP_DOWN);
	// 	for(int j = 0; j < 5; j++){
	// 		w.drawString(44 + j * 264, 425 + i * 10, displayPlayer2[j][i]);
	// 	}
	// 	w.drawString(1320, 425 + i * 10, EXTERNAL_BORDER_CHAR_UP_DOWN);
	// }
	// w.fillRectangle(20, 530, 1300, 2, Xwindow::Black);

	// // hand
	// w.fillRectangle(10, 560, 1350, 150, Xwindow::White);
	// w.drawString(44, 580, "Player1's Hand:");

	// for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
	// 	for(int j = 0; j < 5; j++){
	// 		w.drawString(44 + j * 264, 600 + i * 10, displayHand1[j][i]);
	// 	}
	// }

	// // one card
	// w.fillRectangle(10, 560, 1350, 150, Xwindow::White);
	// int t = 10;
	// w.drawString(44, 580, "ith minion:" + std::to_string(t));

	// for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
	// 	w.drawString(44, 600 + i * 10, displayHand1[1][i]);
	// }

	// 35 total
	// 20 total
	int s = 20;
	int h = 350;
	int v = 175;
	// w
	w.fillRectangle(h, v, s, s, Xwindow::Black);
	w.fillRectangle(h, v + 20, s, s, Xwindow::Black);
	w.fillRectangle(h + 120, v, s, s, Xwindow::Black);
	w.fillRectangle(h + 120, v + 20, s, s, Xwindow::Black);
	w.fillRectangle(h + 20, v + 40, s, s, Xwindow::Black);
	w.fillRectangle(h + 20, v + 60, s, s, Xwindow::Black);
	w.fillRectangle(h + 60, v + 40, s, s, Xwindow::Black);
	w.fillRectangle(h + 60, v + 60, s, s, Xwindow::Black);
	w.fillRectangle(h + 100, v + 40, s, s, Xwindow::Black);
	w.fillRectangle(h + 100, v + 60, s, s, Xwindow::Black);
	w.fillRectangle(h + 40, v + 80, s, s, Xwindow::Black);
	w.fillRectangle(h + 80, v + 80, s, s, Xwindow::Black);

	// i
	w.fillRectangle(h + 160, v, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 180, v + 20, s, s * 3, Xwindow::Black);
	w.fillRectangle(h + 160, v + 80, s * 3, s, Xwindow::Black);

	// n
	w.fillRectangle(h + 240, v, s, s * 5, Xwindow::Black);
	w.fillRectangle(h + 320, v, s, s * 5, Xwindow::Black);
	w.fillRectangle(h + 260, v + 20, s, s, Xwindow::Black);
	w.fillRectangle(h + 280, v + 40, s, s, Xwindow::Black);
	w.fillRectangle(h + 300, v + 60, s, s, Xwindow::Black);

	// n
	w.fillRectangle(h + 360, v, s, s * 5, Xwindow::Black);
	w.fillRectangle(h + 440, v, s, s * 5, Xwindow::Black);
	w.fillRectangle(h + 380, v + 20, s, s, Xwindow::Black);
	w.fillRectangle(h + 400, v + 40, s, s, Xwindow::Black);
	w.fillRectangle(h + 420, v + 60, s, s, Xwindow::Black);

	// e
	w.fillRectangle(h + 500, v, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 500, v + 40, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 500, v + 80, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 480, v, s, s * 5, Xwindow::Black);

	// r
	w.fillRectangle(h + 580, v, s, s * 5, Xwindow::Black);
	w.fillRectangle(h + 600, v, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 600, v + 40, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 640, v + 20, s, s, Xwindow::Black);
	w.fillRectangle(h + 600, v + 60, s, s, Xwindow::Black);
	w.fillRectangle(h + 620, v + 80, s * 2, s, Xwindow::Black);

	// i
	// w.fillRectangle(h + 270, v + 140, s * 3, s, Xwindow::Black);
	// w.fillRectangle(h + 290, v + 160, s, s * 3, Xwindow::Black);
	// w.fillRectangle(h + 270, v + 220, s * 3, s, Xwindow::Black);

	// s
	// w.fillRectangle(h + 350, v + 140, s * 4, s, Xwindow::Black);
	// w.fillRectangle(h + 350, v + 180, s * 4, s, Xwindow::Black);
	// w.fillRectangle(h + 350, v + 220, s * 4, s, Xwindow::Black);
	// w.fillRectangle(h + 350, v + 160, s, s, Xwindow::Black);
	// w.fillRectangle(h + 410, v + 200, s, s, Xwindow::Black);

	// p
	w.fillRectangle(h + 40, v + 280, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 40, v + 280 + 40, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 20, v + 280, s, s * 5, Xwindow::Black);
	w.fillRectangle(h + 80, v + 280 + 20, s, s, Xwindow::Black);

	// l
	w.fillRectangle(h + 120, v + 280, s, s * 5, Xwindow::Black);
	w.fillRectangle(h + 140, v + 280 + 80, s * 3, s, Xwindow::Black);

	// a
	w.fillRectangle(h + 240, v + 280, s * 2, s, Xwindow::Black);
	w.fillRectangle(h + 240, v + 280 + 40, s * 2, s, Xwindow::Black);
	w.fillRectangle(h + 220, v + 280 + 20, s, s * 4, Xwindow::Black);
	w.fillRectangle(h + 280, v + 280 + 20, s, s * 4, Xwindow::Black);

	// y
	w.fillRectangle(h + 320, v + 280, s, s * 2, Xwindow::Black);
	w.fillRectangle(h + 380, v + 280, s, s * 2, Xwindow::Black);
	w.fillRectangle(h + 350, v + 280 + 60, s, s * 2, Xwindow::Black);
	w.fillRectangle(h + 320, v + 280 + 40, s * 4, s, Xwindow::Black);


	// e
	w.fillRectangle(h + 440, v + 280, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 440, v + 280 + 40, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 440, v + 280 + 80, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 420, v + 280, s, s * 5, Xwindow::Black);

	// r
	w.fillRectangle(h + 520, v + 280 , s, s * 5, Xwindow::Black);
	w.fillRectangle(h + 540, v + 280 , s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 540, v + 280 + 40, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 580, v + 280 + 20, s, s, Xwindow::Black);
	w.fillRectangle(h + 540, v + 280 + 60, s, s, Xwindow::Black);
	w.fillRectangle(h + 560, v + 280 + 80, s * 2, s, Xwindow::Black);

	// 1
	// w.fillRectangle(h + 640, v + 280, s * 2, s, Xwindow::Black);
	// w.fillRectangle(h + 640, v + 280 + 80, s * 3, s, Xwindow::Black);
	// w.fillRectangle(h + 660, v + 280 + 20, s, s * 3, Xwindow::Black);

	// 2
	// w.fillRectangle(h + 640, v + 280, s * 3, s, Xwindow::Black);
	// w.fillRectangle(h + 640, v + 280 + 40, s * 3, s, Xwindow::Black);
	// w.fillRectangle(h + 640, v + 280 + 80, s * 3, s, Xwindow::Black);
	// w.fillRectangle(h + 640, v + 280 + 60, s, s, Xwindow::Black);
	// w.fillRectangle(h + 680, v + 280 + 20, s, s, Xwindow::Black);

	// t
	w.fillRectangle(h + 220, v + 140, s * 4, s, Xwindow::Black);
	w.fillRectangle(h + 250, v + 160, s, s * 4, Xwindow::Black);

	// i
	w.fillRectangle(h + 320, v + 140, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 340, v + 160, s, s * 3, Xwindow::Black);
	w.fillRectangle(h + 320, v + 220, s * 3, s, Xwindow::Black);

	// e
	w.fillRectangle(h + 420, v + 140, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 420, v + 180, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 420, v + 220, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 400, v + 140, s, s * 5, Xwindow::Black);

	w.fillRectangle(10, 10, 1350, 700, Xwindow::Red);
}

// void GraphicsDisplay::notify(Subject<Info, State> &whoNotified){

// }
