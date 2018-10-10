/*
    Here all the user defined functions of chainReaction.cpp are written.
    Functions are:
            containerDisplay
            play
*/

void containerDisplay(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            std::cout << " " << containerBox[i][j];
        }
        std::cout << '\n';
    }
}

void play() {
    std::cout << "\tRound " << round++ << " ";
    int x, y;                                           //co-ordinates of value entry.
    for (int i = 0; i < playerCount; i++) {
        std::cout << "\nPlayer" << i << "'s turn : ";
        std::cin >> x;
        std::cin >> y;
    }
}
