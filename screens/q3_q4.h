


#define COMPUTE_AND_DRAW_Q3() \
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
            if(x>0) result=25; \
                else \
                    result=75; \
        } \
        if(result > _percent) c=0; \
            else c=0xffff; \
        }



#define BODY_Q3 \
        index=end-start-1; \
        if( 0 && p>maxPercent) \
        { \
            index=end-start; \
            DRAW_X(index); \
        } else \
        if( 0 &&  p<minPercent) \
        { \
            index=0; \
            DRAW_O(); \
        } else \
        for(int x=start;x<end;x++) \
        { \
        int r=0;\
        if(y)\
             r= (int)(50.*atan2(y,x)/M_PI); \        
        if(r< p) c=0xffff; else c=0;   \
        scanLine[index--]=c; \
        DRAW_COLOR(c); \
        } 
        
        //if(x==start) {char bfer[70];sprintf(bfer,"::x=%d, y=%d,r=%d,p=%d,%d,%d>",x,y,r,p,minPercent,maxPercent); Serial.println(bfer); }\
        
        
#define BODY_Q4 \
        index=0; \
         if( 0&& p>maxPercent) \
        { \
            memset(scanLine,0,2*(end-start)); \
            DRAW_X(index); \
        } else \
        if( 0 && p<=minPercent) \
        { \
            memset(scanLine,0xff,2*(end-start)); \
            DRAW_O(); \
        } else \
        for(int x=start;x<end;x++) \
        { \
        float r=25; \
        if(y) r= (int)(50.*atan2(x,y)/M_PI); \        
        if(r> p) c=0xffff; else c=0x0; \
            scanLine[index++]=c; \
            DRAW_COLOR(c); \
        } 

// char bfer[20];sprintf(bfer,"<r=%d,p=%d,%d,%d>",r,p,minPercent); Serial.prinln(bfer); \        

#ifndef DRAW_Q3      

#define DRAW_Q4 \
            ucg->getTft()->setAddrWindow(160-end,120-y,160-start,120-y); \
            ucg->getTft()->pushColors(scanLine,end-start); 


#define DRAW_Q3 \
            if(0) \
            {\
            ucg->getTft()->setAddrWindow(160-y,120+start,160-y,120+end); \
            ucg->getTft()->pushColors(scanLine,end-start);  \
            } else {\
            for(int z=start;z<end;z++) \
                ucg->getTft()->drawPixel(160-y,120+z,scanLine[end-z-1]);\
                }

#endif