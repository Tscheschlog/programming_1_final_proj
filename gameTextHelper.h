//
// Created by 12676 on 3/18/2022.
//

#ifndef TEXTBASEDGAME001_GAMETEXTHELPER_H
#define TEXTBASEDGAME001_GAMETEXTHELPER_H

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include "colorConsole.cpp"
#include "menuUI.h"

void displayGameText();
void displayGameText(bool); // If a bool is passed it will display in map color formatting
void editGameText(std::string&);
void consoleWhiteSpace(int);
void wipeGameText();
void sendAsciiToScreen(const std::string&);
std::string formatEventText(std::array<std::string, 3>, int);
std::string formatEventText(std::array<std::string, 4>, int);
std::string customBlockText(std::vector<std::string>&);
std::string toLowerCase(const std::string&);
std::string encloseText(const std::string&);
void addTabsToTitle(std::string&);
std::string createTitleTxt(std::string&);

#endif //TEXTBASEDGAME001_GAMETEXTHELPER_H
