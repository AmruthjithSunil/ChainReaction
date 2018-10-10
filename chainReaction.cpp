/*
    This is a Chain Reaction game.
     Developer : Amruthjith Sunil
    Begin Date : 10/10/2018
*/

#include<iostream>

const int size = 6;
int containerBox[size][size] = {};                      //Play Field
int playerCount;                                        //Number of players
int round = 1;                                          //To count rounds

#include "./allFunctions.cpp"

using namespace std;

int main(int argc, char const *argv[]) {
    cout << "Enter the Number of players : ";
    std::cin >> playerCount;
    containerDisplay();                                 //Displays the container
    /*while (1) {
        play(containerBox, size, playerCount);          //each player gets a turn to play.
    }*/
    return 0;
}
