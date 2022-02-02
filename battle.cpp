#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include "battle.h"
#include "hero.h"

using namespace std;

string enemyNames[] = {"Marc", "Marcus", "Markus", "Mark"};
string hitPhrases[] = {"Whack!", "Slice!", "Bam!", "Pow!"};

hero_t enemy;
void startBattle(hero_t &hero)
{
    srand(time(NULL));
    
    //This resets the health and energy from previous fights
    hero.reset();
    enemy.reset();
    
    enemy.setName(enemyNames[rand() % 4]);
    float enemyTempResistance = 0.0;
    float heroTempResistance = 0.0;
    cout << "\n\n";
    cout << "----Welcome to the arena, " << hero.getName() << "!----" << endl;
    cout << "You will be fighting " << enemy.getName() << "." << endl;
    while (true)
    {
        heroTempResistance = 0.0;
        //player chooses
        char choice;
        bool validChoice = false;
        while (!validChoice)
        {
            cout << "\n\n";
            cout << "Choose an option:" << endl;
            cout << "[a] attack (-10 energy)" << endl;
            cout << "[d] defend (-1 energy)" << endl;
            cout << "[n] nothing (+10 energy)" << endl;
            cout << "[i] info" << endl;
            cout << "[You have " << hero.getEnergy() << " energy]" << endl;
            cin >> choice;
            switch (choice)
            {
                case 'A':
                case 'a':
                if (hero.getEnergy() < 10)
                {
                    cout << "----You can't do that.----" << endl;
                }
                else
                {
                    validChoice = true;
                }
                break;
                
                case 'D':
                case 'd':
                if (hero.getEnergy() < 5)
                {
                    cout << "----You can't do that.----" << endl;
                }
                else
                {
                    validChoice = true;
                }
                break;
                
                case 'N':
                case 'n':
                validChoice = true;
                break;
                
                case 'I':
                case 'i':
                showInfo(hero, enemy);
                break;
                
                default:
                cout << "----Sorry, I don't understand.----" << endl;
                cout << "\n\n";
            }
        }
        cout << "\n\n";
        switch (choice)
        {
            case 'A':
            case 'a':
            cout << "[You used 10 energy]" << endl;
            cout << hitPhrases[rand() % 4] << " You hit " << enemy.getName() << " for " << enemy.calculateDamage(hero.getDamage()) * (1 - enemyTempResistance) << " damage." << endl;
            hero.addEnergy(-10);
            enemy.subtractHealth(enemy.calculateDamage(hero.getDamage()) * (1 - enemyTempResistance));
            break;
            
            case 'D':
            case 'd':
            cout << "[You used 1 energy]" << endl;
            cout << "You are shielded from the next attack." << endl;
            hero.addEnergy(-1);
            heroTempResistance = 0.5;
            break;
            
            case 'N':
            case 'n':
            cout << "[You gained 10 energy]" << endl;
            cout << "You are now well rested." << endl;
            hero.addEnergy(10);
            break;
        }
        cout << "\n\n";
        if (enemy.getHealth() <= 0)
        {
            cout << "You have defeated " << enemy.getName() << "!" << endl;
            cout << "[You get 10 gold]" << endl;
            hero.addMoney(10);
            cout << "\n\n";
            
            //the enemy gets stronger every time the player wins
            enemy.addDamage(2);
            enemy.addMaxHealth(5);
            if (enemy.getResistance() < 0.6)
            {
                enemy.addResistance(0.03);
            }
            return;
        }
        //system("PAUSE"); //this might not work on some computers; it should print "Press any key to continue..."
        enemyTempResistance = 0.0;
        //enemy chooses
        int enemyChoice = rand() % 5;
        if (enemyChoice < 3) //3 out of 5 chance
        {
            cout << hitPhrases[rand() % 4] << " " << enemy.getName() << " hits you for " << hero.calculateDamage(enemy.getDamage()) * (1 - heroTempResistance) << " damage." << endl;
            hero.subtractHealth(hero.calculateDamage(enemy.getDamage()) * (1 - heroTempResistance));
        }
        else
        {
            cout << enemy.getName() << " does nothing....." << endl;
        }
        if (hero.getHealth() <= 0)
        {
            cout << enemy.getName() << " has defeated you!" << endl;
            cout << "[You get 3 gold]" << endl;
            hero.addMoney(3);
            cout << "\n\n";
            return;
        }
    }
}

void showInfo(hero_t &hero, hero_t &enemy)
{
    cout << "\n\n";
    cout << "You have " << hero.getHealth() << " health, " << (int)(hero.getResistance() * 100) << "% resistance, and deal " << hero.getDamage() << " damage." << endl;
    cout << enemy.getName() << " has " << enemy.getHealth() << " health, " << (int)(enemy.getResistance() * 100) << "% resistance, and deals " << enemy.getDamage() << " damage." << endl;
}