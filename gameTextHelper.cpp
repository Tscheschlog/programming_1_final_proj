//
// Created by 12676 on 3/18/2022.
//

#include "gameTextHelper.h"
#include "map.h"


bool findDragonColorSwitch(std::string& line) {
    return (line.find('D') != -1 && line.find('r') != -1 &&
    line.find('a') != -1 && line.find('g') != -1 &&
            line.find('o') != -1 && line.find('n') != -1);
}
bool findBoarColorSwitch(std::string& line) {
    return (line.find('B') != -1 && line.find('o') != -1 &&
            line.find('a') != -1 && line.find('r') != -1);
}
bool findGhoulColorSwitch(std::string& line) {
    return (line.find('G') != -1 && line.find('h') != -1 &&
            line.find('o') != -1 && line.find('u') != -1 &&
            line.find('l') != -1);
}

std::string toLowerCase(const std::string& word){

    std::string temp;

    for(char letter : word){
        temp.push_back(tolower(letter));
    }
    return temp;
}

void colorFormatChecker(outputColorEditer& colorEdit, std::string& line) {

    if(!colorEdit.stay) {
        colorEdit.color_code = 15;
    }


    if(line[0] == '>' && colorEdit.playerAction){
        colorEdit.color_code = 10;
        colorEdit.playerAction = false;
    }
    else if(line[0] == '>' && !colorEdit.playerAction){
        colorEdit.color_code = 10;
        colorEdit.playerAction = true;
    }
    else if(line[0] == '+'){
        colorEdit.color_code = 12;
        colorEdit.stay = false;
    }
    else if(findDragonColorSwitch(line)){
        colorEdit.color_code = 14;
        colorEdit.stay = true;
    }
    else if(findGhoulColorSwitch(line)){
        colorEdit.color_code = 11;
        colorEdit.stay = true;
    }
    else if(findBoarColorSwitch(line)){
        colorEdit.color_code = 15;
        colorEdit.stay = true;
    }

}

void printColorCodedLine(outputColorEditer& colorEdit, std::string line){

    SetConsoleTextAttribute(colorEdit.get_hConsole(), colorEdit.color_code);

    std::cout << line << "\n";

}

void highlightPlayerAndPrint(outputColorEditer& colorEdit, std::string line){

    if(line.find('P') != -1){
        for(char item : line){
            if(item == 'P'){
                colorEdit.color_code = 22;
                SetConsoleTextAttribute(colorEdit.get_hConsole(), colorEdit.color_code);
                std::cout << item;
            }
            else {
                colorEdit.color_code = 15;
                SetConsoleTextAttribute(colorEdit.get_hConsole(), colorEdit.color_code);
                std::cout << item;
            }
        }
        std::cout << "\n";
    }
    else {
        printColorCodedLine(colorEdit, line);
    }

}

// Sends all the text stored in the gameText.txt to the console - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void displayGameText(){

    std::ifstream file;

    file.open("../gameText.txt");

    // Clear the console of prior output
    consoleWhiteSpace(0);


    // 'fileLength' starts at -1 to fix output line spacing
    int fileLength = -1;

    // Allow for the color of the console output to change
    outputColorEditer colorEdit;

    std::string line;
    while(std::getline(file,line)){

        colorFormatChecker(colorEdit, line);
        printColorCodedLine(colorEdit, line);

        fileLength++;
    }

    consoleWhiteSpace(fileLength);
    wipeGameText();
}

void displayGameText(bool mapIsOpen){

    std::ifstream file;

    file.open("../gameText.txt");

    // Clear the console of prior output
    consoleWhiteSpace(0);


    // 'fileLength' starts at -1 to fix output line spacing
    int fileLength = -1;

    // Allow for the color of the console output to change
    outputColorEditer colorEdit;

    std::string line;
    while(std::getline(file,line)){

        highlightPlayerAndPrint(colorEdit, line);

        fileLength++;
    }

    consoleWhiteSpace(fileLength);
    wipeGameText();
}

// Takes in a string and appends it to the gameText.txt file - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void editGameText(std::string& newText){

    std::ofstream file;

    file.open("../gameText.txt", std::fstream::app);

    file << newText;

    file.close();

}

// Formats ascii art and sends it to gameText.txt file - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void sendAsciiToScreen(const std::string& artPath){

    std::fstream art;
    std::fstream screen;
    screen.open("../gameText.txt", std::ios::app);
    art.open(artPath);

    screen << "\n";

    std::string line;
    while(getline(art, line)){

        screen << "\t\t" << line << "\n";

    }

    screen << "\n";

    art.close();
}

// std::ofstream::trunc - "Any contents that existed in the file before it is open are discarded." - - - - - - - - - - -
void wipeGameText(){
    std::fstream file;
    file.close();
    file.open("../gameText.txt", std::ofstream::out | std::ofstream::trunc);
    file.close();
}

// Takes in a vector of strings, separates them with '\n', then returns it as a single string - - - - - - - - - - - - -
std::string customBlockText(std::vector<std::string>& textBlocks){

    std::string finalBlock;

    for(auto& item : textBlocks){
        finalBlock += (item + "\n");
    }

    return finalBlock;
}

// Best current fix to 'Clear' console screen - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const int MAX_CONSOLE_SCROLL = 38;

// 'Clears' the screen so when displayGameText() is called there is no overlap from prior prints - - - - - - - - - - - -
void consoleWhiteSpace(int filledLines){

    for(int i = 0;i < MAX_CONSOLE_SCROLL - filledLines; i++)
        std::cout << "\n";

}

std::string encloseText(const std::string& innerTxt){

    std::string line = "\n+---------------------------------------------------------------------------------------"
                       "----+\n";

    return line + innerTxt + line;
}

void addTabsToTitle(std::string& title){

    // 5 Tabs for single char in middle
    std::string tab = "\t\t\t\t\t";

    // Modulo fix for numbers greater than 10
    if(title.length() > 10){
        tab = "\t\t\t\t";
    }


    // Remove tabs based on how long the string is relative to the middle char measurement
    for(int i = 0; i < (title.length() % 5); i++){

        tab = tab.substr(0, tab.length() - 2);

    }

    // Add the tab list to the front of the title
    title = tab + title;
}

std::string createTitleTxt(std::string& title){

    // Tab over text so it is centered in the block
    addTabsToTitle(title);
    std::string m_title;

    // Loop to create proper spacing of each letter
    for(auto letter : title){
        m_title.push_back(letter);
        m_title += "    ";
    }

    return m_title;
}
