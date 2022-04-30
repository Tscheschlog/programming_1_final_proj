//
// Created by 12676 on 4/9/2022.
//

#ifndef TEXTBASEDGAME001_MAP_H
#define TEXTBASEDGAME001_MAP_H

#include <fstream>
#include <string>
#include "gameTextHelper.h"

// Needs the coordinate plain to be passed, and it will return the (x, y) of the player
std::array<int, 2> getPlayerLocation(const std::array<std::array<char, 12>, 16>& map);


class map {
private:

    std::array<std::array<char, 12>, 16> coordinatePlain;

    void initMap() {

        std::fstream map;
        map.open("../map.txt");

        int row = 0;
        std::string line;
        while(getline(map, line)){

            int column = 0;
            for(char item : line){
                coordinatePlain[row][column] = item;
                column++;
            }
            row++;
        }
    }

public:

    map() {
        initMap();
    }

    void drawMap() {

        std::fstream screen;
        screen.open("../gameText.txt", std::ios::app);

        std::string mapTitle = "     Map";
        std::string topBlock = encloseText(createTitleTxt(mapTitle));
        editGameText(topBlock);


        for(auto row : coordinatePlain){

            for(auto item : row){
                screen << "  " << item << "\t";
            }
            screen << "\n";
        }
    }

    void updateMap(int input){

        std::array<int, 2> location = getPlayerLocation(coordinatePlain);


        if(input < 3){
            if(input == 1){

                if(location[0]-1 < 0){
                    return;
                }

                coordinatePlain[location[0]][location[1]] = '0';
                coordinatePlain[location[0]-1][location[1]] = 'P';
            }
            else {

                if(location[0]+1 > 15){
                    return;
                }

                coordinatePlain[location[0]][location[1]] = '0';
                coordinatePlain[location[0]+1][location[1]] = 'P';
            }
        }
        else if(input < 5){
            if(input == 3){

                if(location[1]+1 > 11){
                    return;
                }

                coordinatePlain[location[0]][location[1]] = '0';
                coordinatePlain[location[0]][location[1]+1] = 'P';
            }
            else {

                if(location[1]-1 < 0){
                    return;
                }

                coordinatePlain[location[0]][location[1]] = '0';
                coordinatePlain[location[0]][location[1]-1] = 'P';
            }
        }
        else {
            std::cout << "Bad Input";
        }
    }
};


#endif //TEXTBASEDGAME001_MAP_H
