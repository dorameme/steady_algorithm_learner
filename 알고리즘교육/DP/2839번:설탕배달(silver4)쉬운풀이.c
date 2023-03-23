/*
풀이: 5로 나누어 떨어질때까지 3을 빼준다.그리고 5로 나누어지면 답에 나누어진 몫을 더하고 답을 프린트한다.
*/
#include <iostream>
using namespace std;
int main()
{
    int num;
    cin >> num;
    int answer=0;
    while(num>0){
        if(num%5==0){
            answer+=num/5;
            cout<<answer;
            return 0;
        }
        else
        {
            num-=3;
            answer++;
        }
    }
    if(num==0){cout<<answer;return 0;}
    cout<<-1;
}
