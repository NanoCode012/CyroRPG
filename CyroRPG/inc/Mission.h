#pragma once
#include <iostream>
#include <string>
#include "./Random.h"
#include "./Monster.h"
#include "./Misc.h"

struct Mission
{
    int id = -1;
    int status = -1;
    int reward = -1;
    int difficulty = -1;//0->5 from lowest to highest level
    std::string name = "";

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

    void ShowInfo();

    bool CheckSuccess();
};