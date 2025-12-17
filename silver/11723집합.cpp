#include<iostream>

using namespace std;

class Set{
private:
    int num=0;
public:
    void add(int x){
        num |= (1<<x); 
    }
    void remove(int x){
        num &= ~(1<<x);
    }
    int check(int x){
        return (num >> x)&1;
    }
    void toggle(int x){
        num ^= (1<<x);
    }
    void all(){
        num = (1<<21)-1;
    }
    void empty(){
        num = 0;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, x;
    Set set;
    string cmd;
    cin >> N;

    while(N--){
        cin >> cmd;
        if(cmd  == "add"){
            cin >> x;
            set.add(x);
        }
        else if(cmd == "remove"){
            cin >> x;
            set.remove(x);
        }
        else if(cmd=="check"){
            cin >> x;
            cout << set.check(x) << '\n';
        }
        else if(cmd == "toggle"){
            cin >> x;
            set.toggle(x);
        }
        else if(cmd == "all"){
            set.all();
        }
        else if(cmd == "empty"){
            set.empty();
        }
    }
}

