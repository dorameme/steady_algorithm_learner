/*
시간복잡도:O(N)
공간복잡도:O(N)
풀이: 배열을이용한 큐
*/
#include <stdio.h>
typedef struct queue{
    int arr[1000000];
    int front, back;
}Queue;
Queue q;
void push(int num){
    q.arr[q.back++]=num;
}   

void pop(){
    q.front++;
}   
int top(){
    return q.arr[q.front];
}
int main(){
q.front=0;
q.back=0;
    int num;
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
        push(i);
    }
    while(q.front+1!=q.back){
        pop();
        push(top());
        pop();
    }
    printf("%d",top());
}   //c로 짜려면 이렇게 짜야한다.
