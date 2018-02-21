#include <SPI.h>
#include <Wire.h>
#include <XPT2046_Touchscreen.h>
#include "ili_touch.h"
#include "ili_calibration.h"

/**
 */
iliTouch::iliTouch(int w, int h,int rotation,int XpChipSelect,int irq)
{
    _width=w;
    _height=h;
    _rotation=rotation;
    if(irq)
        xpt=new XPT2046_Touchscreen(XpChipSelect,irq);
    else
        xpt=new XPT2046_Touchscreen(XpChipSelect);
     xpt->begin();
}

/**
 */
bool    iliTouch::press(int &xo,  int &yo)
{
  if(! xpt->touched()) 
  {
    return false;
  }
#if 0
  // See if there's any  touch data for us
  if (xpt->bufferEmpty()) {
    return false;
  } 
#endif

  // Retrieve a point  
  TS_Point p = xpt->getPoint();
  // Rescale
#if 0
      Serial.println("RAW");
      Serial.println(p.x);
      Serial.println(p.y);
#endif
      xo = map(p.x, TOP_LEFT_X, BOTTOM_RIGHT_X, 0, _height );
      yo = map(p.y, TOP_LEFT_Y, BOTTOM_RIGHT_Y, 0, _width);
#if 0
      Serial.println("CAL");
      Serial.println(xo);
      Serial.println(yo);
#endif
  
  return true;

}
