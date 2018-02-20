
/**
 */
#include "Ucglib.h"
#include "screen.h"




class dummyScreen : public Screen
{
public:
        virtual void draw(Ucglib *ucg);
        virtual bool touched(int x, int y);    
};
/**
 */
void dummyScreen::draw(Ucglib *ucg)
{

  ucg->setColor( 1, 0, 0, 255);
  ucg->setColor( 0, 255, 180, 40);
  ucg->drawString( 64, 32,0, "AB");
  ucg->setColor( 0, 255, 200, 70);
  ucg->drawString( 64, 32,1, "AB");
  ucg->setColor( 0, 255, 180, 40);
  ucg->drawString( 64, 32,2, "AB");
  ucg->setColor( 0, 255, 200, 70);
  ucg->drawString( 64, 32,3, "AB");

  ucg->setColor( 0, 128, 128, 255);
  ucg->drawPixel( 64, 32);
 
}


/**
 */
bool dummyScreen::touched(int x, int y)
{
    return false;
}


Screen *dummySpawner(char **args)
{
    return new dummyScreen;
}

//EOF