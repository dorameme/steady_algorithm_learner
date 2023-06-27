//내풀이랑 책풀이랑 같아서 내풀이만 올림
#include <algorithm>
#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;
int C;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int N, D, P;

int main()
{
    cin >> C;
    while (C--)
    {
        cin >> N >> D >> P;
        int arr[55][55]={0,};        
        int have[55]={0,};          
    
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> arr[i][j];
                if(arr[i][j]){
                    have[i]++;        
                }
           }
        }
        int Q, num;
        cout << fixed;
        cout.precision(8);
        cin >> Q; // 테스트케이스 수
        while (Q--)
        {
        
            double helper[55][105]={0,}; 
            helper[P][0] = 1;
            cin >> num; /// 여기로 도착!
            if (helper[num][D])
            {
                cout << helper[num][D] << " ";
                continue;
            }

            for (int y = 1; y <= D; y++) // time
            {
                for (int now = 0; now < N; now++)
                {
                    for (int i = 0; i < N; i++) // where
                    {
                        if (!arr[now][i])
                            continue;
                        helper[i][y] += helper[now][y - 1] / have[now];
                    }
                }
            }
            cout << helper[num][D] << " ";
        }cout << "\n";
    }
}
