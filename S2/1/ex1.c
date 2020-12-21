#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Fruit {
    char name[20];
    char flavor[20];
    int seed;
} Fruit;

int main()
{
    Fruit f1;
    // struct _Fruit f1;

    strcpy(f1.name, "apple");
    strcpy(f1.flavor, "fresh");
    f1.seed = 4;

    printf("name : %s\n", f1.name);
    printf("flavor : %s\n", f1.flavor);
    printf("seed : %d", f1.seed);

    return 0;
}

/*
5~9.
typedef는 변수형에 별칭(alias)를 붙이는 키워드이다.


*/