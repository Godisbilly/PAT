#include <stdio.h>

#define MAXN 10

int even(int n);
int OddSum(int list[],int N);

int main(int argc, char *argv[]) 
{
	int List[MAXN];
	int N;
	scanf("%d",&N);
	printf("Sum of ( ");
	for(int i = 0;i < N;i++)
	{
		scanf("%d",&List[i]);
		if(even(List[i]) == 0)
		{
			printf("%d ",List[i]);
		}
	}
	printf(") = %d\n",OddSum(List,N));
	
	return 0;
	
}

int even(int n)
{
	if(n % 2 == 0)
		return 1;
	else
		return 0;
}

int OddSum(int list[],int n)
{
	int i,sum = 0;
	for(i = 0;i < n;i++)
	{
		if(!even(list[i]))
			sum += list[i];
	}
	
	return sum;
}