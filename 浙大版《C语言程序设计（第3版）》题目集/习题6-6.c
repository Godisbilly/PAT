#include <stdio.h>

//实现一个求整数的逆序数的简单函数

int reverse( int number );

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", reverse(n));

    return 0;
}

/* 你的代码将被嵌在这里 */

#define MAX 10000

int reverse(int number)
{
    if(number == 0)
        return 0;
    int flag = 0;
    //如果是正数，则保持不变；如果是负数，则转换为正数，再计算。
    if(number > 0)
        flag = 1;
    if(number < 0)
    {
        flag = -1;
        number = -number;
    }
    //先将数尾部的0去掉
    while(number % 10 == 0)
    {
        number /= 10;
    }
    
    //处理过的数尾部不是0
    int num[MAX];
    int count = 0;
    while(number)
    {
        num[count++] = number % 10;
        number /= 10;
    }
    
    int number1 = 0;
    for(int i = 0;i < count;i++)
    {
        number1 += num[i];
        number1 *= 10;
    }
    number1 /= 10;
    return flag * number1;
}