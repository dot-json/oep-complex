#include <iostream>
#include <memory>
#include <vector>
#include <ctime>
#include "cAnimals.h"
#include "reader.h"
#include "tundra.h"


bool endState(std::vector<Colony*> hunters);

#ifdef NORMAL_MODE

int main() {
    srand(time(NULL));
    std::string fileName;
    std::cout << "file: ";
    std::cin >> fileName;

    auto cReader = std::make_unique<Reader>(fileName);
    auto cTundra = std::make_unique<Tundra>();

    cReader->read();

    for (int i = 0; i < cReader->n; i++){
        switch (cReader->content[i].type) {
            case 'l':
                cTundra->addPreyColony(new LemmingKolonia(cReader->content[i].name, cReader->content[i].count));
                break;
            case 'n':
                cTundra->addPreyColony(new NyulKolonia(cReader->content[i].name, cReader->content[i].count));
                break;
            case 'u':
                cTundra->addPreyColony(new UrgeKolonia(cReader->content[i].name, cReader->content[i].count));
                break;
        }
    }
    for (int i = cReader->n; i < (cReader->m + cReader->n); i++){
        switch (cReader->content[i].type) {
            case 'h':
                cTundra->addHunterColony(new HobagolyKolonia(cReader->content[i].name, cReader->content[i].count));
                break;
            case 's':
                cTundra->addHunterColony(new SarkiRokaKolonia(cReader->content[i].name, cReader->content[i].count));
                break;
            case 'f':
                cTundra->addHunterColony(new FarkasKolonia(cReader->content[i].name, cReader->content[i].count));
                break;
        }
    }

    int round = 1;
    while (!endState(cTundra->getHunterColonies())){
        std::cout << "kor: " << round << std::endl;
        for (const auto& hunter : cTundra->getHunterColonies()){
            int num = rand() % (cTundra->getPreyColonies().size() - 1);
            hunter->Hunt(cTundra->getPreyColonies()[num]);
            hunter->nextRound(round);
            std::cout << "nev: " << hunter->getName() << " | faj: " << hunter->getSpecies() << " | egyedek: " << hunter->getCount() << std::endl;
        }

        for (const auto& prey : cTundra->getPreyColonies()){
            prey->nextRound(round);
            std::cout << "nev: " << prey->getName() << " | faj: " << prey->getSpecies() << " | egyedek: " << prey->getCount() << std::endl;
        }

        std::cout << "=======================================" << std::endl;
        round++;
    }

    for (const auto& e : cTundra->getPreyColonies()){
        e->Destroy();
    }
    for (const auto& e : cTundra->getHunterColonies()){
        e->Destroy();
    }
    cReader.reset();
    cTundra.reset();

    return 0;
}



#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

bool endState(std::vector<Colony*> hunters){
    bool state = true;
    for (const auto& e : hunters){
        if (e->getCount() >= 4){
            state = false;
        }
    }
    for (const auto& e : hunters){
        if (e->getCount() >= 4){
            state = false;
        }
    }
    return state;
}

TEST_CASE("Check simulation succession", "[vector]"){
    srand(time(NULL));
    std::string fileName = "inp.txt";

    auto cReader = std::make_unique<Reader>(fileName);
    auto cTundra = std::make_unique<Tundra>();

    cReader->read();
    for (int i = 0; i < cReader->n; i++){
    switch (cReader->content[i].type) {
        case 'l':
            cTundra->addPreyColony(new LemmingKolonia(cReader->content[i].name, cReader->content[i].count));
        break;
        case 'n':
            cTundra->addPreyColony(new NyulKolonia(cReader->content[i].name, cReader->content[i].count));
        break;
        case 'u':
            cTundra->addPreyColony(new UrgeKolonia(cReader->content[i].name, cReader->content[i].count));
        break;
        }
    }

    for (int i = cReader->n; i < (cReader->m + cReader->n); i++){
        switch (cReader->content[i].type) {
            case 'h':
                cTundra->addHunterColony(new HobagolyKolonia(cReader->content[i].name, cReader->content[i].count));
            break;
            case 's':
                cTundra->addHunterColony(new SarkiRokaKolonia(cReader->content[i].name, cReader->content[i].count));
            break;
            case 'f':
                cTundra->addHunterColony(new FarkasKolonia(cReader->content[i].name, cReader->content[i].count));
            break;
        }
    }

    int round = 1;
    while (!endState(cTundra->getHunterColonies())){
        std::cout << "kor: " << round << std::endl;
        for (const auto& hunter : cTundra->getHunterColonies()){
            int num = rand() % (cTundra->getPreyColonies().size() - 1);
            hunter->Hunt(cTundra->getPreyColonies()[num]);
            hunter->nextRound(round);
            std::cout << "nev: " << hunter->getName() << " | faj: " << hunter->getSpecies() << " | egyedek: " << hunter->getCount() << std::endl;
        }

        for (const auto& prey : cTundra->getPreyColonies()){
            prey->nextRound(round);
            std::cout << "nev: " << prey->getName() << " | faj: " << prey->getSpecies() << " | egyedek: " << prey->getCount() << std::endl;
        }

        std::cout << "=======================================" << std::endl;
        round++;
    }

    for (const auto& e : cTundra->getHunterColonies()){
        std::cout << e->getCount() << std::endl;
        REQUIRE(e->getCount() < 4);
    }

    for (const auto& e : cTundra->getPreyColonies()){
        e->Destroy();
    }

    for (const auto& e : cTundra->getHunterColonies()){
        e->Destroy();
    }

    cReader.reset();
    cTundra.reset();
}
#endif // NORMAL_MODE