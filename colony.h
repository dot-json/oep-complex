#ifndef BEAD_COLONY_H
#define BEAD_COLONY_H
#include <string>

class Colony {
public:
    Colony(std::string nickname, std::string species, int count) {
        this->name = nickname;
        this->species = species;
        this->count = count;
    }
    virtual ~Colony() {}

    virtual void Destroy() {delete this;}
    virtual void Hunt(Colony* prey){}
    virtual void Hunted(Colony* hunter){}
    virtual bool canBeHunted(Colony* hunter){ return false; }
    virtual void nextRound(int round){}
    virtual int getOriginalCount() { return 0; }

    std::string getName(){
        return name;
    }
    std::string getSpecies(){
        return species;
    }
    int getCount(){
        return count;
    }
    void setCount(int count){
        this->count = count;
    }

private:
    std::string name;
    std::string species;
    int count;
};

#endif //BEAD_COLONY_H
