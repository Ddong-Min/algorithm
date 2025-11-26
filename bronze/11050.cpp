#include<iostream>

using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    int answer=1;
    for(int i=0; i<K && N-i > K; i++){
        answer *= (N-i);
        answer /= (i+1);
    }

    cout << answer;
}