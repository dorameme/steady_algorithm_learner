/*
시간복잡도:O(N*K)
공간복잡도:O(N*K)
풀이: 기본적으로 큐로 구현하되 5000이 N과 K의 최대이므로 크기는 충분히 잡아줘야 런타임에러가 안뜬다.
*/
#include <stdio.h>
typedef struct queue
{
    int arr[25000001];
    int front, back;
} Queue;
Queue q;
void push(int num)
{
    q.arr[q.back++] = num;
}

void pop()
{
    q.front++;
}
int top()
{
    return q.arr[q.front];
}
int main()
{
    q.front = 0;
    q.back = 0;
    int num,K;
    scanf("%d %d", &num,&K);
    for (int i = 1; i <= num; i++)
    {
        push(i);
    }
    printf("<");
    while (q.front!=q.back){
        for(int i=1;i<K;i++){
            push(top());
            pop();
        }
        if(q.front+1!=q.back)
        printf("%d, ",top());
        else{
            printf("%d>",top());
        }
        pop();
    }
}
