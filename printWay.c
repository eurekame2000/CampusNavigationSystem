#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"main.h"
#include"print.h"
#include"printway.h"
#include"writelog.h"
#include"guide.h"
#pragma warning(disable:4996);


void printWay(int type,int sCampus,int eCampus,int start,int end,int* path,int flag,int path1[][20],int notes[][2])//flag==0 �����г��� 
{//�������� ��ʼУ�� ��ֹУ�� ��� �յ� ·������ ���г���־λ ;���ڵ����� ��д���¼����������;��룩 
	int point;
	int j=0;
	char strategy[4][50]={"��̾������","���ʱ�����",";����̾������","��ͨ�������ʱ�����"};
	char name1[20]={'\0'};
	char name2[20]={'\0'};
	char name[20]={'\0'};
	char name_s[20]={'\0'};
	char name_e[20]={'\0'};
	char dname[10]={'\0'};//�淽������
	char ws[maxs] = { 0 };
	
	if(sCampus==1&&eCampus==2)
	{
		strcpy(name_s,"У��һ");
		strcpy(name_e,"У����");
	 } 
	else if(sCampus==2&&eCampus==1)
	{
		strcpy(name_s,"У����");
		strcpy(name_e,"У��һ");		
	}
	else if(sCampus==1&&eCampus==1)
	{
		strcpy(name_s,"У��һ");
		strcpy(name_e,"У��һ");		
	}
	else
	{
		strcpy(name_s,"У����");
		strcpy(name_e,"У����");		
	}
	
	int i=0;
	if(type!=3&&type!=4) //�������� 
	{
		Num_to_Name(eCampus,end,name2);
		if(flag!=1)//����ͣ��ѯʱ����� 
        {
        	Num_to_Name(sCampus,start,name1);
		    printf("%s\n",name1);	
		    printf("����%s ��%s��%s��%s��%s��·��Ϊ��\n",strategy[type-1],name_s,name1,name_e,name2);
			strcat(ws, "����");
			strcat(ws, strategy[type - 1]);
			strcat(ws, "��");
			strcat(ws, name_s);
			strcat(ws, "��");
			strcat(ws, name1);
			strcat(ws, "��");
			strcat(ws, name_e);
			strcat(ws, "��");
			strcat(ws, name2);
			strcat(ws, "��·��Ϊ��");
		}
		else {
			printf("����%s ��%s��%s��·��Ϊ��\n", strategy[type - 1], name_e, name2);
			strcat(ws, "����");
			strcat(ws, strategy[type - 1]);
			strcat(ws, "��");
			strcat(ws, name_e);
			strcat(ws, "��");
			strcat(ws, name2);
			strcat(ws, "��·��Ϊ��");
		}
	}
    else if(type==3)//;����̾������ 
    {
    	Num_to_Name(sCampus,start,name1);
		Num_to_Name(eCampus,end,name2);
    	printf("��%s%s��%s%s ;�о��� ",name_s,name1,name_e,name2);
		strcat(ws, "��");
		strcat(ws, name_s); 
		strcat(ws, name1);
		strcat(ws, "��");
		strcat(ws, name_e);
		strcat(ws, name2);
		strcat(ws, ";�о���");
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
		printf("�Ҿ�����̵�·��Ϊ��\n");
		strcat(ws, "�Ҿ�����̵�·��Ϊ��");
	}
	else
	{
		int s = 0;
		//��У��1��s=1����У��2��s=2��У��1��У��2��s=3��У��2��У��1��s=4
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
			printf("��%s��%s�����г���",name1,name2);
			strcat(ws, "��");
			strcat(ws, name1);
			strcat(ws, "��");
			strcat(ws, name2);
			strcat(ws, "�����г���");
			writelog(0, 1, ws, 0, 0);
			renew(ws);
			return;
		}
		else 
		{
			Num_to_Name(sCampus,start,name1);
		    Num_to_Name(eCampus,end,name2);
		    printf("�����г���%s��%s��ʱ����̵�·��Ϊ��",name1,name2);
			strcat(ws, "��");
			strcat(ws, name1);
			strcat(ws, "��");
			strcat(ws, name2);
			strcat(ws, "��ʱ����̵�·��Ϊ��");
			writelog(0, 1, ws, 0, 0);
			renew(ws);
		}
	}
    //����ͣ��ѯʱ���
	if(type!=1&&flag!=1)
	{
		Num_to_Name(sCampus,start,name);
        printf("��%s���� ",name);
		strcat(ws,"��");
		strcat(ws,name);
		strcat(ws, "���� ");
	 } 
    i=0;
	if(sCampus==1&&eCampus==1)//У��1���ڲ����� 
	{
		while(path[i+1]!=-1)//path[i]�����յ� 
		{
			char tmps[20] = { 0 };
			point=path[i];
			_itoa(distance1[point][path[i + 1]], tmps, 10);
			direction_to_Name(direction1[point][path[i+1]],dname);
			notes[j][0]=direction1[point][path[i+1]];
	        printf("��%s���� ",dname);
			strcat(ws, "��");
			strcat(ws, dname);
			strcat(ws, "���� ");
	        notes[j][1]=distance1[point][path[i+1]];
	        j++;
	        printf("ǰ��%d�� ",distance1[point][path[i+1]]);
			strcat(ws, "ǰ��");
			strcat(ws, tmps);
			strcat(ws, "�� ");
			if(path[i+1]<20)//�ӵڶ����㵽�յ���ж�һ�� 
			{
				Num_to_Name(sCampus,path[i+1],name);
				printf("����%s\n",name);//�����ｨ����
				strcat(ws, "����");
				strcat(ws, name);
				strcat(ws, "\n");
			}
			i++;
		}
	}
	else if(sCampus==2&&eCampus==2)//У��2���ڲ����� 
	{
		while(path[i+1]!=-1)//path[i]�����յ� 
		{
			char tmps[20] = { 0 };
			point=path[i];
			_itoa(distance2[point][path[i + 1]], tmps, 10);
			direction_to_Name(direction2[point][path[i+1]],dname);
			notes[j][0]=direction2[point][path[i+1]];
	        printf("��%s���� ",dname);
			strcat(ws, "��");
			strcat(ws, dname);
			strcat(ws, "���� ");
	        notes[j][1]=distance2[point][path[i+1]];
	        j++;
	        printf("ǰ��%d�� ",distance2[point][path[i+1]]);
			strcat(ws, "ǰ��");
			strcat(ws, tmps);
			strcat(ws, "�� ");
			if(path[i+1]<20)//�ӵڶ����㵽�յ���ж�һ�� 
			{
				Num_to_Name(sCampus,path[i+1],name);
				printf("����%s\n",name);//�����ｨ���� 
				strcat(ws, "����");
				strcat(ws, name);
				strcat(ws, "\n");
			}
			i++;
		}
	}
	else if(sCampus==1&&eCampus==2)//��У��1��У��2
	{
		while(path[i+1]!=-2&&path[i+1]!=-3)//����������ڵ�У����
		{
			char tmps[20] = { 0 };
			point=path[i];
			_itoa(distance1[point][path[i + 1]], tmps, 10);
			direction_to_Name(direction1[point][path[i+1]],dname);
			notes[j][0]=direction1[point][path[i+1]];
	        printf("��%s���� ",dname);
			strcat(ws, "��");
			strcat(ws, dname);
			strcat(ws, "���� ");
	        notes[j][1]=distance1[point][path[i+1]];
	        j++; 
	        printf("ǰ��%d�� ",distance1[point][path[i+1]]);
			strcat(ws, "ǰ��");
			strcat(ws, tmps);
			strcat(ws, "�� ");
		    if(path[i+1]<20)//�ӵڶ����㵽��վ���ж�һ�� 
		    {
		    	Num_to_Name(sCampus,path[i+1],name);
			    printf("����%s\n",name);//�����ｨ���� 
				strcat(ws, "����");
				strcat(ws, name);
				strcat(ws, "\n");
			}
		    i++;
		}//���ڵ�path[i]��Ϊ��վ
		if(path[i+1]==-2) 
		{
			notes[j][0]=-2;
		    notes[j][1]=-2;
		    j++;
		    printf("�����೵�����У���೵վ\n");
			strcat(ws, "�����೵�����У���೵վ\n");
		}
		else
		{
			notes[j][0]=-3;
		    notes[j][1]=-3;
		    j++;
			printf("���������������У��������վ\n");
			strcat(ws, "���������������У��������վ\n");
		} 
		i++;
		i++;//path[i]Ϊ��У����վ ��Ϊ��� 
		while(path[i+1]!=-1)
		{
			char tmps[20] = { 0 };
			point=path[i];
			_itoa(distance2[point][path[i + 1]], tmps, 10);
			direction_to_Name(direction2[point][path[i+1]],dname);
			notes[j][0]=direction2[point][path[i+1]];
	        printf("��%s���� ",dname);
			strcat(ws, "��");
			strcat(ws, dname);
			strcat(ws, "���� ");
	        notes[j][1]=distance2[point][path[i+1]];
	        j++;
	        printf("ǰ��%d�� ",distance2[point][path[i+1]]);
			strcat(ws, "ǰ��");
			strcat(ws, tmps);
			strcat(ws, "�� ");
		    if(path[i+1]<20)//�ӳ�վ���һ���㵽�յ���ж�һ�� 
		    {
		    	Num_to_Name(eCampus,path[i+1],name);
			    printf("����%s \n",name);//�����ｨ���� 
				strcat(ws, "����");
				strcat(ws, name);
				strcat(ws, "\n");
			}
			i++;
		}
	} 
	else if(sCampus==2&&eCampus==1)//��У��2��У��1
	{
		while(path[i+1]!=-2&&path[i+1]!=-3)//����������ڵ�У����
		{
			char tmps[20] = { 0 };
			point=path[i];
			_itoa(distance2[point][path[i + 1]], tmps, 10);
			direction_to_Name(direction2[point][path[i+1]],dname);
			notes[j][0]=direction2[point][path[i+1]];
	        printf("��%s���� ",dname);
			strcat(ws, "��");
			strcat(ws, dname);
			strcat(ws, "���� ");
	        notes[j][1]=distance2[point][path[i+1]];
	        j++;
	        printf("ǰ��%d�� ",distance2[point][path[i+1]]);
			strcat(ws, "ǰ��");
			strcat(ws, tmps);
			strcat(ws, "�� ");
		    if(path[i+1]<20)//�ӵڶ����㵽��վ���ж�һ�� 
		    {
		    	Num_to_Name(sCampus,path[i+1],name);
			    printf("����%s\n",name);//�����ｨ���� 
				strcat(ws, "����");
				strcat(ws, name);
				strcat(ws, "\n");
			}
		    i++;
		}//���ڵ�path[i]��Ϊ��վ
		if(path[i+1]==-2) 
		{
			notes[j][0]=-2;
		    notes[j][1]=-2;
		    printf("�����೵����һУ���೵վ\n");
			strcat(ws, "�����೵����һУ���೵վ\n");
		    j++;
		}
		else
		{
			notes[j][0]=-3;
		    notes[j][1]=-3;
		    printf("��������������һУ��������վ\n"); 
			strcat(ws, "��������������һУ��������վ\n");
		    j++;
		}
		i++;
		i++;//path[i]ΪһУ����վ ��Ϊ��� 
		while(path[i+1]!=-1)
		{
			char tmps[20] = { 0 };
			point=path[i];
			_itoa(distance1[point][path[i + 1]], tmps, 10);
			direction_to_Name(direction1[point][path[i+1]],dname);
			notes[j][0]=direction1[point][path[i+1]];
	        printf("��%s���� ",dname);
			strcat(ws, "��");
			strcat(ws, dname);
			strcat(ws, "���� ");
	        notes[j][1]=distance1[point][path[i+1]];
	        j++;
	        printf("ǰ��%d�� ",distance1[point][path[i+1]]);
			strcat(ws, "ǰ��");
			strcat(ws, tmps);
			strcat(ws, "�� ");
		    if(path[i+1]<20)//�ӳ�վ���һ���㵽�յ���ж�һ�� 
		    {
		    	Num_to_Name(eCampus,path[i+1],name);
			    printf("����%s \n",name);//�����ｨ���� 
				strcat(ws, "����");
				strcat(ws, name);
				strcat(ws, "\n");
			}
			i++;
		}
	} 
	writelog(0, 1, ws, 0, 0);
} 

