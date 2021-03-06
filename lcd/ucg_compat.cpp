
#include "myLcd.h"
#include "Adafruit_ILI9341_STM.h"

static int currentColor=0xffff;

Ucglib::Ucglib(Adafruit_ILI9341_STM *tft)
{
    _tft=tft;
}
void Ucglib::clearScreen()
{
    _tft->setRotation(0);
    _tft->fillRect(0,0,239,319,0);
    _tft->setRotation(1);
}
void Ucglib::begin(int fontMode)
{
    _tft->begin();//SPI,10000000);
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
    _tft->setCursor(x,y-12);
    _tft->println((char *)str);
}
void Ucglib::drawCircle(int x0, int y0, int rad, int option) 
{
    _tft->drawCircle( x0,  y0, rad, currentColor);
}

void Ucglib::drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2)
{
    _tft->  fillTriangle( x0,  y0,  x1,  y1,       x2,  y2, currentColor);

}
void Ucglib::drawPixel(int x0, int y0) 
{
    _tft->drawPixel(x0,y0,currentColor);
}

void Ucglib::drawLine(int x0, int y0, int x1, int y1) 
{
    _tft->drawLine(x0,y0,x1,y1,currentColor);
}

//