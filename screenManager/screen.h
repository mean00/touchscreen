
/**
 */
#pragma once
#include "myLcd.h"
class Ucglib;
class ScreenManager;
/**
 */
class Screen
{
public:
        
                      Screen() {};
        virtual      ~Screen() {};
        virtual void draw(Ucglib *ucg)=0;
        virtual bool touched(int x, int y)=0;    
        void         setParent(ScreenManager *p)
        {
            parent=p;
        }
protected:
        ScreenManager *parent;
};
// EOF