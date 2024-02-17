#include "Overworld.h"

Overworld::Overworld()
{
}

void Overworld::setSize(int t_size)
{
    size = t_size;
}

void Overworld::setX(int t_X)
{
    townX = t_X;
}

void Overworld::setY(int t_y)
{
    townY = t_y;
}

void Overworld::SetRandom(int t_randy)
{
    randomChance = t_randy;
}

int Overworld::getSize()
{
    return size;
}

int Overworld::getX()
{
    return townX;
}

int Overworld::getY()
{
    return townY;
}

int Overworld::getRandom()
{
    return randomChance;
}

bool Overworld::spawnEnemy()
{
    bool spawnE = false;
    if (rand() % (1 - 25) + 1 >= randomChance)
    {
        spawnE = true;
    }

    return spawnE;
}

bool Overworld::enterTown(int t_pX, int t_pY)
{
    bool townP = false;
    if (t_pX == townX && t_pY == townY)
    {
        townP = true;
    }

    return townP;
}