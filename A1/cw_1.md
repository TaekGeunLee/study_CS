* [출처](https://www.codewars.com/kata/56bc28ad5bdaeb48760009b0)

### 문제

<p>
문자열을 매개변수로 갖는 함수가 있다.<br /> 
이 함수는 문자열의 첫 번째, 마지막 번째 문자(char)를 없앤 문자열을 리턴한다.<br /> 
해당 함수를 완성하여라.<br /> 
2글자 이하의 문자열은 고려하지 않는다.
</p>

```c
char * remove_char(char* dst, const char* src)
{
    // 여기에 내용을 입력한다.
}
```


### 모범답안

```c
#include <string.h>

char* remove_char(char* dst, const char* src)
{
    strcpy(dst, src + 1);
    dst[strlen(dst) - 1] = '\0';
    return dst;
}
```

### 나의 답안

```c
#include <string.h>

char* remove_char(char* dst, const char* src)
{  
  char *result;
  
  for (int i=0; i<strlen(dst)-1; i++) {
    result[i] = dst[i+1];
  }
  
  
  return result;
}
```

###### note 1

<p>
매개변수 dst는 처리 결과 문자열을 넣을 자리, src는 변환할 대상 문자열이 들어갈 자리이다.<br />
그냥 변환할 문자열이 들어갈 파라미터 하나만 있어도 되는 거 아니야? 라고 생각했다.    
</p>


```c
int main()
{
    char buffer[BUFFER_SIZE];
    char str[BUFFER_SIZE] = "Alexandrite";

    remove_char(buffer, str);

    printf("result : %s\n", buffer);

    return 0;
}
```
<p>
위의 예제를 보면 이해할 수 있을 것이다.<br />
remove_char()의 매개변수 타입은 포인터 변수였다.<br />
주소 값에 의한 참조에 인해 dst 인자 자리에 들어간 문자열 buffer의 값이 수정되는 것이다.    
</p>

<p>
함수를 통해 값만 리턴하는 것이 아니라 수정하고 싶으면<br />
저런 식으로 코딩을 해줄 필요가 있다는 것.  
</p>

###### note 2

<p>
포인터 값에 숫자를 연산하는 것으로 포인터 변수가 가리키는 주소 값을 조작할 수 있다.<br />
모범 답안에서도 이러한 원리를 사용하여 대상 문자열(src)의 첫 번째 인덱스를 없앴다.<br />
이를 <b>포인터 연산</b> 이라고 한다. 
</p>

###### note 3

<p>아까 직접 IDE에 코드를 쳐볼 때 잘못한 것이 있었다.</p>

```c
char* remove_char(" ", "mountain"); // 쓰기 접근 위반 오류 : error log 없이 프로그램이 다운됨.
```
<p>
remove_char()은 인자로 char형 포인터 값을 받는다.<br />
이러한 값에 문자열 상수(큰따옴표로 씌워진 문자열)를 넣으려고 시도하면 error가 발생한다.<br />
문자열 상수는 수정이 불가한 값이기에 그렇다.. 정도로만 이해하도록 하자.
</p>

### 참고하기 좋은 자료
* [1](https://blog.naver.com/tipsware/221018307213) : 문자열 상수의 잘못된 사용 방법


