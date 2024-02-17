#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(int t_type)
{
    switch (t_type)
    {
    default:
        name = "Bandit";
        maxHealth = rand() % (5 - 14) + 1;
        health = maxHealth;
        attack = rand() % (2 - 3) + 1;
        defence = 1;
        break;
    case 1:
        name = "Bandit";
        maxHealth = rand() % (5 - 14) + 1;
        health = maxHealth;

        attack = rand() % (2 - 3) + 1;
        defence = 1;
        break;
    case 2:
        name = "Dog";
        maxHealth = rand() % (2 - 9) + 1;
        health = maxHealth;

        attack = rand() % (1 - 2) + 1;
        defence = 0;
        break;
    case 3: 
        name = "Polish wanderer:";
        maxHealth = rand() % (10 - 15) + 1;
        health = maxHealth;
        attack = rand() % (3 - 4) + 1;
        defence = 2;
        break;

    }
}

void Enemy::setMaxHealth(int t_health)
{
    maxHealth = t_health;
}

void Enemy::setAlive(bool t_alive)
{
	alive = t_alive;
}

void Enemy::setAttack(int t_attack)
{ 
	attack = t_attack;
}

void Enemy::setDefence(int t_def)
{
    defence = t_def;
}

void Enemy::setHealth(int t_health)
{
    health = t_health;
}

void Enemy::setName(std::string t_name)
{
    name = t_name;
}

void Enemy::setGuarding(bool t_guard)
{
    guarding = t_guard;
}

std::string Enemy::getName()
{
	return name;
}

bool Enemy::getGuarding()
{
	return guarding;
}

bool Enemy::getAlive()
{
	return alive;
}

int Enemy::getAttack()
{
	return attack;
}

int Enemy::getHealth()
{
	return health;
}

int Enemy::getDefense()
{
	return defence;
}

int Enemy::takeDamage(int t_damage)
{
    if (guarding)
    {
        if (t_damage > defence)
        {
            health = health - (t_damage - defence);
            std::cout << name << " took a hit def reduced damage to " << t_damage - defence << ":";

        }

        else
        {
            std::cout << name << " took a hit but defended it well No damage:";
        }
    }
    else
    {
        health = health - t_damage;
    }

    return t_damage;
}

int Enemy::dealDamage()
{
   int damage = rand() % (attack - attack + 5) + 1;

   return damage;
}

char Enemy::getRank()
{
    return rank;
}

void Enemy::changeRank()
{
    rank++;
}

int Enemy::getMaxHealth()
{
    return maxHealth;
}
