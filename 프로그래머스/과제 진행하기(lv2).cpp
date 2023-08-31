/*
start:8:59
end:11:07
시간복잡도:O(N)
공간복잡도:O(N)
풀이: 스트링 파싱 예외처리등이 필요. 백준하곤 좀다른느낌. 보다 연습이 더 필요.
*/
#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
int timer(string time)
{
    return (time[0] - '0') * 600 + (time[1] - '0') * 60 + (time[3] - '0') * 10 + (time[4] - '0'); // 중간에 : 뺴는거 주의
}
int needTime(string time) // 필요한 시간
{
    int need = 0;
    for (int i = 0; i < time.size(); i++)
    {
        need = need * 10 + time[i] - '0';
    }
    return need;
}

vector<string> solution(vector<vector<string>> plans)
{
    vector<string> answer;
    priority_queue<pair<pair<int, int>, string>, vector<pair<pair<int, int>, string>>, greater<pair<pair<int, int>, string>>> pq;

    for (int i = 0; i < plans.size(); i++)
    {
        pq.push({{timer(plans[i][1]), needTime(plans[i][2])}, plans[i][0]});
    } ////시작시간, 걸리는시간,

    stack<pair<pair<int, int>, string>> s;
    pair<pair<int, int>, string> cur = pq.top(); // 시작,걸리는시간
    pq.pop();
    int now = cur.X.X;

    while (!pq.empty())
    {
       
        if(now+cur.X.Y == pq.top().X.X){
              answer.push_back(cur.Y);
              now = now+ cur.X.Y; // 끝냈음.
              cur=pq.top();
                pq.pop();
        }
        else if (now + cur.X.Y > pq.top().X.X) // 시작시간 오바
        {
            cur.X.Y = cur.X.Y - (pq.top().X.X - now);
            s.push(cur);
            cur = pq.top();
            now = cur.X.X;
            pq.pop();
        }
        else
        { // 끝내면
            answer.push_back(cur.Y);
            now = now+ cur.X.Y; // 끝냈음.
            if (!pq.empty() && pq.top().X.X <= now)
            {
                cur = pq.top();
            }
            else{
            if (!s.empty()) // 지금 끝나자마자 뭔가 할게 있음..
            {
                cur = s.top();
                s.pop();
            }
            else
            {
                cur = pq.top();
                pq.pop();
                now = cur.X.X;
            }
            }
        }
    }
    answer.push_back(cur.Y); // 하던거 마져해..
    while (!s.empty())
    {
        answer.push_back(s.top().Y);
        s.pop();
    }
    return answer;
}
