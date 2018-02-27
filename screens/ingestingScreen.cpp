
/**
 */

#include "myLcd.h"
#include "screen.h"
#include "touchyDebug.h"
#include "screenManager.h"
#include "screenUtil.h"

/**
 */
#define base_x 200
#define base_y 200

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
            {
                fullLine[i]=0xffff;
                emptyLine[i]=0;
            }
            emptyLine[ray2]=0;
        }
        
        void quadrant1(Ucglib *ucg);
        void quadrant2(Ucglib *ucg);
        void quadrant3(Ucglib *ucg);
        void quadrant4(Ucglib *ucg);
        
        void         drawAll(Ucglib *ucg);
        virtual void draw(Ucglib *ucg);
                void drawx(Ucglib *ucg);
        virtual void redraw(Ucglib *ucg,const char **arg);
        virtual bool touched(Ucglib *ucg,int x, int y);
        int _percent;
        int _oldPercent;
        
        uint16_t emptyLine[ray2+1];
        uint16_t fullLine[ray2+1];
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
#if 0
    quadrant3(ucg);
    return;
#else
    quadrant1(ucg);
    if(_percent>25)
    {
        quadrant2(ucg);
        if(_percent>50)
        {
            quadrant3(ucg);
            if(_percent>75)
                quadrant4(ucg);    
        }
        
    }
#endif
    ucg->getTft()-> fillRect(140,100,5*10,45,0);
    
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
    drawAll(ucg);
    drawButton(ucg, base_x ,base_y,"Stop");

}

static bool buttonMatch(int x, int bx)
{
    if(x>=bx && x<=(bx+button_width))
        return true;
    return false;
}


/**
 */
bool ingestingScreen::touched(Ucglib *ucg,int x, int y)
{
  
    if((y+2>=base_y) && (y<=button_height+base_y-2))
    {
        if(buttonMatch(x,base_x))
        {
            parent->sendEvent("0");
            return true;
        }
    }     
    return false;
}


Screen *ingestingSpawner(const char **args)
{
    int percent=atoi(args[0]);
    return new ingestingScreen(percent);
}

//EOF
