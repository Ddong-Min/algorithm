#include <stdio.h>
#include <stdlib.h>

/* 1. 청소부 함수 (뒷정리 담당)
    규칙: 반드시 '변수의 주소'를 매개변수로 받아야 합니다.
    그래서 int* 변수를 정리하려면 int**로 받아야 합니다.
*/
void my_cleanup_function(int** p) {
    printf("🧹 [청소부] : 자, 이제 변수가 사라지니 청소를 시작합니다...\n");
    if (*p != NULL) {
        printf("🧹 [청소부] : 메모리(%p)를 해제(free)했습니다!\n", *p);
        free(*p); // 진짜 메모리 해제
    }
}

int main() {
    printf("--- 프로그램 시작 ---\n");

    /* 스코프(범위) 시작 */
    {
        // 2. 변수 선언 + 청소부 등록
        // 해석: "numPtr 변수가 사라질 때, my_cleanup_function을 자동으로 실행해줘!"
        int* numPtr __attribute__((cleanup(my_cleanup_function))) = (int*)malloc(sizeof(int));

        *numPtr = 100;
        printf("🟢 [실행중] : 메모리 할당받고 값(%d)을 넣었습니다.\n", *numPtr);
        printf("🟢 [실행중] : 아직 블록({}) 안입니다.\n");

    } /* 👈 3. 여기가 핵심! 블록이 끝나는 순간(Out of Scope) */

    printf("--- 프로그램 종료 ---\n");
    return 0;
}