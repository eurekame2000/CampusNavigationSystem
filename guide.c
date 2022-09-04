#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"main.h"
#include"guide.h"
#include"printway.h"
#include"initialize.h"
#pragma warning(disable:4996);

int timeCompare(int len1, int len2, int walk);//公交和校车路径花费时间对比，并选出最佳交通方案
void setPath2(int start, int end, int *path, int s);//设置步行最短时间路径
void setPath4(int start, int end, int *path, int s);//设置骑行最短时间路径
void shortestTime(int sCampus, int start, int eCampus, int end, int *path);//步行最短时间路径
void bshortestTime(int sCampus, int start, int eCampus, int end, int *path);//骑行最短时间路径
int exist(int s,int *path);//判断路径是否存在

void findWay(int sCampus, int start, int eCampus, int end, int type, int pass[][20], int* path);
void Guide(int sCampus, int start, int eCampus, int end, int type, int pass[][20]);
void shortestPath(int sCampus, int start, int eCampus, int end, int* paths);
void copy(int n, int locate, int(*map)[75], int(*path)[75]);
void shortPath(int n, int map[][75], int(*path1)[75]);
int distance_path(int start, int end, int map[][75], int path1[][75]);
void short_path(int* path, int start, int end, int path1[][75], int sign);
void pass_shortest(int sCampus, int start, int eCampus, int end, int pass[][20], int* paths);
void pass_shortest1(int sCampus, int start, int eCampus, int end, int pass[][20], int* paths, int* sign);
void pass_shortest2(int sCampus, int start, int eCampus, int end, int pass[][20], int* paths);
int store_path(int path_1[], int ad, int* paths);
int nearest(int pass[][20]);

void Guide(int sCampus,int start,int eCampus,int end,int type,int pass[][20])
{
	int i,j,path[160],t,s;//存路径节点数组
	for(i=0;i<160;i++)
	    path[i]=-1; 
	int notes[160][2];
	for(i=0;i<160;i++)
	{
		for(j=0;j<2;j++)
		    notes[i][j]=-1;
	}
	//导航路线的查询
	findWay(sCampus,start,eCampus,end,type,pass,path);
	system("cls");
	//导航路线的输出
	printWay(type,sCampus,eCampus,start,end,path,0,pass,notes);
	//执行导航路线的模拟
	if (type == 4) {
		if (sCampus == eCampus) {
			s = sCampus;
		}
		else if (sCampus == 1) {
			s = 3;
		}
		else {
			s = 4;
		}
		if (exist(s,path)) {
			printf("\n是否要进行模拟导航？\n");
			printf("<1>是  <2>否\n");
			scanf("%d",&s);
			judge(&s,1);
			if(s==1) 
			{
				mock(type, sCampus, eCampus, start, end, path, notes);
				printf("\n导航结束，欢迎下次使用！");
			}
			else
			    printf("\n导航结束，欢迎下次使用！");
		}
		//当前无路线无法进行模拟导航
		else
		{
			printf("\n当前导航路线不存在，无法进行模拟导航\n");
			printf("\n导航结束，欢迎下次使用！"); 
		} 
	}
	else {
		printf("\n是否要进行模拟导航？\n");
		printf("<1>是  <2>否\n");
		scanf("%d",&s);
		judge(&s,1);
		if(s==1) 
		{
			mock(type, sCampus, eCampus, start, end, path, notes);
			printf("\n导航结束，欢迎下次使用！");
		}
		else
		    printf("\n导航结束，欢迎下次使用！");
	}
}

//导航路线的查询
void findWay(int sCampus,int start,int eCampus,int end,int type,int pass[][20],int* path)
{ 
	
	if (type == 1)//最短距离策略
		shortestPath(sCampus, start, eCampus, end, path);
	else if (type == 2)//最短时间策略
		shortestTime(sCampus, start, eCampus, end, path);
	else if (type == 3)//途经最短距离策略 
		pass_shortest(sCampus, start, eCampus, end, pass, path);
	else//交通工具最短时间策略 
		bshortestTime(sCampus, start, eCampus, end, path);
} 

////************最短距离策略***********////
void shortestPath(int sCampus,int start,int eCampus,int end,int* paths)
{
	int map1[75][75];
	int map2[75][75];
	int path1[75][75];//存路径节点矩阵
	int path2[75][75];
	int path_1[75];//存起点与终点间的路径节点
	int path_2[75]; 
	int i,j,k,n1,n2,distance_1,distance_2,end1,end2;
	
	//起点和终点在同一校区
	if(sCampus==eCampus)
	{
		if(sCampus==1)
		    n1=72;
		else
		    n1=70;
		//初始化 
		copy(n1,sCampus,map1,path1);
	//	printf("%d\n",map1[1][25]);
	//	printf("%d\n",map1[25][26]);
	//	printf("%d\n",path1[1][25]);
	//	printf("%d\n",path1[25][26]);
	    for(i=0;i<75;i++)
	        path_1[i]=-1;
	    //核心算法
		shortPath(n1,map1,path1);
		//寻找最短路径
        short_path(path_1,start,end,path1,0);
  //    for(i=0;i<10;i++)
  //        printf("%d ",path_1[i]);
		i=0;
		while(path_1[i]!=-1)
		{
			i++;
		}	
		i--;
		for(j=0;i!=0;i--)
		{
			paths[j]=path_1[i];
			j++;
		}
		paths[j]=path_1[i];
	 }
	//起点和终点不在同一个校区
	else
	{
		if(sCampus==1)
		{
			n1=72;
			n2=70;
            end1=0;//班车站
			end2=1;//公交站 
		}
		else
		{
			n1=70;
			n2=72;
			end1=15;//班车站 
			end2=0;//公交站 
		}
		//初始化
		copy(n1,sCampus,map1,path1);
		copy(n2,eCampus,map2,path2);
		for(i=0;i<75;i++)
	    {
	    	path_1[i]=-1;
			path_2[i] = -1;
		}
		//核心算法
		shortPath(n1,map1,path1);
		shortPath(n2,map2,path2);
		//对起点校区到班车站还是公交站的处理
		distance_1 = distance_path(start, end1, map1, path1);
		distance_2=distance_path(start,end2,map1,path1);
		if(distance_1<=distance_2)//坐班车
		{
			short_path(path_1,start,end1,path1,1);
	    	if(sCampus==1)
	    	    short_path(path_2,15,end,path2,0);
	    	else
	    	    short_path(path_2,0,end,path2,0);
		} 
		else//坐公交车 
	    {
			short_path(path_1,start,end2,path1,2);
			if(sCampus==1)
			    short_path(path_2,0,end,path2,0);
			else
			    short_path(path_2,1,end,path2,0);		    	
		}
		//存最短路径
		//存起点校区内路径 
		i=0;
		while(path_1[i]!=-1)
		{
			i++;
		}	
		i--;
		for(j=0;i!=0;i--)
		{
			paths[j]=path_1[i];
			j++;
		}
		paths[j]=path_1[i];
		//存终点校区内路径 
		i=0;
		while(path_2[i]!=-1)
		{
			i++;
		}	
		i--;
		j++;
		for(;i!=0;i--)
		{
			paths[j]=path_2[i];
			j++;
		}
		paths[j]=path_2[i];

   }
}

//初始化路径矩阵 
void copy(int n,int locate,int (*map)[75],int (*path)[75])
{
	int i,j,inf;
	inf=999999;//人为设置的正无穷值
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)//i,j同一点 
			    *(*(map+i)+j)=0;
			else//i,j不同点 
			{
                if(locate==1)//校区一
				{
					if(distance1[i][j]==-1||distance1[j][i]==-1)//i,j之间无路径 
				        *(*(map+i)+j)=inf;
				    else
				   {
			     		if(distance1[i][j]==0)
				    	    *(*(map+i)+j)=distance1[j][i];
					    else
					        *(*(map+i)+j)=distance1[i][j];
				    }
				 }
				else//校区二 
				{
					if(distance2[i][j]==-1||distance2[j][i]==-1)//i,j之间无路径 
				        *(*(map+i)+j)=inf;
		    		else
			    	{
				    	if(distance2[i][j]==0)
					        *(*(map+i)+j)=distance2[j][i];
					    else 
					        *(*(map+i)+j)=distance2[i][j];
				    }
				} 	
			}
			*(*(path+i)+j)=i;
		}
	 } 
}

//Floyd算法求最短路径
void shortPath(int n,int map[][75],int (*path1)[75])
{
	int i,j,k;
    for(k=0;k<n;k++)
    {
    	for(i=0;i<n;i++)
    	{
    		for(j=0;j<n;j++)
    		{
    			if(map[i][j]>map[i][k]+map[k][j])
    			{
    				map[i][j]=map[i][k]+map[k][j];
    				*(*(path1+i)+j)=*(*(path1+k)+j);
				}
			}
		}
	}
 }
 
//返回路径长度
int distance_path(int start,int end,int map[][75],int path1[][75])
{
	int i,j,distance,p,q;
	i=0;
	j=end;
    distance=0;
    q=j;
    while(path1[start][j]!=start)
    {
    	i++;
    	p=j;
    	j=path1[start][j];
		q = j;
    	distance=distance+map[p][q];
    }
    p=j;
    q=start;
    distance=distance+map[p][q];
	return distance;	
}

//找最短路径
void short_path(int* path,int start,int end,int path1[][75],int sign)
{
	int i,j;
	if(sign==1)
	{
		path[0]=-2;//坐班车的标记
		i = 1;
	}
	else if(sign==2)
	{
		path[0]=-3;//坐公交车的标记
		i = 1;
	 } 
	else
	    i=0;
    j=end;
    path[i]=j;
    //处理本段路起点是整个导航终点的情况 
    if(start!=end)
    {
        while(path1[start][j]!=start)
        {
    	    i++;
    	    j=path1[start][j];
    	    path[i]=j;
        }
        path[i]=j;
        i++;
        path[i]=start;
	}
}

////************途经最短距离策略***********////
void pass_shortest(int sCampus,int start,int eCampus,int end,int pass[][20],int* paths)
{
	int sign = 0;
	//起点和终点在同一个校区 
	if(sCampus==eCampus)
        pass_shortest1(sCampus,start,eCampus,end,pass,paths,&sign);
	//起点和终点不在同一校区
	else
	    pass_shortest2(sCampus,start,eCampus,end,pass,paths); 
}

//起点和终点在同一校区的途经最短距离策略 
void pass_shortest1(int sCampus,int start,int eCampus,int end,int pass[][20],int* paths,int* sign)
{
	int map1[75][75];
	int map2[75][75];
	int path1[75][75];//存路径节点矩阵
	int path2[75][75];
	int path_1[75];//存起点与终点间的路径节点
	int path_2[75];
	int pass_1[2][20];//复制存储pass数组的信息 
	int i,j,k,ad,locate,n1,n2,end1,end2,start1,distance_1,distance_2;
	
	//将pass数组信息存到pass1中
	for(i=0;i<2;i++)
	{
		for(j=0;j<20;j++)
		    pass_1[i][j]=pass[i][j];
	 } 
	
	//起点和终点在同一个校区
	if(sCampus==1)
	    n1=72;
	else
	    n1=70;
	//初始化 
	copy(n1,sCampus,map1,path1);
   for(i=0;i<75;i++)
        path_1[i]=-1;
    //核心算法
	shortPath(n1,map1,path1);
	//将途径的点进行分段处理，每段都是最短路径，依次途经离得最近的节点
	start1=start;
	for(i=0;pass_1[0][i]!=-1;i++)
	{
		//求现在起点到各未途经点的距离，选出最近的点作为下一个途经点
       for(j=0;pass_1[0][j]!=-1;j++)
        {
        	if(pass_1[1][j]!=-2)//该点未被途经
			    pass_1[1][j]=distance_path(start1,pass_1[0][j],map1,path1);
		}
		//找到距离最近的点
        locate=nearest(pass_1);
		pass_1[1][locate]=-2;//标记该点已经被途经
		//找该段的最短路径
		short_path(path_1,start1,pass_1[0][locate],path1,0);
		//存最短路径 
		if(start1==start)
		    ad=0;
		ad=store_path(path_1,ad,paths);
		for(j=0;j<75;j++)//找完一段初始化一次 
		    path_1[j]=-1; 
		start1=pass_1[0][locate];//更新下一段的起点 
	}
	//寻找并存储最后一个途经点到终点的最短路径
    if(*sign==0)//导航发生在校区内，终点已经确定
	{
		short_path(path_1,start1,end,path1,0);
	    ad=store_path(path_1,ad,paths);
	}
	else//确定终点是公交站还是班车站 
	{
		if(sCampus==1)
		{
			end1=0;
			end2=1;
		}
		else
		{
			end1=15;
			end2=0;
		}
		//对校区终点是到班车站还是公交站的处理
		distance_1 = distance_path(start1, end1, map1, path1);
		distance_2=distance_path(start1,end2,map1,path1);
		if(distance1<=distance2)//坐班车
		{
			short_path(path_1,start1,end1,path1,1);//将起点校区最短路径存进path_1 
			if (sCampus == 1)
				*sign = 15;
			else
				*sign = 0;
		} 
		else//坐公交车 
	    {
			short_path(path_1,start1,end2,path1,2);
			if(sCampus==1)
			    *sign=0;
			else
			    *sign=1;		    	
		}
		ad=store_path(path_1,ad,paths);//将校区一的最短路径存进paths数组
	}				
}

//起点和终点不在同一校区的途经最短距离策略
void pass_shortest2(int sCampus,int start,int eCampus,int end,int pass[][20],int* paths)
{
	int map1[75][75];
	int map2[75][75];
	int path1[75][75];//存路径节点矩阵
	int path2[75][75];
	int path_1[75];//存起点与终点间的路径节点
	int path_2[75];
	int pass_1[2][20];
	int pass1[20] = { 0 };
	int pass2[20] = { 0 };
	int i,j,k,ad,sign,locate,n1,n2,end1,end2,start1, distance_1, distance_2;
	
	//将pass数组信息存到pass_1中
	for(i=0;i<2;i++)
	{
		for(j=0;j<20;j++)
		    pass_1[i][j]=pass[i][j];
	 } 
	
	if(sCampus==1)
	{
		n1=72;
		n2=70;
        end1=0;//班车站
		end2=1;//公交站 
	}
	else
	{
		n1=70;
		n2=72;
		end1=15;//班车站 
		end2=0;//公交站 
	}
	//初始化
	copy(n1,sCampus,map1,path1);
	copy(n2,eCampus,map2,path2);
	for(i=0;i<75;i++)
    {
    	path_1[i]=-1;
		path_2[i] = -1;
	}
	//核心算法
	shortPath(n1,map1,path1);
	shortPath(n2,map2,path2);
	//起点校区并未途经任何点
	if(pass_1[0][0]==-1)
	{
		//对起点校区到班车站还是公交站的处理
		distance_1 = distance_path(start, end1, map1, path1);
		distance_2=distance_path(start,end2,map1,path1);
		if(distance1<=distance2)//坐班车
		{
			short_path(path_1,start,end1,path1,1);//将起点校区最短路径存进path_1 
			if (sCampus == 1)
				start1 = 15;
			else
				start1 = 0;
		} 
		else//坐公交车 
	    {
			short_path(path_1,start,end2,path1,2);
			if(sCampus==1)
			    start1=0;
			else
			    start1=1;		    	
		}
		ad=store_path(path_1,0,paths);//将校区一的最短路径存进paths数组
		//处理终点校区内的途经最短距离问题 
		for(i=0;i<20;i++)
		{
			pass_1[0][i]=pass_1[1][i];
			pass_1[1][i]=-1;
	    }
        sign=0;	
		pass_shortest1(eCampus, start1, eCampus, end, pass_1, path_2, &sign);
		//将终点校区内的途经最短距离路径存进paths
		j=ad;
		for(i=0;path_2[i]!=-1;i++)
		{
			paths[j]=path_2[i];
			j++;
		}
	 } 
	else
	{
		sign=1;
		//处理起点校区内的途经最短距离问题
		for(i=0;i<20;i++)
		{
			pass2[i]=pass_1[1][i];
			pass_1[1][i]=-1;
	    }
		pass_shortest1(sCampus,start,sCampus,end,pass_1,paths,&sign);//此时已将起点校区的途经最短路径顺序存进了paths数组中
		//处理终点校区内的途经最短距离问题
		start1=sign;
		i=0;
		//将ad定位到paths下一次开始存的位置 
		while(paths[i]!=-1)
		    i++;
		ad=i;
		
		//终点校区内没有需要途经的地点
		if(pass2[0]==-1) 
		{
			//找最短路径 
			short_path(path_2,start1,end,path2,0);
			//将终点校区内的最短路径存进pahts中 
			store_path(path_2,ad,paths);
		}
		
		//终点校区内有需要途经的地点 
		else
		{
			for(i=0;i<20;i++)
			{
				pass_1[0][i]=pass2[i];
				pass_1[1][i]=-1;
			}
			//终点校区的途经最短路径顺序存进了path_2数组中
			sign=0;
			pass_shortest1(eCampus,start1,eCampus,end,pass_1,path_2,&sign);
			//将终点校区的途经最短距离路径存进paths中 
		    //将终点校区内的途经最短距离路径存进paths
		    j=ad;
		    for(i=0;path_2[i]!=-1;i++)
		    {
		    	paths[j]=path_2[i];
			    j++;
		    }			
		}
	}
 } 

//存储最短路径
int store_path(int path_1[],int ad,int* paths)
{
	int i,j;
	i=0;
	while(path_1[i]!=-1)//定位到起点 
	    i++;
	i--;
	if(ad!=0&&paths[ad-1]==path_1[i])//避免重复 
	    i--;
	for(j=ad;i!=0;i--)
	{
		paths[j]=path_1[i];
		j++;
	}
	paths[j]=path_1[i];
	j++;
	return j;//返回下一次开始存的位置
}

//找到并返回距离目前起点最近的点的数组下标
int nearest(int pass[][20])
{
	int j,s,min,locate;
	for(j=0,s=0;pass[0][j]!=-1;j++)
	{
		if(pass[1][j]!=-2&&s==0)
		{
			s=1;
			min=pass[1][j];
			locate=j;
		}
		else if(pass[1][j]!=-2&&s==1)
		{
			if(pass[1][j]<min)//更新距离最近的点
			{
				min=pass[1][j];
				locate=j;
			 } 
		}
	 } 
	return locate;
 } 
int timeCompare(int len1, int len2, int walk) {
	int choice = 0, t1 = 0, t2 = 0;
	int tmpspd;//速度缓存
	if (walk) {//步行状态下的速度设置
		tmpspd = wspeed;
	}
	else {//骑行状态下的速度设置
		tmpspd = bspeed;
	}
	t1 = len1 / tmpspd + buscost;
	t2 = len2 / tmpspd + schoolbuscost;
	if (t1 < t2) {
		choice = 1;
	}
	else {
		choice = 2;
	}
	return choice;
}
void setPath2(int start, int end, int *path, int s) {//存储该起始点途径节点数组
													 /*count:校区内导航的总结点数-1，count1：通过公交车跨校区导航的总结点数-1
													 count2:通过校车（班车）跨校区导航的总结点数-1*/
	int i,count = 0, count1 = 0, count2 = 0, blen = 0, sblen = 0, choice = 0;
	int tmppath[80] = { 0 }, tmppath1[80] = { 0 }, tmppath2[80] = { 0 };//途径节点暂存数组
	if (s == 1) {
		while (start != end) {
			tmppath[count++] = start;
			start = path2[0][start][end];
		}
		tmppath[count++] = start;
		tmppath[count++] = -1;
	}
	else if (s == 2) {
		while (start != end) {
			tmppath[count++] = start;
			start = path2[1][start][end];
		}
		tmppath[count++] = start;
		tmppath[count++] = -1;
	}
	else if (s == 3) {
		int s = start;
		while (start != bus1) {
			blen += equidis2[0][start][path2[0][start][bus1]];
			tmppath1[count1++] = start;
			start = path2[0][start][bus1];
		}
		tmppath1[count1++] = start;
		tmppath1[count1++] = bus;
		start = bus2;
		while (start != end) {
			blen += equidis2[1][start][path2[1][start][end]];
			tmppath1[count1++] = start;
			start = path2[1][start][end];
		}
		tmppath1[count1++] = start;
		tmppath1[count1++] = -1;
		start = s;
		while (start != schoolbus1) {
			sblen += equidis2[0][start][path2[0][start][schoolbus1]];
			tmppath2[count2++] = start;
			start = path2[0][start][schoolbus1];
		}
		tmppath2[count2++] = start;
		tmppath2[count2++] = schoolbus;
		start = schoolbus2;
		while (start != end) {
			sblen += equidis2[1][start][path2[1][start][end]];
			tmppath2[count2++] = start;
			start = path2[1][start][end];
		}
		tmppath2[count2++] = start;
		tmppath2[count2++] = -1;
	}
	else if (s == 4) {
		int s = start;
		while (start != bus2) {
			blen += equidis2[1][start][path2[1][start][bus2]];
			tmppath1[count1++] = start;
			start = path2[1][start][bus2];
		}
		tmppath1[count1++] = start;
		tmppath1[count1++] = bus;
		start = bus1;
		while (start != end) {
			blen += equidis2[0][start][path2[0][start][end]];
			tmppath1[count1++] = start;
			start = path2[0][start][end];
		}
		tmppath1[count1++] = start;
		tmppath1[count1++] = -1;
		start = s;
		while (start != schoolbus2) {
			sblen += equidis2[1][start][path2[1][start][schoolbus2]];
			tmppath2[count2++] = start;
			start = path2[1][start][schoolbus2];
		}
		tmppath2[count2++] = start;
		tmppath2[count2++] = schoolbus;
		start = schoolbus1;
		while (start != end) {
			sblen += equidis2[0][start][path2[0][start][end]];
			tmppath2[count2++] = start;
			start = path2[0][start][end];
		}
		tmppath2[count2++] = start;
		tmppath2[count2++] = -1;
	}
	if ((s == 3) || (s == 4)) {
		choice = timeCompare(blen, sblen, 1);
		if (choice == 1) {
			count = count1;
		}
		else {
			count = count2;
		}
		for (i = 0; i < count; i++) {
			if (choice == 1) {
				tmppath[i] = tmppath1[i];
			}
			else {
				tmppath[i] = tmppath2[i];
			}
		}
	}
	for (i = 0; tmppath[i]!=-1; i++) {
		path[i] = tmppath[i];
	}
	path[i] = -1;
}

void setPath4(int start, int end, int *path, int s) {
	//存储该起始点途径节点数组
	/*count:校区内导航的总结点数-1，count1：通过公交车跨校区导航的总结点数-1
	count2:通过校车（班车）跨校区导航的总结点数-1*/
	int i,count = 0, count1 = 0, count2 = 0, blen = 0, sblen = 0, choice = 0;
	int tmppath[80] = { 0 }, tmppath1[80] = { 0 }, tmppath2[80] = { 0 };//途径节点暂存数组
	if (s == 1) {
		while (start != end) {
			tmppath[count++] = start;
			start = path4[0][start][end];
		}
		tmppath[count++] = start;
		tmppath[count++] = -1;
	}
	else if (s == 2) {
		while (start != end) {
			tmppath[count++] = start;
			start = path4[1][start][end];
		}
		tmppath[count++] = start;
		tmppath[count++] = -1;
	}
	else if (s == 3) {
		int s = start;
		while (start != bus1) {
			blen += equidis4[0][start][path4[0][start][bus1]];
			tmppath1[count1++] = start;
			start = path4[0][start][bus1];
		}
		tmppath1[count1++] = start;
		tmppath1[count1++] = bus;
		start = bus2;
		while (start != end) {
			blen += equidis4[1][start][path4[1][start][end]];
			tmppath1[count1++] = start;
			start = path4[1][start][end];
		}
		tmppath1[count1++] = start;
		tmppath1[count1++] = -1;
		start = s;
		while (start != schoolbus1) {
			sblen += equidis4[0][start][path4[0][start][schoolbus1]];
			tmppath2[count2++] = start;
			start = path4[0][start][schoolbus1];
		}
		tmppath2[count2++] = start;
		tmppath2[count2++] = schoolbus;
		start = schoolbus2;
		while (start != end) {
			sblen += equidis4[1][start][path4[1][start][end]];
			tmppath2[count2++] = start;
			start = path4[1][start][end];
		}
		tmppath2[count2++] = start;
		tmppath2[count2++] = -1;
	}
	else if (s == 4) {
		int s = start;
		while (start != bus2) {
			blen += equidis4[1][start][path4[1][start][bus2]];
			tmppath1[count1++] = start;
			start = path4[1][start][bus2];
		}
		tmppath1[count1++] = start;
		tmppath1[count1++] = bus;
		start = bus1;
		while (start != end) {
			blen += equidis4[0][start][path4[0][start][end]];
			tmppath1[count1++] = start;
			start = path4[0][start][end];
		}
		tmppath1[count1++] = start;
		tmppath1[count1++] = -1;
		start = s;
		while (start != schoolbus2) {
			sblen += equidis4[1][start][path4[1][start][schoolbus2]];
			tmppath2[count2++] = start;
			start = path4[1][start][schoolbus2];
		}
		tmppath2[count2++] = start;
		tmppath2[count++] = schoolbus;
		start = schoolbus1;
		while (start != end) {
			sblen += equidis4[0][start][path4[0][start][end]];
			tmppath2[count2++] = start;
			start = path4[0][start][end];
		}
		tmppath2[count2++] = start;
		tmppath2[count2++] = -1;
	}
	if ((s == 3) || (s == 4)) {
		choice = timeCompare(blen, sblen, 0);
		if (choice == 1) {
			count = count1;
		}
		else {
			count = count2;
		}
		for ( i = 0; i < count; i++) {
			if (choice == 1) {
				tmppath[i] = tmppath1[i];
			}
			else {
				tmppath[i] = tmppath2[i];
			}
		}
	}
	for (i = 0; tmppath[i] != -1; i++) {
		path[i] = tmppath[i];
	}
	path[i] = -1;
}
void shortestTime(int sCampus, int start, int eCampus, int end, int *path) {//最短时间策略
	int s = -1;
	//仅校区1：s=1，仅校区2：s=2，校区1到校区2：s=3，校区2到校区1：s=4
	if (sCampus == eCampus) {
		s = sCampus;
	}
	else if (sCampus == 1) {
		s = 3;
	}
	else {
		s = 4;
	}
	setPath2(start, end, path, s);//计算并记录途径节点
}
void bshortestTime(int sCampus, int start, int eCampus, int end, int *path) {
	int s = -1;
	//仅校区1：s=1，仅校区2：s=2，校区1到校区2：s=3，校区2到校区1：s=4
	if (sCampus == eCampus) {
		s = sCampus;
	}
	else if (sCampus == 1) {
		s = 3;
	}
	else {
		s = 4;
	}
	setPath4(start, end, path, s);//计算并记录途径节点
	//return exist(s, path);
}
int exist(int s, int *path) {//路径不存在时返回0，否则返回1
	int i;
	if (s == 1) {
		for ( i = 0; (i < 79)&&(path[i+1]!=-1); i++) {
			if (equidis4[0][path[i]][path[i + 1]] == infi) {
				return 0;
			}
		}
	}
	else if (s == 2) {
		for ( i = 0; (i < 79) && (path[i + 1] != -1); i++) {
			if (equidis4[1][path[i]][path[i + 1]] == infi) {
				return 0;
			}
		}
	}
	else if (s == 3) {
		int i;
		for (i = 0; (i < 80) && (path[i + 1] != bus) && (path[i + 1] != schoolbus); i++) {
			if (equidis4[0][path[i]][path[i + 1]] == infi) {
				return 0;
			}
		}
		if ((path[i+1] == bus)||(path[i+1] == schoolbus)) {
			i+=2;
		}
		for (; (i < 79)&&(path[i+1]!=-1); i++) {
			if (equidis4[1][path[i]][path[i + 1]] == infi) {
				return 0;
			}
		}
	}
	else {
		int i;
		for (i = 0; (i < 80) && (path[i + 1] != bus) && (path[i + 1] != schoolbus); i++) {
			if (equidis4[1][path[i]][path[i + 1]] == infi) {
				return 0;
			}
		}
		if ((path[i+1] == bus) || (path[i+1] == schoolbus)) {
			i+=2;
		}
		for (; (i < 79) && (path[i + 1] != -1); i++) {
			if (equidis4[0][path[i]][path[i + 1]] == infi) {
				return 0;
			}
		}
	}
	return 1;
}
