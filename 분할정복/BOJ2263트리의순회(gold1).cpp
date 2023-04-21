/*
start:17:00
end:17:21
시간복잡도:O(N)
공간복잡도:O(N)
풀이: 이 문제가 분할정복인건 알겠다. 풀 때 inorder의 루트를 기준으로 왼쪽 값 수와 오른쪽 값 수를 이용해서 풀어주면 된다. 
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> in(100001);
vector<int> post(100001);
void solve(int ix, int iy, int px, int py)
{
    for (int i = ix; i <= iy; i++)
    {
        if (in[i] == post[py]) // root//
        {
            cout<<post[py]<<" ";
            int cnt=i-ix-1;
            solve(ix, i - 1, px,px+cnt); // left
            solve(i + 1, iy, px+cnt+1,py-1); // right
        return ;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> in[i]; // inorder
    }
    for (int i = 0; i < n; i++)
    {
        cin >> post[i]; // postorder
    }
    solve(0, n - 1, 0, n - 1); /// 분할정복
}
