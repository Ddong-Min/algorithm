#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
struct Point{
    int x;
    int y;
};
int main(){
    int N;
    cin >> N;
    vector<Point> v;
    Point p;
    for(int i=0; i<N; i++){
        cin >> p.x >> p.y;
        v.push_back(p);
    }

    sort(v.begin(), v.end(), [](Point a, Point b){
        if(a.x > b.x) return false;
        else if(a.x==b.x && a.y > b.y) return false;
        else return true;
    });

    for(int i=0; i<N; i++){
        cout << v[i].x << " " <<v[i].y << '\n';
    }
}