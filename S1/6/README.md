### 전역 변수(global variable)
* 함수 외부에 선언된 변수들
* 프로그램이 시작될 때 메모리가 할당되며 프로그램이 종료될 때 까지 유지된다.
* Data section 이라고 부르는 메모리 영역에 위치.

### 지역 변수(local variable)
* 함수 내부에 선언된 변수들
* 자신이 속한 함수가 호출될 때 메모리가 할당되며 함수가 return될 때 소멸한다.
* 스택(stack) 공간에 할당된다.

### 동적 메모리 할당(dynamic memory allocation)
* 아무때나 malloc등의 함수를 호출하여 필요한 크기의 메모리를 할당할 수 있다. 이것을 동적 메모리 할당이라고 부른다.
* 동적으로 할당된 메모리는 힙(heap) 공간에 할당된다.
* 동적으로 할당된 메모리는 free() 함수를 호출하여 반환하지 않는 이상 계속 유지 된다.

아래는 컴퓨터 메모리 RAM을 간단하게 시각화한 것이다.

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_6-1.png" alt="S1_6-1" />