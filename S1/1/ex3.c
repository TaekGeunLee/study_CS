#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr1 = {0, 1, 2};
    int *p = &arr1;

    printf("%d %x\n", p, p); // 해당 주소의 값을 사용할려면 *p 
    printf("%d %x\n", p+1, p+1);
    printf("%d %x\n", p+2, p+2);

    return 0;
}

/*
    char나 long long 같이 다른 자료형으로 배열을 선언한 뒤에
    해당 코드를 출력해보면 어떤 결과가 도출될까?
*/