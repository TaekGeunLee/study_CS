<p>
이번에 추가할 기능은 다음과 같다.<br />
모두 <a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/2"></a>file 입출력 함수를 써야만 한다.
</p>

* load : 파일을 읽어들여 안의 데이터를 전화번호부에 저장한다.
* save as : 전화번호부에 저장된 모든 데이터들을 문서화 한다. 문서화할 때 이름(name) 오름차순으로 정렬한다.

### load : 문서화된 데이터 불러오기

<p>
load 뒤에 전화부에 저장할 파일 이름을 작성한다.<br />
File 입출력 함수의 사용법만 이해하고 있으면 문제없이 구현할 수 있다.<br />
다음은 load() 함수이다.
</p>

```c
void load() {
    char filename[BUFFER_SIZE];
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");

    char loadName[BUFFER_SIZE];
    char loadNumber[BUFFER_SIZE];

    while (fscanf(fp, "%s", loadName) != EOF) {
        fscanf(fp, "%s",loadNumber);
        name[i] = strdup(loadName);
        number[i] = strdup(loadNumber);
        i++;
    }
    fclose(fp);

    printf("loading data complete!\n");
}
```
<p>
파일로부터 읽어들인 데이터가 들어갈 loadName, loadNumber 변수는 지역변수이다.<br />
load() 함수의 실행이 완료되면 사라지기 때문에 strdup() 함수를 써준다.
</p>

### save as : 데이터 문서화

<p>
특별히 눈에 띄는 로직은 없다.<br />
save as 명령어를 입력받았을 때, 코드 내의 DB 역할에 해당하는 name, number 내의 요소들을 반복문을 이용해 문서화 하면 된다.<br />
FILE 입출력 함수의 사용법만 잘 숙지할 수 있으면 어렵지 않게 기능을 구현할 수 있다.
</p>

```c
void saveAs() {
    int j = 0;
    char commandAs[BUFFER_SIZE];
    char buf1[BUFFER_SIZE]; // file name when save for txt file.
    scanf("%s", commandAs);
    scanf("%s", buf1);

    FILE *fp = fopen(buf1, "w");

    for (j=0; j<i; j++) {
        fprintf(fp, "%s %s\n", name[j], number[j]);
    }

    fclose(fp);
}
```

<p>save as 뒤에는 문서화한 파일의 이름을 적는다.</p>

### save as : 데이터 정렬
<p>
하지만 문서화한 일련의 데이터들을 오름차순으로 정렬한 채로 저장을 해야만 한다.<br />
이를 위해서는 saveAs()에서 문서화를 하기 이전에 이미 name, number 배열 내의 원소들이 정렬 되어 있는 상태여야 한다.<br />
saveAs()에서 정렬하는 방법도 있겠지만 이것보다는 전자가 쉬울 것이다.<br />
add, drop등 배열에 변화를 가하는 명령을 실행할 때 마다 원소들을 정렬해야 한다는 의미이기도 한다.
</p>

<p>
정렬 알고리즘을 이용해 문제를 해결한다.<br />
버블, 삽입 정렬등 여러 알고리즘을 사용하는 방법이 있겠지만 여기서는 강의 대로 구현하는 걸로 하자.
</p>

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_7-1.png" alt="S1_7-1" />

<p>
할당할 원소보다 큰 배열의 요소들을 한 칸 씩 뒤로 뺀다.<br />
그 이외의 요소들은 가만히 내버려둔다.
</p>

<p>
당연하지만 코드상에서는 직접 요소들을 옮기는 것은 가능하지 않다.<br />
반복문을 이용해 하나하나 씩 배열의 요소와 할당할 새로운 요소를 비교해 가면서 정렬하도록 한다.
</p>

```c
void add() {
    char buf1[BUFFER_SIZE];
    char buf2[BUFFER_SIZE];
    scanf("%s", buf1);
    scanf("%s", buf2);

/*
    int n = i-1; // index when i use for sorting array.
    while(n>=0 && strcmp(name[n], buf1)>0) {
        name[n+1] = name[n];
        number[n+1] = number[n];
        n--;
    }
    name[n+1] = strdup(buf1);
    number[n+1] = strdup(buf2);
*/
    i++;
    printf("i : %d\n", i);
}
```
<p>
add() 함수에 새로운 코드를 더했다.<br />
주석 처리를 한 부분이 배열의 요소들을 정렬하는 부분이다.<br />
while 문을 이용해 조건절의 조건을 만족할 때에만 각 요소의 인덱스를 한 칸씩 뒤로 뺀다.
</p>

<p>
while의 조건절을 봤을 때, <a href="https://blockdmask.tistory.com/391">strcmp()</a>를 이용해 각 문자열들을 비교했는데,
첫 번째 인자가 두 번째 보다 클 경우 양수를 반환한다.
</p>

### drop() 함수 개선

<p><a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/5">이전에는</a> 지워버린 데이터 인덱스 자리에 배열의 맨 끝 번째 인덱스의 데이터를 넣는 식으로 drop()을 구현했었다.</p>

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_7-2.JPG" alt="S1_7-2" />

<p>
변수 index를 유심히 살펴보자.
변수 내에 할당된 search() 함수는 인자로 받은 문자열이 위치한 인덱스 자리를 리턴한다.<br />
해당 함수는 다음 디렉토리에서 기록할 것 이다.<br />
(그래서 이 절에 해당되는 코드 영역은 고치지 않았다.)
</p>

<p>
만약 인자로 받은 문자열에 해당하는 데이터가 배열 내에 없다면 -1를 리턴하게 될 것이다.<br />
특정 인덱스를 지정해서 배열 내의 요소를 지울 수는 없으므로 대상 인덱스 뒤의 요소들을 앞 당겨서 대상 인덱스를 덮어 쓸 것이다.
</p>
