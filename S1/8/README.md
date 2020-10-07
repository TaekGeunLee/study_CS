<p>
이번에 추가할 기능은 다음과 같다.<br />
</p>

* 동적 메모리 할당 방식을 이용해 부족한 배열의 공간 확장하기
* 프롬프트 입력 방식 개선

<p>
모든 기능은 이번 디렉토리에서 끝나지 않고 여러 디렉토리를 거쳐서 마치는 것으로 하겠다.
</p>

### 배열 영역 확장하기 : 동적 메모리 할당 방식

<p>
이전 프로그램에서는 최대 크기(CAPACITY)를 미리 정한 채로 배열을 선언했었다.<br />
최대 할당량을 넘어서는 경우가 있을수 있으므로 문제가 생길 수 있다.<br />
저번에 배운 동적 할당 방식을 이용해 최대 할당량을 초과할 경우 더 늘려보도록 해보자.
</p>

```c
char ** name;
char ** number;
```

<p>
이전에 배열 형태로 선언했던 name, number 변수들을 위의 형태로 바꿔준다.<br />
포인터 기호가 중첩 되어 작성되어 있다.<br />
이것은 <b>포인터 변수의 포인터 변수</b>라는 뜻으로, 2번 이상 중첩해보는 것도 생각해볼 수고 있을 것이다.<br />
name과 number는 char * 타입의 배열로 메모리 주소를 할당하는 배열로써 선언했었기 때문에 중첩 포인터를 사용하는 것이다.
</p>

```c
void init_dir() {
    name = (char **)malloc(CAPACITY * sizeof(char *)) 
    number = (char **)malloc(CAPACITY * sizeof(char *))
}
```

<p>
다음은 동적 메모리 할당을 하는 과정을 함수로써 작성한 것이다.<br />
위에서 알 수 있듯이, char * name 에서 *name은 배열의 이름이 아니라 name만 이름에 해당하는 것을 알 수 있었다.<br />
즉, char * 는 데이터 타입이다.
</p>

```c
int main() {
    init_dir();
    command_process();
}
```

<p>
앞에서 따로 함수로 묶은 이유는 코드를 정리하기 위해서 였다.<br />
동적 메모리 할당하는 작업 코드와 명령어 입력 작업 코드를 별개의 함수로 구분하여서 정리하였다.<br />
여기까지의 과정은 telephone_05.c를 참고한다.
</p>

### 프롬프트 입력 방식 개선

<p>
<a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/3">이전 레퍼토리</a>에서 살펴봤듯이, 문자를 입력받는 함수는 여러 가지가 있다. (fgets(), scanf() 등.)<br />
위에서 언급한 함수 말고, 이 프로그램에서는 직접 문자열을 받는 함수를 작성해보도록 해보자.<br />
타 함수와는 달리 띄어 쓰기 이전(\n) 까지의 문자열만 입력받는다.
</p>

```c
int read_line(char str[], int limits) {
    int ch, i = 0;
    
    while((ch = getchar()) != '\n')
        if (i < limit-1)
            str[i++] = ch;
    
    str[i] = '\0';
    
    return i;
}
```