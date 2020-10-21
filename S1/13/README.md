<p>
이전 디렉토리에서 구조체 형식을 이용해 사용자의 여러 항목을 추가했었다.<br />
또 개선해야 할 점은 구조체 자체를 함수의 매개변수로써 사용한다는 것에 있다.
</p>

```c
int search(char *arg1) {
    print_Person(directory[j]);
    return -1;
}

void print_Person(Person p) {
    printf("name : %s\n", p.name);
    printf("number : %s\n", p.number);
}
```
<p>
search() 내부에서 print_Person()을 호출하고 있다.<br />
호출된 함수 내의 인자를 <b>실제 매개변수</b>, 선언된 함수 내의 인자를 <b>형식 매개변수</b> 라고 부르겠다.<br />
(해당 강의에서는 그렇게 부르고 있다. 매개변수, 인자 라고 불리기도 한다.)
</p>

<p>
C언어에서는 호출된 함수 내의 실제 인자가 형식 매개변수로 복사되는 식으로 동작한다.<br />
실제 인자로 받은 directory[]는 구조체로 이루어진 배열이다.<br />
배열의 각 요소마다 여러 개의 변수를 지니고 있는데, 구조체 내의 변수가 많다면 그만큼 복사되는 양이 많아질 것이다.
</p>

```c
void drop(char *arg1) {
    for (int j=index; j<i-1; j++) 
        directory[j] = directory[j+1];
                       
    // 전체 코드 생략
}
```

<p>
또 다른 예시도 있다.<br />
drop() 함수에서 지우는 요소 역시 구조체 배열 내의 요소이다.<br />
이 때 지울려는 대상의 인덱스를 덮어쓰는 식으로 요소를 지우는 데, 
복사하는 요소 내의 변수들을 전부 복사해야 한다는 것이다.
</p>

<p>
이 처럼 구조체를 그냥 사용하면, 프로그램에 부담이 갈 것이다.<br />
(해당 강의에서 다루는 구조체 내의 변수들의 갯수는 적지만 말이다.)
</p>

### 포인터 배열로 변환

<p>
이에 대한 조치를 취하기 위해 구조체들의 배열이였던 directory[]를
포인터 변수를 담는 배열로 바꿀 것이다.
</p>

```c
typedef struct person {
    char *name;
    char *number;
    char *email;
    char *group;
} Person;

Person directory[CAPACITY];
```
<p>
실은 이전 디렉토리에서 포인터 변수를 썻었는데, 그 사용 이유가 바로 이것이다.<br />
directory[]의 자료구조를 그림으로 표현하면 아래처럼 된다.
</p>

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_13-2.png" alt="S1_13-2" />

<p>이전 구절로 돌아와서 포인터 배열을 썻을 때의 코드를 살펴보자.</p>

```c
int search(char *arg1) {         
    print_Person(directory[j]);
    
    return -1;
}

void print_Person(Person *p) {
    printf("name : %s\n", (*p).name);
    printf("number : %s\n", (*p).number);
}

// 일부 코드 생략..
```
<p>
directory[]가 포인터 변수를 담는 배열임으로, print_Person()의 형식 매개변수는 포인터 값이 된다.<br />
이렇게 되면 형식 매개변수로 복사되는 것은 주소 값 하나이기 때문에 이전에 생겼던 부담이 많이 줄어든다.
</p>

<p>
(*p) 부분을 살펴보도록 하자.<br />
접근 지정자(.)를 이용해 구조체 내의 변수에 접근을 하고 있다.<br />
이 때 포인터로 가리키는 구조체의 변수(여기서는 형식 매개변수 *p)에 접근을 해야하기 때문에 저렇게 괄호를 친 것이다.<br />
만약 괄호를 치지 않는다면 구조체 내의 변수(p.name)의 포인터의 의미가 되어버린다.
</p>

### 연산자 ->

<p>(*p).name 와 같은 표현은 상당히 자주 사용된다.</p>

```c
void print_Person(Person *p) {
    printf("name : %s\n", p->name);
    printf("number : %s\n", p->number);
}
```
<p>연산자 ->를 씀으로써 표현을 간단하게 할 수 있다.</p>
