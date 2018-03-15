#pragma once
#include <string>
#include "./Characters.h"
#include "./Random.h"
struct Character;
struct Skill
{
    bool isActive;
    int level = 1;
    int index;
    
    int manaCost;

    //Active
    int damage;
    int damageOverTime;
    int amountOfTurns;

    //Passive
    float defense;
    float evasion;
    float chanceOfDamageReduction;
    float chanceOfCritical;

    void Set(Character player)
    {
        switch(index)
        {
            //Guard skill
            case 1:
                isActive = false;
                manaCost = 0;
                switch(level)
                {
                    case 1:
                        defense = 0.1;
                        break;
                    case 2:
                        defense = 0.15;
                        break;
                    case 3:
                        defense = 0.25;
                        break;
                }
                player.tempDefense = player.defense * (1 + defense);
                break;
            //Sword Dance
            case 2:
                isActive = true;
                switch(level)
                {
                    case 1:
                        manaCost = 5;
                        break;
                    case 2:
                        manaCost = 8;
                        break;
                    case 3:
                        manaCost = 12;
                        break;
                }
                break;
            //Shock Stun
            case 3:
                isActive = true;
                switch(level)
                {
                    case 1:
                        manaCost = 5;
                        break;
                    case 2:
                        manaCost = 8;
                        break;
                    case 3:
                        manaCost = 12;
                        break;
                }
        }
    }

    void Use()
    {

    }
};
