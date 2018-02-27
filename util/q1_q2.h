

#define COMPUTE_AND_DRAW_Q1() \
{\
   float r=0; \
        if(y) \
        { \
            r= (int)(50.*atan2(y,x)/M_PI); \
        } \
        else\
        {\
            r=25;\
        } \
        if(r< _percent) c=0; \
            else c=0xffff; \
        }
#define COMPUTE_AND_DRAW_Q2() \
{\
   float result=0; \
        if(x)\
        { \
            result = (int)(50.*atan2(x,y)/M_PI); \
            if(result<-50) result=-50; \
            if(result>50) result=50; \
            result+=25; \
            if(result<0) result=result+100; \
        } \
        else\
        {\
            if(y>0) result=25;\
                else \
                    result=75;\
        } \
        if(result < _percent) c=0; \
            else c=0xffff; \
        }

      

#define BODY_Q1 \
         if( 0 && p>maxPercent) \ 
        { \
            index=end-start; \
            for(int i=0;i<index;i++) printf("X");printf("-"); \
        } else \
        if(0 && p+1<minPercent) \
        { \
            index=0; \            
            printf("O"); \
        } else \
        for(int x=start;x<end;x++) \
        { \
            COMPUTE_AND_DRAW_Q1(); \
            index++; \
            if(c) printf("*"); else printf("-"); \
        } \
        
#define BODY_Q2 \  
        if(p>maxPercent) \ 
        { \
            index=end-start; \
            for(int i=0;i<index;i++) printf("*");printf("-"); \
        } else \
        if(p<minPercent) \
        { \
            index=0; \            
            printf("-"); \
        } else \
        for(int x=start;x<end;x++) \
        { \
            COMPUTE_AND_DRAW_Q2(); \
            index++; \
            if(c) printf("*"); else printf("-"); \
            if(!c) break; \
        } 

             
        
#if 0        
#define DRAW_Q1 \        
        ucg->getTft()->setAddrWindow(start+160,y+120,160+end+1,y+120); \
        ucg->getTft()->pushColors(fullLine,index);


#define DRAW_Q2 \        
        ucg->getTft()->setAddrWindow(160+xy,120+start,160+xy,120+start+index); \
        ucg->getTft()->pushColors(fullLine,index);

#else
    #define DRAW_Q1 {}
    #define DRAW_Q2 {}
#endif 
