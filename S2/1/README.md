<p>
구조체에 대해선 이미 <a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/11">해당 레퍼토리</a>에서 처음 접했었다.<br />
여기서는 추가적으로 내가 안 사항들을 위주로 정리를 하겠다.
</p>

### 구조체 선언하기

<p>
struct 키워드를 사용해 구조체를 선언한다.<br />
이는 data structure의 약자라고 한다.
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
