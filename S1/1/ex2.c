#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int sum, i, avg;
    int num[15];

    for (i=0; i<15; i++) {
        printf("input number(%d) => ", i);
        scanf("%d", &num[i]);
    }
    sum = calculate_sum(num);
    avg = sum / 15;
    printf("%d\n", avg);

    return 0;
}

int calculate_sum(int *array) {
    int sum, i;
    sum = 0;
    for (i=0; i<15; i++) {
        sum = sum+array[i];
    }

    return sum;
}
