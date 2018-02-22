
/**
 */

#include "myLcd.h"
#include "screen.h"
#include "touchyDebug.h"
#include "screenManager.h"

/**
 */

#define button_width  100
#define button_height  32


class ingestingScreen : public Screen
{
public:
        ingestingScreen(int p)
        {
            _percent=p;
        }
        virtual void draw(Ucglib *ucg);
        virtual bool touched(Ucglib *ucg,int x, int y);
        int _percent;
};

/**
 */
void ingestingScreen::draw(Ucglib *ucg)
{
    LOG("DRAWING query");
    int w=ucg->getWidth();
    int h=ucg->getHeight();
    
    float f=ucg->getWidth()*_percent;
    f/=100;
    
    int third=(int)f;
    
            
    int centery=(h*1)/3;
    ucg->setColor(0, 255, 255, 255);
    ucg->drawBox(0,centery-15,w-1,30);
    ucg->setColor(0, 0, 255, 0);
    ucg->drawBox(1,centery-14,third-2,28);
    
    char str[50];
    sprintf(str," %d %% done",_percent);
    ucg->setColor(0, 255, 255, 255);
    ucg->drawString(10,centery*2,0,str);
   
 
}


/**
 */
bool ingestingScreen::touched(Ucglib *ucg,int x, int y)
{
  
    return false;
}


Screen *ingestingSpawner(const char **args)
{
    int percent=atoi(args[0]);
    return new ingestingScreen(percent);
}

//EOF
