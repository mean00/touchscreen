

#include "serialIo.h"

bool inited=false;
static char incoming[256];
static int  dex;
static bool gotString;
/**
 */
void arduinoSerial::run()
{
    if(!inited)
    {
        inited=true;
        dex=0;
        gotString=false;

    }
    if(gotString)
        return; 
    int n=Serial.available();
    while(n-- && !gotString)
    {
        int c=Serial.read();
        
        if(c=='\n' || c=='\r')
        {
            incoming[dex++]=0;
            gotString=true;
        }else
            incoming[dex++]=c;
        if(dex>200)
        {
            incoming[dex++]=0;
            gotString=true;
        }
    }    
}
/**
 */
bool arduinoSerial::hasString(char **str)
{
    if(!gotString) return false;
    *str=(char *)incoming;
    gotString=false;
    dex=0;
    return true;
}
/**
 */
bool arduinoSerial::sendString(char *str)
{
    Serial.println(str);
    return true;
}

// EOF
    
