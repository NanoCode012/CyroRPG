#include "../inc/DataController.h"

using namespace std;

string path = "Data.txt";

bool CanReadData()
{

    ifstream readStream(path);
    bool canRead = readStream.is_open();
    readStream.close();
    return canRead;
}

void SaveData(Character &player)
{
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

    writeStream << player.amountOfMissions << "/" << player.maxAmountOfMissions << endl;

    //Save mission data
    Mission mission;
    for (int i = 0; i < player.amountOfMissions; i++)
    {
        mission = player.missions[i];
        writeStream << mission.id     << "/" << mission.status      << "/"
                    << mission.reward << "/" << mission.difficulty  << "/"
                    << mission.name   << "/";
        switch (player.missions[i].id)
        {
            case 1:
                writeStream << mission.typeOfMonsterToKill              << "/" 
                            << mission.amountOfMonsterAlreadyKilled     << "/"
                            << mission.amountOfMonsterToKill            << "/";
                break;
            case 2:
                writeStream << (int)mission.hasTalkedToNPC              << "/" 
                            << mission.talkToNPCID                      << "/";
                break;
        }
        writeStream << endl;
    }

    //Save inventory data
    writeStream << player.amountOfItems << "/" << player.maxAmountOfItems << endl;
    Item item;
    for (int i = 0; i < player.amountOfItems; i++)
    {
        item = player.inventory[i];
        writeStream << item.id      << "/" << (int)item.isEquippable << "/"
                    << item.level   << "/" << item.cost              << "/"
                    << (int)item.isNull << "/";
        if (item.isEquippable)
        {
            switch(item.id)
            {
                case 0:
                    writeStream << item.damageReduction << "/";
                    break;
                case 1:
                    writeStream << item.defense << "/";
                    break;
                case 2:
                    writeStream << item.criticalDamagePercentage << "/";
                    break;
                case 3:
                    writeStream << item.chanceOfEvasion << "/";
                    break;
            }
        }
        else
        {
            switch(item.id)
            {
                case 0:
                    writeStream << item.hp << "/";
                    break;
                case 1:
                    writeStream << item.mana << "/";
                    break;
                case 2:
                    writeStream << item.chanceOfEvasion << "/";
                    break;
                case 3:
                    writeStream << item.chanceOfCriticalDamage << "/";
                    break;
            }
        }
        writeStream << endl;
    }

    //Save equipped data
    for (int i = 0; i < 5; i++)
    {
        item = player.equipped[i];
        writeStream << item.id      << "/" << (int)item.isEquippable << "/"
                    << item.level   << "/" << item.cost              << "/"
                    << (int)item.isNull  << "/";
        switch(item.id)
        {
            case 0:
                writeStream << item.damageReduction << "/";
                break;
            case 1:
                writeStream << item.defense << "/";
                break;
            case 2:
                writeStream << item.criticalDamagePercentage << "/";
                break;
            case 3:
                writeStream << item.chanceOfEvasion << "/";
                break;
        }
        writeStream << endl;
    }

    writeStream << endl;
    writeStream.close();
}

void LoadData(Character &player)
{
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

        if (getline(readStream, input)) player.chanceOfEvasion = ConvertFromStringToFloat(input);
        
        if (getline(readStream, input)) player.chanceOfDamageReduction = ConvertFromStringToFloat(input);
        if (getline(readStream, input)) player.damageReduction = (float)ConvertFromStringToInt(input);
        
        if (getline(readStream, input)) player.chanceOfCriticalDamage = ConvertFromStringToFloat(input);
        if (getline(readStream, input)) player.criticalDamagePercentage = ConvertFromStringToFloat(input);
        
        if (getline(readStream, input)) player.amountOfExtraActionAtStartTurn = ConvertFromStringToInt(input);

        //Skill
        if (getline(readStream, input)) SeparateAndSetData(input, player.amountOfSkills, player.maxAmountOfSkills);
        int amountOfSkills = player.amountOfSkills;
        for (int i = 0; i < player.amountOfSkills; i++)
        {
            if (getline(readStream, input)) 
            {
                SeparateAndSetData(input, player.skills[i].id, player.skills[i].level);
                player.SetSkill(player.skills[i].id, player.skills[i].level, i);
            }
        }

        //Load boss killed data
        if (getline(readStream, input)) SeparateAndSetBossData(input, player.killedBoss, 3);

        //Load mission data
        if (getline(readStream, input)) SeparateAndSetData(input, player.amountOfMissions, player.maxAmountOfMissions);
        for (int i = 0; i < player.amountOfMissions; i++)
        {
            if (getline(readStream, input)) SeparateAndSetMissionData(input, player.missions[i]);
        }

        //Load inventory data
        if (getline(readStream, input)) SeparateAndSetData(input, player.amountOfItems, player.maxAmountOfItems);
        for (int i = 0; i < player.amountOfItems; i++)
        {
            if (getline(readStream, input)) SeparateAndSetItemData(input, player.inventory[i]);
        }

        //Load equipped data
        for (int i = 0; i < 5; i++)
        {
            if (getline(readStream, input)) SeparateAndSetItemData(input, player.equipped[i]);
        }
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

void SeparateAndSetBossData(string input, bool *arr, int size, char separator, char endSign)
{
    int i = 0;
    for (int k = 0; k < size - 1; k++)
    {
        arr[k] = (input[i] == '1');
        i++;//To skip the separator
    }

    arr[size - 1] = (input[i] == '1');
}

void SeparateAndSetMissionData(string input, Mission &mission)
{
    int i = 0;

    mission.id = input[i] - '0'; i+=2;
    mission.status = input[i] - '0'; i+=2;
    
    string temp = "";
    while(input[i] != '/') 
    {
        temp += input[i];
        i++;
    }
    mission.reward = ConvertFromStringToInt(temp); i++;

    mission.difficulty = input[i] - '0'; i+=2;

    temp = "";
    while(input[i] != '/') 
    {
        temp += input[i];
        i++;
    }
    mission.name = temp; i++;

    switch(mission.id)
    {
        case 1:
            mission.typeOfMonsterToKill = input[i] - '0'; i+=2;
            
            temp = "";
            while(input[i] != '/') 
            {
                temp += input[i];
                i++;
            }
            mission.amountOfMonsterAlreadyKilled = ConvertFromStringToInt(temp); i++;
            
            temp = "";
            while(input[i] != '/') 
            {
                temp += input[i];
                i++;
            }
            mission.amountOfMonsterToKill = ConvertFromStringToInt(temp); i++;
            break;
        case 2:
            mission.hasTalkedToNPC = (bool)(input[i] - '0'); i+=2;
            mission.talkToNPCID = input[i] - '0'; i+=2;
            break;
    }
}

void SeparateAndSetItemData(string input, Item &item)
{
    //Check if first num is -1, by looking for '-', then it must be null
    if (input[0] == '-')
    {
        item.isNull = true;
    }
    else
    {
        int i = 0;
        item.id = input[i] - '0'; i+=2;
        item.isEquippable = (bool)(input[i] - '0'); i+=2;
        item.level = input[i] - '0'; i+=2;
        item.SetType(item.id, item.level, item.isEquippable);

        string temp = "";
        while(input[i] != '/') 
        {
            temp += input[i];
            i++;
        }
        item.cost = ConvertFromStringToInt(temp); i++;
        item.isNull = (bool)(input[i] - '0'); i+=2;
        
        temp = "";
        while(input[i] != '/') 
        {
            temp += input[i];
            i++;
        }
        if (item.isEquippable)
        {
            switch(item.id)
            {
                case 0:
                    item.damageReduction = ConvertFromStringToInt(temp);
                    break;
                case 1:
                    item.defense = ConvertFromStringToInt(temp);
                    break;
                case 2:
                    item.criticalDamagePercentage = ConvertFromStringToFloat(temp);
                    break;
                case 3:
                    item.chanceOfEvasion = ConvertFromStringToFloat(temp);
                    break;
            }
        }
        else
        {
            switch(item.id)
            {
                case 0:
                    item.hp = ConvertFromStringToFloat(temp);
                    break;
                case 1:
                    item.mana = ConvertFromStringToFloat(temp);
                    break;
                case 2:
                    item.chanceOfEvasion = ConvertFromStringToFloat(temp);
                    break;
                case 3:
                    item.chanceOfCriticalDamage = ConvertFromStringToFloat(temp);
                    break;
            }
        }
    }
}