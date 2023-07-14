/*
start:9:00
end:10:00
시간복잡도:O(1)
공간복잡도:O(1)
풀이:단순하게 구현문제 o가 이길려면 항상 o가 1개 더많아야함
x가 이길려면 o와 x의 개수가 같아야함
*/

#include <string>
#include <vector>
#include <iostream>
#define X first
#define Y second
using namespace std;

pair<int,int> cnt(vector<string> board){
    int A=0,B=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
         if(board[i][j]=='O'){
            A++;
         } 
          else if(board[i][j]=='X'){
            B++;
         }
        }
    }
    return {A,B};
}
string match(vector<string> board){
    int Acur=0;
    int Bcur=0;
    if(board[0][0]!='.' && board[0][0]==board[0][1]&&board[0][0]==board[0][2]){
        if(board[0][0]=='O')Acur++;
        else Bcur++;
    }if(board[1][0]!='.' &&board[1][0]==board[1][1]&&board[1][0]==board[1][2]){
        if(board[1][0]=='O')Acur++;
        else Bcur++;
    }if(board[2][0]!='.' &&board[2][0]==board[2][1]&&board[2][0]==board[2][2]){
        if(board[2][0]=='O')Acur++;
        else Bcur++;
    }
   if(board[0][0]!='.' &&board[0][0]==board[1][0]&&board[2][0]==board[0][0]){
        if(board[0][0]=='O')Acur++;
        else Bcur++;
    }
    if(board[0][1]!='.' &&board[0][1]==board[1][1]&&board[2][1]==board[0][1]){
        if(board[0][1]=='O')Acur++;
        else Bcur++;
    }
    if(board[0][2]!='.' &&board[0][2]==board[1][2]&&board[2][2]==board[0][2]){
        if(board[0][2]=='O')Acur++;
        else Bcur++;
    }
    if(board[0][0]!='.' && board[0][0]==board[1][1]&&board[0][0]==board[2][2]){
        if(board[0][0]=='O')Acur++;
        else Bcur++;
    }
    if(board[0][2]!='.' && board[0][2]==board[1][1]&&board[0][2]==board[2][0]){
        if(board[0][2]=='O')Acur++;
        else Bcur++;
    }
    
    int Acnt=Acur;
    int Bcnt=Bcur;
    
    if(Acnt==0 &&(Bcnt==1 ||Bcnt==2)){
        cout<<" Bcnt";
        if(Bcnt==2) return "N";
        else if(Bcnt==1 && cnt(board).Y==3 &&cnt(board).X==3 )return "X";
        return "N";
    }
    else if((Acnt==1||Acnt==2) && Bcnt==0 ){
        cout<<"Acnt";
        cout<<Acnt <<" "<<Bcnt<<" \n";
        if(Acnt==2 && cnt(board).X==5&& cnt(board).Y==4 ) return "O";
        else if(Acnt==1 && cnt(board).X== cnt(board).Y+1 ) return "O";
        return "N";
    }
    else if(Acnt>0 && Bcnt>0)
    {
        cout<<"Acnt && Bcnt";
        return "N";
    }
    else if(Acnt==0 && Bcnt==0){
        cout<<"Acnt=0 && Bcnt=0";
        if(cnt(board).X==cnt(board).Y || cnt(board).X==cnt(board).Y+1)
        return "O";
        else 
        return "N";
    }
}
int solution(vector<string> board) {
    if(match(board)=="N")return 0;
    return 1;
}
