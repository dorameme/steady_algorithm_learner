
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int arr[11];
    int num;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    vector <int> answer;
    answer.push_back(N);
    for (int i = N-1; i >= 1; i--)
    {//맨끝에서 두번쨰부터 봐주면 됨
        int cnt = 0;
        for (int j = 0; j <= N-i; j++)//1개~2~3~
        {
            if(arr[i]==cnt){
                answer.insert(answer.begin()+j,i);
            }
            cnt++;
            
        }
    }
    for(int i=0;i<N;i++){
        cout<<answer[i]<<" ";
    }
}
