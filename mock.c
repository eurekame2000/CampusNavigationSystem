#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <conio.h>
#include<windows.h>
#include<math.h>
#pragma warning(disable : 4996)

#include"main.h"
#include"print.h"
#include"printWay.h"
#include"writelog.h"
void mock(int type,int sCampus,int eCampus,int start,int end,int path[],int notes[][2]);
void inside_campus(int type,int sCampus,int X,int Y,int time_h,int time_m,int count,int path[],int notes[][2]);//校区内模拟
void cross_campus(int type,int sCampus,int eCampus,int X,int Y,int time_h,int time_m,int count,int path[],int notes[][2]);//校区间模拟 

void stop_inquire(int* hour,int* min,int campus,int x,int y,int locate);//暂停查询 
void Inquire(int campus,int x,int y,int locate);//暂停时查询 
int search(int campus,int x,int y,int note[]);//查询附近设施
 
void move(int *x,int* y,int direction,int way,int flag);//确定当前的X,Y坐标
void time_system(int* hour,int* min,int time);//确定当前系统时间
void print_time(int time_h,int time_m);//打印系统时间




//模拟导航与暂停查询 
void mock(int type,int sCampus,int eCampus,int start,int end,int path[],int notes[][2])
{
	
	int time_h,time_m,time_s,i;//时、分、秒、导航总耗时 
	int X,Y,count;
	char str[100] = { 0 };
	
	//获取当前时间作为系统时间 
	time_t timep;
    struct tm *p;
    time(&timep);
    p=gmtime(&timep); 
    time_h=(p->tm_hour + 8)%24;
	time_m=p->tm_min;
	printf("\n");
	printf("每隔一秒系统时间变化一分钟\n"); 
	printf("人的行走速度是1m/s\n");
	printf("自行车的速度是5m/s\n");
	printf("班车每整点一趟，每趟20分钟\n");
	printf("公交车每半点一趟，每趟30分钟\n\n");
	printf("当前系统时间是： ");
	print_time(time_h,time_m);
	printf("\n");
	printf("模拟导航开始......\n");
	printf("(可按 空格键 进行暂停查询)\n\n");
	strcat(str, "模拟导航开始!");
	writelog(1, 1, str, time_h, time_m);

	//初始化
    if(sCampus==1)
    {
        X=locate1[start][0];
	    Y=locate1[start][1];
	}
	else
	{
		X=locate2[start][0];
	    Y=locate2[start][1];
	}
	for(i=0,count=0;notes[i][0]!=-1;i++)
	    {
	    	count++;
	    	//printf("%d %d\n",notes[i][0],notes[i][1]);
		}
	
	//校区内导航
	if(sCampus==eCampus)
	    inside_campus(type,sCampus,X,Y,time_h,time_m,count,path,notes); 
	else
	    cross_campus(type,sCampus,eCampus,X,Y,time_h,time_m,count,path,notes);
}

//校区内模拟导航
void inside_campus(int type,int sCampus,int X,int Y,int time_h,int time_m,int count,int path[],int notes[][2]) 
{
	int i,j,k,locate,start1,end1;
	int total_time,wait;
	int way,direction,remain,go,sign;
	int total_distance=0;
	float v,v_man,v_bike;
	float time_real,time_sys,time_last;
	char name[20]={'\0'};
	char dname[20]={'\0'};
	char ws[maxs] = { 0 };
	v_man=1;
	v_bike=5;
	
	total_time=0;
	
	j=0;
	locate=path[0];
	Num_to_Name(sCampus,locate,name);
	printf("从%s处开始前进\n",name);
	strcat(ws, "从");
	strcat(ws, name);
	strcat(ws, "开始前进");
	writelog(1, 1, ws, time_h, time_m);
	renew(ws);
	for(i=0;i<count;i++)
	{
		start1=path[j];
		end1=path[j+1];
		way=notes[i][1];//本段路的长度
		direction=notes[i][0];//本段路的方向
		//本段路的速度 
		if(type==2&&sCampus==1)
		    v=v_man*crowded1[start1][end1];
		else if(type==2&&sCampus==2)
		    v=v_man*crowded2[start1][end1];
		else if(type==4&&sCampus==1)
		    v=v_bike*crowded1[start1][end1];
		else if(type==4&&sCampus==2)
		    v=v_bike*crowded2[start1][end1];
		else
		    v=v_man;
		time_sys=way/v;//本段路需要的时间 
		time_real=time_sys/60;//本段路模拟需要的时间
		time_real=((float)((int)((time_real+0.05)*10)))/10;//保留一位小数
		//每秒检查一次是否有按任意键进行查询
		//本段路需要检查的次数  <=  本段路模拟所需要的时间
		//最后一次检查的时间长度为
		time_last=time_real-(int)(time_real/1);
		remain=way;
		for(k=0;k<time_real&&time_real>1;k++)
		{
			//键盘处有输入进行暂停查询 
			if(kbhit())
			{
				//离出发结点更近 
				if(remain>=(way-remain))
                    stop_inquire(&time_h,&time_m,sCampus,X,Y,start1);
                else
                    stop_inquire(&time_h,&time_m,sCampus,X,Y,end1);
			}
			//进行模拟前进 
				go=(int)60*v;//这一分钟内前进的距离
				move(&X,&Y,direction,go,0);//坐标的移动 
				remain=remain-go; //剩余长度 
				time_system(&time_h,&time_m,1);//时间加一分钟 
				total_time++;
				Sleep(1000);//将系统的一分钟反映到现实的1秒上 
		 } 
		 //模拟行走该段路径最后剩余的路径
		 //行走过后到达了一个节点处 
		if(kbhit())
		   {
			if(remain>=(way-remain))
                stop_inquire(&time_h,&time_m,sCampus,X,Y,start1);
            else
                stop_inquire(&time_h,&time_m,sCampus,X,Y,end1);
		  }
        //模拟前进 
			sign=1;
			//坐标的移动到达结点处 
			move(&X,&Y,direction,way,sign);
			remain=0;
			total_distance=total_distance+way;
			//若本段前进所需时间大于30秒则系统时间加一分钟
			if(time_last>0.5) 
			{
				time_system(&time_h,&time_m,1);//时间加一分钟
				total_time++;
		}
			wait = (int)(time_last * 1000);
			locate=end1;
			
			Sleep(wait);
			print_time(time_h,time_m);
			direction_to_Name(direction,dname);
			if(locate<20)
		    {
				char tmpn[20] = { 0 };
				_itoa(way, tmpn, 10);
		    	Num_to_Name(sCampus,locate,name);
		    	printf("向%s前进了%d米  到达了%s\n",dname,way,name);
				strcat(ws, "向");
				strcat(ws, dname);
				strcat(ws, "前进了");
				strcat(ws, tmpn);
				strcat(ws, "到达了");
				strcat(ws, name);
			}
			else {
				char tmpn[20] = { 0 };
				_itoa(way, tmpn, 10);
				printf("向%s前进了%d米\n", dname, way);
				strcat(ws, "向");
				strcat(ws, dname);
				strcat(ws, "前进了");
				strcat(ws, tmpn);
				strcat(ws, "米");
			}
			writelog(1, 1, ws , time_h, time_m);
			renew(ws);
				
	j++;	
	}
	char tmpd[20] = { 0 };
	char tmpt[20] = { 0 };
	_itoa(total_distance, tmpd, 10);
	_itoa(total_time, tmpt, 10);
	printf("模拟导航结束，总路程为%d米，总共用时%d分钟\n",total_distance,total_time);
	strcat(ws, "模拟导航结束，总路程为");
	strcat(ws, tmpd);
	strcat(ws, "米,总共用时");
	strcat(ws, tmpt);
	strcat(ws, "分钟");
	writelog(1, 1, ws,time_h,time_m);
	renew(ws);
}

//校区间进行模拟
void cross_campus(int type,int sCampus,int eCampus,int X,int Y,int time_h,int time_m,int count,int path[],int notes[][2]) 
{
	int i,j,k,locate,start1,end1,campus;
	int total_time,wait;//总时间 
	int way,direction,remain,go,sign;
	int total_distance=0;//总路程 
	float v,v_man,v_bike;
	float time_real,time_sys,time_last;//现实时间，系统时间 
	char name[20]={'\0'};
	char dname[20]={'\0'};
	char ws[maxs] = { 0 };
	v_man=1;
	v_bike=5;
	
	total_time=0;
	
	j=0;
	locate=path[0];
	Num_to_Name(sCampus,locate,name);
	printf("从%s处开始模拟导航\n",name);
	strcat(ws, "从");
	strcat(ws, name);
	strcat(ws, "处开始导航");
	writelog(1, 1, ws, time_h, time_m);
	campus=sCampus;
	for(i=0;i<count;i++)
	{
		start1=path[j];
		//在同一个校区内前进 
        if(path[j+1]!=-2&&path[j+1]!=-3)
		{
			end1=path[j+1];
		    way=notes[i][1];//本段路的长度
    		direction=notes[i][0];//本段路的方向
    		//本段路的速度 
    		if(type==2&&campus==1)
    	   	    v=v_man*crowded1[start1][end1];
	    	else if(type==2&&campus==2)
	    	    v=v_man*crowded2[start1][end1];
	    	else if(type==4&&campus==1)
	    	    v=v_bike*crowded1[start1][end1];
	    	else if(type==4&&campus==2)
	    	    v=v_bike*crowded2[start1][end1];
	    	else
	    	    v=v_man;
	    	time_sys=way/v;//本段路需要的时间 
	    	time_real=time_sys/60;//本段路模拟需要的时间
	    	time_real=((float)((int)((time_real+0.05)*10)))/10;//保留一位小数
	    	//每秒检查一次是否有按任意键进行查询
	    	//本段路需要检查的次数  <=  本段路模拟所需要的时间
	    	//最后一次检查的时间长度为
	    	time_last=time_real-(int)(time_real/1);
	    	remain=way;
	    	for(k=0;k<time_real&&time_real>1;k++)
	    	{
	    		//键盘处有输入进行暂停查询 
	    		if(kbhit())
	    		{
			    	if(remain>=(way-remain))
                        stop_inquire(&time_h,&time_m,campus,X,Y,start1);
                    else
                        stop_inquire(&time_h,&time_m,campus,X,Y,end1);
			    }
	    		//进行模拟前进 
	    			go=(int)60*v;//这一分钟内前进的距离
	    			move(&X,&Y,direction,go,0);//坐标的移动 
	    	 		remain=remain-go; //剩余长度 
	    			time_system(&time_h,&time_m,1);//时间加一分钟 
	    			total_time++;
	    			Sleep(1000);//将系统的一分钟反映到现实的1秒上 
	    	 } 
	    	 //模拟行走该段路径最后剩余的路径
	    	 //行走过后到达了一个节点处 
	    	if(kbhit())
	    	{
				if(remain>=(way-remain))
                    stop_inquire(&time_h,&time_m,campus,X,Y,start1);
                else
                    stop_inquire(&time_h,&time_m,campus,X,Y,end1);
	    	}

	    		sign=1;
	    		//坐标的移动到达结点处 
	    		move(&X,&Y,direction,way,sign);
	    		remain=0;
	    		total_distance=total_distance+way;
	    		//若本段前进所需时间大于30秒则系统时间加一分钟
		    	if(time_last>0.5) 
		    	{
		    		time_system(&time_h,&time_m,1);//时间加一分钟
		    		total_time++;
		        }
	    		wait = (int)(time_last * 1000);
	    		locate=end1;
	    		
    			Sleep(wait);
	    		print_time(time_h,time_m);
		    	direction_to_Name(direction,dname);
			    if(locate<20)
		        {
					char tmpn[20] = { 0 };
					_itoa(way, tmpn, 10);
		        	Num_to_Name(campus,locate,name);
		        	printf("向%s前进了%d米  到达了%s\n",dname,way,name);
					strcat(ws, "向");
					strcat(ws, dname);
					strcat(ws, "前进了");
					strcat(ws, tmpn);
					strcat(ws, "到达了");
					strcat(ws, name);
			    }
				else {
					char tmpn[20] = { 0 };
					_itoa(way, tmpn, 10);
					printf("向%s前进了%d米\n", dname, way);
					strcat(ws, "向");
					strcat(ws, dname);
					strcat(ws, "前进了");
					strcat(ws, tmpn);
					strcat(ws, "米");
				}
				writelog(1, 1, ws, time_h, time_m);
				renew(ws);
	    j++;
		}	
		//到达公交站或班车站
		else
		{
			if(path[j+1]==-2)//到达班车站 
			{
				//等班车
				if(time_m!=0)
				{
					char tmpn[20] = { 0 };
					wait=60-time_m;//等班车的时间
					_itoa(wait, tmpn, 10);
					printf("正在等班车，预计需要等待%d分钟\n",wait);
					strcat(ws, "正在等班车，预计需要等待");
					strcat(ws, tmpn);
					strcat(ws, "分钟");
					writelog(1, 1, ws, time_h, time_m);
					renew(ws);
					for(k=0;k<wait;k++)
					{
						if(kbhit())//暂停查询 
					    {
					    	stop_inquire(&time_h,&time_m,campus,X,Y,start1);
						}

							total_time++;
							time_system(&time_h,&time_m,1);
							Sleep(1000);
						   
					 } 
				 }
				 //坐班车
				 print_time(time_h,time_m);
				 printf("坐上班车，大约需要20分钟到达\n");
				 printf("到达之前不允许暂停查询\n");
				 strcat(ws, "坐上班车，大约需要20分钟到达。");
				 writelog(1, 1, ws, time_h, time_m);
				 renew(ws);
				 total_time=total_time+20;
				 time_system(&time_h,&time_m,20);
				 Sleep(20000);
				 //到达
				 print_time(time_h,time_m);
				 if (eCampus == 1) {
					 printf("到达校区一班车站\n");
					 strcat(ws, "到达校区一班车站");
					 writelog(1, 1, ws, time_h, time_m);
					 renew(ws);
				 }
				 else {
					 printf("到达校区二班车站\n");
					 strcat(ws, "到达校区二班车站");
					 writelog(1, 1, ws, time_h, time_m);
					 renew(ws);
				 }
			}
			if(path[j+1]==-3)//到达公交站 
			{
				//等公交 
				if(time_m!=0&&time_m!=30)
				{
					char tmpn[20] = { 0 };
					wait=30-(time_m%30);//等班车的时间
					_itoa(wait, tmpn, 10);
					printf("正在等公交车，预计需要等待%d分钟\n",wait);
					strcat(ws, "正在等公交车，预计需要等待");
					strcat(ws, tmpn);
					strcat(ws, "分钟");
					writelog(1, 1, ws, time_h, time_m);
					renew(ws);
					for(k=0;k<wait;k++)
					{
						if(kbhit())//暂停查询 
					    {
					    	stop_inquire(&time_h,&time_m,campus,X,Y,start1);
						}

							total_time++;
							time_system(&time_h,&time_m,1);
							Sleep(1000);
						  
					} 
				 }
				 //坐公交 
				 print_time(time_h,time_m);
				 printf("坐上公交车，大约需要30分钟到达\n");
				 printf("到达之前不允许暂停查询\n");
				 strcat(ws, "坐上公交车，大约需要30分钟到达");
				 writelog(1, 1, ws, time_h, time_m);
				 renew(ws);
				 total_time=total_time+30;
				 time_system(&time_h,&time_m,30);
				 Sleep(30000);
				 //到达
				 print_time(time_h,time_m);
				 if (eCampus == 1) {
					 printf("到达校区一公交站\n");
					 strcat(ws, "到达校区一公交站");
					 writelog(1, 1, ws, time_h, time_m);
					 renew(ws);
				 }
				 else {
					 printf("到达校区二公交站\n");
					 strcat(ws, "到达校区二公交站");
					 writelog(1, 1, ws, time_h, time_m);
					 renew(ws);
				 }
			}
			//更新所处位置
			locate=path[j+2];
			if(eCampus==1)
			{
				X=locate1[locate][0];
				Y=locate1[locate][1];
			 } 
			else
			{
				X=locate2[locate][0];
				Y=locate2[locate][1];
			}
			j=j+2;
			campus=eCampus;
		 } 
	}
	char tmpd[20] = { 0 };
	char tmpt[20] = { 0 };
	_itoa(total_distance, tmpd, 10);
	_itoa(total_time, tmpt, 10);
	printf("模拟导航结束，总路程为%d米，总共用时%d分钟\n",total_distance,total_time);
	strcat(ws, "模拟导航结束，总路程为");
	strcat(ws, tmpd);
	strcat(ws, "米，总共用时");
	strcat(ws, tmpt);
	strcat(ws, "分钟");
	writelog(1, 1, ws, time_h, time_m);
	renew(ws);
}

//确定当前的X,Y坐标
void move(int *x,int* y,int direction,int way,int flag)
{
	int w;
	w=(int)way*0.7;
	//处理到达结点的坐标问题 
	if(flag==1&&direction>4)
	{
		while(w%100!=0)
		    w++;
	}
	if(direction==1)//向东前进
        *x=*x+way;
    else if(direction==2)
        *y=*y-way;
    else if(direction==3)
        *x=*x-way;
    else if(direction==4)
        *y=*y+way;
    else if(direction==5)
    {
    	*x=*x+w;
    	*y=*y+w;
	}
    else if(direction==6)
    {
    	*x=*x+w;
    	*y=*y-w;
	}
    else if(direction==7)
    {
    	*x=*x-w;
    	*y=*y-w;
	}
    else
    {
    	*x=*x-w;
    	*y=*y+w;
	}	
} 

//确定当前系统时间
void time_system(int* hour,int* min,int time)
{
	//系统时间变化
	if(((*min)+time)>60)
	{
		*hour=((*hour)+(time/60))%24;
		*min=(*min + (time % 60))%60;
	}
	else if(((*min)+time)==60)
	{
		*hour=(*hour+1)%24;
		*min=0;
	}
	else
	    *min=(*min + time)%60;
 }
 
//暂停查询
void stop_inquire(int* hour,int* min,int campus,int x,int y,int locate)
 {
	time_t timep;
    struct tm *p;
    int time1,time2,time3,time4,time_stop;
	char ws[maxs] = { 0 };
    
	time (&timep);
    p=gmtime(&timep); 
	stph = *hour;
	stpm = *min;
	smh = stph;
	smm = stpm;
    time1=p->tm_min;//暂停时的时间 
    time2=p->tm_sec;
	sh = time1;
	sm = time2;
    printf("\n");
					
	print_time(*hour,*min);
	printf("已停止前进，现在进行暂停查询\n");
	strcat(ws, "已停止前进，现在进行暂停查询");
	writelog(1, 1, ws, smh, smm);
	renew(ws);
	//暂停查询 
	Inquire(campus,x,y,locate); 
		
	time (&timep);
    p=gmtime(&timep); 
    time3=p->tm_min;//结束暂停时的时间                 
    time4=p->tm_sec;                
	//查询所用时间				
	time_stop=(time3*60+time4)-(time1*60+time2);				
    time_system(hour,min,time_stop);
	
	print_time(*hour,*min);
	printf("结束查询，继续前进\n\n"); 
	strcat(ws, "结束查询，继续前进");
	writelog(1, 1, ws, *hour, *min);
	renew(ws);
 } 
 
//暂停时查询
void Inquire(campus,x,y,locate) 
{
	int note[20],count,i,j,sign,distance;
	int map[75][75];
	int path1[75][75];
	int path[75],path2[75];//存最短路径结点 
	char name[20]={'\0'};
	char ws[maxs] = { 0 };
	int pass[2][20]={0};//无用变量 
	int notes[150][2]={0};//无用变量 
	for(i=0;i<75;i++)
	{
		path[i]=-1;//存路径的倒序 
		path2[i]=-1;//存顺序的路径 
	}
	for(i=0;i<20;i++)
	    note[i]=-1;
	
	//在校区一内查询
	if(campus==1)
	{
		//查询当前所处位置
		if(locate<20)//在建筑物附近
		{
			Num_to_Name(campus,locate,name);
			if (x == locate1[locate][0] && y == locate1[locate][1]) {//在建筑物处
				printf("现在正处在校区一的%s\n", name);
				strcat(ws, "现在正处在校区一的");
				strcat(ws, name);
				cvtime(&smh, &smm, sh, sm);
				writelog(1, 1, ws, smh, smm);
				smh = stph;
				smm = stpm;
				renew(ws);
			}
			else {
				printf("现在正处在校区一的%s附近\n", name);
				strcat(ws, "现在正处在校区一的");
				strcat(ws, name);
				strcat(ws, "附近");
				cvtime(&smh, &smm, sh, sm);
				writelog(1, 1, ws, smh, smm);
				smh = stph;
				smm = stpm;
				renew(ws);
			}
		} 
		else {
			printf("现在正处在行进途中\n");
			strcat(ws, "现在正处在行进途中！");
			cvtime(&smh, &smm, sh, sm);
			writelog(1, 1, ws, smh, smm);
			smh = stph;
			smm = stpm;
			renew(ws);
		}
		    
		//查询附近设施
		printf("是否查询附近1000米范围内的设施？\n");
		printf("<1>是   <2>否\n");
		scanf("%d",&sign);
		judge(&sign,1);
		if(sign==1)
		{
			strcat(ws, "选择查询附近1000米范围内的设施");
			cvtime(&smh, &smm, sh, sm);
			writelog(1, 1, ws, smh, smm);
			smh = stph;
			smm = stpm;
			renew(ws);
			//查询附近设施 
			count=search(campus,x,y,note);
			if (count == 0) {
				printf("附近1000米范围内没有相关设施\n");
				strcat(ws, "附近1000米范围内没有相关设施");
				cvtime(&smh, &smm, sh, sm);
				writelog(1, 1, ws, smh, smm);
				smh = stph;
				smm = stpm;
				renew(ws);
			}
			//附近有设施 
			else
			{
				//查最短路径的准备 
				copy(72,campus,map,path1);
				shortPath(72,map,path1);
				//现实附近所有设施信息 
				for(i=0;i<count;i++)
				{
					//若暂停查询时的位置是在道路中间，在查询附近可达的设施时，会近似的将点落在最近的一个节点处
					//在查询最短路径时应该排除掉该点 
					Num_to_Name(campus,note[i],name);
                    if(locate!=note[i])
					{
						char tmpn[20] = { 0 };
			            distance=distance_path(locate,note[i],map,path1);
						_itoa(distance, tmpn, 10);
				    	printf("<%d> %s   距当前位置最短路径长度为：%d 米\n",note[i],name,distance);	
						strcat(ws, name);
						strcat(ws, "距离当前位置最短路径长度为：");
						strcat(ws, tmpn);
						strcat(ws, "米");
						cvtime(&smh, &smm, sh, sm);
						writelog(1, 1, ws, smh, smm);
						smh = stph;
						smm = stpm;
						renew(ws);
					} 
					else {
						printf("<%d> %s   最短路径是直线距离，不可查到该点的最短路径\n", note[i], name);
						strcat(ws, name);
						strcat(ws, "最短路径是直线距离，不可查到该点的最短路径");
						cvtime(&smh, &smm, sh, sm);
						writelog(1, 1, ws, smh, smm);
						smh = stph;
						smm = stpm;
						renew(ws);
					}
				}
				//查询到某一点的最短路径
				printf("是否需要查询到上述设施的最短路径？\n");
				printf("<1>是  <2>否\n");
				scanf("%d",&sign);
				judge(&sign,1);
				if(sign==1)
				{
					char tmps[20] = { 0 };
					strcat(ws, "选择查询到上述设施的最短路径");
					cvtime(&smh, &smm, sh, sm);
					writelog(1, 1, ws, smh, smm);
					smh = stph;
					smm = stpm;
					renew(ws);
					printf("请输入查询目的地的序号\n");
					scanf("%d",&sign);
					_itoa(sign, tmps, 10);
					strcat(ws, "输入了查询目的地的序号，序号为:");
					strcat(ws, tmps);
					cvtime(&smh, &smm, sh, sm);
					writelog(1, 1, ws, smh, smm);
					smh = stph;
					smm = stpm;
					renew(ws);
					short_path(path,locate,sign,path1,0);//寻找最短路径
					j=store_path(path,0,path2);//存储路径
					printWay(1,campus,campus,locate,sign,path2,1,pass,notes); 
				} 
			}
		}
		else {
			strcat(ws, "选择不查询附近1000米范围内的设施");
			cvtime(&smh, &smm, sh, sm);
			writelog(1, 1, ws, smh, smm);
			smh = stph;
			smm = stpm;
			renew(ws);
		}
		 
	} 
	
	//在校区二内查询
	else if(campus==2)
	{
		//查询当前所处位置
		if(locate<20)//在建筑物附近
		{
			Num_to_Name(campus,locate,name);
			if (x == locate2[locate][0] && y == locate2[locate][1]) {//在建筑物处
				printf("现在正处在校区二的%s\n", name);
				strcat(ws, "现在正处在校区二的");
				strcat(ws, name);
				cvtime(&smh, &smm, sh, sm);
				writelog(1, 1, ws, smh, smm);
				smh = stph;
				smm = stpm;
				renew(ws);
			}
			else {
				printf("现在正处在校区二的%s附近\n", name);
				strcat(ws, "现在正处在校区二的");
				strcat(ws, name);
				strcat(ws, "附近");
				cvtime(&smh, &smm, sh, sm);
				writelog(1, 1, ws, smh, smm);
				smh = stph;
				smm = stpm;
				renew(ws);
			}
		} 
		else {
			printf("现在正处在行进途中\n");
			strcat(ws, "现在正处在行进途中！");
			cvtime(&smh, &smm, sh, sm);
			writelog(1, 1, ws, smh, smm);
			smh = stph;
			smm = stpm;
			renew(ws);
		}
		    
		//查询附近设施
		printf("是否查询附近1000米范围内的设施？\n");
		printf("<1>是   <2>否\n");
		scanf("%d",&sign);
		judge(&sign,1);
		if(sign==1)
		{
			strcat(ws, "选择查询附近1000米范围内的设施");
			cvtime(&smh, &smm, sh, sm);
			writelog(1, 1, ws, smh, smm);
			smh = stph;
			smm = stpm;
			renew(ws);
			//查询附近设施 
			count=search(campus,x,y,note);
			if (count == 0) {
				printf("附近1000米范围内没有相关设施\n");
				strcat(ws, "附近1000米范围内没有相关设施");
				cvtime(&smh, &smm, sh, sm);
				writelog(1, 1, ws, smh, smm);
				smh = stph;
				smm = stpm;
				renew(ws);
			}
			//附近有设施 
			else
			{
				//查最短路径的准备 
				copy(70,campus,map,path1);
				shortPath(70,map,path1);
				//现实附近所有设施信息 
				for(i=0;i<count;i++)
				{
					Num_to_Name(campus,note[i],name);
                    if(locate!=note[i])
					{
						char tmpn[20] = { 0 };
			            distance=distance_path(locate,note[i],map,path1);
						_itoa(distance, tmpn, 10);
				    	printf("<%d> %s   距当前位置最短路径长度为：%d 米\n",note[i],name,distance);
						strcat(ws, name);
						strcat(ws, "距离当前位置最短路径长度为：");
						strcat(ws, tmpn);
						strcat(ws, "米");
						cvtime(&smh, &smm, sh, sm);
						writelog(1, 1, ws, smh, smm);
						smh = stph;
						smm = stpm;
						renew(ws);
					} 
					else {
						printf("<%d> %s   最短路径是直线距离，不可查到该点的最短路径\n", note[i], name);
						strcat(ws, name);
						strcat(ws, "最短路径是直线距离，不可查到该点的最短路径");
						cvtime(&smh, &smm, sh, sm);
						writelog(1, 1, ws, smh, smm);
						smh = stph;
						smm = stpm;
						renew(ws);
					}
				}
				//查询到某一点的最短路径
				printf("是否需要查询到上述设施的最短路径？\n");
				printf("<1>是  <2>否\n");
				scanf("%d",&sign);
				judge(&sign,1);
				if(sign==1)
				{
					char tmps[20] = { 0 };
					strcat(ws, "选择查询到上述设施的最短路径");
					cvtime(&smh, &smm, sh, sm);
					writelog(1, 1, ws, smh, smm);
					smh = stph;
					smm = stpm;
					renew(ws);
					printf("请输入查询目的地的序号\n");
					scanf("%d",&sign);
					_itoa(sign, tmps, 10);
					strcat(ws, "输入了查询目的地的序号，序号为:");
					strcat(ws, tmps);
					cvtime(&smh, &smm, sh, sm);
					writelog(1, 1, ws, smh, smm);
					smh = stph;
					smm = stpm;
					renew(ws);
					short_path(path,locate,sign,path1,0);//寻找最短路径
					j=store_path(path,0,path2);//存储路径
					printWay(1,campus,campus,locate,sign,path2,1,pass,notes); 
				} 
			}
		}
		else {
			strcat(ws, "选择不查询附近1000米范围内的设施");
			cvtime(&smh, &smm, sh, sm);
			writelog(1, 1, ws, smh, smm);
			smh = stph;
			smm = stpm;
			renew(ws);
		}
		 
	} 
}

//查询附近设施
int search(int campus,int x,int y,int note[])
{
	int i,j;
	long d;
	int x1,y1;
	//校区一内
	if(campus==1)
	{
		j=0;
		for(i=0;i<20;i++)
		{
			x1=locate1[i][0];
			y1=locate1[i][1];
			d=(x1-x)*(x1-x)+(y1-y)*(y1-y);
			d=(long)sqrt(d);
			if(d>0&&d<1000)
			{
				note[j]=i;
				j++; 
			 } 
		}
	 } 
	//校区二内
	else if(campus==2)
	{
		j=0;
		for(i=0;i<20;i++)
		{
			x1=locate2[i][0];
			y1=locate2[i][1];
			d=(x1-x)*(x1-x)+(y1-y)*(y1-y);
			d=(long)sqrt(d);
			if(d>0&&d<1000)
			{
				note[j]=i;
				j++; 
			 } 
		}
	 } 
	return j;//返回附近设施个数 
 } 

//打印系统时间
void print_time(int time_h,int time_m)
{
	if(time_h<10&&time_m<10)
	    printf("0%d : 0%d  ",time_h,time_m);
	else if(time_h<10&&time_m>=10)
		printf("0%d : %d  ",time_h,time_m);
	else if(time_h>=10&&time_m<10)				
	    printf("%d : 0%d  ",time_h,time_m);
	else
	    printf("%d : %d  ",time_h,time_m);	
 } 
