#include<iostream>
#include<stack>
using namespace std;

int main(){
    int k;
    cin >> k;
    stack<int> s;
    int n, answer = 0;
    for(int i=0; i<k; i++){
        cin >> n;
        if(n) s.push(n);
        else s.pop();
    }
    while(!s.empty()){
        answer += s.top();
        s.pop();
    }
    cout << answer;
}