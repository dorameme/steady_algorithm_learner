/*
start:10:00
end:11:32
시간복잡도:O(n*m*m)
공간복잡도:O(n*m*m)//한칸씩 열을 움직일때마다 연산필요
풀이:아니..반례찾느라 너무 어려웠다. 그리고 주의할점 !! 시간초과때문에 움직임을 나머지계산해줘야하는데 n,m을 그대로 나누는게 아닌 이동은 n-1,m-1만큼씩 움직이므로 그만큼 2*(n-1) 2(m-1)
 씩 해줘야했다. 이해함? 한번 왕복해서제자리에 오는데 저만큼 걸린다는 거임;;;
 */
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 1, -1}; // 0,위,아래,오른쪽,왼쪽
int sea[102][102];           // 물고기 번호를 담고있음.
int n, m, f;
int answer;
vector<tuple<pair<int, int>, pair<int, int>, int>> fish(100001); // x,y,speed,dir,weight
void get_fish(int m)
{
    for (int i = 1; i <= n; i++)
    {
        if (sea[i][m])
        {
            cout<<i<<m<<" "<<get<2>(fish[sea[i][m]])<<"im\n";
            answer += get<2>(fish[sea[i][m]]);
            fish[sea[i][m]] = {{0, 0}, {0, 0}, 0};
            sea[i][m] = 0;
            return;
        }
    }
}
void fish_move()
{
    int arr[102][102] = {
        0,
    };                           // 어레이 임시로 만들고
    for (int i = 1; i <= f; i++) // 물고리들을 이동시키자
    {
        if (get<2>(fish[i])) // 크기값이 있으면
        {
            int x = get<0>(fish[i]).first;
            int y = get<0>(fish[i]).second;
            //  cout<<"start "<<x<<" "<<y<<"\n";
            int dir = get<1>(fish[i]).second;
            int goX = dx[dir];
            int goY = dy[dir];
            for (int s = 0; s < get<1>(fish[i]).first; s++) // 속력만큼 이동해
            {
                //  cout<<"GO"<<goX<<" "<<goY<<"\n";
                if (x + goX <= 0 || x + goX > n || y + goY <= 0 || y + goY > m)
                { // 만일 벽에 부딫히면 방향을 바꿔
                    goX *= -1;
                    goY *= -1;
                    // cout<<x + goX<<" "<<y + goY <<"why";
                    if (get<1>(fish[i]).second == 1)
                        get<1>(fish[i]).second = 2;
                    else if (get<1>(fish[i]).second == 2)
                        get<1>(fish[i]).second = 1;
                    else if (get<1>(fish[i]).second == 3)
                        get<1>(fish[i]).second = 4;
                    else if (get<1>(fish[i]).second == 4)
                        get<1>(fish[i]).second = 3;
                }
                x = x + goX;
                y = y + goY;
                // cout <<"now"<< x << " " << y << " " << goX << " " << goY << "\n";
            }
            
            // 다이동하면 다시 어레이에 넣어
            //위치 바꿔줘
            get<0>(fish[i])={x,y};
            if (arr[x][y])
            {
                arr[x][y] = get<2>(fish[arr[x][y]]) > get<2>(fish[i]) ? arr[x][y] : i; // 어레이에넣는데 만일 이미 물고기가있으면 크기비교해서 없애
                if(get<2>(fish[arr[x][y]])>get<2>(fish[i])){
                    get<2>(fish[i])=0;
                }
                else
                    get<2>(fish[arr[x][y]])=0;
                
            }
            else
            {
                // cout << " " << x << " " << y << "\n";
                arr[x][y] = i;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            sea[i][j] = arr[i][j];
            cout << sea[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    cin >> n >> m >> f;
    int a, b, c, d, e;
    for (int i = 1; i <= f; i++)
    {
        cin >> a >> b >> c >> d >> e;
        fish[i] = make_tuple(make_pair(a, b), make_pair(c, d), e);
        sea[a][b] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        get_fish(i);
        fish_move();
    }
    cout << answer;
}
