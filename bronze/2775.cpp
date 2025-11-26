// #include<iostream>

// using namespace std;

// int buneu(int k, int n){
//     if(k==0) return n;
//     int p=0;
//     for(int i=1; i<=n; i++){
//         p+=buneu(k-1,i);
//     }
//     return p;
// }

// int main(){
//     int T;
//     cin >> T;

//     int k ,n;
//     while(T--){
//         cin >> k;
//         cin >> n;

//         cout << buneu(k, n) << endl;    
//     }
// }

/* 아래에 조금 더 연산이 빠른방법
 i층의 j번째 집을 계산하다고 하면,
 현재 계산된 i층의 j-1번재 집은 i-1번째 집의 1~j-1번째 집을 다 더한 값이 포함되어있음
 따라서 i층의 j번째 집 계산시 j-1번째 집에 값 + i-1층 j번쨰 집의 값을 더하면 된다.
*/

#include<iostream>

using namespace std;

int buneu(int a, int b){
    if(a==0) return b;
    if(b==1) return 1;
    else return buneu(a, b-1) + buneu(a-1,b);
}


int main(){
    int T;

    cin >>T; 
    int a,b; 
    int base[15]={};
    while(T--){
        cin >> a>> b;
        cout << buneu(a,b) << endl;
    }
}