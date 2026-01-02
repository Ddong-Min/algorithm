#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, n;
    cin >> T;

    while(T--){
        unordered_map<string, int> mp;
        cin >> n;
        string name, speci;
        for(int i=0; i<n; i++){
            cin >> name >> speci;
            mp[speci]++;
        }
        int answer=1;
        for(auto &kv : mp){ //key값들 찾기위해서 set에다가 key저장하고 순회했는데, 그럴 필요없이 mp자체를 tuple형태로 다 받아서 순회하면 됌
            answer *= (kv.second+1);
        }
        answer--;
        cout << answer << '\n';
    }
}