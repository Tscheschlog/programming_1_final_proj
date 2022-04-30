//
// Created by 12676 on 3/18/2022.
//

#ifndef TEXTBASEDGAME001_PLAYER_H
#define TEXTBASEDGAME001_PLAYER_H

#include <utility>
#include <iostream>
#include "gameTextHelper.h"
#include "itemHandler.h"
#include "entity.h"

class player: public entity{

public:
    player(std::string name, std::vector<std::string> choices, int healthPoints, int manaPoints, int attackStat,
           int defenseStat) : entity(std::move(name), std::move(choices), healthPoints, manaPoints,
                                     attackStat, defenseStat) {};

    std::vector<item> getInventory(){
        return m_inventory;
    }
    void addToInventory(const item& newItem) {
        m_inventory.push_back(newItem);
    }

    bool getCurrentState() const{
        return m_currentState;
    }

    void setCurrentState(bool state){
        m_currentState = state;
        setChoicesFromCurrentState(m_currentState);
    }
    void setChoicesToCombat(){
        std::vector<std::string> choices;
        choices = {"Select an option:", "Attack", "Defend", "Do Nothing", "You've chosen to "};
        this->setChoices(choices);
    }
    void setChoicesToTreasure() {
        std::vector<std::string> choices;
        choices = {"Select an option:", "Search","Head Back","You've chosen to "};
        this->setChoices(choices);
    }
    void setChoicesToVictory() {
        std::vector<std::string> choices;
        choices = {"Select an option:", "Leave","You've chosen to "};
        this->setChoices(choices);
    }
    int getExperience() const{
        return m_experience;
    }

    void incrementExperience(int exp){
        m_experience += exp;
    }

    void takeAction(int action){
        std::string concatAction = getChoices()[getChoices().size()-1] + getChoices()[action];
        editGameText(concatAction);
    }


private:
    std::vector<item> m_inventory = {};
    int m_experience = 0;

    // Either: Battle State == FALSE || Map State == TRUE
    bool m_currentState = true;

    void setChoicesFromCurrentState(bool state){

        std::vector<std::string> choices;

        if(state){
            choices = {"Where to would you like to go?", "North", "South", "East", "West", "You decided to head "};
        }
        else {
            choices = {"Select an option:", "Fight", "Run Away", "Cry", "You've chosen to "};
        }
        this->setChoices(choices);
    }

};

player initPlayer();

std::string formatPlayerInventory(player mainCharacter);


#endif //TEXTBASEDGAME001_PLAYER_H
