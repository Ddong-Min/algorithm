#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int number;
    bool isPrime;
    int answer = 0;
    while(N--){
        isPrime = true;
        cin >> number;
        if(number==1) isPrime = false;
        for(int i=2; i*i <= number && isPrime; i++){
            if(number % i ==0) isPrime = false;
        }

        if(isPrime) answer ++;
    }
    cout << answer;
}


