<a href="">이전 레퍼토리</a>에서 이어진다.

### 여러 항목 추가

```c
typedef struct person {
    char ** name;
    char ** number;
    char ** email;
    char ** group;
} Person;
```

구조체 person에 새로운 항목, email, group를 추가했다.
이에 맞춰서 add를 실행할 때의 코드도 수정을 해줘야 한다.
이전 코드에 따르면, email, group에 대한 토큰 변수도 생성해줘야 하지만, 이렇게 하면 수정해야할 게 많아진다.
따라서 명령 프롬프트 방식을 이렇게 바꿔준다.

<img src="#" alt="S1_15-1" />

name을 제외한 모든 항목에 대한 입력 프롬프트 처리를 담당하는 함수, handle_add()를 선언해보자.

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
해당 함수는 add()를 호출하는 process_commend() 내의 조건절에서 쓰인다.

```c
if (strcmp(command, "add") == 0) {
    argument1 = strtok(NULL, delim); // name

    handle_add(argument1);
    //add(argument1, argument2);
}
```
기존에 add 명령어에 대한 함수는 handle_add()의 내부에서 처리될 것이다.
그리고 name을 제외한 모든 항목에 대해서는 빈 항목이 존재할 수 있도록 코딩하기로 했었다.

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
handle_add() 내의 호출된 add()를 약간 수정한다.
프롬프트에 name을 제외한 항목들에 빈 항목을 입력했을 경우 그 문자열 길이는 0 이다.
이에 대한 조건절을 이용해 0 미만이면 빈 문자열인 empty를 추가하도록 한다.
이 구절에서 끝나지 않고 수정해야 하는 문단은 조정한다.

### 공백 최소화
