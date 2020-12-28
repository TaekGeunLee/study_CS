#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char *data;

    struct node *next;

} Node;

void add_prev();

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

    Node *s = (Node *)malloc(sizeof(Node));
    s->data = "Ravender";
    s->next = NULL;
    p->next = s;

    add_prev("Coriander");

    return 0;
}

void add_prev(char *str, Node *p) {
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = str;
    tmp->next = p->next;
    p->next = tmp;
    printf("tmp-node : %s\n", tmp->data);
}

/*
32.
노드 Basil, Thyme, Ravender가 있는 상태이다.
Ravender 뒤에 새로운 노드인 Coriander를 삽입하고 있는 모습이다.

연결 리스트의 맨 앞에 새 노드를 끼는 프로그램과 같은 전략이다.
40번 문단의 p->next가 무엇을 가리키고 있는지 유심히 살펴볼 것.

37.
*p는 이전에 main() 함수의 지역변수로써 선언했기 때문에 
다른 함수내에서 쓰기 위해서는 인자로 가져와야만 한다.
그렇게 하지 않으면 아래의 error가 띄워진다.

ERROR.
어딘가에서 num 이라는 변수를 사용했지만,
선언한 적은 없다.

error : 'num' undeclared (first use in this function)

37.
인자 p는 주소로써 값을 가져와야만 한다.
원래 이 코드는 틀렸지만, 원래 목적인 노드 삽입 방법에만 집중하도록 하자.

*/


