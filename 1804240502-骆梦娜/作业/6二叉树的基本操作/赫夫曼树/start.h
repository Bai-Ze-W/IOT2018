#include<iostream>
using namespace std;
#pragma warning (disable:4996)
#define maxSize 100
/*
�շ������Ĵ洢�ṹ����Ҳ��һ�ֶ������ṹ��
���ִ洢�ṹ���ʺϱ�ʾ����Ҳ�ʺϱ�ʾɭ�֡�
*/
typedef struct Node
{
	int weight;                //Ȩֵ  
	int parent;                //���ڵ����ţ�Ϊ-1���Ǹ��ڵ�  
	int lchild, rchild;         //���Һ��ӽڵ����ţ�Ϊ-1����Ҷ�ӽڵ�  
}HTNode, * HuffmanTree;          //�����洢�շ������е����нڵ�  
typedef char** HuffmanCode;    //�����洢ÿ��Ҷ�ӽڵ�ĺշ�������  

HuffmanTree create_HuffmanTree(int* wet, int n);
void select_minium(HuffmanTree HT, int k, int& min1, int& min2);
int min(HuffmanTree HT, int k);
void HuffmanCoding1(HuffmanTree HT, HuffmanCode& HC, int n);
void HuffmanCoding2(HuffmanTree HT, HuffmanCode& HC, int n);
int countWPL1(HuffmanTree HT, int n);
int countWPL2(HuffmanTree HT, int n); 
