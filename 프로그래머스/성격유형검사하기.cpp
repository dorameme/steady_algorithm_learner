/*
start:21:15
end:21:25
시간복잡도:O(N) N=choices.size()
공간복잡도:O(1) 어차피 8칸만채우면 된다.
풀이: 너무너무 쉬웠지만 .. 더 깔끔하게 풀려면 방법이 있다. 
1. 우선 mbti 에 관련된건 배열에 넣어둔다.
char MBTI[4][2] = {
    {'R','T'},//서로 비교대상끼리 짝지어 넣어둔디.
    {'C','F'},
    {'J','M'},
    {'A','N'}
}; 이런식으로 그리고 나중에
for(int i = 0; i < 4; ++i){
     if(score[MBTI[i][0]] >= score[MBTI[i][1]]) ans += MBTI[i][0];
     else ans += MBTI[i][1];
}이렇게 for문을 4번돌려 끝내준다.

2. Map을 사용해 불필요한 배열공간을 줄인다..

 map<char,int> score;

*/
#include <string>
#include <vector>


using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int score[500]={0,};
    for(int i=0;i<survey.size();i++){
        if(choices[i]>4){
            score[survey[i][1]]+=choices[i]-4;
        }
        else if(choices[i]<4){
            score[survey[i][0]]+=4-choices[i];//이부분 주의 choices[i]-4로 썼다가 처음에 틀림
        }
    }
    if(score['R']<score['T'])answer+="T";
    else{answer+="R";}
    if(score['C']<score['F'])answer+="F";
    else{answer+="C";}
    if(score['J']<score['M'])answer+="M";
    else{answer+="J";}
    if(score['A']<score['N'])answer+="N";
    else{answer+="A";}
    return answer;
}
