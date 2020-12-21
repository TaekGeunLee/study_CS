#include <stdio.h>
#include <stdlib.h>

struct Point2D {
    int x;
    int y;
};


int main()
{
    struct Point2D *p1 = malloc(sizeof(struct Point2D));

    p1->x = 24;
    p1->y = 60;

    printf("%d %d\n", p1->x, p1->y);
    
    free(p1);

    return 0;
}

/*
12.
포인터 변수 p1는 malloc()로 동적할당한 영역 내에 위치한 구조체를 가리키고 있다.

14, 15.
포인터 구조체 내의 멤버 변수에 접근하기 위해 전용 연산자(->)를 사용한다.
가리킨다는 의미로 화살표 연산자(arrow operation) 이라고 부른다.
*/
