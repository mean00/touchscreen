
/**
 */

#include "myLcd.h"
#include "screen.h"
#include "touchyDebug.h"
#include "screenManager.h"
#include "sdcard.h"
#include "usb.h"
#include "screenUtil.h"
#define TYPE_SD 1
#define TYPE_USB 2

/**
 */

#define button_width  100
#define button_height  32


class queryScreen : public Screen
{
public:
        queryScreen(int type)
        {
            _type=type;
        }
        virtual void draw(Ucglib *ucg);
        virtual void redraw(Ucglib *ucg,const char **arg);
        virtual bool touched(Ucglib *ucg,int x, int y);    
        int _type;
};
/**
 */
static void drawButton(Ucglib *ucg, int x, int y, int type)
{
  int str_y = y + button_height / 2 + 8;

  switch (type)
  {
  // Confirm button
  case 1:
  {
    ucg->setColor(0, 135, 184, 108);
    // TODO Center text!!!
    ucg->drawString(x + 22+10, str_y, 0, "YES");
  }
  break;

  // Cancel button
  case 2:
  {
    ucg->setColor(0, 204, 95, 85);
    // TODO Center text!!!
    ucg->drawString(x + 22+10, str_y, 0, "NO");
  }
  break;

  default:
  {
    ucg->setColor(0, 0, 0, 0);
    // TODO Center text!!!
    ucg->drawString(x + 22, str_y, 0, "OK");
  }
  }
  // button shape
  ucg->drawRFrame(x, y, button_width, button_height, 2);
}
/**
 */
void drawAskIngest(Ucglib *ucg, int type)
{ 
  switch(type){
    case TYPE_SD:
      {
            drawBitmap(ucg,160-80,0, (const uint8_t *)sdcard_logo,160,160,0,0xffff);
            ucg->setColor(0, 255, 255, 255);
            ucg->drawString(80, 160, 0, "Copy SD card ?");
  
      }
      break;
    case TYPE_USB:
      {
            drawBitmap(ucg,160-80,0, (const uint8_t *)usb_logo,160,160,0,0xffff);
            ucg->setColor(0, 255, 255, 255);
            ucg->drawString(50, 160, 0, "Copy USB device ?");
  
      }
      break;
  }

  drawButton(ucg, 30 , ucg->getHeight() - 60, 2);
  drawButton(ucg, ucg->getWidth()-30-100, ucg->getHeight() - 60, 1); 
}
void redrawAskIngest(Ucglib *ucg, int type)
{ 
    
}
/**
 */
void queryScreen::draw(Ucglib *ucg)
{
    LOG("DRAWING query");
    drawAskIngest(ucg,_type); 
}
void queryScreen::redraw(Ucglib *ucg,const char **arg)
{
    LOG("DRAWING query");
    redrawAskIngest(ucg,_type); 
}

static bool buttonMatch(int x, int bx)
{
    if(x>=bx && x<=(bx+button_width))
        return true;
    return false;
}


/**
 */
bool queryScreen::touched(Ucglib *ucg,int x, int y)
{
   // LOGex(x);
   // LOGex(y);
    if((y>ucg->getHeight() - 60))
    {
        if(buttonMatch(x,30))
        {
            LOG("LEFT CLICK");
            parent->sendEvent("0");
            return true;
        }
        if(buttonMatch(x,ucg->getWidth()-130))
        {
            LOG("RIGHT RIGHT");
            parent->sendEvent("1");
            return true;
        }
    }     
    return false;
}


Screen *querySpawner(const char **args)
{
    int type=TYPE_USB;
    if(atoi(args[0])==1)
        type=TYPE_SD;
    return new queryScreen(type);
}

//EOF
