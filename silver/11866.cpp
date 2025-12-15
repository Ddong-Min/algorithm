#include<iostream>

using namespace std;

class Queue{
private:
    int rear = 0;
    int front = 0;
    int* data;
    int size;
public:
    Queue(int N){
        size = N+1;
        data = (int*)malloc(sizeof(int)*size);
    }
    ~Queue(){
        free(data);
    }
    void push(int x){
        data[rear]=x;
        rear = (rear+1)%size;    
    }
    int pop(){
        int v = data[front];
        front = (front+1)%size;
        return v;
    }
    bool empty(){
        return front == rear;
    }
};

int main(){
    int N, K;
    cin >> N >> K;
    Queue q(N);
    for(int i=1; i<=N; i++){
        q.push(i);
    }
    int index=0;
    cout <<"<";
    while(!q.empty()){
        index++;
        int temp = q.pop();
        if(index%K==0){
            if(index!=K) cout << ", "; 
            cout << temp;
        }
        else q.push(temp);
    }
    cout << ">";
}