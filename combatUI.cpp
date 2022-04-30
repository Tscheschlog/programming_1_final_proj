//
// Created by 12676 on 3/21/2022.
//

#include "combatUI.h"
#include "gameTextHelper.h"
#include "beginnerEnemy.h"
#include <Windows.h>


void sendCombatScreen(player& mc, beginnerEnemy& enemy, std::array<std::string, 2> titles) {

    // Top Text for the combat screen
    std::string topBlock = encloseText(createTitleTxt(titles[0]));
    editGameText(topBlock);

    // Path to the enemy Ascii Art - Then sending it to game screen
    std::string artPath = "../" + toLowerCase(enemy.getName())   +"01.txt";
    sendAsciiToScreen(artPath);

    // Creates the bottom text of the combat screen
    std::string playerOptionTitle = encloseText(createTitleTxt(titles[1]));
    editGameText(playerOptionTitle);

    // Formats the player options at the bottom of the combat screen
    std::string pChoices = formatChoicesToString(mc.getChoices());
    editGameText(pChoices);

}

void combatVictoryScreen(player& mc, beginnerEnemy& enemy) {

    mc.setChoicesToVictory();

    std::string monsterDefeated = "The " + enemy.getName() + " has been slain!";
    editGameText(monsterDefeated);

    // Titles for the top and bottom text of the victory screen
    std::string combatTitle = "  Victory";
    std::string actionMenuTitle = "    Loot";

    sendCombatScreen(mc, enemy, {combatTitle, actionMenuTitle});

    displayGameText();
}

void combatVictory(player& mc, beginnerEnemy& enemy) {
    combatVictoryScreen(mc, enemy);
    // Needs to give exp and 'loot' as well

}

void combatLoopScreen(player& mc, beginnerEnemy& enemy){

    // Titles for the top and bottom text of the combat screen
    std::string combatTitle = "Combat";
    std::string actionMenuTitle = "Action Menu";

    sendCombatScreen(mc, enemy, {combatTitle, actionMenuTitle});

}

bool combatActionHandler(int action){

    if(action == 1){
        return false;
    }
    return true;
}


void combatLoop(player& mc, beginnerEnemy& enemy) {
    int input = 0;
    do {

        // Resets combat loop if user enters unaccepted input
        input = getPlayerInput(mc.getChoices().size());
        if (input >= mc.getChoices().size() - 1 || input <= 0) continue;


        // Shows log of last action at the top of the screen
        mc.takeAction(input);
        enemy.takeAction();

        // Updates Combat screen
        combatLoopScreen(mc, enemy);

        // Display the Combat Screen
        displayGameText();

        // Looping until Combat is over --> endCombatLoop = true
    } while(combatActionHandler(input));
    combatVictory(mc, enemy);
}

void enterCombat(player& mc){

    beginnerEnemy currEnemy(genName());
    std::string topTxt = "\nA " + currEnemy.getName() + " has appeared!";
    editGameText(topTxt);

    // Attack, Defend, Do Nothing
    mc.setChoicesToCombat();

    // Initial Combat screen
    combatLoopScreen(mc, currEnemy);

    // Display Combat Screen
    displayGameText();

    // Begin Combat Loop
    combatLoop(mc, currEnemy);
}
