#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    int n, target, i=1;
    stack<int> s;
    cin >> n;
    vector<char> c;
    while(n--){
        cin >> target;
        while(i <= target){
            s.push(i++);
            c.push_back('+');    
        }
        if(s.top() == target){
            s.pop();
            c.push_back('-');
        }
        else{
            cout << "NO";
            return 0;
        }
    }


    for(int i=0; i<c.size(); i++){
        cout << c[i] << '\n';
    }
}