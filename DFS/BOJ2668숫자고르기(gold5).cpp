/*
 start:13:42
end:15:08
시간 복잡도: O(N²)
각 숫자(1~N)에 대해 DFS를 수행 = O(N)
각 DFS는 최악의 경우 N번 탐색 = O(N)
따라서 총 O(N²)
공간 복잡도: O(N)
풀이: 순환하는 고리의 유무로 푸는 문제 dfs인데 아이디어가 신박하다
*/
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int N;
int arr[101];
int vis[101];
vector <int> ans;
void DFS(int start, int cur){
    if(vis[cur]){
        if(start == cur)ans.push_back(cur);
        return;
    }
    vis[cur]=1;
    DFS(start,arr[cur]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=N;i++){
        memset(vis,0,sizeof(vis));
        DFS(i,i);//시작 & 현 idx
    }
    cout<<ans.size()<<"\n";
    for(int node:ans){
        cout<<node<<"\n";
    }
}
