#include<iostream>

using namespace std;

class Stack {
private :
    int stack[10001];
    int Size=-1;
public :
    void push(int x){
        stack[++Size] = x;
        return;
    }
    int pop(){
        if(empty()) return -1;
        int x = stack[Size--];
        return x;
    }
    int size(){
        return Size+1;
    }
    int empty(){
        if(Size == -1) return 1;
        else return 0;
    }
    int top(){
        if(empty()) return -1;
        else return stack[Size];
    }
};


int main(){
    int T; 
    Stack stack;
    cin >> T;
    while(T--){
        string commend;
        int x;
        cin >> commend;
        
        if(commend == "push"){
            cin >> x;
            stack.push(x);
        }
        else if(commend == "pop"){
            cout << stack.pop() << endl;
        }
        else if(commend == "size"){
            cout << stack.size() << endl;
        }
        else if(commend =="empty"){
            cout << stack.empty() << endl;
        }
        else{
            cout <<stack.top() << endl;
        }
    }   
}


//포인터 버전
#include<iostream>
#include<cstring>
using namespace std;

struct Node{
    int data;
    Node* link;
};

struct Head{
    int Slen=0;
    Node* Tnode=nullptr;
};

void push(Head* head, int data){
    Node* newnode = (Node*)malloc(sizeof(Node));
    if(head->Tnode == nullptr) newnode->link = nullptr;
    else newnode->link = head->Tnode;
    newnode->data = data;
    head->Tnode = newnode;
    head->Slen++;
}

void pop(Head* head){
    if(head->Tnode == nullptr) printf("-1\n");
    else{
        Node* temp = (Node*)malloc(sizeof(Node));
        temp = head->Tnode->link;
        printf("%d\n", head->Tnode->data);
        head->Tnode = temp;
        head->Slen--;
    }
}

void size(Head* head){
    printf("%d\n", head->Slen);
}

void top(Head* head){
    if(head->Tnode == nullptr) printf("-1\n");
    else printf("%d\n", head->Tnode->data);
}

void empty(Head* head){
    if(head->Tnode == nullptr) printf("1\n");
    else printf("0\n");
}

int main(){
    int itr;
    int data;
    Head* head = (Head*)malloc(sizeof(Head));
    scanf("%d", &itr);
    while(itr--){
        char cmd[6];
        scanf("%s", cmd);
        if(!strcmp(cmd, "push")) {
            scanf("%d", &data);
            push(head, data);
        }
        else if(!strcmp(cmd, "pop")) pop(head);
        else if(!strcmp(cmd, "size")) size(head);
        else if(!strcmp(cmd, "empty")) empty(head);
        else if(!strcmp(cmd, "top")) top(head);
    }
}