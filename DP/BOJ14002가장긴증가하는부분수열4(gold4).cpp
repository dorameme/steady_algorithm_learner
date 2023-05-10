/*
start:18:00
end:19:39
시간복잡도:O(N^2)
공간복잡도:O(N)
풀이: 이해하느라 어려웠다 ...일단 -1인덱스부터 함수를 시작할때 넣어줘야하는이유는 시작점이 0이아닌 모두가 될수있기때문이다!!
*/
#include <iostream>
#include <vector>
using namespace std;
int n, cache[1001], S[1000], choices[1001];
int lis(int start)//start는 인덱스
{
    int &ret = cache[start+1];///이렇게 하는이유는 cache[start+1]이 ret 의 값을 가지게 하기위함.
    if (ret != -1)
        return ret;
    ret = 1;//길이의 최소값
    int bestNext = -1;
    for (int next = start+1; next < n; next++)
    {
        if (start == -1 || S[start] < S[next])
        {
            int cand = lis(next) + 1;//더 큰애
            if (cand > ret)
            {
                ret = cand;
                bestNext = next;
            }
        }
    }
    choices[start+1] = bestNext;
    return ret;
}
void reconstruct(int start, vector<int> &v)
{
    if (start != -1)
        v.push_back(S[start]);
    int next = choices[start + 1];
    if (next != -1)
        reconstruct(next, v);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
    }
    for(int i=0;i<1001;i++){

        cache[i]=-1;
        choices[i]=-1;
    }
    lis(-1);
    vector<int> answer;
    reconstruct(-1, answer);
    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
}
