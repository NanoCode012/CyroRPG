#include "./InTown.h"

using namespace std;

void OptionsInTown()
{
    PrintLine();
    cout << "You looked around, and you find some things you can do .." << endl;
    cout << "What would you like to do?"     << endl
         << "Option : "                      << endl
         << "1. Visit Inn"                   << endl
         << "2. Check Misionboard"           << endl
         << "3. Go to Item shop"             << endl
         << "4. Look at stats and inventory" << endl
         << "5. Leave village"               << endl
         << "6. Quit"                        << endl
         << "Opt : ";
}

void Inn(Character &player, bool isDead)
{
    PrintLine();
    if (!isDead)
    {
        char opt;
        cout << "\"Welcome to the Inn."                                         << endl
             << "Would you like to stay here to relax and rejuvenate for 5G?" << endl;
        cout << "Opt (Y/N) : ";
        cin >> opt;
        if (opt == 'Y' || opt == 'y') 
        {
            if (player.gold >= 5)
            {
                player.Fullheal();
                player.gold -= 5;
                cout << "Thank you for resting here!" << endl;
            }
            else
            {
                cout << "Sorry you don't have enough G." << endl;
            }

        }
    }
    else
    {
        cout << "\"Hello ? .... Hello ? Are you OK? I found you fainted in the wild "
             << "and brought you back here. It seems like you're getting better now.\""
             << ", said the Inn Owner."
             << endl;
        int cost = GetRandomNumber(5, 15);
        if (player.gold >= cost) 
        {
            cout << "\"By the way, it cost me quite a bit to bring you here, so I'm taking "
                 << "a bit of money from you.\", pointed the Owner."
                 << endl;
        }
        else 
        {
            cout << "\"By the way, it cost me quite a bit to bring you here, so I'm taking "
                 << "a bit of money from you, but you don't have enough. You owe me "
                 << cost - player.gold
                 << "G\", sneakily pointed the Owner."
                 << endl;
        }
        player.Fullheal();
        player.gold -= cost;
    }
}

void GenerateItem(Item *items, int index, int playerLevel)
{
    Item item;
    int rarity = GetRandomNumber(playerLevel / 10);
    if (rarity < 0) rarity = 0;
    else if (rarity > 5) rarity = 5;
    item.SetType(GetRandomNumber(3), rarity, (bool)GetRandomNumber(1));
    items[index] = item;
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
        switch(item.type)
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
        switch(item.type)
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

void ItemShop(Character &player)
{
    PrintLine();

    int amountOfItemsInShop = 3;
    Item *items = new Item[amountOfItemsInShop];
    bool *itemsBought = new bool[amountOfItemsInShop];

    for (int i = 0; i < amountOfItemsInShop; i++)
    {
        GenerateItem(items, i, player.level);
    }

    cout << "Welcome to my lovely shop" << endl;
    while(true)
    {
        cout << "What would you like to purchase?" << endl;
        for (int i = 0; i < amountOfItemsInShop; i++)
        {
            if (!itemsBought[i])
            {
                cout << i + 1 << ". " << items[i].name        << endl;
                ShowItemStats(items[i], false);
            }
        }
        cout << amountOfItemsInShop + 1 << ". Exit" << endl;
        
        int opt;
        cout << "Opt : ";
        cin >> opt;

        if (opt == amountOfItemsInShop + 1) break;
        else if (opt > amountOfItemsInShop) 
        {
            cout << "Invalid Option" << endl;
        }
        else if (itemsBought[opt - 1])
        {
            cout << "Item already bought" << endl;
        }
        else
        {
            if (player.amountOfItems < player.maxAmountOfItems)
            {
                if (player.gold >= items[opt - 1].cost)
                {
                    cout << "Thank you for your patronage" << endl;
                    player.gold -= items[opt - 1].cost;
                    player.Insert(items[opt - 1]);

                    itemsBought[opt - 1] = true;
                }
                else
                {
                    cout << "You do not have enough G" << endl;
                }
            }
            else
            {
                cout << "You do not have enough space" << endl;
            }
        }

    }
}

void ShowPlayerStatsFull(Character &player)
{
    PrintLine();
    
    cout << "\nStats\n"
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

    cout << "\nSkills\n" << endl;
    for (int i = 0; i < player.amountOfSkills; i++)
    {
        cout << "\t" << player.skills[i].name << "(Lvl: " << player.skills[i].level << ")" << endl;
    }

    cout << "\nEquipped Gear\n" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (!player.equipped[i].isNull)
        {
            ShowItemStats(player.equipped[i]);
            cout << endl;
        }
    }

    cout << "\nInventory\n" << endl;
    for (int i = 0; i < player.amountOfItems; i++)
    {
        ShowItemStats(player.inventory[i]);
        cout << endl;
    }

    PrintLine();
}

void SaveData(Character &player)
{
    string path = "./Data.txt";
    ofstream writeStream;
    writeStream.open(path);
    writeStream << player.name << endl

                << player.currentHp << "/" << player.maxHp << endl
                << player.currentMana << "/" << player.maxMana << endl

                << player.level << endl
                << player.currentExp << "/" << player.expToNextLevel << endl
                
                << player.gold << endl

                << player.role << endl

                << player.attackDamageMin << "/" << player.attackDamageMax << endl
                << player.defense << endl

                << player.chanceOfEvasion << endl
                
                << player.chanceOfDamageReduction << endl
                << player.damageReduction << endl
                
                << player.chanceOfCriticalDamage << endl
                << player.criticalDamagePercentage << endl
                
                << player.amountOfExtraActionAtStartTurn << endl

                << player.amountOfSkills << "/" << player.maxAmountOfSkills << endl;

    //Save skill data
    for (int i = 0; i < player.amountOfSkills; i++)
    {
        writeStream << player.skills[i].id << "/" << player.skills[i].level << endl;
    }

    //Save boss killed data
    for (int i = 0; i < 3; i++)
    {
        writeStream << player.killedBoss[i] << "/";
    }
    writeStream << endl;
    writeStream.close();
}

void LoadData(Character &player)
{
    string path = "./Data.txt";
    string input;
    ifstream readStream(path);
    if (!readStream.is_open())
    {
        CleanExit("File not found");
    }
    else
    {
        int i = 0;
        string temp = "";
        if (getline(readStream, input)) player.name = input;

        if (getline(readStream, input)) SeparateAndSetData(input, player.currentHp, player.maxHp);
        if (getline(readStream, input)) SeparateAndSetData(input, player.currentMana, player.maxMana);
        
        if (getline(readStream, input)) player.level = ConvertFromStringToInt(input);
        if (getline(readStream, input)) SeparateAndSetData(input, player.currentExp, player.expToNextLevel);

        if (getline(readStream, input)) player.gold = ConvertFromStringToInt(input);

        if (getline(readStream, input)) player.role = ConvertFromStringToInt(input);

        if (getline(readStream, input)) SeparateAndSetData(input, player.attackDamageMin, player.attackDamageMax);
        if (getline(readStream, input)) player.defense = ConvertFromStringToInt(input);

        if (getline(readStream, input)) player.chanceOfEvasion = ConvertFromStringToPercentage(input);
        
        if (getline(readStream, input)) player.chanceOfDamageReduction = ConvertFromStringToPercentage(input);
        if (getline(readStream, input)) player.damageReduction = (float)ConvertFromStringToInt(input);
        
        if (getline(readStream, input)) player.chanceOfCriticalDamage = ConvertFromStringToPercentage(input);
        if (getline(readStream, input)) player.criticalDamagePercentage = ConvertFromStringToPercentage(input);
        
        if (getline(readStream, input)) player.amountOfExtraActionAtStartTurn = ConvertFromStringToInt(input);

        if (getline(readStream, input)) SeparateAndSetData(input, player.amountOfSkills, player.maxAmountOfSkills);

        //Skill
        int amountOfSkills = player.amountOfSkills;
        for (int i = 0; i < player.amountOfSkills; i++)
        {
            if (getline(readStream, input)) SeparateAndSetData(input, player.skills[i].id, player.skills[i].level);
            player.SetSkill(player.skills[i].id, i);
        }

        //Save boss killed data
        if (getline(readStream, input)) SeparateAndSetData(input, player.killedBoss, 3);
    }
}

void SeparateAndSetData(string input, float &first, float &second, char separator, char endSign)
{
    string temp = "";
    int i = 0;
    while(input[i] && input[i] != separator) 
    {
        temp += input[i];
        i++;
    }
    i++;//To skip the separator
    first = ConvertFromStringToFloat(temp);

    temp = "";
    while(input[i] && input[i] != endSign) 
    {
        temp += input[i];
        i++;
    }
    second = ConvertFromStringToFloat(temp);
}

void SeparateAndSetData(string input, int &first, int &second, char separator, char endSign)
{
    string temp = "";
    int i = 0;
    while(input[i] && input[i] != separator) 
    {
        temp += input[i];
        i++;
    }
    i++;//To skip the separator
    first = ConvertFromStringToInt(temp);

    temp = "";
    while(input[i] && input[i] != endSign) 
    {
        temp += input[i];
        i++;
    }
    second = ConvertFromStringToInt(temp);
}

void SeparateAndSetData(string input, bool *arr, int size, char separator, char endSign)
{
    string temp = "";
    int i = 0;
    for (int k = 0; k < size - 1; k++)
    {
        temp = "";
        while(input[i] && input[i] != separator) 
        {
            temp += input[i];
            i++;
        }
        i++;//To skip the separator
        arr[k] = (temp == "1");
    }

    temp = "";
    while(input[i] && input[i] != endSign) 
    {
        temp += input[i];
        i++;
    }
    arr[size - 1] = (temp == "1");
}

void InTown(Character &player)
{
    int opt;
    if (!player.IsAlive()) Inn(player, true);
    while(true)
    {
        OptionsInTown();
        cin >> opt;
        if (opt > 10) continue;
        if (opt == 5) break;
        switch(opt)
        {
            case 1:
                Inn(player);
                break;
            case 2:
                //MissionBoard(player);
                break;
            case 3:
                ItemShop(player);
                break;
            case 4:
                ShowPlayerStatsFull(player);
                break;
            case 6:
                cout << "Do you want to save?" << endl
                     << "Option : "            << endl
                     << "1. Yes"               << endl
                     << "2. No"                << endl
                     << "Opt : ";
                cin >> opt;
                if (opt == 1)
                {
                    SaveData(player);
                    cout << "Data Saved" << endl;
                }
                else
                {
                    cout << "Data Not Saved" << endl;
                }
                CleanExit();
                break;
            default:
                cout << "Invalid Option" << endl;
                break;
        }
    }
}

