/*
start:11:30
end:13:01
시간복잡도:O(N)
공간복잡도:O(N)
풀이:간단하게 브루트포스로 풀 수있는 문제를 꼬아서 어렵게 풀었다 ㅠㅠ
1. 100에서 움직이기 2. 특정수로 이동한다음 움직이기 두가지로 나눠서 풀면 된다.
그냥 for문으로 하나하나 다 되는수인지 체크해서 계산하면 끝!
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int vis[1000000];
int target;
int button[10];
int minDistance=987654321;
int answer=987654321;
int dist(int channel){
    return abs(target-channel);
}
void move(int channel,int cnt){
    if(channel>=1000000)return;
    int distance=dist(channel)+cnt;
  
    if(vis[channel]==0 || (vis[channel]!=0 && vis[channel]>distance)){
        vis[channel]= distance;
        if(distance<answer){answer=distance;}
        for(int i=0;i<=9;i++){
            if (button[i] != 1)
            {
                int newDist = dist(channel * 10 + i) + cnt + 1;
              
                move(channel * 10 + i, cnt + 1);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>target;
     int M;
     int num;
     cin >> M;
     for (int i = 0; i < M; i++)
     {
         cin >> num;
         button[num] = 1;
    }
    if (target == 100)
     {
        cout<<0;
        return 0;
     }
    answer= dist(100);
    for(int i=0;i<=9;i++){
        if(button[i]!=1){
            move(i,1);
        }
    }
    cout << answer;
}
