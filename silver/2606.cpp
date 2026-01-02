#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n;
    cin >> m;
    vector<vector<int>> v(n+1);
    bool visited[n+1]={false}; ;
    int w,u;
    for(int i =0;i<m; i++){
        cin >> w >> u;
        v[w].push_back(u);
        v[u].push_back(w);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;
    int cnt=0;

    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int next : v[t]){
            if(!visited[next]){
                visited[next]=true;
                q.push(next);
                cnt++;
            }
        }
    }

    cout << cnt;
}   