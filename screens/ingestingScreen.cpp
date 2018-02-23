
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
        ingestingScreen(int p)
        {
            _percent=p;
        }
        virtual void draw(Ucglib *ucg);
        virtual bool touched(Ucglib *ucg,int x, int y);
        int _percent;
};

/**
 */
void ingestingScreen::draw(Ucglib *ucg)
{
    LOG("DRAWING query");
    int w=ucg->getWidth();
    int h=ucg->getHeight();
       

#define ray0 45
#define ray  50
#define ray2 80
#define ray3 85
    int centerx=160;
    int centery=120;
    ucg->setColor(0, 255, 255, 255);


    ucg->drawCircle(centerx,centery,ray0,UCG_DRAW_ALL);
    ucg->drawCircle(centerx,centery,ray3,UCG_DRAW_ALL);

    for(int y=-ray2;y<ray2;y++)
    for(int x=-ray2;x<ray2;x++)
    {
        int rx=abs(x);
        int ry=abs(y);
   
        // discard obvious not ok
        if(rx>ray2) continue;
        if(ry>ray2) continue;
        if((rx+ry)<ray) continue;
        int r=x*x+y*y;

        if(r>ray2*ray2) continue; 
        if(r<ray*ray) continue; 

        // if we get here, we are within the 2 circles
        
        if(_percent>=25 && y<=0 && x>=0)
        {
            ucg->drawPixel(x+160,y+120);
            continue;
        }
      
        if(_percent>=50 && y>=0 && x>=0)
        {
            ucg->drawPixel(x+160,y+120);
            continue;
        }
        if(_percent>=75 && y>=0 && x<=0)
        {
            ucg->drawPixel(x+160,y+120);
            continue;
        }
        //- skip-
        if(_percent<=75 && y<=0 && x<=0)
        {
            continue;
        }
        if(_percent<=50 && y>=0 && x<=0)
        {
            continue;
        }
        if(_percent<=25 && y>=0 && x>=0)
        {
            continue;
        }

        
        
        
        float result=0;
        if(y)
        {
            result = (int)(180.*atan2(y,x)/M_PI);
            // clip
            if(result<-180) result=-180;
            if(result>180) result=180;
            result+=90;
            if(result<0) result=result+360;
            result=(result*100)/360;
        }
        else
        {

            if(x>0) result=25;
                else 
                    result=75;
        }
        if(result > _percent) continue;

        ucg->drawPixel(160+x,120+y);
    }


    char str[10];
    sprintf(str,"%02d %%",_percent);
    ucg->drawString(140,130,0,str);

}




/**
 */
bool ingestingScreen::touched(Ucglib *ucg,int x, int y)
{
  
    return false;
}


Screen *ingestingSpawner(const char **args)
{
    int percent=atoi(args[0]);
    return new ingestingScreen(percent);
}

//EOF
