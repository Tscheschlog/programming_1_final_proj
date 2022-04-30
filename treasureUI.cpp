//
// Created by 12676 on 4/7/2022.
//

#include "treasureUI.h"

void foundTreasure() {



}

void displayTreasureScreen(player& mc) {


    // Formats the player options at the bottom of the screen
    std::string pChoices = formatChoicesToString(mc.getChoices());
    editGameText(pChoices);

}

void lookForTreasure(player& mc) {

    // Set treasure choices
    mc.setChoicesToTreasure();

    // Initialize Treasure screen
    displayTreasureScreen(mc);

    // Display Treasure Screen
    displayGameText(true);

}