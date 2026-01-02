#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[12]={0,1,2,4};
    int T, num;
    cin>> T;

    for(int i=4; i<11; i++){
        arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
    }
    while(T--){
        cin >> num;
        cout << arr[num] << '\n';
    }

}