// ˳���Ļ�������.cpp : Defines the entry point for the console application.
//
#include "sqhead.h"
//������
int main(void)
{
    int choose;

	while(1)
	{
	printf("*******************************\n");
	printf("1-����La                       2-����Lb\n");
	printf("3-�ϲ�La��Lb�õ�Lc             4-��Lc�в���һ��Ԫ�ص�λ��\n");
	printf("5-��Lc�в���һ��Ԫ��           6-ɾ��Lc�е�һ��Ԫ��\n");
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