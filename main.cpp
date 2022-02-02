#include <iostream>
#include "hero.h"
#include "battle.h"
#include "shop.h"
using namespace std;

int main()
{
    hero_t hero;
    string name;
    cout << "Please enter a name: ";
    cin >> name;
    hero.setName(name);
    char newPerson;
    cout << "Are you new, " << hero.getName() << "? [y/n] ";
    cin >> newPerson;
    if (newPerson == 'y' || newPerson == 'y')
    {
        cout << "\n\n";
        cout << "Basically, you can fight in an arena to battle other people." << endl;
        cout << "By fighting, you get money, which you can use to buy upgrades." << endl;
        cout << "\n\n";
    }
    while (true)
    {
        cout << "----Welcome to the home screen, " << hero.getName() << "!----" << endl;
        cout << "\n\n";
        char entry;
        cout << "What would you like to do?" << endl;
        cout << "[s] Enter the shop" << endl;
        cout << "[b] Start a battle" << endl;
        cout << "[x] Exit" << endl;
        cin >> entry;
        switch (entry)
        {
            //shop
            case 'S':
            case 's':
            shop(hero);
            break;
            
            //battle
            case 'B':
            case 'b':
            startBattle(hero);
            break;
            
            //exit
            case 'X':
            case 'x':
            cout << "Bye!" << endl;
            return 0;
            break;
            
            default:
            cout << "----Sorry, I don't understand.----" << endl;
        }
    }
    return 0;
}