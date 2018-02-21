
/**
 */
#include "myLcd.h"

#include "screen.h"
#include "touchyDebug.h"

/**
 */

class bootScreen : public Screen
{
public:
        bootScreen()
        {
        }
        virtual void draw(Ucglib *ucg);
        virtual bool touched(Ucglib *ucg,int x, int y);    

};
void drawSmallCircle(Ucglib *ucg,bool isTrue, int x, int y)
{
    if(isTrue)
    {
        ucg->setColor(0, 0, 255, 0); // withe color for the text
        ucg->drawCircle(x,y,20,UCG_DRAW_ALL);
        ucg->setColor(0, 0, 0, 0); // withe color for the text
        ucg->drawCircle(x,y,10,UCG_DRAW_ALL);

    }else
    {
        ucg->setColor(0, 0, 0, 0); // withe color for the text
        ucg->drawCircle(x,y,20,UCG_DRAW_ALL);
        ucg->setColor(0, 0, 255, 0); // withe color for the text
        ucg->drawCircle(x,y,10,UCG_DRAW_ALL);
    }
}

/**
 */
void bootScreen::draw(Ucglib *ucg)
{
int center=160;
int step=60;
int middle=120;
int rad1=10;
int rad2=20;
int r;
static int index=0;

    LOG("DRAWING BOOT");
    drawSmallCircle(ucg,index==0,center-step,middle);
    drawSmallCircle(ucg,index==1,center,middle);
    drawSmallCircle(ucg,index==2,center+step,middle);
  index++;
  if(index>2) index=0;
  
 
}


/**
 */
bool bootScreen::touched(Ucglib *ucg,int x, int y)
{
    return false;
}


Screen *bootSpawner(const char **args)
{
    return new bootScreen;
}

//EOF