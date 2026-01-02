// #include<iostream>

// using namespace std;

// int arr[42]={1,0,1};

// int fibo(int n){
//     if(arr[n] != 0 || n==1) return arr[n];
//     arr[n] = fibo(n-1)+fibo(n-2); 
//     return arr[n];
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int n;
//     cin >> n;
//     fibo(41);
//     int t;
//     for(int i=0; i<n; i++){
//         cin >> t;
//         cout << arr[t] << " " << arr[t+1] << '\n';
//     }
// }



#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[42]={1,0};

    for(int i=2; i<42; i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
    int n, t;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> t;
        cout << arr[t] << " " << arr[t+1] << '\n';
    }
}