<p><a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/12">이전 레퍼토리</a>에서 이어진다.</p>

### 여러 항목 추가

```c
typedef struct person {
    char ** name;
    char ** number;
    char ** email;
    char ** group;
} Person;
```
<p>
구조체 person에 새로운 항목, email, group를 추가했다.<br />
이에 맞춰서 add를 실행할 때의 코드도 수정을 해줘야 한다.<br />
이전 코드에 따르면, email, group에 대한 토큰 변수도 생성해줘야 하지만, 이렇게 하면 수정해야할 게 많아진다.<br />
따라서 명령 프롬프트 방식을 이렇게 바꿔준다.
</p>

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_15-1.PNG" alt="S1_15-1" />

<p>name을 제외한 모든 항목에 대한 입력 프롬프트 처리를 담당하는 함수, handle_add()를 선언해보자.</p>

```c
void handle_add(char *name) {
    char number[BUFFER_SIZE], email[BUFFER_SIZE], group[BUFFER_SIZE];
    char empty[] = " ";

    printf("number : ");
    read_line(stdin, number, BUFFER_SIZE);

    printf("email : ");
    read_line(stdin, email, BUFFER_SIZE);

    printf("group : ");
    read_line(stdin, group, BUFFER_SIZE);

    add(name, number, email, group);
    );
};
```
<p>해당 함수는 add()를 호출하는 process_commend() 내의 조건절에서 쓰인다.</p>

```c
if (strcmp(command, "add") == 0) {
    argument1 = strtok(NULL, delim); // name

    handle_add(argument1);
    //add(argument1, argument2);
}
```
<p>
기존에 add 명령어에 대한 함수는 handle_add()의 내부에서 처리될 것이다.<br />
그리고 name을 제외한 모든 항목에 대해서는 빈 항목이 존재할 수 있도록 코딩하기로 했었다.
</p>

```c
void handle_add(char *name) {
    char empty[] = " ";

    add(name, 
    (char *)(strlen(number)>0 ? number : empty), 
    (char *)(strlen(email)>0 ? email : empty), 
    (char *)(strlen(group)>0 ? group : empty)
    );
};
```
<p>
handle_add() 내의 호출된 add()를 약간 수정한다.<br />
프롬프트에 name을 제외한 항목들에 빈 항목을 입력했을 경우 그 문자열 길이는 0 이다.<br />
이에 대한 조건절을 이용해 0 미만이면 빈 문자열인 empty를 추가하도록 한다.<br />
이 구절에서 끝나지 않고 수정해야 하는 문단은 조정한다.
</p>

### 공백 최소화

<p>
명령 프롬프트에 이름을 입력하면서 불필요한 공백까지 작성할 경우, 최소한의 공백만 남기고 나머지 공백들은 없앤다.<br />
외부 함수 compose_name()을 선언한다.
</p>

```c
int compose_name(char *str, int limits) {
    char *ptr;
    int length = 0;

    ptr = strtok(NULL, " ");

    if (ptr == NULL) {
        return 0;
    }

    strcpy(str, ptr);
    length += strlen(ptr);

    while((ptr = strtok(NULL, " ")) != NULL) {
        if (strlen(ptr)+length+1 < limits) {
            str[length] = ' ';
            length += 1;
            str[length] = '\0';
            strcat(str, ptr);
            length += strlen(ptr);
        }
    }
    return length;
}
```

<p>
함수의 인자로 문자열(str)과 문자열 최대 길이(limits)를 받게 된다.<br />
지역변수 ptr를 선언하면서 토큰화를 진행한다.<br />
쪼갠 문자열을 인자 str에 병합(strcat) 하면서 공백 최소화 작업을 진행한다.<br />
결과물은 인자 str에 할당되며, str에 할당된 결과 문자열의 길이(length)를 리턴하게 된다.
</p>

<p>
compose_name()을 다 쓰고 난 뒤에, 해당 함수를 호출할 위치를 선정하는 과정에서 여러가지 헤멨었는데,
그 헤맸던 과정을 적고자 한다.
</p>

```c
char command_line[BUFFER_SIZE];
char *command, *argument1;

while(1) {
    printf("$ ");
    if (read_line(stdin, command_line, BUFFER_SIZE) <= 0)
        continue;

    command = strtok(command_line, delim);
          
    if (strcmp(command, "add") == 0) {
        argument1 = strtok(NULL, delim);

        if (compose_name(argument1, BUFFER_SIZE) <= 0) {
            printf("enter name.\n");
            continue;
        }
        handle_add(argument1);
```

<p>
다음은 잘못된 코드이다.<br />
처음 프롬프트에 입력한 명령어를 토큰화 하면 제일 먼저 명령어(command) 영역이 토큰화 된다.<br />
이 상태에서 토큰화를 한 상태의 변수(argument1)를 compose_name()의 인자로 삼았다.<br />
여기서 문제가 되는 것이, compose_name() 내에서 다시 한번 더 토큰화를 해서 ptr 변수에 할당한다는 것이다.
</p>

<p>
예를 들어 토큰화 대상 문자열 'Lee'를 토큰화 한 상태에서 변수 argument1에 토큰 'Lee'가 들어 있는 상태라면
변수 ptr에는 null 값이 들어가게 된다.<br />
이렇게 되면 원치 않는 결과를 보게 될 것이다.
</p>

<p>따라서 이렇게 수정한다.</p>

```c
char command_line[BUFFER_SIZE];
char *command, *argument1;
char name_str[] = " ";

while(1) {
    printf("$ ");
    if (read_line(stdin, command_line, BUFFER_SIZE) <= 0)
        continue;

    command = strtok(command_line, delim);
          
    if (strcmp(command, "add") == 0) {
        if (compose_name(name_str, BUFFER_SIZE) <= 0) {
            printf("enter name.\n");
            continue;
        }
        handle_add(name_str);
```
<p>
compose_name()의 인자로 빈 공백 값인 name_str를 넣었다.<br />
빈 값을 넣어버리면 더 이상 토큰화를 할 수 없지 않아? 라고 생각했다.<br />
<a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/9">strtok()의 원리</a>를 떠올렸을 때, 토큰화 중인 문자열을 가리키는 포인터 변수의 자료구조를 그림으로 나타내면 다음과 같이 된다.
</p>

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_15-2.PNG" alt="S1_15-2" />

<p>
즉, strtok()로 서로 다른 변수들의 할당을 번갈아가면서 토큰화를 진행할 수 있다는 것이다.<br />
이런 식으로 나머지 코드들을 고친다.
</p>

### 외부 파일 템플릿 수정

<p>
현재 파일 템플릿에는 name과 number 항목 형식만 기록되어 있다.<br />
이번 버전에서 새로 추가된 항목 형식도 저장할 수 있도록 템플릿을 조정하도록 한다.
</p>

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_15-3.png" alt="S1_15-3" />

<p>
구분 문자(#)를 둠으로써 사용자의 각 항목 데이터를 구분하도록 한다.<br />
위의 수정할 템플릿 형식에 맞춰 save와 load 명령어에 대한 함수도 수정해줘야 한다.
</p>


```c
void saveAs(char *filename) {
    FILE *fp = fopen(filename, "w");

    for (int j=0; j<i; j++) {
        fprintf(fp, "%s#", directory[j].name);
        fprintf(fp, "%s#", directory[j].number);
        fprintf(fp, "%s#", directory[j].email);
        fprintf(fp, "%s\n", directory[j].group);
    }

    fclose(fp);
    printf("save file complete!\n");
}
```

<p>
이런 흐름으로 load 명령어 함수도 수정해준다.<br />
여기까지의 진행 사항은 telephone_08.c에 저장했다.
</p>