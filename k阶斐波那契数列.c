#include<stdlib.h>
#include<stdio.h>



// k ��쳲��������е�m ������
// �㷨��������һ������Ϊk �����飬��m>k ʱ�����������ĺͣ�
// ֮�������ֵ����ƽ�ƣ���k ��ֵ����sum����˷���
// Ҳ����ʹ�ö��еķ���
int Fibonacci(int k,int m)
{
    int list[k],i,j,sum=0;
    // initialize value
    for(i=0;i<k;i++)
        list[i]=0;
    list[k-1]=1;

    if(m<0)
        exit(1);
    else if(m<k)
        return list[m];
    else
    {
        for(i=k;i<=m;i++)
        {
            for(j=0;j<k;j++)
            {
                sum=sum+list[j];
            }
            for(j=0;j<k-1;j++)
            {
                list[j]=list[j+1];
            }
            list[k-1]=sum;
            sum=0;
        }
        return list[k-1];
    }
}

int main()
{
    int k,m;
    printf("input k and m:");
    scanf("%d %d",&k,&m);
    printf("\tnumber=%d",Fibonacci(k,m));
}
