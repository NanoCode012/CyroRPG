#include "../inc/Mission.h"

using namespace std;

void Mission::Unreceived()
{
    status = -1;
}

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
    Start();

    Monster monster;
    switch(id)
    {
        case 1:
            typeOfMonsterToKill = (rank / 2) + 1;
            do {
                amountOfMonsterToKill = GetRandomNumber((rank * 10) + 10);
                } while(amountOfMonsterToKill <= 0);

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
    cout << "\t" << name << " ";

    Monster monster;
    monster.SetType(typeOfMonsterToKill, 1);
    switch(id)
    {
        case 1:
            cout << "(" << amountOfMonsterAlreadyKilled << "/" << amountOfMonsterToKill << ") ";
            break;
        case 2:
            cout << "(";
            switch(talkToNPCID)
            {
                case 0:
                    cout << "Inn owner";
                    break;
                case 1:
                    cout << "Item shop owner";
                    break;
                case 2:
                    cout << "Mission board owner";
                    break;
                case 3:
                    cout << "Helio the Sage";
                    break;
            }
            cout << ")";
            break;
    }

    switch(status)
    {
        case -1:
            cout << "[Unreceived]" << endl;
            break;
        case 0:
            cout << "[Ongoing]" << endl;
            break;
        case 1:
            cout << "[Success]" << endl;
            break;
        case 2:
            cout << "[Delayed]" << endl;
            break;
        case 3:
            cout << "[Failed]" << endl;
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
            if (amountOfMonsterAlreadyKilled >= amountOfMonsterToKill)
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