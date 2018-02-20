
/**
 */
#include "Ucglib.h"
#include "screen.h"


/**
 */

class dummyScreen : public Screen
{
public:
        dummyScreen(int bat,int freespace)
        {
            _bat=bat;
            _free=freespace;
        }
        virtual void draw(Ucglib *ucg);
        virtual bool touched(int x, int y);    
        int          _bat,_free;
};
/**
 */
 static void drawBatteryBars(Ucglib *ucg,int battery_pos_x, int battery_pos_y, int nbBar)
    {
      int battery_bar_width = 12;
      int battery_bar_height = 35;
      int battery_space_bar = 3;

      for (int i = 0; i++; i < nbBar)
      {
        ucg->drawBox(battery_pos_x + battery_space_bar * i + battery_bar_width * i, battery_pos_y + battery_space_bar + 4,
                battery_bar_width, battery_bar_height);
      }
    }
/**
 */
static void centeredPrint(Ucglib *ucg,char *str,int line)
{
    int w=ucg->getStrWidth(str);
    w=(ucg->getWidth()-w)/2;
    if(w<0) w=0;
    ucg->drawString(w, line, 0, str);
}
/**
 */
void dummyScreen::draw(Ucglib *ucg)
{

 
  /* 
   * Battery
   */
  int battery_width = 88;
  int battery_height = 48;
  int battery_tit_width = 8;
  int battery_tit_height = 19;
  int battery_pos_x = ucg->getWidth()/2 - (battery_width + battery_tit_width)/2;
  int battery_pos_y = 30;

  int battery_level = _bat;
  //ucg->drawString(10, 70, 0, "Battery 42%");
  if(battery_level > 80) {
    ucg->setColor(0, 0, 199, 20);
    drawBatteryBars(ucg,battery_pos_x, battery_pos_y, 5);
  }
  else if (battery_level > 60) {
    ucg->setColor(0, 139, 196, 65);
    drawBatteryBars(ucg,battery_pos_x, battery_pos_y, 4);
  }
  else if (battery_level > 40 ){
    ucg->setColor(0, 248, 172, 65);
    drawBatteryBars(ucg,battery_pos_x, battery_pos_y, 3);
  }
  else if (battery_level > 20) {
    ucg->setColor(0, 237, 91, 39);
    drawBatteryBars(ucg,battery_pos_x, battery_pos_y, 2);
  }
  else {
    ucg->setColor(0, 233, 29, 33);
    drawBatteryBars(ucg,battery_pos_x, battery_pos_y, 1);
  }
  ucg->drawRFrame(battery_pos_x, battery_pos_y, battery_width, battery_height, 4);     // main shape
  ucg->drawFrame(battery_pos_x+1, battery_pos_y+1, battery_width-2, battery_height-2); 
  ucg->drawFrame(battery_pos_x+2, battery_pos_y+2, battery_width-4, battery_height-4); 
  ucg->drawRBox(battery_pos_x + battery_width - 1, battery_pos_y + battery_height / 2 - battery_tit_height / 2,
    battery_tit_width + 1, battery_tit_height, 2); // tit

  ucg->setColor(0, 255, 255, 255); // withe color for the text

  char str[50];
  const char *unit="GB";
  int sz=_free;
  if(sz>1000)
  {
      sz=_free/100;
      int sz2=sz/10;
      sz=sz-sz2*10;
      sprintf(str,"Free : %d.%d TB",sz2,sz);
  }else
  {
      sprintf(str,"Free : %d GB",sz);
  }
  ucg->setColor(0,0,0);
  ucg->drawBox(0,130-20, ucg->getWidth(),20);
  ucg->setColor(0xff,0xff,0xff);  
  centeredPrint(ucg,str,130);
  ucg->setColor(0,0,0);
  ucg->drawBox(0,190-20, ucg->getWidth(),20);
  ucg->setColor(0xff,0xff,0xff);  
  centeredPrint(ucg,"Mon Jan 02 15:04",190);

  
 
}


/**
 */
bool dummyScreen::touched(int x, int y)
{
    return false;
}


Screen *dummySpawner(const char **args)
{
    int bat=atoi(args[0]);
    int fre=atoi(args[1]);
    return new dummyScreen(bat,fre);
}

//EOF