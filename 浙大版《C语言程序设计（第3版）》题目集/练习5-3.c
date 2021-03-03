#include <stdio.h>

void pyramid(int n);

int main(int argc, char *argv[]) {
	int n;
	scanf("%d",&n);
	pyramid(n);
	
	return 0;
}

void pyramid(int n)
{
	//假如输入的是n，则最后一行的长度为2*n-1
	//第一行头部有n-1个空格，第二行头部有n-2个空格，...，第i行头部有0个空格
	int i;
	//n行
	for(i = 1;i <= n;i++)
	{
		//对每一行处理
		
		//先输出前面的空格
		int j = 1;
		while(j <= n-i)
		{
			printf(" ");
			j++;
		}
		//输入数字，用i控制输入数字的个数，k用来遍历
		int k;
		for(k = 1;k <= i;k++)
		{
			printf("%d ",i);
		}
		printf("\n");
	}
}