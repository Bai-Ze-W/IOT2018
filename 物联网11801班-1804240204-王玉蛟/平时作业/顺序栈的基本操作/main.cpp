#include "header.h"
//������
int main(void)
{
	
    int choose;

    while(1)
	{
	printf("*******************************\n");
	printf("1-��ջ                       2-��ջ\n");
	printf("3-ȡջ��                     4-ջ�ĳ���\n");
	printf("5-�п�                       6-����\n");
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