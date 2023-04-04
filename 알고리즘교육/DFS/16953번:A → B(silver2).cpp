/*
start:16:20
end:16:32
시간복잡도O(N)
공간복잡도:O(N)
풀이:dfs로 쉽게 풀수있다. 풀이법을 2개 써둠. 맞는걸로 참고
*/
#include <iostream>
long long A, B;
using namespace std;
int answer=987654321;
void solve(long long n, int cnt)
{
    if(n==B){
        if(answer>cnt)answer=cnt;
    }
    if (n > B)
    {
        return;
    }
    solve(n * 10 + 1, cnt + 1);
    solve(n * 2, cnt + 1);
}
int main()
{
    cin >> A >> B;
    solve(A, 1);
    if(answer==987654321)cout<<-1;
    else cout << answer;
}

#include <iostream>
#include <queue>
#define X first
#define Y second
long long A, B;
int answer=987654321;
using namespace std;
int main()
{
    cin >> A >> B;
    queue<pair<long long,int> > q;
    q.push(make_pair(A,1));
    while(!q.empty()){
        pair<long long,int> cur=q.front();
        q.pop();
        if(cur.X==B){
            if(answer>cur.Y)answer=cur.Y;
        }
        if(cur.X>B)continue;
        q.push(make_pair(cur.X*10+1,cur.Y+1));
        q.push(make_pair(cur.X*2,cur.Y+1));
    }
    if(answer==987654321)cout<<-1;
    else cout << answer;
}
