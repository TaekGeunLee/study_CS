<p>
<a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/8">이전</a>에 다음과 같이 전체 코드를 init_dir()과 process_command()로 분리했었다.
</p>

```c
int main() {
    init_dir(); // 변수 *name, *number 재할당
    process_command(); // 명령어 처리 함수
    return 0;
}
```

<p>여기서 process_command()를 배운 것을 이용해 고쳐보자.</p>

```c
void process_command() {
    char command_line[BUFFER_SIZE];
    char *command, *argument1, *argument2;
    
    while(1) {
        printf("$ ");
        
        if (read_line(command_line, BUFFER_SIZE) <= 0)
            continue;
        // 아무것도 입력하지 않았을시, 해당 반복 루틴을 건너뛰고 다음 루틴을 실행.
    
        command = strtok(command_line, delim); // delim = " ". 전역 변수로 선언.
    }
}
```

<p>
<a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/8">read_line()</a>을 통해 명령어를 입력받는다.<br />
프롬프트에 명령어(command_line)을 입력하면, 대상 명령어를 세 개의 요소로 토큰화할 것이다.<br />
예시로 load dir.txt 라고 입력했을 시, *command => load, *argument1 => dir.txt가 되는 것이다.
</p>

```c
if (strcmp(command, "add") == 0) {
    argument1 = strtok(NULL, delim);
    argument2 = strtok(NULL, delim);
    
    if (argument1 == NULL || argument2 == NULL)
        printf("invailed arguments.");
        continue;
    add();
} else if (strcmp(command, "show") == 0) {
    show();
}
// ... 이하 생략
```

<p>
command_line을 토큰화해서 생긴 command 토큰을 이용해 명령어 색출 작업을 한다.<br />
각 명령어 마다 필요로 하는 인자의 갯수는 서로 다르므로, 조건마다 인자들(argument1, argument2)에 관한 작업을 작성해준다.
</p>


```c
void add(char *arg1, char *arg2) {
    int n = i-1; // index when i use for sorting array.
    while(n>=0 && strcmp(name[n], arg1)>0) {
        name[n+1] = name[n];
        number[n+1] = number[n];
        n--;
    }
    name[n+1] = strdup(arg1);
    number[n+1] = strdup(arg2);
    i++;
    printf("i : %d\n", i);
}
```

<p>
scanf() 대신 자체 커스텀 함수인 read_line()으로 쓰면서, 각 명령어 함수에도 약간의 변화가 생긴다.<br />
명령어(command_line)을 토큰화 하는 것이기에, 함수의 매개변수로써 command_process()에서 얻은 문자열 토큰들을 넣어줘야 한다.<br />
이런 식으로 다른 함수들도 바꿔준다.
</p>

### read() : 외부 파일 불러오기

<p>
<a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/7">이전</a>에 load 명령어를 이용해 파일을 읽어서 전화번호부에 정보를 저장했었다.
load 명령어가 동작하는 함수를 고쳐보자.
이번에는 load 명령어를 read 명령어로써 바꿀 것이다.
</p>

```c
else if (strcmp(command, "read") == 0) {
    argument1 = strtok(NULL, delim); // filename for load.

    if (argument1 == NULL) {
            printf("enter the filename.\n");
            continue;
        }
    load(argument1);
}
// process_command()
```

<p>명령어를 처리하는 process_command()에서 'read' 명령어를 입력받았을 때, 조건에 따라 load() 함수를 실행토록 할 것이다.</p>

```c
void load(char *filename) {
    char loadName[BUFFER_SIZE];
    char loadNumber[BUFFER_SIZE];

    FILE *fp = fopen(filename, "r");

    while (fscanf(fp, "%s", loadName) != EOF) {
        fscanf(fp, "%s",loadNumber);
        add(loadName, loadNumber);
        i++; // 실수. add()에서 이미 처리하므로 없애버리도록 하자.
    }
    fclose(fp);

    printf("loading data complete!\n");
}
```

<p>
수정 전의 load()에서는 scanf()를 이용해 argument1, argument2 토큰에 해당하는 문자열을 입력받았었다.<br />
process_command()에서 이미 명령어 토큰화 작업을 거쳤음으로 불필요한 코드는 없애주도록 한다.<br />
가장 눈에 띄는 것은 외부 파일을 load한 이후 DB 배열에 데이터를 추가하는 부분이다.<br />
이를 add() 함수를 재활용함으로써 코드를 정리하였다.
</p>

### drop() : 데이터 지우기

<p><a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/5">다음 디렉토리</a>에서 구현했었던 drop()도 살펴보도록 하자.</p>

```c
// before
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

// after
void drop(char *arg1) {
    int index = search(arg1);

    if (index < 0)
        return;

    for (int j=index; j<i-1; j++) {
        name[j] = name[j+1];
        number[j] = number[j+1];
    }
    i--;
}
```
<p>
다음은 수정 이후의 drop()이다.<br />
이전 구절의 load()의 경우처럼 함수를 재활용하였다.<br />
search()는 원래 void 타입의 함수였지만, 인자로 받은 문자열이 위치한 인덱스 번호를 리턴하도록 재조정하였다.
</p>

```c
int search(char *arg1) {
    int index = 0;
    for (int j=0; j<i; j++)
        if (strcmp(arg1, name[j]) == 0) {
            index = j;
            printf("target number : %s | target index : %d\n", number[j], index);
            return index;
        }
    return -1;
}
```

<p>
다음은 수정한 search() 이다.<br />
타깃을 찾지 못할 경우, -1를 리턴하도록 했다.<br />
이는 drop()에서 타깃을 필터링 하는 용도로 쓰이게 될 것이다.
</p>

### reallocate() : 배열 재할당
<p>
마지막으로 add() 함수 동작 도중 DB 담당의 배열이 가득 찼을 경우, 새로운, 할당량이 더 많은 배열로 교체하도록 코드를 짜보자.<br />
배열 재할당의 작업을 담당하는 reallocate()는 add() 내에서 재활용하게 될 것이다.<br />
관련 예제는 이미 <a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/8">여기서</a> 다루었다.
</p>

```c
int capacity = 50; // 최대 배열 할당량
int i = 0; // 인덱스

void add(char *arg1, char *arg2) {
    if (i > capacity)
        reallocate();
// ..이하 생략 
}
```

<p>add() 함수 내에서 현재 루틴의 i값이 최대 할당량(capacity)을 넘었을 경우, reallocate()를 실행토록 할 것이다.</p>

```c
void reallocate() {
    capacity = capacity * 2;
    // 최대 수용량을 늘린다.

    char **tmp1 = (char **)malloc(capacity * sizeof(char *));
    char **tmp2 = (char **)malloc(capacity * sizeof(char *));
    // 동적 할당.

    for (int j=0; j<i; j++) {
        tmp1[j] = name[j];
        tmp2[j] = number[j];
    }

    free(name);
    free(number);

    name = tmp1;
    number = tmp2;
    // 이미 가득 차버린 배열을 가리킬 포인터 변수(즉, 배열 이름)을 교체하는 작업.
}
```
<p>
다음은 reallocate()의 전문이다.<br />
최대 수용량을 늘린 뒤에 두 개의 포인터 변수를 동적 할당 하였다.<br />
변수 **tmp1, **tmp2는 name, number를 대신할 저장공간이다.
</p>

<p>name, number에 있었던 요소들을 tmp1, tmp2로 빼낸 뒤에 배열을 가리킬 포인터 변수를 새 것으로 교체한다.</p>

<p>
free()는 malloc()의 반대 개념으로, 동적 할당한 메모리 공간을 다시 반환하는 함수이다.<br />
이 작업을 거치지 않으면 프로그램에 더 이상 쓰지 않는 쓰레기(garbage) 공간이 쌓인다.<br />
최적화 작업을 위해서라면 반드시 거쳐야만 한다.
</p>