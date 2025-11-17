#include<iostream>

using namespace std;

int main(){
    int N, M;

    cin >> N;
    int i=N-54;
    for(; i<N; i++){
        M=i;
        for(int j = i; j >0; j/=10){
            M += j%10;
        }
        if(M == N){
            cout << i;
            break;
        }
    }
    if(i == N) cout << "0";
}