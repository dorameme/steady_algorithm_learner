/*
start:결국 못풀어서 힌트를 얻음.
end:
시간복잡도:O(3^10)
공간복잡도:O(1)
풀이: 완전탐색으로 답을 낼 수 있는 문제인데 내가 DP로 풀어서 계속 틀렸다
dp코드만 없애면 정답이었음. 현재까지 쓰인 곡괭이 수에 상관없이 순서에따라 답이 달라질 수 있다는걸 명심! 
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int need(int i, string mineral)
{
    if (i == 0)
        return 1;
    else if (i == 1)
    {
        if (mineral == "diamond")
            return 5;
        else
            return 1;
    }
    else if (i == 2)
    {
        if (mineral == "diamond")
            return 25;
        else if (mineral == "iron")
            return 5;
        else
            return 1;
    }
    return 0;
}
int solve(int c,int stress,int p1, int p2, int p3, int idx, vector<string> minerals)
{
   if ((p1 == 0 && p2 == 0 && p3 == 0) || idx >= minerals.size())
    {
        return stress;
    }
    
    // int &ret = dp[p1][p2][p3][idx]; //이부분에서 틀렸다!
    // if (ret)
    //     return ret;

    // 이미해봤거고 더 스트레스가 크면....
    int ret=987654321;
    if (p1 > 0)
    {
        int new_stress = 0;
        for (int i = idx; i < idx + 5 && i < minerals.size(); i++)
            new_stress += need(0, minerals[i]);
    ret = min(ret,solve(c+1,stress+ new_stress,p1 - 1, p2, p3, idx + 5, minerals)) ;
    }
    if (p2 > 0)
    {
        int new_stress = 0;
        for (int i = idx; i < idx + 5 && i < minerals.size(); i++)
            new_stress += need(1, minerals[i]);
      ret = min(ret, solve(c+1,stress+ new_stress,p1, p2 - 1, p3, idx + 5, minerals) );
    }
    if (p3 > 0)
    {
        int new_stress = 0;
        for (int i = idx; i < idx + 5 && i < minerals.size(); i++)
            new_stress += need(2, minerals[i]);
        ret = min(ret, solve(c+1,stress+ new_stress,p1, p2, p3 - 1, idx + 5, minerals));
    }
    return ret;
}
int solution(vector<int> picks, vector<string> minerals)
{
    return solve(0,0,picks[0], picks[1], picks[2],0,minerals);
}
