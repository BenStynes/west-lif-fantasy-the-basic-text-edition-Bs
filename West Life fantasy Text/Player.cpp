#include "Player.h"

Player::Player()
{
}

int Player::getMaxHealth()
{
    return maxHealth;
}

void Player::setMaxHealth(int t_health)
{
    maxHealth = t_health;   
}

void Player::setTown(bool t_town)
{
    inTown = t_town;
}

void Player::setAlive(bool t_alive)
{
    alive = t_alive;
}

void Player::setCombat(bool t_combat)
{
    inCombat = t_combat;
}

void Player::setAttack(int t_attack)
{
    attack = t_attack;
}

void Player::setDefence(int t_def)
{
    defence = t_def;
}

void Player::setX(int t_x)
{
    x = t_x;
}

void Player::setY(int t_y)
{
    y = t_y;
}

void Player::setHealth(int t_health)
{
    health = t_health;
}

void Player::setName(std::string t_name)
{
    name = t_name;
}

void Player::setGuarding(bool t_guard)
{
    guarding = t_guard;
}

std::string Player::getName()
{
    return name;
}

bool Player::getGuarding()
{
    return guarding;
}

bool Player::getCombat()
{
    return inCombat;
}

bool Player::getAlive()
{
    return alive;
}

bool Player::getTown()
{
    return inTown;
}

int Player::getAttack()
{
    return attack;
}

int Player::getHealth()
{
    return health;
}



int Player::getDefense()
{
    return defence;
}

int Player::getX()
{
    return x;
}

int Player::getY()
{
    return y;
}

int Player::takeDamage(int t_damage)
{
    if (guarding)
    {
        if (t_damage > defence)
        {
            health = health - (t_damage - defence);
            std::cout << "You took a hit def reduced damage to " << t_damage - defence << ":";

        }
        else
        {
            std::cout << "You took a hit but defended it well No damage:";
        }
    }
    else
    {
        health = health - t_damage;
    }

    return t_damage;
}

int  Player::dealDamage()
{
    int damage = rand() % (attack - attack + 5) + 1;

    return damage;
}

void Player::up()
{
    y = y + 1;

}

void Player::down()
{
    y = y - 1;
}

void Player::left()
{
    x = x - 1;
}

void Player::right()
{
    x = x + 1;
}

int Player::run()
{

    return (rand() % (1 - 100 + 1) > 45);

}
