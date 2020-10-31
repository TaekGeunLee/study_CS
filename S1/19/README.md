### 연결 리스트 표현하기

<p>
따로 연결 리스트 전용 표현식이 있는 것은 아니다.<br />
구조체 표현식 struct, typedef를 이용해 연결 리스트를 표현한다.
</p>

```c
struct node {
    char *data; // 데이터 필드. char 형태의 연결 리스트를 만들 경우.
    
    struct node *next // 링크 필드.
}
// node 구조체 선언.

typedef struct node Node;
Node *head = NULL // 첫 번째 node의 번지.
```

<p>
node 구조체의 링크 필드 부분을 살펴보자.<br />
처음 봤을 때에는 이해가 안되었지만, 링크 필드에 담기는 것이 무엇인지 생각하면 파악할 수 있다.<br />
다시 한번 next 포인터 변수의 명의로 자기 자신을 선언한 것이다.<br />
이렇게 자신과 동일한 구조체에 대한 포인터를 멤버로 가진다는 의미에서 <b>자기참조형 구조체</b> 라고 부른다.<br />
재귀함수와 비슷할지도. 
</p>

<p>
첫 번째 node의 번지는 까먹어서는 안되고, 함부로 건드려서는 안되기에 별도의 포인터 변수 *head에 선언한 것이다.<br />
*head는 연결 리스트 그 자체를 의미하기도 하니까 말이다.
</p>

### 기본 예제

<p>
연결 리스트의 각 node의 구현 연습을 담은 예제를 리뷰해보자.<br />
어디까지나 연습을 위한 예제이고, 여기서 소개하는 방식은 비효율적임을 알아두자.<br />
한 구절씩 코드 리뷰를 해보자. 전체 코드는 pratice.c에 있다.
</p>

```c
head = (Node *)malloc(sizeof(Node));
head->data = "red";
head->next = NULL;
```
<p>
제일 먼저 하나의 Node를 만들어 *head 포인터 변수가 가리키도록 한다.<br />
미리 최대 수용량 만큼의 메모리 셀을 준비하는 배열과는 달리 연결-리스트는 새로운 node가 필요할 때 마다 뽑아 쓰는 방식이다.<br />
동적 메모리 할당을 통해 하나의 node에 해당하는 공간을 마련한다.<br />
그리고 head의 각 필드(data, next)에 값을 할당한다.<br />
위의 상황을 그림으로 나타내면 다음과 같다.
</p>

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_19-1.PNG" alt="S1_19-1" />

```c
Node *p = (Node *)malloc(sizeof(Node));
p->data = "orange";
p->next = NULL;
head->next = p; // 포인터 변수 p의 역할은 여기서 마쳐짐.
```

<p>
그 다음 문단에서는 또 하나의 node를 생성한다.(여기까지 총 2개의 node가 생성됨.)<br />
새로 생성한 노드는 *p가 가리키고 있는 상태이고, 마지막 node 이기에 p의 링크 필드에 NULL를 할당했다.<br />
이렇게 되면 더 이상 head가 가리키고 있는 node는 마지막 노드가 아니기에 head의 링크 필드를 수정해줘야 한다.<br />
위의 상황을 그림으로 나타내면 다음과 같다.
</p>

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_19-2.PNG" alt="S1_19-2" />

```c
p = (Node *)malloc(sizeof(Node));
p->data = "pink";
p->next = head;
head = p
```

<p>
이번에는 또 하나의 node를 head가 가리키는 node 앞에 두도록 해보자.<br />
또 다시 새로운 변수를 선언해야 하나? 싶었지만 포인터 변수 *p를 재활용 하였다.<br />
p는 orange를 가리키고 있는 상황이라 문제가 생기지 않을까? 라고 생각했었지만, 그게 아니다.
</p>

<p>
일반 변수가 아니라 동적 메모리 할당 방식이기에 이미 값 할당은 이전에 완료한 상태이다.<br />
그리고 포인터 변수 p는 메모리를 가리키고 있는 것일 뿐이라 여기서 p의 역할은 끝난거나 마찬가지이다.<br />
따라서 한번 더 재활용 할 수 있는 것이고 말이다.
</p>

<p>
새로운 노드, pink를 만든 뒤에는 이전의 red는 맨 앞의 노드가 아니게 된다.<br />
따라서 p->next를 *head 변수로 가리키게 하고, <br />
*head 변수를 맨 앞의 노드를 가리키고 있는 p에 가리키도록 한다.<br />
(절차 지향적으로 생각하면 쉽게 이해할 수 있다.)<br />
그림으로 나타내면 다음과 같다.
</p>

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_19-3.PNG" alt="S1_19-3" />

```c
Node *r = head;

while (r != NULL) {
    printf("%s\n", r->data);
    r = r->next
}
```

<p>
마지막으로 각 node들의 데이터들을 출력하기 위해 새로운 포인터 변수 *r를 생성한다.<br />
*r은 반복문을 거쳐서 마지막 node 까지 도달하기에, 새로이 malloc()를 쓸 필요가 없다.
</p>