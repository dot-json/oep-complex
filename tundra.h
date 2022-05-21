#ifndef BEAD_TUNDRA_H
#define BEAD_TUNDRA_H
#include <vector>
#include "colony.h"

class Tundra{
public:
    Tundra(){};
    ~Tundra(){
        preys.clear();
        hunters.clear();
    }

    void addPreyColony(Colony* colony){
        preys.push_back(colony);
    }
    void addHunterColony(Colony* colony){
        hunters.push_back(colony);
    }
    std::vector<Colony*> getPreyColonies(){
        return preys;
    }
    std::vector<Colony*> getHunterColonies(){
        return hunters;
    }

private:
    std::vector<Colony*> preys{};
    std::vector<Colony*> hunters{};
};

#endif //BEAD_TUNDRA_H
