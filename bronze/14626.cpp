#include<iostream>
using namespace std;

// int main(){
//     string s;
//     cin >> s;
//     int count=0;
//     bool even=false;
//     for(int i=0; i<s.length(); i++){
//         if(s[i] == '*'){
//             if( i%2 == 0 ) even = true;
//             continue;
//         }
//         if(i%2 == 0) count += s[i]-'0';
//         else count += (s[i]-'0')*3;
//     }
//     if(even) cout << 10-count%10;
//     else{
//         if(count%10 ==0 ) cout << 0;
//         else cout << (10*(3-(10-count%10-1)%3-1)+ 10-count%10)/3;
//     }
// }   

int main(){
    string s;
    cin >> s;
    int count=0, w[2]={1,3};
    int weight;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '*') weight = w[i&1];
        else count = (count + (s[i]-'0')*w[i&1])%10;    
    }
    int i;
    for(i=0; i<10 && count; ++i, count = (count + weight)%10);

    cout << i << endl;

}
//i&1 = 0 i가 짝수
//i&1=1 i가 홀수
/*
 1 => 000001이다.
 i가 짝수이면 xxxxx0
 따라서      000001
 이므로 &연산 하면 000000이다. 따라서 0

 i가 홀수이면 xxxxx1
 따라서      000001
 이므로 &연산 하면 000001. 따라서 1 
*/