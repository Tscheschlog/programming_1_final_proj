//
// Created by 12676 on 3/19/2022.
//

#include "menuUI.h"
#include <string>

int getPlayerInput(int max){

    std::string input;

    do{
        std::cin >> input;

        //Check if the input is a digit before attempting to convert it for the second condition
    }while((!std::isdigit(input[0])) || (std::stoi(input) > max || std::stoi(input) < 1));

    return std::stoi(input);
}