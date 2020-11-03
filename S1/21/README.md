### 맨 앞의 노드 제거하기

<p>그림을 그려서 전략을 생각해보자.</p>

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_21-1.PNG" alt="S1_21-1" />

이를 함수로 구현해보면 다음과 같다.

```c
Node * remove_front() {
    if (head == NULL) {
        return NULL;
    } else {
        Node *tmp = head;
        head = head->next;
        return tmp // 삭제한 노드의 주소를 리턴.
    }
}
```

이 문제에서 가장 핵심인 구문은 head = head->next 이다.
만약 remove_front()가 아무것도 리턴하지 않고 끝나게 하려면, 아무도 가리키지 않는 삭제 대상을 free()를 이용해 반환해줘야 한다.
head가 지역 변수라면, <a href="https://github.com/TaekGeunLee/study_CS/tree/master/S1/20">이전 레퍼토리</a>에서 다뤘었던 전략을 응용하면 될 것이다.

### 어떤 노드의 다음 노드 삭제하기

작업 과정은 다음과 같다.

<img src="https://github.com/TaekGeunLee/study_CS/blob/master/readmeImg/S1_21-2.PNG" alt="S1_21-2" />

이를 함수로 구현해보면 다음과 같다.

```c
Node * remove_next(Node *prev) {
    Node *tmp = prev->next;
                                
    if (tmp == NULL) {
        return NULL;
    } else {
        prev->next = tmp->next;
        return tmp // 삭제한 노드의 주소를 리턴.
    }
}
```
tmp는 삭제한 노드의 주소를 리턴하기 위해 선언한 것이다.

이번 전략은 반드시 삭제할 노드의 앞 노드를 이용해야만 한다.
연결-리스트에서는 배열과는 달리 특정 노드를 지정해서 조작할 수는 없기에 이런 전략을 사용하는 것이다.

