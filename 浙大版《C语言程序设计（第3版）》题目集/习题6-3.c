/*
本题要求实现一个计算整数因子和的简单函数，并利用其实现另一个函数，输出两正整数m和n（0<m≤n≤10000）之间的所有完数。所谓完数就是该数恰好等于除自身外的因子之和。例如：6=1+2+3，其中1、2、3为6的因子。

其中函数factorsum须返回int number的因子和；函数PrintPN要逐行输出给定范围[m, n]内每个完数的因子累加形式的分解式，每个完数占一行，格式为“完数 = 因子1 + 因子2 + ... + 因子k”，其中完数和因子均按递增顺序给出。如果给定区间内没有完数，则输出一行“No perfect number”。
*/

#include <stdio.h>

int factorsum( int number );
void PrintPN( int m, int n );

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    if ( factorsum(m) == m ) printf("%d is a perfect number\n", m);
    if ( factorsum(n) == n ) printf("%d is a perfect number\n", n);
    PrintPN(m, n);

    return 0;
}

/* 你的代码将被嵌在这里 */

int factorsum(int number)
{
    int sum = 0;
    for(int i = 1;i <= number/2;i++)
    {
        //能被整除就是因子
        if(number % i == 0)
            sum += i;
    }
    return sum;
}

void PrintPN(int m,int n)
{
    int count = 0;
    for(int i = m;i <= n;i++)
    {
        //如果是完数
        if(factorsum(i) == i)
        {
            count++;
            int sum = 0;
            printf("%d = ",i);
            for(int j = 1;j <= i/2;j++)
            {
                if(i % j == 0)
                {
                    sum += j;
                    printf("%d",j);
                    if(sum < i)
                        printf(" + ");
                    else 
                        printf("\n");
                }
            }
        }
    }
    if(!count)
        printf("No perfect number\n");
}
