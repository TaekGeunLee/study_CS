#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 50
#define CAPACITY 100


typedef struct person {
    char *name;
    char *number;
    char *email;
    char *group;
} Person;

Person ** directory;

char delim[] = " ";
int i = 0; // index for DB array name, number.
int capacity = 0;

void process_command();
void init_dir();
int read_line();
void handle_add();
int compose_name();
void print_Person();
void relase_person();
void reallocate();
void add();
void drop();
void show();
int search();
void load();
void saveAs();


int main()
{
    init_dir();
    process_command();

    return 0;
}

void process_command() {
    char command_line[BUFFER_SIZE];
    char *command, *argument1, *argument2;
    char name_str[BUFFER_SIZE] = " ";

    while(1) {
        printf("$ ");
        if (read_line(stdin, command_line, BUFFER_SIZE) <= 0)
            continue;

        command = strtok(command_line, delim);
        // printf("command : %s\n", command);

        if (strcmp(command, "add") == 0) {
            if (compose_name(name_str, BUFFER_SIZE) <= 0) {
                printf("enter name.\n");
                continue;
            }
            handle_add(name_str);
        } else if (strcmp(command, "drop") == 0) {
            strcpy(name_str, strtok(NULL, delim)); // name

            if (name_str == NULL) {
                printf("invailed name.\n");
                continue;
            }
            drop(name_str);
        } else if (strcmp(command, "show") == 0) {
            show();
        } else if (strcmp(command, "search") == 0) {
            strcpy(name_str, strtok(NULL, delim)); // name

            if (name_str == NULL) {
                printf("enter the name.\n");
                continue;
            }

            search(name_str);
        } else if (strcmp(command, "read") == 0) {
            argument1 = strtok(NULL, delim); // filename

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
    directory = (Person **)malloc(CAPACITY * sizeof(Person *));
    capacity = CAPACITY;
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

void handle_add(char *name) {
    char number[BUFFER_SIZE], email[BUFFER_SIZE], group[BUFFER_SIZE];
    char empty[] = " ";

    printf("number : ");
    read_line(stdin, number, BUFFER_SIZE);

    printf("email : ");
    read_line(stdin, email, BUFFER_SIZE);

    printf("group : ");
    read_line(stdin, group, BUFFER_SIZE);

    add(strdup(name),
        (char *)(strlen(number)>0 ? strdup(number) : empty),
        (char *)(strlen(email)>0 ? strdup(email) : empty),
        (char *)(strlen(group)>0 ? strdup(group) : empty)
    );
};

int compose_name(char *str, int limits) {
    char *ptr;
    int length = 0;

    ptr = strtok(NULL, " ");

    if (ptr == NULL) {
        return 0;
    }

    strcpy(str, ptr);
    length += strlen(ptr);

    while((ptr = strtok(NULL, " ")) != NULL) {
        if (strlen(ptr)+length+1 < limits) {
            str[length] = ' ';
            length += 1;
            str[length] = '\0';
            strcat(str, ptr);
            length += strlen(ptr);
        }
    }
    return length;
}

void print_Person(Person *p) {
    printf("name : %s\n", p->name);
    printf("number : %s\n", p->number);
    printf("email : %s\n", p->email);
    printf("group : %s\n\n", p->group);
}

void relase_person(Person *p) {
    free(p->name);
    free(p->number);
    free(p->email);
    free(p->group);
    free(p);
}


void reallocate() {
    capacity = capacity * 2;

    char **tmp = (Person **)malloc(capacity * sizeof(Person *));

    for (int j=0; j<i; j++)
        tmp[j] = directory[j];

    free(directory);

    directory = tmp;
}


void add(char *arg1, char *arg2, char *arg3, char *arg4) {
    if (i >= capacity)
        reallocate();

    int n = i-1; // index when i use for sorting array.
    while(n>=0 && strcmp(directory[n]->name, arg1)>0) {
        directory[n+1] = directory[n];
        n--;
    }

    directory[n+1] = (Person *)malloc(sizeof(Person));

    directory[n+1]->name = arg1;
    directory[n+1]->number = arg2;
    directory[n+1]->email = arg3;
    directory[n+1]->group = arg4;
    i++;
}

void drop(char *arg1) {
    int index = search(arg1);

    if (index < 0)
        return;

    Person *p = directory[index];

    for (int j=index; j<i-1; j++) {
        directory[j] = directory[j+1];
    }
    i--;
    relase_person(p);
    printf("delete complete.\n");
}

void show() {
    for (int j=0; j<i; j++)
        printf("%s %s %s %s\n", directory[j]->name, directory[j]->number, directory[j]->email, directory[j]->group);
}

int search(char *arg1) {
    int index = 0;
    for (int j=0; j<i; j++)
        if (strcmp(arg1, directory[j]->name) == 0) {
            index = j;
            print_Person(directory[j]);
            // printf("target number : %s | target index : %d\n", directory[j].number, index);
            return index;
        }
    return -1;
}


void load(char *filename) {
    char buf[BUFFER_SIZE];
    char *name, *number, *email, *group;
    char *token;

    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
        printf("Open failed.\n");

    while (1) {
        if (read_line(fp, buf, BUFFER_SIZE) <= 0)
            break;
        name = strtok(buf, "#");
        token = strtok(NULL, "#");

        if (strcmp(token, " ") == 0) {
            number = NULL;
        } else {
            number = strdup(token);
        }
        token = strtok(NULL, "#");
        if (strcmp(token, " ") == 0) {
            email = NULL;
        } else {
            email = strdup(token);
        }
        token = strtok(NULL, "#");
        if (strcmp(token, " ") == 0) {
            group = NULL;
        } else {
            group = strdup(token);
        }
        add(strdup(name), number, email, group);
    }
    fclose(fp);

    printf("loading data complete!\n");
}


void saveAs(char *filename) {
    FILE *fp = fopen(filename, "w");

    for (int j=0; j<i; j++) {
        fprintf(fp, "%s#", directory[j]->name);
        fprintf(fp, "%s#", directory[j]->number);
        fprintf(fp, "%s#", directory[j]->email);
        fprintf(fp, "%s\n", directory[j]->group);
    }

    fclose(fp);
    printf("save file complete!\n");
}
