/*
start:15:11
end:16:03
시간복잡도:O()
공간복잡도:O()..잘모르겠음
풀이:사실 이번 문제에 접근하는게 어려워서 답을 봤다.
dp문제인데 크기가 m인 현 집합을 구하려면 이전집합에 있는 모든 요소들 중 합쳤을때 총 쓰인 특정수의 합이 m이되는 원소를 찾아 푸는 문제였다.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int dp[32001];
int target;
int by;
vector <int> num[100];

int solution(int N, int number) {
    int answer; int sum = 0;
    for(int i = 0; i < 8; ++i){ // 각 항목에다가 N, NN, NNN... 넣어줌
        sum = 10*sum + N;
        num[i].push_back(sum);
    }
    num[1].push_back(N+N);
    num[1].push_back(N*N);
    num[1].push_back(N/N);
    for(int m=2;m<8;m++){//만들거
        for(int i=0;i<m;i++){
            for(int a:num[i]){
                for(int b:num[m-i-1]){
                num[m].push_back(a+b);
                num[m].push_back(a-b);      
                num[m].push_back(a*b); 
                if(b!=0)num[m].push_back(a/b);
                }
            }
        }
    }
    for(int i=0;i<8;i++){
        for(int z=0;z<num[i].size();z++){   
            if(number==num[i][z]){
                cout<<i+1;
                return i+1;
             }
        }
    }
    return -1;
}
