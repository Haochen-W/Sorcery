#include "ascii_graphics.h"
#include "concreteminion.h"
#include "concretespell.h"
#include "concreteritual.h"
#include "concreteenchantment.h"

Player::Player(std::string playerName, int playerNum, std::string hero): 
    playerName{playerName}, hero{hero}, playerNum{playerNum}, life{20}, magic{2}, hattackval{0}, heropowerState{true}, heropowercost{1} {}

std::string & Player::gethero() {return hero;}
int Player::getplayerNum() const{return playerNum;}
int Player::getlife() const{return life;}
int Player::getmagic() const{return magic;}
int Player::gethattackval() const {return hattackval;}
bool Player::getheropowerState () const {return heropowerState;}
int Player::getheropowercost () const {return heropowercost;}
std::vector<std::shared_ptr<Card>> & Player::getdeck() {return deck;}
std::vector<std::shared_ptr<Card>> & Player::gethand() {return hand;}
std::vector<std::shared_ptr<Card>> & Player::getminionslot() {return minionslot;}
std::vector<std::shared_ptr<Card>> & Player::getgraveyard() {return graveyard;}
std::vector<std::shared_ptr<Card>> & Player::getactiveRitual() {return activeRitual;}
std::vector<std::string> Player::getplayerCard() {
    std::vector<std::string> temp{display_player_card(playerName, playerNum, hero, life, magic, heropowercost)};
    return temp;
}

void Player::setlife (int nlife){life = nlife;}
void Player::setmagic (int nmagic){magic = nmagic;}
void Player::sethattackval (int nhattackval){hattackval = nhattackval;}
void Player::setheropowerState(bool nheropowerState){heropowerState = nheropowerState;}
void Player::setheropowercost(int nheropowercost){heropowercost = nheropowercost;}

void Player::useHeropower(Player * opponent, bool testing){
    if(!getheropowerState()){
        InvalidMove e{"You can only use your hero power once per turn."};
        throw e;
    }
    if(!testing && getmagic() < getheropowercost()){
        InvalidMove e {"You don't have enough magic."};
        throw e;
    }

    if(gethero() == "Hunter"){
        opponent->setlife(opponent->getlife() - 2);
    } else if(gethero() == "Paladin"){
        if(getminionslot().size() >= 5){
            ExceedMaximum e{"Your minion slot is full."};
            throw e;
        }
        std::shared_ptr<Airelemental> p = std::make_shared<Airelemental>();
        (getminionslot()).emplace_back(p);
        trigger(GameStage::curNewMinion, p, opponent);
        opponent->trigger(GameStage::oppNewMinion, p, this);
    } else if (gethero() == "Warrior"){
        setlife(getlife() + 2);
    } else if(gethero() == "Warlock"){
        setlife(getlife() - 2);
        if(deck.size() <= 0){
            std::shared_ptr<Card> temp{deck[0]};
            getdeck().erase(deck.begin());
            setheropowerState(false);
            ExceedMaximum e{"No more card in your deck."};
            throw e;
        }
        // hand is full, throw exception
        if(hand.size()>= 5){
            std::shared_ptr<Card> temp{deck[0]};
            getdeck().erase(deck.begin());
            setheropowerState(false);
            ExceedMaximum e{"Your hand is full."};
            throw e;
        }
        std::shared_ptr<Card> temp{deck[0]};
        getdeck().erase(deck.begin());
        gethand().emplace_back(temp);
    }
    if(testing && getmagic() < getheropowercost()) {
        setmagic(0);
    } else {
        setmagic(getmagic() - getheropowercost());
    }
    setheropowerState(false);
    this->notifyObservers();
    opponent->notifyObservers();
}

void Player::useHeropower(Player * opponent, bool onme, bool testing){
    if(!getheropowerState()){
        InvalidMove e{"You can only use your hero power once per turn."};
        throw e;
    }
    if(!testing && getmagic() < getheropowercost()){
        InvalidMove e {"You don't have enough magic."};
        throw e;
    }

    if(gethero() == "Mage"){
        if(onme){
            setlife(getlife() - 1);
        } else {
            opponent->setlife(opponent->getlife() - 1);
        }
    } else if(gethero() == "Druid"){
        if(onme){
            InvalidMove e{"You cannot target on yourself."};
            throw e;
        } else {
            sethattackval(gethattackval() + 1);
            opponent->setlife(opponent->getlife() - gethattackval());
            setlife(getlife() + 1);
        }
    }
    if(testing && getmagic() < getheropowercost()) {
        setmagic(0);
    } else {
        setmagic(getmagic() - getheropowercost());
    }
    setheropowerState(false);
    this->notifyObservers();
    opponent->notifyObservers();
}

void Player::useHeropower(Player * opponent, int t, bool onme, bool testing){
    if(!getheropowerState()){
        InvalidMove e{"You can only use your hero power once per turn."};
        throw e;
    }
    if(!testing && getmagic() < getheropowercost()){
        InvalidMove e {"You don't have enough magic."};
        throw e;
    }

    if(gethero() == "Mage"){
        if(onme){
            if (t > static_cast<int>((this->getminionslot()).size()) || t <= 0) {
                InvalidPosition e{"No minion is placed at this position."};
                throw e;
            }
            getminionslot()[t - 1]->setdefenceval(getminionslot()[t - 1]->getdefenceval() - 1);
            if(getminionslot()[t - 1]->miniondead()){
                this->trigger(GameStage::minionLeave, nullptr, opponent);
                opponent->trigger(GameStage::minionLeave, nullptr, this);
                getminionslot()[t - 1]->toGraveyard(this, t);
            }
        } else {
            if (t > static_cast<int>((opponent->getminionslot()).size()) || t <= 0) {
                InvalidPosition e{"No minion is placed at this position."};
                throw e;
            }
            opponent->getminionslot()[t - 1]->setdefenceval(opponent->getminionslot()[t - 1]->getdefenceval() - 1);
            if(opponent->getminionslot()[t - 1]->miniondead()){
                this->trigger(GameStage::minionLeave, nullptr, opponent);
                opponent->trigger(GameStage::minionLeave, nullptr, this);
                opponent->getminionslot()[t - 1]->toGraveyard(opponent, t);
            }
        }
    } else if(gethero() == "Druid"){
        if (onme){
            InvalidMove e{"You can't attack your own minions"};
            throw e;
        } else {
            if (t > static_cast<int>((opponent->getminionslot()).size()) || t <= 0) {
                InvalidPosition e{"No minion is placed at this position."};
                throw e;
            }
            sethattackval(gethattackval() + 1);
            auto mini = opponent->getminionslot()[t - 1];
            const int att = mini->getattackval();
            const int def = mini->getdefenceval();
            mini->setdefenceval(def - gethattackval());
            setlife(getlife() - att + 1);
            if(mini->miniondead()){
                this->trigger(GameStage::minionLeave, nullptr, opponent);
                opponent->trigger(GameStage::minionLeave, nullptr, this);
                mini->toGraveyard(opponent, t);
            }
        } 
    }

    if(testing && getmagic() < getheropowercost()) {
        setmagic(0);
    } else {
        setmagic(getmagic() - getheropowercost());
    }
    setheropowerState(false);
    this->notifyObservers();
    opponent->notifyObservers();
}


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

void Player::discard(int i){
    if (i > static_cast<int>((this->gethand()).size()) || i <= 0) {
        InvalidPosition e{"No card is placed at this position."};
        throw e;
    }
    gethand().erase(gethand().begin() + i - 1);
    this->notifyObservers();
}

void Player::attack(int i, Player * p) {
    if (i > static_cast<int>((this->getminionslot()).size()) || i <= 0) {
        InvalidPosition e{"No minion is placed at this position."};
        throw e;
    }
    if ((this->getminionslot())[i - 1]->getaction() <= 0) {
        InvalidMove e {"Not enough action points."};
        throw e;
    }
    // real attack
    (this->getminionslot())[i - 1]->minionAttack(p);
    (this->getminionslot())[i - 1]->setaction(getminionslot()[i - 1]->getaction() - 1);

    this->notifyObservers();
    p->notifyObservers();
}

void Player::attack(int i, Player * p, int j) {
    // check valid input
    if (i > static_cast<int>((this->getminionslot()).size()) || i <= 0) {
        InvalidPosition e {"No minion is placed at this position in your minion slot."};
        throw e;
    }
    if (j > static_cast<int>((p->getminionslot()).size()) || j <= 0) {
        InvalidPosition e {"No minion is placed at this position in your opponent's minion slot."};
        throw e;
    }
    // check action
    if ((this->getminionslot())[i - 1]->getaction() <= 0) {
        InvalidMove e {"Not enough action points."};
        throw e;
    }
    // real attack
    (this->getminionslot())[i - 1]->minionAttack(p, j);
    (p->getminionslot())[j - 1]->minionAttack(this, i);
    (this->getminionslot())[i - 1]->setaction(getminionslot()[i - 1]->getaction() - 1);

    if ((this->getminionslot())[i - 1]->miniondead()) {
        this->trigger(GameStage::minionLeave, nullptr, p);
        p->trigger(GameStage::minionLeave, nullptr, this);
        (this->getminionslot())[i - 1]->toGraveyard(this, i);
    }

    if ((p->getminionslot())[j - 1]->miniondead()) {
        this->trigger(GameStage::minionLeave, nullptr, p);
        p->trigger(GameStage::minionLeave, nullptr, this);
        (p->getminionslot())[j - 1]->toGraveyard(p, j);
    }
    this->notifyObservers();
    p->notifyObservers();
}

void Player::play(int i, Player * opponent, bool testing){
    // testing mode
    // not enough magic
    if(i > static_cast<int>(gethand().size()) || i <= 0) {
        InvalidPosition e {"No card at this position."};
        throw e;
    }
    
    if (!testing && getmagic() < gethand()[i - 1]->getcost()){
        InvalidMove e {"Not enough magic."};
        throw e;
    }

    const int m = getmagic() - gethand()[i - 1]->getcost();
    gethand()[i - 1]->playCard(this, opponent, i);
    if (testing && m < 0) {
        setmagic(0);
    } else {
        setmagic(m);
    }
    this->notifyObservers();
    opponent->notifyObservers();
}

void Player::playonRitual(int i, Player * opponent, bool onme, bool testing){
    // testing mode
    // not enough magic
    if(i > static_cast<int>(gethand().size()) || i <= 0) {
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
    gethand()[i - 1]->playCardonRitual(this, opponent, i, onme);
    if (testing && m < 0) {
        setmagic(0);
    } else {
        setmagic(m);
    }
    this->notifyObservers();
    opponent->notifyObservers();
}

void Player::play(int i, Player * opponent, int t, bool onme, bool testing){
    // testing mode, not enough magic
    if(i > static_cast<int>(gethand().size()) || i <= 0) {
        InvalidPosition e {"No card at this position."};
        throw e;
    }

    if (!testing && getmagic() < gethand()[i - 1]->getcost()){
        InvalidMove e {"Not enough magic."};
        throw e;
    }

    if(onme) {
        if (static_cast<int>(getminionslot().size()) < t || t <= 0){
            InvalidPosition e {"Not a valid target at this position."};
            throw e;
        }
    } else {
        if (static_cast<int>(opponent->getminionslot().size()) < t || t <= 0){
            InvalidPosition e {"Not a valid target at this position."};
            throw e;
        }
    }

    const int m = getmagic() - gethand()[i - 1]->getcost();
    gethand()[i - 1]->playCard(this, opponent, i, onme, t);
    if (testing && m < 0) {
        setmagic(0);
    } else {
        setmagic(m);
    }
    this->notifyObservers();
    opponent->notifyObservers();
}


void Player::trigger(GameStage state, std::shared_ptr<Card> c, Player * opponent){
    if(state == GameStage::startTurn){
        if(getactiveRitual().size() != 0 && getactiveRitual()[0]->getcardName() == "Dark Ritual"){
            try{
                getactiveRitual()[0]->triggereffect(this, opponent, nullptr);
            } catch(InvalidMove &e){}
        }
    } else if(state == GameStage::endTurn){
        for(int i = 0; i < static_cast<int>(getminionslot().size()); i++){
            if(getminionslot()[i]->getcardName() == "Potion Seller"){
                for(int j = 0; j < static_cast<int>(getminionslot().size()); j++){
                    getminionslot()[i]->triggereffect(this, opponent, getminionslot()[j].get());
                }
            }
        }
    } else if(state == GameStage::curNewMinion){
        if(getactiveRitual().size() != 0 && getactiveRitual()[0]->getcardName() == "Aura of Power"){
            try{
                getactiveRitual()[0]->triggereffect(this, opponent, c.get());
            } catch (InvalidMove &e){}
        } else if(getactiveRitual().size() != 0 && getactiveRitual()[0]->getcardName() == "Standstill"){
            try{
                getactiveRitual()[0]->triggereffect(this, opponent, c.get());
            } catch (InvalidMove &e){}
        }
    } else if(state == GameStage::oppNewMinion){
        if(getactiveRitual().size() != 0 && getactiveRitual()[0]->getcardName() == "Standstill"){
            try{
                getactiveRitual()[0]->triggereffect(opponent, this, c.get());
            } catch (InvalidMove &e){
                for(int i = 0; i < static_cast<int>(getminionslot().size()); i++){
                    if(getminionslot()[i]->getcardName() == "Fire Elemental"){
                        getminionslot()[i]->triggereffect(this, opponent, c.get());
                    }
                }
            }
        } else {
            for(int i = 0; i < static_cast<int>(getminionslot().size()); i++){
                if(getminionslot()[i]->getcardName() == "Fire Elemental"){
                    getminionslot()[i]->triggereffect(this, opponent, c.get());
                }
            }
        }
        
    } else if(state == GameStage::minionLeave){
        for(int i = 0; i < static_cast<int>(getminionslot().size()); i++){
            if(getminionslot()[i]->getcardName() == "Bone Golem"){
                getminionslot()[i]->triggereffect(this, opponent, getminionslot()[i].get());
            }
        }
    }
    this->notifyObservers();
    opponent->notifyObservers();
}

void Player::use(int i, Player * opponent, bool testing){
    // testing mode
    // not enough magic
    if (!testing && getmagic() < getminionslot()[i - 1]->getabilityCost()){
        InvalidMove e {"Not enough magic."};
        throw e;
    }
    if (!testing && getminionslot()[i - 1]->getaction() <= 0){
        InvalidMove e {"Not enough action points."};
        throw e;
    }
    if(i > static_cast<int>(getminionslot().size()) || i <= 0) {
        InvalidPosition e {"No card at this position."};
        throw e;
    }
    const int m = getmagic() - getminionslot()[i - 1]->getabilityCost();
    getminionslot()[i - 1]->useMinion(this, opponent);
    if (testing && m < 0) {
        setmagic(0);
    } else {
        setmagic(m);
    }
    getminionslot()[i - 1]->setaction(getminionslot()[i - 1]->getaction() - 1);
    this->notifyObservers();
    opponent->notifyObservers();
}


void Player::use(int i, Player * opponent, int t, bool onme, bool testing){
    // testing mode
    // not enough magic
    if (!testing && getmagic() < getminionslot()[i - 1]->getabilityCost()){
        InvalidMove e {"Not enough magic."};
        throw e;
    }
    if (!testing && getminionslot()[i - 1]->getaction() <= 0){
        InvalidMove e {"Not enough action points."};
        throw e;
    }

    if(i > static_cast<int>(getminionslot().size()) || i <= 0) {
        InvalidPosition e {"No card at this position."};
        throw e;
    }

    if(onme) {
        if (static_cast<int>(getminionslot().size()) < t || t <= 0){
            InvalidPosition e {"Not a valid target at this position."};
            throw e;
        }
    } else {
        if (static_cast<int>(opponent->getminionslot().size()) < t || t <= 0){
            InvalidPosition e {"Not a valid target at this position."};
            throw e;
        }
    }
    const int m = getmagic() - getminionslot()[i - 1]->getabilityCost();
    if (onme){
        getminionslot()[i - 1]->useMinion(opponent, this, getminionslot()[t - 1].get(), t);
    } else {
        getminionslot()[i - 1]->useMinion(this, opponent, opponent->getminionslot()[t - 1].get(), t);
    }
    if (testing && m < 0) {
        setmagic(0);
    } else {
        setmagic(m);
    }
    getminionslot()[i - 1]->setaction(getminionslot()[i - 1]->getaction() - 1);
    this->notifyObservers();
    opponent->notifyObservers();
}

void Player::initTurn(){
    gainMagic();
    gainAction();
    setheropowerState(true);
    try {
        drawcard();
    } 
    catch(ExceedMaximum &e){}
}

bool Player::die() {return (getlife() <= 0);}

void Player::gainMagic(){magic += 1;}

void Player::gainAction(){
    for (auto i: getminionslot()){
        i->gainAction();
    }
}

void Player::gainCoin(){
    std::shared_ptr<Coin> p = std::make_shared<Coin>();
    gethand().emplace_back(p);
}

