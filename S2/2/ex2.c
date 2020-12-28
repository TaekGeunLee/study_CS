#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Person {
    char name[20];
    int number;
    int weight;
} Person;

int main()
{
    Person *p1 = malloc(sizeof(Person)); // sizeof(struct _Person) 로 써도 무관.

    strcpy(p1->name, "Mina");
    p1->number = 0011;
    p1->weight = 64;

    printf("%s\n", p1->name);
    printf("%d\n", p1->number);
    printf("%d\n", p1->weight);

    return 0;
}

/*
    구조체 별칭을 사용한 경우에도 당연히 포인터 변수를 선언할 수 있다.
*/