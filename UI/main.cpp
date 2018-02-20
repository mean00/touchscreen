
#include <stdlib.h>
#include <stdio.h>
#include "Ucglib.h"

static void drawBatteryBars(Ucglib *ucg,int battery_pos_x, int battery_pos_y, int nbBar);
static void draw(Ucglib *ucg);

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

extern "C"
{
int ucg_sdl_get_key(void);
}
void Ucglib::init()
{
    
}
class  UcglibSdl : public Ucglib
{
  public:
    UcglibSdl()
    { 
        ucg_Init( &ucg,&ucg_sdl_dev_cb, ucg_ext_none, (ucg_com_fnptr)0);
    }

    void begin(uint8_t is_transparent)
    {
        
    }
};


//extern const ucg_fntpgm_uint8_t ucg_font_ncenB18[] UCG_FONT_SECTION("ucg_font_ncenB18");
//extern const u8g_fntpgm_uint8_t u8g_font_ncenB18[] U8G_FONT_SECTION("u8g_font_ncenB18");

ucg_t ucg;



int main(void)
{
  UcglibSdl ucg;

  ucg.setFont(ucg_font_ncenB18_tf);
  ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
  //ucg.setPrintPos(42, 40);

  
  draw(&ucg);
    while( ucg_sdl_get_key() < 0 )
    ;
    
  
  return 0;
}

void _drawBattery(Ucglib *ucg, int nbBar)
{
  int battery_width = 84;
  int battery_height = 48;
  int battery_tit_width = 8;
  int battery_tit_height = 19;
  int battery_pos_x = ucg->getWidth() / 2 - (battery_width + battery_tit_width) / 2;
  int battery_pos_y = 30;
  int battery_bar_width = 12;
  int battery_bar_height = 36;
  int battery_space_bar = 3;

  ucg->drawRFrame(battery_pos_x, battery_pos_y, battery_width, battery_height, 4); // main shape
  ucg->drawFrame(battery_pos_x + 1, battery_pos_y + 1, battery_width - 2, battery_height - 2);
  ucg->drawFrame(battery_pos_x + 2, battery_pos_y + 2, battery_width - 4, battery_height - 4);
  ucg->drawRBox(battery_pos_x + battery_width - 1, battery_pos_y + battery_height / 2 - battery_tit_height / 2,
                battery_tit_width + 1, battery_tit_height, 2); // tit

  for (int i = 0; i < nbBar; i++)
  {
    ucg->drawBox(battery_pos_x + 3 + battery_space_bar + battery_space_bar * i + battery_bar_width * i, battery_pos_y + battery_space_bar + 3,
                 battery_bar_width, battery_bar_height);
  }
}

void drawBattery(Ucglib *ucg, int battery_level)
{
  if (battery_level > 92)
  {
    ucg->setColor(0, 0, 199, 20);
    _drawBattery(ucg, 5);
  }
  else if (battery_level > 72)
  {
    ucg->setColor(0, 139, 196, 65);
    _drawBattery(ucg, 4);
  }
  else if (battery_level > 52)
  {
    ucg->setColor(0, 248, 172, 65);
    _drawBattery(ucg, 3);
  }
  else if (battery_level > 32)
  {
    ucg->setColor(0, 237, 91, 39);
    _drawBattery(ucg, 2);
  }
  else
  {
    ucg->setColor(0, 233, 29, 33);
    _drawBattery(ucg, 1);
  }
}

//---
void draw(Ucglib *ucg)
{

  drawBattery(ucg, 42);

  ucg->setColor(0, 255, 255, 255); // withe color for the text

  ucg->drawString(10, 130, 0, "Free 13.37 GB");
  ucg->drawString(10, 190, 0, "Mon Jan 02 15:04");


}

