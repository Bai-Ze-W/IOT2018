#include "stdlib.h"
#include "stdio.h"
#define LIST_INIT_SIZE 100  //���Ա����󳤶�
#define LISTINCREMENT 10
#define OK 0
#define TURE 1
#define FALSE 0
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;

typedef struct
{
    ElemType *elem;
	int length;
	int listsize;
  
}SqList;//�������Ա�ṹ��

void menu(int choose);//���˵�
Status InitList_Sq(SqList &L);//���������Ա�
void InputList(SqList &L);//��˳��������������
Status LocateElem_Sq(SqList La,ElemType i);//����
Status ListInsert_Sq(SqList &L,int i,ElemType e);//����
Status ListDelete_Sq(SqList &L,int i,ElemType &e);//ɾ��
void Mergelist_Sq(SqList La,SqList Lb,SqList &Lc);//�ϲ�
static	SqList La,Lb,Lc;
