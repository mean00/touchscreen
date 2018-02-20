/*

  GraphicsTest.ino
  
  Generate some example graphics

  Universal uC Color Graphics Library
  
  Copyright (c) 2014, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.
    
  * Redistributions in binary form must reproduce the above copyright notice, this 
    list of conditions and the following disclaimer in the documentation and/or other 
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  

*/

#include <SPI.h>
#include "Ucglib.h"
#include <XPT2046_Touchscreen.h>
#include "ili_touch.h"

#include "screenManager.h"
#include "serialIo.h"
#include "touchySerializer.h"

ScreenManager *manager=NULL;
extern Screen *dummySpawner(const char **args);


#define TS_INTERRUPT_PIN PB6
#define TS_CS_PIN        PA3

Ucglib_ILI9341_18x240x320_HWSPI ucg(/*cd=*/ PA2, /*cs=*/ PA0, /*reset=*/ PA1);
iliTouch  *ts=NULL;
void mySetup(void)
{
  SPI.begin();
  SPI.setBitOrder(MSBFIRST); // Set the SPI bit order
  SPI.setDataMode(SPI_MODE0); //Set the  SPI data mode 0
  SPI.setClockDivider (SPI_CLOCK_DIV2);

  Serial.begin();
  Serial.println("Start");
  ucg.begin(UCG_FONT_MODE_SOLID);
  ucg.setRotate90();
  ucg.setFont(ucg_font_helvB18_tf);//ucg_font_helvB18_tf
  ucg.clearScreen();  
  ts=new iliTouch(ucg.getWidth(),ucg.getHeight(),/*ucg.getRotation()*/1,TS_CS_PIN,TS_INTERRUPT_PIN);
  
  // start Screen Manager
  manager=new ScreenManager (&ucg);
  manager->registerScreen("dummy",2,dummySpawner);
  
  char *args[2]={"50","1200"};
  manager->spawnScreen("dummy",2,(const char **)args);
}

void myLoop(void)
{
  int x,y;
  static int count=0;
  static char *input;
  static const char *args[10];
  
  
    if(!ts->press(x,y))
    {        
        manager->clicked(x,y);
    }
    arduinoSerial::run();
    if(arduinoSerial::hasString(&input))
    {
        int nbArgs;
        if(DeSerializer::deserialize((char *)input,nbArgs,(const char **)args))  // char *input,  int &args, const char **arg);    
        {
            if(nbArgs>2)
            {
                if(!strcmp(args[0],"SCR"))
                {
                    manager->spawnScreen(args[1],nbArgs-2,args+2);
                }
            }
        }
    }
    
  
}
