#include "player.h"
#include "ascii_graphics.h"
#include "concreteminion.h"
// #include "concretespell.h"
// #include "concreteritual.h"
// #include "concreteenchantment.h"

Player::Player(std::string playerName, int playerNum): 
  playerName{playerName}, playerNum{playerNum}, life{20}, magic{3}, activeRitual{nullptr} {
  	// ctor textdisplay
  	// attach observer
}

int Player::getplayernum() {
	return playerNum;
}

int Player::getlife() {
	return life;
}

int Player::getmagic() {
	return magic;
}

std::vector<Card *> & getdeck() {
	return deck;
}

std::vector<Card *> & Player::gethand() {
	return hand;
}

std::vector<Card *> & Player::getminionslot() {
	return minionslot;
}

std::vector<Card *> & Player::getgraveyard() {
	return graveyard;
}

Card * Player::getactiveRitual() {
	return activeRitual;
}
int Player::getplayerNum(){
	return playerNum;
}

std::vector<std::shared_ptr<Card>> & Player::getdeck() {
	return deck;
}
std::vector<std::shared_ptr<Card>> & Player::getminionslot() {
	return minionslot;
}

std::vector<std::string> Player::getplayerCard(){
	std::vector<std::string> temp{display_player_card(playerNum, playerName, life, magic)};
	return temp;
}

void Player::setplayerNum(int nplayerNum){
	playerNum = nplayerNum;
}

void Player::setlife (int nlife){
	life = nlife;
}

void Player::setmagic (int nmagic){
	magic = nmagic;
}

void Player::setdeck (std::vector<Card *> ndeck){
	deck = ndeck;
}

void Player::sethand (std::vector<Card *> nhand){
	hand = nhand;
}

void Player::setminionslot (std::vector<Card *> nminionslot){
	minionslot = nminionslot;
}

void Player::setgraveyard (std::vector<Card *> ngraveyard){
	graveyard = ngraveyard;
}

void Player::setactiveRitual (Card * nactiveRitual){
	activeRitual = nactiveRitual;
}

void Player::setplayerCard (std::vector<std::string> nplayerCard){
	playerCard = nplayerCard;
}

void Player::loadDeck(std::string card){
 if (card == "Air Elemental"){
  std::shared_ptr<Airelemental> p = std::make_shared<Airelemental>();
  deck.emplace_back(p);
 } 
 // else if (card == "Earth Elemental"){
 //  std::shared_ptr<Earthelemental> p = std::make_shared<Earthelemental>();
 //  deck.emplace_back(p);
 // } else if (card == "Bone Golem"){
 //  std::shared_ptr<Bonegolem> p = std::make_shared<Bonegolem>();
 //  deck.emplace_back(p);
 // } else if (card == "Fire Elemental"){
 //  std::shared_ptr<Fireelemental> p = std::make_shared<Fireelemental>();
 //  deck.emplace_back(p);
 // } else if (card == "Potion Seller"){
 //  std::shared_ptr<Potionseller> p = std::make_shared<Potionseller>();
 //  deck.emplace_back(p);
 // } else if (card == "Novice Pyromancer"){
 //  std::shared_ptr<Novicepyromancer> p = std::make_shared<Novicepyromancer>();
 //  deck.emplace_back(p);
 // } else if (card == "Apprentice Summoner"){
 //  std::shared_ptr<Apprenticesummoner> p = std::make_shared<Apprenticesummoner>();
 //  deck.emplace_back(p);
 // } else if (card == "Master Summoner"){
 //  std::shared_ptr<Mastersummoner> p = std::make_shared<Mastersummoner>();
 //  deck.emplace_back(p);
 // } else if (card == "Banish"){
 //  std::shared_ptr<Banish> p = std::make_shared<Banish>();
 //  deck.emplace_back(p);
 // } else if (card == "Unsummon"){
 //  std::shared_ptr<Unsummon> p = std::make_shared<Unsummon>();
 //  deck.emplace_back(p);
 // } else if (card == "Recharge"){
 //  std::shared_ptr<Recharge> p = std::make_shared<Recharge>();
 //  deck.emplace_back(p);
 // } else if (card == "Disenchant"){
 //  std::shared_ptr<Disenchant> p = std::make_shared<Disenchant>();
 //  deck.emplace_back(p);
 // } else if (card == "Raise Dead"){
 //  std::shared_ptr<Raisedead> p = std::make_shared<Raisedead>();
 //  deck.emplace_back(p);
 // } else if (card == "Blizzard"){
 //  std::shared_ptr<Blizzard> p = std::make_shared<Blizzard>();
 //  deck.emplace_back(p);
 // } else if (card == "Giant Strength"){
 //  std::shared_ptr<Giantstrength> p = std::make_shared<Giantstrength>();
 //  deck.emplace_back(p);
 // } else if (card == "Enrage"){
 //  std::shared_ptr<Enrage> p = std::make_shared<Enrage>();
 //  deck.emplace_back(p);
 // } else if (card == "Haste"){
 //  std::shared_ptr<Haste> p = std::make_shared<Haste>();
 //  deck.emplace_back(p);
 // } else if (card == "Magic Fatigue"){
 //  std::shared_ptr<Magicfatigue> p = std::make_shared<Magicfatigue>();
 //  deck.emplace_back(p);
 // } else if (card == "Silence"){
 //  std::shared_ptr<Silence> p = std::make_shared<Silence>();
 //  deck.emplace_back(p);
 // } else if (card == "Dark Ritual"){
 //  std::shared_ptr<Darkritual> p = std::make_shared<Darkritual>();
 //  deck.emplace_back(p);
 // } else if (card == "Aura of Power"){
 //  std::shared_ptr<Auraofpower> p = std::make_shared<Auraofpower>();
 //  deck.emplace_back(p);
 // } else if (card == "Standstill"){
 //  std::shared_ptr<Standstill> p = std::make_shared<Standstill>();
 //  deck.emplace_back(p);
 // } 
}
