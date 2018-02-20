#include "Ucglib.h"
#include "screenManager.h"


ScreenManager:: ScreenManager(Ucglib *theucg)
{
    ucg=theucg;
    currentScreen=NULL;
}
bool ScreenManager::registerScreen(const char *name, int nbArgs,ScreenSpawner *spawner )
{
    screenEntry *entry=new screenEntry;
    entry->screenName=name;
    entry->spawner=spawner;
    entry->nbArg=nbArgs;
    
    entries.push_back(entry);
}
bool ScreenManager::spawnScreen(const char *name, int nb, const char **arg)
{
    int n=entries.size();
    int found=-1;
    for(int i=0;i<n;i++)
        if(!strcmp(entries[i]->screenName,name))
        {
            found=i;
            break;
        }
    if(found==-1)
    {
        Serial.println("COM;this screen is unknown");
        return false;
    }
    if(entries[found]->nbArg!=nb)
    {
        Serial.println("COM;Wrong number of arg");
        return false;
    }
    if(currentScreen) delete currentScreen;
    currentScreen=NULL;
    currentScreen=entries[found]->spawner(arg);
    if(!currentScreen)
    {
        Serial.println("COM;spawning failed");
        return false;
    }
    currentScreen->setParent(this);
    currentScreen->draw(ucg);
    return true;
}


bool ScreenManager::clicked(int x,int y)
{
    if(!currentScreen)
    {
        Serial.println("COM;clicked :No current screen ");
         return false;
    }
    if(currentScreen->touched(x,y))
    {
        delete currentScreen;
        currentScreen=NULL;
        ucg->clearScreen();        
    }
    return false;
}


