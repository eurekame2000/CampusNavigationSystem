#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"main.h"
#include"print.h"
#include"writelog.h"
#pragma warning(disable:4996);

//打印导航相关界面
void print1()
{
	printf("\t\t\t\t * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t * *************************************\n");
	printf("\t\t\t\t * *                                 * *\n");
	printf("\t\t\t\t * *         欢迎使用导航系统        * *\n");
	printf("\t\t\t\t * *                                 * *\n");
	printf("\t\t\t\t * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t * *************************************\n");
     	
} 
//显示建筑标号函数
void print(int num,int school) {
	if (num == 1) {//num为1时打印物理位置
        if(school==1)//打印校区1的物理位置 
        {
    	printf("\n");
		printf("\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *\n");
		printf("\t\t\t\t * *                   *物理位置列表*                   * *\n");
		printf("\t\t\t\t * ****************************************************** *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <0>班车站   <1>公交站   <2>大礼堂   <3>2号办公楼  * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <4>1号办公楼  <5>2号宿舍  <6>4号宿舍  <7>1号超市  * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <8>操场   <9>2号食堂   <10>3号宿舍   <11>1号宿舍  * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <12>1号食堂        <13>2号超市        <14>图书馆  * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <15>3号食堂     <16>2号教学楼     <17>四号教学楼  * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <18>1号教学楼                      <19>3号教学楼  * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * ****************************************************** *\n");
		printf("\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *\n");
		printf("\n");    	
		}
		if(school==2)//打印校区2的物理位置 
		{
        printf("\n");
		printf("\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *\n");
		printf("\t\t\t\t * *                   *物理位置列表*                   * *\n");
		printf("\t\t\t\t * ****************************************************** *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <0>公交车站   <1>四食堂   <2>小超市   <3>一宿舍楼 * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <4>四宿舍楼  <5>一食堂     <6>操场     <7>二食堂  * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <8>二宿舍楼   <9>三宿舍楼  <10>体育馆 <11>三食堂  * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <12>一教学楼        <13>三教学楼    <14>一办公楼  * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <15>班车站          <16>图书馆      <17>二教学楼  * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <18>四教学楼                      <19>二办公楼    * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * ****************************************************** *\n");
		printf("\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *\n");
		printf("\n");
		}
	}
	if(num==2){//num为2时打印逻辑位置表
	    if(school==1){//打印校区1的逻辑位置表 
	    printf("\n");
		printf("\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * * * * * *\n");
		printf("\t\t\t\t * *                       *逻辑位置列表*                       * *\n");
		printf("\t\t\t\t * ************************************************************** *\n");
		printf("\t\t\t\t * *  <<0>班车站       <1>公交站     <2.1>歌唱比赛场地          * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <2.2>心理讲座地点  <2.3>党史竞赛场地  <3.1>辅导员办公室   * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <3.2>计院综合办公室    <3.3>计院活动室   <4.1>教务处      * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <4.2>财务处    <4.3学校安全中心>  <5.1>本科生男生宿舍     * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <6.1>研究生女生宿舍    <7.1>水果店     <7.2>眼镜店        * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <7.3>理发店  <8.1>体育课  <8.2>排球比赛  <9>2号食堂       * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <10.1>研究生男生宿舍  <11.1>本科生女生宿舍  <12>1号食堂   * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <13.1>打印店     <13.2>电脑维修      <14.1>图书馆志愿     * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <14.2>自习室        <14.3>朗读亭        <15.1>清真食堂    * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <16.1>数据结构课  <16.2>数据结构课考场  <17.1>口语考场    * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <17.2>英语四六级考场    <18.1>计网教室  <18.2>计组教室    * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <19.1>计组实验室  <19.2>数字电路实验室  <19.3>毛概教室    * *\n");
		printf("\t\t\t\t * ************************************************************** *\n");
		printf("\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * * * * * *\n");
		printf("\n"); 
		} 
		if(school==2){//打印校区2的逻辑位置表
        printf("\n");
		printf("\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *\n");
		printf("\t\t\t\t * *                   *逻辑位置列表*                   * *\n");
		printf("\t\t\t\t * ****************************************************** *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <0>公交车站    <1>四食堂       <2>小超市          * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <3.1>大一男生宿舍楼        <3.2>大一女生宿舍楼    * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <4.1>大四男生宿舍楼        <4.2>大四女生宿舍楼    * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <5>一食堂  <6>操场  <7>二食堂 <8.1>大二男生宿舍楼 * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <8.2>大二女生宿舍楼    <11>三食堂                 * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <9.1>大三男生宿舍楼        <9.2>大三女生宿舍楼    * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <10.1>游泳馆  <10.2>网球场  <12.1>英语课教室      * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <12.2>英语课考场      <13.1>计算机专业课教室      * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <13.2>计算机专业课考场      <14.1>辅导员办公室    * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <14.2>校长办公室           <15>班车站             * *\n"); 
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <16.1>图书借阅处          <16.2>图书阅览室        * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <17.1>实验课教室 <17.2>实验室   <18.1>研讨室      * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <18.2>综合教室   <19.1>教师办公室 <19.2>财务处    * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * ****************************************************** *\n");
		printf("\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *\n");
		printf("\n"); 
		}
	}
	if(num==3){//num为3时打印4种导航策略
	printf("\n");
	printf("***可选导航策略如下***\n");
	printf("<1>最短距离策略\n");
	printf("<2>最短时间策略\n");
	printf("<3>途径最短距离策略\n");
	printf("<4>交通工具最短时间策略\n"); 
	}
} 

//得到导航的起止地点以及导航策略
void getOrder(int* sCampus,int* start,int* eCampus,int* end,int* type,int (*adress)[20])
{
	int num,school1,school2,s,e,t,i,j;
	int d;
	float f;
	char ws[maxs] = { 0 };
	//选择开始校区与地点
	printf("请选择起点校区编号：<1>校区1  <2>校区2\n");
	scanf_s("%d",&school1);
	judge(&school1,1);
	*sCampus=school1;
	strcat(ws, "正在选择起点校区编号，选择结果：校区");
	if ((school1 == 1) || (school1 == 2)) {
		char num[20] = { 0 };
		num[0]= school1 + '0';
		strcat(ws, num);
		writelog(0,1, ws,0,0);
	}
	else {
		writelog(0,0, ws, 0, 0);
	}
	renew(ws);
	printf("请选择起点表示方式，物理位置请选1，逻辑位置请选2\n");
	scanf_s("%d",&num);
	judge(&num,1);
	strcat(ws, "正在选择起点表示方式，选择结果：");
	if ((num == 1) || (num == 2)) {
		if (num == 1) {
			strcat(ws, "物理位置");
			writelog(0,1, ws, 0, 0);
		}
		else{
			strcat(ws, "逻辑位置");
			writelog(0,1, ws, 0, 0);
		}	
	}
	else {
		writelog(0,0, ws, 0, 0);
	}
	renew(ws);
	printf("请在下列地址表中选择起始地点，并输入其对应编号\n");
	print(num,school1);
	scanf_s("%f",&f);
	s=f;
	judge(&s,2);
	*start=s;
	strcat(ws, "正在选择起始地点，选择结果：");
	if (school1 == 1) {
		char tmps[maxs] = { 0 };
		strcat(ws, "校区1的");
		if (f < 20) {
			Num_to_Name(school1, f, tmps);
			strcat(ws, tmps);
			writelog(0, 1, ws, 0, 0);
		}
		else {
			writelog(0, 0, ws, 0, 0);
		}
	}
	else if (school1==2) {
		char tmps[maxs] = { 0 };
		strcat(ws, "校区2的");
		if (f < 20) {
			Num_to_Name(school1, f, tmps);
			strcat(ws, tmps);
			writelog(0, 1, ws, 0, 0);
		}
		else {
			writelog(0, 0, ws, 0, 0);
		}
	}
	else {
		writelog(0,0, ws, 0, 0);
	}
	renew(ws);
	//选择终点校区与地点 
	printf("请选择终点校区编号：<1>校区1  <2>校区2\n");
	scanf_s("%d",&school2);
	judge(&school2,1);
	*eCampus=school2;
	strcat(ws, "正在选择终点校区编号，选择结果：校区");
	if ((school2 == 1) || (school2 == 2)) {
		char num[20] = { 0 };
		num[0]=school2 + '0';
		strcat(ws, num);
		writelog(0,1, ws, 0, 0);
	}
	else {
		writelog(0,0, ws, 0, 0);
	}
	renew(ws);
	printf("请选择终点表示方式，物理位置请选1，逻辑位置请选2\n");
	scanf_s("%d",&num);
	judge(&num,1);
	strcat(ws, "正在选择终点表示方式，选择结果：");
	if ((num == 1) || (num == 2)) {
		if (num == 1) {
			strcat(ws, "物理位置");
			writelog(0,1, ws, 0, 0);
		}
		else {
			strcat(ws, "逻辑位置");
			writelog(0,1, ws, 0, 0);
		}
	}
	else {
		writelog(0,0, ws, 0, 0);
	}
	renew(ws);
	printf("请在下列地址表中选择终点地点，并输入其对应编号\n");
	print(num,school2);
	scanf_s("%f",&f);
	e=f;
	judge(&e,2);
	*end=e;
	strcat(ws, "正在选择终点地点，选择结果：");
	if (school2 == 1) {
		char tmps[maxs] = { 0 };
		strcat(ws, "校区1的");
		Num_to_Name(school2, f, tmps);
		strcat(ws, tmps);
		writelog(0,1, ws, 0, 0);
	}
	else if (school2==2) {
		char tmps[maxs] = { 0 };
		strcat(ws, "校区2的");
		Num_to_Name(school2, f, tmps);
		strcat(ws, tmps);
		writelog(0,1, ws, 0, 0);
	}
	else {
		writelog(0,0, ws, 0, 0);
	}
	renew(ws);
	//选择导航策略
	printf("请选择导航策略，并输入其对应编号\n");
	print(3,0);
	scanf_s("%d",&t);
	judge(&t,3);
	*type=t;
	strcat(ws, "正在选择导航策略，选择结果：");
	if ((t >= 1) && (t <= 4)) {
		if (t == 1) {
			strcat(ws,"导航策略1--最短距离策略");
		}
		else if (t == 2) {
			strcat(ws,"导航策略2--最短时间策略");
		}
		else if (t == 3) {
			strcat(ws,"导航策略3--途径最短距离策略");
		}
		else {
			strcat(ws, "导航策略4--交通工具的最短时间策略");
		}
		writelog(0,1, ws, 0, 0);
	}
	else {
		writelog(0,0, ws, 0, 0);
	}
	renew(ws);
	if(t==3)//存储途经地点的标号 
	{
		if(school1==school2)//同一校区内默认途径地点存在第一行 
		{
			j=0;
			system("cls");
			printf("请选择途经地点表示方式，物理位置请选1，逻辑位置请选2\n");
	        scanf_s("%d",&num);
	        judge(&num,1);
			print(num, school1);
			strcat(ws, "正在选择");
			if (school1 == 1) {
				strcat(ws, "校区1途径地点表示方式，选择结果：");
			}
			else if(school1==2){
				strcat(ws, "校区2途径地点表示方式，选择结果：");
			}
			/*else {
				writelog(0, ws);
			}*/
			if (num == 1) {
				strcat(ws, "物理位置");
				writelog(0,1, ws, 0, 0);
			}
			else if (num == 2) {
				strcat(ws, "逻辑位置");
				writelog(0,1, ws, 0, 0);
			}
			else {
				writelog(0,0, ws, 0, 0);
			}
			renew(ws);
			printf("请依次输入途径地点的编号，输入以-1结束\n");
			scanf_s("%d",&d);
			judge(&d,4);
			while(d!=-1)
			{
				strcat(ws, "正在选择");
				if (school1 == 1) {
					strcat(ws, "校区1途径地点，选择结果：");
				}
				else if (school1 == 2) {
					strcat(ws, "校区2途径地点，选择结果：");
				}
				if ((d >= 0) && (d <= 19)) {
					char tmps[maxs] = { 0 };
					Num_to_Name(school1, d, tmps);
					strcat(ws, tmps);
					writelog(0,1, ws, 0, 0);
				}
				else {
					writelog(0,0, ws, 0, 0);
				}
				renew(ws);
				*(*(adress+0)+j)=d;
				j++;
				scanf_s("%d",&d);
				judge(&d,4);
			}
			*(*(adress+0)+j)=d;
		}
		else//不同校区时，将起始校区途径的地点放在第一行，终止校区内途径的地点放在第二行 
		{
			j=0;
			system("cls");
			printf("请选择校区%d中途经地点表示方式，物理位置请选1，逻辑位置请选2\n",school1);
	        scanf_s("%d",&num);
	        judge(&num,1);
			print(num, school1);
			if (school1 == 1) {
				strcat(ws, "正在选择校区1中途途径地点表示方式，选择结果：");
			}
			else if (school1 == 2) {
				strcat(ws, "正在选择校区2中途途径地点表示方式，选择结果：");
			}
			if (num == 1) {
				strcat(ws, "物理位置");
				writelog(0,1, ws , 0, 0);
			}
			else if (num == 2) {
				strcat(ws, "逻辑位置");
				writelog(0,1, ws, 0, 0);
			}
			else {
				writelog(0,0, ws, 0, 0);
			}
			renew(ws);
			printf("请依次输入途径地点的编号，输入以-1结束\n");
			scanf_s("%d",&d);
			judge(&d,4);
			while(d!=-1)
			{
				strcat(ws, "正在选择");
				if (school1 == 1) {
					strcat(ws, "校区1途径地点，选择结果：");
				}
				else if (school1 == 2) {
					strcat(ws, "校区2途径地点，选择结果：");
				}
				if ((d >= 0) && (d <= 19)) {
					char tmps[maxs] = { 0 };
					Num_to_Name(school1, d, tmps);
					strcat(ws, tmps);
					writelog(0,1, ws, 0, 0);
				}
				else {
					writelog(0,0, ws, 0, 0);
				}
				renew(ws);
				*(*(adress+0)+j)=d;
				j++;
				scanf_s("%d",&d);
				judge(&d,4);
			}
			*(*(adress+0)+j)=d;
			j=0;
			system("cls");
			printf("请选择校区%d中途经地点表示方式，物理位置请选1，逻辑位置请选2\n",school2);
	        scanf_s("%d",&num);
	        judge(&num,1);
			print(num, school2);
			strcat(ws, "正在选择校区");
			if ((school2 == 1) || (school2 == 2)) {
				if (school2 == 1) {
					strcat(ws, "1中途途径地点表示方式，选择结果：");
				}
				else if (school2 == 2) {
					strcat(ws, "2中途途径地点表示方式，选择结果：");
				}
				if (num == 1) {
					strcat(ws, "物理位置");
					writelog(0,1, ws, 0, 0);
				}
				else if (num == 2) {
					strcat(ws, "逻辑位置");
					writelog(0,1, ws, 0, 0);
				}
			}
			else {
				writelog(0,0, ws, 0, 0);
			}
			renew(ws);
			printf("请依次输入途径地点的编号，输入以-1结束\n");
			scanf_s("%d",&d);
			judge(&d,4);
			while(d!=-1)
			{
				strcat(ws, "正在选择");
				if (school2 == 1) {
					strcat(ws, "校区1途径地点，选择结果：");
				}
				else if (school2 == 2) {
					strcat(ws, "校区2途径地点，选择结果：");
				}
				if ((d >= 0) && (d <= 19)) {
					char tmps[maxs] = { 0 };
					Num_to_Name(school2, d, tmps);
					strcat(ws, tmps);
					writelog(0,1, ws, 0, 0);
				}
				else {
					writelog(0,0, ws, 0, 0);
				}
				renew(ws);
				*(*(adress+1)+j)=d;
				j++;
				scanf_s("%d",&d);
				judge(&d,4);
			}
			*(*(adress+1)+j)=d;
		}
	}
	 
 } 
void Num_to_Name(int school,int number,char* name)
{
	if(school==1)
	{   if(number==0) strcpy(name,"班车站");
		if(number==1) strcpy(name,"公交站");
		if(number==2) strcpy(name,"大礼堂");
		if(number==3) strcpy(name,"2号办公楼");
		if(number==4) strcpy(name,"1号办公楼");
		if(number==5) strcpy(name,"2号宿舍");
		if(number==6) strcpy(name,"4号宿舍");
		if(number==7) strcpy(name,"1号超市");
		if(number==8) strcpy(name,"操场");
		if(number==9) strcpy(name,"2号食堂");
		if(number==10) strcpy(name,"3号宿舍");
		if(number==11) strcpy(name,"1号宿舍");
		if(number==12) strcpy(name,"1号食堂");
		if(number==13) strcpy(name,"2号超市");
		if(number==14) strcpy(name,"图书馆");
		if(number==15) strcpy(name,"3号食堂");
		if(number==16) strcpy(name,"2号教学楼");
		if(number==17) strcpy(name,"四号教学楼");
		if(number==18) strcpy(name,"1号教学楼");
		if(number==19) strcpy(name,"3号教学楼");
	}
	else if(school==2)
	{
		if(number==0) strcpy(name,"公交车站");
		if(number==1) strcpy(name,"四食堂");
		if(number==2) strcpy(name,"小超市");
		if(number==3) strcpy(name,"一宿舍楼");
		if(number==4) strcpy(name,"四宿舍楼");
		if(number==5) strcpy(name,"一食堂");
		if(number==6) strcpy(name,"操场");
		if(number==7) strcpy(name,"二食堂");
		if(number==8) strcpy(name,"二宿舍楼");
		if(number==9) strcpy(name,"三宿舍楼");
		if(number==10) strcpy(name,"体育馆");
		if(number==11) strcpy(name,"三食堂");
		if(number==12) strcpy(name,"一教学楼 ");
		if(number==13) strcpy(name,"三教学楼");
		if(number==14) strcpy(name,"一办公楼");
		if(number==15) strcpy(name,"班车站");
		if(number==16) strcpy(name,"图书馆");
		if(number==17) strcpy(name,"二教学楼");
		if(number==18) strcpy(name,"四教学楼");
		if(number==19) strcpy(name,"二办公楼");
	} 
	else
	printf("不存在此校区"); 
}

//将方向输出为文字
void direction_to_Name(int number,char* name) 
{
	if(number==1) strcpy(name,"东");
	else if(number==2) strcpy(name,"南");
	else if(number==3) strcpy(name,"西");
	else if(number==4) strcpy(name,"北");
	else if(number==5) strcpy(name,"东北");
	else if(number==6) strcpy(name,"东南");
	else if(number==7) strcpy(name,"西南");
	else strcpy(name,"西北");
	
}
