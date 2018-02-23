
/**
 */

#include "myLcd.h"
#include "screen.h"
#include "touchyDebug.h"
#include "screenManager.h"


static const int square[]={
    0,1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,
256,289,324,361,400,441,484,529,576,625,676,729,784,841,900,961,
1024,1089,1156,1225,1296,1369,1444,1521,1600,1681,1764,1849,1936,2025,2116,2209,
2304,2401,2500,2601,2704,2809,2916,3025,3136,3249,3364,3481,3600,3721,3844,3969,
4096,4225,4356,4489,4624,4761,4900,5041,5184,5329,5476,5625,5776,5929,6084,6241,
6400,6561,6724,6889,7056,7225,7396,7569,7744,7921,8100,8281,8464,8649,8836,9025,
9216,9409,9604,9801,10000,10201,10404,10609,10816,11025,11236,11449,11664,11881,12100,12321,
12544,12769,12996,13225,13456,13689,13924,14161,14400,14641,14884,15129,15376,15625,15876,16129,
16384,16641,16900,17161,17424,17689,17956,18225,18496,18769,19044,19321,19600,19881,20164,20449,
20736,21025,21316,21609,21904,22201,22500,22801,23104,23409,23716,24025,24336,24649,24964,25281,
25600,25921,26244,26569,26896,27225,27556,27889,28224,28561,28900,29241,29584,29929,30276,30625,
30976,31329,31684,32041,32400,32761,33124,33489,33856,34225,34596,34969,35344,35721,36100,36481,
36864,37249,37636,38025,38416,38809,39204,39601,40000,40401,40804,41209,41616,42025,42436,42849,
43264,43681,44100,44521,44944,45369,45796,46225,46656,47089,47524,47961,48400,48841,49284,49729,
50176,50625,51076,51529,51984,52441,52900,53361,53824,54289,54756,55225,55696,56169,56644,57121,
57600,58081,58564,59049,59536,60025,60516,61009,61504,62001,62500,63001,63504,64009,64516,65025,
65536,66049,66564,67081,67600,68121,68644,69169,69696,70225,70756,71289,71824,72361,72900,73441,
73984,74529,75076,75625,76176,76729,77284,77841,78400,78961,79524,80089,80656,81225,81796,82369,
82944,83521,84100,84681,85264,85849,86436,87025,87616,88209,88804,89401,90000,90601,91204,91809,
92416,93025,93636,94249,94864,95481,96100,96721,97344,97969,98596,99225,99856,100489,101124,101761
};

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


#define COMPUTE_AND_DRAW() \
{\
   float result=0; \
        if(y)\
        { \
            result = (int)(50.*atan2(y,x)/M_PI); \
            if(result<-50) result=-50; \
            if(result>50) result=50; \
            result+=25; \
            if(result<0) result=result+100; \
        } \
        else\
        {\
\
            if(x>0) result=25;\
                else \
                    result=75;\
        } \
        if(result > _percent) continue; \
 \
        ucg->drawPixel(160+x,120+y); \
        }


#define PRECHECK() \
        int rx,ry; \
        if(x<0) rx=-x; else rx=x; \
        if(y<0) ry=-y; else ry=y; \
   \
        if(rx>ray2) continue;\
        if(ry>ray2) continue;\
        if((rx+ry)<ray) continue;\
        int r=square[rx]+square[ry]; \
\
        if(r>ray2*ray2) continue; \
        if(r<ray*ray) continue; 

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
    
    ucg->setColor(0, 255, 255, 255);
    ucg->drawCircle(160,120,ray0,UCG_DRAW_ALL);
    ucg->drawCircle(160,120,ray3,UCG_DRAW_ALL);

    // 4 quadrant, 0--25, 25--50, 50--75 and 75--100
    // 1st quadrant
    {
    for(int y=-ray2;y<0;y++)
    for(int x=0;x<ray2;x++)
    {
        PRECHECK()
        if(_percent>=25 && y<=0 && x>=0)
        {
            ucg->drawPixel(x+160,y+120);
            continue;
        }
        COMPUTE_AND_DRAW()
    }
    }
    // 2nd quadrant if > 25%    
    if(_percent>=25)
    {
    for(int y=-0;y<ray2;y++)
    for(int x=0;x<ray2;x++)
    {
        PRECHECK();
        if(_percent>=50 && y>=0 && x>=0)
        {
            ucg->drawPixel(x+160,y+120);
            continue;
        }
        COMPUTE_AND_DRAW()
    }
    }
     // 3nd quadrant if > 50%    
    if(_percent>=50)
    {
    for(int y=0;y<ray2;y++)
    for(int x=-ray2;x<0;x++)
    {
        PRECHECK();
        if(_percent>=75 && y>=0 && x<=0)
        {
            ucg->drawPixel(x+160,y+120);
            continue;
        }
        COMPUTE_AND_DRAW()
    }
    }
    // 4th quadrant
    if(_percent>=75)
    {
    for(int y=-ray2;y<0;y++)
    for(int x=-ray2;x<0;x++)
    {
        PRECHECK();
        if(_percent>=75 && y>=0 && x<=0)
        {
            ucg->drawPixel(x+160,y+120);
            continue;
        }
        COMPUTE_AND_DRAW()
    }
    }
        

 next:
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
