/*
start:9:55
end:10:02
시간복잡도:O(N)
공간복잡도:O(N)
풀이: 해시로 가볍게 풀수있는 문제
*/
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
map <string,int> m; 
bool solution(vector<string> phone_book) {
    bool answer = true;
    for(int i=0;i<phone_book.size();i++){ 
        string s="";
        for(int j=0;j<phone_book[i].size();j++){
            s=s+phone_book[i][j];
            m[s]++;
        }
    }
    for(int i=0;i<phone_book.size();i++){
        if(m[phone_book[i]]>=2)return false;
    }
    return answer;
}
