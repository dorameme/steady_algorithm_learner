/*
start:8:40
end:9:37
시간복잡도:O(N^2)
공간복잡도:O(N^2)
풀이:시간초과가 났었는데 Dp를 사용하여 이를 해결했고 경우의 수는 int 를 넘어서서 longlong 을 써줬다.
*/
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
long long solution(vector<int> weights) {
    vector <long long> save[5000];
    long long answer = 0;
    
    for(int i=0;i<weights.size();i++){
        for(int j=2;j<=4;j++){
            save[weights[i]*j].push_back(i);///save 인덱스 무게가 되는 애들//
        }
    }
    long long dp[1001]={0,};
    for(int i=0;i<weights.size();i++){
    if(dp[weights[i]]){
        answer+=dp[weights[i]];
        continue;
    }
    long long arr[100001]={0,};
    long long helper=0;
        for(int j=2;j<=4;j++){
            for(int z=0;z<save[weights[i]*j].size();z++)//무게가 되는 애들리스트
            if(arr[save[weights[i]*j][z]]==0 && save[weights[i]*j][z]!=i)
            {
                arr[save[weights[i]*j][z]]=1;
                helper++;
            }
        }
        dp[weights[i]]=helper;
        answer+=helper;
    }
    return answer/2;
}
