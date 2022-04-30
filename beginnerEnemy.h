//
// Created by 12676 on 3/21/2022.
//

#ifndef TEXTBASEDGAME001_BEGINNERENEMY_H
#define TEXTBASEDGAME001_BEGINNERENEMY_H

#include "entity.h"
#include "gameEvents.h"
#include <cstdlib>
#include <string>
#include <utility>
#include <random>
#include <chrono>

std::string genName();

class beginnerEnemy : public entity {

private:



public:
    beginnerEnemy(std::string name, std::vector<std::string> choices = {"Attack", "Defend"},
    int healthPoints = 100, int manaPoints = 100, int attackStat = 10, int defenseStat = 10)
    : entity(std::move(name), std::move(choices), healthPoints, manaPoints,attackStat,defenseStat) {
    };

    void takeAction(){
        // Random number generation
        unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 g1 (seed);
        unsigned int action = g1();

        // Assignment && sending current action
        std::string takenAction = getChoices()[action%2];
        std::string concatAction = "\nThe " + getName() + " " + takenAction + "ed";
        editGameText(concatAction);
    }
};

beginnerEnemy generateBeginnerEnemy();

#endif //TEXTBASEDGAME001_BEGINNERENEMY_H
