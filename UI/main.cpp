
#include <stdlib.h>
#include <stdio.h>
#include "Ucglib.h"

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
  ucg.setFontMode( UCG_FONT_MODE_SOLID);
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
  ucg.drawPixel( 64, 32);

  //ucg.drawHLine( 0,64,20);
  

  while( ucg_sdl_get_key() < 0 )
    ;
    
  
  return 0;
}

