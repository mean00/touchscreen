#pragma once


#define button_width  100
#define button_height  32


void drawBitmap(Ucglib *ucg,int wx,int wy, const uint8_t *data, int width, int height, int fgcolor,int bgcolor);
void drawButton(Ucglib *ucg, int x, int y, char *text);