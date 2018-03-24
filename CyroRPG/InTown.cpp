#include "./InTown.h"

using namespace std;

void OptionsInTown()
{
    PrintLine();
    cout << "You looked around, and you find some things you can do .." << endl;
    cout << "What would you like to do?"     << endl
         << "Opt : "                         << endl
         << "1. Visit Inn"                   << endl
         << "2. Check Misionboard"           << endl
         << "3. Go to Item shop"             << endl
         << "4. Look at stats and inventory" << endl
         << "5. Leave village"               << endl
         << "6. Quit"                        << endl;
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

void ShowPlayerStatsFull(Character &player)
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


void InTown(Character &player)
{
    int opt;
    if (!player.IsAlive()) Inn(player, true);
    while(true)
    {
        OptionsInTown();
        cin >> opt;
        if (opt == 5) break;
        if (opt == 6) CleanExit();
        switch(opt)
        {
            case 1:
                Inn(player);
                break;
            case 2:
                //MissionBoard(player);
                break;
            case 3:
                //ItemShop(player);
                break;
            case 4:
                ShowPlayerStatsFull(player);
                break;
            default:
                cout << "Invalid Option" << endl;
                break;
        }
    }
}

