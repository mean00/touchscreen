#include "Arduino.h"
#include "myLcd.h"
#include "screenManager.h"
#include "touchyDebug.h"

ScreenManager:: ScreenManager(Ucglib *theucg)
{
    ucg=theucg;
    currentScreen=NULL;
    currentName=NULL;
}
bool ScreenManager::registerScreen(const char *name, int nbArgs,ScreenSpawner *spawner )
{
    screenEntry *entry=new screenEntry;
    entry->screenName=name;
    entry->spawner=spawner;
    entry->nbArg=nbArgs;
    
    entries.push_back(entry);
}
bool ScreenManager::redraw()
{
    if(currentScreen)
    {
        currentScreen->redraw(ucg,NULL);
    }
    return true;
}
bool ScreenManager::spawnScreen(const char *name, int nb, const char **arg)
{
    int n=entries.size();
    // 

    
    const char *foundName;
    int found=-1;
    for(int i=0;i<n;i++)
        if(!strcmp(entries[i]->screenName,name))
        {
            found=i;
            foundName=entries[i]->screenName;
            break;
        }
    if(found==-1)
    {
        LOG("this screen is unknown");
        return false;
    }
    if(entries[found]->nbArg!=nb)
    {
        LOG("Wrong number of arg");
        return false;
    }
    LOG("found screen");
    
    if(currentScreen && currentName)
    {
        if(!strcmp(currentName,name))
        {
            currentScreen->redraw(ucg,arg);
            LOG("Redraw");
            return true;
        }
    }
    
    if(currentScreen) delete currentScreen;
    currentScreen=NULL;
    currentName=NULL;
    currentScreen=entries[found]->spawner(arg);
    if(!currentScreen)
    {
        LOG("spawning failed");
        return false;
    }
    currentScreen->setParent(this);
    currentName=foundName;
    // Reset screen
    
    
    ucg->clearScreen();
    currentScreen->draw(ucg);
    LOG("spawning ok");
    return true;
}


bool ScreenManager::clicked(int x,int y)
{
    if(!currentScreen)
    {
        //Serial.println("COM;clicked :No current screen ");
        return false;
    }
#if DEBUG   
    ucg->setColor(0,255,255,255);
    ucg->drawBox(x,y,5,5);
#endif
    
    if(currentScreen->touched(ucg,x,y))
    {
#if 1        
        delete currentScreen;
        currentScreen=NULL;
        ucg->clearScreen();        
#endif
    }
    return false;
}


bool ScreenManager::sendEvent(const char *event)
{
    if(!currentScreen)
    {
        LOG("NO SCREEN TO SEND EVENT");
        return false;
    }
    char bfer[100];
    strcpy(bfer,"EVENT;");
    strcat(bfer,currentName);
    strcat(bfer,";");
    strcat(bfer,event);
    Serial.println(bfer);
}