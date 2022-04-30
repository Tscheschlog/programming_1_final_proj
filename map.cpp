//
// Created by 12676 on 4/9/2022.
//

#include "map.h"


std::array<int, 2> getPlayerLocation(const std::array<std::array<char, 12>, 16>& map) {

    int row = 0;
    for(auto list : map){

        int col = 0;

        for(char item : list){

            if(item == 'P'){
                return {row, col};
            }

            col++;
        }
        row++;
    }
    return{0,0};
}