
#pragma once

#define UCG_FONT_MODE_SOLID 1
#define UCG_DRAW_ALL 1

#define ucg_font_helvB18_hr NULL
class Adafruit_ILI9341_STM;
class Ucglib
{
public:
         Ucglib(Adafruit_ILI9341_STM *tft)   ;
    void clearScreen();
    void begin(int fontMode);
    void setRotate90();
    void setFont(void *fnt);//ucg_font_helvB18_tf
    int  getWidth();
    int  getHeight();
    int  getStrWidth(const char *s);
    void setColor(int ind,int r, int g, int b);
   // void setColor(int ind,int r, int g, int b);
    void drawRFrame(int x, int y, int w, int h, int r);
    void drawFrame(int x, int y, int w, int h) ;
    void drawRBox(int x, int y, int w, int h, int r) ;
    void drawBox(int x, int y, int w, int h);
    void drawString(int x, int y, int dir, const char *str) ;
    void drawCircle(int x0, int y0, int rad, int option) ;
    void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2) ;
    void drawLine(int x0, int y0,int x1,int y1) ;
    //
    void drawPixel(int x0, int y0) ;
    Adafruit_ILI9341_STM *getTft() {return _tft;}
protected:    
    Adafruit_ILI9341_STM *_tft;
    
};