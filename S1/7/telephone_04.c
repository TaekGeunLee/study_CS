#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 50
#define CAPACITY 100

char *name[CAPACITY];
char *number[CAPACITY];
int i = 0;

int main()
{
    while(1) {
        char command[BUFFER_SIZE];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            add();
        } else if (strcmp(command, "drop") == 0) {
            drop();
        } else if (strcmp(command, "show") == 0) {
            show();
        } else if (strcmp(command, "search") == 0) {
            search();
        } else if (strcmp(command, "load") == 0) {
            load();
        } else if (strcmp(command, "save") == 0){
            saveAs();
        } else if (strcmp(command, "exit") == 0) {
            break;
        }
    }

    return 0;
}

void add() {
    char buf1[BUFFER_SIZE];
    char buf2[BUFFER_SIZE];
    scanf("%s", buf1);
    scanf("%s", buf2);

    int n = i-1; // index when i use for sorting array.
    while(n>=0 && strcmp(name[n], buf1)>0) {
        name[n+1] = name[n];
        number[n+1] = number[n];
        n--;
    }
    name[n+1] = strdup(buf1);
    number[n+1] = strdup(buf2);
    i++;
    printf("i : %d\n", i);
}

void drop() {
    char buf1[BUFFER_SIZE];
    scanf("%s", buf1);

    for (int j=0; j<i; j++) {
        if (strcmp(buf1, name[j]) == 0) {
            name[j] = name[i-1];
            number[j] = number[i-1];
            i--;
        }
    }
}

void show() {
    for (int j=0; j<i; j++)
        printf("%s %s\n", name[j], number[j]);
}

void search() {
    char buf1[BUFFER_SIZE]; //name
    scanf("%s", buf1);

    for (int j=0; j<i; j++) {
        if (strcmp(buf1, name[j]) == 0)
            printf("%s\n", number[j]);
    }
}


void load() {
    char filename[BUFFER_SIZE];
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");

    char loadName[BUFFER_SIZE];
    char loadNumber[BUFFER_SIZE];

    while (fscanf(fp, "%s", loadName) != EOF) {
        fscanf(fp, "%s",loadNumber);
        name[i] = strdup(loadName);
        number[i] = strdup(loadNumber);
        i++;
    }
    fclose(fp);

    printf("loading data complete!\n");
}


void saveAs() {
    int j = 0;
    char commandAs[BUFFER_SIZE];
    char filename[BUFFER_SIZE]; // file name when save for txt file.
    scanf("%s", commandAs);
    scanf("%s", filename);

    FILE *fp = fopen(filename, "w");

    for (j=0; j<i; j++) {
        fprintf(fp, "%s %s\n", name[j], number[j]);
    }

    fclose(fp);
}