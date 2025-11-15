#include<iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    int N, M;

    while(T--){
        cin >> N >> M;
        long long int answer = 1;
        int i;
        for(i =0; M-i>N && i < N; i++){
            answer *= (M-i);
            answer /=(i+1);
        }
        cout << answer << endl;
    }
}

// int binomial(int n, int r){
//     if(n==r) return 1;
//     if(r==1) return n;
//     return binomial(n-1, r) + binomial(n-1, r-1);
// }

// int main(){
//     ios_base :: sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int T;
//     cin >> T;
//     int N, M;

//     while(T--){
//         cin >> N >> M;
//         cout << binomial(M, N) << endl;
//     }
// }