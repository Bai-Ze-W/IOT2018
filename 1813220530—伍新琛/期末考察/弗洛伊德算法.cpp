#include <stdio.h>  
#include <string.h>  
#include <string>  
#include <iostream>  
#include <stack>  
#include <queue>  
#include <vector>  
#include <algorithm>  
#define mem(a,b) memset(a,b,sizeof(a))  
using namespace std;  
const int inf=1<<29;  
int main()  
{  
    int map[10][10],n,m,t1,t2,t3;  
    scanf("%d%d",&n,&m);//n��ʾ���������m��ʾ�ߵ�����  
    //��ʼ��  
    for(int i=1; i<=n; i++)  
        for(int j=1; j<=n; j++)  
            if(i==j)  
                map[i][j]=0;  
            else  
                map[i][j]=inf;  
    //�����  
    for(int i=1; i<=m; i++)  
    {  
        scanf("%d%d%d",&t1,&t2,&t3);  
        map[t1][t2]=t3;  
    }  
    //��������(Floyd)�������  
    for(int k=1; k<=n; k++)  
        for(int i=1; i<=n; i++)  
            for(int j=1; j<=n; j++)  
                if(map[i][k]+map[k][j]<map[i][j])  
                    map[i][j]=map[i][k]+map[k][j];  
    for(int i=1; i<=n; i++)  
    {  
        for(int j=1; j<=n; j++)  
            printf("%10d",map[i][j]);  
        printf("\n");  
    }  
    return 0;  
}  

