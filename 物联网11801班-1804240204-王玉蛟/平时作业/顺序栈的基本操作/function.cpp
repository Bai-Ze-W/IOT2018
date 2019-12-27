#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include "header.h"
//��ʼ��
Status InitStack(SqStack &S)
{//����һ����ջ
	S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base){
		printf("����ʧ��\n");
		return 0;
	}
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return 1;
}

//����
Status DestroyStack_Sq(SqStack &S)
{
    free(S.base);
    S.base = NULL;
	S.stacksize = 0;
	return OK;
}





//��ջ
bool Push(SqStack &S, SElemType e)
{
    if (S.top - S.base >= STACK_INIT_SIZE)//����Ƿ��п���
	{
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
        if(!S.base) 
		{   
			printf("ջ������\n");
			return false;}//�洢����ռ�ʧ��
        S.top = S.base + STACK_INIT_SIZE;//ջ�׵�ַ���ܸı䣬���¶�λջ��Ԫ��
		S.stacksize = S.stacksize + STACKINCREMENT;
	}
    *S.top = e;//���¸�ֵ���µ�ջ��Ԫ��
	S.top++;
	return OK;
}
//��ջ���˵���
void Push_Sq(SqStack &S)
{	
	int n;
	SElemType e;
	int flag;
	printf("��������ջԪ�ظ���(>=1)��\n");	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("�������%d��Ԫ�ص�ֵ:",i+1);
		scanf("%d",&e);
		flag=Push(S,e);	
		if(flag)
			printf("%d������ջ\n",e);	
		else{
			printf("ջ����������\n");
			break;
		}
	}
}



//��ջ
bool Pop(SqStack &S, SElemType &e)//ɾ��˳��ջջ��Ԫ�أ�����e������ֵ
{

   if(S.top==S.base) 
	   return ERROR;
   else
	{
		S.top--;
		e = *S.top;//Ԫ������S.top�У������������Ԫ�أ��ͻᱻ���£�������ɾ����һ��
		return e;//��e���ر�ɾ����Ԫ��
	}
   return TURE;
}

//��ջ���˵���
void Pop_Sq(SqStack &S)
{
	int n;
	SElemType e;
	int flag;
	printf("�������ջԪ�ظ���(>=1):\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		flag=Pop(S,e);
		if(flag)
			printf("%d�ѳ�ջ\n",e);	
		else {
			printf("ջ�ѿգ�����\n");
			break;
		}	
	}
}


//ȡջ��Ԫ��
bool    GetTop_Sq(SqStack S,SElemType e)//ȡ˳��ջ��Ԫ�أ�����e������ֵ
{
  if (S.top == S.base)
		return FALSE;//��ջ
	else
		e = *(S.top - 1);//��e����ջ��Ԫ�أ���ʱָ���1
	return e;
}


//��
int StackLength(SqStack S)  //����S��Ԫ�ظ�������ջ�ĳ���
{
	if (S.top == S.base)
		return FALSE;//ջΪ��ջ
	else
		return (S.top - S.base);

}
//�ж�ջ��
bool StackEmpty_Sq(SqStack S)
{
    if(S.top==S.base) 
	    return TURE;
    else
        return FALSE;
}


//����
bool StackTraverse(SqStack S)

{
	if (S.base == NULL)
		return ERROR;//����
	if (S.top == S.base)
		printf("ջ��û��Ԫ�ء���\n");//��ջ
	SElemType *p;
	p = S.top;
	while (p > S.base)//���ջ��Ԫ��
	{
		p--;
		printf("%d ", *p);
	}

	return OK;
}

//�˵�
void menu(int choose)
{
   SqStack S;
	InitStack(S);
	int i, e,n;
	printf("����ջ�ĳ���:\n");
	scanf("%d", &n);//ȷ����Ҫ�����Ԫ������
	for (i = 1; i <= n; i++)//ѭ������Ԫ��
	{
		printf("����ջ�ĵ�%d��Ԫ��\n", i);
		++S.top;
		scanf("%d", S.top - 1);
	}
	StackTraverse(S);
		printf("\n");
   switch(choose)
   {
   case 1:
	   Push_Sq(S);
	   StackTraverse(S);
	   printf("\n");
	   break;//��ջ
   case 2:
		Pop_Sq(S);
		StackTraverse(S);
		printf("\n");
		break; //��ջ
   case 3:
	   e=GetTop_Sq(S,e);
	   printf("ջ��Ԫ��Ϊ:%d\n",e);
	   break;//ȡջ��Ԫ��
   case 4:
	   	printf("ջԪ�ظ���Ϊ%d:\n",StackLength(S));
		break;//��ջ��
   case 5:
	   if(StackEmpty_Sq(S)==0)
		   printf("ջ��Ϊ�գ�\n");
	   else
		   printf("ջΪ�գ�\n");
	   break;//�п�
   case 6:
	   DestroyStack_Sq(S);
	   printf("������\n");
	   break; //����
   }
}