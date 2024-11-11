/*
start:10:23
end:10:45
시간복잡도:O(N^3)
공간복잡도:O(N^2)
풀이: 테스트 셋이 작아서 나는 플로이드 워셜로 풀었다.
근데 초기화할때 memset썼는데 바이트단위로 설정해서 에러났었다.
memset은 한 번에 1바이트씩 값을 채우는 함수.
value는 int 형태로 전달되지만, memset은 이 값을 1바이트로 처리.
예를 들어, memset(arr[i], 10000, sizeof(int))에서 10000은 1바이트 값으로 변환되므로 실제로 0x2710이라는 바이트 값이 배열에 설정된다.
그니까 초기화는 역시 그냥 for문 이나 fill 돌리자..

C++에서는 fill이 가장 간단하고 안전한 방법이며, for 문은 가장 범용적이고 정확한 방법
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin>>N>>M;
    int arr[1001][1001]={};
    int a,b,c;
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++) {
            arr[i][j]=98765432;
        }   
    }
    for(int i=1;i<N;i++){
        cin>>a>>b>>c;
        arr[a][b]=c;
        arr[b][a]=c;
    }
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
            }
        }
    }
    int node1,node2;
    for(int i=0;i<M;i++){
        cin>>node1>>node2;
        cout<<arr[node1][node2]<<"\n";
    }
}
