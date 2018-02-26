
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


#define ray0 45
#define ray  50
#define ray2 80
#define ray3 85

class ingestingScreen : public Screen
{
public:
        ingestingScreen(int p)
        {
            _percent=p;   
            for(int i=0;i<80;i++) 
                t90[i]=0xffff;
            t90[ray2]=0;
        }
        
        void quadrant1(Ucglib *ucg);
        void quadrant1Full(Ucglib *ucg);
        void quadrant2(Ucglib *ucg);
        void quadrant2Full(Ucglib *ucg);
        void quadrant3(Ucglib *ucg);
        void quadrant4(Ucglib *ucg);
        
        void         drawAll(Ucglib *ucg);
        virtual void draw(Ucglib *ucg);
                void drawx(Ucglib *ucg);
        virtual void redraw(Ucglib *ucg,const char **arg);
        virtual bool touched(Ucglib *ucg,int x, int y);
        int _percent;
        int _oldPercent;
        
        uint16_t t90[ray2+1];
};

#include "ingestingScreen_draw.h"



/**
 */
void ingestingScreen::drawx(Ucglib *ucg)
{       

    ucg->setColor(0, 255, 255, 255);
    if(_oldPercent<25)
    {
        quadrant1(ucg);
    }
    if(_oldPercent<50)
    {
        // 2nd quadrant if > 25%        
        if(_percent>=25)
        {
            quadrant2(ucg);
        }
    }
     // 3nd quadrant if > 50%    
    if(_oldPercent<75)
    {
        if(_percent>=50)
        {
            quadrant3(ucg);
        }
    }
    // 4th quadrant
    if(_percent>=75)
    {
        quadrant4(ucg);
    }
        

 next:
    char str[10];
    sprintf(str,"%02d %%",_percent);
    ucg->getTft()->setTextColor(0xffff,0);
    ucg->drawString(140,128,0,str);

}
/**
 */
void ingestingScreen::drawAll(Ucglib *ucg)
{       
    if(_percent>=25)
        quadrant1Full(ucg);
    else
        quadrant1(ucg);
    if(_percent>=50)
        quadrant2Full(ucg);
    else
        quadrant2(ucg);
    quadrant3(ucg);
    quadrant4(ucg);    
    
    ucg->setColor(0, 0, 0, 0);
    ucg->drawBox(140,128,5*12,12);
    ucg->setColor(0, 255, 255, 255);
    
    char str[10];
    
    sprintf(str,"%02d %%",_percent);
    ucg->drawString(140,128,0,str);
}

/**
 */
void ingestingScreen::redraw(Ucglib *ucg,const char **arg)
{    
    LOG("REDRAWING ingesting");
    ucg->setColor(0, 255, 255, 255);
    _oldPercent=_percent;
    _percent=atoi(arg[0]);
    char st[10];
    sprintf(st,"p:%d",_percent);
    LOGex(st);
    drawAll(ucg);
}


/**
 */
void ingestingScreen::draw(Ucglib *ucg)
{
    LOG("DRAWING ingesting");    
    _oldPercent=0;
    ucg->setColor(0, 255, 255, 255);
    ucg->drawCircle(160,120,ray0,UCG_DRAW_ALL);
    ucg->drawCircle(160,120,ray3,UCG_DRAW_ALL);
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
