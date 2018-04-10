#include "../inc/Home.h"

using namespace std;

void OptionsHome()
{
    PrintLine();
    cout << "You look at the mirror and see yourself .." << endl;
    cout << "1. Check stats"                             << endl
         << "2. Observe skills"                          << endl
         << "3. View equipped gear"                      << endl
         << "4. Look in inventory"                       << endl
         << "5. Show all info"                           << endl
         << "6. Equip gear"                              << endl
         << "7. Unequip gear"                            << endl
         << "8. Save"                                    << endl
         << "9. Leave home"                              << endl
         << "Opt : ";
}

void ShowItemStats(Item item, bool showName)
{
    if (showName)
    {
        cout << "\tName : " << item.name << endl;
    }
    cout  << "\tCost : "      << item.cost << "G"                             << endl
          << "\tCan Equip : " << ((item.isEquippable) ? "Yes" : "No")         << endl
          << "\tRarity : "    << item.level                                   << endl;
    if (item.isEquippable)
    {
        switch(item.id)
        {
            case 0:
                cout << "\tDamage Reduction : " << item.damageReduction << endl;
                break;
            case 1:
                cout << "\tDefense : " << item.defense << endl;
                break;
            case 2:
                cout << "\tCritical Multiplier : " << item.criticalDamagePercentage << endl;
                break;
            case 3:
                cout << "\tEvasion : " << item.chanceOfEvasion << endl;
                break;
        }
    }
    else
    {
        switch(item.id)
        {
            case 0:
                cout << "\tHP : " << item.hp << endl;
                break;
            case 1:
                cout << "\tMana : " << item.mana << endl;
                break;
            case 2:
                cout << "\tEvasion : " << item.chanceOfEvasion << endl;
                break;
            case 3:
                cout << "\tCritical Chance : " << item.chanceOfCriticalDamage << endl;
                break;
        }
    }
}

void ShowPlayerStats(Character &player)
{
    cout << "Stats\n"
         << "\n\tName : " << player.name
         << "\n\tHP : " << player.currentHp << " / " << player.maxHp
         << "\n\tMP : " << player.currentMana << " / " << player.maxMana
         << "\n\tLevel : " << player.level
         << "\n\tExp : " << player.currentExp << " / " << player.expToNextLevel
         << "\n\tG : " << player.gold
         << "\n\tClass : " << player.GetClassName()
         << "\n\tAttack Power : " << player.attackDamageMin << " - " << player.attackDamageMax
         << "\n\tDefense : " << player.defense
         << "\n\tEvasion : " << player.chanceOfEvasion * 100 << " % "
         << "\n\tDamage Reduction Chance : " << player.chanceOfDamageReduction * 100 << " % "
         << "\n\tDamage Reduction : " << player.damageReduction
         << "\n\tCritical Chance : " << player.chanceOfCriticalDamage * 100 << " % "
         << endl;
}

void ShowPlayerSkills(Character &player)
{
    cout << "Skills\n" << endl;
    int amountOfSkills = player.amountOfSkills;
    bool hasSkill = (amountOfSkills > 0);
    if (hasSkill)
    {
        for (int i = 0; i < amountOfSkills; i++)
        {
            cout << "\t" << player.skills[i].name << " (Lvl: " << player.skills[i].level << ")" << endl;
        }
    }
    else
    {
        cout << "\tNone" << endl;
    }
}

void ShowPlayerEquippedGear(Character &player, bool showWithNumbering)
{
    cout << "Equipped Gear\n" << endl;
    int amountOfItems = 5;
    bool hasGear = false;
    if (!showWithNumbering)
    {
        for (int i = 0; i < amountOfItems; i++)
        {
            if (!player.equipped[i].isNull)
            {
                hasGear = true;
                ShowItemStats(player.equipped[i]);
                cout << endl;
            }
        }
    }
    else
    {
        for (int i = 0; i < amountOfItems; i++)
        {
            if (!player.equipped[i].isNull)
            {
                hasGear = true;
                cout << i + 1 << ". " << player.equipped[i].name << endl;
                ShowItemStats(player.equipped[i], false);
                cout << endl;
            }
        }
    }
    if (!hasGear)
    {
        cout << "\tNone" << endl;
    }
}

void ShowPlayerInventory(Character &player)
{
    int amountOfItems = player.amountOfItems;
    cout << "Inventory ( " << amountOfItems << " / " << player.maxAmountOfItems << " )\n" << endl;
    bool hasItems = (amountOfItems > 0);
    if (hasItems)
    {
        for (int i = 0; i < amountOfItems; i++)
        {
            ShowItemStats(player.inventory[i]);
            cout << endl;
        }
    }
    else
    {
        cout << "\tNone" << endl;
    }
}

void ShowAllPlayerInfo(Character &player)
{   
    ShowPlayerStats(player);

    cout << endl;
    ShowPlayerSkills(player);

    cout << endl;
    ShowPlayerEquippedGear(player);

    cout << endl;
    ShowPlayerInventory(player);    
}

void ShowPlayerEquippableGear(Character &player)
{
    cout << "Equippable Items in Inventory\n" << endl;
    int amountOfItems = player.amountOfItems;
    bool hasEquippableItems = false;
    for (int i = 0; i < amountOfItems; i++)
    {
        if (player.inventory[i].isEquippable)
        {
            hasEquippableItems = true;
            cout << i + 1 << ". " << player.inventory[i].name << endl;
            ShowItemStats(player.inventory[i], false);
            cout << endl;
        }
    }
    if (!hasEquippableItems) cout << "\tNone" << endl;
}

void EquipItem(Character &player, int indexInInventory)
{
    int amountOfItems = player.amountOfItems;
    if (indexInInventory < 1 || indexInInventory > amountOfItems) 
    {
        cout << "Invalid Item" << endl;
    }
    else
    {
        player.Equip(indexInInventory - 1);
    }
}

void UnequipItem(Character &player, int indexInEquipped)
{
    if (indexInEquipped < 1 || indexInEquipped > 5) 
    {
        cout << "Invalid Item" << endl;
    }
    else
    {
        player.Unequip(indexInEquipped - 1);
    }
}

void Home(Character &player)
{
    int opt;
    while(true)
    {
        OptionsHome();
        cin >> opt;
        if (opt == 9) break;
        PrintLine();
        switch(opt)
        {
            case 1:
                ShowPlayerStats(player);
                break;
            case 2:
                ShowPlayerSkills(player);
                break;
            case 3:
                ShowPlayerEquippedGear(player);
                break;
            case 4:
                ShowPlayerInventory(player);
                break;
            case 5:
                ShowAllPlayerInfo(player);
                break;
            case 6:
                ShowPlayerEquippableGear(player);
                cout << "Which item do you want to equip?(0 to cancel)" << endl;
                cout << "Opt : ";
                cin >> opt;
                if (opt != 0) EquipItem(player, opt);
                break;
            case 7:
                ShowPlayerEquippedGear(player, true);
                cout << "Which item do you want to unequip?(0 to cancel)" << endl;
                cout << "Opt : ";
                cin >> opt;
                if (opt != 0) UnequipItem(player, opt);
                break;
            case 8:
                SaveData(player);
                cout << "Data Saved" << endl;
                break;
            default:
                cout << "Invalid Option" << endl;
                break;
        }
    }
}