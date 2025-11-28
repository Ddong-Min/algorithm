#include<iostream>
#include<stack>
using namespace std;

int main(){

    int n;
    string cmd;
    cin >> n;

    while(n--){
        cin >> cmd;
        stack<char> s;
        for(int i=0; i<cmd.length(); i++){
            char c =cmd[i];
            if(c=='(') s.push(c);
            else if(!s.empty() && s.top() =='(') s.pop();
            else{
                s.push('x');
                break;   
            }
        }
        if(s.empty()) cout << "YES" << '\n';
        else cout  << "NO" << '\n';
    }
}