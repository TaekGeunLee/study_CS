<p>
이제까지 배웠던 개념을 이용해 간단한 전화부 프로그램을 만들어보자.<br />
사용자의 이름과 전화번호를 관리하는 간단한 DB 시스템을 만드는 것이다.
</p>

<p>
만들 프로그램은 기초적인 CRUD 기능만 가지고 있다.<br />
콘솔로 특정 명령어를 입력하면 사용자 정보를 추가하거나 수정을 가한다.<br />
이전에 MongoDB를 학습할 때 Mongo Shell로 데이터를 관리했었던 경험이 있었을 것이다.<br />
그것이 바로 이것이다.
</p>

### 구현할 기능

<p>구현할 기능은 다음과 같다. 아래의 리스트에 해당하는 명령어를 입력하면 해당 기능이 실행할 것이다.</p>

<ul>
<li>add : 사용자 정보를 추가</li>
<li>drop : 정보 제거</li>
<li>show : 전화부에 기록된 모든 정보를 열람</li>
<li>search : 콘솔에 입력한 사용자의 전화 번호를 출력</li>
<li>exit : 프로그램을 종료</li>
</ul>

<p>
각 기능들은 함수로 구현하게 될 것이다.<br />
각 기능들을 제외한 메인 소스 코드의 일부는 다음 처럼 된다.
</p>

```c
    char command[BUFFER_SIZE];

    while(1) {
        printf("$ ");
        scanf("%s", command);
        
        if (strcmp(command, "add") == 0) {
            add();
        } else if (strcmp(command, "drop") == 0) {
            drop();
        } else if (strcmp(command, "show") == 0) {
            show();
        } else if (strcmp(command, "search") == 0) {
            search();
        }
            
        printf("%s\n", command);
    }
// telephone_1.c
```
<p>
if-else 문을 이용해 각 명령어 별로 실행할 명령어 함수를 분기화 시킨다.<br />
strcmp()는 인자로 받은 함수들을 비교하는 함수로, 서로 일치 시 0을 리턴한다.
</p>

### add : 사용자 정보 추가하기

<p>첫 번째 기능, add 함수를 구현해보자.</p>

```c
void add() {
    char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];

    scanf("%s", buf1);
    scanf("%s", buf2);

    name[n] = strdup(buf1);
    number[n] = strdup(buf2);
    n++;

    printf("add %s info completed.\n", buf1);
};
// telephone_2.c
```
<p>
다음은 함수 add()의 일부분이다.<br />
프로그램이 실행되는 곳인 main() 함수에서 add 명령어가 감지되면 해당 함수가 실행된다.<br />
add1()에서는 두 개의 문자열을 입력(input) 받는데, buf1(name)과 buf2(number)가 이것이다.    
</p>

<p>
예를 들어 Lee의 정보를 입력한다고 가정한다면 '$ add Lee 12340000' 이런 양상일 것이다.<br />
입력받은 두 개의 문자열은 복사된 뒤 각각 name[]과 number[]의 n번째 인덱스에 할당된다.<br />
(복사하지 않으면 데이터가 축적되지 않는다. 이전 디렉토리 참고.)    
</p>

<p>
맨 처음 name[]과 number[]는 포인터 변수로써 선언한 뒤 이므로
해당 배열 내에는 주소가 할당된다.    
</p>
