하나의 긴 문자열을 여러 작은 문자열로 쪼개는 것을 토큰화(tokenizing)라고 한다.
<a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/8">이전 레퍼토리</a>에서 값 입력용으로 read_line() 함수를 만들었었다. 프롬프트에 명령어를 입력하면, 개행 문자(\n) 바로 이전까지의 문자열들을 읽어들이는데, 이렇게 읽힌 문자열들을 토큰화해서 코드에서 다루기 쉽게 만들것 이다.

예를 들어서 'save as dir.txt' 라고 프롬프트에 입력했다고 가정을 해보자.
이때 공백을 기준으로 삼아 'save', 'as', 'dir.txt'로 토큰화할 것이다.
이렇게 쪼개진 문자열들을 토큰(token)이라고 부르고, 토큰화하는데 기준으로 삼은 공백 문자를 구분 문자(delimiter) 이라고 부르자.

### strtok() : 토큰화 함수

간단한 예시를 통해 함수 사용법을 익혀보자.

```c
#include <string.h>

char str[] = "Mango # is ## my ### favorite # fruit.";
char deli[] = "#";
char * token = strtok(str, deli);
```

strtok()는 <string.h> 혜더 내의 함수이다.
첫 번째 인자로 토큰화할 대상, 두 번째로 구분 문자로 삼을 문자열을 받는다.
포인터 변수로 초기화 하는 것으로 선언되어있는데, 일단은 이것은 이렇게 해야 한다로 이해하고 있자.

```c
int main(void)
{
    char str[] = "Mango # is ## my ### favorite # fruit.";
    char deli[] = "#";
    char * token = strtok(str, deli);

    while(token != NULL) {
        printf("token : %s(%d)\n", token, strlen(token));
        token = strtok(NULL, deli);
    }

    return 0;
}

/*
★ 결과
token : Mango (6)
token :  is (4)
token :  my (4)
token :  favorite (10)
token :  fruit.(7)
*/
```

토큰화 작업이 끝나면 strtok()에서는 NULL를 리턴한다.
반복문을 이용해 토큰화 작업을 코딩해준다.
이 때 한번 문자열을 쪼갤 때 마다 다음 문단을 작성함으로써 다음 문자열을 토큰화할 수 있도록 한다.

```c
strtok(NULL, deli);
```

### strtok()은 어떻게 동작하는가?

다른 문자열 함수와는 달리 strtok()의 운용 방법은 특이하다.
내가 들은 대로 기록해보면 다음과 같다.

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_9-1.png" alt="S1_9-1" />

처음 strtok()를 호출했을 때 strtok()를 선언하면서 초기화한 변수(이전 구절에서는 token에 해당.)가 첫 번째 토큰인 'favoirte'의 첫 번째 인덱스 'f'를 가리키게 된다.
그리고 구분 문자에 해당하는 '#'을 문자열의 끝을 나타내는 '\0'으로 바꿔준다.
그 다음 strtok('문자열', NULL)를 호출했을 때, 다음 토큰에 해당하는 문자열의 첫 번째 인덱스를 가리키게 되고, 구분 문자를 변환하는 과정을 거치게 된다.
이런 식으로 진행하다가 문자열의 맨 마지막 '\0'을 만날 시, strtok()은 더 이상 쪼갤 문자열이 없다고 판단을 하여 NULL을 리턴하는 것이다.

위에서 처럼, strtok()는 기존 문자열을 수정을 하기 때문에 string literal에 해당 함수를 사용했을 경우 오류가 발생한다.

