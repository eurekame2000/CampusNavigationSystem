#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"main.h"

#include"main.h"
#include"initialize.h"
#pragma warning(disable:4996);

void initialize();
void locate();
void distance();
void direction();
void setbikeway();
void setcrowded();
void initMap();//初始化距离矩阵
void setEquiDis();//综合拥挤度或拥挤度+自行车道对距离矩阵进行处理
void floyd24();//floyd处理策略2和策略4距离矩阵




//初始化函数
void initialize()
{
	locate();
	distance();
	direction();
	setbikeway();
	setcrowded();
	initMap();
	setEquiDis();
	floyd24();
}
 
//初始化建筑物坐标 
void locate()
{
	int i,j;
	FILE* fp1,*fp2;
    fp1=fopen("location1.txt","r");
	fp2=fopen("location2.txt","r");
	if (fp1!=NULL && fp2 != NULL)
	{
		//存1校区x,y坐标
		for (i = 0; i < 20; i++)
		{
			for (j = 0; j < 2; j++)
				fscanf(fp1, "%d", &locate1[i][j]);
		}
		fclose(fp1);
		//存2校区的x,y坐标 
		for (i = 0; i < 20; i++)
		{
			for (j = 0; j < 2; j++)
				fscanf(fp2, "%d", &locate2[i][j]);
		}
		fclose(fp2);
		fclose(fp1);
	}
	
} 


//初始化道路距离 
void distance()
{
	int i,j,n;
	FILE* fp1,*fp2;

	fp1=fopen("distances1.txt","r");
	fp2=fopen("data.txt","r");
	//初始化校区的距离矩阵 
	for(i=0;i<80;i++)
	{
		for(j=0;j<80;j++)
		    distance1[i][j]=0;
		    distance2[i][j]=0;
	 }
	if (fp1 != NULL && fp2 != NULL)
	{
		//储存1校区的所有道路
		for (i = 0; i < 72; i++)
		{
			for (j = 0; j < i; j++)
			{
				fscanf(fp1, "%d", &distance1[i][j]);
				distance1[j][i] = distance1[i][j];
				distance1[i][j]=distance1[j][i];
			}
		}
		fclose(fp1);
		//储存2校区的所有道路
		i = 0;
		while (!feof(fp2))
		{
			j = 0;
			fscanf(fp2, "%d", &n);
			while (n != 0)
			{
				distance2[i][j] = n;
				distance2[j][i] = distance2[i][j];
				j++;
				fscanf(fp2, "%d", &n);
			}
			distance2[i][j] = 0;
			//getc(fp2);
			i++;
		}
		fclose(fp2);
	}
}

//初始化方向矩阵
void direction()
{
	int i,j,n;
	FILE* fp1,*fp2;

	fp1=fopen("direction1.txt","r");
	fp2=fopen("direction2.txt","r");
	//初始化方向矩阵
	for(i=0;i<80;i++)
	{
		for(j=0;j<80;j++)
		    direction1[i][j]=0;
		    direction2[i][j]=0;
	 } 
	if (fp1 != NULL && fp2 != NULL)
	{
		//存校区一方向矩阵 
		for (i = 0; i < 72; i++)
		{
			for (j = 0; j < i; j++)
			{
				fscanf(fp1, "%d", &direction1[i][j]);
				if (direction1[i][j] == 1 || direction1[i][j] == 2 || direction1[i][j] == 5 || direction1[i][j] == 6)
					direction1[j][i] = direction1[i][j] + 2;
				else if (direction1[i][j] == 3 || direction1[i][j] == 4 || direction1[i][j] == 7 || direction1[i][j] == 8)
					direction1[j][i] = direction1[i][j] - 2;
				else
					direction1[j][i] = direction1[i][j];
			}
		}
		fclose(fp1);
		//存校区二的方向矩阵
		i = 0;
		while (!feof(fp2))
		{
			j = 0;
			fscanf(fp2, "%d", &n);
			while (n != 0)
			{
				direction2[i][j] = n;
				if (direction2[i][j] == 1 || direction2[i][j] == 2 || direction2[i][j] == 5 || direction2[i][j] == 6)
					direction2[j][i] = direction2[i][j] + 2;
				else if (direction2[i][j] == 3 || direction2[i][j] == 4 || direction2[i][j] == 7 || direction2[i][j] == 8)
					direction2[j][i] = direction2[i][j] - 2;
				else
					direction2[j][i] = direction2[i][j];
				j++;
				fscanf(fp2, "%d", &n);
			}
			direction2[i][j] = 0;
			direction2[j][i] = 0;
			//getc(fp2);
			i++;
		}
		fclose(fp2);
	}
}


//初始化自行车道，0为不可通自行车，1为可以通自行车 
void setbikeway() 
{
	int i, j;
	for (i = 0; i < 80; i++) {//初始化
		for (j = 0; j < 80; j++) {
			bikeway1[i][j] = 0;
			bikeway2[i][j] = 0;
		}
	}
	for (i = 0; i < 80; i++) {
		for (j = 0; j < i; j++) {
			if (distance1[i][j]!=-1) {
				bikeway1[i][j] = rand() % 2;//0或1的随机数
				bikeway1[j][i] = bikeway1[i][j];
			}
			if (distance2[i][j]!=-1) {
				bikeway2[i][j] = rand() % 2;
				bikeway2[j][i] = bikeway2[i][j];
			}
		}
	}
}


//初始化道路拥挤度 
void setcrowded() 
{
	int i, j;
	for (i = 0; i < 80; i++) {//初始化
		for (j = 0; j < 80; j++) {
			crowded1[i][j] = 0;
			crowded2[i][j] = 0;
		}
	}
	for (i = 0; i < 80; i++) {
		for (j = 0; j < i; j++) {
			if (distance1[i][j]!=-1) {
				crowded1[i][j] = rand()/(RAND_MAX+1.0);//0~1之间的小数
				crowded1[j][i]=crowded1[i][j];
			}
			if (distance2[i][j]!=-1) {
				crowded2[i][j] = rand()/(RAND_MAX+1.0);
				crowded2[j][i]=crowded2[i][j];
			}
		}
	}
} 

void initMap() {//处理距离矩阵,初始化路径矩阵
	int tmpdis;//距离矩阵缓存
	int tmpbike;//自行车道缓存
	int i,j,k;
	for (i = 0; i < 80; i++) {
		for (j = 0; j <= i; j++) {
			for (k = 0; k < 2; k++) {
				if (k == 0) {//根据k值选择缓存校区的距离和自行车道
					tmpdis = distance1[i][j];
					tmpbike = bikeway1[i][j];
				}
				else {
					tmpdis = distance2[i][j];
					tmpbike = bikeway2[i][j];
				}
				if (i == j) {
					wdistance[k][i][j] = 0;//自己到自己为0
					bdistance[k][i][j] = 0;
				}
				else {
					if ((tmpdis == -1)||(tmpdis==0)) {
						wdistance[k][i][j] = infi;
						wdistance[k][j][i] = infi;//无法到达的情况
						bdistance[k][i][j] = infi;
						bdistance[k][j][i] = infi;//无法到达的情况
					}
					else {
						wdistance[k][i][j] = tmpdis;
						wdistance[k][j][i] = tmpdis;
						if (tmpbike) {
							bdistance[k][i][j] = tmpdis;
							bdistance[k][j][i] = tmpdis;
						}
						else {
							bdistance[k][i][j] = infi;
							bdistance[k][j][i] = infi;
						}
					}
				}
				path2[k][i][j] = j;
				path4[k][i][j] = j;
				path2[k][j][i] = i;
				path4[k][j][i] = i;
			}
		}
	}
}
void setEquiDis() {//将拥挤度或拥挤度+自行车道考虑在其中后的等同距离矩阵
	int i,j,k;//拥挤度缓存
	double tmpcrw;
	for (i = 0; i < 80; i++) {
		for (j = 0; j <= i; j++) {
			for (k = 0; k < 2; k++) {
				if (k == 0) {
					tmpcrw = crowded1[i][j];
				}
				else {
					tmpcrw = crowded2[i][j];
				}
				if (i == j) {
					equidis2[k][i][j] = 0;//自己到自己距离为0
					equidis4[k][i][j] = 0;
				}
				else {
					if (wdistance[k][i][j] != infi) {
						equidis2[k][i][j] = wdistance[k][i][j] / tmpcrw;//等同距离等于原距离除以拥挤度
						equidis2[k][j][i] = equidis2[k][i][j];
					}
					else {
						equidis2[k][i][j] = infi;
						equidis2[k][j][i] = equidis2[k][i][j];
					}
					if (bdistance[k][i][j] != infi) {
						equidis4[k][i][j] = bdistance[k][i][j] / tmpcrw;//等同距离等于原距离除以拥挤度
						equidis4[k][j][i] = equidis4[k][i][j];
					}
					else {
						equidis4[k][i][j] = infi;
						equidis4[k][j][i] = equidis4[k][i][j];
					}
				}
			}
		}
	}
}
void floyd24() {//使用Floyd算法处理距离矩阵
	int i, j, k;
	for (j = 0; j < 80; j++) {//中间点
		for (i = 0; i < 80; i++) {//起始点
			for (k = 0; k < 80; k++) {//终点
				if (equidis2[0][i][k] > equidis2[0][i][j] + equidis2[0][j][k]) {
					equidis2[0][i][k] = equidis2[0][i][j] + equidis2[0][j][k];
					path2[0][i][k] = path2[0][i][j];
				}
				if (equidis2[1][i][k] > equidis2[1][i][j] + equidis2[1][j][k]) {
					equidis2[1][i][k] = equidis2[1][i][j] + equidis2[1][j][k];
					path2[1][i][k] = path2[1][i][j];
				}
				if (equidis4[0][i][k] > equidis4[0][i][j] + equidis4[0][j][k]) {
					equidis4[0][i][k] = equidis4[0][i][j] + equidis4[0][j][k];
					path4[0][i][k] = path4[0][i][j];
				}
				if (equidis4[1][i][k] > equidis4[1][i][j] + equidis4[1][j][k]) {
					equidis4[1][i][k] = equidis4[1][i][j] + equidis4[1][j][k];
					path4[1][i][k] = path4[1][i][j];
				}
			}
		}
	}
}
