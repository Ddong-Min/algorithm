#include<iostream>

using namespace std;

class Queue{
private :
    int f=-1;
    int r = -1;
    int data[10001];

public :
    void push(int x){
        data[++r] = x;
    }
    int pop(){
        if(empty()) return -1;
        else return data[++f];
    }
    int empty(){
        return f == r ? 1 :0;
    }
    int size(){
        return r - f;
    }
    int front(){
        if(empty()) return -1;
        return data[f+1];
    }
    int back(){
        if(empty()) return -1;
        return data[r];
    }
};

int main(){
    int N, data;
    cin >> N;
    string cmd;
    Queue q;
    while(N--){
        cin >> cmd;
        if(cmd == "push"){
            cin >> data;
            q.push(data);
        }
        else if(cmd == "pop") cout << q.pop() << '\n';
        else if(cmd == "size") cout << q.size() <<'\n';
        else if(cmd=="empty") cout << q.empty() << '\n';
        else if(cmd =="front") cout << q.front() << '\n';
        else if(cmd == "back") cout << q.back() << '\n';
        
    }
}