#include "../inc/Mission.h"

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
    switch(id)
    {
        case 1:
            typeOfMonsterToKill = ((rank / 2) + 1) % ;
            amountOfMonsterToKill = GetRandomNumber(rank * 10);
            break;
        case 2:
            talkToNPCID = GetRandomNumber(2) + 1;
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