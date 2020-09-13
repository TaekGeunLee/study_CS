#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x = 15, y = 20;
    int *xp = &x; // 포인터 변수 xp는 x를 가리킴.

    y = *xp;
    *xp = 0;

    printf("xp : %d\n", *xp);
    printf("y : %d", y);

    return 0;
}

/*
    1.
    최종 결과로 x와 y에 들어있는 값은 얼마일까?
    직접 메모리 구조를 그림으로 그려서 생각해보자.
    
    ** hint
    C언어는 절차 지향으로 동작한다. 한번에 다수의 작업을 동시에 처리할 수 없다.
    이 점을 주의해서 고민을 해보도록 하자.

*/