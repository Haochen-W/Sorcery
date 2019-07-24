#include "player.h"
#include "ascii_graphics.h"

Player::Player(std::string playerName, int playerNum): 
  playerName{playerName}, playerNum{playerNum}, life{20}, magic{3}, activeRitual{nullptr} {
  	// ctor textdisplay
  	// attach observer
}


int Player::getplayernum() const {return playerNum;}

std::vector<std::string> Player::getplayercard() const {
	return {display_player_card(playerNum, playerName, life, magic)};
}

