
/*
start:9:10
end:9:19
시간복잡도:O(N*K)
공간복잡도:O(N)
풀이:구현문제인데 앞에서 K+1개 까지만 확인해주면 된다는게 포인트. 그리고 마지막에 K를 전부 삭제하지못했으면 뒷부분에서 남은 양만큼 제거해 줘야함.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
string solution(string number, int k) {
    string answer = "";
    int start=0;
    int z=3;
    while(k){
        int idx=0;
        int biggest=-1;
        for(int j=0;j<k+1;j++){
            if(number[start+j]>biggest){
                biggest=number[start+j];
                idx=start+j;
            }
        }
        // cout<<k<<" "<<idx<<"\n";
        answer+=number[idx];
        k=k-idx+start;
        start=idx+1;
        if(k && start>=number.size()){break;}
    }
    for(int i=start;i<number.size();i++){
        answer+=number[i];
    }
    while(k--){
        answer.pop_back();
    }
    return answer;
}
