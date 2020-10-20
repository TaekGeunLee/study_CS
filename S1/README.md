[다음 강의](https://www.inflearn.com/course/c%EB%A1%9C-%EB%B0%B0%EC%9A%B0%EB%8A%94-%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EB%B0%8F-%EC%97%AC%EB%9F%AC%EA%B0%80%EC%A7%80-%EC%98%88%EC%A0%9C-%EC%8B%A4%EC%8A%B5)를 수강하면서 정리한 레퍼토리 입니다.

# File list

### Section 0 : C언어 기초 문법 리뷰
* [1](https://github.com/TaekGeunLee/study_CS/tree/master/S1/1) : 배열과 포인터
* [2](https://github.com/TaekGeunLee/study_CS/tree/master/S1/2) : 문자열
* [3](https://github.com/TaekGeunLee/study_CS/tree/master/S1/3) : 문자열 예제

### Section 1 : 전화번호집 프로그램 제작 실습
##### version 1.0
* [4](https://github.com/TaekGeunLee/study_CS/tree/master/S1/4) : 개요, 데이터 추가(add) 기능
* [4-1](https://github.com/TaekGeunLee/study_CS/tree/master/S1/4-1) : strdup(), strcpy()의 차이점
* [5](https://github.com/TaekGeunLee/study_CS/tree/master/S1/5) : 데이터 열람(show), 제거(drop), 탐색(search) 기능
* [7](https://github.com/TaekGeunLee/study_CS/tree/master/S1/7) : save, load - 데이터 파일화하기
##### version 2.0
* [8](https://github.com/TaekGeunLee/study_CS/tree/master/S1/8) : 배열 재할당, 프롬프트 입력 방식 개선하기
* [9](https://github.com/TaekGeunLee/study_CS/tree/master/S1/9) : 토큰화(tokenizing)
* [10](https://github.com/TaekGeunLee/study_CS/tree/master/S1/10) : 전화번호부 2.0
##### version 3.0
* [11](https://github.com/TaekGeunLee/study_CS/tree/master/S1/11) : 개요, 구조체란?
* [12](https://github.com/TaekGeunLee/study_CS/tree/master/S1/12) : 전화번호부 3.0_1
* [15](https://github.com/TaekGeunLee/study_CS/tree/master/S1/15) : 전화번호부 3.0_2
##### version 4.0
* [13](https://github.com/TaekGeunLee/study_CS/tree/master/S1/13) : 구조체에 대한 포인터, 동적 메모리 할당
* [14](https://github.com/TaekGeunLee/study_CS/tree/master/S1/14) : 전화번호부 4.0


### Section 2 : 연결 리스트_개념, 기본 동작 알아보기


# index

### 예제
* 포인터 변수를 이용해 배열 선언하기
* 배열의 길이(length) 늘이기
* 여러 개의 문자열들을 입력받아 하나의 배열에 저장하기
* 파일 입출력하기
* 문자열을 입력받으면 입력받은 문자열과 그 길이 출력하기

### 함수
* printf(), scanf() : 기본적인 입출력 함수
* malloc() : Nbyte의 메모리를 선언한 변수에 할당.
* sizeof() : 함수가 아닌 연산자. 인자로 받은 변수 타입의 기본 메모리 할당 byte를 리턴.
* fopen(), fclose()
* fscanf(), fprintf() : 파일 스트림 입출력 함수
* 문자열 조작 주요 함수 : strcpy(), strlen(), strcat(), strcmp()
* gets(), fgets() : 표준 입력(stdin)으로 들어온 문자열을 C언어 스타일 문자열인 char*, char[] 타입으로 저장
* fgetc() : 스트림 입력 함수
* getchar() : char형의 데이터를 입력(input).
* isspace() : 공백 값이면 true 반환
* strtok() : 토큰화(tokenizing), 문자열 나누기

### 노트
* [6](https://github.com/TaekGeunLee/study_CS/tree/master/S1/6) : C언어에서의 메모리 관리 방식
* [16](https://github.com/TaekGeunLee/study_CS/tree/master/S1/16) : 스트림(stream)
* [17](https://github.com/TaekGeunLee/study_CS/tree/master/S1/17) : error-assignment-to-expression-with-array-type-error
