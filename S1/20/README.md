<p>여러 디렉토리를 거치면서 연결-리스트의 운용 방법을 익혀나가보자.</p>

<p>
일련의 노드가 있다고 가정했을 때, 맨 앞에 노드를 생성해야 하는 문제를 풀어보자.<br />
이 때 맨 첫 번째 노드를 가리키는 포인터 변수 *head의 주목 대상을 바꿔야 할 것이다.<br />
<a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/19">이전 레퍼토리</a>에서 다뤘었지만, 경우에 따라 고려해야 하는 사항들이 있다.
</p>


### 기본 전략

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_20-1.png" alt="S1_20-1" />

<p>기본 메커니즘은 다음과 같다.</p>

<ul>
    <li>맨 앞에 둘 node를 하나 생성.</li>
    <li>새로운 node의 링크 필드를 *head(현재의 맨 앞 노드)로 향하게 둔다.</li>
    <li>*head의 주목 대상을 새로운 node로 향하게 한다.</li>
</ul>

<p>
여기서 2번째, 3번째의 순서를 뒤바꿔도 아무런 문제 없지 않을까?<br />
만약 *head의 주목 대상을 먼저 뒤바꿔버리면 주목 대상이였던 연결 리스트 자체가 사라져버린다.<br />
이후에 어떤 작업을 해도 연결 리스트를 잃어버렸기에.. 문제가 발생해버린다.
</p>

<p>다음 작업에 대한 내용을 코드로 바꾸면 다음과 같다.</p>

```c
Node *tmp = (Node *)malloc(sizeof(Node));
tmp->data = "Thyme";
tmp->next = head;
head = tmp;
```

### 함수 내부에 구현 : head가 지역 변수일 경우

<p>
위에서 다뤘던 전략을 함수로 구현하고 싶은 상황이 있을 수 있다.<br />
함수로 구현한다면 다음 처럼 된다.
</p>

```c
void add_first(char *item) {
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = item;
    tmp->next = head;
    head = tmp;
}
```

<p>
head가 전역 변수라면 아무런 문제가 없는 코드이다.<br />
만약 head가 지역 변수(예를 들어 main() 컨텍스트에서 선언된)라면, 함수의 인자로 head를 받아야 한다.
</p>

```c
void add_first(char *item, Node *head) {
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = item;
    tmp->next = head;
    head = tmp; // error
}
```

<p>
하지만 또 고쳐야 할 부분이 있다.<br />
어디까지나 head는 다른 함수 컨텍스트의 지역 변수이다.
</p>

<p>
add_first()를 호출했을 때, head 변수에 대한 임시 공간이 생기는데,<br />
해당 임시 공간은 add_first()의 호출이 완료되었을 시 사라져 버린다.<br />
head 내의 값을 사용하는 것은 문제 없겠지만, 내용을 바꾸지는 못한다는 것.<br />
(잘 이해되지 않는다면 C언어 함수 호출 방식에 대해 공부할 것. 실은 이전 파일에서도 언급했었다.)
</p>

<p>
그렇다면 어떻게 해야할까?<br />
그것은 head를 값이 아닌, 주소로써 인자로 받는 것이다.
</p>

```c
void main() {
    add_first("Basil", &head); // 주소로써 인자를 받기에 주소를 나타내는 문자(&)를 사용한다.  
}

void add_first(char *item, Node **ptr_head) {
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = item;
    tmp->next = *ptr_head;
    *ptr_head = tmp;
}
```

<p>
ptr_head 부분을 살펴보자.
*head의 번지를 함수의 인자로 받는 것이니 중첩 포인터 기호(*)를 사용한 것이다.
</p>

<p>
*head는 애초에 주소 값인데 안 써도 문제 없지 않을까? 라고 생각했었다만,<br />
C언어에서는 함수 호출시 값에 해당하는 인자는 임시 공간이 생긴다고 했었다.<br />
임시 공간 내로 복제된 값을 사용하는 것이고, 실제 인자로 받은 변수를 사용한다는 것이 아니라는 말이다.
</p>

```c
Node * add_first(char *item, Node *head) {
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = item;
    tmp->next = head;
    head = tmp;
}
```
<p>
또 다른 대안으로 함수 내에서 값을 직접 리턴하는 경우를 생각해 볼 수 있다.<br />
그렇게 되면 head를 값으로써 인자로 넣어도 아무런 문제 없이 동작할 것이다.
</p>


