/*
start:9:30
end:11:07
시간복잡도:O(1)//어디있든 간에 어차피 500000 까지 다봐야함..
공간복잡도:O(1)
풀이:BFS문제인데 이걸 처음에 그냥 재귀로 풀다가 틀렸다 왜냐믄.. 밑에있는 canVis 를 쓰면 cnt+1이 중구난방으로 순서에 상관없이 작동해서 ㅜㅜ 추가연산이 들어간다
따라서 이를 BFS로 cnt가 순차적으로 늘어나게 풀어야한다!!!! 너무나 중요한사실.. BFS.. 순차적... 주의
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int a, b;
int dp[500001][2]; // 위치// 짝수 홀수..
// void canVis(int now,int cnt)//위치 시간
// {

//     if(b+cnt*(cnt+1)/2>500000)return;

//     if (now < 0 || now > 500000)
//         return;

//     if ( dp[now][cnt%2]!=0 && dp[now][cnt % 2]<=cnt)
//         return;
//     dp[now][cnt% 2] = cnt;
//     canVis(now * 2, cnt + 1);
//     canVis(now + 1, cnt + 1);
//     canVis(now - 1, cnt + 1);
// }이렇게 하면 cnt값이 중구난방이라 느리다 ! BFS 도입!!!! cnt+1 cnt+2... 순으로 계산되도록 ㄱ
void BFS()
{
    queue<pair<int, int>> q;
    q.push(make_pair(a, 0));
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        // cout << cur.first << " " << cur.second << "\n";
        q.pop();
        if((cur.second)*(cur.second+1)/2 > 500000)return;
        if (cur.first < 0 || cur.first > 500000)
            continue;
        if (dp[cur.first][cur.second % 2])
            continue;
        dp[cur.first][cur.second % 2] = cur.second;
        q.push(make_pair(cur.first + 1, cur.second + 1));
        q.push(make_pair(cur.first - 1, cur.second + 1));
        q.push(make_pair(cur.first * 2, cur.second + 1));
    }
}
int main()
{
    cin >> a >> b;
    if (a == b)
    {
        cout << 0;
        return 0;
    }
    BFS();
    // canVis(a, 0);
    for (int i = 0; i < 1000; i++)
    { // i 초에...
        int newB = b + i * (i + 1) / 2;
        if (newB > 500000)
        {
            cout << -1;
            return 0;
        }
        if (dp[newB][i % 2] != 0 && dp[newB][i % 2] <= i)
        {
            cout << i; // 만일 가능하다면...
            return 0;
        }
    }
    cout << -1;
    return 0;
}
