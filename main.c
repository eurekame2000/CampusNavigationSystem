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
	print1();//欢迎界面 
	//初始化
	initialize();
	strcat(inits, "程序运行开始！");
	writelog(0,1, inits,  0, 0);
	//询问导航要求
	getOrder(&sCampus,&start,&eCampus,&end,&type,pass);
	//进行导航路线的查询输出和模拟 
	Guide(sCampus,start,eCampus,end,type,pass);  
}

//判断输入的序号是否符合规定，若不符合再次输入 
void judge(int* num,int sign)
{
    int number;
    number=*num;
    //序号限定在1~2时的判断 
	if(sign==1)	
	{
		while(number!=1&&number!=2)
		{
			printf("输入序号不可选，请重新输入\n");
			scanf("%d",&number);
		}
	}
	//序号限定在0~19时的判断
	if(sign==2)
	{
		while(number<0||number>19)
		{
			printf("输入序号不可选，请重新输入\n");
			scanf("%d",&number);
		}
	}
	//序号限定在1~4时的判断
	if(sign==3)
	{
		while(number<1||number>4)
		{
			printf("输入序号不可选，请重新输入\n");
			scanf("%d",&number);
		}
	} 
	//途经时的判断
	if(sign==4)
	{
		while((number<0||number>19)&&number!=-1)
		{
			printf("输入序号不可选，请重新输入\n");
			scanf("%d",&number);
		}
	}
	*num=number;
}
