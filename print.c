#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"main.h"
#include"print.h"
#include"writelog.h"
#pragma warning(disable:4996);

//��ӡ������ؽ���
void print1()
{
	printf("\t\t\t\t * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t * *************************************\n");
	printf("\t\t\t\t * *                                 * *\n");
	printf("\t\t\t\t * *         ��ӭʹ�õ���ϵͳ        * *\n");
	printf("\t\t\t\t * *                                 * *\n");
	printf("\t\t\t\t * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t * *************************************\n");
     	
} 
//��ʾ������ź���
void print(int num,int school) {
	if (num == 1) {//numΪ1ʱ��ӡ����λ��
        if(school==1)//��ӡУ��1������λ�� 
        {
    	printf("\n");
		printf("\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *\n");
		printf("\t\t\t\t * *                   *����λ���б�*                   * *\n");
		printf("\t\t\t\t * ****************************************************** *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <0>�೵վ   <1>����վ   <2>������   <3>2�Ű칫¥  * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <4>1�Ű칫¥  <5>2������  <6>4������  <7>1�ų���  * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <8>�ٳ�   <9>2��ʳ��   <10>3������   <11>1������  * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <12>1��ʳ��        <13>2�ų���        <14>ͼ���  * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <15>3��ʳ��     <16>2�Ž�ѧ¥     <17>�ĺŽ�ѧ¥  * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <18>1�Ž�ѧ¥                      <19>3�Ž�ѧ¥  * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * ****************************************************** *\n");
		printf("\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *\n");
		printf("\n");    	
		}
		if(school==2)//��ӡУ��2������λ�� 
		{
        printf("\n");
		printf("\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *\n");
		printf("\t\t\t\t * *                   *����λ���б�*                   * *\n");
		printf("\t\t\t\t * ****************************************************** *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <0>������վ   <1>��ʳ��   <2>С����   <3>һ����¥ * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <4>������¥  <5>һʳ��     <6>�ٳ�     <7>��ʳ��  * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <8>������¥   <9>������¥  <10>������ <11>��ʳ��  * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <12>һ��ѧ¥        <13>����ѧ¥    <14>һ�칫¥  * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <15>�೵վ          <16>ͼ���      <17>����ѧ¥  * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <18>�Ľ�ѧ¥                      <19>���칫¥    * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * ****************************************************** *\n");
		printf("\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *\n");
		printf("\n");
		}
	}
	if(num==2){//numΪ2ʱ��ӡ�߼�λ�ñ�
	    if(school==1){//��ӡУ��1���߼�λ�ñ� 
	    printf("\n");
		printf("\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * * * * * *\n");
		printf("\t\t\t\t * *                       *�߼�λ���б�*                       * *\n");
		printf("\t\t\t\t * ************************************************************** *\n");
		printf("\t\t\t\t * *  <<0>�೵վ       <1>����վ     <2.1>�質��������          * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <2.2>�������ص�  <2.3>��ʷ��������  <3.1>����Ա�칫��   * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <3.2>��Ժ�ۺϰ칫��    <3.3>��Ժ���   <4.1>����      * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <4.2>����    <4.3ѧУ��ȫ����>  <5.1>��������������     * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <6.1>�о���Ů������    <7.1>ˮ����     <7.2>�۾���        * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <7.3>����  <8.1>������  <8.2>�������  <9>2��ʳ��       * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <10.1>�о�����������  <11.1>������Ů������  <12>1��ʳ��   * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <13.1>��ӡ��     <13.2>����ά��      <14.1>ͼ���־Ը     * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <14.2>��ϰ��        <14.3>�ʶ�ͤ        <15.1>����ʳ��    * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <16.1>���ݽṹ��  <16.2>���ݽṹ�ο���  <17.1>���￼��    * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <17.2>Ӣ������������    <18.1>��������  <18.2>�������    * *\n");
		printf("\t\t\t\t * *                                                            * *\n");
		printf("\t\t\t\t * *  <19.1>����ʵ����  <19.2>���ֵ�·ʵ����  <19.3>ë�Ž���    * *\n");
		printf("\t\t\t\t * ************************************************************** *\n");
		printf("\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * * * * * *\n");
		printf("\n"); 
		} 
		if(school==2){//��ӡУ��2���߼�λ�ñ�
        printf("\n");
		printf("\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *\n");
		printf("\t\t\t\t * *                   *�߼�λ���б�*                   * *\n");
		printf("\t\t\t\t * ****************************************************** *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <0>������վ    <1>��ʳ��       <2>С����          * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <3.1>��һ��������¥        <3.2>��һŮ������¥    * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <4.1>������������¥        <4.2>����Ů������¥    * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <5>һʳ��  <6>�ٳ�  <7>��ʳ�� <8.1>�����������¥ * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <8.2>���Ů������¥    <11>��ʳ��                 * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <9.1>������������¥        <9.2>����Ů������¥    * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <10.1>��Ӿ��  <10.2>����  <12.1>Ӣ��ν���      * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <12.2>Ӣ��ο���      <13.1>�����רҵ�ν���      * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <13.2>�����רҵ�ο���      <14.1>����Ա�칫��    * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <14.2>У���칫��           <15>�೵վ             * *\n"); 
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <16.1>ͼ����Ĵ�          <16.2>ͼ��������        * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <17.1>ʵ��ν��� <17.2>ʵ����   <18.1>������      * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * *  <18.2>�ۺϽ���   <19.1>��ʦ�칫�� <19.2>����    * *\n");
		printf("\t\t\t\t * *                                                    * *\n");
		printf("\t\t\t\t * ****************************************************** *\n");
		printf("\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *\n");
		printf("\n"); 
		}
	}
	if(num==3){//numΪ3ʱ��ӡ4�ֵ�������
	printf("\n");
	printf("***��ѡ������������***\n");
	printf("<1>��̾������\n");
	printf("<2>���ʱ�����\n");
	printf("<3>;����̾������\n");
	printf("<4>��ͨ�������ʱ�����\n"); 
	}
} 

//�õ���������ֹ�ص��Լ���������
void getOrder(int* sCampus,int* start,int* eCampus,int* end,int* type,int (*adress)[20])
{
	int num,school1,school2,s,e,t,i,j;
	int d;
	float f;
	char ws[maxs] = { 0 };
	//ѡ��ʼУ����ص�
	printf("��ѡ�����У����ţ�<1>У��1  <2>У��2\n");
	scanf_s("%d",&school1);
	judge(&school1,1);
	*sCampus=school1;
	strcat(ws, "����ѡ�����У����ţ�ѡ������У��");
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
	printf("��ѡ������ʾ��ʽ������λ����ѡ1���߼�λ����ѡ2\n");
	scanf_s("%d",&num);
	judge(&num,1);
	strcat(ws, "����ѡ������ʾ��ʽ��ѡ������");
	if ((num == 1) || (num == 2)) {
		if (num == 1) {
			strcat(ws, "����λ��");
			writelog(0,1, ws, 0, 0);
		}
		else{
			strcat(ws, "�߼�λ��");
			writelog(0,1, ws, 0, 0);
		}	
	}
	else {
		writelog(0,0, ws, 0, 0);
	}
	renew(ws);
	printf("�������е�ַ����ѡ����ʼ�ص㣬���������Ӧ���\n");
	print(num,school1);
	scanf_s("%f",&f);
	s=f;
	judge(&s,2);
	*start=s;
	strcat(ws, "����ѡ����ʼ�ص㣬ѡ������");
	if (school1 == 1) {
		char tmps[maxs] = { 0 };
		strcat(ws, "У��1��");
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
		strcat(ws, "У��2��");
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
	//ѡ���յ�У����ص� 
	printf("��ѡ���յ�У����ţ�<1>У��1  <2>У��2\n");
	scanf_s("%d",&school2);
	judge(&school2,1);
	*eCampus=school2;
	strcat(ws, "����ѡ���յ�У����ţ�ѡ������У��");
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
	printf("��ѡ���յ��ʾ��ʽ������λ����ѡ1���߼�λ����ѡ2\n");
	scanf_s("%d",&num);
	judge(&num,1);
	strcat(ws, "����ѡ���յ��ʾ��ʽ��ѡ������");
	if ((num == 1) || (num == 2)) {
		if (num == 1) {
			strcat(ws, "����λ��");
			writelog(0,1, ws, 0, 0);
		}
		else {
			strcat(ws, "�߼�λ��");
			writelog(0,1, ws, 0, 0);
		}
	}
	else {
		writelog(0,0, ws, 0, 0);
	}
	renew(ws);
	printf("�������е�ַ����ѡ���յ�ص㣬���������Ӧ���\n");
	print(num,school2);
	scanf_s("%f",&f);
	e=f;
	judge(&e,2);
	*end=e;
	strcat(ws, "����ѡ���յ�ص㣬ѡ������");
	if (school2 == 1) {
		char tmps[maxs] = { 0 };
		strcat(ws, "У��1��");
		Num_to_Name(school2, f, tmps);
		strcat(ws, tmps);
		writelog(0,1, ws, 0, 0);
	}
	else if (school2==2) {
		char tmps[maxs] = { 0 };
		strcat(ws, "У��2��");
		Num_to_Name(school2, f, tmps);
		strcat(ws, tmps);
		writelog(0,1, ws, 0, 0);
	}
	else {
		writelog(0,0, ws, 0, 0);
	}
	renew(ws);
	//ѡ�񵼺�����
	printf("��ѡ�񵼺����ԣ����������Ӧ���\n");
	print(3,0);
	scanf_s("%d",&t);
	judge(&t,3);
	*type=t;
	strcat(ws, "����ѡ�񵼺����ԣ�ѡ������");
	if ((t >= 1) && (t <= 4)) {
		if (t == 1) {
			strcat(ws,"��������1--��̾������");
		}
		else if (t == 2) {
			strcat(ws,"��������2--���ʱ�����");
		}
		else if (t == 3) {
			strcat(ws,"��������3--;����̾������");
		}
		else {
			strcat(ws, "��������4--��ͨ���ߵ����ʱ�����");
		}
		writelog(0,1, ws, 0, 0);
	}
	else {
		writelog(0,0, ws, 0, 0);
	}
	renew(ws);
	if(t==3)//�洢;���ص�ı�� 
	{
		if(school1==school2)//ͬһУ����Ĭ��;���ص���ڵ�һ�� 
		{
			j=0;
			system("cls");
			printf("��ѡ��;���ص��ʾ��ʽ������λ����ѡ1���߼�λ����ѡ2\n");
	        scanf_s("%d",&num);
	        judge(&num,1);
			print(num, school1);
			strcat(ws, "����ѡ��");
			if (school1 == 1) {
				strcat(ws, "У��1;���ص��ʾ��ʽ��ѡ������");
			}
			else if(school1==2){
				strcat(ws, "У��2;���ص��ʾ��ʽ��ѡ������");
			}
			/*else {
				writelog(0, ws);
			}*/
			if (num == 1) {
				strcat(ws, "����λ��");
				writelog(0,1, ws, 0, 0);
			}
			else if (num == 2) {
				strcat(ws, "�߼�λ��");
				writelog(0,1, ws, 0, 0);
			}
			else {
				writelog(0,0, ws, 0, 0);
			}
			renew(ws);
			printf("����������;���ص�ı�ţ�������-1����\n");
			scanf_s("%d",&d);
			judge(&d,4);
			while(d!=-1)
			{
				strcat(ws, "����ѡ��");
				if (school1 == 1) {
					strcat(ws, "У��1;���ص㣬ѡ������");
				}
				else if (school1 == 2) {
					strcat(ws, "У��2;���ص㣬ѡ������");
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
		else//��ͬУ��ʱ������ʼУ��;���ĵص���ڵ�һ�У���ֹУ����;���ĵص���ڵڶ��� 
		{
			j=0;
			system("cls");
			printf("��ѡ��У��%d��;���ص��ʾ��ʽ������λ����ѡ1���߼�λ����ѡ2\n",school1);
	        scanf_s("%d",&num);
	        judge(&num,1);
			print(num, school1);
			if (school1 == 1) {
				strcat(ws, "����ѡ��У��1��;;���ص��ʾ��ʽ��ѡ������");
			}
			else if (school1 == 2) {
				strcat(ws, "����ѡ��У��2��;;���ص��ʾ��ʽ��ѡ������");
			}
			if (num == 1) {
				strcat(ws, "����λ��");
				writelog(0,1, ws , 0, 0);
			}
			else if (num == 2) {
				strcat(ws, "�߼�λ��");
				writelog(0,1, ws, 0, 0);
			}
			else {
				writelog(0,0, ws, 0, 0);
			}
			renew(ws);
			printf("����������;���ص�ı�ţ�������-1����\n");
			scanf_s("%d",&d);
			judge(&d,4);
			while(d!=-1)
			{
				strcat(ws, "����ѡ��");
				if (school1 == 1) {
					strcat(ws, "У��1;���ص㣬ѡ������");
				}
				else if (school1 == 2) {
					strcat(ws, "У��2;���ص㣬ѡ������");
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
			printf("��ѡ��У��%d��;���ص��ʾ��ʽ������λ����ѡ1���߼�λ����ѡ2\n",school2);
	        scanf_s("%d",&num);
	        judge(&num,1);
			print(num, school2);
			strcat(ws, "����ѡ��У��");
			if ((school2 == 1) || (school2 == 2)) {
				if (school2 == 1) {
					strcat(ws, "1��;;���ص��ʾ��ʽ��ѡ������");
				}
				else if (school2 == 2) {
					strcat(ws, "2��;;���ص��ʾ��ʽ��ѡ������");
				}
				if (num == 1) {
					strcat(ws, "����λ��");
					writelog(0,1, ws, 0, 0);
				}
				else if (num == 2) {
					strcat(ws, "�߼�λ��");
					writelog(0,1, ws, 0, 0);
				}
			}
			else {
				writelog(0,0, ws, 0, 0);
			}
			renew(ws);
			printf("����������;���ص�ı�ţ�������-1����\n");
			scanf_s("%d",&d);
			judge(&d,4);
			while(d!=-1)
			{
				strcat(ws, "����ѡ��");
				if (school2 == 1) {
					strcat(ws, "У��1;���ص㣬ѡ������");
				}
				else if (school2 == 2) {
					strcat(ws, "У��2;���ص㣬ѡ������");
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
	{   if(number==0) strcpy(name,"�೵վ");
		if(number==1) strcpy(name,"����վ");
		if(number==2) strcpy(name,"������");
		if(number==3) strcpy(name,"2�Ű칫¥");
		if(number==4) strcpy(name,"1�Ű칫¥");
		if(number==5) strcpy(name,"2������");
		if(number==6) strcpy(name,"4������");
		if(number==7) strcpy(name,"1�ų���");
		if(number==8) strcpy(name,"�ٳ�");
		if(number==9) strcpy(name,"2��ʳ��");
		if(number==10) strcpy(name,"3������");
		if(number==11) strcpy(name,"1������");
		if(number==12) strcpy(name,"1��ʳ��");
		if(number==13) strcpy(name,"2�ų���");
		if(number==14) strcpy(name,"ͼ���");
		if(number==15) strcpy(name,"3��ʳ��");
		if(number==16) strcpy(name,"2�Ž�ѧ¥");
		if(number==17) strcpy(name,"�ĺŽ�ѧ¥");
		if(number==18) strcpy(name,"1�Ž�ѧ¥");
		if(number==19) strcpy(name,"3�Ž�ѧ¥");
	}
	else if(school==2)
	{
		if(number==0) strcpy(name,"������վ");
		if(number==1) strcpy(name,"��ʳ��");
		if(number==2) strcpy(name,"С����");
		if(number==3) strcpy(name,"һ����¥");
		if(number==4) strcpy(name,"������¥");
		if(number==5) strcpy(name,"һʳ��");
		if(number==6) strcpy(name,"�ٳ�");
		if(number==7) strcpy(name,"��ʳ��");
		if(number==8) strcpy(name,"������¥");
		if(number==9) strcpy(name,"������¥");
		if(number==10) strcpy(name,"������");
		if(number==11) strcpy(name,"��ʳ��");
		if(number==12) strcpy(name,"һ��ѧ¥ ");
		if(number==13) strcpy(name,"����ѧ¥");
		if(number==14) strcpy(name,"һ�칫¥");
		if(number==15) strcpy(name,"�೵վ");
		if(number==16) strcpy(name,"ͼ���");
		if(number==17) strcpy(name,"����ѧ¥");
		if(number==18) strcpy(name,"�Ľ�ѧ¥");
		if(number==19) strcpy(name,"���칫¥");
	} 
	else
	printf("�����ڴ�У��"); 
}

//���������Ϊ����
void direction_to_Name(int number,char* name) 
{
	if(number==1) strcpy(name,"��");
	else if(number==2) strcpy(name,"��");
	else if(number==3) strcpy(name,"��");
	else if(number==4) strcpy(name,"��");
	else if(number==5) strcpy(name,"����");
	else if(number==6) strcpy(name,"����");
	else if(number==7) strcpy(name,"����");
	else strcpy(name,"����");
	
}
