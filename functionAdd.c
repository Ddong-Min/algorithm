#include<stdio.h>

// void (*foo)();

// void foo2(){
//     printf("foo2");
// }
// int main(){
//     printf("%p\n", foo);
//     foo = foo2;
//     printf("%p", foo);
// }

void (*foo)(); //*foo에 매개변수 안넣으면 foo2로 casting해도 몰라 아무거나 넘겨주겠지 하고 string넘겨줬는데 그냥 받아들이고 이상한 정수값을 출력
// void (*foo)(int n); 이렇게 하면, 왜 int형에 char*을 넣냐고 뭐라함.

void foo2(int n){
    printf("%d", n);   
}

int main(){
    foo = foo2;
    foo("123123");
}