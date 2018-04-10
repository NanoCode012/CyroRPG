#include "../inc/InTown.h"

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
         << "4. Stop by the academy"         << endl
         << "5. Enter home"                  << endl
         << "6. Leave village"               << endl
         << "7. Quit"                        << endl
         << "Opt : ";
}

void Inn(Character &player, bool isDead)
{
    PrintLine();

    if (!isDead)
    {
        char opt;
        cout << "Welcome to the Inn."                                         << endl
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

void ShowMissionStatus(Character &player)
{
    PrintLine();

    int amountOfMissions = player.amountOfMissions;
    cout << "Status (" << amountOfMissions << "/" << player.maxAmountOfMissions << ")\n" << endl;
    for (int i = 0; i < amountOfMissions; i++)
    {
        cout << i + 1 << ".";
        player.missions[i].ShowInfo();
    }
}

Mission GenerateMission(int playerLevel)
{
    Mission mission;
    int rank = GetRandomNumber(playerLevel / 10);
    if (rank < 0) rank = 0;
    else if (rank > 5) rank = 5;
    mission.SetType(1, rank);
    return mission;
}

void MissionBoard(Character &player)
{
    PrintLine();

    int opt, temp;
    int amountOfMissionsInBoard = 3;
    Mission *missions = new Mission[amountOfMissionsInBoard];
    bool *missionsTaken = new bool[amountOfMissionsInBoard];

    //GenerateMissions
    for (int i = 0; i < amountOfMissionsInBoard; i++)
    {
        missions[i] = GenerateMission(player.level);
    }

    cout << "Welcome to the Mission board" << endl;
    
    while(true)
    {
        cout << "How can I help you today?"     << endl
            << "1. Check my current mission(s)" << endl
            << "2. Check available mission(s)"  << endl
            << "3. Exit"                        << endl
            << "Opt : ";
        cin >> opt;
        if (opt == 3) break;
        switch(opt)
        {
            case 1:
                ShowMissionStatus(player);
                cout << "Which do you want to expand upon?" << endl
                     << "Opt : ";
                cin >> opt;
                if (opt <= 0 || opt > player.amountOfMissions)
                {
                    cout << "Invalid Option" << endl;
                    break;
                }

                player.missions[opt - 1].ShowInfo();
                cout << "Options : "    << endl
                     << "1. Turn in"    << endl
                     << "2. Forfeit"    << endl
                     << "Opt : ";
                cin >> temp;
                switch(temp)
                {
                    case 1:
                        player.CheckMissionSuccessAndCalculate(opt - 1);
                        break;
                    case 2:
                        player.ForfeitMission(opt - 1);
                        break;
                    default:
                        cout << "Invalid Option" << endl;
                        break;
                }
                break;
            case 2:
                cout << "Which mission do you want to accept?" << endl;
                for (int i = 0; i < amountOfMissionsInBoard; i++)
                {
                    if (!missionsTaken[i])
                    {
                        cout << i + 1 << ". " << missions[i].name << endl;
                    }
                }
                cout << "Opt : ";
                cin >> opt;
                if (opt <= 0)
                {
                    cout << "Invalid Option" << endl;
                    break;
                }
                if (player.amountOfMissions >= player.maxAmountOfMissions)
                {
                    cout << "You cannot accept any more missions" << endl;
                } 
                else if (missionsTaken[opt - 1])
                {
                    cout << "Mission already taken" << endl;
                }
                else
                {
                    player.missions[player.amountOfMissions] = missions[opt - 1];
                    player.amountOfMissions++;
                    missionsTaken[opt - 1] = true;
                }
                break;
            default:
                cout << "Invalid Option" << endl;
                break;
        }
        PrintLine();
    }
    delete []missions;
    delete []missionsTaken;
}

Item GenerateItem(int playerLevel)
{
    Item item;
    int rarity = GetRandomNumber(playerLevel / 10);
    if (rarity < 0) rarity = 0;
    else if (rarity > 5) rarity = 5;
    item.SetType(GetRandomNumber(3), rarity, (bool)GetRandomNumber(1));
    return item;
}

void ItemShop(Character &player)
{
    PrintLine();

    int amountOfItemsInShop = 3;
    Item *items = new Item[amountOfItemsInShop];
    bool *itemsBought = new bool[amountOfItemsInShop];

    for (int i = 0; i < amountOfItemsInShop; i++)
    {
        items[i] = GenerateItem(player.level);
    }

    cout << "Welcome to my lovely shop" << endl;
    while(true)
    {
        cout << "What would you like to purchase?" << endl;

        //Show items that can be bought
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

        if (opt == amountOfItemsInShop + 1) break;//Exit
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
        
        PrintLine();
    }
    delete []items;
    delete []itemsBought;
}

void ShowAvailableSkills(Character &player, bool showIndex)
{
    if (showIndex)
    {
        for (int i = 0; i < player.amountOfSkills; i++)
        {
            cout << i + 1 << ". \t" << player.skills[i].name << endl;
            player.skills[i].ShowInfo(false);
            cout << endl;
        }
    }
    else 
    {
        for (int i = 0; i < player.amountOfSkills; i++)
        {
            player.skills[i].ShowInfo();
            cout << endl;
        }
    }
}

void FindUnlearntSkill(Character &player, bool *(&learnt))
{
    int classID = player.role;
    int maxSkill = player.maxAmountOfSkills;
    int skillAmount = player.amountOfSkills;

    for (int i = 0; i < skillAmount; i++)
    {
        for (int j = 1; j <= maxSkill; j++)
        {
            if (learnt[j]) continue;
            if ((classID - 1) * 3 + j == player.skills[i].id)
            {
                learnt[j] = true;
                break;
            }
        }
    }
}

void ShowUnlearntSkill(Character &player, bool *(&learnt))
{
    int classID = player.role;
    int maxSkill = player.maxAmountOfSkills;

    FindUnlearntSkill(player, learnt);

    Skill temp;
    for (int i = 1; i <= maxSkill; i++)
    {
        if (!learnt[i])
        {
            temp.SetType((classID - 1) * 3 + i);
            cout << i << ". \t" << temp.name << endl;
            temp.ShowInfo(false);
            cout << endl;
        }
    }
}

void Academy(Character &player)
{
    PrintLine();

    cout << "Hello " << player.name << "!" << endl
         << "Welcome back to the Academy!" << endl;

    int opt;
    int maxSkill = player.maxAmountOfSkills;
    bool *learnt = new bool[maxSkill + 1];
    for (int i = 1; i <= maxSkill; i++) learnt[i] = false;
    while(true)
    {
        cout << "What would you like to do?"    << endl
             << "1. Check current skill(s)"     << endl
             << "2. Learn a new skill"          << endl
             << "3. Level up my current skill"  << endl
             << "4. Quit"                       << endl
             << "Opt : ";
        cin >> opt;
        if (opt == 4) break;
        PrintLine();
        switch(opt)
        {
            case 1:
                ShowAvailableSkills(player, false);
                break;
            case 2:
                if (player.amountOfSkills < player.maxAmountOfSkills)
                {
                    cout << "Which skill would you like to learn?" << endl;
                    ShowUnlearntSkill(player, learnt);
                    cout << "Opt : ";
                    cin >> opt;
                    if (opt < 1 || opt > maxSkill) 
                    {
                        cout << "Invalid Option" << endl;
                        break;
                    }
                    if (!learnt[opt])
                    {
                        cout << "LOG: SKILL LEARNT" << endl;
                        player.SetSkill(opt);
                    }
                    else
                    {
                        cout << "Skill already learnt" << endl;
                    }
                }
                else
                {
                    cout << "You already have learned all the skills for that class" << endl;
                }
                break;
            case 3:
                cout << "Which skill would you like to upgrade?" << endl;
                ShowAvailableSkills(player);
                cout << "Opt : ";
                cin >> opt;
                if (opt < 1 || opt > player.amountOfSkills)
                {
                    cout << "Invalid Option" << endl;
                    break;
                }
                if (player.skills[opt - 1].level >= player.maxSkillLevel)
                {
                    cout << "This skill's level is already maxed out" << endl;
                }
                else
                {
                    cout << "LOG: LEVEL SKILL UP" << endl;
                    player.SetSkill(player.skills[opt - 1].id, player.skills[opt - 1].level + 1, opt - 1);
                }
                break;
        }

        PrintLine();
    }
}

void Quit(Character &player)
{
    int opt;
    PrintLine();
    cout << "Do you really want to quit?" << endl
            << "Option : "                   << endl
            << "1. Yes"                      << endl
            << "2. No"                       << endl;
    cout << "Opt : ";
    cin >> opt;
    if (opt == 1)
    {
        PrintLine();
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
    }
}

void InTown(Character &player)
{
    int opt;
    if (!player.IsAlive()) Inn(player, true);
    while(true)
    {
        OptionsInTown();
        cin >> opt;
        if (opt > 10) continue;//Defense, albeit better than nothing
        if (opt == 6) break;//Leave intown for outtown
        switch(opt)
        {
            case 1:
                Inn(player);
                break;
            case 2:
                MissionBoard(player);
                break;
            case 3:
                ItemShop(player);
                break;
            case 4:
                Academy(player);
                break;
            case 5:
                Home(player);
                break;
            case 7:
                Quit(player);
                break;
            default:
                cout << "Invalid Option" << endl;
                break;
        }
    }
}

