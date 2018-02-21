
/**
 */

#include "myLcd.h"
#include "screen.h"
#include "touchyDebug.h"
#include "screenManager.h"
#define TYPE_SD 1
#define TYPE_USB 2

/**
 */

#define button_width  100
#define button_height  32


class queryScreen : public Screen
{
public:
        queryScreen()
        {
        }
        virtual void draw(Ucglib *ucg);
        virtual bool touched(Ucglib *ucg,int x, int y);    
};
/**
 */
void drawSdCard(Ucglib *ucg, int x, int y, int w)
{
  int sd_height = w*1.3;
  int sd_bar_width = w/8;
  int sd_bar_height = w/4.1;
  int sd_bar_space = w/17.6;
  if(0 == sd_bar_space){
    sd_bar_space = 1;
  }
  int sd_triangle = w/3.3;
  int sd_round = sd_bar_space;

  // main shape
  ucg->setColor(0, 94, 122, 231);
  ucg->drawRBox(x, y, w, sd_height, sd_round);
  ucg->setColor(0, 0, 0, 0);
  ucg->drawTriangle(x, y, x + sd_triangle, y, x, y + sd_triangle);

  // connectors
  ucg->setColor(0, 255, 255, 255);
  ucg->drawBox(x + sd_triangle - sd_bar_space - sd_bar_width, y + sd_triangle / 2 + (sd_bar_space * 2), sd_bar_width, sd_bar_height);
  for (int i = 0; i < 4; i++)
  {
    ucg->drawBox(x + sd_triangle + i * (sd_bar_space + sd_bar_width), y + (sd_bar_space * 2), sd_bar_width, sd_bar_height);
  }
}
/**
 */
void drawButton(Ucglib *ucg, int x, int y, int type)
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
        int sd_width = 40;
        drawSdCard(ucg, ucg->getWidth() / 2 - sd_width / 2, 20, sd_width);
      }
      break;
    case TYPE_USB:
      {
        // TODO Make a icon...
        ucg->setColor(0, 94, 122, 231);
        ucg->drawString(30, 20, 0, "USB");
      }
      break;
  }

  ucg->setColor(0, 255, 255, 255);

  // TODO Center text!!!
  ucg->drawString(60, 132, 0, "Copy SD card ?");
  drawButton(ucg, 30 , ucg->getHeight() - 50, 2);
  drawButton(ucg, ucg->getWidth()-30-100, ucg->getHeight() - 50, 1); 
}

/**
 */
void queryScreen::draw(Ucglib *ucg)
{
    LOG("DRAWING query");
    drawAskIngest(ucg,TYPE_SD); 
   
 
}

bool buttonMatch(int x, int bx)
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
    if((y>ucg->getHeight() - 50) && (y<ucg->getHeight() - 50 +button_height))
    {
        if(buttonMatch(x,30))
        {
            LOG("LEFT CLICK");
            parent->sendEvent("0");
            return true;
        }
        if(buttonMatch(x,240 - 50))
        {
            LOG("LEFT RIGHT");
            parent->sendEvent("1");
            return true;
        }
    }     
    return false;
}


Screen *querySpawner(const char **args)
{
    return new queryScreen;
}

//EOF
