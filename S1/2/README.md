### 문자열(string) 생성

<p>문자열은 배열 형태로 저장된다.</p>

```C
char str[6];

str[0] = 'm';
str[1] = 'a';
str[2] = 'n';
str[3] = 'g';
str[4] = 'o';
str[5] = '\0'; // 문자열의 끝을 알리는 이스케이프 문자. 반드시 사용한다.
```

<p>
위의 예제 대로라면 str는 'mango' 문자열을 할당하게 되는 것이다.<br />
축약형의 일종으로 아래와 같이 써도 된다.
</p>

```c
char str[] = 'mango';
char *str = 'mango'; // string literal. 수정할 수 없는 배열.
```

<p>
<a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/1">이전 레퍼토리</a>에서 배웠듯이, 배열의 이름은 첫 번째 인덱스를 가리키는 포인터 변수와 마찬가지.. 라고 익혔었다.<br />
따라서 str[]를 생성했을 때 같이 만들어지는 포인터 변수 *str은 배열의 첫 번째 인덱스인 'm'이 담겨진 인덱스의
주소를 가리키게 되는 것이다.
</p>

<p>
만약 배열이 아닌 포인터 형식으로 배열을 초기화 했을 경우 그 이후에는 수정할 수 없다.<br />
이는 여기, 문자열에서도 마찬가지이다.
</p>

### 예제 1

<p>
여러 개의 문자열을 입력받아 저장하는 예제를 작성해보자.<br />
자료구조를 그림으로 표현해보면 다음과 같다.
</p>

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_2-1.PNG" alt="S1_2-1" />

<p>
제일 먼저 입력 받은 문자열들을 담아둘 문자열(buffer)과 
이렇게 담아둔 문자열을 저장할 배열(words)를 선언한다.
</p>

```c
char *words[100];
char buffer[100];
```

<p>
착각하지 말아야 할 것이, 배열을 생성하면 words 포인터 변수가 생성된다고 해서
*words[100] 나 words[100] 가 서로 똑같지 않아? 라고 생각을 하면 안된다.<br />
단지 데이터의 주소값을 담느냐, 데이터를 담느냐 의 차이일 뿐이다.<br />
다음은 반복문을 작성한다.
</p>

```c
int n = 0;
while(n<4 && scanf("%s", buffer) != EOF) {
    words[n] = ??
    n++
}
```
<p>
scanf()의 두 번째 인자에 주목해보자.<br />
일반적이라면 &#38;buffer 라고 쓰는 것이 맞겠지만, 문자열의 첫 번째 인덱스 번지를 가리키는 포인터 변수 buffer를 썻다.<br />
그 이유는 맨 위의 자료구조 형태를 보듯이, words의 각 셀에 buffer에 입력받은 문자열 전체를 할당하는 것이 아닌 buffer의 첫 번째 자리만
참조하는 식으로 코드를 작성할 것이기 때문이다.<br />
'왜 이렇게 불편하게 쓰는거야!! 그냥 셀 안에 buffer를 넣으면 땡 아니야?' 라고 생각을 했었지만, 그렇게 하면 1 byte의 크기의 셀 안에 buffer로 입력받은 문자열을 전부 넣기에는 공간이 부족한 것이다.
</p>

<p>
이제 주목할 것은 다음 영역이다.
</p>

```c
words[n] = ??
```

<p>
?? 안에는 무엇이 들어갈까.<br />
buffer를 쓰면 되겠지. 라고 생각했지만, 그렇게 하면 다음과 같은 결과가 도출되어 버린다.
</p>

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_2-2.PNG" alt="S1_2-2" />

<p>
현 시점에서 JS만 쓰다가 C로 넘어가서 이해하기 어려울 수도 있겠지만,
C언어는 컴파일러, 즉 전체 코드를 해석한 뒤에 결과를 도출하기 때문에 저런 결과가 발생하는 것이다.<br />
따라서, 이에 대해선 문자열을 하나 더 복사를 하는 strdup() 함수를 사용할 것이다. (string.h 내의 함수)
</p>

<p>
strcpy()를 써야 하지 않아? 싶겠지만, words[]를 이미 주소를 할당하는 배열로써 선언했기 때문에
메모리의 주소값을 복사하는 strdup()를 쓰는 것이다.
</p>

### 파일 읽고 쓰기

<p>
node.js 에서 fs 모듈로 파일을 읽고 썼었던 것 처럼 여기에서도 해보도록 하자.<br />
제일 먼저 다음 구문을 입력한다.
</p>

```C
FILE *fp = fopen("input.txt", "r"); // input.txt를 읽겠다고 세팅을 한다.
fclose(fp);
```
<p>
자료형 FILE 타입의 포인터 변수 fp를 선언하면서 함수 fopen()을 호출하였다.<br />
FILE 타입을 사용할 때에는 반드시 포인터 변수로 선언해야 한다! 라고 일단 그렇게 알고 있자.<br />
fopen(), fclose()는 파일을 열고(open) 닫는(close) 함수이다.<br />
파일에 관련된 작업을 하기 위해선 반드시 파일을 열어서 어느 작업을 할 지에 대한 세팅 작업을 거친다.
</p>

```c
FILE *fp = fopen("input.txt", "r"); // 파일을 연다.
char buffer[100];

while(fscanf(fp, "%s", buffer) != EOF)
    printf(buffer, "%s");

fclose(fp); // 파일을 닫는다.

// ex2.c
```
<p>
다음은 전체 코드이다.<br />
반복문을 이용해 input.txt 내부의 문자를 하나 하나 읽어들인 뒤 buffer에 할당한다.<br />
이후 buffer 문자열의 각 문자를 출력해보면 파일에서 읽어들였던 문자열이 출력된다.
</p>

<p>
이번엔 파일을 써보자(write).<br />
처음 파일을 열 때 호출했던 fopen()의 두 번째 인자로 "w"를 쓰면 쓰기 모드가 된다.
</p>

```c
FILE *fp_write = fopen("ouput.txt", "w");
char buffer[100];

fprintf(fp_write, "%s", "nurse"); // 세번째 인자의 내용을 ouput.txt에 작성.

fclose(fp_write);
```

<p>
파일을 읽는 함수가 fscanf() 이라면, fprinf()는 파일을 쓰는 거라고 생각하면 된다.<br />
이후 코드를 실행해보면 프로젝트 파일 내에 ouput.txt 파일이 생성되어 있을 것이다.
</p>

<p>
ex3.c에 input.txt를 읽은 뒤에 읽어들인 그 내용을 output.txt에 쓰는 예제 코드가 적혀 있다.<br />
반드시 참고해보도록 하자.
</p>