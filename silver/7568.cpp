#include<iostream>
#include<vector>
using namespace std;

struct P{
    int weight;
    int height;
    int rank=1;
};

int main(){
    int N;
    cin >> N;
    vector<P> v;
    for(int i=0; i<N; i++){
        P p;
        cin >> p.weight >> p.height;
        for(int j=0; j<i;j++){
            if(v[j].weight > p.weight && v[j].height > p.height){
                p.rank++;
            }
            else if(v[j].weight < p.weight && v[j].height < p.height) v[j].rank++;
        }
        v.push_back(p);
    }
    for(int i=0; i<N; i++){
        cout << v[i].rank << " ";
    }
}