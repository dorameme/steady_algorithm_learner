/*
start:10:00
end:10:41
시간복잡도:O(N)
공간복잡도:O(N)
풀이: 오목에서 누가 이겼는지 찾는 문제인데, 틀렸던 포인트는 -> 6목인경우 ... 여의봉처럼 위아래로 다 6목이상으로 이어져있는지 확인이필요했다.
*/
#include <stdio.h>
int arr[19][19];
int winner(int x, int y)
{
    for (int i = 0; i < 5; i++) // 대각선1 제일 먼저 확인필요
    {
        if (i + x >= 19 || y - i < 0)
            break;
        if (arr[i + x][y - i] != arr[x][y])
            break;
        if (i == 4)
        {
            if (i + x + 1 < 19 && y - i - 1 >= 0 && arr[i + x + 1][y - i - 1] == arr[x][y])
                break;
            if (x - 1 >= 0 && y + 1 < 19 && arr[x - 1][y + 1] == arr[x][y])
                break;
            return 2;
        }
    }
    for (int i = 0; i < 5; i++) // 세로
    {
        if (i + x >= 19)
            break;
        if (arr[i + x][y] != arr[x][y])
            break;
        if (i == 4)
        {
            if (i + x + 1 < 19 && arr[i + x + 1][y] == arr[x][y])
                break;
            if (x - 1 >= 0 && arr[x - 1][y] == arr[x][y])
                break;
            return 1;
        }
    }
    for (int i = 0; i < 5; i++) // 가로
    {
        if (i + y >= 19)
            break;
        if (arr[x][i + y] != arr[x][y])
            break;
        if (i == 4)
        {
            if (i + y + 1 < 19 && arr[x][i + y + 1] == arr[x][y])
                break;
            if (y - 1 >= 0 && arr[x][y - 1] == arr[x][y])
                break;
            return 1;
        }
    }
    for (int i = 0; i < 5; i++) // 대각선2
    {
        if (i + x >= 19 || i + y >= 19)
            break;
        if (arr[i + x][i + y] != arr[x][y])
            break;
        if (i == 4)
        {
            if (i + x + 1 < 19 && y + i + 1 < 19 && arr[i + x + 1][y + i + 1] == arr[x][y])
                break;
            if (x - 1 >= 0 && y - 1 >= 0 && arr[x - 1][y - 1] == arr[x][y])
                break;
            return 1;
        }
    }
    return 0;
}
int main()
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (arr[i][j])
            {
                int winner_pos = winner(i, j);
                if (winner_pos == 1)
                {
                    printf("%d\n%d %d", arr[i][j], i + 1, j + 1);
                    return 0;
                }
                if (winner_pos == 2)
                {
                    printf("%d\n%d %d", arr[i][j], i + 5, j - 3);
                    return 0;
                }
            }
        }
    }
    printf("0");
}
