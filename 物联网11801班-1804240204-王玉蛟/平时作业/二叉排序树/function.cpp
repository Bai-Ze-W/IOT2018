#include"header.h"
#include "stdio.h"
//����
Status SearchBST(BSTree T,KeyType kval,BSTree f,BSTree *p)
{
    if(!T)
	{
		*p=f;
		return ERROR;
	}
	else if(kval==T->data)
	{
	     *p=T;
		 return OK;
	}
	else if(kval<T->data)
		return SearchBST(T->lchild,kval,T,p);
	else
		return SearchBST(T->rchild,kval,T,p);
}

//����
void InsertBST(BSTree T,int key)
{
	BSTree p,s;
    if(!SearchBST(T,key,NULL,&p))
	{
	    s=new BiTNode;
		s->data=key;
		s->lchild=s->rchild=NULL;
		if(!p)
		{
		   T=s;
		}
		else if(key<p->data)
			p->lchild=s;
		else
			p->rchild=s;
	}
	else printf("��Ǹ��Ԫ���ظ�\n");
}

//ɾ���Ӻ���
void Delete (BSTree p)
{
   BSTree q,s;
   if(p->rchild==NULL)
   {
       q=p;
	   p=p->lchild;
	   free(q);
   }
   else if(p->lchild==NULL)
   {
      q=p;
	  p=p->rchild;
	  free(q);   
   }
   else
   {
       q=p;
	   s=p->lchild;
	   while(s->rchild)
	   {
	      q=s;
		  s=s->rchild;
	   }
	   p->data=s->data;
	   if(q!=p)
		   q->rchild=s->lchild;
	   else
		   q->lchild=s->lchild;
	   free(s);
   }
}

//ɾ��
void DeleteBST(BSTree T,KeyType key)
{
   BSTree p;
   if(!SearchBST(T,key,NULL,&p))
   {
      if(key==T->data)
		  Delete(T);
	  else if(key<T->data)
		  DeleteBST(T->lchild,key);
	  else
		  DeleteBST(T->rchild,key);
   }
   else
	   printf("��Ǹ��û������Ҫɾ����Ԫ��\n");

}

//�������
void InOrder(BSTree T)
{
    if(T)
	{
	   InOrder(T->lchild);
	   printf("%d",T->data);
	   InOrder(T->rchild);
	}
	else 
		return;
}


//�˵�
void menu(int choose)
{
   int i,num,n;
   KeyType kval;
   BSTree T=NULL,f,*p;
p   int a[n];
   switch(choose)
   {
   case(1):
	   printf("���� n\n");
	   scanf("%d",&n);
	   printf("����n��Ԫ��\n");
	   for(i=0;i<n;i++)
	   {
	       InsertBST(T,a[i]);  
	   }
	   printf("�������!\n");
	   break;
   case(2):
	   printf("��������Ҫ�����Ԫ�أ�");
	   scanf("%d",&num);
	   InsertBST(T,num);
	   printf("������ɣ�\n");
	   break;
   case(3):
	   printf("������Ҫɾ����Ԫ��:\n");
	   scanf("%d",&num);
	   DeleteBST(T,num);
	   printf("ɾ����ɣ�\n");
	   break;
   case(4):
	   InOrder(T);
	   break;
   case(5):
	   SearchBST(T,kval,f,*p);
	   break;





}
 
