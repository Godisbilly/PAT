#include <stdio.h>

int fib( int n );
void PrintFN( int m, int n );

int main()
{
    int m, n, t;

    scanf("%d %d %d", &m, &n, &t);
    printf("fib(%d) = %d\n", t, fib(t));
    PrintFN(m, n);

    return 0;
}

/* 你的代码将被嵌在这里 */
//斐波那契数的非递归算法

int fib(int n)
{
    if(n == 1 || n == 2)
        return 1;
    int first = 1;
    int second = 1;
    int third = 0;
    for(int i = 3;i <= n;i++)
    {
        third = first + second;
        first = second;
        second = third;
    }
    return third;
}

void PrintFN(int m,int n)
{
    int count = 0;
    int i = 1;
    while(fib(i) <= n)
    {
        if(fib(i) >= m)
        {
            count++;
            printf("%d",fib(i));
            if(fib(i+1) <= n)
                printf(" ");
        }
        i++;
    }
    if(!count)
        printf("No Fibonacci number");
}