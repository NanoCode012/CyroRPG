#include "./Characters.h"

using namespace std;

void Character::SetName(string playerName)
{
    name = playerName;
}
void Character::SetClass(int index)
{
    role = index;
    switch(role)
    {
        //Warriors
        case 1:
            maxHp = 50;
            maxMana = 10;

            attackDamageMin = 20;
            attackDamageMax = 25;

            defense = 10;
            chanceOfEvasion = 0.01;

            chanceOfDamageReduction = 0.05;
            damageReduction = 5;

            chanceOfCriticalDamage = 0.05;
            break;
        //Mage
        case 2:
            maxHp = 20;
            maxMana = 30;

            attackDamageMin = 5;
            attackDamageMax = 10;

            defense = 2;
            chanceOfEvasion = 0.01;

            chanceOfDamageReduction = 0;
            damageReduction = 5;

            chanceOfCriticalDamage = 0.04;
            break;
        //Archer
        case 3:
            maxHp = 25;
            maxMana = 5;

            attackDamageMin = 30;
            attackDamageMax = 40;

            defense = 2;
            chanceOfEvasion = 0.1;

            chanceOfDamageReduction = 0;
            damageReduction = 5;

            chanceOfCriticalDamage = 0.07;

            amountOfExtraActionAtStartTurn = 2;
            break;
    }
    SetSkillForClass(role);
}

string Character::GetClassName()
{
    switch(role)
    {
        case 1:
            return "Warrior";
        case 2:
            return "Mage";
        case 3:
            return "Archer";
    }
    return "null";
}

void Character::SetTempStatsEqualToNonTemp()
{
    tempAttackDamageMin = attackDamageMin;
    tempAttackDamageMax = attackDamageMax;
    tempDefense = defense;

    tempChanceOfEvasion = chanceOfEvasion;
    tempChanceOfDamageReduction = chanceOfDamageReduction;
    tempDamageReduction = damageReduction;
    tempChanceOfCriticalDamage = chanceOfCriticalDamage;
    tempCriticalDamagePercentage = criticalDamagePercentage;
}

void Character::Insert(Item &item)
{
    if (amountOfItems < maxAmountOfItems)
    {
        inventory[amountOfItems++] = item;
    }
    else
    {
        cout << "Inventory is full!" << endl;
    }
}

void Character::ApplyItemEffect(int index, bool inInventory, bool addEffect)
{
    int multiplier = (addEffect) ? 1 : -1;
    if (!inInventory)
    {
        switch(index)
        {
            case 0:
                damageReduction += (equipped[index].damageReduction) * multiplier;
                break;
            case 1:
                defense += (equipped[index].defense) * multiplier;
                break;
            case 2:
                criticalDamagePercentage += (equipped[index].criticalDamagePercentage) * multiplier;
                break;
            case 3:
                chanceOfEvasion += (equipped[index].chanceOfEvasion) * multiplier;
                break;
        }
    }
    else
    {
        switch(inventory[index].type)
        {
            case 0:
                cout << "Your hp increased by " << inventory[index].hp << endl;
                currentHp += (inventory[index].hp);
                if (currentHp > maxHp) 
                {
                    cout << "Your hp capped at " << maxHp << endl;
                    currentHp = maxHp;
                }
                break;
            case 1:
                cout << "Your mp increased by " << inventory[index].mana << endl;
                currentMana += (inventory[index].mana);
                if (currentMana > maxMana) 
                {
                    cout << "Your mp capped at " << maxMana << endl;
                    currentMana = maxMana;
                }
                break;
            case 2:
                cout << "Your evasion increased by " << inventory[index].chanceOfEvasion * 100<< "%" << endl;
                tempChanceOfEvasion += (inventory[index].chanceOfEvasion);
                break;
            case 3:
                cout << "Your critical chance increased by " << inventory[index].chanceOfCriticalDamage * 100<< "%" << endl;
                tempChanceOfCriticalDamage += (inventory[index].chanceOfCriticalDamage);
                break;
        }
    }
}

void Character::Swap(int index, bool swapFromInventoryToEquipped, bool swapOnlyInInventory)
{
    if (!swapOnlyInInventory)
    {
        if (swapFromInventoryToEquipped)
        {
            equipped[inventory[index].type] = inventory[index];
            //if item position is at the end, do nothing
            if (index != amountOfItems - 1)
            {
                inventory[index] = inventory[amountOfItems - 1];
            }
            inventory[amountOfItems - 1].isNull = true;
            amountOfItems--;
        }
        else
        {
            inventory[amountOfItems] = equipped[index];
            equipped[index].isNull = true;
            amountOfItems++;
        }   
    }
    else
    {
        inventory[index] = inventory[amountOfItems - 1];
        inventory[amountOfItems - 1].isNull = true;
        amountOfItems--;
    }
}

void Character::Equip(int indexInInventory)
{
    if (inventory[indexInInventory].isEquippable)
    {
        if (equipped[inventory[indexInInventory].type].isNull)
        {
            int temp = inventory[indexInInventory].type;
            Swap(indexInInventory, true);
            ApplyItemEffect(temp, false);
            cout << "Item equipped" << endl;
        }
        else
        {
            cout << "Previous Gear must be unequipped first" << endl;
        }
    }
    else
    {
        cout << "Item cannot be equipped" << endl;
    }
}

void Character::Unequip(int indexInEquipped)
{
    if (amountOfItems < maxAmountOfItems)
    {
        if (!equipped[indexInEquipped].isNull)
        {
            ApplyItemEffect(indexInEquipped, false, false);
            equipped[indexInEquipped].isNull = true;
            Swap(indexInEquipped, false);
            cout << "Item unequipped" << endl;
        }
        else
        {   
            cout << "You did not equip anything at that position" << endl;
        } 
    }
    else
    {
        cout << "Cannot unequip because inventory is full" << endl;
    }
}

void Character::UseItem(int indexInInventory)
{
    cout << "You used " << inventory[indexInInventory].name << endl;
    ApplyItemEffect(indexInInventory, true);
    Swap(indexInInventory, false, true);
}

void Character::SetSkillForClass(int role)
{
    for(int i = 1; i <= maxAmountOfSkills; i++)
    {
        Character:SetSkill((role - 1) * 3 + i);
    }
}

void Character::SetSkill(int skillID, int index)
{
    if (index == -1) 
    {
        index = amountOfSkills;
        skills[index].id = skillID;
        amountOfSkills++;
    }
    switch(skillID)
    {
        //Guard
        case 1:
            skills[index].name = "Guard";
            skills[index].isActive = false;
            switch(skills[index].level)
            {
                case 1:
                    skills[index].defenseIncreasePercentage = 0.1;
                    break;
                case 2:
                    skills[index].defenseIncreasePercentage = 0.15;
                    break;
                case 3:
                    skills[index].defenseIncreasePercentage = 0.25;
                    break;
            }
            break;
        //Sword Barrage
        case 2:
            skills[index].name = "Sword Barrage";
            skills[index].isActive = true;
            switch(skills[index].level)
            {
                case 1:
                    skills[index].damageMultiplier = 2;
                    skills[index].manaCost = 5;
                    break;
                case 2:
                    skills[index].damageMultiplier = 3;
                    skills[index].manaCost = 8;
                    break;
                case 3:
                    skills[index].damageMultiplier = 4;
                    skills[index].manaCost = 12;
                    break;
            }
            break;
        //Shock
        case 3:
            skills[index].name = "Shock";
            skills[index].isActive = true;
            switch(skills[index].level)
            {
                case 1:
                    skills[index].stunnedTurns = 1;
                    skills[index].damage = 100;
                    skills[index].manaCost = 10;
                    break;
                case 2:
                    skills[index].stunnedTurns = 1;
                    skills[index].damage = 300;
                    skills[index].manaCost = 18;
                    break;
                case 3:
                    skills[index].stunnedTurns = 2;
                    skills[index].damage = 500;
                    skills[index].manaCost = 25;
                    break;
            }
            break;
        //Hell Fire
        case 4:
            skills[index].name = "Hell Fire";
            skills[index].isActive = true;
            switch(skills[index].level)
            {
                case 1:
                    skills[index].damage = 150;
                    skills[index].damageOverTime = 25;
                    skills[index].amountOfTurnsDOT = 1;
                    skills[index].manaCost = 10;
                    break;
                case 2:
                    skills[index].damage = 250;
                    skills[index].damageOverTime = 25;
                    skills[index].amountOfTurnsDOT = 2;
                    skills[index].manaCost = 20;
                    break;
                case 3:
                    skills[index].damage = 350;
                    skills[index].damageOverTime = 35;
                    skills[index].amountOfTurnsDOT = 3;
                    skills[index].manaCost = 30;
                    break;
            }
            break;
        //Frostbite
        case 5:
            skills[index].name = "Frostbite";
            skills[index].isActive = true;
            switch(skills[index].level)
            {
                case 1:
                    skills[index].damage = 100;
                    skills[index].damageReductionPercentage = 0.2;
                    skills[index].manaCost = 7;
                    break;
                case 2:
                    skills[index].damage = 150;
                    skills[index].damageReductionPercentage = 0.3;
                    skills[index].manaCost = 9;
                    break;
                case 3:
                    skills[index].damage = 200;
                    skills[index].damageReductionPercentage = 0.65;
                    skills[index].manaCost = 12;
                    break;
            }
            break;
        //Thunder Strike
        case 6:
            skills[index].name = "Thunder Strike";
            skills[index].isActive = true;
            skills[index].stunnedTurns = 1;
            switch(skills[index].level)
            {
                case 1:
                    skills[index].damage = 50;
                    skills[index].chanceOfStun = 0.2;
                    skills[index].manaCost = 5;
                    break;
                case 2:
                    skills[index].damage = 100;
                    skills[index].chanceOfStun = 0.35;
                    skills[index].chanceOfDrainHP = 0.2;
                    skills[index].hpDrainOfMaxPercentage = 0.2;
                    skills[index].manaCost = 8;
                    break;
                case 3:
                    skills[index].damage = 150;
                    skills[index].chanceOfStun = 0.5;
                    skills[index].chanceOfDrainHP = 0.5;
                    skills[index].hpDrainOfMaxPercentage = 0.35;
                    skills[index].manaCost = 15;
                    break;
            }
            break;
        //Swift
        case 7:
            skills[index].name = "Swift";
            skills[index].isActive = false;
            switch(skills[index].level)
            {
                case 1:
                    skills[index].chanceOfEvasion = 0.1;
                    skills[index].chanceOfDamageReduction = 0.3;
                    skills[index].damageReduction = 20;
                    break;
                case 2:
                    skills[index].chanceOfEvasion = 0.2;
                    skills[index].chanceOfDamageReduction = 0.3;
                    skills[index].damageReduction = 30;
                    break;
                case 3:
                    skills[index].chanceOfEvasion = 0.3;
                    skills[index].chanceOfDamageReduction = 0.3;
                    skills[index].damageReduction = 40;
                    break;
            }
            break;
        //Sharp Eye
        case 8:
            skills[index].name = "Sharp Eye";
            skills[index].isActive = false;
            switch(skills[index].level)
            {
                case 1:
                    skills[index].chanceOfCriticalDamage = 0.2;
                    skills[index].criticalDamagePercentage = 0.25;
                    break;
                case 2:
                    skills[index].chanceOfCriticalDamage = 0.3;
                    skills[index].criticalDamagePercentage = 0.5;
                    break;
                case 3:
                    skills[index].chanceOfCriticalDamage = 0.5;
                    skills[index].criticalDamagePercentage = 0.75;
                    break;
            }
            break;
        //Arrow Burst
        case 9:
            skills[index].name = "Arrow Burst";
            skills[index].isActive = true;
            skills[index].chanceOfFiringAgain[0] = 0;
            skills[index].chanceOfFiringAgain[1] = 0;
            switch(skills[index].level)
            {
                case 1:
                    skills[index].damage = 150;
                    skills[index].chanceOfFiringAgain[0] = 0.3;
                    break;
                case 2:
                    skills[index].damage = 225;
                    skills[index].chanceOfFiringAgain[0] = 0.5;
                    break;
                case 3:
                    skills[index].damage = 150;
                    skills[index].chanceOfFiringAgain[0] = 0.75;
                    skills[index].chanceOfFiringAgain[1] = 0.25;
                    break;
            }
            break;
    }
}

void Character::UseSkill(int index, Monster &monster)
{
    int rand = GetRandomNumber(100);
    float damage;
    if (currentMana < skills[index].manaCost)
    {
        cout << "You do not have enough mana. You lost a turn." << endl;
    }
    else
    {
        currentMana -= skills[index].manaCost;
        switch(skills[index].id)
        {
            //Guard Skill
            case 1:
                tempDefense = defense * (1 + skills[index].defenseIncreasePercentage);
                cout << "Your defense increased by "
                    << skills[index].defenseIncreasePercentage * 100
                    << " % "
                    << endl;
                break;
            //Sword Barrage
            case 2:
                cout << "Sword Barrage" << endl;
                if (rand > tempChanceOfCriticalDamage)
                {
                    damage = NormalAttack() * skills[index].damageMultiplier;
                    cout << "You did a Normal Attack " << skills[index].damageMultiplier << " times" << endl;
                }
                else 
                {
                    damage = CriticalAttack() * skills[index].damageMultiplier;
                    cout << "You did a Critical Attack " << skills[index].damageMultiplier << " times" << endl;
                }

                monster.DamageCalculation(damage);
                break;
            //Shock
            case 3:
                cout << "Shock" << endl;
                if (rand > tempChanceOfCriticalDamage)
                {
                    damage = skills[index].damage;
                    cout << "You did a Normal Attack" << endl;
                }
                else 
                {
                    damage = skills[index].damage * (1 + tempCriticalDamagePercentage);
                    cout << "You did a Critical Attack" << endl;
                }

                //Stun does not stack, only refreshes previous stack
                if (monster.DamageCalculation(damage))
                {
                    cout << "Enemy has been stunned for " << skills[index].stunnedTurns << " turns" << endl;
                    monster.stunnedTurns = skills[index].stunnedTurns;
                }
                break;
            //Hell Fire
            case 4:
                cout << "Hell Fire" << endl;
                if (rand > tempChanceOfCriticalDamage)
                {
                    damage = skills[index].damage;
                    cout << "You did a Normal Attack" << endl;
                }
                else 
                {
                    damage = skills[index].damage * (1 + tempCriticalDamagePercentage);
                    cout << "You did a Critical Attack" << endl;
                }

                if (monster.DamageCalculation(damage))
                {
                    monster.damagedOverTime = skills[index].damageOverTime;
                    monster.amountOfTurnsDOT = skills[index].amountOfTurnsDOT;
                }
                break;
            //Frostbite
            case 5:
                cout << "Frostbite" << endl;
                if (rand > tempChanceOfCriticalDamage)
                {
                    damage = skills[index].damage;
                    cout << "You did a Normal Attack" << endl;
                }
                else 
                {
                    damage = skills[index].damage * (1 + tempCriticalDamagePercentage);
                    cout << "You did a Critical Attack" << endl;
                }

                if (monster.DamageCalculation(damage))
                {
                    monster.damageReductionPercentage += skills[index].damageReductionPercentage;
                    monster.amountOfTurnsDamageReductionPercentage = 1;
                    cout << "Enemy's next damage will be reduced by " 
                        << ConvertFromPercentageToString(monster.damageReductionPercentage, 2) << "%" 
                        << endl;
                }
                break;
            //Thunder Strike
            case 6:
                cout << "Thunder Strike" << endl;
                if (rand > tempChanceOfCriticalDamage)
                {
                    damage = skills[index].damage;
                    cout << "You did a Normal Attack" << endl;
                }
                else 
                {
                    damage = skills[index].damage * (1 + tempCriticalDamagePercentage);
                    cout << "You did a Critical Attack" << endl;
                }

                if (monster.DamageCalculation(damage))
                {
                    rand = GetRandomNumber(100);
                    if (rand <= skills[index].chanceOfStun)
                    {
                        cout << "You stunned the enemy for " << monster.stunnedTurns << " turn(s)" << endl;
                        monster.stunnedTurns = skills[index].stunnedTurns;
                    }
                    rand = GetRandomNumber(100);
                    if (rand <= skills[index].chanceOfDrainHP)
                    {
                        //Player take half of hp drained
                        currentHp += (monster.maxHp * (1 + skills[index].hpDrainOfMaxPercentage))/2;
                        monster.currentHp -= monster.maxHp * (1 + skills[index].hpDrainOfMaxPercentage);
                    }
                }
                break;
            //Swift
            case 7:
                cout << "Swift" << endl;
                tempChanceOfEvasion += skills[index].chanceOfEvasion;
                tempChanceOfDamageReduction += skills[index].chanceOfDamageReduction;
                tempDamageReduction += skills[index].damageReduction;
                cout << "Your evasion chance increased by " << skills[index].chanceOfEvasion * 100 << "%" << endl;
                if (skills[index].chanceOfDamageReduction > 0)
                {
                    cout << "Your damage reduction chance increased by " 
                        << skills[index].chanceOfDamageReduction * 100
                        << "% against " 
                        << skills[index].damageReduction
                        << " damage"
                        << endl;
                }
                break;
            //Sharp Eye
            case 8:
                cout << "Sharp Eye" << endl;
                tempChanceOfCriticalDamage += skills[index].chanceOfCriticalDamage;
                tempCriticalDamagePercentage += skills[index].criticalDamagePercentage;
                cout << "Your critical chance increased by " << skills[index].chanceOfCriticalDamage * 100 << "%" << endl;
                cout << "Your critical damage is " << 1 + tempChanceOfCriticalDamage << "x of your normal attack" << endl;
                break;
            //Arrow Burst
            case 9:
                cout << "Arrow Burst" << endl;
                if (rand > tempChanceOfCriticalDamage)
                {
                    damage = skills[index].damage;
                    cout << "You did a Normal Attack" << endl;
                }
                else 
                {
                    damage = skills[index].damage * (1 + tempCriticalDamagePercentage);
                    cout << "You did a Critical Attack" << endl;
                }

                if (monster.DamageCalculation(damage))
                {
                    rand = GetRandomNumber(100);
                    if (rand <= skills[index].chanceOfFiringAgain[0])
                    {
                        amountOfExtraTurns++;
                        rand = GetRandomNumber(100);
                        if (rand <= skills[index].chanceOfFiringAgain[1])
                        {
                            amountOfExtraTurns++;
                        }
                        cout << "Enemy is pushed back. You get " << amountOfExtraTurns << " extra turn(s)." << endl;
                    }
                }
                break;
        }
    }
    
}

float Character::NormalAttack()
{
    return (GetRandomNumber(tempAttackDamageMin, tempAttackDamageMax));
}

float Character::CriticalAttack()
{
    return (NormalAttack() * (1 + tempCriticalDamagePercentage));
}

bool Character::DamageCalculation(float damage)
{
    bool isDamaged = false;
    //Half of defense is how much damage is removed
    if ((tempDefense / 2) >= damage)
    {
        cout << "Your defense negated the enemy's attack" << endl;
    }
    else 
    {
        damage -= tempDefense / 2;
        
        //Player evasion/damage reduct
        int rand = GetRandomNumber(100);
        if (rand > (tempChanceOfEvasion * 100))
        {
            rand = GetRandomNumber(100);
            if (rand > (tempChanceOfDamageReduction * 100))
            {
                cout << "You took " << damage << " damage" << endl;
                currentHp -= damage;
            }
            else
            {
                if (damage > tempDamageReduction)
                {
                    cout << "You took reduced damage " << endl;
                    currentHp -= damage - tempDamageReduction;
                    cout << "You took " << damage - tempDamageReduction << " damage" << endl;
                }
                else
                {
                    cout << "You negated the enemy's attack with your damage reduction" << endl;
                }
            }

        }
        else
        {
            cout << "You evaded the enemy's attack" << endl;
        }
    }
    return isDamaged;
}

void Character::IncreaseStats()
{
    switch(role)
    {
        case 1:
            maxHp += 10+level*7;
            maxMana += 1.25*level;
            attackDamageMin += 2*level;
            attackDamageMax += 2*level;
            break;
        case 2:
            maxHp += 5+level*2.5;
            maxMana += 3*level;
            attackDamageMin += 0.75*level;
            attackDamageMax += 0.75*level;
            break;
        case 3:
            maxHp += 5+level*3;
            maxMana += 1.5*level;
            attackDamageMin += 3*level;
            attackDamageMax += 3*level;
            break;
    }
}

bool Character::LevelUp()
{
    if (level >= 100) return false;
    if (expToNextLevel - currentExp <= 0.01 || currentExp >= expToNextLevel) 
    {
        level++;
        Fullheal();
        currentExp -= expToNextLevel;
        for (int i = 1; i < 25; i++)
        {
            if (i*5 > level) 
            {
                expToNextLevel += i*5;
                break;
            }
        }
        IncreaseStats();
        return true;
    }
    return false;
}

float Character::GetExpPercentage() 
{
    return (currentExp/expToNextLevel)*100;
}

void Character::Fullheal()
{
    currentHp = maxHp;
    currentMana = maxMana;
}

bool Character::IsAlive()
{
    return (currentHp > 0);
}