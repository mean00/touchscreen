#pragma once
/**
 * 
 * Simple Wrapper around XPT2046 touch screen circuit
 * It abstracts the internal and offers a much simpler interface
 * 
 */

class iliTouch
{
public:
                    iliTouch(SPIClass &spi,int w,int h,int rotation,int XpChipSelect, int irq=-1);
            bool    press(int &x,  int &y);
private:
            XPT2046_Touchscreen *xpt;
            int                 _width;
            int                 _height;
            int                 _rotation;
  
};
