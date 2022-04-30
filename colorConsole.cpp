//
// Created by 12676 on 4/2/2022.
//

#include <iostream>
#include <windows.h>


class outputColorEditer {

private:
    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
public:
    int color_code = 7; // WHITE
    bool stay = false;
    bool playerAction = true;

    HANDLE get_hConsole(){
        return hConsole;
    }

};

/*
 * All Color codes I want:
 * 1    -   Blue
 * 2    -   Green
 * 3    -   Teal
 * 4    -   Red
 * 5    -   Purple
 * 6    -   Gold
 * 7    -   White
 * 8    -   Gray


 NOTE: Add '8' to any of the number keys to get the color in a bolder/brighter format.

    !!!IMPORTANT: THIS DOES NOT WORK FOR COLOR KEY CODE '8'!!!


    #include <windows.h>   // WinApi header

    HANDLE  hConsole;
    int k;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 2); // '2' is a color key code


    ^^^ Maybe create a struct to store the two values, so it would be easier to swap ^^^


 */

