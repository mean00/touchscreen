
#include <stdlib.h>
#include <stdio.h>
#include "Ucglib.h"

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

    void drawBatteryBars(int battery_pos_x, int battery_pos_y, int nbBar)
    {
      int battery_bar_width = 12;
      int battery_bar_height = 35;
      int battery_space_bar = 3;

      for (int i = 0; i++; i < nbBar)
      {
        drawBox(battery_pos_x + battery_space_bar * i + battery_bar_width * i, battery_pos_y + battery_space_bar + 4,
                battery_bar_width, battery_bar_height);
      }
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

  /* 
   * Battery
   */
  int battery_width = 88;
  int battery_height = 48;
  int battery_tit_width = 8;
  int battery_tit_height = 19;
  int battery_pos_x = SCREEN_WIDTH/2 - (battery_width + battery_tit_width)/2;
  int battery_pos_y = 30;

  int battery_level = 42;
  //ucg.drawString(10, 70, 0, "Battery 42%");
  if(battery_level > 80) {
    ucg.setColor(0, 0, 199, 20);
    ucg.drawBatteryBars(battery_pos_x, battery_pos_y, 5);
  }
  else if (battery_level > 60) {
    ucg.setColor(0, 139, 196, 65);
    ucg.drawBatteryBars(battery_pos_x, battery_pos_y, 4);
  }
  else if (battery_level > 40 ){
    ucg.setColor(0, 248, 172, 65);
    ucg.drawBatteryBars(battery_pos_x, battery_pos_y, 3);
  }
  else if (battery_level > 20) {
    ucg.setColor(0, 237, 91, 39);
    ucg.drawBatteryBars(battery_pos_x, battery_pos_y, 2);
  }
  else {
    ucg.setColor(0, 233, 29, 33);
    ucg.drawBatteryBars(battery_pos_x, battery_pos_y, 1);
  }
  ucg.drawRFrame(battery_pos_x, battery_pos_y, battery_width, battery_height, 4);     // main shape
  ucg.drawFrame(battery_pos_x+1, battery_pos_y+1, battery_width-2, battery_height-2); 
  ucg.drawFrame(battery_pos_x+2, battery_pos_y+2, battery_width-4, battery_height-4); 
  ucg.drawRBox(battery_pos_x + battery_width - 1, battery_pos_y + battery_height / 2 - battery_tit_height / 2,
    battery_tit_width + 1, battery_tit_height, 2); // tit

  ucg.setColor(0, 255, 255, 255); // withe color for the text

  ucg.drawString(10, 130, 0, "Free 13.37 GB");
  ucg.drawString(10, 190, 0, "Mon Jan 02 15:04");

  /*   ucg.setFontMode( UCG_FONT_MODE_SOLID);
  ucg.setFont( ucg_font_ncenB24_hf);  

  ucg.setColor( 1, 0, 0, 255);
  ucg.setColor( 0, 255, 180, 40);
  ucg.drawString( 64, 32,0, "AB");
  ucg.setColor( 0, 255, 200, 70);
  ucg.drawString( 64, 32,1, "AB");
  ucg.setColor( 0, 255, 180, 40);
  ucg.drawString( 64, 32,2, "AB");
  ucg.setColor( 0, 255, 200, 70);
  ucg.drawString( 64, 32,3, "AB");

  ucg.setColor( 0, 128, 128, 255);
  ucg.drawPixel( 64, 32); */

  //ucg.drawHLine( 0,64,20);
  

  while( ucg_sdl_get_key() < 0 )
    ;
    
  
  return 0;
}

