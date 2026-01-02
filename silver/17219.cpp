#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s1, s2;
    unordered_map<string, string> mp; //최적화 1 : unordered_map은 o(1)이라 더 빠름
    int n, m;
    cin >> n >> m;
    mp.reserve(n); // 해시 크기 테이블을 미리 정하면 재해싱 비용을 줄일수있음

    for(int i=0; i<n;i++){
        cin >> s1 >> s2;
        mp.insert({s1, s2});
    }
    for(int i=0; i<m; i++){
        cin >> s1;
        cout << mp[s1] << '\n';
    }
}