#include <stdio.h>
#include "head.h"

int main()
{
#ifdef DEBUG
        printf("此为DEBUG 即需指定运行的代码\n");
#endif

        int a = 20;
        int b = 12;
        printf("a = %d, b = %d\n", a, b);
        printf("a + b = %d\n", add(a, b));
        printf("a - b = %d\n", subtract(a, b));
        printf("a * b = %d\n", multiply(a, b));
        printf("a / b = %f\n", divide(a, b));
        return 0;
}