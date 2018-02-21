
#include "myLcd.h"
#include "Adafruit_ILI9341_STM.h"

static int currentColor=0xffff;

Ucglib::Ucglib(Adafruit_ILI9341_STM *tft)
{
    _tft=tft;
}
void Ucglib::clearScreen()
{
    _tft->fillScreen(0);
}
void Ucglib::begin(int fontMode)
{
    _tft->begin();
    _tft->setTextSize(2);

}
void Ucglib::setRotate90()
{
    _tft->setRotation(1);
}
void Ucglib::setFont(void *fnt)
{
    
}
int  Ucglib::getWidth()
{
    return _tft->width ();
}
int  Ucglib::getHeight()
{
    return _tft->height();
}
int  Ucglib::getStrWidth(const char *s)
{
    return strlen(s)*20;
}
void Ucglib::setColor(int ind,int r, int g, int b)
{
    r=r>>3; // 8bit -> 5 bits
    g>>=2; // 8 bits -> 6 bits
    b>>=3; // 8 bits -> 8 bits
    currentColor=(r<<11)+(g<<5)+b;
}

void Ucglib::drawRFrame(int x, int y, int w, int h, int r)
{
    _tft->drawRoundRect(x,y,w,h,r, currentColor);
}
void Ucglib::drawFrame(int x, int y, int w, int h)
{
    _tft->drawRect(x,y,w,h, currentColor);
}
void Ucglib::drawRBox(int x, int y, int w, int h, int r) 
{
    _tft->fillRect(x,y,w,h, currentColor);

}
void Ucglib::drawBox(int x, int y, int w, int h)
{
    _tft->fillRect(x,y,w,h, currentColor);
}
void Ucglib::drawString(int x, int y, int dir, const char *str) 
{
    _tft->setTextColor(currentColor);
    _tft->setCursor(x,y);
    _tft->println((char *)str);
}
void Ucglib::drawCircle(int x0, int y0, int rad, int option) 
{
    _tft->drawCircle( x0,  y0, rad, currentColor);
}
//