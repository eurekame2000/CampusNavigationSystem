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
void inside_campus(int type,int sCampus,int X,int Y,int time_h,int time_m,int count,int path[],int notes[][2]);//У����ģ��
void cross_campus(int type,int sCampus,int eCampus,int X,int Y,int time_h,int time_m,int count,int path[],int notes[][2]);//У����ģ�� 

void stop_inquire(int* hour,int* min,int campus,int x,int y,int locate);//��ͣ��ѯ 
void Inquire(int campus,int x,int y,int locate);//��ͣʱ��ѯ 
int search(int campus,int x,int y,int note[]);//��ѯ������ʩ
 
void move(int *x,int* y,int direction,int way,int flag);//ȷ����ǰ��X,Y����
void time_system(int* hour,int* min,int time);//ȷ����ǰϵͳʱ��
void print_time(int time_h,int time_m);//��ӡϵͳʱ��




//ģ�⵼������ͣ��ѯ 
void mock(int type,int sCampus,int eCampus,int start,int end,int path[],int notes[][2])
{
	
	int time_h,time_m,time_s,i;//ʱ���֡��롢�����ܺ�ʱ 
	int X,Y,count;
	char str[100] = { 0 };
	
	//��ȡ��ǰʱ����Ϊϵͳʱ�� 
	time_t timep;
    struct tm *p;
    time(&timep);
    p=gmtime(&timep); 
    time_h=(p->tm_hour + 8)%24;
	time_m=p->tm_min;
	printf("\n");
	printf("ÿ��һ��ϵͳʱ��仯һ����\n"); 
	printf("�˵������ٶ���1m/s\n");
	printf("���г����ٶ���5m/s\n");
	printf("�೵ÿ����һ�ˣ�ÿ��20����\n");
	printf("������ÿ���һ�ˣ�ÿ��30����\n\n");
	printf("��ǰϵͳʱ���ǣ� ");
	print_time(time_h,time_m);
	printf("\n");
	printf("ģ�⵼����ʼ......\n");
	printf("(�ɰ� �ո�� ������ͣ��ѯ)\n\n");
	strcat(str, "ģ�⵼����ʼ!");
	writelog(1, 1, str, time_h, time_m);

	//��ʼ��
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
	
	//У���ڵ���
	if(sCampus==eCampus)
	    inside_campus(type,sCampus,X,Y,time_h,time_m,count,path,notes); 
	else
	    cross_campus(type,sCampus,eCampus,X,Y,time_h,time_m,count,path,notes);
}

//У����ģ�⵼��
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
	printf("��%s����ʼǰ��\n",name);
	strcat(ws, "��");
	strcat(ws, name);
	strcat(ws, "��ʼǰ��");
	writelog(1, 1, ws, time_h, time_m);
	renew(ws);
	for(i=0;i<count;i++)
	{
		start1=path[j];
		end1=path[j+1];
		way=notes[i][1];//����·�ĳ���
		direction=notes[i][0];//����·�ķ���
		//����·���ٶ� 
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
		time_sys=way/v;//����·��Ҫ��ʱ�� 
		time_real=time_sys/60;//����·ģ����Ҫ��ʱ��
		time_real=((float)((int)((time_real+0.05)*10)))/10;//����һλС��
		//ÿ����һ���Ƿ��а���������в�ѯ
		//����·��Ҫ���Ĵ���  <=  ����·ģ������Ҫ��ʱ��
		//���һ�μ���ʱ�䳤��Ϊ
		time_last=time_real-(int)(time_real/1);
		remain=way;
		for(k=0;k<time_real&&time_real>1;k++)
		{
			//���̴������������ͣ��ѯ 
			if(kbhit())
			{
				//����������� 
				if(remain>=(way-remain))
                    stop_inquire(&time_h,&time_m,sCampus,X,Y,start1);
                else
                    stop_inquire(&time_h,&time_m,sCampus,X,Y,end1);
			}
			//����ģ��ǰ�� 
				go=(int)60*v;//��һ������ǰ���ľ���
				move(&X,&Y,direction,go,0);//������ƶ� 
				remain=remain-go; //ʣ�೤�� 
				time_system(&time_h,&time_m,1);//ʱ���һ���� 
				total_time++;
				Sleep(1000);//��ϵͳ��һ���ӷ�ӳ����ʵ��1���� 
		 } 
		 //ģ�����߸ö�·�����ʣ���·��
		 //���߹��󵽴���һ���ڵ㴦 
		if(kbhit())
		   {
			if(remain>=(way-remain))
                stop_inquire(&time_h,&time_m,sCampus,X,Y,start1);
            else
                stop_inquire(&time_h,&time_m,sCampus,X,Y,end1);
		  }
        //ģ��ǰ�� 
			sign=1;
			//������ƶ������㴦 
			move(&X,&Y,direction,way,sign);
			remain=0;
			total_distance=total_distance+way;
			//������ǰ������ʱ�����30����ϵͳʱ���һ����
			if(time_last>0.5) 
			{
				time_system(&time_h,&time_m,1);//ʱ���һ����
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
		    	printf("��%sǰ����%d��  ������%s\n",dname,way,name);
				strcat(ws, "��");
				strcat(ws, dname);
				strcat(ws, "ǰ����");
				strcat(ws, tmpn);
				strcat(ws, "������");
				strcat(ws, name);
			}
			else {
				char tmpn[20] = { 0 };
				_itoa(way, tmpn, 10);
				printf("��%sǰ����%d��\n", dname, way);
				strcat(ws, "��");
				strcat(ws, dname);
				strcat(ws, "ǰ����");
				strcat(ws, tmpn);
				strcat(ws, "��");
			}
			writelog(1, 1, ws , time_h, time_m);
			renew(ws);
				
	j++;	
	}
	char tmpd[20] = { 0 };
	char tmpt[20] = { 0 };
	_itoa(total_distance, tmpd, 10);
	_itoa(total_time, tmpt, 10);
	printf("ģ�⵼����������·��Ϊ%d�ף��ܹ���ʱ%d����\n",total_distance,total_time);
	strcat(ws, "ģ�⵼����������·��Ϊ");
	strcat(ws, tmpd);
	strcat(ws, "��,�ܹ���ʱ");
	strcat(ws, tmpt);
	strcat(ws, "����");
	writelog(1, 1, ws,time_h,time_m);
	renew(ws);
}

//У�������ģ��
void cross_campus(int type,int sCampus,int eCampus,int X,int Y,int time_h,int time_m,int count,int path[],int notes[][2]) 
{
	int i,j,k,locate,start1,end1,campus;
	int total_time,wait;//��ʱ�� 
	int way,direction,remain,go,sign;
	int total_distance=0;//��·�� 
	float v,v_man,v_bike;
	float time_real,time_sys,time_last;//��ʵʱ�䣬ϵͳʱ�� 
	char name[20]={'\0'};
	char dname[20]={'\0'};
	char ws[maxs] = { 0 };
	v_man=1;
	v_bike=5;
	
	total_time=0;
	
	j=0;
	locate=path[0];
	Num_to_Name(sCampus,locate,name);
	printf("��%s����ʼģ�⵼��\n",name);
	strcat(ws, "��");
	strcat(ws, name);
	strcat(ws, "����ʼ����");
	writelog(1, 1, ws, time_h, time_m);
	campus=sCampus;
	for(i=0;i<count;i++)
	{
		start1=path[j];
		//��ͬһ��У����ǰ�� 
        if(path[j+1]!=-2&&path[j+1]!=-3)
		{
			end1=path[j+1];
		    way=notes[i][1];//����·�ĳ���
    		direction=notes[i][0];//����·�ķ���
    		//����·���ٶ� 
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
	    	time_sys=way/v;//����·��Ҫ��ʱ�� 
	    	time_real=time_sys/60;//����·ģ����Ҫ��ʱ��
	    	time_real=((float)((int)((time_real+0.05)*10)))/10;//����һλС��
	    	//ÿ����һ���Ƿ��а���������в�ѯ
	    	//����·��Ҫ���Ĵ���  <=  ����·ģ������Ҫ��ʱ��
	    	//���һ�μ���ʱ�䳤��Ϊ
	    	time_last=time_real-(int)(time_real/1);
	    	remain=way;
	    	for(k=0;k<time_real&&time_real>1;k++)
	    	{
	    		//���̴������������ͣ��ѯ 
	    		if(kbhit())
	    		{
			    	if(remain>=(way-remain))
                        stop_inquire(&time_h,&time_m,campus,X,Y,start1);
                    else
                        stop_inquire(&time_h,&time_m,campus,X,Y,end1);
			    }
	    		//����ģ��ǰ�� 
	    			go=(int)60*v;//��һ������ǰ���ľ���
	    			move(&X,&Y,direction,go,0);//������ƶ� 
	    	 		remain=remain-go; //ʣ�೤�� 
	    			time_system(&time_h,&time_m,1);//ʱ���һ���� 
	    			total_time++;
	    			Sleep(1000);//��ϵͳ��һ���ӷ�ӳ����ʵ��1���� 
	    	 } 
	    	 //ģ�����߸ö�·�����ʣ���·��
	    	 //���߹��󵽴���һ���ڵ㴦 
	    	if(kbhit())
	    	{
				if(remain>=(way-remain))
                    stop_inquire(&time_h,&time_m,campus,X,Y,start1);
                else
                    stop_inquire(&time_h,&time_m,campus,X,Y,end1);
	    	}

	    		sign=1;
	    		//������ƶ������㴦 
	    		move(&X,&Y,direction,way,sign);
	    		remain=0;
	    		total_distance=total_distance+way;
	    		//������ǰ������ʱ�����30����ϵͳʱ���һ����
		    	if(time_last>0.5) 
		    	{
		    		time_system(&time_h,&time_m,1);//ʱ���һ����
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
		        	printf("��%sǰ����%d��  ������%s\n",dname,way,name);
					strcat(ws, "��");
					strcat(ws, dname);
					strcat(ws, "ǰ����");
					strcat(ws, tmpn);
					strcat(ws, "������");
					strcat(ws, name);
			    }
				else {
					char tmpn[20] = { 0 };
					_itoa(way, tmpn, 10);
					printf("��%sǰ����%d��\n", dname, way);
					strcat(ws, "��");
					strcat(ws, dname);
					strcat(ws, "ǰ����");
					strcat(ws, tmpn);
					strcat(ws, "��");
				}
				writelog(1, 1, ws, time_h, time_m);
				renew(ws);
	    j++;
		}	
		//���﹫��վ��೵վ
		else
		{
			if(path[j+1]==-2)//����೵վ 
			{
				//�Ȱ೵
				if(time_m!=0)
				{
					char tmpn[20] = { 0 };
					wait=60-time_m;//�Ȱ೵��ʱ��
					_itoa(wait, tmpn, 10);
					printf("���ڵȰ೵��Ԥ����Ҫ�ȴ�%d����\n",wait);
					strcat(ws, "���ڵȰ೵��Ԥ����Ҫ�ȴ�");
					strcat(ws, tmpn);
					strcat(ws, "����");
					writelog(1, 1, ws, time_h, time_m);
					renew(ws);
					for(k=0;k<wait;k++)
					{
						if(kbhit())//��ͣ��ѯ 
					    {
					    	stop_inquire(&time_h,&time_m,campus,X,Y,start1);
						}

							total_time++;
							time_system(&time_h,&time_m,1);
							Sleep(1000);
						   
					 } 
				 }
				 //���೵
				 print_time(time_h,time_m);
				 printf("���ϰ೵����Լ��Ҫ20���ӵ���\n");
				 printf("����֮ǰ��������ͣ��ѯ\n");
				 strcat(ws, "���ϰ೵����Լ��Ҫ20���ӵ��");
				 writelog(1, 1, ws, time_h, time_m);
				 renew(ws);
				 total_time=total_time+20;
				 time_system(&time_h,&time_m,20);
				 Sleep(20000);
				 //����
				 print_time(time_h,time_m);
				 if (eCampus == 1) {
					 printf("����У��һ�೵վ\n");
					 strcat(ws, "����У��һ�೵վ");
					 writelog(1, 1, ws, time_h, time_m);
					 renew(ws);
				 }
				 else {
					 printf("����У�����೵վ\n");
					 strcat(ws, "����У�����೵վ");
					 writelog(1, 1, ws, time_h, time_m);
					 renew(ws);
				 }
			}
			if(path[j+1]==-3)//���﹫��վ 
			{
				//�ȹ��� 
				if(time_m!=0&&time_m!=30)
				{
					char tmpn[20] = { 0 };
					wait=30-(time_m%30);//�Ȱ೵��ʱ��
					_itoa(wait, tmpn, 10);
					printf("���ڵȹ�������Ԥ����Ҫ�ȴ�%d����\n",wait);
					strcat(ws, "���ڵȹ�������Ԥ����Ҫ�ȴ�");
					strcat(ws, tmpn);
					strcat(ws, "����");
					writelog(1, 1, ws, time_h, time_m);
					renew(ws);
					for(k=0;k<wait;k++)
					{
						if(kbhit())//��ͣ��ѯ 
					    {
					    	stop_inquire(&time_h,&time_m,campus,X,Y,start1);
						}

							total_time++;
							time_system(&time_h,&time_m,1);
							Sleep(1000);
						  
					} 
				 }
				 //������ 
				 print_time(time_h,time_m);
				 printf("���Ϲ���������Լ��Ҫ30���ӵ���\n");
				 printf("����֮ǰ��������ͣ��ѯ\n");
				 strcat(ws, "���Ϲ���������Լ��Ҫ30���ӵ���");
				 writelog(1, 1, ws, time_h, time_m);
				 renew(ws);
				 total_time=total_time+30;
				 time_system(&time_h,&time_m,30);
				 Sleep(30000);
				 //����
				 print_time(time_h,time_m);
				 if (eCampus == 1) {
					 printf("����У��һ����վ\n");
					 strcat(ws, "����У��һ����վ");
					 writelog(1, 1, ws, time_h, time_m);
					 renew(ws);
				 }
				 else {
					 printf("����У��������վ\n");
					 strcat(ws, "����У��������վ");
					 writelog(1, 1, ws, time_h, time_m);
					 renew(ws);
				 }
			}
			//��������λ��
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
	printf("ģ�⵼����������·��Ϊ%d�ף��ܹ���ʱ%d����\n",total_distance,total_time);
	strcat(ws, "ģ�⵼����������·��Ϊ");
	strcat(ws, tmpd);
	strcat(ws, "�ף��ܹ���ʱ");
	strcat(ws, tmpt);
	strcat(ws, "����");
	writelog(1, 1, ws, time_h, time_m);
	renew(ws);
}

//ȷ����ǰ��X,Y����
void move(int *x,int* y,int direction,int way,int flag)
{
	int w;
	w=(int)way*0.7;
	//����������������� 
	if(flag==1&&direction>4)
	{
		while(w%100!=0)
		    w++;
	}
	if(direction==1)//��ǰ��
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

//ȷ����ǰϵͳʱ��
void time_system(int* hour,int* min,int time)
{
	//ϵͳʱ��仯
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
 
//��ͣ��ѯ
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
    time1=p->tm_min;//��ͣʱ��ʱ�� 
    time2=p->tm_sec;
	sh = time1;
	sm = time2;
    printf("\n");
					
	print_time(*hour,*min);
	printf("��ֹͣǰ�������ڽ�����ͣ��ѯ\n");
	strcat(ws, "��ֹͣǰ�������ڽ�����ͣ��ѯ");
	writelog(1, 1, ws, smh, smm);
	renew(ws);
	//��ͣ��ѯ 
	Inquire(campus,x,y,locate); 
		
	time (&timep);
    p=gmtime(&timep); 
    time3=p->tm_min;//������ͣʱ��ʱ��                 
    time4=p->tm_sec;                
	//��ѯ����ʱ��				
	time_stop=(time3*60+time4)-(time1*60+time2);				
    time_system(hour,min,time_stop);
	
	print_time(*hour,*min);
	printf("������ѯ������ǰ��\n\n"); 
	strcat(ws, "������ѯ������ǰ��");
	writelog(1, 1, ws, *hour, *min);
	renew(ws);
 } 
 
//��ͣʱ��ѯ
void Inquire(campus,x,y,locate) 
{
	int note[20],count,i,j,sign,distance;
	int map[75][75];
	int path1[75][75];
	int path[75],path2[75];//�����·����� 
	char name[20]={'\0'};
	char ws[maxs] = { 0 };
	int pass[2][20]={0};//���ñ��� 
	int notes[150][2]={0};//���ñ��� 
	for(i=0;i<75;i++)
	{
		path[i]=-1;//��·���ĵ��� 
		path2[i]=-1;//��˳���·�� 
	}
	for(i=0;i<20;i++)
	    note[i]=-1;
	
	//��У��һ�ڲ�ѯ
	if(campus==1)
	{
		//��ѯ��ǰ����λ��
		if(locate<20)//�ڽ����︽��
		{
			Num_to_Name(campus,locate,name);
			if (x == locate1[locate][0] && y == locate1[locate][1]) {//�ڽ����ﴦ
				printf("����������У��һ��%s\n", name);
				strcat(ws, "����������У��һ��");
				strcat(ws, name);
				cvtime(&smh, &smm, sh, sm);
				writelog(1, 1, ws, smh, smm);
				smh = stph;
				smm = stpm;
				renew(ws);
			}
			else {
				printf("����������У��һ��%s����\n", name);
				strcat(ws, "����������У��һ��");
				strcat(ws, name);
				strcat(ws, "����");
				cvtime(&smh, &smm, sh, sm);
				writelog(1, 1, ws, smh, smm);
				smh = stph;
				smm = stpm;
				renew(ws);
			}
		} 
		else {
			printf("�����������н�;��\n");
			strcat(ws, "�����������н�;�У�");
			cvtime(&smh, &smm, sh, sm);
			writelog(1, 1, ws, smh, smm);
			smh = stph;
			smm = stpm;
			renew(ws);
		}
		    
		//��ѯ������ʩ
		printf("�Ƿ��ѯ����1000�׷�Χ�ڵ���ʩ��\n");
		printf("<1>��   <2>��\n");
		scanf("%d",&sign);
		judge(&sign,1);
		if(sign==1)
		{
			strcat(ws, "ѡ���ѯ����1000�׷�Χ�ڵ���ʩ");
			cvtime(&smh, &smm, sh, sm);
			writelog(1, 1, ws, smh, smm);
			smh = stph;
			smm = stpm;
			renew(ws);
			//��ѯ������ʩ 
			count=search(campus,x,y,note);
			if (count == 0) {
				printf("����1000�׷�Χ��û�������ʩ\n");
				strcat(ws, "����1000�׷�Χ��û�������ʩ");
				cvtime(&smh, &smm, sh, sm);
				writelog(1, 1, ws, smh, smm);
				smh = stph;
				smm = stpm;
				renew(ws);
			}
			//��������ʩ 
			else
			{
				//�����·����׼�� 
				copy(72,campus,map,path1);
				shortPath(72,map,path1);
				//��ʵ����������ʩ��Ϣ 
				for(i=0;i<count;i++)
				{
					//����ͣ��ѯʱ��λ�����ڵ�·�м䣬�ڲ�ѯ�����ɴ����ʩʱ������ƵĽ������������һ���ڵ㴦
					//�ڲ�ѯ���·��ʱӦ���ų����õ� 
					Num_to_Name(campus,note[i],name);
                    if(locate!=note[i])
					{
						char tmpn[20] = { 0 };
			            distance=distance_path(locate,note[i],map,path1);
						_itoa(distance, tmpn, 10);
				    	printf("<%d> %s   �൱ǰλ�����·������Ϊ��%d ��\n",note[i],name,distance);	
						strcat(ws, name);
						strcat(ws, "���뵱ǰλ�����·������Ϊ��");
						strcat(ws, tmpn);
						strcat(ws, "��");
						cvtime(&smh, &smm, sh, sm);
						writelog(1, 1, ws, smh, smm);
						smh = stph;
						smm = stpm;
						renew(ws);
					} 
					else {
						printf("<%d> %s   ���·����ֱ�߾��룬���ɲ鵽�õ�����·��\n", note[i], name);
						strcat(ws, name);
						strcat(ws, "���·����ֱ�߾��룬���ɲ鵽�õ�����·��");
						cvtime(&smh, &smm, sh, sm);
						writelog(1, 1, ws, smh, smm);
						smh = stph;
						smm = stpm;
						renew(ws);
					}
				}
				//��ѯ��ĳһ������·��
				printf("�Ƿ���Ҫ��ѯ��������ʩ�����·����\n");
				printf("<1>��  <2>��\n");
				scanf("%d",&sign);
				judge(&sign,1);
				if(sign==1)
				{
					char tmps[20] = { 0 };
					strcat(ws, "ѡ���ѯ��������ʩ�����·��");
					cvtime(&smh, &smm, sh, sm);
					writelog(1, 1, ws, smh, smm);
					smh = stph;
					smm = stpm;
					renew(ws);
					printf("�������ѯĿ�ĵص����\n");
					scanf("%d",&sign);
					_itoa(sign, tmps, 10);
					strcat(ws, "�����˲�ѯĿ�ĵص���ţ����Ϊ:");
					strcat(ws, tmps);
					cvtime(&smh, &smm, sh, sm);
					writelog(1, 1, ws, smh, smm);
					smh = stph;
					smm = stpm;
					renew(ws);
					short_path(path,locate,sign,path1,0);//Ѱ�����·��
					j=store_path(path,0,path2);//�洢·��
					printWay(1,campus,campus,locate,sign,path2,1,pass,notes); 
				} 
			}
		}
		else {
			strcat(ws, "ѡ�񲻲�ѯ����1000�׷�Χ�ڵ���ʩ");
			cvtime(&smh, &smm, sh, sm);
			writelog(1, 1, ws, smh, smm);
			smh = stph;
			smm = stpm;
			renew(ws);
		}
		 
	} 
	
	//��У�����ڲ�ѯ
	else if(campus==2)
	{
		//��ѯ��ǰ����λ��
		if(locate<20)//�ڽ����︽��
		{
			Num_to_Name(campus,locate,name);
			if (x == locate2[locate][0] && y == locate2[locate][1]) {//�ڽ����ﴦ
				printf("����������У������%s\n", name);
				strcat(ws, "����������У������");
				strcat(ws, name);
				cvtime(&smh, &smm, sh, sm);
				writelog(1, 1, ws, smh, smm);
				smh = stph;
				smm = stpm;
				renew(ws);
			}
			else {
				printf("����������У������%s����\n", name);
				strcat(ws, "����������У������");
				strcat(ws, name);
				strcat(ws, "����");
				cvtime(&smh, &smm, sh, sm);
				writelog(1, 1, ws, smh, smm);
				smh = stph;
				smm = stpm;
				renew(ws);
			}
		} 
		else {
			printf("�����������н�;��\n");
			strcat(ws, "�����������н�;�У�");
			cvtime(&smh, &smm, sh, sm);
			writelog(1, 1, ws, smh, smm);
			smh = stph;
			smm = stpm;
			renew(ws);
		}
		    
		//��ѯ������ʩ
		printf("�Ƿ��ѯ����1000�׷�Χ�ڵ���ʩ��\n");
		printf("<1>��   <2>��\n");
		scanf("%d",&sign);
		judge(&sign,1);
		if(sign==1)
		{
			strcat(ws, "ѡ���ѯ����1000�׷�Χ�ڵ���ʩ");
			cvtime(&smh, &smm, sh, sm);
			writelog(1, 1, ws, smh, smm);
			smh = stph;
			smm = stpm;
			renew(ws);
			//��ѯ������ʩ 
			count=search(campus,x,y,note);
			if (count == 0) {
				printf("����1000�׷�Χ��û�������ʩ\n");
				strcat(ws, "����1000�׷�Χ��û�������ʩ");
				cvtime(&smh, &smm, sh, sm);
				writelog(1, 1, ws, smh, smm);
				smh = stph;
				smm = stpm;
				renew(ws);
			}
			//��������ʩ 
			else
			{
				//�����·����׼�� 
				copy(70,campus,map,path1);
				shortPath(70,map,path1);
				//��ʵ����������ʩ��Ϣ 
				for(i=0;i<count;i++)
				{
					Num_to_Name(campus,note[i],name);
                    if(locate!=note[i])
					{
						char tmpn[20] = { 0 };
			            distance=distance_path(locate,note[i],map,path1);
						_itoa(distance, tmpn, 10);
				    	printf("<%d> %s   �൱ǰλ�����·������Ϊ��%d ��\n",note[i],name,distance);
						strcat(ws, name);
						strcat(ws, "���뵱ǰλ�����·������Ϊ��");
						strcat(ws, tmpn);
						strcat(ws, "��");
						cvtime(&smh, &smm, sh, sm);
						writelog(1, 1, ws, smh, smm);
						smh = stph;
						smm = stpm;
						renew(ws);
					} 
					else {
						printf("<%d> %s   ���·����ֱ�߾��룬���ɲ鵽�õ�����·��\n", note[i], name);
						strcat(ws, name);
						strcat(ws, "���·����ֱ�߾��룬���ɲ鵽�õ�����·��");
						cvtime(&smh, &smm, sh, sm);
						writelog(1, 1, ws, smh, smm);
						smh = stph;
						smm = stpm;
						renew(ws);
					}
				}
				//��ѯ��ĳһ������·��
				printf("�Ƿ���Ҫ��ѯ��������ʩ�����·����\n");
				printf("<1>��  <2>��\n");
				scanf("%d",&sign);
				judge(&sign,1);
				if(sign==1)
				{
					char tmps[20] = { 0 };
					strcat(ws, "ѡ���ѯ��������ʩ�����·��");
					cvtime(&smh, &smm, sh, sm);
					writelog(1, 1, ws, smh, smm);
					smh = stph;
					smm = stpm;
					renew(ws);
					printf("�������ѯĿ�ĵص����\n");
					scanf("%d",&sign);
					_itoa(sign, tmps, 10);
					strcat(ws, "�����˲�ѯĿ�ĵص���ţ����Ϊ:");
					strcat(ws, tmps);
					cvtime(&smh, &smm, sh, sm);
					writelog(1, 1, ws, smh, smm);
					smh = stph;
					smm = stpm;
					renew(ws);
					short_path(path,locate,sign,path1,0);//Ѱ�����·��
					j=store_path(path,0,path2);//�洢·��
					printWay(1,campus,campus,locate,sign,path2,1,pass,notes); 
				} 
			}
		}
		else {
			strcat(ws, "ѡ�񲻲�ѯ����1000�׷�Χ�ڵ���ʩ");
			cvtime(&smh, &smm, sh, sm);
			writelog(1, 1, ws, smh, smm);
			smh = stph;
			smm = stpm;
			renew(ws);
		}
		 
	} 
}

//��ѯ������ʩ
int search(int campus,int x,int y,int note[])
{
	int i,j;
	long d;
	int x1,y1;
	//У��һ��
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
	//У������
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
	return j;//���ظ�����ʩ���� 
 } 

//��ӡϵͳʱ��
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
