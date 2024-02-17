// Author Ben Stynes
// Date: 15th of feb 2024
//  Start time 22:44
// doing simple stuff rather than normal stuff like constructurs because I feel bad for allexis.
//  stop time 1    01:40
// playing games now implemented movement and combat, plus a game loop


#include <math.h>
#include <iostream>
#include <time.h> 
#include "Game.h"



int main()
{
   
    srand(time(0));
    Game game;
    while (game.GetRunning() == true)
    {
        game.gameplay();
    }
   
    system("pause");

}



