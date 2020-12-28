<p>
구조체에 대해선 이미 <a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/11">해당 레퍼토리</a>에서 처음 접했었다.<br />
여기서는 추가적으로 내가 안 사항들을 위주로 정리를 하겠다.
</p>

### 구조체 선언하기

<p>
struct 키워드(data structure의 약자)를 사용해 구조체를 선언한다.<br />
실제 메모리에는 <b>구조체 내 멤버 변수들 중 가장 큰 변수형의 크기만큼 할당</b>된다.<br />
</p>

```c
struct Person {
    char name[15];
    int age;
    int number;
};
// 반드시 뒤에 세미콜론(;)을 붙이도록 한다.
```

<p>
이렇게 생성한 구조체를 사용하기 위해선 구조체 변수를 선언해줘야 한다.<br />
객체 지향 언어에 비유하자면 인스턴스(instance)에 해당된다.
</p>

```c
struct Person {
    char name[15];
    int age;
    int number;
} p1;
```

<p>구조체 뒤에 변수를 쓰는 식으로 구조체 변수를 만들 수 있다.</p>

```c
struct Person {
    char name[15];
    int age;
    int number;
};

int main() {
    struct Person p1;
    struct Person p2;
    
    return 0;
}
```
<p>
main() 함수 부분을 살펴보자.<br />
여러 개의 구조체 변수를 선언하고 싶을 경우 다음과 같은 방법을 선택할 수 있다.
</p>

```c
struct Person p1 = { .name="Mina", .age=24, .number=5500}
```
<p>
중괄호를 이용해 구조체 변수를 선언하는 동시에 특정 값으로 초기화 할 수도 있다.<br />
반드시 점(.)을 붙여야 한다는 것에 주의를 하도록 하자.<br />
위의 방법을 사용할 떄에는 멤버들의 순서를 전부 지킬 필요가 없으며, 
모든 멤버 값을 할당할 필요도 없다.
</p>

<p>이런 식으로 기존 일반 데이터 형을 조합하여 만든 형을 파생형(derived type) 이라고 한다.</p>

### typedef : 사용자 정의 타입

<p>
typedef는 특정 자료형에 별칭(alias)를 부여하는 키워드이다.<br />
예를 들어서 int형을 해당 키워드를 이용해 MYINT형으로 이름을 사용할 수 있는 것이다.
</p>

```c
typedef struct _Fruit {
    char name[20];
    char flavor[20];
    int seed;
} Fruit;

/*
struct _Fruit {
    char name[20];
    char flavor[20];
    int seed;
}
*/
```

<p>
굳이 구조체에 별칭을 달아주는 이유? 라고 생각했다.<br />
일반적이라면 구조체 변수를 선언할 때 마다 앞에 struct를 붙여줘야만 한다.<br />
typedef를 사용하게 되면 그런 번거로움을 생략할 수 있다는 것이다. 
</p>

```c
struct Fruit p1;
Fruit p1;

// 위의 각 두 문단은 서로 같은 의미이다.
```

<p>
착각할 수 있는 것으로 typedef는 식별자가 아닌 변수 형에다가 별칭(alias)을 달아주는 것이다.<br />
이렇게 typedef로 만든 별칭을 <b>사용자 정의 타입</b> 이라고도 부른다.
</p>

### typedef : 구조체 이름 생략하기

<p>typedef를 이용해 구조체를 선언한 상태라면, 구조체 이름을 생략할 수 있다.</p>

```c
typedef struct {
    char name[20];
    char flavor[20];
    int seed;
} Fruit;

Fruit f1;
```

<p>
앞 구절에서는 구조체 이름을 _Fruit로 했었다.<br />
(struct 뒤에 붙는 구조체 이름을 태그(tag) 라고도 지칭한다.)<br />
이러한 이름을 생략한 대신 구조체 변수에는 typedef로 만든 사용자 정의 타입, Fruit를 사용한다.
</p>