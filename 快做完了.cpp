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
}zgs[999];
	int n=0;
	int grsds(int n);
void read()    //读取职工工资数据
{
	 FILE *fp;
     if((fp=fopen("gz.dat","rb"))==NULL)
     {
          printf("不能打开文件\n");
		  getch();
          exit(1);
     }
	 for(int i=0; i<999; i++)  //判断几条数据
	 {  
		 fscanf(fp,"%s %s %f %f %f %f %f %f %f\n",zgs[i].num,zgs[i].name,&(zgs[i].wage_gw),&(zgs[i].wage_xj),&(zgs[i].wage_zw),&(zgs[i].wage_jx),&(zgs[i].wage_yf),&(zgs[i].taxfee),&(zgs[i].wage_sf));
		 //printf("%s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n",zgs[i].num,zgs[i].name,zgs[i].wage_gw,zgs[i].wage_xj,zgs[i].wage_zw,zgs[i].wage_jx,zgs[i].wage_yf,zgs[i].taxfee,zgs[i].wage_sf);
		 n++;
		 if(feof(fp))
		 {
		   break;
		 }
	 }
	 fclose(fp);
	 //printf("共有数据数为：%d\n",n);
}
void write()
{
	FILE *fp; 
	if((fp=fopen("gz.dat","wb+"))==NULL) 
	{
	 printf("不能打开 \n"); 
	 getch();
	 exit(1); 
	} 
	rewind(fp);
	for(int i=0;i<n;i++)
	{
		fprintf(fp,"%s %s %f %f %f %f %f %f %f\n",zgs[i].num,zgs[i].name,zgs[i].wage_gw,zgs[i].wage_xj,zgs[i].wage_zw,zgs[i].wage_jx,zgs[i].wage_yf,zgs[i].taxfee,zgs[i].wage_sf);
	}
	printf("成功保存\n");
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
			printf("工号      姓名      岗位工资      薪级工资     职务津贴      绩效工资     应发工资      个人所得税      实发工资\n");
			printf("%s\t %s\t %8.2f\t  %8.2f     %8.2f\t    %8.2f\t  %8.2f\t   %8.2f\t     %8.2f\t\n",zgs[i].num,zgs[i].name,zgs[i].wage_gw,zgs[i].wage_xj,zgs[i].wage_zw,zgs[i].wage_jx,zgs[i].wage_yf,zgs[i].taxfee,zgs[i].wage_sf);
			break;
		}
	}
	if(strcmp(zgs[i].num,gonghao)!=0)
	{
		printf("\n没有此工号记录");
	}
	
}
void list()
{
	char jieshu[10];
	jieshu[0]=0;
	printf("工号      姓名      岗位工资      薪级工资     职务津贴      绩效工资     应发工资      个人所得税      实发工资\n");
	for(int k=0;k<999;k++)
	{	
		printf("%s\t %s\t   %8.2f\t %8.2f     %8.2f\t    %8.2f\t  %8.2f\t   %8.2f\t     %8.2f\t\n",zgs[k].num,zgs[k].name,zgs[k].wage_gw,zgs[k].wage_xj,zgs[k].wage_zw,zgs[k].wage_jx,zgs[k].wage_yf,zgs[k].taxfee,zgs[k].wage_sf);
		if(strcmp(zgs[k+1].num,jieshu)==0) break;
	}
}
void modify()
{
	char gonghao[20];
	printf("\n请输入职工工号:");
	gets(gonghao);
	for(int i=0; i<999; i++)  
	{
		if(strcmp(zgs[i].num,gonghao)==0)
		{
			printf("请输入职工信息:\n");
			printf("工号：");
			scanf("%s",zgs[i].num);
			printf("姓名：");
			scanf("%s",zgs[i].name);
			printf("%s",zgs[i].name);
			printf("岗位工资：");
			scanf("%f",&(zgs[i].wage_gw));
			printf("薪级工资：");
			scanf("%f",&(zgs[i].wage_xj));
			printf("职务津贴：");
			scanf("%f",&(zgs[i].wage_zw));
			printf("绩效工资：");
			scanf("%f",&(zgs[i].wage_jx));
			zgs[i].wage_yf=zgs[i].wage_gw+zgs[i].wage_xj+zgs[i].wage_zw+zgs[i].wage_jx;
			grsds(i);
			zgs[i].wage_sf=zgs[i].wage_yf-zgs[i].taxfee;
			printf("已修改，注意保存！");
			//write();
			break;	
		}
	}

}
void add()
{
	FILE *fp; 
	if((fp=fopen("gz.dat","ab+"))==NULL) 
	{
	 printf("不能打开 \n"); 
	 getch();
	 exit(1); 
	} 
	int i=0;
	i=n;n++;
	printf("增加第：%d\n",n);
	printf("工号：");
	scanf("%s",zgs[i].num);
	printf("姓名：");
	scanf("%s",zgs[i].name);
	printf("岗位工资：");
	scanf("%f",&(zgs[i].wage_gw));
	printf("薪级工资：");
	scanf("%f",&(zgs[i].wage_xj));
	printf("职务津贴：");
	scanf("%f",&(zgs[i].wage_zw));
	printf("绩效工资：");
	scanf("%f",&(zgs[i].wage_jx));
	zgs[i].wage_yf=zgs[i].wage_gw+zgs[i].wage_xj+zgs[i].wage_zw+zgs[i].wage_jx;
	grsds(i);
	zgs[i].wage_sf=zgs[i].wage_yf-zgs[i].taxfee;
	//fprintf(fp,"%s %s %f %f %f %f %f %f %f\n",zgs[i].num,zgs[i].name,zgs[i].wage_gw,zgs[i].wage_xj,zgs[i].wage_zw,zgs[i].wage_jx,zgs[i].wage_yf,zgs[i].taxfee,zgs[i].wage_sf);
	printf("已增加，注意保存！");
}
void del()
{	
	char gonghao[20];
	char c1='0';
	printf("\n请输入要删除的职工编号:");
	gets(gonghao);
	for(int k=0;k<999;k++)  
	{
		if(strcmp(zgs[k].num,gonghao)==0)
		{
			printf("工号      姓名      岗位工资      薪级工资       职务津贴      绩效工资     应发工资      个人所得税      实发工资\n");
			printf("%s\t %s\t  %8.2f\t  %8.2f    %8.2f\t   %8.2f\t  %8.2f\t  %8.2f\t    %8.2f\t\n",zgs[k].num,zgs[k].name,zgs[k].wage_gw,zgs[k].wage_xj,zgs[k].wage_zw,zgs[k].wage_jx,zgs[k].wage_yf,zgs[k].taxfee,zgs[k].wage_sf);
			printf("确定要删除吗？确认按1 :");
			c1=getchar();
			getchar();
			if(c1=='1')
			{
				for(k;k<=n;k++)
				{
					zgs[k]=zgs[k+1];
				}printf("\n成功删除!\n");n--;
				
			} 	
			else 
			{
				printf("\n取消删除!\n");
			}
		}
	}
}
int grsds(int n)
{
		if(zgs[n].wage_yf<=500)
			zgs[n].taxfee=zgs[n].wage_yf*0.05;
		else if(zgs[n].wage_yf>=500&&zgs[n].wage_yf<=2000)
			zgs[n].taxfee=(zgs[n].wage_yf-500)*0.10+25;
		else if(zgs[n].wage_yf>=2000&&zgs[n].wage_yf<=5000)
			zgs[n].taxfee=(zgs[n].wage_yf-2000)*0.15+150+25;
		else if(zgs[n].wage_yf>=5000&&zgs[n].wage_yf<=20000)
			zgs[n].taxfee=(zgs[n].wage_yf-5000)*0.20+450+150+25;
		else if(zgs[n].wage_yf>=20000&&zgs[n].wage_yf<=40000)
			zgs[n].taxfee=(zgs[n].wage_yf-20000)*0.25+3000+450+150+25;
		else if(zgs[n].wage_yf>=40000&&zgs[n].wage_yf<=60000)
			zgs[n].taxfee=(zgs[n].wage_yf-40000)*0.30+5000+3000+450+150+25;
		else if(zgs[n].wage_yf>=60000&&zgs[n].wage_yf<=80000)
			zgs[n].taxfee=(zgs[n].wage_yf-60000)*0.35+6000+5000+3000+450+150+25;
		else if(zgs[n].wage_yf>=80000&&zgs[n].wage_yf<=100000)
			zgs[n].taxfee=(zgs[n].wage_yf-80000)*0.40+7000+6000+5000+3000+450+150+25;
		else if(zgs[n].wage_yf>=100000)
			zgs[n].taxfee=(zgs[n].wage_yf-100000)*0.45+8000+7000+6000+5000+3000+450+150+25;
		return 0;
}
int main()
{
	read();
	int act;
	while(1)
	{
		printf("\t\t###   欢迎使用广西民族大学软件与信息安全学院职工工资管理系统   ###\n\n");
		printf("\t\t请选择< 1 - 7 > :\n");
		printf("\t\t==================================================================\n");
		printf("\t\t|           1.查询职工工资记录                                   |\n");
		printf("\t\t|           2.修改职工工资记录                                   |\n");
		printf("\t\t|           3.添加职工工资记录                                   |\n");
		printf("\t\t|           4.删除职工工资记录                                   |\n");
		printf("\t\t|           5.保存数据到文件                                     |\n");
		printf("\t\t|           6.浏览职工工资记录                                   |\n");
		printf("\t\t|           7.退出系统                                           |\n");
		printf("\t\t==================================================================\n");
		printf("\t\t你的选择是:");break;

}
	while(1)
	{
		//read();
		scanf("%d",&act); 
		getchar(); 
		switch(act) 
		{
		case 1: find(); break; 
		case 2: modify(); break; 
		case 3: add(); break; 
		case 4: del(); break; 
		case 5: write(); break; 
		case 6: list(); break; 
		case 7: return 0; 
		default:printf("\n按键错误，请重新选择\n"); 
		} 
		printf("\n继续操作请选择< 1 - 7 > :");

	}
	//write();
	//find();
	//modify();
	//list();
	//add();
	//del();
}