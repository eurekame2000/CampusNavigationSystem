#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"main.h"
#include"initialize.h"
#include"print.h"
#include"guide.h"
#include"writelog.h"
#pragma warning(disable:4996);
int main()
{
	int sCampus,eCampus,start,end,type,pass[2][20];
	char inits[30] = { 0 };
	int i,j;
	for(i=0;i<2;i++)
    {
    	for(j=0;j<20;j++)
	        pass[i][j]=-1;
	 } 
	print1();//��ӭ���� 
	//��ʼ��
	initialize();
	strcat(inits, "�������п�ʼ��");
	writelog(0,1, inits,  0, 0);
	//ѯ�ʵ���Ҫ��
	getOrder(&sCampus,&start,&eCampus,&end,&type,pass);
	//���е���·�ߵĲ�ѯ�����ģ�� 
	Guide(sCampus,start,eCampus,end,type,pass);  
}

//�ж����������Ƿ���Ϲ涨�����������ٴ����� 
void judge(int* num,int sign)
{
    int number;
    number=*num;
    //����޶���1~2ʱ���ж� 
	if(sign==1)	
	{
		while(number!=1&&number!=2)
		{
			printf("������Ų���ѡ������������\n");
			scanf("%d",&number);
		}
	}
	//����޶���0~19ʱ���ж�
	if(sign==2)
	{
		while(number<0||number>19)
		{
			printf("������Ų���ѡ������������\n");
			scanf("%d",&number);
		}
	}
	//����޶���1~4ʱ���ж�
	if(sign==3)
	{
		while(number<1||number>4)
		{
			printf("������Ų���ѡ������������\n");
			scanf("%d",&number);
		}
	} 
	//;��ʱ���ж�
	if(sign==4)
	{
		while((number<0||number>19)&&number!=-1)
		{
			printf("������Ų���ѡ������������\n");
			scanf("%d",&number);
		}
	}
	*num=number;
}
