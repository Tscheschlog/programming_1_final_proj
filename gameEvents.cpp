//
// Created by 12676 on 3/18/2022.
//

#include "gameEvents.h"
#include "combatUI.h"
#include "treasureUI.h"
#include "map.h"
#include <random>
#include <array>

void beginGame() {

    player mc = initPlayer();
    map gameMap;

    std::vector<std::string> intro;

    intro.emplace_back("You awake on a beach.");
    intro.emplace_back("Why are you here? You like to think a lot so you contemplated how this happened. This begins "
                       "to hurt your head so you \ndecide it is best to stop.");
    //intro.emplace_back(formatChoicesToString(mc.getChoices()));

    std::string introBlock = customBlockText(intro);
    editGameText(introBlock);

    gameMap.drawMap();
    std::string pChoices = formatChoicesToString(mc.getChoices());
    editGameText(pChoices);

    displayGameText(true);

    rollingGameLoop(mc, gameMap);
}

/// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

std::array<std::string, 4> mapFillerText = {"\nYou hear the wind howl which scares you a little.",
                                            "\nThere is nothing happening. Literally nothing.",
                                            "\nThe trees nearby are pretty big. You decide you dislike them.",
                                            "\nThere are cries for help in the distance. You ignore them."};

std::array<std::string, 2> treasureEventsText = {"\nYou found a chest of gold!", "\nYou've discovered an item!"};


void rollingGameLoop(player& mc, map& gameMap){

    int input = getPlayerInput(mc.getChoices().size());
    if(input > mc.getChoices().size()-2 || input < 0) return;

    mc.takeAction(input);

    presentCurrentEvent(mc, gameMap, input);

    rollingGameLoop(mc, gameMap);
}

// Bool used as a switch inside selectRandomEvent()===
bool combatLast = false;
bool treasureLast = false;

void selectRandomEvent(player& mc, map& gameMap) {
    srand(time(0));
    int num = rand() % 10;

    if(!(num < 2 && !combatLast)){
        gameMap.drawMap();
    }

    // Get random number using mt "something"
    if(num < 2 && !combatLast){
        num %= 3;
        beginFightingEvent(mc, num);

        // Prevents two combat events in a row
        combatLast = true;
    }
        /// Lucky number seven means free stuff :)
    else if(num == 7 && !treasureLast) {
        num %= 2;
        beginTreasureEvent(mc, num);

        // Prevents two treasure events in a row
        treasureLast = true;
    }
    else {
        srand(time(0));
        num = rand() % 4;
        returnToMap(mc, num);

        // Prevent Combat/Treasure twice in a row.
        combatLast = false;
        treasureLast = false;
    }
}
// ===================================================

void presentCurrentEvent(player& mc, map& gameMap, int input){

    // Update map after each input
    gameMap.updateMap(input);

    // Generate a random event
    selectRandomEvent(mc, gameMap);

}

// Goes to combatUI
void beginFightingEvent(player& mc, int eventID){

    mc.setCurrentState(false);

    enterCombat(mc);
}

// Needs to send something to the player inventory: Just like the after combat but no exp || Goes to treasureUI
void beginTreasureEvent(player& mc, int eventID) {

    mc.setCurrentState(true);
    editGameText(treasureEventsText[eventID]);

    std::string pChoices = formatChoicesToString(mc.getChoices());
    editGameText(pChoices);

    displayGameText(true);

}

// Goes back to rollingGameLoop()
void returnToMap(player& mc, int eventID) {

    mc.setCurrentState(true);
    editGameText(mapFillerText[eventID]);

    std::string pChoices = formatChoicesToString(mc.getChoices());
    editGameText(pChoices);

    displayGameText(true);
}
