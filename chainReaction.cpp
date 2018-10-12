/*
    This is a Chain Reaction game.
    https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
     Developer : Amruthjith Sunil
    Begin Date : 10/10/2018
*/

#include<iostream>

const int size = 6;
int Box[size][size] = {};                               //Play Field
int playerCount;                                        //Number of players
int round = 1;                                          //To count rounds

#include "./allFunctions.cpp"

using namespace std;

int main(int argc, char const *argv[]) {
    std::cout << "\t" ;
    cout << "\033[1;31mCHAIN REACTION\033[0m\n";
    cout << "Enter the Number of players : ";
    std::cin >> playerCount;
    containerDisplay();                                 //Displays the container
    while (1) {
        play();                                         //each player gets a turn to play.
    }
    return 0;
}
