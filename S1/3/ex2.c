#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    char line[80];
    while(1) {
        printf("$ ");
        int length = read_line_with_compression(line, 80);
        printf("%s:%d\n", line, length);
    }
    return 0;
}

int read_line_with_compression(char compressed[], int limit) {
    int ch, i = 0;
    while ((ch=getchar()) != '\n') {
        if (i<limit-1 && (!isspace(ch) || i>0 && !isspace(compressed[i-1]))) // 첫 번째 조건
            compressed[i++] = ch;
    }
    if (i>0 && isspace(compressed[i-1])) // 두번째 조건
        i--;
    compressed[i] = '\0';
    return i;
}

compressed[5] != ' '
/*
    ★ 첫 번째 조건
    대상 인덱스(i)가 배열 최대 크기(limit) 보다 작거나, 공백문자가 아니라면,
    콘솔로부터 입력받은 문자열의 문자를 할당.
    
    ★ 두 번째 조건
    대상 인덱스(i)가 0보다 크고, 공백문자라면 대상 인덱스(i)를 한칸 줄임.
    해당 조건에서 연속으로 공백 문자가 하나 이상 들어갔을 경우도 필터링 함.
    이해가 안된다면 compressed[i-1]를 유심히 살펴볼 것.
    
    ** tip!
    배열 구조가 어떻게 돌아가는지만 알면 코드 전체를 암기하지 않아도
    술술 코드를 작성해나갈 수 있을 것이다.
*/