/*
start:11:37
end:12:06
시간복잡도:O(N)
공간복잡도:O(N)
풀이: 하단 참고
*/
#include <iostream>
#include <vector>
using namespace std;
int arr[100001];
long long sum_front[100001];
long long sum_back[100001];
long long sum_mid[100001];
int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    sum_front[0] = arr[0];
    for (int i = 1; i < num; i++)
    {
        sum_front[i] = arr[i] + sum_front[i - 1];
        sum_back[num - i] = arr[num - i] + sum_back[num + 1 - i];
    }
    sum_back[0] = arr[0] + sum_back[1];
    
    long long answer = 0;

    for (int i = 0; i < num; i++)
    {
        long long total = sum_front[i] + sum_back[i] - arr[0] - arr[num - 1];//중간에있으면 양끝에서 시작므로
        //양끝을 뺴주고 i번 째에 꿀을 둔다
        if (answer < total)
            answer = total;
    }//중간에 있을때

    for(int i=1;i<num;i++){////꿀은 맨 뒤에있고 벌은인덱스 1부터~끝까지 시작해야한다.  왜냐면 0번째에 벌이이미 한마리있으므로
        long long total=sum_back[0]+sum_back[i]-arr[0]-2*arr[i];//처음부터 끝까지 +i부터 끝까지 
        //근데 arr[i]를 두 벌 모두 지나므로 두번뺴준다.
        if (answer < total)
            answer = total;
    }//맨뒤에 꿀이있으면

    for(int i=num-2;i>=0;i--){////꿀은 맨 앞에 있고 num-2~0 로 시작해야한다.  왜냐면 num-1번째에 벌이이미 한마리있으므로
        long long total=sum_front[num-1]+sum_front[i]-arr[num-1]-2*arr[i];//처음부터 끝까지 +i부터 끝까지 
        //근데 arr[i]를 두 벌 모두 지나므로 두번뺴준다.
        if (answer < total)
            answer = total;
    }//맨앞에 꿀이있을때
    cout << answer;
}
