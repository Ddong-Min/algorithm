#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

// hash map으로 구현
// O(n+m)
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int n, m;
//     cin >> n >> m;  
//     unordered_map<string, int> noHear;
//     string temp;
//     for(int i=0; i<n; i++){
//         cin >> temp;
//         noHear.insert({temp, 1});
//     }
//     vector<string> noSeeHear;
//     for(int i=0; i<m; i++){
//         cin >> temp;
//         if(noHear.find(temp) != noHear.end()){
//             noSeeHear.push_back(temp);
//         }
//     }
//     sort(noSeeHear.begin(), noSeeHear.end());
//     cout << noSeeHear.size() << '\n';
//     for(int i=0; i<noSeeHear.size(); i++){
//         cout << noSeeHear[i] << '\n';
//     }
// }


// 2진탐색으로 구현
// O(NlogN + MlogN + KlogK)
bool binarySearch(string* noHear, int start, int end, const string& target){
    if(start > end) return false;
    int mid = (start+end)/2;
    if(noHear[mid] > target) return binarySearch(noHear, start, mid-1, target);
    else if(noHear[mid] < target) return binarySearch(noHear, mid+1, end, target);
    else return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    string noHear[n];
    vector<string> noSeeHear;

    for(int i=0; i<n; i++){
        cin >> noHear[i];
    }
    sort(noHear, noHear+n);

    string target;
    for(int i=0; i<m; i++){
        cin >> target;
        if(binarySearch(noHear, 0, n-1, target)) noSeeHear.push_back(target);
    }
    sort(noSeeHear.begin(), noSeeHear.end());

    cout << noSeeHear.size() << '\n';
    for(int i=0; i<noSeeHear.size(); i++){
        cout << noSeeHear[i] << '\n';
    }
}