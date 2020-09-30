<p>strdup(), strcpy()는 문자열을 복사하는 라이브러리 함수다만, 각각 약간의 차이점이 있다.</p>

### strdup()

<p>
다음은 작동 원리를 설명하기 위해 strdup()의 코드를 모방한 함수이다.<br />
(실제로 저렇게 생겼다는 의미는 아님.)
</p>

```c
char * strduppp(char *s) {
    char *p;
    p = (char *)malloc(strlen(s) + 1); // \0가 들어갈 자리도 마련해야 하기 때문에 +1를 해주는 것.
    if (p != NULL)
        strcpy(p);
    return p;
}
```

<p>
위의 함수는 char 타입의 데이터 번지를 리턴한다.<br />
인자로 문자열을 받으면, 별도로 문자열 갯수 만큼의 데이터 셀을 동적 할당(p) 한뒤에
해당 변수를 복사한다(strcpy(p)). 그림으로 나타내면 다음과 같다.
</p>

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_^4-1.png" alt="S1_^4-1" />

<p>strcpy()와 다른 점이라면, strdup()은 내부적으로 메모리를 동적 할당 한다는 것이다.. 라고 할 수 있겠다.</p>


