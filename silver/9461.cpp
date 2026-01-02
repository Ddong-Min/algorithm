#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int p[101]={0,1,1,1,2,2};
    //p[i]를 구하기 위해 대략 자신의 1/3인 값을 계속 더하게 됌
    //즉 크기가 계속 4/3씩 커지는건데 (4/3)^90만 해도 1000억이 넘음
    for(int i=6; i<101; i++){
        p[i] = p[i-1]+p[i-5];
    }
    int T, num;
    cin >> T;
    while(T--){
        cin >> num;
        cout << p[num] << '\n';
    }
}

