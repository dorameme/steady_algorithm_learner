/*
start:10:45
end:11:18
시간복잡도O(4^N)
공간복잡도:O(4^N)
풀이:N이 작아서 완전탐색으로 풀수있었다. 연산의 중간 결과값도 최대10억으로 int 안에 들어옴 하지만 난 long long을 썼다. 
/*
  #include <iostream>
#include <vector>
using namespace std;
int maxdp[12][12][12][12][12];
int mindp[12][12][12][12][12];
long long answer1=-9987654321;
long long answer2=+9987654321;
int op1, op2, op3, op4;
int N;
vector<int> v(101);
void solve(int idx,int a,int b,int c,int d,long long now)
{
    if(a<0||b<0||c<0||d<0){
        return ;
    }
    if (idx == N)
    {
        if(now>answer1)answer1=now;
        if(now<answer2)answer2=now;
        return;
    }
    
    solve(idx+1,a-1,b,c,d,now+v[idx]);
    solve(idx+1,a,b-1,c,d,now-v[idx]);
    solve(idx+1,a,b,c-1,d,now*v[idx]);
    solve(idx+1,a,b,c,d-1,now/v[idx]);
    
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    cin >>op1>>op2>>op3>>op4;
   solve(1,op1,op2,op3,op4,v[0]);
   cout<<answer1<< "\n"<<answer2;
}
