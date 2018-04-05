#include "../inc/Skill.h"

void Skill::SetType(int skillID, int lvl)
{
    id = skillID;
    level = lvl;

    switch(skillID)
    {
        //Guard
        case 1:
            name = "Guard";
            isActive = false;
            switch(level)
            {
                case 1:
                    defenseIncreasePercentage = 0.1;
                    break;
                case 2:
                    defenseIncreasePercentage = 0.15;
                    break;
                case 3:
                    defenseIncreasePercentage = 0.25;
                    break;
            }
            break;
        //Sword Barrage
        case 2:
            name = "Sword Barrage";
            isActive = true;
            switch(level)
            {
                case 1:
                    damageMultiplier = 2;
                    manaCost = 5;
                    break;
                case 2:
                    damageMultiplier = 3;
                    manaCost = 8;
                    break;
                case 3:
                    damageMultiplier = 4;
                    manaCost = 12;
                    break;
            }
            break;
        //Shock
        case 3:
            name = "Shock";
            isActive = true;
            switch(level)
            {
                case 1:
                    stunnedTurns = 1;
                    damage = 100;
                    manaCost = 10;
                    break;
                case 2:
                    stunnedTurns = 1;
                    damage = 300;
                    manaCost = 18;
                    break;
                case 3:
                    stunnedTurns = 2;
                    damage = 500;
                    manaCost = 25;
                    break;
            }
            break;
        //Hell Fire
        case 4:
            name = "Hell Fire";
            isActive = true;
            switch(level)
            {
                case 1:
                    damage = 150;
                    damageOverTime = 25;
                    amountOfTurnsDOT = 1;
                    manaCost = 10;
                    break;
                case 2:
                    damage = 250;
                    damageOverTime = 25;
                    amountOfTurnsDOT = 2;
                    manaCost = 20;
                    break;
                case 3:
                    damage = 350;
                    damageOverTime = 35;
                    amountOfTurnsDOT = 3;
                    manaCost = 30;
                    break;
            }
            break;
        //Frostbite
        case 5:
            name = "Frostbite";
            isActive = true;
            switch(level)
            {
                case 1:
                    damage = 100;
                    damageReductionPercentage = 0.2;
                    manaCost = 7;
                    break;
                case 2:
                    damage = 150;
                    damageReductionPercentage = 0.3;
                    manaCost = 9;
                    break;
                case 3:
                    damage = 200;
                    damageReductionPercentage = 0.65;
                    manaCost = 12;
                    break;
            }
            break;
        //Thunder Strike
        case 6:
            name = "Thunder Strike";
            isActive = true;
            stunnedTurns = 1;
            switch(level)
            {
                case 1:
                    damage = 50;
                    chanceOfStun = 0.2;
                    manaCost = 5;
                    break;
                case 2:
                    damage = 100;
                    chanceOfStun = 0.35;
                    chanceOfDrainHP = 0.2;
                    hpDrainOfMaxPercentage = 0.2;
                    manaCost = 8;
                    break;
                case 3:
                    damage = 150;
                    chanceOfStun = 0.5;
                    chanceOfDrainHP = 0.5;
                    hpDrainOfMaxPercentage = 0.35;
                    manaCost = 15;
                    break;
            }
            break;
        //Swift
        case 7:
            name = "Swift";
            isActive = false;
            switch(level)
            {
                case 1:
                    chanceOfEvasion = 0.1;
                    chanceOfDamageReduction = 0.3;
                    damageReduction = 20;
                    break;
                case 2:
                    chanceOfEvasion = 0.2;
                    chanceOfDamageReduction = 0.3;
                    damageReduction = 30;
                    break;
                case 3:
                    chanceOfEvasion = 0.3;
                    chanceOfDamageReduction = 0.3;
                    damageReduction = 40;
                    break;
            }
            break;
        //Sharp Eye
        case 8:
            name = "Sharp Eye";
            isActive = false;
            switch(level)
            {
                case 1:
                    chanceOfCriticalDamage = 0.2;
                    criticalDamagePercentage = 0.25;
                    break;
                case 2:
                    chanceOfCriticalDamage = 0.3;
                    criticalDamagePercentage = 0.5;
                    break;
                case 3:
                    chanceOfCriticalDamage = 0.5;
                    criticalDamagePercentage = 0.75;
                    break;
            }
            break;
        //Arrow Burst
        case 9:
            name = "Arrow Burst";
            isActive = true;
            chanceOfFiringAgain[0] = 0;
            chanceOfFiringAgain[1] = 0;
            switch(level)
            {
                case 1:
                    damage = 150;
                    chanceOfFiringAgain[0] = 0.3;
                    break;
                case 2:
                    damage = 225;
                    chanceOfFiringAgain[0] = 0.5;
                    break;
                case 3:
                    damage = 325;
                    chanceOfFiringAgain[0] = 0.75;
                    chanceOfFiringAgain[1] = 0.25;
                    break;
            }
            break;
    }
}