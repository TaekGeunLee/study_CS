#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 80

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
    printf("add command operate.\n");
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
