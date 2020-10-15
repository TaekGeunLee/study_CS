<p>
전화번호부 3.0에서 새로이 추가할 기능은 다음과 같다.<br />
여기서는 구조체에 관한 간단한 설명만 다룰 것이다.
</p>

<ul>
<li>이전엔 사용자 이름(name)과 전화번호(number) 까지만 저장했었다.<br />이메일, 좋아하는 색깔 등 더 많은 항목을 추가할 수 있도록 해보자.</li>   
<li>커스텀 함수 read_line()의 조정</li>
<li>저장(save as), 로드(load) 할 때 사용되는 txt 파일의 템플릿 규격 수정</li>  
<li>입력 프롬프트를 개선시킨다. <a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/3">이전 예제</a>를 활용해서, 이름을 입력할 때 불필요한 공백을 한 칸의 공백만 남기도록 하자.</li>   
</ul>

### 구조체(structure)

<p>
DB 역할을 담당하는 배열들을 하나의 그룹으로 묶어서 선언해보도록 하자.<br />
이렇게 관련있는 변수끼리 묶은 자료구조를 <b>구조체(structure)</b> 라고 부르자.<br />
다음은 구조체를 사용해서 여러 항목을 구현했다.
</p>

```c
#define CAPACITY 110;

typedef struct person {
    char *name;
    char *number;
    char *email;
    char *group;
    // char group[];와 같다.
} Person;

Person directory[CAPACITY];
```

<p>
구조체 Person으로 관련 있는 변수들 끼리 묶었다.<br />
이전 방식대로 하면 연관성 있는 배열들을 분산시켜서 코딩하는 실수를 유발할 수도 있으므로, 가독성 면에서도 떨어진다.<br />
객체 지향 언어의 객체와 유사하다.
</p>

<p>
이후 Person 구조체 타입의 배열 directory[]를 선언했다.<br />
이는 구조체를 담아내는 배열이다. 라고 생각하면 된다.<br />
Person 타입은 먼저 구조체로 묶을 때 선언한 커스텀 타입으로, 이름은 언제든지 바꿀 수 있다.<br />
directory[] 구조를 그림으로 표현하면 다음과 같다.
</p>

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_11-1.png" alt="S1_11-1" />

<p>구조체의 각 항목에 접근하기 위해서는 다음과 같이 작성하면 된다.</p>

```c
directory[3].name // directory의 3번째 요소의 name 항목에 접근
directory[0].email
```
<p>Java에서 객체의 속성과 메서드에 접근하는 것 처럼 접근 지정자(.)를 사용하면 된다.</p>