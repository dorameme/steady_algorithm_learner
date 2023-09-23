/*
start:17;10
end:19:41
시간복잡도:O(N)
공간복잡도:O(N)
풀아:그냥 구현인데 엄청 오래걸렸다 이렇게 푸는것보다
void rollWest()
{
    dice = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
}
이런식으로 굴렸을떄 dice의 어떤인덱스를 참고하게되는지를 표현하는게 쉽게 풀수 있다 ㅠㅠ 나는 일일이 다 구현햇음 ㅠㅠㅠㅠ
*/
#include <iostream>
using namespace std;
int N, M;
int x, y;
int K;
int arr[21][21];
int dice[4][4];

void diceMove4(int x, int y)
{
    if(arr[x][y]==0)arr[x][y]=dice[2][1];
    else {
        int t=arr[x][y];
        arr[x][y]=0;
        dice[2][1]=t;
    }
    int tmp = dice[1][1];
    dice[1][1] = dice[2][1];
    dice[2][1] =dice[3][1];
    dice[3][1] = dice[0][1];
    dice[0][1] = tmp;
    
    cout << dice[3][1]<<"\n";
}
void diceMove3(int x, int y)
{
    if(arr[x][y]==0)arr[x][y]=dice[0][1];
    else {
        int t=arr[x][y];
        arr[x][y]=0;
        dice[0][1]=t;
    }
    int tmp = dice[1][1];
    dice[1][1] = dice[0][1];
    dice[0][1] = dice[3][1];
    dice[3][1] = dice[2][1];
    dice[2][1] = tmp;
    cout << dice[3][1]<<"\n";
}
void diceMove2(int x, int y)
{
    if(arr[x][y]==0)arr[x][y]=dice[1][0];
    else {
        int t=arr[x][y];
        arr[x][y]=0;
        dice[1][0]=t;
    }
    int tmp = dice[1][1];
    dice[1][1] =dice[1][0];
    dice[1][0] = dice[3][1];
    dice[3][1] = dice[1][2];
    dice[1][2] = tmp;
    cout << dice[3][1]<<"\n";
}
void diceMove1(int x, int y)
{
    if(arr[x][y]==0)arr[x][y]=dice[1][2];
    else {
        int t=arr[x][y];
        arr[x][y]=0;
        dice[1][2]=t;
    }
    int tmp = dice[1][1];
    dice[1][1] = dice[1][2];
    dice[1][2] = dice[3][1];
    dice[3][1] = dice[1][0];
    dice[1][0] = tmp;
    cout << dice[3][1]<<"\n";
    

    
}
void dir1()
{
    if (y + 1 >= M)
        return;
    diceMove1(x, y + 1);
    y++;
}
void dir2()
{
    if (y - 1 < 0)
        return;
    diceMove2(x, y - 1);
    y--;
}
void dir3()
{
    if (x - 1 < 0)
        return;
    diceMove3(x - 1, y);
    x--;
}
void dir4()
{
    if (x + 1 >= N)
        return;
    diceMove4(x + 1, y);
    x=x+1;
}
int main()
{
    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    while (K--)
    {
        int num;
        cin >> num;
        if (num == 1)
        {
            dir1();
        }
        else if (num == 2)
        {
            dir2();
        }
        else if (num == 3)
        {
            dir3();
        }
        else
        {
            dir4();
        }
    }
}
