#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 50

int main(void)
{
    char str[BUFFER_SIZE];

    while(1) {
        printf("$ ");
        int k = read_line(str, BUFFER_SIZE);
        printf("%s:%d\n", str, k);
    }
    return 0;
}

int read_line(char s[], int limits) {
    int ch, i = 0;

    while((ch = getchar()) != '\n') {
        if (i<limits)
            s[i++] = ch;
    }

    s[i] = '\0';
    return i;
} // 읽어들인 문자열의 길이가 BUFFER_SIZE를 넘었을 경우 그 이상의 문자는 읽지 않는다.
