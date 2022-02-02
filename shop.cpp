#include <iostream>
#include "shop.h"

using namespace std;

int damageCost = 10;
int armorCost = 10;
int healthCost = 20;
int energyCost = 15;

void shop(hero_t &hero)
{
    cout << "----Welcome to the shop, " << hero.getName() << "!----" << endl;
    while (true)
    {
        cout << "\n\n";
        
        char choice;
        cout << "What would you like to buy?" << endl;
        cout << "[d] damage: " << damageCost << " gold (increases attack damage)" << endl;
        cout << "[a] armor: " << armorCost << " gold (increases resistance to attacks)" << endl;
        cout << "[h] health: " << healthCost << " gold (gives you more health points)" << endl;
        cout << "[e] energy: " << energyCost << " gold (gives you more energy at the start of a battle)" << endl;
        cout << "[i] info (your stats)" << endl;
        cout << "[x] exit" << endl;
        cout << "[You have " << hero.getMoney() << " gold]" << endl;
        cin >> choice;
        switch (choice)
        {
            case 'D':
            case 'd':
            if (hero.getMoney() < damageCost)
            {
                cout << "----You can't do that.----" << endl;
            }
            else
            {
                hero.addDamage(5);
                handlePurchase(hero, "damage", damageCost);
                cout << "Your damage is now " << hero.getDamage() << "." << endl;
                damageCost += 2;
            }
            
            case 'A':
            case 'a':
            if (hero.getMoney() < armorCost)
            {
                cout << "----You can't do that.----" << endl;
            }
            else if (hero.getResistance() >= 0.8)
            {
                cout << "You already have the best armor!" << endl;
            }
            else
            {
                hero.addResistance(0.1);
                handlePurchase(hero, "armor", armorCost);
                cout << "Your resistance is now " << (int)(hero.getResistance() * 100)  << "%." << endl;
                armorCost += 5;
            }
            break;
            
            case 'H':
            case 'h':
            if (hero.getMoney() < healthCost)
            {
                cout << "----You can't do that.----" << endl;
            }
            else
            {
                hero.addMaxHealth(5);
                handlePurchase(hero, "health", healthCost);
                cout << "Your health is now " << hero.getMaxHealth() << "." << endl;
                healthCost += 5;
            }
            break;
            
            case 'E':
            case 'e':
            if (hero.getMoney() < energyCost)
            {
                cout << "----You can't do that.----" << endl;
            }
            else
            {
                hero.addMaxEnergy(5);
                handlePurchase(hero, "energy", energyCost);
                cout << "Your energy is now " << hero.getMaxEnergy() << "." << endl;
                energyCost += 2;
            }
            break;
            
            case 'I':
            case 'i':
            listStats(hero);
            break;
            
            case 'X':
            case 'x':
            cout << "----You are now exiting the shop.----" << endl;
            return;
            break;
            
            default:
            cout << "----Sorry, I don't understand.----" << endl;
        }
    }
}

void handlePurchase(hero_t &hero, string type, int cost)
{
    hero.addMoney(-cost);
    cout << "You have purchased " << type << " for " << cost << " gold" << endl;
    cout << "You now have " << hero.getMoney() << " gold" << endl;
}

void listStats(hero_t &hero)
{
    cout << hero.getDamage() << " damage" << endl;
    cout << (int)(hero.getResistance() * 100) << "% resistance" << endl;
    cout << hero.getMaxHealth() << " health" << endl;
    cout << hero.getMaxEnergy() << " energy" << endl;
}