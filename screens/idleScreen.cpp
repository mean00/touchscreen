
/**
 */

#include "myLcd.h"
#include "screen.h"
#include "touchyDebug.h"
#include "0bat.h"
#include "1bat.h"  
#include "2bat.h"
#include "3bat.h"
#include "screenUtil.h"
/**
 */

class dummyScreen : public Screen
{
public:
        dummyScreen(int bat,int freespace,char *txt)
        {
            _bat=bat;            
            _free=freespace;
            _txt=strdup(txt);
        }
        ~dummyScreen()
        {
            free(_txt);
        }
        virtual void draw(Ucglib *ucg);
        void        drawBattery(Ucglib *ucg);
        virtual void redraw(Ucglib *ucg,const char **arg);
        virtual bool touched(Ucglib *ucg,int x, int y);    
        int          _bat,_free;
        char        *_txt;
};
/**
 */

static int bat2bar(int bat)
{
    if(bat>90) return 3;
    if(bat>55) return 2;
    if(bat>20) return 1;
    return 0;
}

int mkColor(int r,int g, int b)
{
    r=((0x1f*r)>>8);
    g=((0x1f*r)>>8);
    b=((0x1f*r)>>8);
    return (r<<11)+(g<<5)+b;
}

/**
 */
void dummyScreen::drawBattery(Ucglib *ucg)
{
    const char *bitmap;
    int fgcolor;
    switch(_bat)
    {
        default: 
        case 3:            bitmap=bat0; fgcolor=mkColor(233,29,33);break;
        case 2:            bitmap=bat1; fgcolor=mkColor(233,29,33);break;
        case 1:            bitmap=bat2; fgcolor=mkColor(233,29,33);break;
        case 0:            bitmap=bat3; fgcolor=mkColor(233,29,33);break;
        
    }    
    drawBitmap(ucg,80,10,(const uint8_t *)bitmap,160,106,fgcolor,0);    
 
}
/**
 */
static void centeredPrint(Ucglib *ucg,char *str,int line)
{
    int w=ucg->getStrWidth(str);
    w=(ucg->getWidth()-w)/2;
    if(w<0) w=0;
    ucg->drawString(w, line, 0, str);
}
/**
 */
void dummyScreen::draw(Ucglib *ucg)
{
    redraw(ucg,NULL);
}
void dummyScreen::redraw(Ucglib *ucg,const char **arg)
{

 LOG("DRAWING idle");
 int redraw=false;
 int oldbat=_bat;
 if(arg)
 {
     free(_txt);
     _txt=strdup(arg[2]);
     _bat=bat2bar(atoi(arg[0]));
     _free=atoi(arg[1]);
    if(_bat != oldbat)
        drawBattery(ucg);
 }else
 {
    drawBattery(ucg);
 }
  /* 
   * Battery
   */
  

  ucg->setColor(0, 255, 255, 255); // withe color for the text

  char str[50];
  const char *unit="GB";
  int sz=_free;
  if(sz>1000)
  {
      sz=_free/100;
      int sz2=sz/10;
      sz=sz-sz2*10;
      sprintf(str,"  Free : %d.%d TB  ",sz2,sz);
  }else
  {
      sprintf(str,"  Free : %d GB  ",sz);
  }
  ucg->getTft()-> fillRect(0,120,320,130,0);
  ucg->setColor(0, 255, 255, 255); // withe color for the text
  centeredPrint(ucg,str,150);
  centeredPrint(ucg,_txt,210);
 
}

/**
 */
bool dummyScreen::touched(Ucglib *ucg,int x, int y)
{
    return false;
}


Screen *dummySpawner(const char **args)
{
    int bat=bat2bar(atoi(args[0]));
    int fre=atoi(args[1]);
    char *txt=(char *)args[2];
    return new dummyScreen(bat,fre,txt);
}

//EOF