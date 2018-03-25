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

void MoveCharacter(Character &player, int opt, bool &exitStatus)
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

bool CheckIfMeetEnemy(Character &player)
{
    int num = GetRandomNumber(100);
    if (player.position != 0 && player.position % 5 == 0)
    {
        return true;
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
    monster.SetType((player.position / 5) + 1, player.position);
    monster.SetTempStatsEqualToNonTemp();
}

void ShowPlayerStats(Character &player)
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
         << "\nAttack Power : " << player.attackDamageMin << " - " << player.attackDamageMax
         << "\nDefense : " << player.defense
         << "\nEvasion : " << player.chanceOfEvasion * 100 << " % "
         << "\nDamage Reduction Chance : " << player.chanceOfDamageReduction * 100 << " % "
         << "\nDamage Reduction : " << player.damageReduction
         << "\nCritical Chance : " << player.chanceOfCriticalDamage * 100 << " % "
         << endl;

    cout << "\nPlayer Skills\n" << endl;
    for (int i = 0; i < player.amountOfSkills; i++)
    {
        cout << player.skills[i].name << "(Lvl: " << player.skills[i].level << ")" << endl;
    }

    PrintLine();
}

void ShowEnemyStats(Monster &monster)
{
    PrintLine();
    
    cout << "Monster Stats\n"
         << "\nName : " << monster.name
         << "\nHP : " << monster.currentHp << " / " << monster.maxHp
         << "\nMP : " << monster.currentMana << " / " << monster.maxMana
         << "\nLevel : " << monster.level
         << "\nAttack Power : " << monster.attackDamageMin << " - " << monster.attackDamageMax
         << "\nDefense : " << monster.defense
         << "\nEvasion : " << monster.chanceOfEvasion * 100 << " % "
         << "\nDamage Reduction Chance : " << monster.chanceOfDamageReduction * 100 << " % "
         << "\nDamage Reduction : " << monster.damageReduction
         << "\nCritical Chance : " << monster.chanceOfCritical * 100 << " % "
         << endl;
}

void ShowBattleOptions()
{
    PrintLine();
    cout << "Your turn .."      << endl;
    cout << "Opt : "            << endl
         << "1. Normal Attack"  << endl
         << "2. Use Skill"      << endl
         << "3. Use Item"       << endl;
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
        default:
            cout << "Invalid Option. You lost a round" << endl;
    }
    player.turn = false;
}

void CalculateMonsterAttack(Monster &monster, Character &player, int opt)
{
    int rand = GetRandomNumber(100);
    float damage;
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
        else if (rand >= 100 - (monster.tempChanceOfSpecialAttack*100) - (monster.tempChanceOfCritical*100)) 
        {
            cout << "Enemy did a Critical Attack" << endl;
            damage = monster.CriticalAttack();
        }
        else 
        {
            cout << "Enemy did a Normal Attack" << endl;
            damage = monster.NormalAttack();
        }

        player.DamageCalculation(damage);
    }
    player.turn = true;
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
            cout << "LOG: ENEMY DETECTED!" << endl;
            
            Monster monster;
            SetEnemyStats(monster, player);
            ShowEnemyStats(monster);
            
            SetPlayerStats(player, monster);

            //Early Attack for Archers
            for (int i = 0; i < player.amountOfExtraActionAtStartTurn; i++)
            {
                cout << "You can attack " << player.amountOfExtraActionAtStartTurn - i << " turns more." << endl;
                ShowBattleOptions();
                cin >> opt;
                CalculatePlayerAttack(player, monster, opt);
                ShowEnemyStats(monster);
            }

            //Fighting
            do
            {
                if (player.turn)
                {
                    ShowBattleOptions();
                    cin >> opt;
                    CalculatePlayerAttack(player, monster, opt);
                    ShowEnemyStats(monster);
                    if (!monster.IsAlive()) break;
                }
                else
                {
                    cout << "Monster is attacking  .." << endl;
                    CalculateMonsterAttack(monster, player, opt);
                    ShowPlayerStats(player);
                }

            }while(monster.IsAlive() && player.IsAlive());
            if (!monster.IsAlive()) 
            {
                cout << "You killed the monster!"           << endl
                     << "You get " << monster.gold << " G." << endl;
                player.gold += monster.gold;
            }else cout << "You have been defeated!"         << endl;
        }
    }while(player.IsAlive());
}