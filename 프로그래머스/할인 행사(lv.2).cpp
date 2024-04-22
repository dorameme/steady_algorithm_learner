/*
start:13:05
end:13:21
시간복잡도:O(nm)//n은 discount size, m은 want size
공간복잡도:O(n)
풀이: 맵을 사용해서 현재 몇개의 할인이 더 필요한지 확인한다. 
할인이 모두 되어 wantNum의 value값이 전부 0이 되면 answer++;
*/
#include <string>
#include <vector>
#include <map>
using namespace std;
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    map <string,int> wantNum;   
    int wantCnt=0;
    int answer=0;
    int cnt=0;
    // 필요개수 채우기
    for(int i=0;i<number.size();i++){
        wantNum[want[i]]=number[i];
    }
    //solve
    for(int i=0;i<discount.size();i++){
        if(i>=10 ){//10일 경과
           ++wantNum[discount[i-10]];//필요개수 증가    
        }
        --wantNum[discount[i]];//필요개수 감소
        for(int i=0;i<want.size();i++){
          if(wantNum[want[i]]!=0){
             answer--;
              break;
          }
        }
        answer++;
         
    }
    return answer;
}
