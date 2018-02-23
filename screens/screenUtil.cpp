
/**
 */
#include "myLcd.h"

#include "screen.h"
#include "touchyDebug.h"
#include "stx_logo.h"
/**
 */
#include "Adafruit_ILI9341_STM.h"


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