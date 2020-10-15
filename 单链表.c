#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef int ElemType;

typedef struct Link
{
    ElemType elem;
    struct Link *next;
}Link;

Link *initLink(int n)
{
    // 初始化后只有一个头指针
    int i;
    Link *p,*head,*node;
    head = p;
    for(i=0;i<n;i++)
    {
        node = (Link*)malloc(sizeof(Link));
        printf("input the %d:",i+1);
        scanf("%d",&node->elem);
        p->next=node;
        p=node;
    }
    
    p->next = NULL;
    return head;
}

void LinkInsert(Link *head,int site,ElemType e)
{
    int i=0;
    Link *p=head,*node;
    // 寻找位置节点
    while(p && i<site-1)
    {
        p=p->next;
        i++;
    }
    // 判断site是否大于链表长度
    if(!p || site<1)
    {
        printf("out of range");
        exit(1);
    }
    node = (Link*)malloc(sizeof(Link));
    node->elem = e;
    node->next=p->next;
    p->next=node;
}

void LinkDelete(Link *head,int site)
{
    int i=0;
    Link *p=head,*node;
    while(1)
    {
        if(i==site-1)
        {
            node=p->next;
            p->next=node->next;
            free(node);
            break;
        }

        p=p->next;
        i++;

        if (p==NULL || site<1)
        {
            printf("out of range");
            exit(1);
        }
        
    }
}

void PrintLsit(Link *head)
{
    Link *p;
    p = head;
    while(p->next !=NULL)
    {
        p=p->next;
        printf("%d ",p->elem);
    }
}

int main()
{
    Link *bb;
    bb = initLink(5);
    // LinkInsert(bb,6,66);
    LinkDelete(bb,4);
    PrintLsit(bb);
}