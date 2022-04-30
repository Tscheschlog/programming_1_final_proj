//
// Created by 12676 on 3/21/2022.
//

#ifndef TEXTBASEDGAME001_COMBATUI_H
#define TEXTBASEDGAME001_COMBATUI_H

#endif //TEXTBASEDGAME001_COMBATUI_H
#include <iostream>
#include <string>
#include <fstream>
#include "player.h"

std::string encloseText(const std::string& innerTxt);
std::string createTitleTxt(std::string& title);
void enterCombat(player&);
