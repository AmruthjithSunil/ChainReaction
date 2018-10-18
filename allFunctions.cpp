/*
    Here all the user defined functions of chainReaction.cpp are written.
    Functions are:
            containerDisplay
            winCheck
            react
            read
            play
    Note : 'i' refers to player id(except containerDisplay)
*/

void containerDisplay(){
    for(int i = 0; i < size; i++){
        std::cout << "\n\t" ;
        for(int j = 0; j < size; j++){
            if (Box[i][j]%4 == 0){
                std::cout << " 0" ;
                continue;
            }
            std::cout << " " << "\033[1;"<< 31 + Box[i][j]/4 << "m" << Box[i][j]%4 << "\033[0m";
        }
    }
}

int winCheck(){
    winnerID = -1;
    int a[9] = {};
    for (int j = 0; j < size; j++) {
        for (int k = 0; k < size; k++) {
            if(Box[j][k]%4 > 0 && round > 2){
                a[Box[j][k]/4] = 1;
            }
        }
    }
    int c = 0;
    for (int j = 0; j < playerCount; j++) {
        if(a[j] == 1){
            c++;
        }
    }
    if(c == 1){
        for (int j = 0; j < playerCount; j++) {
            if(a[j] == 1){
                winnerID = j;
                break;
            }
        }
    }
    return winnerID;
}

void react(int x, int y, int i) {
    if(winnerID > -1){
        return;
    }
    if(winCheck() > -1){
        return;
    }
    int f = 0;
    if(x == 0){
        if (y == 0){
            if(Box[0][0] % 4 > 0){
                f = 1;
                react(1,0,i);
                react(0,1,i);
                Box[0][0] = 0;
            }
        }else if(y+1 == size){
            if(Box[0][y] % 4 > 0){
                f = 1;
                react(1,y,i);
                react(0,y-1,i);
                Box[0][y] = 0;
            }
        }else{
            if(Box[0][y] % 4 > 1){
                f = 1;
                react(0,y-1,i);
                react(0,y+1,i);
                react(1,y,i);
                Box[0][y] = 0;
            }
        }
    }else if(x+1 == size){
        if (y == 0){
            if(Box[x][0] % 4 > 0){
                f = 1;
                react(x-1,0,i);
                react(x,1,i);
                Box[x][0] = 0;
            }
        }else if(y+1 == size){
            if(Box[x][y] % 4 > 0){
                f = 1;
                react(x-1,y,i);
                react(x,y-1,i);
                Box[x][y] = 0;
            }
        }else{
            if(Box[x][y] % 4 > 1){
                f = 1;
                react(x,y-1,i);
                react(x,y+1,i);
                react(x-1,y,i);
                Box[x][y] = 0;
            }
        }
    }else if(y == 0){
        if(Box[x][y] % 4 > 1){
            f = 1;
            react(x-1,y,i);
            react(x+1,y,i);
            react(x,y+1,i);
            Box[x][y] = 0;

        }
    }else if(y+1 == size){
        if(Box[x][y] % 4 > 1){
            f = 1;
            react(x,y-1,i);
            react(x+1,y,i);
            react(x-1,y,i);
            Box[x][y] = 0;
        }
    }else if(Box[x][y] % 4 > 2){
        f = 1;
        react(x,y-1,i);
        react(x,y+1,i);
        react(x-1,y,i);
        react(x+1,y,i);
        Box[x][y] = 0;
    }
    if (f ==  0){
        Box[x][y] = 4 * i + ((Box[x][y] + 1) % 4);
    }
}

void read() {
    int x, y;                                           //co-ordinates of value entry.
    for (int i = 0; i < playerCount; i++) {
        std::cout << "\n\nPlayer" << i << "'s turn : ";
        std::cin >> x;
        std::cin >> y;
        if(Box[x][y]/4 == i || Box[x][y] == 0){
            react(x,y,i);
        } else {
            std::cout << "\n\tInvalid Entry\n" << '\n';
            i--;
        }
        containerDisplay();
    }
}

void play() {
    if(winCheck() > -1){
        return;
    }
    std::cout << "\n\n\t   Round" << round++;
    read();
}
