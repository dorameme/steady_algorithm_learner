/*
start:13:00
end:13:30
시간복잡도:O(N)
공간복잡도:O(N)
풀이:단순하게 두개의 배열을 만들어서 풀어주면 된다. 밑에처럼 풀어도되지만 dp인 만큼 그냥 최솟값을 들고갈 필요없이 dp 자체에 최댓값을 넣어서 데리구다니면 편하다
예를들어 밑에와 같이 풀이가능
long long solution(vector<int> sequence) {
    long long answer = 0;
    long long psum = 0;
    long long ret = -INF;
    vector<long long> arr;
    for(int i = 0 ; i< sequence.size() ; i++){
        arr.push_back(sequence[i]);/arr[i]는 -1 1 -1 1 이 순차적으로 더해져 있음.
        if(i % 2 == 1)
            arr[i] *= -1;
    }
    for(int i = 0 ; i < arr.size(); i++){
        psum = max(psum,0) + arr[i];////지금까지중 최대 psum 거기에 arr[i]값을 더하거나 뺴줌.....
        ret = max(ret, psum);
    }
    psum = 0;
    for(int i = 0 ; i < arr.size(); i++){
        psum = max(psum,0) - arr[i];//지금까지중 최대 psum 거기에 arr[i]값을 더하거나 뺴줌.....
        ret = max(ret, psum);


*/
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long arr[500001];
long long arr2[500001];
long long solution(vector<int> sequence) {
    long long answer=sequence[0];

    long long s1=0;
    long long s2=0;
    for(int i=0;i<sequence.size();i++){
        if(i%2==0)
        {
        arr[1+i]=sequence[i]+arr[i]; 
        arr2[1+i]=-sequence[i]+arr2[i]; 
            }
        else{
        arr[1+i]=-sequence[i]+arr[i]; 
        arr2[1+i]=sequence[i]+arr2[i]; 
        }
        if(s1>arr[i+1])s1=arr[i+1];
        if(s2>arr2[i+1])s2=arr2[i+1];
        if(answer<max(arr[i+1]-s1,arr2[i+1]-s2))answer=max(arr[i+1]-s1,arr2[i+1]-s2);
    }
    
    return answer;
}
