#include"start.h"



/* �������� */
int main(int argc, char* argv[])
{
	Queue* q;
	int a[10];
	int i,t,c,d;

	/* ͨ������̨����10������Ԫ�� */
	printf("Input 10 numbers :\n");
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);
	}

	/* ����һ��ѭ������ */
	q = queue_create();
	if (NULL == q)
	{
		printf("queue_create error!\n");
		return -1;
	}

	/* ����������е�Ԫ�ز��뵽���е��� */
	for (i = 0; i < 10; i++)
	{
		queue_rear_insert(q, a[i]);
	}

	printf("*******************************************************\n");

	/* ��ѭ������������Ԫ�ض���ӡ���� */
	queue_items_print(q);

	printf("*******************************************************\n");
	t = queue_get_front(q);
	printf("��ͷԪ��Ϊ:%d\n", t);
	/* ��ѭ��������ͷԪ�ض���ӡ���� */

	printf("*******************************************************\n");

	/* �������β���ٲ�������Ԫ�� */
	queue_rear_insert(q, 200);
	queue_rear_insert(q, 300);
	queue_items_print(q);

	printf("*******************************************************\n");
	c = queue_full(q);
	printf("%d(1Ϊ��,0Ϊ����)\n", c);
	/*����*/

	printf("*******************************************************\n");

	/* �Ӷ���ͷ��ɾ������Ԫ�� */
	queue_front_delete(q);
	queue_front_delete(q);
	queue_front_delete(q);
	queue_items_print(q);

	printf("*******************************************************\n");
	d = queue_empty(q);
	printf("%d(1Ϊ��,0Ϊ�ǿ�)\n", d);
	/*�п�*/

	printf("*******************************************************\n");

	/* ����һ��ѭ������ */
	queue_destroy(q);

	return 0;
}