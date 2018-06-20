#include<stdio.h>
//#include<string.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
struct zggz{
	char num[10];
	char name[20];
	char wage_gw;
	float wage_xj;
	float wage_zw;
	float wage_jx;
	float wage_yf;
	float taxfee;
	float wage_sf;
}zg[999],newzg;
void read()    //读取职工工资数据
{
	 FILE *fp;
     char ch;
	 int n=0;
     if((fp=fopen("gx.dat","rb"))==NULL)
     {
          printf("不能打开文件\n");
		  getch();
          exit(-1);
     }
for(int i=0; i<5; i++)  //循环读取
	 {  
	   fprintf(fp,"%c %c %f %f %f %f %f %f %f\n",zg[i].num,zg[i].name,zg[i].wage_gw,zg[i].wage_xj,zg[i].wage_zw,zg[i].wage_jx,zg[i].wage_yf,zg[i].taxfee,zg[i].wage_sf);
       rewind(fp);
	   fscanf(fp,"%c %c %f %f %f %f %f %f %f\n",zg[i].num,zg[i].name,&(zg[i].wage_gw),&(zg[i].wage_xj),&(zg[i].wage_zw),&(zg[i].wage_jx),&(zg[i].wage_yf),&(zg[i].taxfee),&(zg[i].wage_sf)); 
++n;

}
ch=fgetc(fp);
while(ch!=EOF)
{
	putchar(ch);
	ch=fgetc(fp);
}
  fclose(fp);
}
int main()
{
	read();
	return 0;
}
