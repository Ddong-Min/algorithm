#include<iostream>
#include<queue>

using namespace std;

struct tree{
    int data;
    int cnt;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    queue<tree> q;
    int n;
    bool visitied[1000001]={false};
    cin >> n;
    tree t = {n, 0};
    q.push(t);
    while(1){
        t = q.front();
        visitied[t.data] = true; //코드가 지저분해서 안했지만 push할때 방문처리하면 성능이 더 좋아짐    
        q.pop();
        if(t.data == 1){
            cout << t.cnt;
            break;
        }
        if(t.data%3==0 && !visitied[t.data/3]) q.push({t.data/3, t.cnt+1});
        if(t.data%2==0 && !visitied[t.data/2]) q.push({t.data/2, t.cnt+1});
        if(!visitied[t.data-1]) q.push({t.data-1, t.cnt+1});
    }
}