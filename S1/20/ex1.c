#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char *data;

    struct node *next;

} Node;

Node *head = NULL;


int main()
{
    head= (Node *)malloc(sizeof(Node));
    head->data = "Basil";
    head->next = NULL;

    Node *p = (Node *)malloc(sizeof(Node));
    p->data = "Thyme";
    p->next = NULL;
    head->next = p;

    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = "Coriander";
    tmp->next = head;
    head = tmp;

    return 0;
}

/*

25~28.
노드 Basil, Thyme이 있는 상태에서 맨 앞(head) 자리에 
Coriander를 삽입하려고 한다.
반드시 동작 순서가 뒤 바뀌는 일이 없도록 한다.
*/
