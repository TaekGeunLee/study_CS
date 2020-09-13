#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr = (int *)malloc(4*sizeof(int));
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;

    int *tmp = (int *)malloc(8*sizeof(int));
    for (int i=0; i<4; i++)
        tmp[i] = arr[i];

    arr = tmp; // 처음부터 변수로 선언했었으니 특수 기호(*)를 빼도 상관은 없다.

    arr[4] = 6;
    arr[5] = 7;
    arr[6] = 8;

    for (int v=0; v<6; v++)
        printf("%d ", arr[v]);


    return 0;
}