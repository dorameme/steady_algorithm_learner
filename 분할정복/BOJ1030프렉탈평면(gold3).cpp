/*
시작:7:47
종료:10:47
시간복잡도:O(N*M)구해야하는 넓이 만큼이 시간복잡도가된다,
공간복잡되:O(1)
풀이 : 재귀를 이용하여 풀어주는데 짱어려웠다.. 그래서 정답을 참고하여 풀었다.
나는 역시 재귀에 약하다.. 나는 프렉탈평면을 전부 구현하였는데 
그렇게 풀필요없이 그냥 프렉탈평면에서 구해야할 부분만 뺴고 그부분이 검은색이 되는 범위인지 아닌지만판단해주면 되는 문제였다..
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
long long cnt;
long long s, N, K, R1, R2, C1, C2;
int len=1;
int square(int len,int y,int x)
{   

    if(len==1)return 0;
    int border = len / N;
	if (x >= border * (N - K) / 2 && x < border * (N+K) / 2 
    && y >= border * (N - K) / 2 && y < border * (N+K) / 2) 
   {return 1;}
   else{return square(border,y%border,x%border);}
}
int main()
{
    cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;
    while(s--)len*=N;
    for (long long y = R1; y <=R2; y++)
    {
        for(long long x=C1;x<=C2;x++)
       {     
        cout<<square(len,y,x);
        }
        cout<<'\n';
    }
}
