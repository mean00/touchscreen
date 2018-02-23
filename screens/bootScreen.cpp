
/**
 */
#include "myLcd.h"

#include "screen.h"
#include "touchyDebug.h"
#include "stx_logo.h"
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
void drawLogo(Ucglib *ucg,int wx,int wy)
{
    uint8_t *p=(uint8_t *)stx_logo;
    for(int y=0;y<110;y++)
        for(int x=0;x<160>>3;x++)
        {
            int stack=*p++;
                    
            for(int step=0;step<8;step++)
            {
                int color=0;
                if(stack&0x80)
                    color=0xff;
                ucg->setColor(0, color, color, color); // withe color for the text
                ucg->drawPixel(wx+x*8+step,wy+y);
                stack<<=1;
            }
        }
}
/**
 */
void bootScreen::draw(Ucglib *ucg)
{
int center=160;
int step=60;
int middle=180;
int rad1=10;
int rad2=20;
int r;
static int index=0;

    LOG("DRAWING BOOT");
    drawLogo(ucg,160-80,30);
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
