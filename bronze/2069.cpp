#include<iostream>

using namespace std;

int Euclid(int a, int b){
    if(a%b==0) return b;
    else return Euclid(b, a%b);
}
int main(){
    int a,b;
    cin >> a>> b;

    int g = Euclid(a,b);

    cout << g << endl;
    cout << (a/g)*b;
}