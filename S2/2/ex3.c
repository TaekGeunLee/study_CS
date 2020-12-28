#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[20];
    int grade;
    float average;
};

int main()
{
    struct Student pt; // 일반 구조체 변수
    struct Student *ptr; // 포인터 구조체 변수

    ptr = &pt; // 포인터 변수에 일반 변수의 주소값을 할당.

    strcpy(pt.name, "Suzi");
    pt.grade = 1;
    ptr->average = 65.9;

    printf("이름: %s\n", pt.name);
    printf("학년: %d\n", ptr->grade);
    printf("평균점수: %f\n", ptr->average);

    free(ptr);

    return 0;
}

/*
    14~17.
    포인터 변수에 일반 변수의 주소를 할당하는 식으로 
    malloc()를 이용한 동적 할당의 과정을 생략할 수 있다.
    
    해당 방식은 구조체 뿐만 아니라 정수형, 실수형등 일반 포인터 변수에도 해당된다.
    
    19~26.
    일반 변수(pt), 포인터 변수(ptr)로 메모리에 할당한 구조체에 접근하고 있는 모습이다.
    선언한 해당 2개의 변수로 접근이 가능하다.
*/
