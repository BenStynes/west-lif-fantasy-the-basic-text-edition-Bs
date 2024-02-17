#pragma once
#include <math.h>
#include <iostream>
#include <time.h> 
class Player
{
private:
    bool inTown = false;
    bool inCombat = false;
    int maxHealth = 0;
    bool guarding = false;
    bool alive = true;
    int x = 0;
    int y = 0;
    int health = 0;
    int attack = 0;
    int defence = 0;
    std::string name = " ";
public:
    Player();
    int getMaxHealth();
    void setMaxHealth(int t_health);
    void setTown(bool t_town);
    void setAlive(bool t_alive);
    void setCombat(bool  t_combat);
    void setAttack(int t_attack);
    void setDefence(int t_def);
    void setX(int t_x);
    void setY(int t_y);
    void setHealth(int t_health);
    void setName(std::string t_name);
    void setGuarding(bool t_guard);
    std::string getName();
    bool getGuarding();
    bool getCombat();
    bool getAlive();
    bool getTown();
    int getAttack();
    int getHealth();
    int getDefense();
    int getX();
    int getY();
    int takeDamage(int t_damage);
    int dealDamage();
    void up();
    void down();
    void left();
    void right();
    int run();


};