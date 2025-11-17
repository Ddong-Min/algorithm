#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int Euclidian(long long int a, long long int b){
    if(a%b == 0) return b;
    return Euclidian(b, a%b);
}
int main(){
    int T;
    cin >> T;
    int n;
    while(T--){
        cin >> n;
        long long int number[n];
        int answer=0;
        for(int i=0; i<n; i++){
            cin >> number[i];
        }
        long long int i;
        for(i=2; i<pow(10, 18) && answer != 1; i++){
            for(int j=0; j<n; j++){   
                if(i > number[j]) answer = Euclidian(i, number[j]); 
                else answer = Euclidian(number[j], i);         
                if(answer == 1){
                    cout << i << endl;
                    break;
                }
            }
        }
        if(i == pow(10,18)) cout << "-1" << endl;
    }
}


/*
생각해 볼거리
1. 정답은 항상 prime number임

 */