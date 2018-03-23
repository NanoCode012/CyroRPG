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
    player.SetTempStatsEqualToNonTemp();
    for (int i = 0; i < player.amountOfSkills; i++)
    {
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

void ShowBattleOptions()
{
    PrintLine();
    cout << "Your turn .."      << endl;
    cout << "Opt : "            << endl
         << "1. Normal Attack"  << endl
         << "2. Use Skill"      << endl
         << "3. Use Item"       << endl;
}

void CalculatePlayerAttack(Character &player, Monster &monster, int opt)
{
    int rand = GetRandomNumber(100);
    switch(opt)
    {
        case 1:
            if (rand >= 100 - player.chanceOfCritical)
            {
                monster.currentHp -= player.CriticalAttack();
            }
            else
            {
                monster.currentHp -= player.NormalAttack();
            }
            break;
    }
}

void CalculateMonsterAttack(Monster &monster, Character &player, int opt)
{
    int rand = GetRandomNumber(100);
    float damage;
    //Type of attack
    if (rand >= 100 - (monster.tempChanceOfSpecialAttack * 100)) 
    {
        cout << "Enemy used Special Attack" << endl;
        damage = monster.SpecialAttack();
    }
    else if (rand >= 100 - (monster.tempChanceOfSpecialAttack*100) - (monster.tempChanceOfCritical*100)) 
    {
        cout << "Enemy does Critical Attack" << endl;
        damage = monster.CriticalAttack();
    }
    else 
    {
        cout << "Enemy does Normal Attack" << endl;
        damage = monster.NormalAttack();
    }

    //Half of defense is how much damage is removed
    if ((player.defense / 2) >= damage)
    {
        cout << "Your defense negated the enemy's attack" << endl;
    }
    else 
    {
        damage -= player.defense / 2;
        
        //Player evasion/damage reduct
        rand = GetRandomNumber(100);
        if (rand > (player.chanceOfEvasion * 100))
        {
            rand = GetRandomNumber(100);
            if (rand > (player.chanceOfDamageReduction * 100))
            {
                cout << "You take " << damage << " damage" << endl;
                player.currentHp -= damage;
            }
            else
            {
                if (damage > player.damageReduction)
                {
                    cout << "You took reduced damage" << endl;
                    player.currentHp -= damage - player.damageReduction;
                }
                else
                {
                    cout << "You negated the enemy's attack with your damage reduction" << endl;
                }
            }

        }
        else
        {
            cout << "You evaded the enemy's attack" << endl;
        }
    }

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
                ShowBattleOptions();
                cin >> opt;
                CalculatePlayerAttack(player, monster, opt);
                ShowEnemyStats(monster);
                if (!monster.IsAlive()) break;

                cout << "Monster is attacking  .." << endl;
                CalculateMonsterAttack(monster, player, opt);
                ShowPlayerStats(player);
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