#ifndef __HERO_H__
#define __HERO_H__

#include <string>

using namespace std;

class hero_t
{
    private:
    string name;
    
    int money;
    
    float maxHealth;
    float health;
    float resistance;
    float damage;
    int maxEnergy;
    int energy;
    
    public:
    hero_t();
    void reset();
    
    string getName();
    void setName(string newName);
    
    int getMoney();
    void addMoney(int amount);
    
    float getHealth();
    void subtractHealth(float damage);
    float getMaxHealth();
    void addMaxHealth(float health);
    
    float getResistance();
    void addResistance(float amount);
    
    int getDamage();
    void addDamage(int amount);
    
    int getEnergy();
    void addEnergy(int amount);
    int getMaxEnergy();
    void addMaxEnergy(int amount);
    
    float calculateDamage(float damage);
};

#endif