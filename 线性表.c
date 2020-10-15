#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef int ElemType;

typedef struct List
{
    ElemType *elem;
    int length;
    int listsize;
}List;

void initList(List *L,int size)
{
    L->elem=(ElemType*)malloc(size*sizeof(ElemType));
    if(!L->elem)
    {
        printf("failed to allocate memory");
        exit(1);
    }
    L->length=0;
    L->listsize=size;

    //初始化数值
    int i;
    for(i=0;i<size;i++)
    {
        printf("input list of the %d:",i+1);
        scanf("%d",&L->elem[i]);
        L->length++;
    }
}

void ListInsert(List *L,int site,int elem)
{
    int i;
    ElemType *newbase;
    if(site<1 || site>L->length+1)
    {
        printf("out of range");
        exit(1);
    }
    if(L->length==L->listsize)
    {
        newbase = (ElemType*)realloc(L->elem, (L->listsize+1)*sizeof(ElemType) );
        if(!newbase)
            exit(1);
        L->elem = newbase;
        L->listsize++;
    }
    for(i=L->length;i>=site;i--)
    {
        L->elem[i] = L->elem[i-1];
    }
    L->elem[site-1]=elem;
    L->length++;
}

void PrinteList(List *L)
{
    int i;
    for(i=0;i<L->length;i++)
    {
        printf("%d ",L->elem[i]);
    }
}

void delete(List *L,int site)
{
    int i;
    if(site<1 || site>L->length+1)
    {
        printf("out of range");
        exit(1);
    }
    for(i=site-1;i<L->length;i++)
    {
        L->elem[i]=L->elem[i+1];
    }
//    free(L->elem[L->length-1]);
    L->length--;
//    L->listsize--;
}

int main()
{
    List aa;
    initList(&aa,5);
    // ListInsert(&aa,2,100);
    delete(&aa,5);
    PrinteList(&aa);
    printf("\n%d-%d",aa.length,aa.listsize);
}
