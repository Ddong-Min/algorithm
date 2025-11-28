#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    char c;
    string cmd;
    while(1){
        stack<char> s;
        getline(cin, cmd);
        int i=0;
        char c = cmd[i++];
        if(c=='.') break;
        while(c!='.'){
            if(c=='(' || c=='[') s.push(c);
            else if(c==')'){
                if(!s.empty() && s.top()== '(') s.pop();
                else s.push('x');
            }
            else if(c==']'){
                if(!s.empty() && s.top()== '[') s.pop();
                else s.push('x');
            }
            c=cmd[i++];
        }
        if(s.empty()) cout << "yes" << '\n'; 
        else cout << "no" << '\n';
    }
}