#include<stdio.h>
#include<stdlib.h>
#define OK 0
#define TURE 1
#define FALSE 0
#define ERROR 0
#define MAXSIZE 20
typedef int ElemType;
typedef int Status;
typedef int KeyType;


typedef struct BiTNode{
        ElemType data;
		struct BiTNode *lchild,*rchild;
}BiTNode,*BSTree;
Status SearchBST(BSTree T,KeyType kval,BSTree f,BSTree *p);//����
void InsertBST(BSTree T,int key);//����
void Delete (BSTree p);//ɾ���Ӻ���
void DeleteBST(BSTree T,KeyType key);//ɾ��
void InOrder(BSTree T);//�������
void menu(int choose);//�˵�