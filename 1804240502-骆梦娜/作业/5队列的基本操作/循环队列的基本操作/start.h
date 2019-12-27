#include <stdio.h>
#include <stdlib.h>

/* ����ѭ�����еĻ������Ĵ�С */
#define	MAX_ITEMS		256

/* ����ѭ�����е����ݽṹ�� */
typedef enum { FALSE, TRUE } boolean;
typedef struct
{
	int base[MAX_ITEMS];	// ѭ�����еĻ�����
	int front;				// ѭ�����е�ͷָ��
	int rear;				// ѭ�����е�βָ��
} Queue;


Queue* queue_create(void);
void queue_destroy(Queue* q);
void queue_init(Queue* q);
int queue_empty(Queue* q);
int queue_full(Queue* q);
boolean queue_rear_insert(Queue* q, int item);
int queue_front_delete(Queue* q);
int queue_get_front(Queue* q);
void queue_items_print(Queue* q);
