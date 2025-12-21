#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unordered_map<string, int> nameMap;
    vector<string> indexMap;

    int N, M;
    cin >> N >> M;
    string name;

    for(int i=1; i<=N; i++){
        cin >> name;
        nameMap.insert({name, i});
        indexMap.push_back(name);
    }
 
    string cmd;
    for(int i=0; i<M; i++){
        cin >> cmd;
        if(isdigit(cmd[0])){
            int findIdx = stoi(cmd);
            cout << indexMap[findIdx-1] << '\n';
        }
        else{
            cout << nameMap.find(cmd)->second << '\n';
        }
    }
}
