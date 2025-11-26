#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int number, max = 0;
    float sum =0;
    for(int i=0; i<n; i++){
        cin >> number;
        if(number > max) max = number;
        sum += number;
    }
    cout << (sum/max)*100/n;
}