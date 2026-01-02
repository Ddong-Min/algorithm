#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, tmp;
    vector<int> time;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> tmp;
        time.push_back(tmp);
    }
    sort(time.begin(), time.end(), [](int a, int b){
        return a < b;
    }); //c++ stl에서 sort는 a==b일때 반드시 false를 반환해야함. 따라서 처음에 a<=b로 할때 segfault발생
    long long int ans = time[0];
    for(int i=1; i<n; i++){
        time[i] += time[i-1];
        ans += time[i];
    }

    cout << ans;
    return 0;
}