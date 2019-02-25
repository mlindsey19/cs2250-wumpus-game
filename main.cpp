//
//  main.cpp
//  p3.2250
//
//  Created by David Lindsey on 10/17/17.
//  Copyright Â© 2017 David Lindsey. All rights reserved.
//

#include <iostream>
#include "GameWorld.h"

using namespace std;

int main(int argc, const char * argv[]) {

    char input;
    GameWorld *game;

    do
    {
        game = new GameWodrld;
        game->displayVisibleWorld();

        do
        {
            cin >> input;
            input = toupper(input);
            switch (input)
            {
                case 'A': (*game).turnLeft();
                    break;
                case 'D': game->turnRight();
                    break;
                case 'W': game->moveForward();
                    break;
                case 'C': game->displayEntireWorld();
                    break;
                case 'Q':  return 0;
                default: cout<< "wrong choice";
                    break;
            }
        }
        while (game->amIAlive() == 0 && game->haveIWon() == 0);
        if ( game->amIAlive() == 1)
            cout << "you lost\nPress Y to play agian or Q to quit.";
        if( game->haveIWon() == 1)
            cout << "you win\nPress Y to play again or Q to quit.";
        delete game;
        cin >> input;
    }
    while (toupper(input) == 'Y');

    return 0;
}
