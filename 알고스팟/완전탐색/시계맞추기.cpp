/*
시간복잡도:O(4^m)
공간복잡도:O(1) 거의 없다고 보면된다.^^
풀이:시계는 16개가있고 버튼이 10개이다.
각 버튼은 4번씩 누를수있다
완전탐색은 보통 O(N^m)의 시간복잡도를 가진다. N은 선택의 가지수, m은 선택해야 하는 수이다.
여기서 N=4 m=10이므로
시간내에 완전탐색으로 풀어낼수있다. 
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
int answer;
int button[10][5] = {
    { 0, 1, 2, -1, -1 },
    { 3, 7, 9, 11, -1 },
    { 4, 10, 14, 15, -1 },
    { 0, 4, 5, 6, 7 },
    { 6, 7, 8, 10, 12 },
    { 0, 2, 14, 15, -1 },
    { 3, 14, 15, -1, -1 },
    { 4, 5, 7, 14, 15 },
    { 1, 2, 3, 4, 5 },
    { 3, 4, 5, 9, 13 }
};
int clocks[16];
bool clocks_12()
{
    for (int i = 0; i < 16; i++)
    {
        if (clocks[i] % 12 != 0)
            return false;
    }
    return true;
}
void make_answer(int button_num, int push_button, int cnt)
{
    if (clocks_12())
    {
        if (answer == -1 || answer > cnt)
            answer = cnt;
        return;
    }
    if (button_num == 10)
        return;
    else
    {
        if (push_button < 4)
        {

        make_answer(button_num + 1, 0, cnt);
            for (int i = 0; i < 5; i++)
            {
                if (button[button_num][i] == -1)
                    break;
                clocks[button[button_num][i]] += 3;
            }

            make_answer(button_num, push_button + 1, cnt + 1);

            for (int i = 0; i < 5; i++)
            {
                if (button[button_num][i] == -1)
                    break;
                clocks[button[button_num][i]] -= 3;
            }
        }
    }
}
int main()
{
    int C;
    cin>>C;
    while (C--)
    {
        answer = -1;
        for (int i = 0; i < 16; i++)
        {
            cin >> clocks[i];
        }
        make_answer(0, 0, 0);
        cout<< answer << "\n";
    }
}
