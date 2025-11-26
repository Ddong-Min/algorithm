#include<iostream>

using namespace std;

int main(){
    int a, b, c;

    while(1){
        cin >> a >> b >> c;
        if(!a||!b||!c){
            break;
        }
        else if( a*a == b*b+c*c || c*c == a*a+b*b || b*b == a*a+c*c){
            cout << "right" << endl;
        }
        else{
            cout << "wrong" << endl;
        }
    }
}