/*
이게왜 골드4??? 어려웠음 ..
start:13:38
end: 15:41
시간복잡도:O(N*N)
공간복잡도:O(V+E)
풀이: 위상정렬+ string으로 값이들어오므로 그값을 int형태로 바꾸어주었다,,, 2시간이나 걸렸고 좀더 쉬운풀이를 참고해 넣었다.
50대까지 내려갈수있으므로 ll을이용하여 그 2진수로 나타내줌..ㅎㅎ double로는 무리무리

*/
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef long long LL;
const LL INF = 1LL << 52;
vector<string> candidate(200);
string me, mom, dad;
vector<double> order(2000);
// 계산하기 쉽도록 이름에 번호를 부여하여 계산하자!
map<LL, string> family2;
map<string, LL> family;
int main(void)
{
    LL cnt = 1; // 번호주기..1부터시작
    LL N, M;
    cin >> N >> M;
    string king;
    cin >> king;
    family2[cnt] = king;
    family[king] = cnt++;
    // 연결관계
    vector<LL> adj[200];
    // indegree
    vector<pair<LL,LL>> deg(200);
    for(LL i=1;i<= N;i++)
    {
        cin >> me >> mom >> dad;

        if (!family[me])
        {
        //    cout<<"\n"<<me<<" "<<cnt<<"\n";
            family2[cnt] = me;
            family[me] = cnt++;
        }
        if (!family[mom])
        {
     //       cout<<"\n"<<mom<<" "<<cnt<<"\n";
            family2[cnt] = mom;
            family[mom] = cnt++;
        }
        if (!family[dad])
        {
          //  cout<<"\n"<<dad<<" "<<cnt<<"\n";
            family2[cnt] = dad;
            family[dad] = cnt++;
        }
        adj[family[mom]].push_back(family[me]); // 번호 번호
        adj[family[dad]].push_back(family[me]); // 번호 번호
        deg[family[me]].X += 2;                   // me가 나올려면 위에 2명이 먼저 태어나야함
        deg[family[me]].Y=0;
    }
    for (LL m = 1; m <= M; m++)
    {
        cin >> candidate[m];
    }
    priority_queue <pair<LL, double>> solve;
    for (LL i = 1; i <cnt; i++)
    {
         if (deg[i].X == 0)
        {                 
            if(i==1){  
              solve.push({i, INF}); // solve에 이름번호, 순서를 넣는다
            order[i] = INF;
            }else{
                solve.push({i,0});
            order[i]=0;
            }
    //        cout<<family2[i];

        }
    }
    while (!solve.empty())
    {
        pair<LL, double> cur = solve.top();//이름번호 순서
        solve.pop();
        // adj[cur.X]와 연결된 아이들...
        for (LL i = 0; i < adj[cur.X].size(); i++)
        {
            deg[adj[cur.X][i]].X--;
            if (deg[adj[cur.X][i]].X == 0)
            {
                 
                solve.push({adj[cur.X][i],(deg[adj[cur.X][i]].Y+ cur.Y)/2});
           //      cout<<cur.Y<<"cur"<<i<<"i"<<(deg[adj[cur.X][i]].Y+ cur.Y)/2<<"\n";
                order[adj[cur.X][i]] =( deg[adj[cur.X][i]].Y+ cur.Y)/2;
            }
            else deg[adj[cur.X][i]].Y+=cur.Y;
        }
    }
    double answer=0;
    string who="";
    for (LL i = 1; i <=M;i++ )
    {
        double can=order[family[candidate[i]]];
      //  cout<<"can"<<can<<candidate[i]<<"\n";
        if(answer<=can){
            answer=can;
            who=candidate[i];
        }
    }
    cout<<who;
}


#include <map>
#include <string>
#include <iostream>

using namespace std;

typedef long long LL;
const LL INF = 1LL << 52;
map<string, LL> mp;

int main(void) {
    string ans;
    LL tmp = 0;
    vector<vector<string>> v(3);
    string str;
    int n, m;
    scanf("%d %d", &n, &m);
    cin >> str;
    mp[str] = INF;

    for (int i = 0; i < n; i++) {
        cin >> str, v[0].push_back(str);//자식
        cin >> str, v[1].push_back(str);//부모
        cin >> str, v[2].push_back(str);//부모
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mp[v[0][j]] = (mp[v[1][j]] + mp[v[2][j]]) / 2;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> str;
        if(mp[str] > tmp) tmp = mp[str], ans = str;
    }
    cout << ans << endl;
    return 0;
}
