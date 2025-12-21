#include <stdio.h>
#include <windows.h>

void checkStackMemory() {
    int localVariable;
    unsigned char* ptr = (unsigned char*)&localVariable;
    
    printf("--- Stack Memory Map (Scanning Downwards) ---\n");
    printf("Current Stack Address: %p\n\n", ptr);

    // 50페이지(약 200KB) 정도 아래로 내려가면서 스캔
    for (int i = 0; i < 50; i++) { 
        MEMORY_BASIC_INFORMATION mbi;
        VirtualQuery(ptr, &mbi, sizeof(mbi));

        printf("Addr: %p | State: ", ptr);

        // 상태 출력 (영어)
        if (mbi.State == MEM_COMMIT) printf("COMMITTED (Usable)   ");
        else if (mbi.State == MEM_RESERVE) printf("RESERVED  (Waiting)  ");
        else printf("FREE      (Empty)    ");

        printf("| Protect: ");
        
        // ★ 핵심: 가드 페이지 확인 ★
        if (mbi.Protect & PAGE_GUARD) {
            printf("!!! PAGE_GUARD (TOUCH = DIE) !!!"); // 여기가 지뢰
        } else if (mbi.Protect == PAGE_READWRITE) {
            printf("Read/Write"); // 안전지대
        } else if (mbi.Protect == PAGE_NOACCESS) {
            printf("No Access");  // 출입금지
        } else {
            printf("Other (%ld)", mbi.Protect);
        }

        printf("\n");

        // 예약된 공간(RESERVED)이 나오기 시작하면 5줄만 더 찍고 종료
        if (mbi.State == MEM_RESERVE && i > 5) break; 

        ptr -= 4096; // 4KB씩 아래로 이동
    }
}

int main() {
    checkStackMemory();
    return 0;
}