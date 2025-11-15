#include<iostream>

using namespace std;

int main(){
    int N;
    int quantity[6]={};
    int T, P;

    cin >> N;
    for(int i=0; i<6; i++){
        cin >> quantity[i];
    }
    cin >> T >> P;
    int ta=0, pa, pr;
    for(int i=0; i<6; i++){
        ta += (quantity[i]+T-1)/T;
    }
    pa = N/P;
    pr = N%P;

    cout << ta << endl;
    cout << pa << " " << pr;
}