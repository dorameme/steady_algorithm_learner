/*
start:20:35
end:20:49
시간복잡도:O(N*N)
공간복집도:O(N)
풀이:의외로 간단하다 현재위치에서 봤을때 양옆에 자기보다 큰 막대가 있으면 큰 막대 두개중 작은애 - 자신의 크기만큼 빗물이 모인다 
500개가 최대이므로 브루트포스로 돌려도 250000만큼밖에 안도므로 시간적으로도 충분했다
*/
#include <iostream>
#include <vector>
using namespace std;
int dp[501][2];
int main()
{
    int n, m;
    cin>>n>>m;
    int num;
    int answer = 0;
    vector<int> v;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    for(int i=1;i<m;i++){
        int big=i,big2=i;
        for(int j=0;j<i;j++){
            if(v[big]<v[j])big=j;
        }
        for(int z=i+1;z<m;z++){
            if(v[big2]<v[z])big2=z;
        }
        if(v[big]>v[i]&&v[big2]>v[i])answer+=min(v[big]-v[i],v[big2]-v[i]);
    }
    cout<<answer;
}
