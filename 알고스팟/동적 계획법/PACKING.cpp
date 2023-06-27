//이번엔 아예못풀어서 답지 봄 
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#define X first
#define Y second
using namespace std;
int cache[1011][1011];
string name[100];
int volume[100],need[100];
int n,capacity;
int total;

int pack(int capacity,int item){
    if(item==n)return 0;
    int & ret =cache[capacity][item];
    if(ret!=-1)return ret;
    ret=pack(capacity,item+1);
    if(capacity>=volume[item])
        ret=max(ret,pack(capacity-volume[item],item+1)+need[item]);
    return ret;
}

void reconstruct(int capacity,int item, vector<string>& answer){
    if(item==n)return;
    if(pack(capacity,item)==pack(capacity,item+1)){//만일 내가 이번에 안가져가게되어도 결과가 같다면...
        reconstruct(capacity,item+1,answer);
    }
    else{
       answer.push_back(name[item]);
       total+=need[item];
       reconstruct(capacity-volume[item],item+1,answer);
    }
}

int main(){
    int C;
    cin>>C;
    while(C--){
       total=0;
        fill(&cache[0][0],&cache[1001][1001],-1);
        cin>>n>>capacity;
        for(int i=0;i<n;i++){
            cin>>name[i]>>volume[i]>>need[i];
        }
        vector <string> answer;
        reconstruct(capacity,0,answer);
        cout<<total<<" " <<answer.size()<<"\n";
        for(string s:answer){
            cout<<s<<"\n";
        }
    }
}
