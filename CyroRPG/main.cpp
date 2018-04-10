#include <iostream>
#include "./inc/Character.h"
#include "./inc/InTown.h"
#include "./inc/OutTown.h"
#include "./inc/Misc.h"

using namespace std;

void PrintTitle()
{
    cout << "CyroRPG - The Legend" << endl;
}

void PrintLegend()
{
    cout << "'All we knew was that we needed to survive ... in this cruel wretched world inhabited by monsters.' \n" << endl 
         << "We created fortresses, armies, weaponries."                                                          << endl
         << "We learnt foresting, arcane magic, war tactics."                                                     << endl
         << "We killed flocks of cursed pterodactyls, almighty dragons, warlocks of the undead. \n"               << endl
         << "We are Cyrions! \n"                                                                                  << endl
         << "\"Well that's what they said in the legends\", he thought as he awaited his graduation " 
         << "ceremony into adulthood, where he will be blessed with power."                                       << endl;
}

int main(){
    Character player;
    int opt;
    string name;
    
    PrintTitle();
    PrintLine();

    cout << "Do you want to load previous save data? " << endl
         << "Option : "                                 << endl
         << "1. Yes"                                    << endl
         << "2. No"                                     << endl
         << "Opt : ";
    cin >> opt;
    if (opt == 1)
    {
        LoadData(player);
    }
    else if (opt == 2)
    {
        PrintLine();
        PrintLegend();
        PrintLine();

        cout << "\"Can I have your name, child?\", said a man in religious atire." << endl
            << "Name: ";
        cin  >> name;
        PrintLine();

        cout << "\"Hear me Young " << name << "! "
            << "For you are not young anymore! You are now qualified to be one of us, a Cyrion!\", the man announced.\n" << endl
            << "Drums started to roar .. louder and LouDer!\n"                                                           << endl
            << "\"Now tell me, do you wish to protect your kind with almighty strength? Perhaps, you wish to learn the "
            << "forbidden arts of magic? Or do you plan to wreck havoc in our foes with your unmatchable movements? The choice "
            << "is yours child. \", commanded the robed man. "                                                           << endl;
        
        cout << "Options : "            << endl
            << "1. Warrior"            << endl
            << "2. Mage"               << endl
            << "3. Archer"             << endl
            << "Opt : ";
        cin >> opt;
        if (opt < 1 || opt > 3) CleanExit("Invalid Option");

        player.SetName(name);
        player.SetClass(opt);
        player.Fullheal();
        player.gold = 10;
        
        PrintLine();

        cout << "\"Very well! I, Helios the Sage, proclaim you as a " << player.GetClassName() << ". May you fulfill your purpose "
            << "well and serve our people.\", chanted Helios. \n"
            << endl;

        cout << "Power started to swell within me. Pushing me past the barriers of 'normal' into a Cyrion. " << endl
            << "\"This power .. is this why we were the Kings of Cyro?\", pondered " << name << "."         << endl
            << "\"But, why are we in poverty? Why are we DYYING?!!\", questioned " << name << " angrily."   << endl;

        cout << "\"Calm down. Isn't this what I'm fighting for? I will resurrect my clan and find out why. "
            << "Why and How we fell from Kings to Outcasts!\", " << name << " declared."                                               
            << endl;
    }
    else
    {
        CleanExit("Invalid Option");
    }

    while(true)
    {
        InTown(player);
        OutTown(player);
    }
    
    return 0;
}