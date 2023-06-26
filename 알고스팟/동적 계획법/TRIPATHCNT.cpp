#include <algorithm>
#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;
int countCache[101][101];
int arr[101][101];
int cache[101][101];
int n;
int C;
int answer = 0;
int path(int x, int y)
{
    if (x == n - 1)
    {
        return arr[x][y];
    }
    int & ret = cache[x][y];
    if(ret!=-1)return ret;
    return ret=max(path(x+1,y+1),path(x+1,y))+arr[x][y];
}
int countPath(int x,int y){
    if(x==n-1)return 1;
    int &ret =countCache[x][y];
    if(ret!=-1)return ret;
    ret=0;
    if(path(x+1,y+1)>=path(x+1,y))ret+=countPath(x+1,y+1);///
    if(path(x+1,y+1)<=path(x+1,y))ret+=countPath(x+1,y);///진짜 천재인줄...
    return ret;
}
int main()
{
    cin >> C;
    while (C--)
    {
        for (int i = 0; i <= 100; i++)
        {
            for (int j = 0; j <= 100; j++)
            {
              countCache[i][j] = cache[i][j] = arr[i][j] = -1;
            }
        }
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cin >> arr[i][j];
            }
        }
        cout << countPath(0, 0) << "\n";
    }
}

