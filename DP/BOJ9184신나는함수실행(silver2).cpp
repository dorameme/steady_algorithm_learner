/*
start:16:30
end:17:30
시간복잡도:O(A*B*C)
공간복잡도:O(A*B*C)
풀이: 디피로 저장해서 풀면된다. w(a,b,c)의 값을 dp[a][b][c]에 저장하되 값을 받아서 넘겨줄 때 50 씩더해서 줘야 변수가 음수가 안나온다. 
*/
#include <iostream>
using namespace std;
int dp[102][102][102];
int w(int a, int b, int c)
{
    if(dp[a][b][c])return dp[a][b][c];
    if (a <= 50 || b <= 50 || c <= 50)
        return 1;
    if (a >70 || b > 70 || c > 70)
    {
        return dp[a][b][c] = w(70, 70, 70);
    }
    if (a < b && b < c)
       
        return dp[a][b][c]=w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    return dp[a][b][c]=w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
int main()
{
    ios::syno_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a=1,b,c;
    while(1){
        cin>>a>>b>>c;
        if(a==-1&&b==-1&&c==-1)return 0;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a+50,b+50,c+50)<<"\n";
    }

}
