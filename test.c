#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // for uintptr_t

int main() {
    printf("=== 실험 시작 ===\n\n");

    // 1. 같은 크기의 메모리 2개 할당 (작은 크기는 tcache/fastbin이라는 리스트로 관리됨)
    // 64비트 시스템에서는 8바이트 단위로 정렬되므로 넉넉히 32바이트 할당
    void *chunk1 = malloc(2048);
    void *chunk2 = malloc(2048);

    // 2. 주소 확인 (정답지)
    printf("[정답] Chunk 1의 주소: %p\n", chunk1);
    printf("[정답] Chunk 2의 주소: %p\n\n", chunk2);

    // 3. 순서대로 해제 (LIFO: Last In First Out 구조인 경우)
    // tcache나 fastbin은 보통 스택처럼 동작하므로, 
    // chunk1을 먼저 넣고, chunk2를 나중에 넣으면 -> chunk2가 chunk1을 가리키게 됨
    free(chunk1);
    printf("1. Chunk 1 해제 완료\n");
    
    free(chunk2);
    printf("2. Chunk 2 해제 완료\n\n");

    // 4. Chunk 2의 내부를 들여다보자 (여기에 Chunk 1의 주소가 있을까?)
    uintptr_t *hidden_link = (uintptr_t*)chunk2;
    uintptr_t *hidden_link2 = (uintptr_t*)chunk1;

    printf("=== 결과 확인 ===\n");
    printf("Chunk 1 안에 적힌 값; 0x%llx\n", (unsigned long long)*hidden_link2);
    printf("Chunk 2 안에 적힌 값: 0x%llx\n", (unsigned long long)*hidden_link);
    printf("chunk 1 blink Ox%llx\n", (unsigned long long)hidden_link2[1]);
    printf("chunk 2 blink Ox%llx\n", (unsigned long long)hidden_link[1]);

    
    printf("\n--------------------------------------------------\n");
    printf("판독 팁:\n");
    printf("1. 이 값이 Chunk 1의 주소(%p)와 똑같은가요?\n", chunk1);
    printf("2. 아니면 비슷하지만 조금 다른 값(암호화됨)인가요?\n");

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdint.h>

// int main() {
//     printf("=== [검증 실험] 상호 연결 증명 ===\n\n");

//     // 1. 샌드위치 할당 (3개)
//     void *chunk1 = malloc(64);
//     void *chunk2 = malloc(64);
//     void *chunk3 = malloc(64);

//     // 2. 주소 확보 (정답지)
//     printf("[내 위치] Chunk 1의 주소: %p\n", chunk1);

//     // 3. 해제 (샌드위치 만들기)
//     // 순서는 OS마다 다를 수 있지만, 중요한 건 연결 관계 형성임
//     free(chunk3);
//     free(chunk1); // 주인공 해제
//     free(chunk2); 

//     // 4. Chunk 1의 내부 들여다보기
//     uintptr_t *my_view = (uintptr_t*)chunk1;
    
//     // Chunk 1의 뒷친구(Blink) 주소 가져오기
//     uintptr_t back_friend_addr = my_view[1]; 
    
//     printf("\n[1단계] Chunk 1 내부 확인\n");
//     printf(" -> 내 뒷친구(Blink)의 주소는? : 0x%llx\n", (unsigned long long)back_friend_addr);

//     // ==========================================================
//     // 5. [핵심] 뒷친구 집으로 직접 찾아가기 (Pointer Chasing)
//     // ==========================================================
//     printf("\n[2단계] 뒷친구 집(%p)으로 이동해서 문 따기...\n", (void*)back_friend_addr);
    
//     // 그 주소를 포인터로 변환해서 접속
//     uintptr_t *back_friend_view = (uintptr_t*)back_friend_addr;

//     // 뒷친구의 첫 번째 값(Flink) 읽기
//     uintptr_t back_friend_flink = back_friend_view[0];

//     printf(" -> 뒷친구의 Flink(앞) 값 확인 : 0x%llx\n", (unsigned long long)back_friend_flink);

//     // 6. 최종 판결
//     printf("\n==========================================\n");
//     printf("             [진실의 순간]                \n");
//     printf("==========================================\n");
    
//     if (back_friend_flink == (uintptr_t)chunk1) {
//         printf("✅ 증명 성공! \n");
//         printf("   \"뒷친구는 정확하게 나(Chunk 1)를 가리키고 있었습니다.\"\n");
//         printf("   (0x%llx == %p)\n", (unsigned long long)back_friend_flink, chunk1);
//     } else {
//         printf("❌ 증명 실패...\n");
//         printf("   (값이 다릅니다. 연결 구조가 다르거나 보안 기법이 적용됨)\n");
//     }

//     return 0;
// }