#pragma once
#include <math.h>
#include <iostream>
#include <time.h> 
class Overworld
{
private:
    int size = 0;
    int townX = 0;
    int townY = 0;
    int randomChance = 0;
public:
    Overworld();
    void setSize(int t_size);
    void setX(int t_X);
    void setY(int t_y);
    void SetRandom(int t_randy);
    int getSize();
    int getX();
    int getY();
    int getRandom();
    bool spawnEnemy();
    bool enterTown(int t_pX, int t_pY);
};