#include "ascii_graphics.h"
#include "concreteminion.h"
#include "concretespell.h"
#include "concreteritual.h"
#include "concreteenchantment.h"

const int maxMagic = 5;
const int heroPowerCost = 1;
const int maxLife = 20;
const int initialMagic = 0;
const int maxMinionNum = 5;
const int maxHandNum = 5;

Player::Player(std::string playerName, int playerNum, std::string hero, bool first): 
    playerName{playerName}, hero{hero}, playerNum{playerNum}, life{maxLife}, magic{initialMagic}, round{0}, hattackval{0}, heropowerState{true}, heropowercost{heroPowerCost}, first{first} {}

//take other->deck/hand/minionslot/graveyard/activeRitual
//make_shared, shared ptr assign
//need the selfvec parameter to indicate which vector to load into
static void duplicateCard(std::vector<std::shared_ptr<Card>> & selfvec, const std::vector<std::shared_ptr<Card>> & othervec){
    for(int i = 0; i < othervec.size(); i++){
        const auto tmp = othervec[i];
        std::string card = tmp->getcardName(); // get card name
        
        // construct and do the assignment
        if (card == "Air Elemental"){
            std::shared_ptr<Airelemental> p = std::make_shared<Airelemental>();
            p->setcost(tmp->getcost());
            p->setattackval(tmp->getattackval());
            p->setdefenceval(tmp->getdefenceval());
            p->setabilityCost(tmp->getabilityCost());
            p->setaction(tmp->getaction());
            p->setactioneachturn(tmp->getactioneachturn());
            p->getEnchantmentadded() = tmp->getEnchantmentadded();
            p->setcanuse(tmp->getcanuse());
            selfvec.emplace_back(p);
        } else if (card == "Earth Elemental"){
            std::shared_ptr<Earthelemental> p = std::make_shared<Earthelemental>();
            p->setcost(tmp->getcost());
            p->setattackval(tmp->getattackval());
            p->setdefenceval(tmp->getdefenceval());
            p->setabilityCost(tmp->getabilityCost());
            p->setaction(tmp->getaction());
            p->setactioneachturn(tmp->getactioneachturn());
            p->getEnchantmentadded() = tmp->getEnchantmentadded();
            p->setcanuse(tmp->getcanuse());
            selfvec.emplace_back(p);
        } else if (card == "Bone Golem"){
            std::shared_ptr<Bonegolem> p = std::make_shared<Bonegolem>();
            p->setcost(tmp->getcost());
            p->setattackval(tmp->getattackval());
            p->setdefenceval(tmp->getdefenceval());
            p->setabilityCost(tmp->getabilityCost());
            p->setaction(tmp->getaction());
            p->setactioneachturn(tmp->getactioneachturn());
            p->getEnchantmentadded() = tmp->getEnchantmentadded();
            p->setcanuse(tmp->getcanuse());
            selfvec.emplace_back(p);
        } else if (card == "Fire Elemental"){
            std::shared_ptr<Fireelemental> p = std::make_shared<Fireelemental>();
            p->setcost(tmp->getcost());
            p->setattackval(tmp->getattackval());
            p->setdefenceval(tmp->getdefenceval());
            p->setabilityCost(tmp->getabilityCost());
            p->setaction(tmp->getaction());
            p->setactioneachturn(tmp->getactioneachturn());
            p->getEnchantmentadded() = tmp->getEnchantmentadded();
            p->setcanuse(tmp->getcanuse());
            selfvec.emplace_back(p);
        } else if (card == "Potion Seller"){
            std::shared_ptr<Potionseller> p = std::make_shared<Potionseller>();
            p->setcost(tmp->getcost());
            p->setattackval(tmp->getattackval());
            p->setdefenceval(tmp->getdefenceval());
            p->setabilityCost(tmp->getabilityCost());
            p->setaction(tmp->getaction());
            p->setactioneachturn(tmp->getactioneachturn());
            p->getEnchantmentadded() = tmp->getEnchantmentadded();
            p->setcanuse(tmp->getcanuse());
            selfvec.emplace_back(p);
        } else if (card == "Novice Pyromancer"){
            std::shared_ptr<Novicepyromancer> p = std::make_shared<Novicepyromancer>();
            p->setcost(tmp->getcost());
            p->setattackval(tmp->getattackval());
            p->setdefenceval(tmp->getdefenceval());
            p->setabilityCost(tmp->getabilityCost());
            p->setaction(tmp->getaction());
            p->setactioneachturn(tmp->getactioneachturn());
            p->getEnchantmentadded() = tmp->getEnchantmentadded();
            p->setcanuse(tmp->getcanuse());
            selfvec.emplace_back(p);
        } else if (card == "Apprentice Summoner"){
            std::shared_ptr<Apprenticesummoner> p = std::make_shared<Apprenticesummoner>();
            p->setcost(tmp->getcost());
            p->setattackval(tmp->getattackval());
            p->setdefenceval(tmp->getdefenceval());
            p->setabilityCost(tmp->getabilityCost());
            p->setaction(tmp->getaction());
            p->setactioneachturn(tmp->getactioneachturn());
            p->getEnchantmentadded() = tmp->getEnchantmentadded();
            p->setcanuse(tmp->getcanuse());
            selfvec.emplace_back(p);
        } else if (card == "Master Summoner"){
            std::shared_ptr<Mastersummoner> p = std::make_shared<Mastersummoner>();
            p->setcost(tmp->getcost());
            p->setattackval(tmp->getattackval());
            p->setdefenceval(tmp->getdefenceval());
            p->setabilityCost(tmp->getabilityCost());
            p->setaction(tmp->getaction());
            p->setactioneachturn(tmp->getactioneachturn());
            p->getEnchantmentadded() = tmp->getEnchantmentadded();
            p->setcanuse(tmp->getcanuse());
            selfvec.emplace_back(p);
        } else if (card == "Banish"){
            std::shared_ptr<Banish> p = std::make_shared<Banish>();
            p->setcost(tmp->getcost());
            selfvec.emplace_back(p);
        } else if (card == "Unsummon"){
            std::shared_ptr<Unsummon> p = std::make_shared<Unsummon>();
            p->setcost(tmp->getcost());
            selfvec.emplace_back(p);
        } else if (card == "Recharge"){
            std::shared_ptr<Recharge> p = std::make_shared<Recharge>();
            p->setcost(tmp->getcost());
            selfvec.emplace_back(p);
        } else if (card == "Disenchant"){
            std::shared_ptr<Disenchant> p = std::make_shared<Disenchant>();
            p->setcost(tmp->getcost());
            selfvec.emplace_back(p);
        } else if (card == "Raise Dead"){
            std::shared_ptr<Raisedead> p = std::make_shared<Raisedead>();
            p->setcost(tmp->getcost());
            selfvec.emplace_back(p);
        } else if (card == "Blizzard"){
            std::shared_ptr<Blizzard> p = std::make_shared<Blizzard>();
            p->setcost(tmp->getcost());
            selfvec.emplace_back(p);
        } else if (card == "Giant Strength"){
            std::shared_ptr<Giantstrength> p = std::make_shared<Giantstrength>(nullptr);
            p->setcost(tmp->getcost());
            selfvec.emplace_back(p);
        } else if (card == "Enrage"){
            std::shared_ptr<Enrage> p = std::make_shared<Enrage>(nullptr);
            p->setcost(tmp->getcost());
            selfvec.emplace_back(p);
        } else if (card == "Haste"){
            std::shared_ptr<Haste> p = std::make_shared<Haste>(nullptr);
            p->setcost(tmp->getcost());
            selfvec.emplace_back(p);
        } else if (card == "Magic Fatigue"){
            std::shared_ptr<Magicfatigue> p = std::make_shared<Magicfatigue>(nullptr);
            p->setcost(tmp->getcost());
            selfvec.emplace_back(p);
        } else if (card == "Silence"){
            std::shared_ptr<Silence> p = std::make_shared<Silence>(nullptr);
            p->setcost(tmp->getcost());
            selfvec.emplace_back(p);
        } else if (card == "Dark Ritual"){
            std::shared_ptr<Darkritual> p = std::make_shared<Darkritual>();
            p->setcost(tmp->getcost());
            p->setactivationCost(tmp->getactivationCost());
            p->setcharge(tmp->getcharge());
            selfvec.emplace_back(p);
        } else if (card == "Aura of Power"){
            std::shared_ptr<Auraofpower> p = std::make_shared<Auraofpower>();
            p->setcost(tmp->getcost());
            p->setactivationCost(tmp->getactivationCost());
            p->setcharge(tmp->getcharge());
            selfvec.emplace_back(p);
        } else if (card == "Standstill"){
            std::shared_ptr<Standstill> p = std::make_shared<Standstill>();
            p->setcost(tmp->getcost());
            p->setactivationCost(tmp->getactivationCost());
            p->setcharge(tmp->getcharge());
            selfvec.emplace_back(p);
        } else if (card == "Coin"){
            std::shared_ptr<Coin> p = std::make_shared<Coin>();
            p->setcost(tmp->getcost());
            selfvec.emplace_back(p);
        }
    }
}

// copy ctor
Player::Player(const Player & other):
    playerName{other.playerName}, hero{other.hero}, 
    playerNum{other.playerNum}, life{other.life}, magic{other.magic}, 
    round{other.round}, hattackval{other.hattackval}, 
    heropowerState{other.heropowerState}, heropowercost{other.heropowercost} {    
        //ignoring the observers, and player card? they are for display only
        //duplicate all cards
        duplicateCard(deck, other.deck);
        duplicateCard(hand, other.hand);
        duplicateCard(minionslot, other.minionslot);
        duplicateCard(graveyard, other.graveyard);
        duplicateCard(activeRitual, other.activeRitual);       
    }

std::string & Player::gethero() {return hero;}
int Player::getplayerNum() const{return playerNum;}
int Player::getlife() const{return life;}
int Player::getmagic() const{return magic;}
int Player::getround() const{return round;}
int Player::gethattackval() const {return hattackval;}
bool Player::getheropowerState () const {return heropowerState;}
int Player::getheropowercost () const {return heropowercost;}
bool Player::getfirst () const {return first;}
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
void Player::setmagic (int nmagic){
    magic = nmagic;
    if (nmagic >= maxMagic){
        magic = maxMagic;
    }
    if (nmagic <= 0){
        magic = 0;
    }
}
void Player::sethattackval (int nhattackval){
    hattackval = nhattackval;
    if (nhattackval <= 0){
        hattackval = 0;
    }
}
void Player::setheropowerState(bool nheropowerState){heropowerState = nheropowerState;}
void Player::setheropowercost(int nheropowercost){heropowercost = nheropowercost;}
void Player::setfirst(bool nfirst){first = nfirst;}

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
        if(getminionslot().size() >= maxMinionNum){
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
        if(hand.size()>= maxHandNum){
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
    if(hand.size()>= maxHandNum){
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

    int m = gethand()[i - 1]->getcost();
    gethand()[i - 1]->playCard(this, opponent, i);
    m = getmagic() - m;
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
    nextRound();
    gainMagic();
    gainAction();
    setheropowerState(true);
    try {
        drawcard();
    } 
    catch(ExceedMaximum &e){}
}

bool Player::die() {return (getlife() <= 0);}

void Player::gainMagic(){setmagic(getround());}

void Player::gainOneMagicForce(){magic += 1;}

void Player::nextRound(){round += 1;}

void Player::gainAction(){
    for (auto i: getminionslot()){
        i->gainAction();
    }
}

void Player::gainCoin(){
    std::shared_ptr<Coin> p = std::make_shared<Coin>();
    gethand().emplace_back(p);
}

double Player::evalState(Player * opponent){
    const double MIN_MARK = 0;
    const double MAX_MARK = 100;
    int DANGER_LIFE = 2;

    double mark = MIN_MARK;
    double survive_mark = 50;
    double minion_mark = 0;
    double minion_num_mark = 50;
    double minion_attack_mark = 50;
    // adv in each minion?
    // double minion_each_mark = 0;
    double ritual_mark = 50;
    double hand_mark = 50;

    if (die() && !(opponent->die())) return MIN_MARK;
    if (!die() && opponent->die()) return MAX_MARK;
    if (die() && opponent->die()) return (MIN_MARK + MAX_MARK) / 2;
    
    int oppoTotalAttack = 0;
    for (auto i: opponent->getminionslot()){
        oppoTotalAttack += i->getattackval() * i->getactioneachturn();
    }
    int oppo_minion_attack_total = oppoTotalAttack;
    int oppo_magic_available = getround();
    if (getfirst() == false) oppo_magic_available += 1;
    if (oppo_magic_available > maxMagic) oppo_magic_available = maxMagic;
    for (auto i: opponent->gethand()){
        if (i->getcardName() == "Coin"){
            oppo_magic_available += 1;
        }
    }
    if (opponent->getactiveRitual().size() != 0 && 
        opponent->getactiveRitual()[0]->getcardName() == "Dark Ritual") oppo_magic_available+= 1;
    if (oppo_magic_available >= 2){
        if (opponent->gethero() == "Mage" || opponent->gethero() == "Druid"){
            oppoTotalAttack += 1;
        } else if (opponent->gethero() == "Hunter") {
            oppoTotalAttack += 2;
        }
    }

    // be dead next turn
    if (oppoTotalAttack >= getlife()) return MIN_MARK;
    if (oppoTotalAttack >= getlife() - DANGER_LIFE) survive_mark -= 30;

    int myTotalAttack = 0;
    for (auto j: getminionslot()){
        myTotalAttack += j->getattackval() * j->getactioneachturn();
    }
    int my_minion_attack_total = myTotalAttack;

    int magic_available = getround() + 1;
    if (magic_available > maxMagic) magic_available = maxMagic;
    if (getactiveRitual().size() != 0 && 
        getactiveRitual()[0]->getcardName() == "Dark Ritual" && 
        getactiveRitual()[0]->getcharge() >= 1) magic_available+= 1;
        // should be using getactiveRitual()[0]->getactivationCost() above, but card does not have a member function called getactivationCost(). 
    // calculate based on hand and ability
    int giant_strength_count = 0;
    int enrage_count = 0;
    int haste_count = 0;
    for(auto k: gethand()){
        if (k->getcardName() == "Giant Strength"){
            giant_strength_count += 1;
        } else if (k->getcardName() == "Enrage"){
            enrage_count += 1;
        } else if (k->getcardName() == "Haste"){
            haste_count += 1;
        }
    }

    int max_attack = 0;
    int max_attack_val = 0;
    int max_single_attack_val = 0;
    int max_action_each_turn = 0;
    for(int i = 0; i < static_cast<int>(getminionslot().size()); i++){
        int temp = getminionslot()[i]->getattackval() * getminionslot()[i]->getactioneachturn();
        if (getminionslot()[i]->getattackval() >= max_single_attack_val) {
            max_single_attack_val = getminionslot()[i]->getattackval();
        }
        if (temp > max_attack){
            max_attack = temp;
            max_attack_val = getminionslot()[i]->getattackval();
            max_action_each_turn = getminionslot()[i]->getactioneachturn();
        }
    }
    std::vector<std::shared_ptr<Card>> ThreeEnchantments;
    std::shared_ptr<Giantstrength> p1 = std::make_shared<Giantstrength>(nullptr);
    std::shared_ptr<Enrage> p2 = std::make_shared<Enrage>(nullptr);
    std::shared_ptr<Haste> p3 = std::make_shared<Haste>(nullptr);
    int count_for_each_enchantment[3] = {0};
    int ID_for_each_card[3] = {0};
    // determine the order of using these three enchantments
    if (max_attack_val >= 4){ // Enrage > Giant Strength
        if (max_attack_val > 2 * max_single_attack_val){ //Enrage > Haste
            if (max_single_attack_val > 2){ //Enrage > Haste > Giant Strength
                ThreeEnchantments.emplace_back(p2);
                ThreeEnchantments.emplace_back(p3);
                ThreeEnchantments.emplace_back(p1);
                count_for_each_enchantment[0] = enrage_count;
                count_for_each_enchantment[1] = haste_count;
                count_for_each_enchantment[2] = giant_strength_count;
                ID_for_each_card[0] = 2;
                ID_for_each_card[1] = 3;
                ID_for_each_card[2] = 1;
            } else { // Enrage > Giant > Haste
                ThreeEnchantments.emplace_back(p2);
                ThreeEnchantments.emplace_back(p1);
                ThreeEnchantments.emplace_back(p3);
                count_for_each_enchantment[0] = enrage_count;
                count_for_each_enchantment[1] = giant_strength_count;
                count_for_each_enchantment[2] = haste_count;
                ID_for_each_card[0] = 2;
                ID_for_each_card[1] = 1;
                ID_for_each_card[2] = 3;
            }
        } else { // Enrage < Haste, so Haste > Enrage > Giant
            ThreeEnchantments.emplace_back(p3);
            ThreeEnchantments.emplace_back(p2);
            ThreeEnchantments.emplace_back(p1);
            count_for_each_enchantment[0] = haste_count;
            count_for_each_enchantment[1] = enrage_count;
            count_for_each_enchantment[2] = giant_strength_count;
            ID_for_each_card[0] = 3;
            ID_for_each_card[1] = 2;
            ID_for_each_card[2] = 1;
        }
    } else { // Enrage < Giant
        if (max_attack_val > 2 * max_single_attack_val){ // Enrage > Haste, so Giant > Enrage > Haste
            ThreeEnchantments.emplace_back(p1);
            ThreeEnchantments.emplace_back(p2);
            ThreeEnchantments.emplace_back(p3);
            count_for_each_enchantment[0] = giant_strength_count;
            count_for_each_enchantment[1] = enrage_count;
            count_for_each_enchantment[2] = haste_count;
            ID_for_each_card[0] = 1;
            ID_for_each_card[1] = 2;
            ID_for_each_card[2] = 3;
        } else {// Enrage < Haste
            if (max_single_attack_val > 2){ // Haste > Giant > Enrage
                ThreeEnchantments.emplace_back(p3);
                ThreeEnchantments.emplace_back(p1);
                ThreeEnchantments.emplace_back(p2);
                count_for_each_enchantment[0] = haste_count;
                count_for_each_enchantment[1] = enrage_count;
                count_for_each_enchantment[2] = giant_strength_count;
                ID_for_each_card[0] = 3;
                ID_for_each_card[1] = 1;
                ID_for_each_card[2] = 2;
            } else { // Giant > Haste > Enrage
                ThreeEnchantments.emplace_back(p1);
                ThreeEnchantments.emplace_back(p3);
                ThreeEnchantments.emplace_back(p2);
                count_for_each_enchantment[0] = giant_strength_count;
                count_for_each_enchantment[1] = haste_count;
                count_for_each_enchantment[2] = enrage_count;
                ID_for_each_card[0] = 1;
                ID_for_each_card[1] = 3;
                ID_for_each_card[2] = 2;
            }
        }
    }
    for (int i = 0; i < 3; i++){
        int magic_need = count_for_each_enchantment[i] * ThreeEnchantments[i]->getcost();
        if (magic_need > magic_available){
            count_for_each_enchantment[i] = magic_available / ThreeEnchantments[i]->getcost();
            for (int j = i; j < 3; j++){
                count_for_each_enchantment[j] = 0;
            }
            break;
        } else {
            magic_available -= magic_need;
        }
    }
    int increase_in_action = 0;
    for (int i = 0; i < 3; i++){
        int card = ID_for_each_card[i];
        int count = count_for_each_enchantment[i];
        if (card == 1){ // Giant
            max_attack_val += 2 * count;
            max_attack += 2 * count;
            max_single_attack_val += 2* count;
        } else if (card == 2){ // enrage
            for(int j = 0; j < count; j++){
                max_attack_val *= 2;
                max_attack *= 2;
            }
        } else if (card == 3){
            increase_in_action += count;
        }
    }
    // finalize calculating myTotalAttack (next round)
    if (max_single_attack_val > max_attack_val){
        myTotalAttack += max_attack + increase_in_action * max_single_attack_val;
    } else {
        myTotalAttack += max_attack + increase_in_action * max_attack_val;
    }

    if (myTotalAttack >= opponent->getlife()) {
        survive_mark += 50;
    } else if (myTotalAttack >= opponent->getlife() - DANGER_LIFE) {
        survive_mark += 30;
    }
    // calculate minion marks
    int diff_in_minion_attack = my_minion_attack_total - oppo_minion_attack_total;
    minion_attack_mark += diff_in_minion_attack * 10;
    if (minion_attack_mark < 0) minion_attack_mark = 0;
    if (minion_attack_mark > 100) minion_attack_mark = 100;
    int diff_in_minion_num = getminionslot().size() - opponent->getminionslot().size();
    minion_num_mark += diff_in_minion_num * 10;
    if (minion_num_mark < 0) minion_num_mark = 0;
    if (minion_num_mark > 100) minion_num_mark = 100;
    minion_mark = 0.8 * minion_attack_mark + 0.2 * minion_num_mark;

    int diff_in_ritual = getactiveRitual().size() - opponent->getactiveRitual().size();
    ritual_mark += diff_in_ritual * 50;
    if (ritual_mark < 0) ritual_mark = 0;
    if (ritual_mark > 100) ritual_mark = 100;
    int diff_in_hand = gethand().size() - opponent->gethand().size();
    hand_mark += diff_in_hand * 10;
    if (hand_mark < 0) hand_mark = 0;
    if (hand_mark > 100) hand_mark = 100;
    mark = 0.5 * survive_mark + 0.3 * minion_mark + 0.15 * hand_mark + 0.05 * ritual_mark;
    return mark;
}
