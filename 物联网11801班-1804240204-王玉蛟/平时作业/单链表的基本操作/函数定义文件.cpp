#include"ͷ�ļ�.h"
#include"stdio.h"

//��ʼ��
void InitList(LinkList &L)//����һ����ͷ���Ŀ�����L��Ϊָ��ͷ����ָ��
{
    L=new LNode;
	if(!L)
		exit(1);//����ռ����ʧ��
	L->next=NULL;

}


//��ȡ
Status GetElem_L(LinkList L,int i,ElemType &e)
{
	LNode *p;
    p=L->next;//��ʼ��pָ���һ�����
	int j=1;//jΪ������
	while(p&&j<i)
	{
	   p=p->next;
	   ++j;
	}
	if(!p||j>i)
		return ERROR;//��i��Ԫ�ز�����
	e=p->date;//ȡ��i��Ԫ��
	return OK;

}



//����
Status ListInsert_L(LinkList &L,int i,ElemType e)//�ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
{
	LNode *p;
    LNode *s;
    p=L;
    int j=0;
    while(p&&j<i-1)
    {
      p=p->next;
	  ++j;
    }//Ѱ�ҵ�i-1�����
   if(!p||j>i-1)//�������Ϸ���iС��1���ߴ��ڱ���1
	   return ERROR;
   s=new LNode;//�����½��
   s->date=e;
   s->next=p->next;
   p->next=s;//����L��
   return OK;

}

//ɾ��
Status ListDelete_L(LinkList &L,int i,ElemType &e)
{
	LNode *p,*q;
   p=L;
   int j=0;
   while(p->next&&j<i-1)
   {
      p=p->next;
	  ++j;
   }
   if(!(p->next)||j>i-1)
	   return ERROR;//ɾ��λ�ò�����
   q=p->next;
   p->next=q->next;
   e=q->date;//ɾ�����
   free(q);//�ͷŽ��
   return OK;

}
//ͷ�巨����������
void HeadCreate_L(LinkList &L,int n)
{
	LinkList p;
	int a;
     for(int i=0;i<n;i++)
	 {
	    p=new LNode;
		scanf("%d",&a);
		p->date=a;
		p->next=L->next;//pָ����һ��
		L->next=p;//�ٽ�p��������L�ı�ͷ
	 }

}

//�鲢��δʹ�ã�
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc)
{
	LNode *pa;
	LNode *pb;
	LNode *pc;
    pa=La->next;
	pb=Lb->next;
	Lc=pc=La;
	while(pa&&pb)
	{
	   if(pa->date<=pb->date)
	   {
	      pc->next=pa;
		  pc=pa;
		  pa=pa->next;
	   }//
	   else 
	   {
	      pc->next=pb;
		  pc=pb;
		  pb=pb->next;
	   }
	}
	pc->next=pa?pa:pb;//����ʣ���
	free(Lb);//�ͷ�b��ͷ���
}





//ɾ������
void purge_L(LinkList &L)
{
	//ɾ���������е�����Ԫ�أ���ʹ������ĵ�������ֻ����
	//����֮ǰ��������ֵ����ͬ��Ԫ��
	LinkList q,c;
	LNode *p;
	p=L->next;
	L->next=NULL;
	while(p)
	{
		c=p->next;
		q=L->next;
		while(q&&p->date!=q->date)
			q=q->next;

		if(!q)
		{
			p->next=L->next;
			L->next=p;
		}
		else
			delete p;
		p=c;
	}
}


//β�巨����������
void TailCreate_L(LinkList &L,int n)
{
    LinkList p,r;
    int i,a;
    L=new LNode; // LΪ�������Ա�
    r=L;//rΪָ��β���Ľ��
    for(i=0; i<n; i++)
	{
       p=new LNode; //�����½��
	   scanf("%d",&a);
       p->date = a;//
       r->next=p; //����β�ն˽���ָ��ָ���½��
       r =p;//����ǰ���½�㶨��Ϊ��β�ն˽��
	}
    r->next = NULL ;//��ʾ��ǰ�������
}

//���������
void print (LinkList L)
{
	LinkList p;
	p=L->next;
	while(p)
	{		
		printf("%d,",p->date );
		p=p->next;
	}
	printf("\n");
}


//���˵�
void menu(int choose)
{
	int n;
	int i;
	ElemType e;
    switch(choose)
	{
	case 1:
		printf("Enter n:");
		scanf("%d",&n);
		InitList(L);
        HeadCreate_L(L,n);
        print(L);
	    printf("\n");
		break;
	case 2:
        printf("Enter n:");
		scanf("%d",&n);
		InitList(L);
        TailCreate_L(L,n);
		print(L);
		printf("\n");
		break;
	case 3:
		printf("����λ��:");
		scanf("%d",&i);
        printf("Enter number:");
		scanf("%d",&e);
		ListInsert_L(L,i,e);
		print(L);
		printf("\n");
		break;
	case 4:
        printf("Enter i:");
		scanf("%d",&i);
		ListDelete_L(L,i,e);
		print(L);
		printf("\n");
		break;
	case 5:
        printf("����λ�ã�");
	    scanf("%d",&i);
		GetElem_L(L,i,e);
		printf("%d",e);
		printf("\n");
		break;
	case 6:
		purge_L(L);
	    print(L);
		printf("\n");
		break;

	
	}

}
