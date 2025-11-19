#include<iostream>
#include<algorithm>
#include<chrono>
using namespace std;

// string* sort(string* s, int index){
//     string temp;
//     for(int i=0; i<index; i++){
//         for(int j=0; j<index-i-1; j++){
//             if(s[j].length() > s[j+1].length()){
//                 temp = s[j];
//                 s[j]=s[j+1];
//                 s[j+1] = temp;
//             }else if(s[j].length() == s[j+1].length() && s[j] > s[j+1]){
//                 temp = s[j];
//                 s[j]=s[j+1];
//                 s[j+1] = temp;
//             }
//         }
//     }
//     return s;
// }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, index = 0;
    cin >> T;
    string temp;
    string s[20001];
    for(int i=0; i<T; i++){
        cin >> temp;
        if(find(s, s+index, temp) == s+index){
            s[index++] = temp;
        }
    }
    sort(s, s+index, [](const string& a, const string&b){
        if(a.length() > b.length()) return 0;
        else if(a.length() == b.length() && a > b) return 0;
        else return 1;
    });

    for(int i=0; i<index; i++){
        cout << s[i] << endl;
    }
}