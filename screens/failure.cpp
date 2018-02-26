
/**
 */

#include "myLcd.h"
#include "screen.h"
#include "touchyDebug.h"
#include "screenManager.h"
#include "screenUtil.h"
#include "failure.h"

/**
 */

#define button_width  100
#define button_height  32

#define button_baseline_y (ucg->getHeight() -84)
#define button_baseline_x (160-60)

class  failureScreen : public Screen
{
public:
         failureScreen()
        {
        }
        virtual void draw(Ucglib *ucg);
        virtual void redraw(Ucglib *ucg,const char **arg);
        virtual bool touched(Ucglib *ucg,int x, int y);    
};
/**
 */
static void drawButton(Ucglib *ucg, int x, int y)
{
  int str_y = y + button_height / 2 + 8;

  ucg->setColor(0, 255, 255, 255);
    // TODO Center text!!!
  ucg->drawString(x + 22+10, str_y, 0, "Done");
  ucg->drawRFrame(x, y, button_width, button_height, 2);
}
/**
 */
void failureScreen::draw(Ucglib *ucg)
{
    LOG("DRAWING failure");

    drawBitmap(ucg,160-80,60, (const uint8_t *)failure,160,60,0,0x1f<<11);
    drawButton(ucg, button_baseline_x ,button_baseline_y);
}
void failureScreen::redraw(Ucglib *ucg,const char **arg)
{
    LOG("DRAWING failure");
}

static bool buttonMatch(int x, int bx)
{
    if(x>=bx && x<=(bx+button_width))
        return true;
    return false;
}


/**
 */
bool failureScreen::touched(Ucglib *ucg,int x, int y)
{
    if((y+2>=button_baseline_y) && (y<=button_height+button_baseline_y-2))
    {
        if(buttonMatch(x,button_baseline_x))
        {
            parent->sendEvent("0");
            return true;
        }
    }     
    return false;
}


Screen *failureSpawner(const char **args)
{
    return new failureScreen;
}

//EOF
