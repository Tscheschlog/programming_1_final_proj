//
// Created by 12676 on 3/18/2022.
//

#include "entity.h"
#include <utility>

entity::entity(std::string name, std::vector<std::string> choices, int healthPoints, int manaPoints, int attackStat,
               int defenseStat) {

    this->m_name = std::move(name);
    this->m_choices = std::move(choices);
    this->m_healthPoints = healthPoints;
    this->m_manaPoints = manaPoints;
    this->m_attackStat = attackStat;
    this->m_defenseStat = defenseStat;

}


std::string formatChoicesToString(const std::vector<std::string>& choices){

    std::string outString = "\n\n";
    int i = 1;

    for(const auto& item : choices) {

        // Prevents the printing of the last element -- Which is currently used as the "You chose to ","You headed "
        if(i == choices.size()-1) break;

        if(item == choices[0]){
            outString += (item + "\n");
        }
        else {
            outString += (std::to_string(i) + ":" + item + "\n");
            i++;
        }
    }

    return outString;
}