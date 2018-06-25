
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct zggz{
	char num[20];
	char name[20];
	float wage_gw;
	float wage_xj;
	float wage_zw;
	float wage_jx;
	float wage_yf;
	float taxfee;
	float wage_sf;
}zgs[999],*zg;
	int n=0;
void read()    //读取职工工资数据
{
	 FILE *fp;
     zg=zgs;
     if((fp=fopen("gz.dat","rb+"))==NULL)
     {
          printf("不能打开文件\n");
		  getch();
          exit(-1);
     }
	 rewind(fp);
	 for(int i=0; i<999; i++,zg++)  //判断几条数据
	 {  
		 fscanf(fp,"%s %s %f %f %f %f %f %f %f\n",zg->num,zg->name,&(zg->wage_gw),&(zg->wage_xj),&(zg->wage_zw),&(zg->wage_jx),&(zg->wage_yf),&(zg->taxfee),&(zg->wage_sf));
		 printf("%s %s %f %f %f %f %f %f %f\n",zg->num,zg->name,zg->wage_gw,zg->wage_xj,zg->wage_zw,zg->wage_jx,zg->wage_yf,zg->taxfee,zg->wage_sf);
		 n++;
		 if(feof(fp))
		 {
		   break;
		 }
	 }

	 //printf("%s\n",zgs[6].num );
	 fclose(fp);
	 printf("共有数据数为：%d\n",n);
}
void write()
{
	FILE *fb; 
 if((fb=fopen("gz.dat","rb+"))==NULL) 
 {
	 printf("不能打开 \n"); 
	 getch();
	 exit(-1); 
 } 
 fwrite(zgs,sizeof(struct zggz),n,fb);
 fclose(fb); 
}
void find()
{
	char gonghao[20];
	printf("\n请输入职工编号:");
	gets(gonghao);
	for(int i=0; i<999; i++)  
	{
		if(strcmp(zgs[i].num,gonghao)==0)
		{
			printf("有");
			printf("%s\n",zgs[i].num);
			getch();
			break;	
		}
	

	}
}
void list()
{
	zg=zgs;
	char jieshu[10];
	jieshu[0]=0;
		printf("工号   姓名   岗位工资  薪级工资   职务津贴   绩效工资  应发工资  个人所得税   实发工资\n");
	for(int i=0;i<999;i++,zg++)
	{	
		printf("%s %s %f %f %f %f %f %f %f\n",zg->num,zg->name,zg->wage_gw,zg->wage_xj,zg->wage_zw,zg->wage_jx,zg->wage_yf,zg->taxfee,zg->wage_sf);
		if(strcmp(zgs[i+1].num,jieshu)==0) break;
	}
}
void modify()
{
	FILE *fb; 
	if((fb=fopen("gz.dat","rb+"))==NULL) 
	{
	 printf("不能打开 \n"); 
	 getch();
	 exit(-1); 
	} 
	char gonghao[20];
	printf("\n请输入职工编号:");
	zg=zgs;
	gets(gonghao);
	for(int i=0; i<999; i++)  
	{
		if(strcmp(zgs[i].num,gonghao)==0)
		{
			printf("请输入职工信息:\n");
			scanf("%s %s %f %f %f %f %f %f %f\n",zg->num,zg->name,&(zg->wage_gw),&(zg->wage_xj),&(zg->wage_zw),&(zg->wage_jx),&(zg->wage_yf),&(zg->taxfee),&(zg->wage_sf));
			fwrite(zg,sizeof(struct zggz),1,fb);
			getch();
			fclose(fb);
			break;	
		}
	}
}
int main()
{
	//modify();
	read();
	//find();
	//write();
	//list();
	return 0;
}