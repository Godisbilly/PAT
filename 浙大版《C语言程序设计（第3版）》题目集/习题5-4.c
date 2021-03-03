#include <stdio.h>
#include <math.h>

int prime(int p);
int PrimeSum(int m,int n);

int main(int argc, char *argv[]) {
	int m,n;
	
	scanf("%d %d",&m,&n);
	printf("Sum of ( ");
	for(int p = m;p <= n;p++)
	{
		if(prime(p))
		{
			printf("%d ",p);
		}
	}
	printf(") = %d\n",PrimeSum(m,n));

	return 0;
}

//判断一个数是不是素数，有三种方法：
//第一种方法：从1到n开始遍历，看中间有没有数能被n整除，如果有，则不是素数，否则就是素数。
//第二种方法：从1到sqrt(n)开始遍历，看中间有没有数能被n整除，如果有，则不是素数，否则就是素数。
//第三种方法：素数还有一个特点，它总是等于6x+1或6x-1，x是大于等于1的自然数。
//证明：首先，6x肯定不是素数，它能被6整除；6x+2也不是素数，它能被2整除；6x+3不是素数，它能被3整除；6x+4也不是素数，它能被2整除；只有6x+1和6x+5了。所以循环的步长是6，每次只要判断6两侧的数即可。
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

int PrimeSum(int m,int n)
{
	int i,sum = 0;
	for(i = m>0?m:2;i <= n;i++)
	{
		if(prime(i))
			sum += i;
	}
	return sum;
}