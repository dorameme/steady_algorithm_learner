/*
투포인터에 주의하자 오른쪽 포인터가 배열크기를 넘어설 때 종료된다.
long long 써야하는지 int 써야하는지도 잘 구분하기
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <cmath>
#define X first
#define Y second
using namespace std;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
long long notPrimeNumber[5400000];
long long arr[5400000];
long long N;
void prime()
{
    for (long long i = 2; i <=N;i++){
        if(notPrimeNumber[i]==false){
            for(long long j=i*i;j<=N;j+=i){
                notPrimeNumber[j]=true;
            }
        }
    }
}
int main()
{
    cin >> N;
    prime();
    vector <long long> add;
    for(int i=2;i<=N;i++){
        if(notPrimeNumber[i]==false){
            add.push_back(i);
        }
    }
    long long answer=0;
    int r=0;
    long long total=0;
    int l=0;
    if(add.size()==0){cout<<0;return 0;}
    while(r<=add.size()){//투포인터에서 주의할점 r=add.size()일떄도 탐색이 필요하다. 왜냐면 마지막값을 가져갈때 +1 되어서 add랑 사이즈가 같아지므로
        if(total<N){
            total+=add[r++];
        }
        else if(total>N){
            total-=add[l++];
        }
        else{
            total-=add[l++];
            answer++;
        }
    }
    cout<<answer;
}
