#include<iostream>

using namespace std;
int arr[20000001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    int temp;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        arr[temp+10000000]++;
    }
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> temp;
        cout <<arr[temp+10000000] << " ";
    }
}