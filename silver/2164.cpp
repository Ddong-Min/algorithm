#include<iostream>

using namespace std;

class Queue{
private:
    int data[500001];
    int front=-1;
    int end=-1;
public:
    void push(int x){
        data[++end%500001]=x;
    }
    int pop(){
        return data[++front%500001];
    }
    int empty(){
        return front == end;
    }
};
int main(){
    int N;
    cin >> N;
    Queue q;
    for(int i=1; i<=N; i++){
        q.push(i);
    }
    int answer;
    while(1){
        answer = q.pop();
        if(q.empty()){
            cout << answer;
            break;
        }
        q.push(q.pop());
    }

}