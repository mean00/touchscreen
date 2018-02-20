
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
/**
 */
class dummyScreen : public Screen
{
public:
        void draw(Ucglib *ucg);
         bool touched(int x, int y){return false;}
};
// EOF