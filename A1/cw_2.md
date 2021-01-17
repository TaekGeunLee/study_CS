* [출처](https://www.codewars.com/kata/57eae20f5500ad98e50002c5)

### 문제

<p>
문자열의 공백을 지운다. 그 결과물을 리턴하는 함수를 작성해보자.
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
            len2++;
        }
    }

    char *str = malloc(len2 * sizeof(char) + 1);

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
#include <stdlib.h>
#include <string.h>

char *no_space(const char *str_in) {
  char *result = (char *)malloc(sizeof(char *) * strlen(str_in));
  int s=0;
  
  for (int i=0; i<strlen(str_in); i++) {
    if (str_in[i] == " ") {
      s--;
    } else {
      result[s] = str_in[i];
      s++;
    }
  }
  
  result[s] = '\0';
  return result;
}

// 틀린 풀이!
```

###### note 1

=> 작성할 것



