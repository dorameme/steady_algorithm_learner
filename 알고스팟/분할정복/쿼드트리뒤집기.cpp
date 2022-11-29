/*
시간복잡도:O(N)
공간복잡되:O(1)
풀이 : 재귀를 이용하여 풀어주는데 짱어려웠다.. 그래서 정답을 참고하여 풀었다.
String(number, 문자)->
새로 알게된 함수 지정한 길이의 반복 문자열이 포함된 Variant(String) 형식을 반환합니다.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
string reverse(string::iterator &it)
{
    char head = *it++;
    if (head == 'w' || head == 'b')
    {
        return string(1, head);
    }
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);
    return "x"+lowerLeft+lowerRight+upperLeft+upperRight;
}
int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        string quadTree;
        cin >> quadTree;
        string::iterator it = quadTree.begin();
        cout << reverse(it) << "\n";
    }
}
