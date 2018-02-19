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
#include "Arduino.h"
#include "touchySerializer.h"
void setup(void)
{
        Serial.begin();
        delay(3000);
        Serial.println("READY!");
}


#define CHECK(x) if(!(x)) {Serial.println("Test " #x "Failed!!!");}

void loop(void)
{

    char out[256];
    char deser[256];
    char *arg[3];
    char kind[10];
    char name[10];
    int  args;
    
    
    arg[0]=deser;
    arg[1]=deser+50;
    arg[2]=deser+100;
    Serializer::serialize(out,(char *)"SCR","IDLE","Time","GB","BEEP");
    Serial.println(out);
    //
     DeSerializer::deserialize(out, kind, name, args, arg);
     CHECK(args==3);
     CHECK(!strcmp(kind,"SCR"));
    
    
    Serializer::serialize(out,"SCR","MEGA","alpha","Beta");
    Serial.println(out);
    Serializer::serialize(out,"Event","foo","one");
    Serial.println(out);
    Serializer::serialize(out,"zelda","syphon");
    Serial.println(out);
    
    delay(3000);
}
