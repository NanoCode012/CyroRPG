#include <iostream>
#include "./Characters.h"
#include "./InTown.h"
#include "./OutTown.h"
#include "./Misc.h"

using namespace std;

void PrintTitle()
{
    cout << "CyroRPG - The Legend" << endl;
}

void PrintLegend()
{
    cout << "'All we know is that we need to survive ... in this cruel wretched world inhabited by monsters.' \n" << endl 
         << "We created fortresses, armies, weaponries."                                                          << endl
         << "We learnt foresting, arcane magic, war tactics."                                                     << endl
         << "We killed flocks of cursed pterodactyls, almighty dragons, warlocks of the undead. \n"               << endl
         << "We are Cyrions! \n"                                                                                  << endl
         << "\"Well that's what they said in the legends\", he thought as he awaited his graduation " 
         << "ceremony into adulthood, where he will be blessed with power."                                       << endl;
}

int main(){
    PrintTitle();
    PrintLine();
    PrintLegend();
    PrintLine();

    string name;
    cout << "\"Can I have your name, child?\", said a man in religious atire." << endl
         << "Name: ";
    cin  >> name;
    PrintLine();

    cout << "\"Hear me Young " << name << "! "
         << "For you are not young anymore! You are now qualified to be one of us, a Cyrion!\", the man announced.\n" << endl
         << "Drums started to roar .. louder and LouDer!\n"                                                           << endl
         << "\"Now tell me, do you wish to protect your kind with almighty strength? Perphaps, you wish to learn the "
         << "forbidden arts of magic? Or do you plan to wreck havoc in our foes with your unmatchable movements? The choice "
         << "is yours child. \", commanded the robed man. "                                                           << endl;
    
    int opt;
    cout << "Options : "            << endl
         << "1. Warrior"            << endl
         << "2. Mage"               << endl
         << "3. Archer"             << endl
         << "Opt : ";
    cin >> opt;
    if (opt < 1 || opt > 3) exit(1);

    Character player;
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

    while(true)
    {
        InTown(player);
        OutTown(player);
    }
    
    return 0;
}