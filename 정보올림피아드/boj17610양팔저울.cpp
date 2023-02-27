/*
start:19:00
end:19:52
시간복잡도:O(N)
공간복잡도:O(N)
풀이:그냥 재귀써서 풀었는데 그 방문기록을 남기면서 풀었는데 처음에 무게에 대해서만 방문기록을 남겨서 계속틀렸다..중요한 점은 어떤 추를 사용해 그 무게를 만들었냐도 있기에 무게
와 사용한 추 둘다 저장해서 풀어주어야 했다.
*/

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <queue>
using namespace std;
int k;
int answer=0;
vector<int> v(14);
int visit[4000000][14];
int weight[4000000];
int getWeight(int w, int i)
{
    if(visit[w][i])return 0;//추 종류 인덱스도 방문에 포함해줘야하는이유-> 1 2 더해서 3된거랑 3하나써서 3 된거랑 다르므로...
    visit[w][i] = 1;
    if(weight[w]==0){
        weight[w]=1;
        answer++;
    }
   
    if (i == -1 )
        return 0;
    int result = 1 + getWeight(w, i - 1);
    if (w - v[i] > 0)
        result += getWeight(w - v[i], i - 1);
    if (w - 2 * v[i] > 0)
        result += getWeight(w - 2 * v[i], i - 1);
    return result;
}
int main()
{
    int S = 0;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> v[i];
        S += v[i];
    }
    getWeight(S, k - 1);
    cout<<S-answer;
}
