#include"start.h"


/* ����һ��ѭ������
 *		����ֵ : ���ش�����ѭ�����еĽṹ��ָ��
 */
Queue* queue_create(void)
{
	Queue* q = new Queue;	// ����һ�����пռ�
	if (NULL == q)	// ����ʧ��
	{
		return NULL;
	}
	else	// ����ɹ�
	{
		q->front = 0;
		q->rear = 0;
		return q;
	}
}

/*	����һ��ѭ������
 *		q : ��ʾҪ���ٵ�ѭ������
 */
void queue_destroy(Queue* q)
{
	if (NULL != q)
	{
		free(q);	// ִ�����ٲ���
	}
}

/* ��ʼ��ѭ������
 *		q : Ҫ��ʼ����ѭ������
 */
void queue_init(Queue* q)
{
	q->front = 0;
	q->rear = 0;
}

/*	�ж�ѭ�������Ƿ�Ϊ��
 *		q : ��ʾҪ�жϵ�ѭ������
 *		����ֵ: TRUEΪ�գ�FALSEΪ�ǿ�
 */
int queue_empty(Queue* q)
{
	if (q->front == q->rear) return 1;
	else return 0;
}

/*	�ж�ѭ�������Ƿ�Ϊ��
 *		q : ��ʾҪ�жϵ�ѭ������
 *		����ֵ: TRUE��ʾ����FALSE��ʾ����
 */
int queue_full(Queue* q)
{
	if ((q->rear + 1) % MAX_ITEMS == q->front) return 1;
	else return 0;
}

/*	�����β������һ��Ԫ��
 *		q : Ҫ�����ѭ������
 *		item : Ҫ�����Ԫ��
 *		����ֵ: TRUE�ɹ���FALSEʧ��
 */
boolean queue_rear_insert(Queue* q, int item)
{
	if (queue_full(q)) return FALSE;
	else	// ���ѭ������δ��
	{
		// �Ƚ�Ԫ�ز��뵽ѭ�����е�β����Ȼ��ѭ������β����rearָ���һ
		q->base[q->rear] = item;
		q->rear = (q->rear + 1) % MAX_ITEMS;
		return TRUE;
	}
}

/*	��ѭ������ͷ��Ԫ��ɾ��
 *		q : Ҫ�����Ķ�ջ
 *		����ֵ: �ɹ�����Ҫɾ����Ԫ��ֵ��Ϊ0��ʾɾ��ʧ��
 */
int queue_front_delete(Queue* q)
{
	int temp_item;

	if (queue_empty(q)) return 0;
	else	// �����ջ��Ϊ��
	{
		// �Ƚ�ѭ������ͷ����Ԫ��ȡ����Ȼ��ͷ��ָ���һ
		temp_item = q->base[q->front];
		q->front = (q->front + 1) % MAX_ITEMS;
		return temp_item;
	}
}

/*	��ȡѭ������ͷ��Ԫ��
 *		q : Ҫ������ѭ������
 *		����ֵ : �ɹ�����Ԫ��ֵ��ʧ���򷵻�0
 */
int queue_get_front(Queue* q)
{
	if (queue_empty(q)) return 0;
	else	// �����Ϊ�գ����ض�ջ��ֵ
	{
		return q->base[q->front];
	}
}

/*	��ӡѭ�����е�Ԫ��
 *		q : Ҫ��ӡ��ѭ������
 */
void queue_items_print(Queue* q)
{
	int front = q->front;
	int rear = q->rear;

	printf("Queue : ");
	while (!(front == rear))		// �ж��Ƿ��ȡ��ѭ������������Ԫ��
	{
		printf("%d ", q->base[front]);
		front = (front + 1) % MAX_ITEMS;
	}
	printf("\n");
}