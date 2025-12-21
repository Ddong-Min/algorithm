#include <stdio.h>
#include <stdlib.h>

void testSingleFrame(long size) {
    printf("Testing single frame size: %ld KB ... ", size / 1024);
    fflush(stdout); // 줄바꿈 전에 출력 강제 (에러 나기 직전 문구 확인용)

    // 여기서 '단 하나의' 거대한 지역 변수 배열을 선언 (스택 할당)
    volatile char bigArray[size]; 
    
    // 메모리에 실제로 접근해봄 (OS가 페이지를 할당하게 강제함)
    bigArray[size - 1] = 'A'; 

    printf("Success!\n");
}

int main() {
    long size = 1024; // 1KB 부터 시작

    while (1) {
        testSingleFrame(size);
        
        // 크기를 128KB씩 늘려감
        size += (1024 * 128); 
    }
    return 0;
}
