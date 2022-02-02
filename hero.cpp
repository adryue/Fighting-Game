#include <string>
#include "hero.h"

using namespace std;

hero_t::hero_t()
{
    money = 20;
    
    maxHealth = 100.0;
    health = 100.0;
    resistance = 0.0;
    damage = 10.0;
    maxEnergy = 70;
    energy = 70;
}

void hero_t::reset()
{
    health = maxHealth;
    energy = maxEnergy;
}

void hero_t::setName(string newName)
{
    name = newName;
}

string hero_t::getName()
{
    return name;
}

int hero_t::getMoney()
{
    return money;
}
void hero_t::addMoney(int amount)
{
    money += amount;
}

float hero_t::getHealth()
{
    return health;
}
void hero_t::subtractHealth(float damage)
{
    health -= damage;
}
float hero_t::getMaxHealth()
{
    return maxHealth;
}
void hero_t::addMaxHealth(float health)
{
    maxHealth += health;
}

float hero_t::getResistance()
{
    return resistance;
}
void hero_t::addResistance(float amount)
{
    resistance += amount;
}

int hero_t::getDamage()
{
    return damage;
}
void hero_t::addDamage(int amount)
{
    damage += amount;
}

int hero_t::getEnergy()
{
    return energy;
}
void hero_t::addEnergy(int amount)
{
    energy += amount;
}
int hero_t::getMaxEnergy()
{
    return maxEnergy;
}
void hero_t::addMaxEnergy(int amount)
{
    maxEnergy += amount;
}

float hero_t::calculateDamage(float damage)
{
    return damage * (1.0 - resistance);
}