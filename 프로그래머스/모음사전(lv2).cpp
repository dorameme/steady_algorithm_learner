/*
start:14:30
end:14:59
시간복잡도:O(5^N)
공간복잡도:O(1)
풀이:N이 5라서 어차피 완전탐색으로 풀린다. 주의할 점은 밑에 주석으로 달아둠 
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int answer = 0;
int flag;
int cnt;
char alpa[]={'A','E','I','O','U'};
void dfs(string word,string target){
    if(word==target){
        answer=cnt;
        flag=1;
        return;
    }//얘가 맨앞에 와야한다 왜냐면 밑에있는 줄이 더 앞에오면 답의 길이가 5일때 카운트가 안됨 ㅜㅜ
    if(flag==1 ||word.size()==5){
        return;
    }
    for(int i=0;i<5;i++){ 
        cnt++;
        dfs(word+alpa[i],target);
    }
}
int solution(string word) {
    dfs("",word);
    return answer;
}
