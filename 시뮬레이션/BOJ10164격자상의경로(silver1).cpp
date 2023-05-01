/*
start:22:12
end:~9:43(집에가야해서 다음날 이어서품)
시간복잡도:O(M*N)
공간복잡도:O(M*N)
풀이:예외처리가 많이 필요한 구현문제였다. 쉬운문젠데 내가 너무 어렵게 푼듯하다.
*/
#include <iostream>
using namespace std;
long long solve(int a, int b)
{
    long long arr[16][16] = {
        0,
    };
    for (int i = 0; i < a; i++)
    {
        arr[i][0] = 1;
    }
    for (int j = 0; j < b; j++)
    {
        arr[0][j] = 1;
    }
     for (int i = 1; i < a; i++)
     {
         for (int j = 1; j < b; j++)
         {
             arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
    //         cout<<arr[i][j]<<" ";
    //     }cout<<"\n";
     }
     }
    return arr[a - 1][b - 1];
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    if(k==0){
        cout<<solve(n,m);
        return 0;}
    int x = 1+k/m;
    if(k%m==0)x--;
    if(n==1)x=1;
    int y = k % m;
    if(!y)y=m;
    int x2 = 1+n - x;
    if(x2==0)x2=1;
    int y2 = 1+ m - y;
//    cout << x << " " << y << " " << x2 << " " << y2 << "\n";
    cout << solve(x, y) * solve(x2, y2);
}
