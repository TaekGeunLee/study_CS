* [출처](https://www.acmicpc.net/problem/2675)

### 문제

##### 개요
<p>
문자열 S를 입력받은 후에, 각 문자를 R번 반복해 새 문자열 P를 만든 후 출력하는 프로그램을 작성하시오.<br />
즉, 첫 번째 문자를 R번 반복하고, 두 번째 문자를 R번 반복하는 식으로 P를 만들면 된다.<br />
S에는 QR Code "alphanumeric" 문자만 들어있다.<br />

QR Code "alphanumeric" 문자는 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./: 이다.
</p>

##### 입력
<p>
<strong>첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 1,000)가 주어진다.</strong><br />
각 테스트 케이스는 반복 횟수 R(1 ≤ R ≤ 8), 문자열 S가 공백으로 구분되어 주어진다.<br />
S의 길이는 적어도 1이며, 20글자를 넘지 않는다.    
</p>


##### 출력
<p>각 테스트 케이스에 대해 P를 출력한다.</p>

```
2 
3 ABC // AAABBBCCC
5 /HTP // /////HHHHHTTTTTPPPPP 
```

### 나의 답안 (틀린 풀이)

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char S[21]; // input string
    int R, size_T=0;
    char T[150]; // output string for printing

    scanf("%d %s", &R, S);

    for (int n=0; n<strlen(S); n++) {
        for (int i=0; i<R; i++)
            T[size_T++] = S[n];
            // 배열 T에 할당한 뒤 T를 출력. 이런 방법도 있으니까.
    }

    printf("%s\n", T);

    return 0;
}
// 결과는 성공적. 백준 컴파일러에서는 틀렸다고 함. 왜 그럴까..
```

### 나의 답안 (고친 풀이)

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char S[21]; // input string
    int R, T;

    scanf("%d", &T);

    while(T--) { // test case T가 0이 되면 반복문 종료.
        scanf("%d %s", &R, S);

        for (int n=0; n<strlen(S); n++) {
            for (int i=0; i<R; i++)
                printf("%c", S[n]);
        }

        printf("\n");
    }
    return 0;
}

```

###### note 1

<p>
가장 중요한 것은 문제에서 요구하는 조건이다.<br />
첫째 줄에 테스트 케이스의 개수 T도 입력(input) 받아야만 하는데, 그것을 이해하지 못하여 쩔쩔 해맸다.<br />
(프로그램을 몇 번 실행할 것이냐에 관한 변수이다.)    
</p>

<p>다음부터 이런 일이 발생하지 않도록 주의하도록 하자.</p>

##### note 2

<p>
문제를 풀면서 혜더 파일 string.h의 함수인 strlen()이 리턴한 값의 출력을 시험해봤다.<br />
strlen()이 리턴하는 값의 type은 size_t형이다.<br />
(통상적인 일반 정수형이 int형과는 별개의 형태.)
</p>

<p>이를 출력하고자 할 때에는 커스텀으로 int형으로 변환한 뒤에 출력하도록 하자.</p>



