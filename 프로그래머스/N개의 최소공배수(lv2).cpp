/*
start:9:50
end:9:55
시간복잡도:O(N)
공간복잡도:O(N)
풀이:간단하게 배수를 찾는문제인데 쉽게푸는법이있다. -> 제일 큰수의 배수씩 최소공배수인지 찾아보는게 좋음! 
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> arr) {
    sort(arr.begin(),arr.end());
    for(int i=arr[arr.size()-1];;i+=arr[arr.size()-1]){
        for(int j=0;j<arr.size();j++){
            if(i%arr[j]==0){
                if(j==arr.size()-1){return i;}
            }
            else break;
        }
    }
    
}
