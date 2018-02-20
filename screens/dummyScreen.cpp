
/**
 */
#include "Ucglib.h"
#include "screen.h"




class dummyScreen : public Screen
{
public:
        virtual void draw(Ucglib *ucg);
        virtual bool touched(int x, int y);    
};

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

  int battery_level = 42;
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

  ucg->drawString(10, 130, 0, "Free 13.37 GB");
  ucg->drawString(10, 190, 0, "Mon Jan 02 15:04");
 
}


/**
 */
bool dummyScreen::touched(int x, int y)
{
    return false;
}


Screen *dummySpawner(char **args)
{
    return new dummyScreen;
}

//EOF