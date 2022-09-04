#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"main.h"
#include"guide.h"
#include"printway.h"
#include"initialize.h"
#pragma warning(disable:4996);

int timeCompare(int len1, int len2, int walk);//������У��·������ʱ��Աȣ���ѡ����ѽ�ͨ����
void setPath2(int start, int end, int *path, int s);//���ò������ʱ��·��
void setPath4(int start, int end, int *path, int s);//�����������ʱ��·��
void shortestTime(int sCampus, int start, int eCampus, int end, int *path);//�������ʱ��·��
void bshortestTime(int sCampus, int start, int eCampus, int end, int *path);//�������ʱ��·��
int exist(int s,int *path);//�ж�·���Ƿ����

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
	int i,j,path[160],t,s;//��·���ڵ�����
	for(i=0;i<160;i++)
	    path[i]=-1; 
	int notes[160][2];
	for(i=0;i<160;i++)
	{
		for(j=0;j<2;j++)
		    notes[i][j]=-1;
	}
	//����·�ߵĲ�ѯ
	findWay(sCampus,start,eCampus,end,type,pass,path);
	system("cls");
	//����·�ߵ����
	printWay(type,sCampus,eCampus,start,end,path,0,pass,notes);
	//ִ�е���·�ߵ�ģ��
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
			printf("\n�Ƿ�Ҫ����ģ�⵼����\n");
			printf("<1>��  <2>��\n");
			scanf("%d",&s);
			judge(&s,1);
			if(s==1) 
			{
				mock(type, sCampus, eCampus, start, end, path, notes);
				printf("\n������������ӭ�´�ʹ�ã�");
			}
			else
			    printf("\n������������ӭ�´�ʹ�ã�");
		}
		//��ǰ��·���޷�����ģ�⵼��
		else
		{
			printf("\n��ǰ����·�߲����ڣ��޷�����ģ�⵼��\n");
			printf("\n������������ӭ�´�ʹ�ã�"); 
		} 
	}
	else {
		printf("\n�Ƿ�Ҫ����ģ�⵼����\n");
		printf("<1>��  <2>��\n");
		scanf("%d",&s);
		judge(&s,1);
		if(s==1) 
		{
			mock(type, sCampus, eCampus, start, end, path, notes);
			printf("\n������������ӭ�´�ʹ�ã�");
		}
		else
		    printf("\n������������ӭ�´�ʹ�ã�");
	}
}

//����·�ߵĲ�ѯ
void findWay(int sCampus,int start,int eCampus,int end,int type,int pass[][20],int* path)
{ 
	
	if (type == 1)//��̾������
		shortestPath(sCampus, start, eCampus, end, path);
	else if (type == 2)//���ʱ�����
		shortestTime(sCampus, start, eCampus, end, path);
	else if (type == 3)//;����̾������ 
		pass_shortest(sCampus, start, eCampus, end, pass, path);
	else//��ͨ�������ʱ����� 
		bshortestTime(sCampus, start, eCampus, end, path);
} 

////************��̾������***********////
void shortestPath(int sCampus,int start,int eCampus,int end,int* paths)
{
	int map1[75][75];
	int map2[75][75];
	int path1[75][75];//��·���ڵ����
	int path2[75][75];
	int path_1[75];//��������յ���·���ڵ�
	int path_2[75]; 
	int i,j,k,n1,n2,distance_1,distance_2,end1,end2;
	
	//�����յ���ͬһУ��
	if(sCampus==eCampus)
	{
		if(sCampus==1)
		    n1=72;
		else
		    n1=70;
		//��ʼ�� 
		copy(n1,sCampus,map1,path1);
	//	printf("%d\n",map1[1][25]);
	//	printf("%d\n",map1[25][26]);
	//	printf("%d\n",path1[1][25]);
	//	printf("%d\n",path1[25][26]);
	    for(i=0;i<75;i++)
	        path_1[i]=-1;
	    //�����㷨
		shortPath(n1,map1,path1);
		//Ѱ�����·��
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
	//�����յ㲻��ͬһ��У��
	else
	{
		if(sCampus==1)
		{
			n1=72;
			n2=70;
            end1=0;//�೵վ
			end2=1;//����վ 
		}
		else
		{
			n1=70;
			n2=72;
			end1=15;//�೵վ 
			end2=0;//����վ 
		}
		//��ʼ��
		copy(n1,sCampus,map1,path1);
		copy(n2,eCampus,map2,path2);
		for(i=0;i<75;i++)
	    {
	    	path_1[i]=-1;
			path_2[i] = -1;
		}
		//�����㷨
		shortPath(n1,map1,path1);
		shortPath(n2,map2,path2);
		//�����У�����೵վ���ǹ���վ�Ĵ���
		distance_1 = distance_path(start, end1, map1, path1);
		distance_2=distance_path(start,end2,map1,path1);
		if(distance_1<=distance_2)//���೵
		{
			short_path(path_1,start,end1,path1,1);
	    	if(sCampus==1)
	    	    short_path(path_2,15,end,path2,0);
	    	else
	    	    short_path(path_2,0,end,path2,0);
		} 
		else//�������� 
	    {
			short_path(path_1,start,end2,path1,2);
			if(sCampus==1)
			    short_path(path_2,0,end,path2,0);
			else
			    short_path(path_2,1,end,path2,0);		    	
		}
		//�����·��
		//�����У����·�� 
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
		//���յ�У����·�� 
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

//��ʼ��·������ 
void copy(int n,int locate,int (*map)[75],int (*path)[75])
{
	int i,j,inf;
	inf=999999;//��Ϊ���õ�������ֵ
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)//i,jͬһ�� 
			    *(*(map+i)+j)=0;
			else//i,j��ͬ�� 
			{
                if(locate==1)//У��һ
				{
					if(distance1[i][j]==-1||distance1[j][i]==-1)//i,j֮����·�� 
				        *(*(map+i)+j)=inf;
				    else
				   {
			     		if(distance1[i][j]==0)
				    	    *(*(map+i)+j)=distance1[j][i];
					    else
					        *(*(map+i)+j)=distance1[i][j];
				    }
				 }
				else//У���� 
				{
					if(distance2[i][j]==-1||distance2[j][i]==-1)//i,j֮����·�� 
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

//Floyd�㷨�����·��
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
 
//����·������
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

//�����·��
void short_path(int* path,int start,int end,int path1[][75],int sign)
{
	int i,j;
	if(sign==1)
	{
		path[0]=-2;//���೵�ı��
		i = 1;
	}
	else if(sign==2)
	{
		path[0]=-3;//���������ı��
		i = 1;
	 } 
	else
	    i=0;
    j=end;
    path[i]=j;
    //������·��������������յ����� 
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

////************;����̾������***********////
void pass_shortest(int sCampus,int start,int eCampus,int end,int pass[][20],int* paths)
{
	int sign = 0;
	//�����յ���ͬһ��У�� 
	if(sCampus==eCampus)
        pass_shortest1(sCampus,start,eCampus,end,pass,paths,&sign);
	//�����յ㲻��ͬһУ��
	else
	    pass_shortest2(sCampus,start,eCampus,end,pass,paths); 
}

//�����յ���ͬһУ����;����̾������ 
void pass_shortest1(int sCampus,int start,int eCampus,int end,int pass[][20],int* paths,int* sign)
{
	int map1[75][75];
	int map2[75][75];
	int path1[75][75];//��·���ڵ����
	int path2[75][75];
	int path_1[75];//��������յ���·���ڵ�
	int path_2[75];
	int pass_1[2][20];//���ƴ洢pass�������Ϣ 
	int i,j,k,ad,locate,n1,n2,end1,end2,start1,distance_1,distance_2;
	
	//��pass������Ϣ�浽pass1��
	for(i=0;i<2;i++)
	{
		for(j=0;j<20;j++)
		    pass_1[i][j]=pass[i][j];
	 } 
	
	//�����յ���ͬһ��У��
	if(sCampus==1)
	    n1=72;
	else
	    n1=70;
	//��ʼ�� 
	copy(n1,sCampus,map1,path1);
   for(i=0;i<75;i++)
        path_1[i]=-1;
    //�����㷨
	shortPath(n1,map1,path1);
	//��;���ĵ���зֶδ���ÿ�ζ������·��������;���������Ľڵ�
	start1=start;
	for(i=0;pass_1[0][i]!=-1;i++)
	{
		//��������㵽��δ;����ľ��룬ѡ������ĵ���Ϊ��һ��;����
       for(j=0;pass_1[0][j]!=-1;j++)
        {
        	if(pass_1[1][j]!=-2)//�õ�δ��;��
			    pass_1[1][j]=distance_path(start1,pass_1[0][j],map1,path1);
		}
		//�ҵ���������ĵ�
        locate=nearest(pass_1);
		pass_1[1][locate]=-2;//��Ǹõ��Ѿ���;��
		//�Ҹöε����·��
		short_path(path_1,start1,pass_1[0][locate],path1,0);
		//�����·�� 
		if(start1==start)
		    ad=0;
		ad=store_path(path_1,ad,paths);
		for(j=0;j<75;j++)//����һ�γ�ʼ��һ�� 
		    path_1[j]=-1; 
		start1=pass_1[0][locate];//������һ�ε���� 
	}
	//Ѱ�Ҳ��洢���һ��;���㵽�յ�����·��
    if(*sign==0)//����������У���ڣ��յ��Ѿ�ȷ��
	{
		short_path(path_1,start1,end,path1,0);
	    ad=store_path(path_1,ad,paths);
	}
	else//ȷ���յ��ǹ���վ���ǰ೵վ 
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
		//��У���յ��ǵ��೵վ���ǹ���վ�Ĵ���
		distance_1 = distance_path(start1, end1, map1, path1);
		distance_2=distance_path(start1,end2,map1,path1);
		if(distance1<=distance2)//���೵
		{
			short_path(path_1,start1,end1,path1,1);//�����У�����·�����path_1 
			if (sCampus == 1)
				*sign = 15;
			else
				*sign = 0;
		} 
		else//�������� 
	    {
			short_path(path_1,start1,end2,path1,2);
			if(sCampus==1)
			    *sign=0;
			else
			    *sign=1;		    	
		}
		ad=store_path(path_1,ad,paths);//��У��һ�����·�����paths����
	}				
}

//�����յ㲻��ͬһУ����;����̾������
void pass_shortest2(int sCampus,int start,int eCampus,int end,int pass[][20],int* paths)
{
	int map1[75][75];
	int map2[75][75];
	int path1[75][75];//��·���ڵ����
	int path2[75][75];
	int path_1[75];//��������յ���·���ڵ�
	int path_2[75];
	int pass_1[2][20];
	int pass1[20] = { 0 };
	int pass2[20] = { 0 };
	int i,j,k,ad,sign,locate,n1,n2,end1,end2,start1, distance_1, distance_2;
	
	//��pass������Ϣ�浽pass_1��
	for(i=0;i<2;i++)
	{
		for(j=0;j<20;j++)
		    pass_1[i][j]=pass[i][j];
	 } 
	
	if(sCampus==1)
	{
		n1=72;
		n2=70;
        end1=0;//�೵վ
		end2=1;//����վ 
	}
	else
	{
		n1=70;
		n2=72;
		end1=15;//�೵վ 
		end2=0;//����վ 
	}
	//��ʼ��
	copy(n1,sCampus,map1,path1);
	copy(n2,eCampus,map2,path2);
	for(i=0;i<75;i++)
    {
    	path_1[i]=-1;
		path_2[i] = -1;
	}
	//�����㷨
	shortPath(n1,map1,path1);
	shortPath(n2,map2,path2);
	//���У����δ;���κε�
	if(pass_1[0][0]==-1)
	{
		//�����У�����೵վ���ǹ���վ�Ĵ���
		distance_1 = distance_path(start, end1, map1, path1);
		distance_2=distance_path(start,end2,map1,path1);
		if(distance1<=distance2)//���೵
		{
			short_path(path_1,start,end1,path1,1);//�����У�����·�����path_1 
			if (sCampus == 1)
				start1 = 15;
			else
				start1 = 0;
		} 
		else//�������� 
	    {
			short_path(path_1,start,end2,path1,2);
			if(sCampus==1)
			    start1=0;
			else
			    start1=1;		    	
		}
		ad=store_path(path_1,0,paths);//��У��һ�����·�����paths����
		//�����յ�У���ڵ�;����̾������� 
		for(i=0;i<20;i++)
		{
			pass_1[0][i]=pass_1[1][i];
			pass_1[1][i]=-1;
	    }
        sign=0;	
		pass_shortest1(eCampus, start1, eCampus, end, pass_1, path_2, &sign);
		//���յ�У���ڵ�;����̾���·�����paths
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
		//�������У���ڵ�;����̾�������
		for(i=0;i<20;i++)
		{
			pass2[i]=pass_1[1][i];
			pass_1[1][i]=-1;
	    }
		pass_shortest1(sCampus,start,sCampus,end,pass_1,paths,&sign);//��ʱ�ѽ����У����;�����·��˳������paths������
		//�����յ�У���ڵ�;����̾�������
		start1=sign;
		i=0;
		//��ad��λ��paths��һ�ο�ʼ���λ�� 
		while(paths[i]!=-1)
		    i++;
		ad=i;
		
		//�յ�У����û����Ҫ;���ĵص�
		if(pass2[0]==-1) 
		{
			//�����·�� 
			short_path(path_2,start1,end,path2,0);
			//���յ�У���ڵ����·�����pahts�� 
			store_path(path_2,ad,paths);
		}
		
		//�յ�У��������Ҫ;���ĵص� 
		else
		{
			for(i=0;i<20;i++)
			{
				pass_1[0][i]=pass2[i];
				pass_1[1][i]=-1;
			}
			//�յ�У����;�����·��˳������path_2������
			sign=0;
			pass_shortest1(eCampus,start1,eCampus,end,pass_1,path_2,&sign);
			//���յ�У����;����̾���·�����paths�� 
		    //���յ�У���ڵ�;����̾���·�����paths
		    j=ad;
		    for(i=0;path_2[i]!=-1;i++)
		    {
		    	paths[j]=path_2[i];
			    j++;
		    }			
		}
	}
 } 

//�洢���·��
int store_path(int path_1[],int ad,int* paths)
{
	int i,j;
	i=0;
	while(path_1[i]!=-1)//��λ����� 
	    i++;
	i--;
	if(ad!=0&&paths[ad-1]==path_1[i])//�����ظ� 
	    i--;
	for(j=ad;i!=0;i--)
	{
		paths[j]=path_1[i];
		j++;
	}
	paths[j]=path_1[i];
	j++;
	return j;//������һ�ο�ʼ���λ��
}

//�ҵ������ؾ���Ŀǰ�������ĵ�������±�
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
			if(pass[1][j]<min)//���¾�������ĵ�
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
	int tmpspd;//�ٶȻ���
	if (walk) {//����״̬�µ��ٶ�����
		tmpspd = wspeed;
	}
	else {//����״̬�µ��ٶ�����
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
void setPath2(int start, int end, int *path, int s) {//�洢����ʼ��;���ڵ�����
													 /*count:У���ڵ������ܽ����-1��count1��ͨ����������У���������ܽ����-1
													 count2:ͨ��У�����೵����У���������ܽ����-1*/
	int i,count = 0, count1 = 0, count2 = 0, blen = 0, sblen = 0, choice = 0;
	int tmppath[80] = { 0 }, tmppath1[80] = { 0 }, tmppath2[80] = { 0 };//;���ڵ��ݴ�����
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
	//�洢����ʼ��;���ڵ�����
	/*count:У���ڵ������ܽ����-1��count1��ͨ����������У���������ܽ����-1
	count2:ͨ��У�����೵����У���������ܽ����-1*/
	int i,count = 0, count1 = 0, count2 = 0, blen = 0, sblen = 0, choice = 0;
	int tmppath[80] = { 0 }, tmppath1[80] = { 0 }, tmppath2[80] = { 0 };//;���ڵ��ݴ�����
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
void shortestTime(int sCampus, int start, int eCampus, int end, int *path) {//���ʱ�����
	int s = -1;
	//��У��1��s=1����У��2��s=2��У��1��У��2��s=3��У��2��У��1��s=4
	if (sCampus == eCampus) {
		s = sCampus;
	}
	else if (sCampus == 1) {
		s = 3;
	}
	else {
		s = 4;
	}
	setPath2(start, end, path, s);//���㲢��¼;���ڵ�
}
void bshortestTime(int sCampus, int start, int eCampus, int end, int *path) {
	int s = -1;
	//��У��1��s=1����У��2��s=2��У��1��У��2��s=3��У��2��У��1��s=4
	if (sCampus == eCampus) {
		s = sCampus;
	}
	else if (sCampus == 1) {
		s = 3;
	}
	else {
		s = 4;
	}
	setPath4(start, end, path, s);//���㲢��¼;���ڵ�
	//return exist(s, path);
}
int exist(int s, int *path) {//·��������ʱ����0�����򷵻�1
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
