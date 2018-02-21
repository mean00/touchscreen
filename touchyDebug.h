

#if 1
    #define LOG(x) Serial.println("COM;" x)
    #define LOGex(x) Serial.println( x)
#else
    #define LOG(x) {}
    #define LOGex(x) {}
#endif