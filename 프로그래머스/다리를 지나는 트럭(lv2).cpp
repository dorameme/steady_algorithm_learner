/*
start:10:56
end:11:23
시간복잡도:O(N)
공간복잡도:O(N)
풀이: queue를 이용해서 하나씩 트럭을 이동시킨다.
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int,int>> q;//들어온시간 ,인덱스
    int time=1;
    int now=truck_weights[0];
    int idx=1;
    q.push({1,0});//1초에 들어옴.//인덱스0
    while(!q.empty()){
       time++;
        if(bridge_length<=time-q.front().first){
            now-=truck_weights[q.front().second];
            q.pop();
        }
        if(idx<truck_weights.size()){
            if(now+truck_weights[idx]<=weight &&bridge_length>q.size()){
                now+=truck_weights[idx];
                q.push({time,idx});
                idx++;
            }
        }
        // cout<<"시간 ="<<time<<" 다리위 트럭수="<<q.size()<<" 다리무게="<<now<<" \n"; 
    }
    return time;
}
