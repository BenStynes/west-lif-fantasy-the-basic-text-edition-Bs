#pragma once
#include <math.h>
#include <vector>
#include <iostream>
#include <time.h> 
#include "Overworld.h"
#include "Player.h"
#include "Enemy.h"
class Game {
private:
    Overworld Area;
    Player P1;
    Enemy enemies[10]{};
    void setUpGame();
    int partyGold = 0;
    bool running = true;
    bool combat = false;
    bool explore = true;
    bool town = false;
    bool choosing = true;
    bool playerTurn = false;
    bool attacking = false;
    bool enemyTurn = false;
    bool flee = false;
    int input =0;
    int enemyAmount = 0;
    int aliveEnemies = 0;
public:
    Game();
    bool GetRunning();
    void gameplay();
    void Exploring();
    void Combat();
    int createEnemy();
    void downtown();
    void shop();
    void tavern();
};