#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 50
#define CAPACITY 50


typedef struct person {
    char **name;
    char **number;
} Person;

Person directory[CAPACITY];

/*
char **name;
char **number;
*/

char delim[] = " ";
int i = 0; // index for DB array name, number.
int capacity = CAPACITY;

void process_command();
void init_dir();
void add();
void drop();
void show();
int search();
void load();
void saveAs();
int read_line();
void reallocate();

int main()
{
    init_dir();
    process_command();

    return 0;
}

void process_command() {
    char command_line[BUFFER_SIZE];
    char *command, *argument1, *argument2;


    while(1) {
        printf("$ ");
        if (read_line(stdin, command_line, BUFFER_SIZE) <= 0)
            continue;

        command = strtok(command_line, delim);

        if (strcmp(command, "add") == 0) {
            argument1 = strtok(NULL, delim);
            argument2 = strtok(NULL, delim);

            if (argument1 == NULL || argument2 == NULL) {
                printf("invailed name or number.\n");
                continue;
            }
            add(argument1, argument2);
        } else if (strcmp(command, "drop") == 0) {
            argument1 = strtok(NULL, delim);

            if (argument1 == NULL) {
                printf("invailed name.\n");
                continue;
            }
            drop(argument1);
        } else if (strcmp(command, "show") == 0) {
            show();
        } else if (strcmp(command, "search") == 0) {
            argument1 = strtok(NULL, delim); // filename for load.

            if (argument1 == NULL) {
                printf("enter the filename.\n");
                continue;
            }

            search(argument1);
        } else if (strcmp(command, "read") == 0) {
            argument1 = strtok(NULL, delim); // filename for load.

            if (argument1 == NULL) {
                printf("enter the filename.\n");
                continue;
            }
            load(argument1);
        } else if (strcmp(command, "save") == 0) {
            argument1 = strtok(NULL, delim); // command 'as'
            argument2 = strtok(NULL, delim); // filename for save

            if (strcmp(argument1, "as")!=0 || argument2 == NULL) {
                printf("enter the correct command.\n");
                continue;
            }

            saveAs(argument2);
        } else if (strcmp(command, "exit") == 0) {
            break;
        }
    }
}

void init_dir() {
    for (int n=0; n<CAPACITY; n++) {
        directory[n].name = (char **)malloc(CAPACITY * sizeof(char *));
        directory[n].number = (char **)malloc(CAPACITY * sizeof(char *));
    }

}

int read_line(FILE *fp, char *str, int limits) {
    int ch, n = 0;

    while((ch = fgetc(fp)) != '\n' && ch != EOF)
        if (n < limits-1)
            str[n++] = ch;

    str[n] = '\0';
    return n;
    // return 0 when there's no read strings.
}

/*
void reallocate() {
    capacity = capacity * 2;

    char **tmp1 = (char **)malloc(capacity * sizeof(char *));
    char **tmp2 = (char **)malloc(capacity * sizeof(char *));

    for (int j=0; j<i; j++) {
        tmp1[j] = name[j];
        tmp2[j] = number[j];
    }

    free(name);
    free(number);

    name = tmp1;
    number = tmp2;
}
*/

void add(char *arg1, char *arg2) {
    /* modify after change all DB arrays to structure variables.
    if (i > CAPACITY)
        reallocate();
    */
    int n = i-1; // index when i use for sorting array.
    while(n>=0 && strcmp(directory[n].name, arg1)>0) {
        directory[n+1] = directory[n];
        n--;
    }
    directory[n+1].name = strdup(arg1);
    directory[n+1].number = strdup(arg2);
    i++;
    printf("i : %d\n", i);
}

void drop(char *arg1) {
    int index = search(arg1);

    if (index < 0)
        return;

    for (int j=index; j<i-1; j++) {
        directory[j] = directory[j+1];
    }
    i--;
}

void show() {
    for (int j=0; j<i; j++)
        printf("%s %s\n", directory[j].name, directory[j].number);
}

int search(char *arg1) {
    int index = 0;
    for (int j=0; j<i; j++)
        if (strcmp(arg1, directory[j].name) == 0) {
            index = j;
            printf("target number : %s | target index : %d\n", directory[j].number, index);
            return index;
        }
    return -1;
}


void load(char *filename) {
    char buf[BUFFER_SIZE];
    char *name, *number;

    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
        printf("Open failed.\n");

    while (1) {
        if (read_line(fp, buf, BUFFER_SIZE) <= 0)
            break;
        name = strtok(buf, delim);
        number = strtok(NULL, delim);
        printf("name : %s, number: %s\n", name, number);
        add(name, number);
    }
    fclose(fp);

    printf("loading data complete!\n");
}


void saveAs(char *filename) {
    FILE *fp = fopen(filename, "w");

    for (int j=0; j<i; j++) {
        fprintf(fp, "%s %s\n", directory[j].name, directory[j].number);
    }

    fclose(fp);
    printf("save file complete!\n");
}
