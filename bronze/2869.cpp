#include<iostream>

using namespace std;

int main(){
    int a, b, v;
    cin >> a >> b >> v;
    int step = a-b;
    cout << (v-a + step-1)/step+1; //올림 나눗셈
}