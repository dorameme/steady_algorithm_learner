/*
start:
end:
시간복잡도:
공간복집도:
풀이: 항상 풀이에서 시키는 대로 풀어야 정석이다..
나는 그냥 목표값에서 상대값을 뺀것중 제일 가까운걸 찾으려 했는데..
그렇게하지말고 그냥 둘다 더해서 마진구하고 마진작은걸 계속 업데이트가 필요하다...

아래 로직을 뜯어보자
        for (int i = 0; i < n; i++) -> 나는 i값과 함꼐 어울릴 mid를 구해야하고
        {
            int target = k - asc[i]; 
            int p1 = i + 1, p2 = n - 1; // i + 1로 자기 자신을 제외하고 탐색 시작
            //mid는 p1, p2 와 같을 수 있으며 i 보다는 큰값이어야한다.
            // 이진 탐색을 통해 target에 가장 가까운 값 찾기
            while (p1 <= p2)
            {
                int mid = (p1 + p2) / 2;
                int currentSum = asc[i] + asc[mid];
                int currentMargin = abs(k - currentSum);

*/
//틀린코드
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
using namespace std;
int findMargin(int target, int x, int y)
{
    return abs(target - x - y);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> asc(n);
        vector<int> desc(n);
        int num;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            asc[i] = num;
        }
        sort(asc.begin(), asc.end());
        int answer = 0;
        int margin = 987654321;
        for (int i = 0; i < n; i++)
        {
            int target = k - asc[i];
            int p1 = i+1, p2 = n - 1;
            int mid;
            while (p1 <= p2)//둘다 답이 될수있도록..
            {
                mid =(p1 + p2)/2;
                if (asc[mid] < target)
                {
                    p1 = mid+1 ;
                }
                else if (asc[mid] == target)
                {
                    break;
                }
                else if (asc[mid] > target)
                {
                    p2 = mid -1;
                }
            }
            int newMargin = findMargin(k, asc[mid], asc[i]);

            if (newMargin < margin && i != mid && asc[mid] != asc[i])
            {
                answer = 1;
                margin = newMargin;
            }
            else if (newMargin == margin && i != mid && asc[mid] != asc[i] ){
                answer++;
            }
            
        }   
        cout<<answer<<"\n";
    }

}


//맞는코드
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int findMargin(int target, int x, int y)
{
    return abs(target - x - y);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> asc(n);

        for (int i = 0; i < n; i++)
        {
            cin >> asc[i];
        }
        
        sort(asc.begin(), asc.end());
        
        int answer = 0;
        int margin = INT_MAX;
        
        for (int i = 0; i < n; i++)
        {
            int target = k - asc[i];
            int p1 = i + 1, p2 = n - 1; // i + 1로 자기 자신을 제외하고 탐색 시작
            
            // 이진 탐색을 통해 target에 가장 가까운 값 찾기
            while (p1 <= p2)
            {
                int mid = (p1 + p2) / 2;
                int currentSum = asc[i] + asc[mid];
                int currentMargin = abs(k - currentSum);
                
                // 새로운 최소 margin이 발견될 경우 answer 초기화 및 갱신
                if (currentMargin < margin)
                {
                    margin = currentMargin;
                    answer = 1;
                }
                else if (currentMargin == margin) // 동일한 margin이 발견되면 answer 증가
                {
                    answer++;
                }
                
                // 현재 합이 목표 값보다 작으면 더 큰 값으로 이동
                if (currentSum < k)
                {
                    p1 = mid + 1;
                }
                else
                {
                    p2 = mid - 1;
                }
            }
        }
        
        cout << answer << "\n";
    }

    return 0;
}
