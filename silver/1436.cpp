#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int i=0;
    int number=665;
    while(i<N){
        number++;
        for(int j = number; j>=666; j/=10){
            if((j - 666)%1000 == 0){
                i++;
                break;
            }
        } 
    }
    cout << number;
}