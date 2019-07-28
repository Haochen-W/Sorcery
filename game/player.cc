#include "player.h"
#include "ascii_graphics.h"
#include "concreteminion.h"
#include "concretespell.h"
#include "concreteritual.h"
#include "concreteenchantment.h"

Player::Player(std::string playerName, int playerNum): 
    playerName{playerName}, playerNum{playerNum}, life{20}, magic{2}{}

std::vector<std::string> Player::getplayerCard(){
	std::vector<std::string> temp{display_player_card(playerNum, playerName, life, magic)};
	return temp;
}
int Player::getplayerNum() {return playerNum;}
int Player::getlife() {return life;}
int Player::getmagic() {return magic;}
std::vector<std::shared_ptr<Card>> & Player::getdeck() {return deck;}
std::vector<std::shared_ptr<Card>> & Player::gethand() {return hand;}
std::vector<std::shared_ptr<Card>> & Player::getminionslot() {return minionslot;}
std::vector<std::shared_ptr<Card>> & Player::getgraveyard() {return graveyard;}
std::vector<std::shared_ptr<Card>> & Player::getactiveRitual() {return activeRitual;}


void Player::setplayerNum(int nplayerNum){playerNum = nplayerNum;}
void Player::setlife (int nlife){life = nlife;}
void Player::setmagic (int nmagic){magic = nmagic;}
void Player::setdeck (std::vector<std::shared_ptr<Card>> ndeck){deck = ndeck;}
void Player::sethand (std::vector<std::shared_ptr<Card>> nhand){hand = nhand;}
void Player::setminionslot (std::vector<std::shared_ptr<Card>> nminionslot){minionslot = nminionslot;}
void Player::setgraveyard (std::vector<std::shared_ptr<Card>> ngraveyard){graveyard = ngraveyard;}
void Player::setactiveRitual (std::vector<std::shared_ptr<Card>> nactiveRitual){activeRitual = nactiveRitual;}
void Player::setplayerCard (std::vector<std::string> nplayerCard){playerCard = nplayerCard;}

void Player::attach(Observer *o){
    observers.emplace_back(o);
} 

void Player::notifyObservers(){
    for(auto &ob : observers) ob->notify(*this);
}

void Player::loadDeck(std::string card){
    if (card == "Air Elemental"){
        std::shared_ptr<Airelemental> p = std::make_shared<Airelemental>();
        getdeck().emplace_back(p);
    } else if (card == "Earth Elemental"){
        std::shared_ptr<Earthelemental> p = std::make_shared<Earthelemental>();
        getdeck().emplace_back(p);
    } else if (card == "Bone Golem"){
        std::shared_ptr<Bonegolem> p = std::make_shared<Bonegolem>();
        getdeck().emplace_back(p);
    } else if (card == "Fire Elemental"){
        std::shared_ptr<Fireelemental> p = std::make_shared<Fireelemental>();
        getdeck().emplace_back(p);
    } else if (card == "Potion Seller"){
        std::shared_ptr<Potionseller> p = std::make_shared<Potionseller>();
        getdeck().emplace_back(p);
    } else if (card == "Novice Pyromancer"){
        std::shared_ptr<Novicepyromancer> p = std::make_shared<Novicepyromancer>();
        getdeck().emplace_back(p);
    } else if (card == "Apprentice Summoner"){
        std::shared_ptr<Apprenticesummoner> p = std::make_shared<Apprenticesummoner>();
        getdeck().emplace_back(p);
    } else if (card == "Master Summoner"){
        std::shared_ptr<Mastersummoner> p = std::make_shared<Mastersummoner>();
        getdeck().emplace_back(p);
    } else if (card == "Banish"){
        std::shared_ptr<Banish> p = std::make_shared<Banish>();
        getdeck().emplace_back(p);
    } else if (card == "Unsummon"){
        std::shared_ptr<Unsummon> p = std::make_shared<Unsummon>();
        getdeck().emplace_back(p);
    } else if (card == "Recharge"){
        std::shared_ptr<Recharge> p = std::make_shared<Recharge>();
        getdeck().emplace_back(p);
    } else if (card == "Disenchant"){
        std::shared_ptr<Disenchant> p = std::make_shared<Disenchant>();
        getdeck().emplace_back(p);
    } else if (card == "Raise Dead"){
        std::shared_ptr<Raisedead> p = std::make_shared<Raisedead>();
        getdeck().emplace_back(p);
    } else if (card == "Blizzard"){
        std::shared_ptr<Blizzard> p = std::make_shared<Blizzard>();
        getdeck().emplace_back(p);
    } else if (card == "Giant Strength"){
        std::shared_ptr<Giantstrength> p = std::make_shared<Giantstrength>(nullptr);
        getdeck().emplace_back(p);
    } else if (card == "Enrage"){
        std::shared_ptr<Enrage> p = std::make_shared<Enrage>(nullptr);
        getdeck().emplace_back(p);
    } else if (card == "Haste"){
        std::shared_ptr<Haste> p = std::make_shared<Haste>(nullptr);
        getdeck().emplace_back(p);
    } else if (card == "Magic Fatigue"){
        std::shared_ptr<Magicfatigue> p = std::make_shared<Magicfatigue>(nullptr);
        getdeck().emplace_back(p);
    } else if (card == "Silence"){
        std::shared_ptr<Silence> p = std::make_shared<Silence>(nullptr);
        getdeck().emplace_back(p);
    } else if (card == "Dark Ritual"){
        std::shared_ptr<Darkritual> p = std::make_shared<Darkritual>();
        getdeck().emplace_back(p);
    } else if (card == "Aura of Power"){
        std::shared_ptr<Auraofpower> p = std::make_shared<Auraofpower>();
        getdeck().emplace_back(p);
    } else if (card == "Standstill"){
        std::shared_ptr<Standstill> p = std::make_shared<Standstill>();
        getdeck().emplace_back(p);
    } 
}

void Player::drawcard(){
    if(deck.size() <= 0){
        ExceedMaximum e{"No more card in your deck."};
        throw e;
    }
    // hand is full, throw exception
    if(hand.size()>= 5){
        ExceedMaximum e{"Your hand is full."};
        throw e;
    }
    std::shared_ptr<Card> temp{deck[0]};
    getdeck().erase(deck.begin());
    gethand().emplace_back(temp);
    this->notifyObservers();
}

void Player::disgard(int i){
    gethand().erase(gethand().begin() + i - 1);
    this->notifyObservers();
}

void Player::attack(int i, Player * p) {
    if (i > (this->getminionslot()).size() || i <= 0) {
        InvalidPosition e{"No minion is placed at this position."};
        throw e;
    }
    if ((this->getminionslot())[i - 1]->getaction() == 0) {
        InvalidMove e {"Not enough action points."};
        throw e;
    }
    // real attack
    (this->getminionslot())[i - 1]->minionAttack(p);
    (this->getminionslot())[i - 1]->setaction(0);

    this->notifyObservers();
    p->notifyObservers();
}

void Player::attack(int i, Player * p, int j) {
    // check valid input
    if (i > (this->getminionslot()).size() || i <= 0) {
        InvalidPosition e {"No minion is placed at this position in your minion slot."};
        throw e;
    }
    if (j > (p->getminionslot()).size() || j <= 0) {
        InvalidPosition e {"No minion is placed at this position in your opponent's minion slot."};
        throw e;
    }
    // check action
    if ((this->getminionslot())[i - 1]->getaction() == 0) {
        InvalidMove e {"Not enough action points."};
        throw e;
    }
    // real attack
    (this->getminionslot())[i - 1]->minionAttack(p, j);
    (p->getminionslot())[j - 1]->minionAttack(this, i);
    (this->getminionslot())[i - 1]->setaction(0);

    if ((this->getminionslot())[i - 1]->miniondead()) {
        (this->getminionslot())[i - 1]->toGraveyard(this, i);
    }

    if ((p->getminionslot())[j - 1]->miniondead()) {
        (p->getminionslot())[j - 1]->toGraveyard(p, j);
    }
    this->notifyObservers();
    p->notifyObservers();
    this->trigger(GameStage::minionLeave, nullptr, p);
    p->trigger(GameStage::minionLeave, nullptr, this);
}

void Player::play(int i, Player * opponent, bool testing){
    // testing mode
    // not enough magic
    if(i > gethand().size() || i <= 0) {
        InvalidPosition e {"No card at this position."};
        throw e;
    }
    
    if (!testing && getmagic() < gethand()[i - 1]->getcost()){
        InvalidMove e {"Not enough magic."};
        throw e;
    }

    const int m = getmagic() - gethand()[i - 1]->getcost();
    gethand()[i - 1]->playCard(this, opponent, i);
    if (testing) {
        setmagic(0);
    } else {
        setmagic(m);
    }
    this->notifyObservers();
}

void Player::play(int i, Player * opponent, bool onme, bool ritual, bool testing){
    // testing mode
    // not enough magic
    if(i > gethand().size() || i <= 0) {
        InvalidPosition e {"No card at this position."};
        throw e;
    }

    if (!testing && getmagic() < gethand()[i - 1]->getcost()){
        InvalidMove e {"Not enough magic."};
        throw e;
    }

    if (onme) {
        if (getactiveRitual().size() == 0) {
            InvalidPosition e {"There is no active ritual."};
            throw e;
        }
    } else {
        if (opponent->getactiveRitual().size() == 0) {
            InvalidPosition e {"There is no active ritual."};
            throw e;
        }
    }
    const int m = getmagic() - gethand()[i - 1]->getcost();
    gethand()[i - 1]->playCard(this, opponent, i, onme, ritual);
    if (testing) {
        setmagic(0);
    } else {
        setmagic(m);
    }
    this->notifyObservers();
}

void Player::play(int i, Player * opponent, int t, bool onme, bool testing){
    // testing mode, not enough magic
    if(i > gethand().size() || i <= 0) {
        InvalidPosition e {"No card at this position."};
        throw e;
    }

    if (!testing && getmagic() < gethand()[i - 1]->getcost()){
        InvalidMove e {"Not enough magic."};
        throw e;
    }

    if(onme) {
        if (getminionslot().size() < t || t <= 0){
            InvalidPosition e {"Not a valid target at this position."};
            throw e;
        }
    } else {
        if (opponent->getminionslot().size() < t || t <= 0){
            InvalidPosition e {"Not a valid target at this position."};
            throw e;
        }
    }

    const int m = getmagic() - gethand()[i - 1]->getcost();
    gethand()[i - 1]->playCard(this, opponent, i, onme, t);
    if (testing) {
        setmagic(0);
    } else {
        setmagic(m);
    }
    this->notifyObservers();
}


void Player::trigger(GameStage state, std::shared_ptr<Card> c, Player * opponent){
    if(state == GameStage::startTurn){
        if(getactiveRitual().size() != 0 && getactiveRitual()[0]->getcardName() == "Dark Ritual"){
            getactiveRitual()[0]->triggereffect(this, opponent, nullptr);
        }
    } else if(state == GameStage::endTurn){
        for(int i = 0; i < getminionslot().size(); i++){
            if(getminionslot()[i]->getcardName() == "Potion Seller"){
                for(int j = 0; j < getminionslot().size(); j++){
                    getminionslot()[i]->triggereffect(this, opponent, getminionslot()[j].get());
                }
            }
        }
    } else if(state == GameStage::curNewMinion){
        if(getactiveRitual().size() != 0 && getactiveRitual()[0]->getcardName() == "Aura of Power"){
            getactiveRitual()[0]->triggereffect(this, opponent, c.get());
        } else if(getactiveRitual().size() != 0 && getactiveRitual()[0]->getcardName() == "Standstill"){
            getactiveRitual()[0]->triggereffect(this, opponent, c.get());
        }
    } else if(state == GameStage::oppNewMinion){
        for(int i = 0; i < getminionslot().size(); i++){
            if(getminionslot()[i]->getcardName() == "Fire Elemental"){
                getminionslot()[i]->triggereffect(this, opponent, c.get());
            }
        }
        if(getactiveRitual().size() != 0 && getactiveRitual()[0]->getcardName() == "Standstill"){
            getactiveRitual()[0]->triggereffect(this, opponent, c.get());
        }
    } else if(state == GameStage::minionLeave){
        for(int i = 0; i < getminionslot().size(); i++){
            if(getminionslot()[i]->getcardName() == "Bone Golem"){
                getminionslot()[i]->triggereffect(this, opponent, getminionslot()[i].get());
            }
        }
    }
    this->notifyObservers();
}

void Player::use(int i, Player * opponent, bool testing){
    // testing mode
    // not enough magic
    if (!testing && getmagic() < getminionslot()[i - 1]->getabilityCost()){
        InvalidMove e {"Not enough magic."};
        throw e;
    }

    if(i > getminionslot().size() || i <= 0) {
        InvalidPosition e {"No card at this position."};
        throw e;
    }
    const int m = getmagic() - getminionslot()[i - 1]->getabilityCost();
    getminionslot()[i - 1]->useMinion(this, opponent);
    if (testing) {
        setmagic(0);
    } else {
        setmagic(m);
    }
    this->notifyObservers();
}


void Player::use(int i, Player * opponent, int t, bool onme, bool testing){
    // testing mode
    // not enough magic
    if (!testing && getmagic() < getminionslot()[i - 1]->getabilityCost()){
        InvalidMove e {"Not enough magic."};
        throw e;
    }

    if(i > getminionslot().size() || i <= 0) {
        InvalidPosition e {"No card at this position."};
        throw e;
    }

    if(onme) {
        if (getminionslot().size() < t || t <= 0){
            InvalidPosition e {"Not a valid target at this position."};
            throw e;
        }
    } else {
        if (opponent->getminionslot().size() < t || t <= 0){
            InvalidPosition e {"Not a valid target at this position."};
            throw e;
        }
    }
    const int m = getmagic() - getminionslot()[i - 1]->getabilityCost();
    if (onme){
        getminionslot()[i - 1]->useMinion(this, opponent, getminionslot()[i - 1].get());
    } else {
        getminionslot()[i - 1]->useMinion(this, opponent, opponent->getminionslot()[i - 1].get());
    }
    if (testing) {
        setmagic(0);
    } else {
        setmagic(m);
    }
    this->notifyObservers();
}

void Player::gainaction(){
    for (auto i: getminionslot()){
        i->gainaction();
    }
}

bool Player::die() {return (getlife() <= 0);}

void Player::gainMagic(){magic += 1;}







