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
