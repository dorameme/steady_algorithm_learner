/*
시간복잡도:O(N)
공간복잡되:O(N)
풀이 : 구현
항상 내가 틀리는거->for문의 인덱스를 중복으로 사용하는 것에 주의하자!
p.s int->21억 정도
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#define X first
#define Y second
using namespace std;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int N, up;
vector<pair<int, int>> photo(101); // 번호-> 추천수, 시간
int deleteIt()
{
    int score = 987654321;
    int time = 987654321;
    int idx = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (photo[i].X > 0)
        { // 추천이있어
            if (score > photo[i].X)
            {
                score = photo[i].X;
                time = photo[i].Y;
                idx = i;
            }
            else if (score == photo[i].X)
            {
                if (time > photo[i].Y)
                {
                    time = photo[i].Y;
                    idx = i;
                }
            }
        }
    }
    return idx;
}
int main()
{
    cin >> N >> up;
    int num;
    int cnt = 0;
    for (int i = 0; i < up; i++)
    {
        cin >> num;
        if (photo[num].X != 0)
        { // 이미 보드에 있어
            photo[num].X++;
        }
        else
        { // x
            cnt++;
            if (cnt > N)
            {
                int idx = deleteIt();
                photo[idx].X = 0;
            }
            photo[num].X++;
            photo[num].Y = i;
        }
    }
    for (int x = 1; x <= 100; x++)
    {
        if (photo[x].X != 0)
        {
            cout << x << " ";
        }
    }
}
