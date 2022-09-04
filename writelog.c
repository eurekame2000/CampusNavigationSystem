#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"writelog.h"
#pragma warning(disable:4996);

void writelog(int mock,int correct,char s[],int h,int m) {
	if (!correct) {
		strcat(s, "选择出错！");
	}
	FILE *f = fopen("log.txt", "a+");
	char tmps[maxs] = { 0 };
	if (!m) {
		strcat(s, "\t当前真实时间：");
		getrtime(tmps);
		strcat(s, tmps);
		strcat(s, "\n");
		fputs(s, f);
		fclose(f);
	}
	else {
			char tmph[20] = { 0 };
			char tmpm[20] = { 0 };
			_itoa(h, tmph, 10);
			_itoa(m, tmpm, 10);
			strcat(s, "\t当前模拟系统时间：");
			strcat(s, tmph);
			strcat(s, ":");
			strcat(s, tmpm);
			strcat(s, "\n");
			fputs(s, f);
			fclose(f);
	}
}
void getrtime(char *mytime) {
	char *wday[] = { "星期天", "星期一", "星期二",
		"星期三", "星期四", "星期五", "星期六" };
	time_t timep;
	struct tm *p;
	time(&timep);
	p = gmtime(&timep);
	char tmpyr[20] = { 0 };
	char tmpmt[20] = { 0 };
	char tmpdy[20] = { 0 };
	char tmphr[20] = { 0 };
	char tmpm[20] = { 0 };
	char tmps[20] = { 0 };
	_itoa(1900 + p->tm_year, tmpyr, 10);
	_itoa(1 + p->tm_mon, tmpmt, 10);
	_itoa(p->tm_mday, tmpdy, 10);
	_itoa(8 + p->tm_hour, tmphr, 10);
	_itoa(p->tm_min, tmpm, 10);
	_itoa(p->tm_sec, tmps, 10);
	strcat(mytime, tmpyr);
	mytime[strlen(mytime)] = '/';
	strcat(mytime, tmpmt);
	mytime[strlen(mytime)] = '/';
	strcat(mytime, tmpdy);
	mytime[strlen(mytime)] = ' ';
	strcat(mytime, wday[p->tm_wday]);
	mytime[strlen(mytime)] = ' ';
	strcat(mytime, tmphr);
	mytime[strlen(mytime)] = ':';
	strcat(mytime, tmpm);
	mytime[strlen(mytime)] = ':';
	strcat(mytime, tmps);
}
/*void getvtime(char *vtime) {
	time_t timep;
	struct tm *p;
	time(&timep);
	p = gmtime(&timep);
	char tmphr[20] = { 0 };
	char tmpm[20] = { 0 };
	char tmps[20] = { 0 };
	int h, m, s;
	h = 8 + p->tm_hour;
	m = p->tm_min;
	s = p->tm_sec;
	time_system(h,m, s);
	_itoa(h, tmphr, 10);
	_itoa(m, tmpm, 10);
	_itoa(s, tmps, 10);
	strcat(vtime, tmphr);
	vtime[strlen(vtime)] = ':';
	strcat(vtime, tmpm);
	vtime[strlen(vtime)] = ':';
	strcat(vtime, tmps);
}*/
void renew(char *s) {
	int i;
	for (i = 0; s[i] != 0; i++) {
		s[i] = 0;
	}
}
void cvtime(int *mh, int *mm,int h,int m) {//虚拟时间的推演
	time_t timep;
	struct tm *p;
	int time1, time2,time_stop;
	time(&timep);
	p = gmtime(&timep);
	time1 = p->tm_min;//结束暂停时的时间                 
	time2 = p->tm_sec;
	//查询所用时间				
	time_stop = (time1 * 60 + time2) - (h * 60 + m);
	time_system(mh, mm, time_stop);
}