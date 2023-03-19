//이렇게 짜면 안되는 이유 queue 에서 넘어가는값이 head 도 포인터고 함수엔 head 의 복사본이 날아간다 따라서 포인터의 주소형인 이중포인터가 필요함 따라서 전역에 포인터 선언필요
#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int val;
    struct queue* next;
} Queue;

void push(Queue *q, int num)
{
    Queue *node = (Queue *)malloc(sizeof(Queue));
    node->val = num;
    node->next = NULL;

    if (q == NULL)
    {
        q = node;
    }
    else
        printf("%d",q->val);
    {
        Queue *i;
        for (i=q; i->next!= NULL; i = i->next);
        i->next = node;
    }
}
int front(Queue *q){
    if(q==NULL){return -1;}
    else{return q->val;}
}

void pop(Queue *q)
{
    Queue *node = q;
    if (q != NULL)
    {
        q = q->next;
        free(node);
    }
}
int main()
{
    Queue* head=NULL;
    int num;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        push(head,i);
        printf("%d",front(head));
    }
    while(head->next!=NULL)
    {
        pop(head);
        push(head,front(head));
        pop(head);
    }        
    printf("%d",front(head));
}

//이렇게 짜면 시간초과 남

#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int val;
    struct queue *next;
} Queue;

Queue *q = NULL;
void push( int num)
{
    Queue *node = (Queue *)malloc(sizeof(Queue));
    node->val = num;
    node->next = NULL;

    if (q == NULL)
    {
        q = node;
    }
    else
    {
        Queue *i;
        for (i = q; i->next != NULL; i = i->next);//이과정이 O(N)이므로 전체적으로 push에서 o(N^2)가 되어 풀어지지않는다.
        i->next = node;
    }
}
int front()
{
    return q->val;
}

void pop()
{
    Queue *node = q;
    if (q != NULL)
    {
        q = q->next;
        free(node);
    }
}
int main()
{
    int num;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        push(i);
    }
    while (q->next != NULL)
    {
        pop();
        push(front());
        pop();
    }
    printf("%d", front());
} 
