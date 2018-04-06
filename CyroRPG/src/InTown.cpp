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
         << "4. Enter home"                  << endl
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
}

void Quit()
{
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
                Home(player);
                break;
            case 6:
                Quit();
                break;
            default:
                cout << "Invalid Option" << endl;
                break;
        }
    }
}

