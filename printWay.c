#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"main.h"
#include"print.h"
#include"printway.h"
#include"writelog.h"
#include"guide.h"
#pragma warning(disable:4996);


void printWay(int type,int sCampus,int eCampus,int start,int end,int* path,int flag,int path1[][20],int notes[][2])//flag==0 无自行车道 
{//策略类型 起始校区 终止校区 起点 终点 路径数组 自行车标志位 途径节点数组 待写入记录函数（方向和距离） 
	int point;
	int j=0;
	char strategy[4][50]={"最短距离策略","最短时间策略","途经最短距离策略","交通工具最短时间策略"};
	char name1[20]={'\0'};
	char name2[20]={'\0'};
	char name[20]={'\0'};
	char name_s[20]={'\0'};
	char name_e[20]={'\0'};
	char dname[10]={'\0'};//存方向名称
	char ws[maxs] = { 0 };
	
	if(sCampus==1&&eCampus==2)
	{
		strcpy(name_s,"校区一");
		strcpy(name_e,"校区二");
	 } 
	else if(sCampus==2&&eCampus==1)
	{
		strcpy(name_s,"校区二");
		strcpy(name_e,"校区一");		
	}
	else if(sCampus==1&&eCampus==1)
	{
		strcpy(name_s,"校区一");
		strcpy(name_e,"校区一");		
	}
	else
	{
		strcpy(name_s,"校区二");
		strcpy(name_e,"校区二");		
	}
	
	int i=0;
	if(type!=3&&type!=4) //其他策略 
	{
		Num_to_Name(eCampus,end,name2);
		if(flag!=1)//非暂停查询时的输出 
        {
        	Num_to_Name(sCampus,start,name1);
		    printf("%s\n",name1);	
		    printf("采用%s 从%s的%s到%s的%s的路径为：\n",strategy[type-1],name_s,name1,name_e,name2);
			strcat(ws, "采用");
			strcat(ws, strategy[type - 1]);
			strcat(ws, "从");
			strcat(ws, name_s);
			strcat(ws, "的");
			strcat(ws, name1);
			strcat(ws, "到");
			strcat(ws, name_e);
			strcat(ws, "的");
			strcat(ws, name2);
			strcat(ws, "的路径为：");
		}
		else {
			printf("采用%s 到%s的%s的路径为：\n", strategy[type - 1], name_e, name2);
			strcat(ws, "采用");
			strcat(ws, strategy[type - 1]);
			strcat(ws, "到");
			strcat(ws, name_e);
			strcat(ws, "的");
			strcat(ws, name2);
			strcat(ws, "的路径为：");
		}
	}
    else if(type==3)//途经最短距离策略 
    {
    	Num_to_Name(sCampus,start,name1);
		Num_to_Name(eCampus,end,name2);
    	printf("从%s%s到%s%s 途中经过 ",name_s,name1,name_e,name2);
		strcat(ws, "从");
		strcat(ws, name_s); 
		strcat(ws, name1);
		strcat(ws, "到");
		strcat(ws, name_e);
		strcat(ws, name2);
		strcat(ws, "途中经过");
    	while(path1[0][i]!=-1)
    	{
    		Num_to_Name(sCampus,path1[0][i],name);
    		printf("%s%s ",name_s,name);
    		i++;
			strcat(ws, " ");
			strcat(ws, name_s);
			strcat(ws, name);
		}
		i=0;
		while(path1[1][i]!=-1)
    	{
    		Num_to_Name(eCampus,path1[1][i],name);
    		printf("%s%s ",name_e,name);
    		i++;
			strcat(ws, " ");
			strcat(ws, name_e);
			strcat(ws, name);
		}
		printf("且距离最短的路径为：\n");
		strcat(ws, "且距离最短的路径为：");
	}
	else
	{
		int s = 0;
		//仅校区1：s=1，仅校区2：s=2，校区1到校区2：s=3，校区2到校区1：s=4
		if ((sCampus == 1) && (eCampus == 1)) {
			s = 1;
		}
		else if ((sCampus == 2) && (eCampus == 2)) {
			s = 2;
		}
		else if ((sCampus == 1) && (eCampus == 2)) {
			s = 3;
		}
		else {
			s = 4;
		}
		if (exist(s,path)) {
			flag = 1;
		}
		else {
			flag = 0;
		}
		if(flag==0)
		{
			Num_to_Name(sCampus,start,name1);
		    Num_to_Name(eCampus,end,name2);
			printf("从%s到%s无自行车道",name1,name2);
			strcat(ws, "从");
			strcat(ws, name1);
			strcat(ws, "到");
			strcat(ws, name2);
			strcat(ws, "无自行车道");
			writelog(0, 1, ws, 0, 0);
			renew(ws);
			return;
		}
		else 
		{
			Num_to_Name(sCampus,start,name1);
		    Num_to_Name(eCampus,end,name2);
		    printf("骑自行车从%s到%s且时间最短的路径为：",name1,name2);
			strcat(ws, "从");
			strcat(ws, name1);
			strcat(ws, "到");
			strcat(ws, name2);
			strcat(ws, "且时间最短的路径为：");
			writelog(0, 1, ws, 0, 0);
			renew(ws);
		}
	}
    //非暂停查询时输出
	if(type!=1&&flag!=1)
	{
		Num_to_Name(sCampus,start,name);
        printf("从%s出发 ",name);
		strcat(ws,"从");
		strcat(ws,name);
		strcat(ws, "出发 ");
	 } 
    i=0;
	if(sCampus==1&&eCampus==1)//校区1的内部导航 
	{
		while(path[i+1]!=-1)//path[i]不是终点 
		{
			char tmps[20] = { 0 };
			point=path[i];
			_itoa(distance1[point][path[i + 1]], tmps, 10);
			direction_to_Name(direction1[point][path[i+1]],dname);
			notes[j][0]=direction1[point][path[i+1]];
	        printf("沿%s方向 ",dname);
			strcat(ws, "沿");
			strcat(ws, dname);
			strcat(ws, "方向 ");
	        notes[j][1]=distance1[point][path[i+1]];
	        j++;
	        printf("前进%d米 ",distance1[point][path[i+1]]);
			strcat(ws, "前进");
			strcat(ws, tmps);
			strcat(ws, "米 ");
			if(path[i+1]<20)//从第二个点到终点均判断一次 
			{
				Num_to_Name(sCampus,path[i+1],name);
				printf("到达%s\n",name);//“到达建筑”
				strcat(ws, "到达");
				strcat(ws, name);
				strcat(ws, "\n");
			}
			i++;
		}
	}
	else if(sCampus==2&&eCampus==2)//校区2的内部导航 
	{
		while(path[i+1]!=-1)//path[i]不是终点 
		{
			char tmps[20] = { 0 };
			point=path[i];
			_itoa(distance2[point][path[i + 1]], tmps, 10);
			direction_to_Name(direction2[point][path[i+1]],dname);
			notes[j][0]=direction2[point][path[i+1]];
	        printf("沿%s方向 ",dname);
			strcat(ws, "沿");
			strcat(ws, dname);
			strcat(ws, "方向 ");
	        notes[j][1]=distance2[point][path[i+1]];
	        j++;
	        printf("前进%d米 ",distance2[point][path[i+1]]);
			strcat(ws, "前进");
			strcat(ws, tmps);
			strcat(ws, "米 ");
			if(path[i+1]<20)//从第二个点到终点均判断一次 
			{
				Num_to_Name(sCampus,path[i+1],name);
				printf("到达%s\n",name);//“到达建筑” 
				strcat(ws, "到达");
				strcat(ws, name);
				strcat(ws, "\n");
			}
			i++;
		}
	}
	else if(sCampus==1&&eCampus==2)//从校区1到校区2
	{
		while(path[i+1]!=-2&&path[i+1]!=-3)//还在起点所在的校区内
		{
			char tmps[20] = { 0 };
			point=path[i];
			_itoa(distance1[point][path[i + 1]], tmps, 10);
			direction_to_Name(direction1[point][path[i+1]],dname);
			notes[j][0]=direction1[point][path[i+1]];
	        printf("沿%s方向 ",dname);
			strcat(ws, "沿");
			strcat(ws, dname);
			strcat(ws, "方向 ");
	        notes[j][1]=distance1[point][path[i+1]];
	        j++; 
	        printf("前进%d米 ",distance1[point][path[i+1]]);
			strcat(ws, "前进");
			strcat(ws, tmps);
			strcat(ws, "米 ");
		    if(path[i+1]<20)//从第二个点到车站均判断一次 
		    {
		    	Num_to_Name(sCampus,path[i+1],name);
			    printf("到达%s\n",name);//“到达建筑” 
				strcat(ws, "到达");
				strcat(ws, name);
				strcat(ws, "\n");
			}
		    i++;
		}//现在的path[i]即为车站
		if(path[i+1]==-2) 
		{
			notes[j][0]=-2;
		    notes[j][1]=-2;
		    j++;
		    printf("乘坐班车到达二校区班车站\n");
			strcat(ws, "乘坐班车到达二校区班车站\n");
		}
		else
		{
			notes[j][0]=-3;
		    notes[j][1]=-3;
		    j++;
			printf("乘坐公交车到达二校区公交车站\n");
			strcat(ws, "乘坐公交车到达二校区公交车站\n");
		} 
		i++;
		i++;//path[i]为二校区车站 作为起点 
		while(path[i+1]!=-1)
		{
			char tmps[20] = { 0 };
			point=path[i];
			_itoa(distance2[point][path[i + 1]], tmps, 10);
			direction_to_Name(direction2[point][path[i+1]],dname);
			notes[j][0]=direction2[point][path[i+1]];
	        printf("沿%s方向 ",dname);
			strcat(ws, "沿");
			strcat(ws, dname);
			strcat(ws, "方向 ");
	        notes[j][1]=distance2[point][path[i+1]];
	        j++;
	        printf("前进%d米 ",distance2[point][path[i+1]]);
			strcat(ws, "前进");
			strcat(ws, tmps);
			strcat(ws, "米 ");
		    if(path[i+1]<20)//从车站后第一个点到终点均判断一次 
		    {
		    	Num_to_Name(eCampus,path[i+1],name);
			    printf("到达%s \n",name);//“到达建筑” 
				strcat(ws, "到达");
				strcat(ws, name);
				strcat(ws, "\n");
			}
			i++;
		}
	} 
	else if(sCampus==2&&eCampus==1)//从校区2到校区1
	{
		while(path[i+1]!=-2&&path[i+1]!=-3)//还在起点所在的校区内
		{
			char tmps[20] = { 0 };
			point=path[i];
			_itoa(distance2[point][path[i + 1]], tmps, 10);
			direction_to_Name(direction2[point][path[i+1]],dname);
			notes[j][0]=direction2[point][path[i+1]];
	        printf("沿%s方向 ",dname);
			strcat(ws, "沿");
			strcat(ws, dname);
			strcat(ws, "方向 ");
	        notes[j][1]=distance2[point][path[i+1]];
	        j++;
	        printf("前进%d米 ",distance2[point][path[i+1]]);
			strcat(ws, "前进");
			strcat(ws, tmps);
			strcat(ws, "米 ");
		    if(path[i+1]<20)//从第二个点到车站均判断一次 
		    {
		    	Num_to_Name(sCampus,path[i+1],name);
			    printf("到达%s\n",name);//“到达建筑” 
				strcat(ws, "到达");
				strcat(ws, name);
				strcat(ws, "\n");
			}
		    i++;
		}//现在的path[i]即为车站
		if(path[i+1]==-2) 
		{
			notes[j][0]=-2;
		    notes[j][1]=-2;
		    printf("乘坐班车到达一校区班车站\n");
			strcat(ws, "乘坐班车到达一校区班车站\n");
		    j++;
		}
		else
		{
			notes[j][0]=-3;
		    notes[j][1]=-3;
		    printf("乘坐公交车到达一校区公交车站\n"); 
			strcat(ws, "乘坐公交车到达一校区公交车站\n");
		    j++;
		}
		i++;
		i++;//path[i]为一校区车站 作为起点 
		while(path[i+1]!=-1)
		{
			char tmps[20] = { 0 };
			point=path[i];
			_itoa(distance1[point][path[i + 1]], tmps, 10);
			direction_to_Name(direction1[point][path[i+1]],dname);
			notes[j][0]=direction1[point][path[i+1]];
	        printf("沿%s方向 ",dname);
			strcat(ws, "沿");
			strcat(ws, dname);
			strcat(ws, "方向 ");
	        notes[j][1]=distance1[point][path[i+1]];
	        j++;
	        printf("前进%d米 ",distance1[point][path[i+1]]);
			strcat(ws, "前进");
			strcat(ws, tmps);
			strcat(ws, "米 ");
		    if(path[i+1]<20)//从车站后第一个点到终点均判断一次 
		    {
		    	Num_to_Name(eCampus,path[i+1],name);
			    printf("到达%s \n",name);//“到达建筑” 
				strcat(ws, "到达");
				strcat(ws, name);
				strcat(ws, "\n");
			}
			i++;
		}
	} 
	writelog(0, 1, ws, 0, 0);
} 

