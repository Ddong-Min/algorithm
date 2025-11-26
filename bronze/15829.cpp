#include<iostream> 

using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    long long int answer=0;
    int mod = 1234567891;
    long long int expo = 1;
    for(int i=0; i<n; i++){
        answer = (answer + ((s[i]-'a'+1)*expo)%mod)%mod;
        expo = (expo*31)%mod;
    }
    cout << answer;
}
//int범위 2,147,483,647
//1,234,567,891