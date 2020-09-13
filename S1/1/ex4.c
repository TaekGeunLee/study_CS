#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p;
    p = (int *)malloc(12); // malloc()는 stdlib.h의 함수이다.

    p[0] = 1;
    p[1] = 1;
    p[2] = 1;

    for (int i=0; i<3; i++)
        printf("%d\n", *p);

    return 0;
}
