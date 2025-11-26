#include<iostream>
#include<set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    set<int> A;
    int M;
    int temp;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> temp;
        A.insert(temp);
    }
    cin >>M;
    for(int i=0; i<M; i++){
        cin >> temp;
        if(A.find(temp) != A.end()){
            cout << "1" << "\n";
        }
        else cout << "0" << '\n';
    }

}