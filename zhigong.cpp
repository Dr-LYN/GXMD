
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct zggz{
	char num[10];
	char name[20];
	float wage_gw;
	float wage_xj;
	float wage_zw;
	float wage_jx;
	float wage_yf;
	float taxfee;
	float wage_sf;
}zgs[999],*zg;
void read()    //��ȡְ����������
{
	 FILE *fp;
     zg=zgs;
	 int n=0;
     if((fp=fopen("gx.dat","rb+"))==NULL)
     {
          printf("���ܴ��ļ�\n");
		  getch();
          exit(-1);
     }
	 for(int i=0; i<999; i++,zg++)  //�жϼ�������
	 {  
		 fscanf(fp,"%s %s %f %f %f %f %f %f %f\n",zg->num,zg->name,&(zg->wage_gw),&(zg->wage_xj),&(zg->wage_zw),&(zg->wage_jx),&(zg->wage_yf),&(zg->taxfee),&(zg->wage_sf));
		 printf("%s %s %f %f %f %f %f %f %f\n",zg->num,zg->name,zg->wage_gw,zg->wage_xj,zg->wage_zw,zg->wage_jx,zg->wage_yf,zg->taxfee,zg->wage_sf);
		 n++;
		 if(feof(fp))
		 {
		   break;
		 }
	 }
	 fclose(fp);
	 printf("����������Ϊ��%d\n",n);
}
void write()
{
	FILE *fb; 
 if((fb=fopen("gz.dat","wt+"))==NULL) 
 {
	 printf("���ܴ� \n"); 
 exit(-1); 
 } 

 fclose(fb); 
}
int main()
{
	read();
	return 0;
}