// #include<iostream>
// #include<queue>

// using namespace std;
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int N, M;
//     queue<int> qx, qy;
//     int map[50][50]={};
//     int wMap[50][50];
//     int bMap[50][50];
//     char c;
//     int min = 50000;
//     cin >> N >> M;

//     for(int i=0; i<N; i++){
//         for(int j=0; j<M; j++){
//             if((i+j)%2==0){
//                 wMap[i][j]=0;
//                 bMap[i][j]=1;
//             }
//             else{
//                 wMap[i][j]=1;
//                 bMap[i][j]=0;
//             }
//         }
//     }
//     for(int i=0; i<N; i++){
//         for(int j=0; j<M; j++){
//             cin >> c;
//             if(c == 'W') map[i][j]=0;
//             else map[i][j]=1;
//         }
//     }

//     for(int x=0; x<=N-8; x++){
//         for(int y=0; y<=M-8; y++){
//             int wCnt=0;
//             int bCnt=0;
//             for(int dx = 0; dx < 8; dx++){
//                 for(int dy=0; dy<8; dy++){
//                     if(map[x+dx][y+dy] != wMap[dx][dy]) wCnt++;
//                     if(map[x+dx][y+dy] != bMap[dx][dy]) bCnt++;
//                 }
//             }
//             if(min > wCnt) min = wCnt;
//             if(min > bCnt) min = bCnt;
//         }
//     }
//     cout << min;
// }

//아주 비슷한 접근이지만 조금은 더 천재적인 방법
//굳이 w시작 체스판이랑 b시작 체스판을 나눌 필요가 없음, 그냥 w를 기준으로 이상한 거 개수를 세었을때 만약 그게 8x8의 칸개수의 절반인 32보다 높다면 b시작 판이었던 걸로하고
//64-cnt하면 되는 거였음

#include<iostream>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    int map[50][50];
    char c;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> c;
            if(c=='W') map[i][j]=0;
            else map[i][j]=1;
        }
    }
    int min = 500000;

    for(int x=0; x<N-7; x++){
        for(int y=0; y<M-7; y++){
            int cnt=0;
            for(int dx=0; dx<8; dx++){
                for(int dy=0;dy<8; dy++){
                    if((x+dx+y+dy)%2==0 && map[x+dx][y+dy]==0) cnt++;
                    else if((x+dx+y+dy)%2==1 && map[x+dx][y+dy]==1) cnt++;
                }
            }

            cnt = cnt >  64-cnt ? 64-cnt : cnt;
            min = min > cnt ? cnt : min;
        }
    }
    cout << min;
}
