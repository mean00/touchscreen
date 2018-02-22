
#include <stdlib.h>
#include <stdio.h>
#include "Ucglib.h"

static void drawBatteryBars(Ucglib *ucg,int battery_pos_x, int battery_pos_y, int nbBar);
static void draw(Ucglib *ucg);

#define TYPE_SD 1
#define TYPE_USB 2

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

  // main shape
  ucg->drawRFrame(battery_pos_x, battery_pos_y, battery_width, battery_height, 4); 
  ucg->drawFrame(battery_pos_x + 1, battery_pos_y + 1, battery_width - 2, battery_height - 2);
  ucg->drawFrame(battery_pos_x + 2, battery_pos_y + 2, battery_width - 4, battery_height - 4);

  // tit
  ucg->drawRBox(battery_pos_x + battery_width - 1, battery_pos_y + battery_height / 2 - battery_tit_height / 2,
                battery_tit_width + 1, battery_tit_height, 2); 

  // bars
  for (int i = 0; i < 5; i++)
  {
    if (i == nbBar) { // draw black bars to optimize the screen refresh
      ucg->setColor(0, 0, 0, 0);
    }
    ucg->drawBox(battery_pos_x + 3 + battery_space_bar + (battery_space_bar + battery_bar_width) * i , battery_pos_y + battery_space_bar + 3,
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

void drawButton(Ucglib *ucg, int x, int y, int type)
{
  int button_width = 100;
  int button_height = 32;
  int str_y = y + button_height / 2 + 8;

  switch (type)
  {
  // Confirm button
  case 1:
  {
    ucg->setColor(0, 135, 184, 108);
    // TODO Center text!!!
    ucg->drawString(x + 22, str_y, 0, "YES");
  }
  break;

  // Cancel button
  case 2:
  {
    ucg->setColor(0, 204, 95, 85);
    // TODO Center text!!!
    ucg->drawString(x + 22, str_y, 0, "NO");
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
  ucg->drawString(30, 132, 0, "Do you want to copy?");

  drawButton(ucg, 30 , ucg->getHeight() - 50, 2);
  drawButton(ucg, ucg->getWidth()-30-100, ucg->getHeight() - 50, 1);
}



//---
void draw(Ucglib *ucg)
{

    int _percent=30;
    int w=ucg->getWidth();
    int h=ucg->getHeight();
    
    float f=ucg->getWidth()*_percent;
    f/=100;
            
    int centery=(h*1)/3;
    ucg->setColor(0, 255, 255, 255);
    ucg->drawBox(0,centery-15,w-1,30);
    ucg->setColor(0, 0, 255, 0);
    ucg->drawBox(1,centery-14,f-2,28);
    
    char str[50];
    sprintf(str," %d %% done",_percent);
    ucg->setColor(0, 255, 255, 255);
    ucg->drawString(10,f*2,0,str);
    
    
}
