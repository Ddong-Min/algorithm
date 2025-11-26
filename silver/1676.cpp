#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    int cnt10=0, cnt5=0, cnt2=0;

    while(N >0){
        for(int i=N; i>0;){
            if(i%10==0){
                cnt10++;
                i/=10;
            }
            else if(i%5==0){
                cnt5++;
                i/=5;
            }    
            else if(i%2==0){
                cnt2++;
                i/=2;
            }
            else break;
        }
        N--;
    }
    cout << cnt10 + (cnt5 < cnt2 ? cnt5 : cnt2);
}