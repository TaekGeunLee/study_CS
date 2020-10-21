### 구조체 배열, init_dir() 수정

```c
typedef struct person {
    char *name;
    char *number;
    char *email;
    char *group;
} Person;

Person ** directory;

void init_dir() {
    directory = (Person **)malloc(CAPACITY * sizeof(Person *));
    capacity = CAPACITY;
}
```
<p>
포인터 변수들을 담는 배열, *directory[]를 선언한다.<br />
init_dir()에서 동적 메모리 할당을 통해 배열을 만들 것이므로, 이중 포인터 타입을 선언한다.<br />
(malloc()를 사용하지 않을거면 Person * directory[CAPACITY]로 선언하면 된다.)
</p>

<p>
init_dir()의 directory 부분을 살펴보자.<br />
복습 삼아서 구술해보면 malloc()를 이용해 Person ** 형태로 동적으로 메모리를 할당한다.<br />
할당한 메모리의 각 셀에는 구조체 Person을 가리킬 포인터 타입 Person * 형태의 데이터가 담겨 있다.
</p>

### add() 함수

```c
void add(char *arg1, char *arg2, char *arg3, char *arg4) {
    if (i > CAPACITY)
        reallocate();

    int n = i-1; // index when i use for sorting array.
    while(n>=0 && strcmp(directory[n]->name, arg1)>0) {
        directory[n+1] = directory[n];
        n--;
    }

    directory[n+1] = (Person *)malloc(sizeof(Person));

    directory[n+1]->name = arg1;
    directory[n+1]->number = strdup(arg2);
    directory[n+1]->email = strdup(arg3);
    directory[n+1]->group = strdup(arg4);
    i++;
}
```

<p>
이전 버전과 로직은 크게 다르지 않다.<br />
다만, directory[]가 포인터 변수를 담는 배열이므로, 인덱스간 이동하는 것도 주소 값에 불과하다.<br />
즉, add() 인자로 받은 항목 데이터들을 담을 실제 그릇을 만들어줘야 한다는 이야기 이다.
</p>


```c
directory[n+1] = (Person *)malloc(sizeof(Person));
```

<p>동적 할당을 이용해 항목 데이터들을 추가할 객체를 만들어준다.</p>

### reallocate() 함수

<p><a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/10">이전 디렉토리</a>에서 만들어줬던 reallocate()에도 큰 변동이 생긴다.</p>

```c
void reallocate() {
    capacity = capacity * 2;

    char **tmp = (Person **)malloc(capacity * sizeof(Person *));

    for (int j=0; j<i; j++)
        tmp[j] = directory[j];

    free(directory);

    directory = tmp;
}
```
<p>
이전 버전에서는 name과 number 배열을 관리해야 했었기 때문에 tmp 배열을 2개나 생성했었다.<br />
(name, number 역시 포인터 주소를 담는 배열이였다.)<br />
DB 역할의 배열을 구조체 배열로 만들었기에 tmp는 하나만 만들었다.
</p>

<p>
게다가 DB directory[]는 구조체들을 가리키는 포인터 배열이기 때문에 자료구조가 달라졌다.<br />
재할당(reallocate)를 수행할 때 구조체들을 바꾸지 않고 이들을 가리키는 포인터 주소만 교체해주면 되기에 
<a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/15">이전 버전</a>에서 느꼈던 부담감이 싹 사라졌다. 
</p>

<p>
복습 삼아서 이것도 기록해보도록 하겠다.<br />
동적 할당으로 생성한 메모리를 더 이상 사용하지 않을 경우, 반드시 변환하는 과정이 필요하다.<br />
free() 함수가 이를 위해 있는 것이다.<br />
만약 재변환 과정을 거치지 않으면 컴퓨터 메모리의 <a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/6">heap 영역</a>에 점차 쌓이게 되어 꽉 차버리는 가능성이 생긴다.
</p>

<p>
동적 할당으로 만들지 않는 메모리(지역, 전역 변수)에 대해서는, 프로그램 혹은 함수의 실행이 마치면 자동으로 소멸되기 때문에
신경 쓰지 않아도 된다.<br />
결론으로 <b>동적 할당으로 생성한 메모리에 대해선 재환원 하는 것도 고려해야 한다</b>는 뜻이다.
</p>

### drop() 함수

<p>바로 이전 구절에서 적었던 결론을 상기하면서 이번 구절을 작성하겠다.</p>

```c
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
```
<p>
문자열 복사 함수 <a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/4-1">strdup()</a>는 내부적으로 동적 할당 작업을 사용한다.<br />
add() 함수에서 데이터를 추가할 때 strdup()를 썼었으므로 제거할 때에도 재환원 작업을 거쳐야 한다.<br />
search()를 이용해 제거할 대상의 인덱스를 찾은 뒤에, 해당 인덱스를 가리키는 포인터 변수, p를 선언한다.<br />
이렇게 선언한 p는 후술할 relase_person()의 인자로 삼게 되는데..
</p>

```c
void relase_person(Person *p) {
    free(p->name);
    free(p->number);
    free(p->email);
    free(p->group);
    free(p);
}
```
<p>
제거 대상(구조체)의 각 항목들을 전부 환원한 뒤에 구조체를 환원해준다.<br />
각 항목에 들어있었던 문자열들도 add()에서 strdup()를 통해 추가된 문자열들이기에 이들도 환원을 해줘야 한다.<br />
이 작업을 거치지 않고 구조체만을 환원해도 각 항목의 문자열에 해당하는 메모리는 그대로 남는다.
</p>