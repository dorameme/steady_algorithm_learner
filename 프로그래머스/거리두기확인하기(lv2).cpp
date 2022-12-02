/*
start:7:00
end:8:00
시간복잡도:O(N) 주어진 배열들의 값들을 모두순회
공간복잡도:O(1)
풀이: 단순 구현문제였는데... 맨헤튼거리가 2이하인경우를 잘못캐치해서 틀렸었다
내가 짠 코드는 너무 깔끔하지 않으므로 새로운 코드를 밑에 같이 첨부한다.
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;
int dx[] = {0,0,-1,1,0, 2, -2, 0, 1, 1, -1, -1};
int dy[] = {-1,1,0,0,2, 0, 0, -2, 1, -1, 1, -1};
vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer(5);
    int k = 0;
    while (k < 5)
    {

        bool helper = true;
        for (int i = 0; i < 5; i++)
        {
            for (int m = 0; m < 5; m++)
            {

                if (places[k][i][m] == 'P')
                {
                    for (int x = 0; x < 12; x++)
                    {
                        int nx = i + dx[x];
                        int ny = m + dy[x];
                        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
                            continue;
                        if (places[k][nx][ny] == 'P')
                        {
                            if (x < 4)
                            {
                                cout << x << i << m << "\n";
                                helper = false;
                                break;
                            }
                            else if(x<8){
                                
                                if (places[k][i+dx[x]/2][m+dy[x]/2] == 'X' && places[k][i+dx[x]/2][m+dy[x]/2] == 'X')
                                    continue;
                                else
                                {
                                    helper = false;
                                    break;
                                }
                            }
                            else
                            {
                                if (places[k][nx][m] == 'X' && places[k][i][ny] == 'X')
                                    continue;
                                else
                                {
                                    helper = false;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (helper == false)
                {
                    break;
                }
            }
            if (helper == false)
            {
                break;
            }////이런식으로 겹쳐서 빠져나오지말고 함수로 바꿔서 return false/true 로바꾸는게 이쁠듯
        }
        answer[k] = helper;
        k++;
    }
    return answer;
}


#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
"POOOP",
"OXXOX", 
"OPXPX",
"OOXOX",
"POXXP"
*/

bool is_valid_place(const vector<string>& place)
{
    constexpr size_t N = 5;

    vector<vector<int>> is_in_use(
        N,
        vector<int>(N, false)
    );

    int di[] = {1,-1,0,0};
    int dj[] = {0,0,1,-1};

    for(size_t i=0; i!=N; ++i)
        for(size_t j=0; j!=N; ++j)
            if(place[i][j] == 'P'){
                for(size_t k=0; k!=4; ++k){
                    size_t moved_i = i + di[k];
                    size_t moved_j = j + dj[k];

                    if(moved_i >= N || moved_j >= N)
                        continue;

                    switch(place[moved_i][moved_j]){
                        case 'P':
                            return false;
                        case 'O':
                            if(is_in_use[moved_i][moved_j])
                                return false;

                            is_in_use[moved_i][moved_j] = true;
                            break;
                        case 'X':
                            break;
                    }
                }
            }

    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(5);
    for(size_t i=0; i!=5; ++i)
        answer[i] = is_valid_place(places[i]);
    return answer;
}
