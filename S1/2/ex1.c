#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *words[100];
    int n = 0;
    char buffer[100];

    while(n<4 && scanf("%s", buffer) != EOF) {
        words[n] = strdup(buffer); // buffer의 번지의 복사본을 words[n]에 할당.
        n++;
    }

    for (int v=0; v<4; v++) {
        printf("%s\n", words[v]);
    }

    return 0;
}

/*
    EOF(End Of File)
    : 위의 예제에서는 buffer 문자열에 문자가 꽉 차면(이것은 파일, 즉 데이터의 모음(배열)의 끝에 도달했다는 뜻) EOF가 출력된다만, 
    전부 채우지 않을 것이기 때문에 관계 연산자 != 를 쓴 것이다.
*/ 