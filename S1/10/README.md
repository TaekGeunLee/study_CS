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

<p>여기서 process_command() 영역을 배운 것을 이용해 고쳐보자.</p>

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

★ 다음에 진행할 계획은 다음과 같다.

- 로컬 파일의 telephone.c 작성 마무리 하기. : 강의에서 내가 기록하지 않은 영역이 있다.
- README.md 작성 마무리.
- section 07~08 훝어보기.