#include"header.h"

int main(void)
{
   int choose;
   while(1)
	{
	printf("*******************************\n");
	printf("1-���������                           2-����\n");
	printf("3-ɾ��                                 4-�������\n");
	printf("5-����                                 6-����\n");
	printf("����-�˳�����");
	printf("******************************\n");
	printf("Enter your choose:");
	scanf("%d",&choose);
	if(choose<1||choose>6)
		break;
	else
		menu(choose);
	}
	return 0;
}
