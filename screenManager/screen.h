
/**
 */
#pragma once
class Ucglib;
/**
 */
class Screen
{
public:
                      Screen() {};
        virtual      ~Screen() {};
        virtual void draw(Ucglib *ucg)=0;
        virtual bool touched(int x, int y)=0;    
};
// EOF