<p>
구조체는 복수의 멤버 변수를 지니고 있다.<br />
작성하고 있는 코드가 대규모라면, 구조체 내에 들어가는 멤버 변수의 수가 많아질 수 있다.
</p>

<p>
만약 위의 상태에서 인자로 구조체를 받는 함수(값으로써의 참조)를 만든다면,<br />
프로그램에게는 큰 부담이 될 수 밖에 없다. 그만큼 처리량이 많아진다는 것이다.<br />
이러한 상황에서 구조체에다 포인터를 사용할 수 있다.
</p>

```c
struct Person {
    char name[20];
    int age;
    int weight;
}

struct Person *p1 = malloc(sizeof(struct Person));
```
<p>
구조체에서 포인터를 사용하기 위해 동적 메모리 할당을 진행한다.<br />
(이 과정 없이 시도해본 결과, 원하는 결과가 안 나왔다.)<br />
포인터 변수 p1은 malloc()로 할당한 영역 내부에 존재하는 구조체 Person을 가리키고 있다.
</p>

```c
strcpy(p1->name, "Minsu");
p1->age = 14;
p1->weight = 30;
```
<p>
포인터 구조체 내부의 멤버 변수에 접근하기 위해 전용 연산자(->)를 사용한다.<br />
일반 구조체는 접근 지정자(.)를 사용한다.
</p>

```c
typedef struct _Person {
    char name[20];
    int age;
    int weight;
} Person

struct Person *p1 = malloc(sizeof(Person)); // sizeof(struct _Person)와 같음.
```

typedef를 이용해 별칭을 단 경우에도 구조체 포인터를 온전히 쓸 수 있다.
