
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
        
        void quadant1(Ucglib *ucg);
        void quadant2(Ucglib *ucg);
        void quadant3(Ucglib *ucg);
        void quadant4(Ucglib *ucg);
        
        virtual void draw(Ucglib *ucg);
        virtual void drawx(Ucglib *ucg);
        virtual void redraw(Ucglib *ucg,const char **arg);
        virtual bool touched(Ucglib *ucg,int x, int y);
        int _percent;
};

#include "ingestingScreen_draw.h"

/**
 */
void ingestingScreen::draw(Ucglib *ucg)
{
    LOG("DRAWING ingesting");
    int w=ucg->getWidth();
    int h=ucg->getHeight();

    
    ucg->setColor(0, 255, 255, 255);
    ucg->drawCircle(160,120,ray0,UCG_DRAW_ALL);
    ucg->drawCircle(160,120,ray3,UCG_DRAW_ALL);
    drawx(ucg);

}


/**
 */
void ingestingScreen::drawx(Ucglib *ucg)
{
   
    ucg->setColor(0, 255, 255, 255);
    quadant1(ucg);
    // 2nd quadrant if > 25%    
    if(_percent>=25)
    {
        quadant2(ucg);
    }
     // 3nd quadrant if > 50%    
    if(_percent>=50)
    {
        quadant3(ucg);
    }
    // 4th quadrant
    if(_percent>=75)
    {
        quadant4(ucg);
    }
        

 next:
    char str[10];
    sprintf(str,"%02d %%",_percent);
    ucg->drawString(140,128,0,str);

}


/**
 */
void ingestingScreen::redraw(Ucglib *ucg,const char **arg)
{
    
    LOG("REDRAWING ingesting");
    _percent=atoi(arg[0]);
    char st[10];
    sprintf(st,"p:%d",_percent);
    LOGex(st);
    ucg->clearScreen();
    drawx(ucg);
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
