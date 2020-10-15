#include<stdlib.h>
#include<stdio.h>



// k 阶斐波那契数列第m 个数字
// 算法描述：设一个长度为k 的数组，在m>k 时，先求出数组的和，
// 之后数组的值向左平移，第k 个值等于sum，如此反复
// 也可以使用队列的方法
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
