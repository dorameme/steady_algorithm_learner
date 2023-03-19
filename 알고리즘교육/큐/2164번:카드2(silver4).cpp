/*
start:10:26
end:10:28
시간복잡도:O(N)
공간복잡도:O(N)
풀이: 간단하게 큐를 이용해서 주어진 조건대로 풀어준다
*/

#include <iostream>
#include <queue>
using namespace std;
int main(){
    int num;
    cin>>num;
    queue<int> q;
    for(int i=1;i<=num;i++){
        q.push(i);///우선 주어진 수 들을 다 넣어준다.
    }  
    while(q.size()!=1){
      //뺴준다
      q.pop();
      //뒤로 넣어준다->뺴준다.
        q.push(q.front());
        q.pop();
    } 
    cout<<q.front();
}
