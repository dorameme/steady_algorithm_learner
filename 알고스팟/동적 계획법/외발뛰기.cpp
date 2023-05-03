/*
start:12:40
end:13:00
시간복잡도:O(N^2)
공간복잡도:O(N^2)
풀이:경로는 무수히 많지만 입력개수는 촤대 100*100 로 10000뿐이므로 비둘기 집의 원리에 의해 중복이 있음을 알수있고 
solve 는 참조적 투명함수이기에 dp로 풀수있다.
*/
#include <iostream>
using namespace std;
int arr[151][151];
int t;
int num;
int vis[151][151];
int answer = 0;
bool solve(int x, int y)
{
    if (x >= num || y >= num )
        return 0;
    if (answer||x == num - 1 && y == num - 1)
    {
        answer = 1;
        return 1;
    }
    if (vis[x][y] != -1)
        return vis[x][y];
    return vis[x][y] = solve(x + arr[x][y], y) || solve(x, arr[x][y] + y);//둘중 정답을 반환
}
int main()
{
    cin >> t;
    while (t--)
    {
        answer = 0;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num; j++)
            {
                vis[i][j] = -1; // before each
                cin >> arr[i][j];
            }
        }
        solve(0,0);
        if (answer)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
