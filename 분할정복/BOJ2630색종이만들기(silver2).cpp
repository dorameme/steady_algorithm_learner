/*
start:20:30
end:21:00
시간복잡도:O(NlgN)
공간복잡도:O(N)
풀이: 1/4씩 분할해가며 문제를 해결한다 인덱스 쓰는데 애썼다.
*/
#include <iostream>
using namespace std;
int arr[200][200];
int blue,white;
int cnt=1;
int check(int x, int y, int x2, int y2)
{
    for (int i = x; i <= x2; i++)
    {
        for (int j = y; j <= y2; j++)
        {
            if (arr[i][j] != arr[x][y])
                return 0;
        }
    }
    return 1;
}
void solve(int x,int y,int x2,int y2){
  //  cout<<cnt++<<"\n";
    if(check(x,y,x2,y2)){
        if(arr[x][y]==1){blue++;}
        else{white++;}
        return;
    }
    else{
        int mid=(x+x2)/2;
        int mid2=(y+y2)/2;
        solve(x,y,mid,mid2);// 쌍왼
        solve(x,mid2+1,mid,y2);//상 오
        solve(mid+1,y,x2,mid2);//하 왼
        solve(mid+1,mid2+1,x2,y2);//하 오
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    solve(0,0,n-1,n-1);
    cout<<white<<"\n"<<blue;
}
