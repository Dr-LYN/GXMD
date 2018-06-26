
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
	void saveone(int i);
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
	FILE *fp; 
 if((fp=fopen("gz.dat","rb"))==NULL) 
 {
	 printf("不能打开 \n"); 
	 getch();
	 exit(-1); 
 } 
 rewind(fp);
 for(int i=0;i<n;i++)
 {
	 fwrite(&zgs[i],sizeof(struct zggz),1,fp);
 }
 printf("成功\n");
 fclose(fp); 
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
	
	char gonghao[20];
	printf("\n请输入职工编号:");
	//zg=zgs;
	gets(gonghao);
	for(int i=0; i<999; i++,zg++)  
	{
		if(strcmp(zgs[i].num,gonghao)==0)
		{
			printf("请输入职工信息:\n");
			//scanf("%s %s %f %f %f %f %f %f %f\n",zg->num,zg->name,&(zg->wage_gw),&(zg->wage_xj),&(zg->wage_zw),&(zg->wage_jx),&(zg->wage_yf),&(zg->taxfee),&(zg->wage_sf));
			printf("工号：");
			scanf("%s",zg->num);
			printf("姓名：");
			scanf("%s",zg->name);
			printf("岗位工资：");
			scanf("%f",&(zg->wage_gw));
			printf("薪级工资：");
			scanf("%f",&(zg->wage_xj));
			printf("职务津贴：");
			scanf("%f",&(zg->wage_zw));
			printf("绩效工资：");
			scanf("%f",&(zg->wage_jx));
			printf("应发工资：");
			scanf("%f",&(zg->wage_yf));
			printf("个人所得税：");
			scanf("%f",&(zg->taxfee));
			printf("实发工资：");
			scanf("%f",&(zg->wage_sf));
			getch();
			break;	
		}
	}
}
void saveone(int i)
{
	FILE *fp; 
	if((fp=fopen("gz.dat","wb+"))==NULL) 
	{
	 printf("不能打开 \n"); 
	 getch();
	 exit(-1); 
	} 
	fwrite(&zgs[i],sizeof(struct zggz),1,fp);
	fclose(fp);
}
int main()
{
	read();
	//find();
	//modify();
	//write();
	//list();
	return 0;
}