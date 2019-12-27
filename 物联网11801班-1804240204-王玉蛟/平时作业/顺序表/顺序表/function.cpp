
#include "stdio.h"
#include "sqhead.h"
//�ϲ�(����)
void Mergelist_Sq(SqList La,SqList Lb,SqList &Lc)//��֪˳�����Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
                                                 //�鲢La��Lb�õ����µ�˳�����Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
{
	int *pa,*pb,*pa_last,*pb_last,*pc;
     pa=La.elem;
	 pb=Lb.elem;
	 Lc.listsize=Lc.length=La.length+Lb.length;
	 pc=Lc.elem=(ElemType*)malloc(Lc.listsize*sizeof(ElemType));
	 if(!Lc.elem)
		 exit(OVERFLOW);//�洢����ʧ��
	 pa_last=La.elem+La.length-1;
     pb_last=Lb.elem+Lb.length-1;
	 while(pa<=pa_last&&pb<=pb_last)
	 {
	      if(*pa<=*pb)
			  *pc++=*pa++; 
		  else
			  *pc++=*pb++;
	 }
	 while(pa<=pa_last)
		 *pc++=*pa++;//����La��ʣ��Ԫ��
	 while(pb<=pb_last)//����Lb��ʣ��Ԫ��
		 *pc++=*pb++;
}


//ɾ��
Status ListDelete_Sq(SqList &L,int i,ElemType &e)
{
	int *p,*q;
     if((i<1)||(i>L.length))
		 return ERROR;//iֵ���Ϸ�
	 p=&(L.elem[i-1]);//pΪ��ɾ��Ԫ�ص�λ��
	 e=*p;//��ɾ��Ԫ�ص�ֵ����e
	 q=L.elem+L.length-1;//��βԪ�ص�λ��
	 for(++p;p<=q;++p)*(p-1)=*p;//��ɾ��Ԫ��֮���Ԫ������
	  --L.length;
	  return OK;//����һ
}


//����
Status ListInsert_Sq(SqList &L,int i,ElemType e)//��˳���L�е�i��λ��֮ǰ�����µ�Ԫ��e  //i�ĺϷ�ֵΪ1<=i<=ListLength_Sq(L)+1
{
     int *newbase,*q,*p;
    if(i<1||i>L.length+1)
		return ERROR;
	if(L.length>=L.listsize)
	{
	    newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)
			exit(OVERFLOW);//�洢����ʧ��
		L.elem=newbase;//�»�ַ
		L.listsize+=LISTINCREMENT;//���Ӵ�������	
	}
	q=&(L.elem[i-1]);
	for(p=&(L.elem[L.length-1]);p>=q;--p)
		*(p+1)=*p;//����λ�ü�֮���Ԫ�غ���
	*q=e;//����e
	++L.length;//����1
    return OK;
}


//����
Status LocateElem_Sq(SqList La,ElemType i)
{
    ElemType*pa,*pa_last;
	ElemType k=0;
	pa=La.elem;
	pa_last=La.elem+La.length-1;
	while(pa<pa_last)
	{
	   if(*pa==i)
	   {
	       printf("��%d������%d",k+1,i);
		   return OK;
	   	   
	   }
	   else
		   *pa++;
	   k++;
	   
	}
	printf("NO Found!!!");
	return FALSE;


}



//���������Ա�
Status InitList_Sq(SqList &L)
{
  
   L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
   if(!L.elem)
	   exit (OVERFLOW);//�洢����ʧ��
   L.length=0;//�ձ���Ϊ0
   L.listsize=LIST_INIT_SIZE;//��ʼ�洢����
   return OK;
}


//��˳��������������
void InputList(SqList &L)
{
	int n = -1, i, m;
	ElemType e;

	while (n) {								//����׼�������Ԫ�ظ���
		printf("�����ȼ���׼�������Ԫ�ظ���(��໹������%d��Ԫ��)������0�˳�:", L.listsize - L.length);
		scanf("%d", &n);
		fflush(stdin);

		if (n > L.listsize - L.length)		//�ж�����ֵ��ִ����
			printf("���Ա��������㣬���������롣\n");

		    else if (n < 0)
			    printf("����Ƿ���");

	       	else if (n == 0)
		     	break;

		else {								//����ѭ������
			printf("�����Ҫ�����ֵ����%d������", n);
			m = L.length + n;
			for (i = L.length + 1; i <= m; i++) {
					scanf("%d", &e);
					L.elem[i-1] = e;
					L.length++;
			}
			printf("������ɣ�\n");
			break;
		}
	}
}
//��ӡ����Ԫ��


//���˵�
void menu(int choose)
{
    ElemType e;
	int i;
   switch(choose)
   {
   case(1):
       InitList_Sq(La);
       InputList(La);
	   for(i=0;i<La.length;i++)
		   printf("%d",La.elem[i]);
	   printf("\n");
	   break;//����La
   case(2):
	    InitList_Sq(Lb);
       InputList(Lb);
	   for(i=0;i<Lb.length;i++)
		   printf("%d",Lb.elem[i]);
	    printf("\n");
	   break;//����Lb
   case(3):
	   Mergelist_Sq(La,Lb,Lc);
	   for(i=0;i<Lc.length;i++)
		   printf("%d",Lc.elem[i]);
	   printf("\n");
	   break;//�ϲ�
   case(4):
	   printf("Enter��");
	   scanf("%d",&i);
	   LocateElem_Sq(Lc,i);
       printf("\n");
	   break;//����


   case(5):
       printf("λ�ú����֣�");
	   scanf("%d%d",&i,&e);
       ListInsert_Sq(Lc,i,e);
	   
       for(i=0;i<Lc.length;i++)
		   printf("%d",Lc.elem[i]);
	   printf("\n");
	   break;//����

   case(6):
       printf("λ�ú����֣�");
	   scanf("%d%d",&i,&e);
       ListDelete_Sq(Lc,i,e);
       for(i=0;i<Lc.length;i++)
		   printf("%d",Lc.elem[i]);
	   printf("\n");
	   break;//ɾ��	   
   }

}
