/*
start:14:30
end:16:06
시간복잡도:O(100) or O(1).//100을 넘지 않으므로 
공간복잡도:O(1)//
풀이: 삼성 문제 풀때 중요한건 메소드 잘 나누고, 주어진 예제랑 똑같이 메소드를 짜는것이 매우 중요하다..는걸 알게되었다 .
문제는 단순 구현 문제였음
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[3][3];
int r, c, k;
int row = 3, col = 3;
vector<int> Row[101];
vector<int> Col[101];
void C()
{

    for (int i = 0; i < col; i++)
    {
        vector<int> numbers(101);
        vector<pair<int, int>> num; /// 등장횟수 . 수
        for (int j = 0; j < Col[i].size(); j++)
        {
            numbers[Col[i][j]]++;
        }
        for (int j = 1; j <= 100; j++)
        {
            if (numbers[j] != 0)
                num.push_back({numbers[j], j});
        }
        sort(num.begin(), num.end());
        Col[i].clear();
        for (auto N : num)
        {
            if (Col[i].size() >= 100)
                break;
            Col[i].push_back(N.second);
            Col[i].push_back(N.first);
            // cout << N.second << N.first << " ";
        }
        // cout << "\n";
        if (row < Col[i].size())
            row = Col[i].size();
        while (Col[i].size() < row)
            Col[i].push_back(0);
    }
    // cout << row << "row\n";

    for (int i = 0; i < 101; i++)
    {
        Row[i].clear();
    }
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < Col[i].size(); j++)
        {
            Row[j].push_back(Col[i][j]);
        }
    }
}
void R()
{
    for (int i = 0; i < row; i++)
    {
        vector<int> numbers(101);
        vector<pair<int, int>> num;
        for (int j = 0; j < Row[i].size(); j++)
        {
            numbers[Row[i][j]]++;
        }
        for (int j = 1; j <= 100; j++)
        {
            if (numbers[j] != 0)
                num.push_back({numbers[j], j});
        }
        sort(num.begin(), num.end());
        Row[i].clear();
        for (auto N : num)
        {
            if (Row[i].size() >= 100)
                break;
            Row[i].push_back(N.second);
            Row[i].push_back(N.first);
            // cout << N.second << N.first << " ";
        }
        // cout << "\n";
        if (col < Row[i].size())
            col = Row[i].size();
        while (Row[i].size() < col)
            Row[i].push_back(0);
    }

    // cout << col << "col\n";
    for (int i = 0; i < 101; i++)
    {
        Col[i].clear();
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < Row[i].size(); j++)
        {
            Col[j].push_back(Row[i][j]);
        }
    }
    // for (int i = 0; i < col; i++)
    // {
    //     for (int j = 0; j < Col[i].size(); j++)
    //     {
    //    //     cout<<Col[i][j];
    //     }//cout<<"\n";
    // }//cout<<"\n\n";
}
int main()
{
    cin >> r >> c >> k;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
            Col[j].push_back(arr[i][j]);
            Row[i].push_back(arr[i][j]);
        }
    }
    int cnt = 0;
    while (1)
    {
        if (cnt > 100)
        {
            cout << -1;
            return 0;
        }
        if (Row[r - 1].size() >= c && Row[r - 1][c - 1] == k)
        {
            cout << cnt;
            return 0;
        }
        cnt++;
        if (row >= col)
            R();
        else
            C();
    }
}
