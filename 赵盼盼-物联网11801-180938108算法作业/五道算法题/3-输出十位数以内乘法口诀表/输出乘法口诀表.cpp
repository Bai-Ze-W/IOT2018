#include<stdio.h>
int main()
{
	int i,j,t;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			t=i*j;
			printf("%d*%d=%-3d ",i,j,t);  /*-3d��ʾ����룬ռ����*/
		}
		printf("\n");
	}
	return 0;
}
