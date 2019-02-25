//
//  GameWorld.cpp
//  p3.2250
//
//  Created by David Lindsey on 10/17/17.
//  Copyright Â© 2017 David Lindsey. All rights reserved.
//

#include "GameWorld.h"
#include <cstdlib>
#include <ctime>



using namespace std;

GameWorld::GameWorld()
{
    unsigned seed = time(0);
    srand(seed);

    // number of pits
    int pits = (rand() %(10 - 5 + 1) +5);

    for(int r = 0;r < SIZE; r++)   // assigns spaces and array of ptrs
        for(int c = 0; c < SIZE; c++)
        {
            map[r][c] = ' ';
            ptrs[(SIZE * r) + c] = &map[r][c];
        }
    for (int p = 0; p < pits; p++) // adds pits to map
    {
        int x = (rand() % (24 - 0 + 1));
        while (!isspace(*ptrs[x]))
            x =(rand() % (24 - 0 + 1));
        *ptrs[x] =  'P';
    }

    {                           //adds wumpus to map
        int x = (rand() % (24 - 0 + 1) +1);
        while (!isspace(*ptrs[x]))
            x =(rand() % (24 - 0 + 1));
        *ptrs[x] =  'W';
    }

    {                           //adds gold
        int x = (rand() % (24 - 0 + 1) +1);
        while (!isspace(*ptrs[x]))
            x =(rand() % (24 - 0 + 1));
        *ptrs[x] =  'G';
    }

    {                           // adds player
        int x = (rand() % (24 - 0 + 1) +1);
        while (!isspace(*ptrs[x]))
            x =(rand() % (24 - 0 + 1));
        *ptrs[x] =  '^';
        player = ptrs[x];
    }
    cout << "\nA turns left\nD turns right\nW moves forward\nC displays entire world\nQ quits\n";
}

void GameWorld::displayEntireWorld()
{
    for(int r = 0;r < SIZE; r++)
    {
        for(int c = 0; c < SIZE; c++)
            cout << "|" << *ptrs[SIZE * r + c];
        cout << "|\n";
    }

}
void GameWorld::displayVisibleWorld()
{
    //(ptrs / 5, ptrs % 5)... convert 1d array to 2 corrodinates
    int pos = player - *ptrs;
    const int R = pos / 5;
    const int C = pos % 5;

    cout<< endl;

    for(int r = 0;r < SIZE; r++)
    {
        for(int c = 0; c < SIZE; c++)
            if (abs(C-c) <= 1 && abs(R-r) <= 1)
                cout << "|" << *ptrs[SIZE * r + c];
            else cout << "| ";
        cout << "|\n";
    }
}

void GameWorld::moveForward()
{
    int pos = player - *ptrs;
    // what is forward?
    // is it a space
    // is it out of bounds
    // is it the gold

    switch (dir) {
        case UP:
            if (pos <= 4)//out of bounds
            {
                cout << "You cannot step out of bounds!";
                break;
            }
            player = player - 5;
            if (*player == ' ')
            {
                *player = *(player + 5);
                *(player + 5) = ' ';
            }
            displayVisibleWorld();
            break;
        case RIGHT:
            if (pos == 4 || pos == 9 || pos == 14 || pos == 19 || pos == 24) //out of bounds
            {
                cout << "You cannot step out of bounds!";
                break;
            }
            player = player + 1;
            if (*player == ' ')
            {
                *player = *(player - 1);
                *(player - 1) = ' ';
            }

            displayVisibleWorld();
            break;
        case DOWN:
            if (pos >= 20)//out of bounds
            {
                cout << "You cannot step out of bounds!";
                break;
            }
            player = player + 5;
            if (*player == ' ')
            {
                *player = *(player - 5);
                *(player - 5) = ' ';
            }
            displayVisibleWorld();
            break;
        case LEFT:
            if (pos == 5 || pos == 10 || pos == 15 || pos == 20 || pos == 25)//out of bounds
            {
                cout << "You cannot step out of bounds!";
                break;
            }
            player = player - 1;
            if (*player == ' ')
            {
                *player = *(player + 1);
                *(player + 1) = ' ';
            }
            displayVisibleWorld();
            break;
    }
}
void GameWorld::changeDir()
{
    switch (GameWorld::dir){
        case UP: *player = '^';
            break;
        case RIGHT: *player = '>';
            break;
        case DOWN: *player = 'v';
            break;
        case LEFT: *player = '<';
            break;}
}