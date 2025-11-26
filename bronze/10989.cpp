#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
int partition(vector<int> &v, int start, int end){
    int pivot = end;
    int index = start -1;
    for(int i=start; i<end; i++){
        if(v[i] <= v[pivot]){
            index++;
            if(i!=index){
                int temp = v[i];
                v[i]=v[index];
                v[index]=temp;
            }
        }
    }
    index++;
    int temp = v[index];
    v[index] = v[pivot];
    v[pivot] = temp;
    return index;

}   

void quickSort(vector<int> &v, int start, int end){
    if(start > end) return;
    int pivotIndex = partition(v, start, end);
    quickSort(v, start, pivotIndex-1);
    quickSort(v, pivotIndex+1, end);
    return;
}
    */
// int main(){
//     int T;
//     vector<int> v;
//     cin >> T;
//     int temp;
//     while(T--){
//         cin >> temp;
//         v.push_back(temp);
//     }
//     sort(v.begin(), v.end());
//     for(int i=0; i<v.size(); i++){
//         cout << v[i] << endl;
//     }
// }

//이문제는 그냥 이렇게정렬을 하는게 아니었네 메모리가 8mb면 매우작은건가봐

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    int arr[10001]={};      
    int temp;
    cin >> T;
    while(T--){
        cin >> temp;
        arr[temp]++;
    }
    
    for(int i=1; i<10001; i++){
        while(arr[i]--){
            cout << i << '\n';
        }
    }
}