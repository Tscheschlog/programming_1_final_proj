//
// Created by 12676 on 3/18/2022.
//

#include "player.h"
#include <array>
#include <fstream>


std::array<int, 4> insertFromStatSheet(){

    std::array<int, 4> stats = {};

    std::ifstream file;

    file.open("../playerStatSheet.txt");

    std::string line;
    int i = 0;
    while(std::getline(file,line)){
        stats[i] = std::stoi(line);
        i++;
    }
    file.close();

    return stats;
}


player initPlayer(){

    std::vector<std::string> initChoices = {"Where to next?", "North", "South", "East", "West",
                                            "You decided to head "};
    std::string name = "Chris";
    std::array<int, 4> stats = insertFromStatSheet();
    player mc(name,initChoices,stats[0],stats[1],stats[2],stats[3]);

    sword basicSword("Wooden Sword", 10, true);

    mc.addToInventory(basicSword);

    return mc;
}


std::string formatPlayerInventory(player mainCharacter) {

    std::string outputString = mainCharacter.getName() + "'s" + " Inventory:";

    for(auto& item : mainCharacter.getInventory()){
        outputString += item.to_string();
    }
    return outputString;
}

