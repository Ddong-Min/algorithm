#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, temp;
    vector<int> coin;
    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> temp;
        coin.push_back(temp);
    }
    int ans=0;
    int pos = n-1;
    while(k > 0){
        if(coin[pos] > k){
            pos--;
            continue;
        }
        ans++;
        k -= coin[pos];
    }

    cout << ans;
}