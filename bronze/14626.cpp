#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int count=0;
    bool even=false;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '*'){
            if( i%2 == 0 ) even = true;
            continue;
        }
        if(i%2 == 0) count += s[i]-'0';
        else count += (s[i]-'0')*3;
    }
    if(even) cout << 10-count%10;
    else{
        if(count%10 ==0 ) cout << 0;
        else cout << (10*(3-(10-count%10-1)%3-1)+ 10-count%10)/3;
    }
}   