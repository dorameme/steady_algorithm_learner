/*
start:15:48
end:15:58
시간복잡도:O(N)
공간복잡도:O(N)
풀이:문제를 제대로 이해하지못하여 헤멨다. 근데 진짜 문제 제대로 읽는게 최고임.. 그냥 구현문제였음
*/
#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;


int solution(vector<int> topping) {
    int answer=0;
    vector<int> t=topping;
    vector <int> v1(10001),v2(10001);
    int cnt1=0,cnt2=0;
    for(int i=0;i<topping.size();i++){
        v1[topping[i]]++;
        if(v1[topping[i]]==1){
            cnt1++;
        }
    }
    for(int i=0;i<topping.size();i++){
        v2[topping[i]]++;
        if(v2[topping[i]]==1){
            cnt2++;
        }
        v1[topping[i]]--;
        if(v1[topping[i]]==0){
            cnt1--;
        }
        if(cnt2==cnt1)answer++;
    }
    return answer;
    
}
