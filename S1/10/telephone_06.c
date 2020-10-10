#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 50
#define CAPACITY 50

char **name;
char **number;
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
        if (read_line(command_line, BUFFER_SIZE) <= 0)
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
    name = (char **)malloc(CAPACITY * sizeof(char *));
    number = (char **)malloc(CAPACITY * sizeof(char *));
}

int read_line(char *comnd, int limits) {
    int n = 0;
    int str;

    while((str = getchar()) != '\n')
        if (n < limits-1)
            comnd[n++] = str;

    comnd[n] = '\0';
    return n;
}

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

void add(char *arg1, char *arg2) {
    if (i > CAPACITY)
        reallocate();

    int n = i-1; // index when i use for sorting array.
    while(n>=0 && strcmp(name[n], arg1)>0) {
        name[n+1] = name[n];
        number[n+1] = number[n];
        n--;
    }
    name[n+1] = strdup(arg1);
    number[n+1] = strdup(arg2);
    i++;
    printf("i : %d\n", i);
}

void drop(char *arg1) {
    int index = search(arg1);

    if (index < 0)
        return;

    for (int j=index; j<i-1; j++) {
        name[j] = name[j+1];
        number[j] = number[j+1];
    }
    i--;
}

void show() {
    for (int j=0; j<i; j++)
        printf("%s %s\n", name[j], number[j]);
}

int search(char *arg1) {
    int index = 0;
    for (int j=0; j<i; j++)
        if (strcmp(arg1, name[j]) == 0) {
            index = j;
            printf("target number : %s | target index : %d\n", number[j], index);
            return index;
        }
    return -1;
}


void load(char *filename) {
    char loadName[BUFFER_SIZE];
    char loadNumber[BUFFER_SIZE];

    FILE *fp = fopen(filename, "r");

    while (fscanf(fp, "%s", loadName) != EOF) {
        fscanf(fp, "%s",loadNumber);
        add(loadName, loadNumber);
    }
    fclose(fp);

    printf("loading data complete!\n");
}


void saveAs(char *filename) {
    FILE *fp = fopen(filename, "w");

    for (int j=0; j<i; j++) {
        fprintf(fp, "%s %s\n", name[j], number[j]);
    }

    fclose(fp);
    printf("save file complete!\n");
}