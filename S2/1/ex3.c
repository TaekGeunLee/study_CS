#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Point2D {
    int x;
    int y;
};


int main()
{
    struct Point2D p1;

    p1.x = 10;
    p1.y = 20;

    printf("%d %d\n", p1.x, p1.y);

    return 0;
}

/*
5~8.
구조체 Point2D를 선언하였다.
내부에는 연관된 변수, x, y가 들어있다. 
이러한 변수들을 구조체 Point2D의 멤버 변수 라고도 부른다.
*/