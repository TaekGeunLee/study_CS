### read_line() 수정하기

read_line()은 scanf()의 역할을 대신하여 프롬프트의 한 줄을 입력받는 커스텀 함수 였다.
이전 버전에서는 키보드로부터 입력받는 문자열만 인식했었지만, 이번에는 파일로부터로도 인식할 수 있게 해보자.

```c
int read_line(FILE *fp, char *str, int limits) {
    int ch, n = 0;

    while((ch = fgetc(fp)) != '\n' && ch != EOF)
        if (n < limits-1)
            str[n++] = ch;

    str[n] = '\0';
    return n;
}
```
read_line()의 매개변수로 스트림 형태의 변수 fp를 받을 수 있게 하였다.
FILE *fp로부터 'stdin'을 받으면 키보드, 파일 타입의 변수를 입력받으면 파일의 문자열 타입으로 인식하게 될 것이다.
이것은 while문 조건절의 fgetc()가 담당한다.

이것으로 프롬프트의 명령어 뿐 만 아니라 외부 파일의 문자열을 load 할 때에도 read_line()을 사용할 수 있게 되었다.

```c
void load(char *filename) {
    char buf[BUFFER_SIZE];
    char *name, *number;

    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
        printf("Open failed.\n");

    while (1) {
        if (read_line(fp, buf, BUFFER_SIZE) <= 0)
            break;
        name = strtok(buf, delim);
        number = strtok(NULL, delim);
        printf("name : %s, number: %s\n", name, number);
        add(name, number);
    }
    fclose(fp);

    printf("loading data complete!\n");
}
// read 명령어를 입력했을 때 실행됨.
```
load() 내의 read_line() 영역을 살펴보자.
이전에는 fgets()를 사용해 파일(fp)를 읽는 식으로 운용했었다.
하지만 read_line()이 파일까지 읽을 수 있게 되면서 이를 재활용했다.

read_line()으로 읽어들인 문자열을 토큰화하여 각각 지역변수 name, number에 할당하였다.

### 구조체 선언

<a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/11">이전 디렉토리</a>에서 다뤘었던 구조체를 이용해 새로이 DB 역할의 배열을 조정해보자.

```c
/* 이전 코드
    char *name;
    char *number;
*/

typedef struct name {
    char **name;
    char **number;
} Person;

Person directory[capacity];
```

email, group등의 새 항목은 나중에 작성해보도록 해보자.

```c
/* before
while(n>=0 && strcmp(name[n], arg1)>0) {
    name[n+1] = name[n];
    number[n+1] = number[n];
    n--;
}
*/
while(n>=0 && strcmp(directory[n].name, arg1)>0) {
    directory[n+1] = directory[n];
    n--;
}
```

다음은 구조체 변수에 맞춰서 수정한 add() 내의 일부이다.
Person 구조체를 담아둔 directory 배열을 통해 연관 있는 배열들을 묶었기 때문에
directory[] 만으로 코드를 수정할 수 있다.
다만, directory의 개별 요소에 접근을 해야하는 경우에는 따로 접근 지정자(.)를 써서 작성을 해야만 한다.
이런 식으로 전체 프로그램을 고친다. 여기까지의 수정사항은 telephone_07.c에 저장한다.