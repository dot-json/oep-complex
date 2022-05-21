#ifndef BEAD_CANIMALS_H
#define BEAD_CANIMALS_H
#include "colony.h"
// RAGADOZOK ============================================================================
class HobagolyKolonia : public Colony{
public:
    HobagolyKolonia(std::string name, int count) : Colony(name, "hobagoly", count){}
    void Hunt(Colony* prey) override{
        if (!prey->canBeHunted(this)){
            setCount(getCount() - getCount() / 4);
        } else {
            prey->Hunted(this);
        }
    }
    void nextRound(int round) override{
        if (round % 8 == 0){
            setCount(getCount() + getCount() / 4);
        }
    }
    void Destroy() override{
        delete this;
    }
};

class SarkiRokaKolonia : public Colony{
public:
    SarkiRokaKolonia(std::string name, int count) : Colony(name, "sarki_roka", count){}
    void Hunt(Colony* prey) override{
        if (!prey->canBeHunted(this)){
            setCount(getCount() - getCount() / 4);
        } else {
            prey->Hunted(this);
        }
    }
    void nextRound(int round) override{
        if (round % 8 == 0){
            setCount(getCount() + getCount() * (3 / 4));
        }
    }
    void Destroy() override{
        delete this;
    }
};

class FarkasKolonia : public Colony{
public:
    FarkasKolonia(std::string name, int count) : Colony(name, "farkas", count){}
    void Hunt(Colony* prey) override{
        if (!prey->canBeHunted(this)){
            setCount(getCount() - getCount() / 4);
        } else {
            prey->Hunted(this);
        }
    }
    void nextRound(int round) override{
        if (round % 8 == 0){
            setCount(getCount() + getCount() * (2 / 4));
        }
    }
    void Destroy() override{
        delete this;
    }
};
// ======================================================================================

// ZSAKMANYOK ===========================================================================
class LemmingKolonia : public Colony{
public:
    LemmingKolonia(std::string name, int count) : Colony(name, "lemming", count){ this->oCount = count; }


    void Hunted(Colony* hunter) override{
        setCount(getCount() - hunter->getCount() * 4);
    }
    void nextRound(int round) override{
        if (round % 2 == 0){
            setCount(getCount() * 2);
        }
        if (getCount() > 200){
            setCount(30);
        }
    }
    bool canBeHunted(Colony* hunter) override{
        if ((getCount() - hunter->getCount() * 4) < 0){
            return false;
        } else {
            return true;
        }
    }
    void Destroy() override{
        delete this;
    }
    int getOriginalCount() override{
        return oCount;
    }
private:
    int oCount;
};

class NyulKolonia : public Colony{
public:
    NyulKolonia(std::string name, int count) : Colony(name, "nyul", count){ this->oCount = count; }

    void Hunted(Colony* hunter) override{
        setCount(getCount() - hunter->getCount() * 2);
    }
    void nextRound(int round) override{
        if (round % 2 == 0){
            setCount(getCount() * 1.5);
        }
        if (getCount() > 100){
            setCount(20);
        }
    }
    bool canBeHunted(Colony* hunter) override{
        if ((getCount() - hunter->getCount() * 2) < 0){
            return false;
        } else {
            return true;
        }
    }
    void Destroy() override{
        delete this;
    }
    int getOriginalCount() override{
        return oCount;
    }
private:
    int oCount;
};

class UrgeKolonia : public Colony{
public:
    UrgeKolonia(std::string name, int count) : Colony(name, "urge", count){ this->oCount = count; }

    void Hunted(Colony* hunter) override{
        setCount(getCount() - hunter->getCount() * 2);
    }
    void nextRound(int round) override{
        if (round % 4 == 0){
            setCount(getCount() * 2);
        }
        if (getCount() > 200){
            setCount(40);
        }
    }
    bool canBeHunted(Colony* hunter) override{
        if ((getCount() - hunter->getCount() * 2) < 0){
            return false;
        } else {
            return true;
        }
    }
    void Destroy() override{
        delete this;
    }
    int getOriginalCount() override{
        return oCount;
    }
private:
    int oCount;
};
// ======================================================================================


#endif //BEAD_CANIMALS_H
