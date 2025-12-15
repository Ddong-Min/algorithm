#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M,N;
    bool *arr;
    cin >> M >> N;
    arr = (bool*)malloc(sizeof(bool)*(N+1));
    for(int i=0; i<=N; i++){
        arr[i]=false;
    }

    for(int i=2; i<=N; i++){
        if(arr[i]) continue;
        else{
            if(i >= M) cout << i << '\n';
            for(int j=i; j<=N; j+=i){
                arr[j]=true;
            }
        }
    }
}