#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int answer=1;
    int i=1;
    for(; answer <N; i++){
        answer += 6*i;
    }
    cout << i << endl;
}