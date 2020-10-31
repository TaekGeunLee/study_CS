#include <stdio.h>
#include <stdlib.h>

struct node {
    char *data; // data field

    struct node *next // link field
};

typedef struct node Node;

Node *head = NULL;

int main(void)
{
    head = (Node *)malloc(sizeof(Node));
    head->data = "red";
    head->next = NULL;

    Node *p = (Node *)malloc(sizeof(Node));
    p->data = "orange";
    p->next = NULL;
    head->next = p;

    p = (Node *)malloc(sizeof(Node));
    p->data = "pink";
    p->next = head;
    head = p;

    Node *r = head;
    while(r != NULL) {
        printf("%s\n", r->data);
        r = r->next;
    };

    return 0;
}