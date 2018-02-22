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
#include <vector>
#include <SPI.h>


#include <XPT2046_Touchscreen.h>
#include "ili_touch.h"

#include "screenManager.h"
#include "serialIo.h"
#include "touchySerializer.h"
#include "myLcd.h"
#include "touchyDebug.h"
#define BOOT_SCREEN


ScreenManager *manager=NULL;
extern Screen *dummySpawner(const char **args);
extern Screen *bootSpawner(const char **args);
extern Screen *querySpawner(const char **args);
extern Screen *ingestingSpawner(const char **args);

#define TS_INTERRUPT_PIN PB6
#define TS_CS_PIN        PA3


#ifdef FAST_LCD
   Adafruit_ILI9341_STM tft = Adafruit_ILI9341_STM(PA0, PA2,PA1);
   Ucglib  ucg(&tft);

#else
    Ucglib_ILI9341_18x240x320_HWSPI ucg(/*cd=*/ PA2, /*cs=*/ PA0, /*reset=*/ PA1);
#endif


iliTouch  *ts=NULL;
/**
 */
void mySetup(void)
{
  SPI.begin();
  SPI.setBitOrder(MSBFIRST); // Set the SPI bit order
  SPI.setDataMode(SPI_MODE0); //Set the  SPI data mode 0
  SPI.setClockDivider (SPI_CLOCK_DIV2);

  Serial.begin();
  Serial.println("Start");
  ucg.begin(UCG_FONT_MODE_SOLID);
  
  ucg.clearScreen();  
  ucg.setFont(ucg_font_helvB18_hr);//ucg_font_helvB18_tf
  ts=new iliTouch(240,320,0,TS_CS_PIN,TS_INTERRUPT_PIN);
  
  // start Screen Manager
  manager=new ScreenManager (&ucg);
  manager->registerScreen("idle",2,dummySpawner);
  manager->registerScreen("boot",0,bootSpawner);
  manager->registerScreen("query",0,querySpawner);
  manager->registerScreen("ingesting",1,ingestingSpawner);
  
#ifndef BOOT_SCREEN  
  char *args[2]={"50","1200"};
  manager->spawnScreen("idle",2,(const char **)args);
  //manager->spawnScreen("query",0,(const char **)args);
#else
   manager->spawnScreen("boot",0,NULL);
#endif
}
/**
 */
static void ProcessInputString(char *input)  
{
  static const char *args[10];
  LOG("Got string");
  LOGex(input);

  int nbArgs;
  if(DeSerializer::deserialize((char *)input,nbArgs,(const char **)args))  // char *input,  int &args, const char **arg);    
  {
      if(nbArgs>=2)
      {
          if(!strcmp(args[0],"SCR"))
          {                   
              LOG("SPWANING");
              manager->spawnScreen(args[1],nbArgs-2,args+2);
          }else
              LOG("Wrong screen name");
      }else
      {
          LOG("Not enough args");
          Serial.println(nbArgs);
      }
  }else
        LOG("Cannot deserialize");
}
  
/**
 */
void myLoop(void)
{
  int x,y;
  static int count=0;
  static char *input;
  
  
#if defined(BOOT_SCREEN)
  static bool bootloop=true;
  if(bootloop)
  {
    manager->redraw();
    delay(500);
    arduinoSerial::run();
    if(arduinoSerial::hasString(&input))
    {
        if(strlen(input)>2)
        {
            LOGex(input);
            LOG("Got a string, exiting bootlopo");
            bootloop=false;
            ProcessInputString(input);
        }
    }
    return;
  }
#endif
#if 1
    bool touched=ts->press(x,y);
    SPI.setClockDivider (SPI_CLOCK_DIV2);
    if(touched)
    {        
        //LOG("Screen Pressed");
        manager->clicked(x,y);
    }
#endif
    arduinoSerial::run();
    if(arduinoSerial::hasString(&input))
    {
        ProcessInputString(input);
    }

}
