/*
start:12:20
end:12:32
시간복잡도:O(n)
공간복잡도:O(1)
풀이: 간단한문제인데 더 쉽게푸는방법 밑에 첨부함 그리고 순서상관없으니까 시간복잡도 줄이려면 역시 unordered_set쓰기!
*/
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
int arr[3001];
unordered_set <int >s;
int eleSize;
void helper(int idx,int cnt,int subset,vector<int>& elements){
    s.insert(subset);
    if(cnt==eleSize)return;
    if(idx==elements.size()){idx=0;}
    helper(idx+1,cnt+1,subset+elements[idx],elements);
}
int solution(vector<int> elements) {
    eleSize=elements.size();
    int answer = 0;
  for(int i=0;i<eleSize;i++){
     helper(i+1,1,elements[i],elements);
  }
    return s.size();
}

/*
이풀이가 미쳤음..
나처럼 함수둘 필요없음 
그냥 0부터시작 ,,1부터시작 , 2부터시작 이렇게 하고 만일 인덱스 넘어갈경우 %사용해주면 ㅇㅋㅇㅋ
*/
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
unordered_set <int >s;

int solution(vector<int> elements) {
    for(int i=0;i<elements.size();i++){
        int cnt=0;
        for(int j=i;j<i+elements.size();j++){
            cnt+=elements[j%elements.size()];
            s.insert(cnt);
        }
    }
    return s.size();
}
