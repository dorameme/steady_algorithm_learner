/*
start:6~13/14 2일에 걸쳐풀었고 총 3시간 가량 사용
end:
시간복잡도:4^(시도횟수)
공간복잡도:N*M
풀이: 기본적인 구현문제였는데 주의 할점이 몇몇있다.
sol로 들어오는 변수가 음수일수 있으므로 visit표시보단 음수인지아닌지부터확인이 필요했다..
198~199  번줄에서 주의할 점이 하나더 있는데
 if(vis[Rx][Ry][Bx][By]<cnt&& vis[Rx][Ry][Bx][By]!=0)return;
    vis[Rx][Ry][Bx][By]=cnt;
cnt가 더 큰상태에서 먼저들어오고 작은게 들어오면 작은걸 우선으로 생각해야하는데 만일 큰애가 먼저들어와 vis을 1이상으로 만들면
다음에 더 작은 cnt가 들어와도 그냥 함수가 끝나버리므로 안된다. 따라서 vis에 들어온게 cnt보다 작냐 크냐로 비교해야한다.
예시)
  if(vis[Rx][Ry][Bx][By])return;
    vis[Rx][Ry][Bx][By]++;   
  이렇게 짜면 틀린다.
    
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
char dir[] = {'L', 'R', 'U', 'D'};
char arr[20][20];
int N, M;
bool fall(int x, int y)
{
    if (arr[x][y] == 'O')
    {
        return true;
    }
    return false;
}
int L(int x, int y)
{
    while (arr[x][y] != '#')
    {
        y += dy[0];
        if (fall(x, y))
        {
            return -1;
        }
    }
    return y-=dy[0];
}
int R(int x, int y)
{
    while (arr[x][y] != '#')
    {
        y += dy[1];
        if (fall(x, y))
        {
            return -1;
        }
    }
    return y-=dy[1];
}
int U(int x, int y)
{
    while (arr[x][y] != '#')
    {
        x += dx[2];
        if (fall(x, y))
        {
            return -1;
        }
    }
    return x-=dx[2];
}
int D(int x, int y)
{
    while (arr[x][y] != '#')
    {
        x += dx[3];
        if (fall(x, y))
        {
            return -1;
        }
    }
    return x-dx[3];
}
pair<pair<int,int>,pair<int,int>>  solveL(int Rx, int Ry, int Bx, int By)
{
    int A = L(Rx, Ry);
    int B = L(Bx, By);
    if (B == -1)
        return {{-1,-1},{-1,-1}}; // 파란공이 떨어지면 아웃
    else if (A == -1)
    {
        // cout<<"\n"<<Rx<<A<<Bx<<B<<"solved!\n";
        return {{100,100},{100,100}}; // 빨간공만 떨어지면 성공
    }
   if (Rx == Bx && A == B)
    {
        if (Ry < By)
        {
            return{{Rx, A}, {Bx, B + 1}};
        }
        else
        {
           return  {{Rx, A + 1}, {Bx, B}};
        }
    }
    else return {{Rx,A},{Bx,B}};
}
pair<pair<int,int>,pair<int,int>>  solveR(int Rx, int Ry, int Bx, int By)
{///고치기 시작!
    int A = R(Rx, Ry);
    int B = R(Bx, By);
    if (B == -1)
        return {{-1,-1},{-1,-1}}; // 파란공이 떨어지면 아웃
    else if (A == -1)
    {
        // cout<<"\n"<<Rx<<A<<Bx<<B<<"solved!\n";
        return {{100,100},{100,100}}; // 빨간공만 떨어지면 성공
    }
   if (Rx == Bx && A == B)
    {
        if (Ry < By)
        {
           return {{Rx, A - 1}, {Bx, B}};
        }
        else
        {
           return {{Rx, A},{ Bx, B - 1}};
        }
    }
    else return {{Rx,A},{Bx,B}};
}
pair<pair<int,int>,pair<int,int>>  solveU(int Rx, int Ry, int Bx, int By)
{
    int A = U(Rx, Ry);
    int B = U(Bx, By);
    if (B == -1)
        return {{-1,-1},{-1,-1}}; // 파란공이 떨어지면 아웃
    else if (A == -1)
    {
        // cout<<"\n"<<A<<Ry<<B<<By<<"solved!\n";
        return {{100,100},{100,100}}; // 빨간공만 떨어지면 성공
    }
   if (A == B && Ry == By)
    {
        if (Rx < Bx)
        {
            return {{A, Ry},{B+1 , By}} ;
        }
        else
        {
            return {{A+1 , Ry},{B, By}};
        }
    }
    else return {{A,Ry},{B,By}};
}
pair<pair<int,int>,pair<int,int>> solveD(int Rx, int Ry, int Bx, int By)
{
    int A = D(Rx, Ry);
    int B = D(Bx, By);
    if (B == -1)
        return {{-1,-1},{-1,-1}}; // 파란공이 떨어지면 아웃
    else if (A == -1)
    {
        // cout<<"\n"<<A<<Ry<<B<<By<<"solved!\n";
        return {{100,100},{100,100}}; // 빨간공만 떨어지면 성공
    }
    if (A == B && Ry == By)
    {
        if (Rx < Bx)
        {
            return {{A-1, Ry}, {B, By}} ;
        }
        else
        {
            return {{A, Ry}, {B-1, By}};
        }
    }
    else {
        return {{A,Ry},{B,By}};
    }
    
}

int solved=-1;
int vis[20][20][20][20];
vector <char> v;
vector <char> answer;
void sol(int Rx,int Ry,int Bx,int By,int cnt){
   
    if(cnt>10|| Rx==-1){return ;}
    if(Rx==100){
        // cout<<cnt<<"cnt";
        if(answer.size()==0 || answer.size()>cnt){
            answer.clear();
            solved=cnt;
            for(int i=0;i<v.size();i++){
                answer.push_back(v[i]);
            }
        }
        return ;
    }
   //배열에 넣는건 가들어있을수 있으므로 앞에다 두면안돼!
    if(vis[Rx][Ry][Bx][By]<cnt&& vis[Rx][Ry][Bx][By]!=0)return;
    vis[Rx][Ry][Bx][By]=cnt;//순서가 왜....
    
    pair<pair<int,int>,pair<int,int>> cur;
    v.push_back('D');
    // cout<<"D";
    cur=solveD(Rx,Ry,Bx,By);
    sol(cur.X.X,cur.X.Y,cur.Y.X,cur.Y.Y,1+cnt);
    v.pop_back();
    
    v.push_back('U');
    // cout<<"U";
    cur=solveU(Rx,Ry,Bx,By);
    sol(cur.X.X,cur.X.Y,cur.Y.X,cur.Y.Y,1+cnt);
    v.pop_back();
    
    v.push_back('L');
    // cout<<"L";
    cur=solveL(Rx,Ry,Bx,By);
    sol(cur.X.X,cur.X.Y,cur.Y.X,cur.Y.Y,1+cnt);
    v.pop_back();
    
    v.push_back('R');
    // cout<<"R";
    cur=solveR(Rx,Ry,Bx,By);
    sol(cur.X.X,cur.X.Y,cur.Y.X,cur.Y.Y,1+cnt);
    v.pop_back();
    
}
int main()
{
    int Rx, Ry, Bx, By;
    cin >> N >> M;
    string s;
    for (size_t i = 0; i < N; i++)
    {
        cin >> s;
        for (size_t n = 0; n < M; n++)
        {
            arr[i][n] = s[n];
            if (s[n] == 'R')
            {
                Rx = i;
                Ry = n;
                arr[i][n] = '.';
            }
            else if (s[n] == 'B')
            {
                Bx = i;
                By = n;
                arr[i][n] = '.';
            }
        }
    }
    sol(Rx, Ry, Bx, By,0);
    
    // cout<<"\n";
    
    cout<<solved<<"\n";
    for(int i=0;i<answer.size();i++)
    {
        cout<<answer[i];
    }
}
