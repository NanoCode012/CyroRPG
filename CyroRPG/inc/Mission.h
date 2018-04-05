#pragma once
#include "./Random.h"

struct Mission
{
    int id = -1;
    int status = -1;
    int reward = -1;
    int difficulty = -1;//0->5 from lowest to highest level

    int typeOfMonsterToKill = -1;
    int amountOfMonsterAlreadyKilled = 0;
    int amountOfMonsterToKill = 0;

    bool hasTalkedToNPC = false;
    int talkToNPCID = -1;

    void Start();
    void Success();
    void Delayed();
    void Failed();

    void SetType(int type, int rank);

    bool CheckSuccess();
};