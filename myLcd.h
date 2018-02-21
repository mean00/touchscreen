#ifdef FAST_LCD
    #undef swap
    #include "Adafruit_ILI9341_STM.h"
    #include "ucg_compat.h"
#else
    #include "Ucglib.h"
#endif
