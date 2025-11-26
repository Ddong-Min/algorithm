#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    for(int i=0; i<3; i++){
        cin >> s;
        if(s!="Fizz" && s!="Buzz" && s!="FizzBuzz"){
            int number = stoi(s)+3-i;
            if(number%15==0) cout << "FizzBuzz";
            else if(number%5==0) cout << "Buzz";
            else if(number%3==0) cout << "Fizz";
            else cout << number;
            break;
        }
    }
}