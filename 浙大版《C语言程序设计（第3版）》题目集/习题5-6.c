#include <stdio.h>


#include <stdio.h>

int narcissistic( int number );
void PrintN( int m, int n );

int main()
{
	int m, n;
	
	scanf("%d %d", &m, &n);
	if ( narcissistic(m) ) printf("%d is a narcissistic number\n", m);
	PrintN(m, n);
	if ( narcissistic(n) ) printf("%d is a narcissistic number\n", n);
	
	return 0;
}

/* 你的代码将被嵌在这里 */

int narcissistic(int number)
{
	int n1 = number,n2 = number,count = 0,sum = 0;
	//统计这个数有几位
	while(n1)
	{
		count++;
		n1 /= 10;
	}
	
	while(n2)
	{
		int n = n2 % 10,temp = n;
		for(int i = 1;i < count;i++)
		{
			n = temp * n;
		}
		sum += n;
		n2 /= 10;
	}
	if(sum == number)
		return 1;
	else
		return 0;
}

void PrintN(int m,int n)
{
	int i = m+1;
	while(i < n)
	{
		if(narcissistic(i))
			printf(
				"%d\n",i);
		i++;
	}
}