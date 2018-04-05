#include "../inc/Item.h"

void Item::SetType(int index, int rarity, bool wearable)
{
    isNull = false;

    type = index;
    level = rarity;
    cost = level * 100 + GetRandomNumber(((int)wearable + 1) * 100);
    
    isEquippable = wearable;
    if (isEquippable)
    {
        switch(type)
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
        }
    }
    else
    {
        switch(type)
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