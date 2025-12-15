#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin  >> n;
    vector<int> v;
    int cut = round(n*0.15);
    int temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for(int i=cut; i<n-cut; i++){
        sum += v[i];
    }
    if(n==0) cout << sum;
    else cout << round((float)sum/(n-2*cut));
}