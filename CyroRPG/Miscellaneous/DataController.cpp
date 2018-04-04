#include "./DataController.h"

using namespace std;

string path = "./Data/Data.txt";

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

        if (getline(readStream, input)) SeparateAndSetData(input, player.amountOfSkills, player.maxAmountOfSkills);

        //Skill
        int amountOfSkills = player.amountOfSkills;
        for (int i = 0; i < player.amountOfSkills; i++)
        {
            if (getline(readStream, input)) SeparateAndSetData(input, player.skills[i].id, player.skills[i].level);
            player.SetSkill(player.skills[i].id, i);
        }

        //Save boss killed data
        if (getline(readStream, input)) SeparateAndSetData(input, player.killedBoss, 3);
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

void SeparateAndSetData(string input, bool *arr, int size, char separator, char endSign)
{
    int i = 0;
    for (int k = 0; k < size - 1; k++)
    {
        arr[k] = (input[i] == '1');
        i++;//To skip the separator
    }

    arr[size - 1] = (input[i] == '1');
}