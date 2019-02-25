//
//  GameWorld.hpp
//  p3.2250
//
//  Created by David Lindsey on 10/17/17.
//  Copyright © 2017 David Lindsey. All rights reserved.
//

#ifndef GameWorld_h
#define GameWorld_h

#include <iostream>
using namespace std;

class GameWorld
{
private:
    const static int SIZE = 5;
    char map[SIZE][SIZE];
    char * ptrs[SIZE * SIZE];
    enum Direction { UP, RIGHT, DOWN, LEFT};
    Direction dir = UP;
    char *player = nullptr;
public:
    GameWorld();
    void displayEntireWorld();
    void displayVisibleWorld();
    void turnLeft()
    { dir = (dir == UP) ? LEFT :static_cast<Direction>(dir - 1);
    changeDir();
        displayVisibleWorld();};
    void turnRight()
    {dir = (dir == LEFT) ? UP : static_cast<Direction>(dir + 1);
        changeDir();
        displayVisibleWorld();};
    void moveForward();
    bool haveIWon()
    {return (*player == 'G');};
    bool amIAlive()
    {return (*player == 'P' || *player == 'W');};
    void changeDir();
};

#endif /* GameWorld_h */