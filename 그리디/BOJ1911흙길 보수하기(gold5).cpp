/*
start:15:35
end:16:58
시간복잡도:O(N)
공간복잡도:O(N)
풀이:정렬해준다음.. 어디까지 타일을 깔았는지 마지막 위치만 담아서 그리디하게 풀어주면 된다!
*/

#include <iostream>
#include <vlgorithm>
using nameector>
#include <aspace std;
#define X first
#define Y second
int main()
{
    int N, L;
    cin >> N >> L;
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].X >> v[i].Y;
    }
    int answer = 0;
    int end = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++)
    {
        if(v[i].Y<=end)continue;
        else if(v[i].X<=end && v[i].Y>end){
            while(v[i].Y>end){
                end+=L;
                answer++;
            }
        }
        else if(v[i].X>end){
            end= v[i].X;
            while(v[i].Y>end){
                end+=L;
                answer++;
            }
        }
    }cout<<answer;
}
