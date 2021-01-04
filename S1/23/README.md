### 개요

<p>
해당 구절 section 03 에서,<br />
연결-리스트를 이용해 다항식을 다루는 프로그램을 만들어보자.<br />
여기서 말하는 다항식은 중학생 때 배웠던 함수 및 방정식에 사용한 그것이 맞다.
</p>

<p>만들 프로그램에 대한 내용은 다음과 같다.</p>

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_23-1.JPG" alt="S1_23-1" />

<p>만들 프로그램에 사용할 연결-리스트의 자료구조는 다음과 같다.</p>

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_23-2.JPG" alt="S1_23-2" />

<p>
이전 디렉토리에서는 포인터 변수 head가 연속으로 정렬된 노드들의 집합을 가리키는 형태였다.<br />
이번엔 노드 Polynomial 내에 head의 역할을 담당하는 멤버 변수(first)가 있다.
</p>

<p>
그리고 각 항에 해당하는 노드 Term들이 연속으로 배치되어 있다.<br />
Term의 갯수가 변한다는 것은 각 항의 갯수가 변한다는 의미로, 그것에 대한 필드 size가 노드 Polynomial 내에 포함되어 있다.<br />
Term 내의 멤버 변수의 정보들을 나열해보면 다음과 같다.
</p>

* coef : 계수
* expo : 지수
* next : 링크 필드.

<p>지수(expo)가 0인 경우도 있을 수 있다. 이것은 해당 항이 상수라는 의미이다.</p>

### 소스 목록
<p>해당 디렉토리, 23에서의 소스 코드들이다.</p>

* [1](https://github.com/TaekGeunLee/study_CS/blob/master/S1/22/23-1.md) : 구조체 Polynomial, Term 생성
* [2](https://github.com/TaekGeunLee/study_CS/blob/master/S1/22/23-2.md) : Polynomial, Term 초기화 함수
* ■■ : add_term: 항 추가 함수
* ■■ : 전체 코드

