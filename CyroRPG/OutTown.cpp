#include "./OutTown.h"

using namespace std;

void Options(int playerPosition)
{
    PrintLine();
    cout << "You are now at point ";
    if (playerPosition == 0) cout << "Outskirt" << endl;
    else cout << playerPosition << endl;

    cout << "As you carefully looked at your surroundings, you are presented with choices .." << endl;
    cout << "Opt : "            << endl
         << "1. Use item"       << endl;

    if (playerPosition < 15) 
    {
        cout << "2. Walk forward" << endl;
        if (playerPosition > 0) cout << "3. Walk backward" << endl;
        else cout << "3. Return back to village" << endl;
    }
    else cout << "2. Walk backward" << endl;
    
}

void Calculate(Character &player, int opt, bool &exitStatus)
{
    switch(opt)
        {
            case 1:
                // player.ShowItem();
                break;   
            case 2:
                if (player.position < 15) player.position += 1;
                else player.position -= 1;
                break;
            case 3:
                if (player.position >= 15) break;
                if (player.position > 0) player.position -= 1;
                else exitStatus = true;
                break;
        }
}

void OutTown(Character &player)
{
    player.position = 0;
    int opt;
    bool exit = false;
    while(player.IsAlive())
    {
        Options(player.position);
        cin >> opt;
        Calculate(player, opt, exit);
        if (exit) break;

    }
}

