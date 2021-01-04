다음 [기사](https://stackoverflow.com/questions/5481579/why-does-an-empty-declaration-work-for-definitions-with-int-arguments-but-not-fo)를 보고 작성한 기록입니다.

<p>C언어를 공부하면서 특정 코딩 스타일을 알게 되었다.</p>

```c
#include <stdio.h>

void showDan(int num);

int main(void)
{
    int dan = 1;
    int num = 1;

    for (dan = 1; dan <= 9; dan++)
    {
        showDan(dan);
    }
}

void showDan(int num)
{
    printf("=== %d단 ===\n", dan);

    for (num = 1; num <= 9; num++)
    {
        printf("%d * %d = %d\n", dan, num, dan * num);
    }
}
```

<p>
위의 예제를 보면서 알 수 있듯이,<br />
showDan() 함수를 미리 <b>선언</b> 한 뒤에 <b>정의</b>를 main() 함수의 아래쪽에다 해놨다.<br />
(호출을 말하는 것이 아니다.)
</p>

<p>
C언어 컴파일러는 맨 위쪽에서부터 코드를 해석해 나간다.<br />
함수를 미리 선언한다는 것은 컴파일러에게 미리 이런 함수가 있다는 것을 알려주는 것이다.<br />
만약 함수 선언부가 없다면 컴파일러는 생뚱맞은 함수에 대해 에러를 부를 것이니..
</p>

<p>
미리 선언한 위쪽 영역의 함수를 <b>프로토타입</b> 이라고 부른다.<br />
프로토타입과 함수 정의부의 인자는 꼭 적어놔야 한다.<br />
이를 지키지 않을 시 다음과 같은 에러를 마주치게 된다.
</p>

```
error : conflicting types for 'XXX'
note : an argument type that has a default promotion can't match an empty parameter name 
        list declaration.
```

<p>
상황에 따라 생략이 가능한 경우도 있는 듯 하다.<br />
맨 위에 하이퍼링크 처리한 질문에서는 int형 인자는 생략해도 잘 동작하는데, float형은 왜 동작이 안되느냐?
의 내용이다. <br />
이런 생략 기법이 있지만.. 지금은 정석적으로 코딩하는 것으로 하자.
</p>

