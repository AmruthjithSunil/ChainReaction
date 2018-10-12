/*
    Here all the user defined functions of chainReaction.cpp are written.
    Functions are:
            containerDisplay
            read
            play
*/

void containerDisplay(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if (Box[i][j]%4 == 0){
                std::cout << " 0" ;
                continue;
            }
            std::cout << " " << "\033[1;"<< 31 + Box[i][j]/4 << "m" << Box[i][j]%4 << "\033[0m";
        }
        std::cout << '\n';
    }
}

void read() {
    int x, y;                                           //co-ordinates of value entry.
    for (int i = 0; i < playerCount; i++) {
        std::cout << "\nPlayer" << i << "'s turn : ";
        std::cin >> x;
        std::cin >> y;
        if(Box[x][y]/4 == i || Box[x][y] == 0){
            Box[x][y] = 4 * i + ((Box[x][y] + 1) % 4);
        }
        containerDisplay();
    }
}

void play() {
    std::cout << "\tRound " << round++ << " ";
    read();
}
