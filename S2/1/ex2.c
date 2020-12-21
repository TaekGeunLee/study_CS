#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char flavor[20];
    int seed;
} Fruit;

int main()
{
    Fruit f1;

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
typedef로 구조체 별칭을 선언한 상태라면 구조체 이름을 생략할 수 있다.
13번째 문단에서 이름 대신 별칭만을 사용해 구조체 변수를 선언하고 있는 것을 관찰할 수 있다.

15.
그냥 f1.name = "apple"로 해도 마찬가지 아닐까? 라고 생각했다.
f1.name은 문자열이고, C에서의 문자열은 문자들의 배열이라고 했다.
즉 f1.name은 포인터 변수이며, 일개 포인터 변수에 배열을 할당하려고 하는 것이다.

당연히 오류가 발생할 수 밖에 없기 때문에 
전략으로 strcpy()로 f1.name에 "apple"를 덮어씌우기 하는 것이다.
*/
