#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N;
    int arr[8001]={};
    int temp, sum=0;
    vector<int> v;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> temp;
        sum+=(temp+4000);
        arr[temp+4000]++;
        v.push_back(temp);
    }

    //산술평균균
    cout << round((float)sum/N)-4000 << '\n'; 

    //중앙값
    sort(v.begin(), v.end());
    cout << v[N/2] << '\n';

    //최빈값 구하기
    int max_feq=0;
    for(int i=0; i<=8000; i++){
        if(max_feq < arr[i]) max_feq = arr[i];
    }

    vector<int> sub;
    for(int i=0; i<=8000; i++){
        if(max_feq ==arr[i]) sub.push_back(i-4000);
    }
    cout << ((sub.size() >= 2) ? sub[1] : sub[0]) << '\n'; 
    //삼항연산자 쓸때는 <<가 ?보다 연산 우선순위가 높아서 엔터출력안되고 이상할 수있음
    //그러니 삼항연산자 부분은 괄호로 묶기


    //범위
    cout << v[v.size()-1]-v[0];
    
}