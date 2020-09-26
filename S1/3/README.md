<p>이전에 배운 것을 토대로 여러 예제들을 다뤄보자.</p>

### 예제 1

<p>
문자열을 입력하면, 그 문자열과 문자열의 길이를 출력하는 프로그램을 작성해보자.<br />
일반적인 경우라면 다음과 같이 작성하는 것을 생각해볼 수 있다.
</p>

```c
#include <stdio.h>
#include <string.h>

char str[50];

while(1) {
    printf("$ "):
    scanf("%s", str);
    
    printf("%s:%d\n", str, strlen(str));
}
```

<p>
예를 들어 콘솔에 "my favorite color" 이라고 입력했을 때, 원했던 결과와는 달리 "my" "favorite" "color" 라고 읽힌다.<br />
scanf()로 문자열을 입력했을 시, 공백을 기준으로 단어별로 분류해서 받아들인다.<br />
scanf() 대신 다른 함수를 사용하여 이 문제를 해결할 수 있다.
</p>

```c
while(1) {
    printf("$ "):
    gets(str);
    printf("%s:%d\n", str, strlen(str));
}
```

<p>
gets()는 줄바꿈이 발생할 때 까지 콘솔에 입력한 문자열 전부(공백 포함)을 읽여들인다.<br />
이러면 문제를 해결할 수 있되, gets()의 사용은 권장하지 않고 있다.<br />
대신 fgets()의 사용을 고려해볼 수 있다.
</p>

```c
fgets(str, 50, stdin); // fgets(입력받을 대상 문자열, 문자열의 크기, 입력 파일 형식)
```
<p>
함수 이름을 잘보면 앞에 f가 붙었으니, file 입출력에 사용하는 함수 아니야? 라고 생각했다.<br />
하지만 파일 이외에 다른 형식의 데이터도 받아들일 수 있다.. 라고 하더라.<br />
표준 입력 파일, 즉 키보드로부터 받은 데이터를 사용 할 땐 세 번째 매개변수에 stdin을 쓴다.<br />
또 문제점이 있다. 콘솔에 문자열을 입력해보자.
</p>


```
$ dolphin
dolphin
: 8
// comments : 줄바꿈 문자까지 받아들여졌기 때문에 줄바꿈이 발생하는 것이다.
```
<p>
위의 예제에서 입력한 문자열의 길이는 7이되, 하나 더 긴 8이 출력되었다.<br />
fgets()의 기능은 gets()와 거의 같되, 문자열을 입력 한 뒤에 생긴 줄바꿈 문자까지 읽여들여서 저런 결과가 나온 것이다.<br />
(줄바꿈 하면 이스케이프 문자 "\n")이 생성됨.
</p>

<p>문자열의 끝을 나타내는 특수 문자 '\0'을 이용해 코드를 고칠 필요가 있겠다.</p>

```c
while(1) {
    printf("$ "):
    fgets(str, 50, stdin);
    str[strlen(str)-1] = '\0';
    printf("%s:%d\n", str, strlen(str));
}
```
<p>fgets()로 받은 문자열의 맨 끝 번째 자리에 '\0'를 추가함 으로써 문제를 해결했다.</p>

<p>
해당 문제에 관한 소스코드는 ex1.c에 저장했다.<br />
다만, fgets()나 get() 함수를 쓰는 대신 직접 함수를 만들어서 코드를 개선시켰다.<br />
그에 대해선 예제코드를 확인하길 바란다.
</p>

### 예제 2

<p>
콘솔로부터 입력받은 문자열의 불필요한 공백들을 제거한 채로 출력해보자.<br />
예를 들어 "  My  little ponny.. " 라고 입력했을 때 "My little ponny.." 라고 출력되는 것이다.
</p>

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_3-1.PNG" alt="S1_3-1" />

<p>
위의 그림 처럼 콘솔로부터 입력받은 문자를 담을 배열(buffer)과 buffer 문자열을 압축해서 담아낼 배열(compression)을 구상한다.<br />
실제 코딩에서는 반드시 두 개의 문자열을 선언하지 않은 채로 푸는 방법도 있으니 한 방법만 고집하지 말자.
</p>

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_3-2.PNG" alt="S1_3-2" />

<p>
buffer에서 최초의 문자가 들어있는 인덱스에 도달할 때 까지, 초반의 공백 문자들은 지운다.<br />
지운다는 것은 배열의 index를 스킵한다.. 라고 생각하면 된다.<br />
문자의 공백 판별은 getchar() 함수를 이용해 알아낼 것 이다.
</p>

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_3-3.PNG" alt="S1_3-3" />

<p>
이후엔 공백 문자를 할당 하되, 문자 바로 뒤에 있는 공백은 할당하고, 
그 이후의 인덱스에 공백이 있다면 스킵한다.<br />
예를 들어서 <b>대상 인덱스가 i라면, 이전 인덱스(i-1)에 공백이 있는지 없는지 체크하는 것이다.</b><br />
상단에 굵은 글씨로 표시한 문단이 키 포인트이다.
</p>
