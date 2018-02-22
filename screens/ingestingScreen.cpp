
/**
 */

#include "myLcd.h"
#include "screen.h"
#include "touchyDebug.h"
#include "screenManager.h"

/**
 */

#define button_width  100
#define button_height  32


class ingestingScreen : public Screen
{
public:
        ingestingScreen()
        {
        }
        virtual void draw(Ucglib *ucg);
        virtual bool touched(Ucglib *ucg,int x, int y);    
};

/**
 */
void ingestingScreen::draw(Ucglib *ucg)
{
    LOG("DRAWING query");
   
   
 
}


/**
 */
bool ingestingScreen::touched(Ucglib *ucg,int x, int y)
{
  
    return false;
}


Screen *ingestingSpawner(const char **args)
{
    return new ingestingScreen;
}

//EOF
