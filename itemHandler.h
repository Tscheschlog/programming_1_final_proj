//
// Created by 12676 on 3/20/2022.
//

#ifndef TEXTBASEDGAME001_ITEMHANDLER_H
#define TEXTBASEDGAME001_ITEMHANDLER_H

#include <string>
#include <utility>

class item {

private:
    std::string m_name;
    int m_goldValue;
    bool m_equippedAble;
public:
    item(std::string name, int goldValue, bool equippedAble){
        m_name = std::move(name);
        m_goldValue = goldValue;
        m_equippedAble = equippedAble;
    }
    std::string to_string(){
        return "\tName: " + m_name + "\n\t " + std::to_string(m_goldValue) + "gp";
    }
};

class sword : public item{

private:
    int m_dmg;
public:
    sword(std::string name, int goldValue, bool equippedAble = true) :
    item(std::move(name), goldValue, equippedAble) {
        m_dmg = goldValue;
    }
    int getDamage() const{
        return m_dmg;
    }
    void setDamage(int newDmg){
        m_dmg = newDmg;
    }
};


#endif //TEXTBASEDGAME001_ITEMHANDLER_H
