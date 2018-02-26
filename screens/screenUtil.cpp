
/**
 */
#include "myLcd.h"

#include "screen.h"
#include "touchyDebug.h"
#include "stx_logo.h"
/**
 */
#include "screenUtil.h"
#include "Adafruit_ILI9341_STM.h"

/**
 */
void drawButton(Ucglib *ucg, int x, int y, char *text)
{
  int str_y = y + button_height / 2 + 8;

  ucg->setColor(0, 255, 255, 255);
    // TODO Center text!!!
  ucg->drawString(x + 22+10, str_y, 0, text);
  ucg->drawRFrame(x, y, button_width, button_height, 2);
}

// slow mode
#if 0
void drawBitmap(Ucglib *ucg,int wx,int wy, const uint8_t *data, int width, int height, int fgcolor,int bgcolor)
{
    uint8_t *p=(uint8_t *)data;
    Adafruit_ILI9341_STM *tft=ucg->getTft();
    
    for(int y=0;y<height;y++)
    {
        for(int x=0;x<width>>3;x++)
        {
            int stack=*p++;
            for(int step=0;step<8;step++)
            {
                int color=bgcolor;
                if(stack&0x80)
                    color=fgcolor;
                tft->  drawPixel(wx+x*8+step,wy+y,color);                
                stack<<=1;
            }
        }        
    }   
}
#else
// fast mode
// Prepare bitmap and send it line per line
void drawBitmap(Ucglib *ucg,int wx,int wy, const uint8_t *data, int width, int height, int fgcolor,int bgcolor)
{
    uint8_t *p=(uint8_t *)data;
    Adafruit_ILI9341_STM *tft=ucg->getTft();
    static uint16_t line[320];
    
    width>>=3;
    for(int y=0;y<height;y++)
    {
        uint16_t *o=line;
        tft-> setAddrWindow(wx, wy+y, wx+width*8, wy+y);
        for(int x=0;x<width;x++)
        {
            int stack=*p++;
            for(int step=0;step<8;step++)
            {
                int color;
                if(stack&0x80)                                        
                    color=fgcolor;
                else
                    color=bgcolor;
                *o++=color;
                stack<<=1;
            }            
        }    
        tft->pushColors(line,width*8,0);
    }   
}
#endif