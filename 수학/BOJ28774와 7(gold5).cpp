/*
startL15:21
end:17:34
시간복잡도:O(lgN)
공간복잡도:O(1)
풀이:아니..엄청오래풀었다. 사실 아이디어 떠올리는게 제일어려웠다
근데 생각해보니 이게 트리구조로 4,7이 반복해 나온다는걸 알 수 있었다.
거기서 착안해서 문제 품 .. 
      ""
     4  7
   47    47
 47 47 47 47  
 대략이렇게 생김 ㅋㅋ
 */
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <string>
using namespace std;

long long binarySum(int num)
{
    long long add = 0;
    for (int i = 0; i <= num; i++)
    {
        add += (1 << i);
    }
    return add;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long N;
    cin >> N;
    string answer = "";
    for (int i = 0;; i++)
    {
        if (binarySum(i) > N)
        {
            if (N % 2 == 0)
                answer ="7";
            else
                answer ="4";
            for (int j = i-1; j > 0; j--)
            {
                N= (N-1)/2;
                if(N%2==0)
                {
                    answer = "7"+ answer;
                }
                else
                {
                    answer = "4"+ answer;
                }
            }
            cout<< answer;
            break;
        }
    }
}
