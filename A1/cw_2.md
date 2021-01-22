* [출처](https://www.codewars.com/kata/57eae20f5500ad98e50002c5)

### 문제

<p>
문자열의 공백을 지운다. 그 결과물을 리턴하는 함수를 작성해보자.<br />
C언어의 경우, 리턴 값으로 메모리 동적 할당한 값을 내놓는다.
</p>

```c
char *no_space(const char *str_in) {
    //  <----  hajime!
}
```


### 모범답안

```c
#include <stdlib.h>

char *no_space(char *strin) {
  char *tmp = malloc(strlen(strin) + 1);
  char *start = tmp;
  
  while (*strin != '\0') {
    if (*strin != ' ') {
      *tmp++ = *strin;
    }
    strin++;
  }
  *tmp = '\0';
  
  return start;
}
```

### 다른 풀이

```c
#include <stdlib.h>

char *no_space(char *strin) {

    int len = strlen(strin);

    int len2=0;
    for (int i=0; i<len; i++) {
        if (strin[i] != ' ') {
            len2++; // 공백을 뺐을 경우의 문자열의 갯수를 센다.
        }
    }

    char *str = malloc(len2 * sizeof(char) + 1); // 공백을 뺀 만큼의 갯수 + '\0'이 들어갈 공간 하나만큼 동적 할당.

    int j=0;
    for (int i=0; i<len; i++) {
        if (strin[i] != ' ') {
            str[j] = strin[i];
            j++;
        }
    }

    str[len2] = '\0';
    printf("%s--%s\n", strin, str);

    return str;
}
```

### 나의 답안

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *nono_space(char *strin) {
  char *result = (char *)malloc(strlen(strin)+1);
  char *start = result;
  int s_index=0, r_index=0;

  while (*strin != '\0') {
    if (strin[s_index] != ' ') {
        result[r_index] = strin[s_index];
        r_index++;
    }
    s_index++;
  }

  result[s_index] = '\0';
  printf("%s\n", start);
  return start;
}


// Runtime error
```

###### note 1

<p>모범답안을 보면 다음과 같은 표현식을 볼 수 있다.</p>

```c
*tmp++ = *strin;
```

<p>위의 표현식은 아래의 예제와 같다.</p>

```c
*tmp = *strin;
tmp += 1;

/*
    strin가 가리키는 인덱스가 공백이 아니라면 tmp 내에 문자를 할당하고 
    tmp의 주소를 증가시킨다. 
    이는 포인터 변수 tmp가 배열의 다음 인덱스를 가리키는 것과 마찬가지 이다.
*/
```
<p>
포인터 기호(*)가 붙었다 해서 전혀 당황할 필요가 없다.<br />
일반 증감 연산자와 다를 게 없다.
</p>


<p>
<a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/1">이전에</a> 배웠듯이, <br />
이미 선언한 포인터 변수를 사용할 때 포인터 기호(*)를 쓰면 해당 메모리의 실제 값을 쓰게 된다고 학습했었다.<br />
즉, 문자를 할당하고 난 뒤에야 tmp의 주소 값을 증가 시킴으로써 tmp가 가리키는 곳을 배열의 다음 인덱스로 가리키게 한다.
</p>

###### note 2

<p>모범 답안을 잘 보면 총 2개의 동적 할당이 된 포인터 변수를 선언했다.</p>

```c
char *tmp = malloc(strlen(strin) + 1);
char *start = tmp;

// 이런 저런 처리를 하면..

return start;
```

근데 정작 tmp 에다가 문자들을 할당해 놓고서 또 다른 포인터 변수인 start를 return 하고 앉아있다.
그냥 tmp를 리턴하지 않고 start를 return 하는 이유는 대체 뭘까.
지역 변수로써 포인터 변수는 어떻게 동작하는 것일까?
[참고 자료](https://dojang.io/mod/page/view.php?id=529)

###### 자료

* [Pointer expressions: *ptr++, *++ptr and ++*ptr](https://stackoverflow.com/questions/18481740/pointer-expressions-ptr-ptr-and-ptr)


