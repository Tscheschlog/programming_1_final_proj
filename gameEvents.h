//
// Created by 12676 on 3/18/2022.
//

#ifndef TEXTBASEDGAME001_GAMEEVENTS_H
#define TEXTBASEDGAME001_GAMEEVENTS_H

#include "gameTextHelper.h"
#include "player.h"
#include "menuUI.h"
#include "map.h"


void beginGame();

void beginFightingEvent(player&, int);
void beginTreasureEvent(player&, int);
void returnToMap(player&, int);


void rollingGameLoop(player&, map&);
void presentCurrentEvent(player&, map&, int);


#endif //TEXTBASEDGAME001_GAMEEVENTS_H
