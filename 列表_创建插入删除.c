// #include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
//列表部分
typedef int Elemtype;

typedef struct Link
{
	Elemtype *list;
	int length;
	int size;
}Link;

int init_List(Link *m,int i)//m是列表，i是长度
{
	m->list = (Elemtype*)malloc(i*sizeof(Elemtype));
	if(m->list == NULL)
	{
		printf("allocation failure\n");
		exit(0);
	}
	m->length=0;
	m->size=i;
}

int insert(Link *m,int i,int num)//在i的位置插入num
{
	int j;
	if(i<0 || i > m->size-1)
	{
		printf("\n\n---error :size of 'i' not right");
		exit(0);
	}
	realloc( m->list,(m->size+1) * sizeof(Elemtype) );
	for(j = m->size;j>=i;j--)
	{
		m->list[j] = m->list[j-1];
	}
	m->list[i-1] = num;
}

int delete(Link *m,int i)
{
	int j;
	if(i<0 || i > m->size-1)
	{
		printf("\n\n---error :size of 'i' not right");
		exit(0);
	}
	for(j = i-1;j<m->size;j++)
	{
		m->list[j] = m->list[j+1];
	}
}

int main()
{
	Link m;
	int i,j,a;
	printf("填写链表的长度：");
	scanf("%d",&i);
	init_List(&m,i);
	for(j=0;j<i;j++)
	{
		printf("第%d个元素:",j+1);
		scanf("%d",&a);
		putchar('\n');
		m.list[j]=a;
		if(a==0)
		{
			break;
		}
		m.length++;
	}
	for(j=0;j<i;j++)
	{
		printf("[%d]:%d  ",j+1,m.list[j]);
	}

	insert(&m,2,10);
	putchar('\n');
	for(j=0;j<i+1;j++)
	{
		printf("[%d]:%d  ",j+1,m.list[j]);
	}

	delete(&m,2);
	putchar('\n');
	for(j=0;j<i;j++)
	{
		printf("[%d]:%d  ",j+1,m.list[j]);
	}
}
*/
//----------------------------

// 链表
/*
typedef struct Link
{
	int data;
	struct Link *next;
}Link;

Link *AppendNode(Link *head);
void DisplyNode(Link *head);
void DeleteMemory(Link *head);



int main()
{
	int i=0;
	char c;
	Link *head = NULL;
	printf("do you want to append a new node(Y/N)?\n");
	scanf(" %c",&c);
	while(c=='Y' || c=='y')
	{
		head = AppendNode(head);
		DisplyNode(head);
		printf("do you want to append a new node(Y/N)?");
		scanf(" %c",&c);
		i++;
	}
	printf("%d new nodes have been appended!\n",i);
	DeleteMemory(head);
}

Link *AppendNode(Link *head)
{
	Link *p = NULL,*pr = head;
	int data;
	p = (Link*)malloc(sizeof(Link));
	if(p==NULL)
	{
		printf("No enough memory to allocated!\n");
		exit(0);
	}
	if(head == NULL)
	{
		head = p;
	}
	else
	{
		while(pr->next!=NULL)
		{
			pr = pr->next;
		}
		pr->next = p;
	}
	printf("input number of this number please\n");
	scanf("%d",&data);
	p->data = data;
	p->next = NULL;
	return head;
}

void DisplyNode(Link *head)
{
	int i=1;
	Link *p=head;
	while(p != NULL)
	{
		printf("%d:---%d\n",i,p->data);
		p = p->next;
		i++;
	}
}

void DeleteMemory(Link *head)
{
	Link *p=head,*pr=NULL;
	while(p!=NULL)
	{
		pr=p;
		p=p->next;
		free(pr);
	}
}
*/

 typedef struct Link
{
	int data;
	struct Link *next;
}Link;

Link *initLink(Link *head)
{
    Link *p;
    p->next = NULL;
    head = p;
    char reply;
    printf("do you want to append a node?(Y/N)\n");
    scanf(" %c",&reply);
    while(reply =='Y' || reply=='y')
    {
        p->next = (Link*)malloc(sizeof(Link));
        if(p==NULL)
	    {
	    	printf("No enough memory to allocated!\n");
	    	exit(0);
	    }
        p = p->next;
        printf("input data number:");
        scanf("%d",&p->data);
        p->next = NULL;
        printf("do you want to append a node?(Y/N)\n");
        scanf(" %c",&reply);
    }
    return head;
}

int PrintLink(Link *head)
{
    Link *p=head;
    printf("\n888888****\n");
    while(p->next != NULL)
    {
        p = p->next;
        printf("%d--",p->data);
    }
}

int main()
{
    Link *head=NULL;
    head = initLink(head);
    PrintLink(head);
}
