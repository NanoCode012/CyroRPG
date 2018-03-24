#include "./Misc.h"
using namespace std;

void PrintLine(char character)
{
    for (int i = 0; i < 100; i++) cout << character;
    cout << endl;
}

void CleanExit(string message)
{
    cout << "Exiting.. Reason : " << message << endl;
    atexit(CleanUp);
    exit(0);
}

void CleanUp(void)
{
    
}

void ShowPlayerStats(Character &player)
{
    PrintLine();
    
    cout << "Player Stats\n"
         << "\nName : " << player.name
         << "\nHP : " << player.currentHp << " / " << player.maxHp
         << "\nMP : " << player.currentMana << " / " << player.maxMana
         << "\nLevel : " << player.level
         << "\nExp : " << player.currentExp << " / " << player.expToNextLevel
         << "\nG : " << player.gold
         << "\nClass : " << player.GetClassName()
         << "\nAttack Power : " << player.attackDamageMin << " - " << player.attackDamageMax
         << "\nDefense : " << player.defense
         << "\nEvasion : " << player.chanceOfEvasion * 100 << " % "
         << "\nDamage Reduction Chance : " << player.chanceOfDamageReduction * 100 << " % "
         << "\nDamage Reduction : " << player.damageReduction
         << "\nCritical Chance : " << player.chanceOfCritical * 100 << " % "
         << endl;

    cout << "\nPlayer Skills\n" << endl;
    for (int i = 0; i < player.amountOfSkills; i++)
    {
        cout << player.skills[i].name << "(Lvl: " << player.skills[i].level << ")" << endl;
    }

    PrintLine();
}

void ShowEnemyStats(Monster &monster)
{
    PrintLine();
    
    cout << "Monster Stats\n"
         << "\nName : " << monster.name
         << "\nHP : " << monster.currentHp << " / " << monster.maxHp
         << "\nMP : " << monster.currentMana << " / " << monster.maxMana
         << "\nLevel : " << monster.level
         << "\nAttack Power : " << monster.attackDamageMin << " - " << monster.attackDamageMax
         << "\nDefense : " << monster.defense
         << "\nEvasion : " << monster.chanceOfEvasion * 100 << " % "
         << "\nDamage Reduction Chance : " << monster.chanceOfDamageReduction * 100 << " % "
         << "\nDamage Reduction : " << monster.damageReduction
         << "\nCritical Chance : " << monster.chanceOfCritical * 100 << " % "
         << endl;
}