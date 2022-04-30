//
// Created by 12676 on 3/21/2022.
//

#include "beginnerEnemy.h"


std::string genName() {
    /// This will get the current time to use for our 'mersenne twister' --> (mt19937)
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();

    /// Pass the seed into the mt instance to generate the random number
    std::mt19937 g1 (seed);

    /// Stores the number generated into the member for monster generation
    unsigned int randNum = g1();

    std::string randName;

    int seedNum = randNum % 4;

    if(seedNum == 0){
        //Skeleton;
        randName = "Skeleton";
    }
    else if(seedNum == 1) {
        //BOAR;
        randName = "Boar";
    }
    else if(seedNum == 2) {
        //GHOUL;
        randName = "Ghoul";
    }
    else {
        //Dragon;
        randName = "Dragon";
    }

    return randName;
}
