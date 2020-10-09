#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[] = "Mango # is ## my ### favorite # fruit.";
    char deli[] = "#";
    char * token = strtok(str, deli);

    while(token != NULL) {
        printf("token : %s(%d)\n", token, strlen(token));
        token = strtok(NULL, deli);
    }

    printf("str : %s\n", str);

    return 0;
}
