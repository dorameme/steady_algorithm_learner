/*
전혀 감이안잡혀서 인터넷 답안을참고하였다.
시간복잡도:O(N^3)
공간복잡도:O(N^2)
풀이: 더미를 1부터 N-1크기까지 쪼갠뒤 하나씩 값을 채워나가면 됨. 중간에 다른 더미랑 연결할때는 각 더미의 크기를 더한뒤 연결 N*M*K 형식으로 연결할때 필요한 추가연산만 해주면 됨.
*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int arr[501][2];
int dp[501][501];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
      cin>>arr[i][0]>>arr[i][1];
  }

  for(int i=1;i<N;i++){///더미 크기(i)
    for(int j=0;j+i<N;j++){//시작점(j)
      dp[j][j+i]=INT32_MAX;
      for(int z=j;z<j+i;z++){///중간점
          dp[j][j+i]=min(dp[j][j+i],dp[j][z]+dp[z+1][j+i]+arr[j][0]*arr[z+1][0]*arr[j+i][1]);
      }
    }
  }
  cout<<dp[0][N-1];
}
