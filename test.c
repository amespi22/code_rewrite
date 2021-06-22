#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long simple_func(int x, int y, int z)
{
    x = 10;
    y = 3;
    long b =x*y;
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
    int x = 90;
    if ((3 > x) && (5 > 9)){
        printf("WORK");
    }
    if (simple_func3() > 40){
        printf("WORK2");
    }
    if (8 > 0){
        int tlv1 = 8;
        printf("%ld\n",simple_func(tlv1,44,x));
        printf("%ld\n",simple_func(8,44,99));
        long nv = simple_func(8,44,99);
        printf("%ld\n",simple_func(8,simple_func(1,2,3),8));
        printf("%ld\n",simple_func(8,
                                    tlv1,
                                    6));
        printf("%ld\n",simple_func2("this","that"));
    }
    return 0;
}

