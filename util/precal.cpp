#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
int main(int argc, char **argv)
{
    printf("static const int precalc[]={\n");
    for(int i=0;i<=80;i++)
    {
        float x;
        int percent,percent2;
        if(i>50) x=0;
            else x=sqrt(50*50-i*i);
        float x2=sqrt(80*80-i*i);

        if(i)
        { 
            percent = 25-(int)(50.*atan2(i,x)/M_PI); 
            percent2 = 25-(int)(50.*atan2(i,x2)/M_PI); 
    
        } 
        else
        {
            percent=25;
            percent2=25;
        }



        //printf("y=%d==>%d,%d,percent=%d,percent2=%d\n",i,(int)x,(int)(x2-x),percent,percent2);
        printf("%d,%d,%d,%d,\n",(int)x,(int)(x2-x),percent,percent2);

    }
    printf("};\n");
    return 0;


}
