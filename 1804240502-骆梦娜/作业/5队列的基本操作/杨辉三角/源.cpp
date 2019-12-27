# include<stdio.h>
# define M 100
typedef struct
{
	int a[M];
	int front, rear;
}sq;
void init(sq* q)
{
	q->rear = q->front = 0;
}
int  enter(sq* q, int x)
{
	if ((q->rear + 1) % M == q->front)
	{
		return 0;
	}
	else
	{
		q->a[q->rear] = x;
		q->rear = (q->rear + 1) % M;
		return 1;

	}
}
int delet(sq* q, int* x)
{
	if (q->front == q->rear)
	{
		return 0;
	}
	else
	{
		*x = q->a[q->front];
		q->front = (q->front + 1) % M;
		return 1;
	}
}
int get(sq* q, int* x)
{
	if (q->front == q->rear)
	{
		return 0;
	}
	else
	{
		*x = q->a[q->front];
		return 1;
	}
}
void main()
{
	sq q;
	int n, m, i, x, y;
	init(&q);
	printf("������������ǵ�����\n");
	scanf_s("%d", &m);
	enter(&q, 1);
	for (n = 2; n <= m; n++)
	{
		enter(&q, 1);
		for (i = 1; i <= n - 2; i++)
		{
			delet(&q, &x);
			printf("%d ", x);
			get(&q, &y);
			y = y + x;
			enter(&q, y);
		}
		delet(&q, &x);
		printf("%d", x);
		printf("\n");
		enter(&q, 1);
	}
	while (q.front != q.rear)
	{
		delet(&q, &x);
		printf("%d ", x);
	}
}