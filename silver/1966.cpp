// #include<iostream>
// #include<queue>
// #include<algorithm>
// using namespace std;

// struct Document{
//     int idx;
//     int imp;
// };

// int main(){
//     int T;
//     cin >> T;
//     while(T--){
//         int N, M, imp;
//         cin >> N >> M;
//         queue<Document> q;
//         int impArr[N];
//         for(int i=0; i<N; i++){
//             cin >> imp;
//             q.push({i, imp});
//             impArr[i]=imp;
//         }
//         sort(impArr, impArr+N, greater<int>());
//         int topImp = 0;
//         int order = 1;
//         while(!q.empty()){
//             Document temp = q.front();
//             q.pop();
//             if(temp.imp == impArr[topImp] ){
//                 if(temp.idx == M) {
//                     cout << order << '\n';
//                     break;
//                 }
//                 topImp++;
//                 order++;
//             }
//             else if(temp.imp != impArr[topImp]){
//                 q.push(temp);
//             }
//         }
//     }
// }



// #include <cstdio>
// #include <algorithm>

// using namespace std;

// int d[101];
// int s[101];

// int main()
// {
//     int tc;
//     scanf("%d",&tc);
//     int n,m,i,t;
//     for(;tc--;){
//         scanf("%d%d",&n,&m);
//         for(i=0;i<n;++i) scanf("%d",d+i), s[i]=-d[i];
//         sort(s,s+n);
//         t=0;
//         i=0;
//         while(true){
//             while(d[t] != -s[i]) t=(t+1)%n;
//             ++i;
//             if(t==m) break;
//             t=(t+1)%n;
//         }
//         printf("%d\n",i);
//     }
//     return 0;
// }
//분석한 타인 풀이
/*
그냥 배열에 원래 가중치 값, 정렬한 가중치 값을가지는 배열을 만듦
원래 값에서 순환하면서 가중치가 가장높은애부터  몇번째 index에 있나 찾고, m과 동일한 index면 출력

가중치가 동일한게 있어서 해당 index가 한번더 걸릴수있는데 pop()하지 않아도  되는이유
같은 가중ㅇ치가 더 있어도
만약 3인가중치가 3개 있고, 4번재 index에서 처음 발견됬다면 다시돌아서 4번째 index로 오기전에
어차피 3인 가중치를 가진 idnex는 다 나오기 ㄸㅐ문에 4번재로 돌아올때는 3인가중치는 이미 다 찾은 상태일것
그래서 굳이 pop하지 않아도 된다.
*/


//조금은 더 직관적인 풀이
#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    while(T--){
        int N, M;
        cin >> N >> M;
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        for(int i=0; i<N; i++){
            int var;
            cin >> var;
            q.push({var,i});
            pq.push(var);
        }

        int cnt=1;

        while(!q.empty()){
            int currentVar = q.front().first;
            int currentIdx = q.front().second;
            q.pop();
            int targetVar = pq.top();
            if(currentVar == targetVar){
                pq.pop();
                if(currentIdx == M){
                    cout << cnt <<'\n';
                    break;
                }
                else cnt++;
            }
            else q.push({currentVar, currentIdx});
        }
    }
}