/*
start:15:38
end: 16:17
시간복잡도:O(N*N*K) 
𝑁= N은 가능한 문의 위치 수 (1부터 N까지의 위치)입니다.
𝐾= K는 use의 값으로, 열어야 하는 문 개수입니다.
공간복잡도:O(N*N*K) 
풀이: 디피문제였는데 오랜만이라 그런지 잘못풀어서 답을 좀봤다.. .열심히하자
p.s. memset은 바이트 단위로 초기화한다.
0 또는 -1 외 다른 숫자 초기화는 std::fill을 사용하는 것이 좋다.
std::vector에는 memset을 사용할 수 없다.
다차원 배열에서는 sizeof를 통해 정확한 크기를 사용해야 한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;


int N, use;
vector<int> doors(200);
int dp[22][22][22];

int solve(int o1, int o2, int doorIdx) {
    // 기저 사례: 모든 문을 처리했을 때
  if(doorIdx== use+1){return 0;}
  int &ret = dp[o1][o2][doorIdx];
  if(ret!=-1)return ret;
  ret=0;
  return ret = min(abs(doors[doorIdx]-o1)+ solve(doors[doorIdx],o2,doorIdx+1),
  abs(doors[doorIdx]-o2)+solve(o1,doors[doorIdx],doorIdx+1) );
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int o1, o2;
    cin >> N >> o1 >> o2 >> use;
    memset(dp,-1, sizeof(dp));
    for (int i = 1; i <= use; i++) {
        cin >> doors[i];
    }
   cout<<solve(o1, o2, 1);
    
    return 0;
}
