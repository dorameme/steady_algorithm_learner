/*
start:16:40
end:17:09
시간복잡도: O(NM)
공간복잡도: O(NM)
풀이: 그냥 구현문젠데 주의할 점은 밑에 주석달아둠
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<string> b;
void move(){
    for(int i=0;i<b[0].size();i++){
        int idx=b.size()-1;
        for(int j=b.size()-1;j>=0;j--){
            if(b[j][i]!='.'){
                b[idx--][i]=b[j][i];
            }
        }
        for(int k=0;k<=idx;k++){
            b[k][i]='.';////윗부분 다 다시'.'으로 채워줘야함.
        }
    }
}
int dx[]={0,1,1};
int dy[]={1,0,1};
int bfs(){
    int answer=0;
    int used[40][40]={0,};
    for(int i=0;i<b.size()-1;i++){
        for(int j=0;j<b[0].size()-1;j++){
            int flag=0;
            for(int z=0;z<3;z++){
                if(b[i][j]=='.'|| b[i][j]!=b[dx[z]+i][dy[z]+j]){////'.'일땐 연산하면 안됨
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                used[i][j]=1;
              for(int z=0;z<3;z++){
                used[dx[z]+i][dy[z]+j]=1;
                 
              }
            answer=1;
            }
        }
    }
    for(int i=0;i<b.size();i++){
        for(int j=0;j<b[0].size();j++){
           if(used[i][j]==1)b[i][j]='.';
           
        }
    }
    return answer;
}
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    b=board;
    while(1)
    {
    if(bfs()==0){break;}
        move();
    }
    for(int i=0;i<b.size();i++){
        for(int j=0;j<b[0].size();j++){
            if(b[i][j]=='.')answer++;
        }
    }
    return answer;
}
