// #include<iostream>
// #include<algorithm>
// #include<vector>

// using namespace std;
// struct P{
//     int age;
//     string name;
//     int reg;
// };
// int main(){
//     int N;
//     cin >> N;
//     vector<P> v;
//     for(int i=0; i<N; i++){
//         P p;
//         cin >> p.age >> p.name;
//         p.reg=i;
//         v.push_back(p);
//     }
//     sort(v.begin(), v.end(), [](P a, P b){
//         if(a.age > b.age) return false;
//         else if(a.age == b.age && a.reg > b.reg) return false;
//         else return true;
//     });

//     for(int i=0; i<N; i++){
//         cout << v[i].age << " " << v[i].name << '\n';
//     }
// }

//아래는 천재적인 방법

#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    string s[201];
    int age;
    string name;
    while(N--){
        cin >> age >> name;
        s[age] += to_string(age) + " " + name + "\n";
    }
    for(int i=1; i<201; i++){
        cout <<s[i];
    }
}