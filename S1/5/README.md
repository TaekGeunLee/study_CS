<p>이전 디렉토리에서 다음 명령들을 함수 단위로 구현한다고 했었다.</p>

* add : 사용자 정보를 추가
* drop : 정보 제거
* show : 전화부에 기록된 모든 정보를 열람
* search : 콘솔에 입력한 사용자의 전화 번호를 출력
* exit : 프로그램을 종료

add() 함수의 구현은 이미 했다. 이번 디렉토리에서는 나머지 기능들을 구현하도록 하겠다.

### drop - 정보 제거

<p>
C언어에서 배열 내의 특정 원소만을 없애서 해당 인덱스를 빈 자리로 만들지는 못한다.<br />
해당 함수를 구현하기 위한 전략으로, 입력받은 문자열과 배열의 모든 원소를 전부 비교한 뒤 같은 게 있다면
자리를 치환하는 것을 생각해볼 수 있다.
</p>

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_5-1.png" alt="S1_5-1" />

<p>
위와 같이 삭제할 대상 인덱스를 맨 뒤(코드 상에서는 int i)로 빼주고, i값을 하나 줄일 것이다.<br />
코드는 다음과 같다.
</p>

```c
void drop() {
    char buf1[BUFFER_SIZE];
    scanf("%s", buf1);
    
    for (int i=0; i<n; i++) {
        if (strcmp(buf1, name[i]) == 0) {
            name[i] = name[n];
            number[i] = number[n];
            n--;
            break;
        }
    }
};
// telephone_3.c
```
<p>
if 조건절을 살펴보면 strcmp()를 이용해 문자열을 비교해주는 것을 관찰했었다.<br />
해당 라이브러리 함수 없이 코드를 작성했지만 원하는 대로 실행이 되지 않았었다.<br />
이에 대해선 아직 잘 모르는 게 없으니 아직은 함수를 쓰는 것으로 하자.
</p>

### show, search

<p>특별한 어려움 없이 작성할 수 있다.</p>

```c
void show() {
    for (int i=0; i<n; i++)
        printf("%s %s\n", name[i], number[i]);
};

void search() {
    char buf1[BUFFER_SIZE];
    scanf("%s", buf1);

    for (int i=0; i<n; i++) {
        if (strcmp(buf1, name[i]) == 0) {
            printf("%s\n", number[i]);
            break;
        }
    }
};
```
