/*
start:17:20
end:17:33
시간복잡도:O(NlgN)//priority queue이므로
공간복잡도:O(N)
풀이:pq를 이용해서 최댓값을 구해준다.
*/
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> pq;
    int answer = 0;
    for(int i=0;i<enemy.size();i++){
        if(enemy[i]>n){
            if(k==0)return i;
            else{
                pq.push(enemy[i]);
                n-=enemy[i];
                while(k){
                    n+=pq.top();
                    pq.pop();
                    k--;
                    if(n>=0)break;
                }
                if(k==0&& n<0)return i;
            }   
        }  
        else{
        pq.push(enemy[i]);
        n-=enemy[i];
        }
    }
    
    return enemy.size();
}
