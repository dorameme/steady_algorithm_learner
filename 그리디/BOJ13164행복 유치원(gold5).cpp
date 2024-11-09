/*
start:8:25
end:10:29
시간복잡도:O(N log N)
공간복잡도:O(N)
풀이: 인접한 차이를 계산하는 그리디문제
어려워서 chatGPT의 도움을 받아 풀었다....
차이가 최소가 되게 하려는것이니.. 제일 차이가 큰 애들 k-1 그룹을 빼주고 계산하면 된다.
(문제를 해결하는 각 단계에서 가장 좋은 선택을 하고, 그 선택이 전체적인 최적해로 이어진다고 가정하는 알고리즘.)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    // 인접한 원생들의 키 차이를 저장
    vector<int> diffs(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        diffs[i] = heights[i + 1] - heights[i];
    }

    // 차이를 오름차순 정렬
    sort(diffs.begin(), diffs.end());

    // 가장 큰 (K - 1)개의 차이를 제외하고 합산
    long long minCost = 0;
    for (int i = 0; i < N - K; ++i) {
        minCost += diffs[i];
    }

    cout << minCost << endl;
    return 0;
}
