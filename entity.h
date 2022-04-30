//
// Created by 12676 on 3/18/2022.
//

#ifndef TEXTBASEDGAME001_ENTITY_H
#define TEXTBASEDGAME001_ENTITY_H


#include <utility>
#include <vector>
#include <string>


class entity{

public:
    entity(std::string name,
    std::vector<std::string> choices,
    int healthPoints,
    int manaPoints,
    int attackStat,
    int defenseStat);

    int getHealthPoints(){
        return m_healthPoints;
    }

    void setHealthPoints(int hp){
        m_healthPoints = hp;
    }

    int getManaPoints(){
        return m_manaPoints;
    }

    void setManaPoints(int mp){
        m_manaPoints = mp;
    }

    int getAttackStat(){
        return m_attackStat;
    }

    void setAttackStat(int atkDMG){
        m_attackStat = atkDMG;
    }

    int getDefenseStat(){
        return m_defenseStat;
    }

    void setDefenseStat(int def){
        m_defenseStat = def;
    }

    std::string getName() {
        return m_name;
    }

    void setName(std::string name) {
        m_name = std::move(name);
    }

    std::vector<std::string>& getChoices(){
        return m_choices;
    }

    void setChoices(std::vector<std::string>& options){
        m_choices = {};

        for(auto& item : options){
            m_choices.push_back(item);
        }

    }
    ~entity()= default;

private:

    std::string m_name;
    std::vector<std::string> m_choices;
    int m_healthPoints;
    int m_manaPoints;
    int m_attackStat;
    int m_defenseStat;

};

std::string formatChoicesToString(const std::vector<std::string>&);

#endif //TEXTBASEDGAME001_ENTITY_H
