#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long simple_func(int x, int y, int z)
{
    x = 10;
    y = 3;
    long b;
    b=x*y;
    return b;

}

long simple_func2(char *x, char *y)
{
    return 44;
}
long simple_func3()
{
    return 44;
}

int main()
{
    int x;
    x=90;
    if ((3 > x) && (5 > 9)){
        printf("WORK");
    }
    long tlv2;
    tlv2=simple_func3();
    if (tlv2 > 40){
        printf("WORK2");
    }
    if (8 > 0){
        int tlv1;
        tlv1=8;
        {
            int tlv3;
            tlv3=44;
            printf("%ld\n",simple_func(tlv1,tlv3,x));
        }
        {
            int tlv3;
            tlv3=8;
            int tlv4;
            tlv4=44;
            int tlv5;
            tlv5=99;
            printf("%ld\n",simple_func(tlv3,tlv4,tlv5));
        }
        long nv;
        {
            int tlv3;
            tlv3=8;
            int tlv4;
            tlv4=44;
            int tlv5;
            tlv5=99;
            nv=simple_func(tlv3,tlv4,tlv5);
        }
        printf("%ld\n",simple_func(8,simple_func(1,2,3),8));
        printf("%ld\n",simple_func(8,
                                    tlv1,
                                    6));
        printf("%ld\n",simple_func2("this","that"));
    }
    return 0;
}

