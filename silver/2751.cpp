#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    bool arr[2000001]={false};
    while(N--){
        int temp;
        cin >> temp;
        arr[temp+1000000]= true;
    }
    for(int i=0; i<2000001; i++){
        if(arr[i]) cout << i-1000000 <<'\n';
    }
}