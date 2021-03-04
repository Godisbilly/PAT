#include <stdio.h>
#include <math.h>

int prime( int p );
void Goldbach( int n );

int main()
{
    int m, n, i, cnt;

    scanf("%d %d", &m, &n);
    if ( prime(m) != 0 ) printf("%d is a prime number\n", m);
    if ( m < 6 ) m = 6;
    if ( m%2 ) m++;
    cnt = 0;
    for( i=m; i<=n; i+=2 ) {
        Goldbach(i);
        cnt++;
        if ( cnt%5 ) printf(", ");
        else printf("\n");
    }

    return 0;
}

/* 你的代码将被嵌在这里 */

int prime(int p)
{
    if(p == 1)
        return 0;
    if(p == 2 || p == 3)
        return 1;
    else if(p % 6 != 1 && p % 6 != 5)
        return 0;
    int sqrt_p = (int)sqrt(p);
    for(int i = 5;i <= sqrt_p;i += 6)
        {
            //一路遍历，看它能都找到一个数能被整除，如果出现一个，则直接return，否则，一直遍历下去，直到推出循环，这个时候所有的数都不能被整除。
            if(p % i == 0 || p % (i+2) == 0)
                return 0;
        }
    return 1;
}

void Goldbach(int n)
{
    for(int i = 3;i <= n/2;i += 2)
    {
        if(prime(i) && prime(n - i))
        {
            printf("%d=%d+%d",n,i,n-i);
            break;
        }    
    }
}