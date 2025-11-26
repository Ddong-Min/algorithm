#include<iostream>

using namespace std;

int main(){
    int N;
    while(1){
        cin >> N;
        int reverse=0;
        if(!N) break;
        
        for(int i=N; i>0; i/=10){
            reverse = reverse*10 + i%10;
        }

        if(reverse == N) cout << "yes" << endl;
        else cout << "no"<<endl;
    }
}