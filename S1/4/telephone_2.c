#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 80
#define CAPACITY 100

char *name[CAPACITY];
char *number[CAPACITY];

int n = 0; // buffer's index number

int main(void)
{

    char command[BUFFER_SIZE];


    while(1) {
        printf("$ ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            add();
        } else if (strcmp(command, "drop") == 0) {
            drop();
        } else if (strcmp(command, "show") == 0) {
            show();
        } else if (strcmp(command, "search") == 0) {
            search();
        } else if (strcmp(command, "exit") == 0) {
            break;
        }
    }
    return 0;
}

void add() {
    char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];

    scanf("%s", buf1);
    scanf("%s", buf2);

    name[n] = strdup(buf1);
    number[n] = strdup(buf2);
    n++;

    printf("add %s info completed.\n", buf1);
};

void drop() {
    printf("drop command operate.\n");
};
void show() {
    printf("show command operate.\n");
};
void search() {
    printf("search command operate.\n");
};