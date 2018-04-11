#include "../inc/OutTown.h"

using namespace std;

void Options(int playerPosition)
{
    PrintLine();
    cout << "You are now at point ";
    if (playerPosition == 0) cout << "Outskirt" << endl;
    else cout << playerPosition << endl;

    cout << "As you carefully looked at your surroundings, you are presented with choices .." << endl;
    cout << "Opt : "                 << endl
         << "1. Use item"            << endl
         << "2. Check mission stats" << endl;

    if (playerPosition < 15) 
    {
        cout << "3. Walk forward" << endl;
        if (playerPosition > 0) cout << "4. Walk backward" << endl;
        else cout << "4. Return back to village" << endl;
    }
    else cout << "3. Walk backward" << endl;
    cout << "Opt : ";
}

void UseItemInBattle(Character &player)
{
    int opt;
    ShowAvailableItemsInInventory(player);
    cin >> opt;
    if (1 <= opt && opt <= player.amountOfItems)
    {
        int temp = opt;
        for (int i = 0; i < player.amountOfItems; i++)
        {
            if (!player.inventory[i].isEquippable) temp--;
            if (temp <= 0) 
            {
                player.UseItem(i);
                break;
            }
        }
    }
    else
    {
        cout << "Invalid Option. You lost a round" << endl;
    }
}

void MoveCharacter(Character &player, int opt, bool &exitStatus)
{
    switch(opt)
        {
            case 1:
                UseItemInBattle(player);
                break;   
            case 2:
                PrintLine();
                cout << "Status\n" << endl;
                if (player.amountOfMissions <= 0)
                {
                    cout << "\tNone" << endl;
                }
                else
                {
                    for (int i = 0; i < player.amountOfMissions; i++)
                    {
                        player.missions[i].ShowInfo();
                    }
                }
                break;
            case 3:
                if (player.position < 15) player.position += 1;
                else player.position -= 1;
                break;
            case 4:
                if (player.position >= 15) break;
                if (player.position > 0) player.position -= 1;
                else exitStatus = true;
                break;
        }
}

bool CheckIfMeetEnemy(Character &player)
{
    int num = GetRandomNumber(100);
    if (player.position != 0 && player.position % 5 == 0)
    {
        if (!player.killedBoss[(player.position/5) - 1])
        {
            return true;
        }
        else return (num <= 10);
    }
    return (num <= 35 + player.position * 4);
}

void SetPlayerStats(Character &player, Monster &monster)
{
    player.turn = true;
    player.SetTempStatsEqualToNonTemp();
    for (int i = 0; i < player.amountOfSkills; i++)
    {
        //Use passive stats
        if (!player.skills[i].isActive) 
        {
            player.UseSkill(i, monster);
        }
    }
}

void SetEnemyStats(Monster &monster, Character &player)
{
    if (player.position != 0 && player.position % 5 == 0)
    {
        monster.SetType(0, player.position);
    }
    else
    {
        monster.SetType((player.position / 5) + 1, player.position);
    }
    monster.SetTempStatsEqualToNonTemp();
}

void ShowPlayerTempStats(Character &player)
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
         << "\nAttack Power : " << player.tempAttackDamageMin << " - " << player.tempAttackDamageMax
         << "\nDefense : " << player.tempDefense
         << "\nEvasion : " << player.tempChanceOfEvasion * 100 << " % "
         << "\nDamage Reduction Chance : " << player.tempChanceOfDamageReduction * 100 << " % "
         << "\nDamage Reduction : " << player.tempDamageReduction
         << "\nCritical Chance : " << player.tempChanceOfCriticalDamage * 100 << " % "
         << endl;

    cout << "\nPlayer Skills\n" << endl;
    for (int i = 0; i < player.amountOfSkills; i++)
    {
        cout << player.skills[i].name << " (Lvl: " << player.skills[i].level << ")" << endl;
    }

    PrintLine();
}

void ShowEnemyTempStats(Monster &monster)
{
    PrintLine();
    
    cout << "Monster Stats\n"
         << "\nName : " << monster.name
         << "\nHP : " << monster.currentHp << " / " << monster.maxHp
         << "\nMP : " << monster.currentMana << " / " << monster.maxMana
         << "\nLevel : " << monster.level
         << "\nAttack Power : " << monster.tempAttackDamageMin << " - " << monster.tempAttackDamageMax
         << "\nDefense : " << monster.tempDefense
         << "\nEvasion : " << monster.tempChanceOfEvasion * 100 << " % "
         << "\nDamage Reduction Chance : " << monster.tempChanceOfDamageReduction * 100 << " % "
         << "\nDamage Reduction : " << monster.tempDamageReduction
         << "\nCritical Chance : " << monster.tempChanceOfCriticalDamage * 100 << " % "
         << endl;
}

void ShowBattleOptions()
{
    PrintLine();
    cout << "Your turn .."      << endl;
    cout << "Options : "        << endl
         << "1. Normal Attack"  << endl
         << "2. Use Skill"      << endl
         << "3. Use Item"       << endl
         << "Opt : ";
}

void ShowActiveSkills(Character &player)
{
    cout << "Options : " << endl;

    for (int i = 0; i < player.amountOfSkills; i++)
    {
        if (player.skills[i].isActive)
        {
            cout << i + 1 << ". " << player.skills[i].name << endl;
        }
    }

    cout << "Opt : " ;
}

void ShowAvailableItemsInInventory(Character &player)
{
    cout << "Options : " << endl;

    bool hasItem = false;
    int index = 1;
    for(int i = 0; i < player.amountOfItems; i++)
    {
        if (!player.inventory[i].isEquippable)
        {
            hasItem = true;
            cout << index++ << ". " << player.inventory[i].name << endl;
            player.inventory[i].ShowInfo(false);
        }
    }
    if (!hasItem) cout << "\tNone" << endl;

    cout << "Opt : ";
}

void CalculatePlayerAttack(Character &player, Monster &monster, int opt)
{
    int rand = GetRandomNumber(100);
    int damage;
    switch(opt)
    {
        case 1:
            if (rand >= 100 - player.tempChanceOfCriticalDamage * 100)
            {
                cout << "You did a Critical Attack" << endl;
                damage = player.CriticalAttack();
            }
            else
            {
                cout << "You did a Normal Attack" << endl;
                damage = player.NormalAttack();
            }

            monster.DamageCalculation(damage);
            break;
        case 2:
            ShowActiveSkills(player);
            cin >> opt;
            if (1 <= opt && opt <= player.amountOfSkills && player.skills[opt - 1].isActive) 
            {
                player.UseSkill(opt - 1, monster);
            }
            else cout << "Invalid Option. You lost a round" << endl;
            break;
        case 3:
            UseItemInBattle(player);
            break;
        default:
            cout << "Invalid Option. You lost a round" << endl;
    }
    player.turn = false;
}

void CalculateMonsterAttack(Monster &monster, Character &player, int opt)
{
    int rand = GetRandomNumber(100);
    float damage;
    if (monster.amountOfTurnsDOT > 0)
    {
        monster.amountOfTurnsDOT--;
        if (monster.DamageCalculation(monster.damagedOverTime))
        {
            cout << "Enemy got damaged by " << monster.damagedOverTime 
                 << " due to status effect" << endl;
        }
        else
        {
            cout << "Status effect had no effect on enemy this round" << endl;
        }
    }
    if (monster.IsAlive())
    {
        if (monster.stunnedTurns > 0) 
        {
            monster.stunnedTurns--;
            cout << "Enemy is stunned this turn" << endl;
        }
        else
        {
            //Type of attack
            if (rand >= 100 - (monster.tempChanceOfSpecialAttack * 100)) 
            {
                cout << "Enemy used a Special Attack" << endl;
                damage = monster.SpecialAttack();
            }
            else if (rand >= 100 - (monster.tempChanceOfSpecialAttack*100) - (monster.tempChanceOfCriticalDamage*100)) 
            {
                cout << "Enemy did a Critical Attack" << endl;
                damage = monster.CriticalAttack();
            }
            else 
            {
                cout << "Enemy did a Normal Attack" << endl;
                damage = monster.NormalAttack();
            }

            if (monster.amountOfTurnsDamageReductionPercentage > 0)
            {
                monster.amountOfTurnsDamageReductionPercentage--;
                damage *= 1 - monster.damageReductionPercentage;
            }

            player.DamageCalculation(damage);
        }
    }
    else
    {
        cout << "Enemy died due to status effect" << endl;
    }
    player.turn = true;
}

void CheckIfMonsterDead(Monster &monster, Character &player)
{
    if (!monster.IsAlive()) 
    {
        if (player.position != 0 && player.position % 5 == 0) player.killedBoss[(player.position/5) - 1] = true;
        cout << "You killed the monster!"           << endl
                << "You get " << monster.gold << " G." << endl
                << "You get " << monster.exp  << " exp." << endl;
        player.gold += monster.gold;
        player.currentExp += monster.exp;
        while (player.LevelUp()) 
        {
            cout << "You leveled up!"       << endl;
            cout << "You are now level "    << player.level << "." << endl;
        }

        player.CheckIfGotRelatedMonsterMissionAndCalculate(monster.id);
    }
    else if (!player.IsAlive()) cout << "You have been defeated!"         << endl;
}

void OutTown(Character &player)
{
    player.position = 0;
    int opt;
    bool exit = false;
    do
    {
        Options(player.position);
        cin >> opt;
        MoveCharacter(player, opt, exit);
        if (exit) break;
        if (CheckIfMeetEnemy(player))
        {
            PrintLine();

            cout << "AN ENEMY APPEARED!" << endl;
            
            Monster monster;
            SetEnemyStats(monster, player);
            ShowEnemyTempStats(monster);

            PrintLine();

            SetPlayerStats(player, monster);
            
            //Early Attack for Archers
            for (int i = 0; i < player.amountOfExtraActionAtStartTurn; i++)
            {
                PrintLine();
                if (monster.IsAlive())
                {
                    cout << "You can attack " << player.amountOfExtraActionAtStartTurn - i << " turns more in advance." << endl;
                    ShowBattleOptions();
                    cin >> opt;
                    CalculatePlayerAttack(player, monster, opt);
                    ShowEnemyTempStats(monster);
                    CheckIfMonsterDead(monster, player);
                    player.turn = true;
                }
            }

            //Fighting
            while(monster.IsAlive() && player.IsAlive())
            {
                if (player.turn)
                {
                    ShowBattleOptions();
                    cin >> opt;
                    CalculatePlayerAttack(player, monster, opt);
                    ShowEnemyTempStats(monster);
                    if (player.amountOfExtraTurns > 0)
                    {
                        player.amountOfExtraTurns--;
                        player.turn = true;
                        cout << "You have " << player.amountOfExtraTurns << " extra turn(s) left" << endl;
                    }
                }
                else
                {
                    cout << "Monster is attacking  .." << endl;
                    CalculateMonsterAttack(monster, player, opt);
                    ShowPlayerTempStats(player);
                }
                CheckIfMonsterDead(monster, player);
            }
        }
    }while(player.IsAlive());
}