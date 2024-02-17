#pragma once
#include <iostream>>
#include <math.h>
class Enemy
{
private:
    bool guarding = false;
    bool alive = true;
    int maxHealth = 0;
    int health = 0;
    int attack = 0;
    int defence = 0;
    char rank = 'a';
    std::string name = " ";
public:
    Enemy();
    Enemy(int t_type);
    void setMaxHealth(int t_health);
    void setAlive(bool t_alive);
    void setAttack(int t_attack);
    void setDefence(int t_def);
    void setHealth(int t_health);
    void setName(std::string t_name);
    void setGuarding(bool t_guard);
    std::string getName();
    bool getGuarding();
    bool getAlive();
    int getAttack();
    int getHealth();
    int getDefense();
    int takeDamage(int t_damage);
    int dealDamage();
    char getRank();
    void changeRank();
    int getMaxHealth();

};

