// #include<iostream>

// using namespace std;

// int main(){
//     int N;
//     cin >> N;
//     int div5 = N/5;
//     int answer=-1;
//     for(int i=div5; i>=0; i--){
//         if((N-5*i)%3==0){
//             answer = i + (N-5*i)/3;
//             break;
//         }
//     }
//     cout << answer;
// }

//미친 쉬운 방법
/*
일단 최대한 5개씩 묶는다고 생각하자.
N/5

그리고 남는 개수를 생각해보자
남는개수
0개 : 그대로
1개 : 5kg -1, 3kg +2 => + 1
2개 : 5kg -2, 3kg +4 => + 2
3개 : just 3kg +1 => + 1
4개 : 5kg -1, 3kg +3 => + 2

따라서
N%5 == 0 => just N/5
N%5가 홀수 N/5+1;
N%5가 짝수 N/5+2;

*/


#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int answer = (N!=4)&&(N!=7) ? N/5+(N%5>0)+(N%5%2 == 0 && N%5>0) : -1;
    cout << answer;
}