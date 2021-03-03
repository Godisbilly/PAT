#include <stdio.h>

int CountDigit(int number,int digit);

int main(int argc, char *argv[]) {
	int number,digit;
	scanf("%d %d",&number,&digit);
	printf("Number of digit  %d in %d:%d\n",digit,number,CountDigit(number,digit));
	
	return 0;
}

int CountDigit(int number,int digit)
{
	int count = 0;
	if(number < 0)
		number = -number;
	//这里要特别注意，自己不会写，也是看的网上的答案写的。
	if(number == 0)
	{
		if(digit == 0)
			return 1;
		else
			return 0;
	}
	while(number != 0)
	{
		if(number % 10 == digit)
			count++;
		number /= 10;
	}
	return count;
}