/*
    Here all the user defined functions of chainReaction.cpp are written.
    Functions are:
            containerDisplay
            react
            read
            play
    Note : 'i' refers to player id.(except containerDisplay)
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

void react(int x, int y, int i) {
    int f = 0;
    if(x == 0){
        if (y == 0){
            if(Box[0][0] % 4 > 0){
                f = 1;
                Box[0][0] = 0;
                react(1,0,i);
                react(0,1,i);
            }
        }else if(y+1 == size){
            if(Box[0][y] % 4 > 0){
                Box[0][y] = 0;
                f = 1;
                react(1,y,i);
                react(0,y-1,i);
            }
        }else{
            if(Box[0][y] % 4 > 1){
                Box[0][y] = 0;
                f = 1;
                react(0,y-1,i);
                react(0,y+1,i);
                react(1,y,i);
            }
        }
    }else if(x+1 == size){
        if (y == 0){
            if(Box[x][0] % 4 > 0){
                Box[x][0] = 0;
                f = 1;
                react(x-1,0,i);
                react(x,1,i);
            }
        }else if(y+1 == size){
            if(Box[x][y] % 4 > 0){
                Box[x][y] = 0;
                f = 1;
                react(x-1,y,i);
                react(x,y-1,i);
            }
        }else{
            if(Box[x][y] % 4 > 1){
                Box[x][y] = 0;
                f = 1;
                react(x,y-1,i);
                react(x,y+1,i);
                react(x-1,y,i);
            }
        }
    }else if(y == 0){
        if(Box[x][y] % 4 > 1){
            Box[x][y] = 0;
            f = 1;
            react(x-1,y,i);
            react(x+1,y,i);
            react(x,y+1,i);

        }
    }else if(y+1 == size){
        if(Box[x][y] % 4 > 1){
            Box[x][y] = 0;
            f = 1;
            react(x,y-1,i);
            react(x+1,y,i);
            react(x-1,y,i);
        }
    }else if(Box[x][y] % 4 > 2){
        Box[x][y] = 0;
        f = 1;
        react(x,y-1,i);
        react(x,y+1,i);
        react(x-1,y,i);
        react(x+1,y,i);
    }
    if (f ==  0){
        Box[x][y] = 4 * i + ((Box[x][y] + 1) % 4);
    }
}

void read() {
    int x, y;                                           //co-ordinates of value entry.
    for (int i = 0; i < playerCount; i++) {
        std::cout << "\nPlayer" << i << "'s turn : ";
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
    std::cout << "\n\n\t   Round" << round++ << "\n";
    read();
}
