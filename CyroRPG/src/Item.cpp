#include "../inc/Item.h"

using namespace std;

void Item::SetType(int type, int rarity, bool wearable)
{
    isNull = false;

    id = type;
    level = rarity;
    cost = level * 100 + GetRandomNumber(((int)wearable + 1) * 100);
    
    isEquippable = wearable;
    if (isEquippable)
    {
        switch(id)
        {
            case 0:
                name = "Head Gear";
                damageReduction = 10 + GetRandomNumber(level * 30);
                break;
            case 1:
                name = "Body Gear";
                defense = 15 + GetRandomNumber(level * 50);
                break;
            case 2:
                name = "Leg Gear";
                criticalDamagePercentage = 0.15 + (float)GetRandomNumber(level * 10)/100;
                break;
            case 3:
                name = "Shoe Gear";
                chanceOfEvasion = 0.05 + (float)GetRandomNumber(level * 5)/100;
                break;
            case 4:
                //Weapon
                break;
        }
    }
    else
    {
        switch(id)
        {
            case 0:
                name = "Hp Potion";
                hp = 30 + GetRandomNumber(level * 30);
                break;
            case 1:
                name = "Mana Potion";
                mana = 15 + GetRandomNumber(level * 15);
                break;
            case 2:
                name = "Evasion Potion";
                chanceOfEvasion = 0.1 + (float)GetRandomNumber(level * 1)/100;
                break;
            case 3:
                name = "Critical Chance Potion";
                chanceOfCriticalDamage = 0.2 + (float)GetRandomNumber(level * 1)/100;
                break;
        }
    }
    
}

void Item::ShowInfo(bool showName)
{
    if (showName)
    {
        cout << "\tName : " << name << endl;
    }
    cout  << "\tCost : "      << cost << "G"                             << endl
          << "\tCan Equip : " << ((isEquippable) ? "Yes" : "No")         << endl
          << "\tRarity : "    << level                                   << endl;
    if (isEquippable)
    {
        switch(id)
        {
            case 0:
                cout << "\tDamage Reduction : " << damageReduction << endl;
                break;
            case 1:
                cout << "\tDefense : " << defense << endl;
                break;
            case 2:
                cout << "\tCritical Multiplier : " << criticalDamagePercentage << endl;
                break;
            case 3:
                cout << "\tEvasion : " << chanceOfEvasion << endl;
                break;
        }
    }
    else
    {
        switch(id)
        {
            case 0:
                cout << "\tHP : " << hp << endl;
                break;
            case 1:
                cout << "\tMana : " << mana << endl;
                break;
            case 2:
                cout << "\tEvasion : " << chanceOfEvasion << endl;
                break;
            case 3:
                cout << "\tCritical Chance : " << chanceOfCriticalDamage << endl;
                break;
        }
    }
}