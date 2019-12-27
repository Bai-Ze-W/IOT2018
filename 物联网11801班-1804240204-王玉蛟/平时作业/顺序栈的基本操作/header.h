#include <stdlib.h>
#include <stdio.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

#define OK 1
#define ERROR 0
#define TURE 1
#define FALSE 0

#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int SElemType;

typedef struct
{
   SElemType *base;
   SElemType *top;
   int stacksize;
}SqStack;

Status InitStack(SqStack &S);//��ʼ��
Status DestroyStack_Sq(SqStack &S);//����
bool Push(SqStack &S, SElemType e);//��ջ
void Push_Sq(SqStack &S);//��ջ���˵���
bool Pop(SqStack &S, SElemType &e);//��ջ
void Pop_Sq(SqStack &S);//��ջ���˵���
bool GetTop_Sq(SqStack S,SElemType e);//ȡջ��Ԫ��
int StackLength(SqStack S);//��
bool StackEmpty_Sq(SqStack S);//�ж�ջ��
bool StackTraverse(SqStack S);//����
void menu(int choose);//�˵�
