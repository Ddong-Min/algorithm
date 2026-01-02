// #include<iostream>

// using namespace std;
// int step[300]={};
// int weight[300]={};

// int calWeight(int n){
//     if(weight[n] != 0) return weight[n];
//     if(weight[n-2] == 0) calWeight(n-2);
//     if(weight[n-3] == 0) calWeight(n-3);
//     return weight[n] = (max(step[n-1] + weight[n-3], weight[n-2])+step[n]);
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int n;
//     cin >> n; 
//     for(int i=0; i<n; i++){
//         cin >> step[i];
//     }

//     weight[0] = step[0];
//     if(n>1) weight[1] = step[1]+step[0];
//     if(n>2) weight[2] = max(step[1], step[0])+step[2];
//     cout << calWeight(n-1);
// }


// #include<iostream>

// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cout.tie(NULL);
//     cin.tie(NULL);
//     int dp[301]={}, step[301]={};
//     int n;
//     cin >> n;
//     for(int i=0; i<n; i++){
//         cin >> step[i];
//     }
    
//     dp[0] = step[0];
//     if(n>1) dp[1] = step[0]+step[1];
//     if(n>2) dp[2] = max(step[0], step[1]) + step[2];

//     for(int i=3; i<n; i++){
//         dp[i] = max(step[i-1]+dp[i-3], dp[i-2]) + step[i];
//     }
//     cout << dp[n-1];
// }

//미친 최적화 변수3개 돌려막기
#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int step[301]={};
    int n, a, b, c;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> step[i];
    }
    int result;    
    a = step[0];
    result =a;
    if(n>1){
        b = step[0]+step[1];
        result = b;
    }
    if(n>2){
        c = max(step[0], step[1]) + step[2];
        result = c;
    }    
    for(int i=3; i<n; i++){
        result = max(step[i-1]+a, b) + step[i];
        a=b;
        b=c;
        c=result;
    }
    cout << result;
}