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
        if(i>50) x=0;
            else x=sqrt(50*50-i*i);
        float x2=sqrt(80*80-i*i);
        printf("%d,%d,\n",(int)x,(int)(x2-x));

    }
    printf("};\n");
    return 0;


}
