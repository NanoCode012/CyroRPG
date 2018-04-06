#include "../inc/Mission.h"

using namespace std;

void Mission::Start()
{
    status = 0;
}

void Mission::Success()
{
    status = 1;
}

void Mission::Delayed()
{
    status = 2;
}

void Mission::Failed()
{
    status = 3;
}

void Mission::SetType(int type, int rank)
{
    id = type;
    difficulty = rank;
    reward = GetRandomNumber(rank * 20);
    
    Monster monster;
    switch(id)
    {
        case 1:
            typeOfMonsterToKill = (rank / 2) + 1;
            amountOfMonsterToKill = GetRandomNumber(rank * 10);

            name = "Kill " + ConvertFromIntToString(amountOfMonsterToKill) + " ";
            monster.SetType(typeOfMonsterToKill, 1);
            name += monster.name;
            break;
        case 2:
            talkToNPCID = GetRandomNumber(3);
            name = "Talk to ";
            switch(talkToNPCID)
            {
                case 0:
                    name += "Inn owner";
                    break;
                case 1:
                    name += "Item store owner";
                    break;
                case 2:
                    name += "Mission board owner";
                    break;
                case 3:
                    name += "Helio the Sage";
                    break;
            }
            break;
    }
}

void Mission::ShowInfo()
{
    cout << "\tTitle : "    << name << endl;

    cout << "\tStatus : ";
    switch(status)
    {
        case -1:
            cout << "Unreceived" << endl;
            break;
        case 0:
            cout << "Success" << endl;
            break;
        case 1:
            cout << "Ongoing" << endl;
            break;
        case 2:
            cout << "Delayed" << endl;
            break;
        case 3:
            cout << "Failed" << endl;
            break;
    }

    Monster monster;
    monster.SetType(typeOfMonsterToKill, 1);
    switch(id)
    {
        case 1:
            cout << "Monster to kill : " << monster.name << endl
                 << "Amount Monster Killed : " << amountOfMonsterAlreadyKilled << endl
                 << "Amount Monster To Kill : " << amountOfMonsterToKill << endl;
            break;
        case 2:
            cout << "NPC to meet : ";
            switch(talkToNPCID)
            {
                case 0:
                    cout << "Inn owner" << endl;
                    break;
                case 1:
                    cout << "Item shop owner" << endl;
                    break;
                case 2:
                    cout << "Mission board owner" << endl;
                    break;
                case 3:
                    cout << "Helio the Sage" << endl;
                    break;
            }
            break;
    }
}

bool Mission::CheckSuccess()
{
    //Check if already success
    if (status == 1) return true;

    switch(id)
    {
        case 1:
            if (amountOfMonsterAlreadyKilled <= amountOfMonsterToKill)
            {
                Success();
            }
            break;
        case 2:
            if (hasTalkedToNPC) 
            {
                Success();
            }
            break;
    }
    return (status == 1);
}