
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct zggz{
	char num[20];    //工号
	char name[20];   //姓名
	float wage_gw;   //岗位工资
	float wage_xj;   //薪级工资
	float wage_zw;   //职务津贴
	float wage_jx;   //绩效工资
	float wage_yf;   //应发工资
	float taxfee;    //个人所得税
	float wage_sf;   //实发工资
}zgs[999];           //结构体定义
	int n=0;         //用以记录数据条数
	int grsds(int n);//个人所得税计算函数声明
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void read()    //读取职工工资数据
{
	 FILE *fp;
     if((fp=fopen("gz.dat","rb"))==NULL)
     {
          printf("不能打开文件\n");
		  getch();
          exit(1);
     }
	 for(int i=0; i<999; i++)    //判断几条数据
	 {  
		 fscanf(fp,"%s %s %f %f %f %f %f %f %f\n",zgs[i].num,zgs[i].name,&(zgs[i].wage_gw),&(zgs[i].wage_xj),&(zgs[i].wage_zw),&(zgs[i].wage_jx),&(zgs[i].wage_yf),&(zgs[i].taxfee),&(zgs[i].wage_sf));
		 n++;    //读取一条数据n+1
		 if(feof(fp))
		 {
		   break;
		 }
	 }
	 fclose(fp);
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void write()    //保存职工工资数据
{
	FILE *fp; 
	if((fp=fopen("gz.dat","wb+"))==NULL) 
	{
	 printf("不能打开 \n"); 
	 getch();
	 exit(1); 
	} 
	rewind(fp);
	for(int i=0;i<n;i++)//逐条读取逐条保存
	{
		fprintf(fp,"%s %s %f %f %f %f %f %f %f\n",zgs[i].num,zgs[i].name,zgs[i].wage_gw,zgs[i].wage_xj,zgs[i].wage_zw,zgs[i].wage_jx,zgs[i].wage_yf,zgs[i].taxfee,zgs[i].wage_sf);
	}
	printf("成功保存\n");
	fclose(fp); 
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void find()    //查询职工工资数据
{
	char gonghao[20];    //定义查询用的字符数组
	printf("\n请输入职工编号:");
	gets(gonghao);    //接收查询用的字符数组（工号）
	for(int i=0; i<999; i++)    //逐条对比数据
	{
		if(strcmp(zgs[i].num,gonghao)==0)    //工号相符则输出
		{
			printf("工号      姓名     岗位工资      薪级工资     职务津贴      绩效工资     应发工资      个人所得税      实发工资\n");
			printf("%s\t %s\t   %8.2f\t %8.2f     %8.2f\t    %8.2f\t  %8.2f\t %8.2f\t    %8.2f\t\n",zgs[i].num,zgs[i].name,zgs[i].wage_gw,zgs[i].wage_xj,zgs[i].wage_zw,zgs[i].wage_jx,zgs[i].wage_yf,zgs[i].taxfee,zgs[i].wage_sf);
			break;
		}
	}
	if(strcmp(zgs[i].num,gonghao)!=0)    //工号不相符则报错
	{
		printf("\n没有此工号记录");
	}
	
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void list()    //浏览职工工资数据
{
	char jieshu[10];    //定义结束字符数组作为读取停止标志
	jieshu[0]=0;    //读取停止标志赋控空值
	printf("工号      姓名      岗位工资      薪级工资     职务津贴      绩效工资     应发工资      个人所得税      实发工资\n");
	for(int k=0;k<999;k++)
	{	
		printf("%s\t %s\t   %8.2f\t %8.2f     %8.2f\t    %8.2f\t  %8.2f\t   %8.2f\t     %8.2f\t\n",zgs[k].num,zgs[k].name,zgs[k].wage_gw,zgs[k].wage_xj,zgs[k].wage_zw,zgs[k].wage_jx,zgs[k].wage_yf,zgs[k].taxfee,zgs[k].wage_sf);
		if(strcmp(zgs[k+1].num,jieshu)==0) break;    //工号为空时则停止读取
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void modify()    //修改职工工资数据
{
	char gonghao[20];    //定义查询用的字符数组
	printf("\n请输入要修改的职工工号:");
	gets(gonghao);    //接收查询用的字符数组
	for(int i=0; i<999; i++)    //逐条对比数据
	{
		if(strcmp(zgs[i].num,gonghao)==0)    //若工号与查询字符数组相同则执行修改操作
		{
			printf("请输入修改后的职工信息:\n");    //逐项修改结构体数组属性
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
			grsds(i);    //调用个人所得税函数计算个人所得税
			zgs[i].wage_sf=zgs[i].wage_yf-zgs[i].taxfee;
			printf("已修改，注意保存！");
			break;	
		}
	}
	if(strcmp(zgs[i].num,gonghao)!=0)    //工号不相符则报错
	{
		printf("\n没有此工号记录");
	}

}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void add()    //增加职工工资数据
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
	printf("增加第：%d\n",n);    //逐项给第n条结构体数组中的属性赋值
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
	grsds(i);    //调用个人所得税函数计算个人所得税
	zgs[i].wage_sf=zgs[i].wage_yf-zgs[i].taxfee;
	printf("已增加，注意保存！");
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void del()    //删除职工工资数据
{	
	char gonghao[20];    //定义查询用的字符数组
	char c1='0';    //删除标志置0
	printf("\n请输入要删除的职工编号:");
	gets(gonghao);    //接收查询用的字符数组
	for(int k=0;k<999;k++)    //逐条对比数据
	{
		if(strcmp(zgs[k].num,gonghao)==0)    //若工号与查询字符数组相同则执行删除操作
		{
			printf("工号      姓名      岗位工资      薪级工资       职务津贴      绩效工资     应发工资      个人所得税      实发工资\n");
			printf("%s\t %s\t  %8.2f\t  %8.2f    %8.2f\t   %8.2f\t  %8.2f\t  %8.2f\t    %8.2f\t\n",zgs[k].num,zgs[k].name,zgs[k].wage_gw,zgs[k].wage_xj,zgs[k].wage_zw,zgs[k].wage_jx,zgs[k].wage_yf,zgs[k].taxfee,zgs[k].wage_sf);
			printf("确定要删除吗？确认按1 :");
			c1=getchar();
			getchar();
			if(c1=='1')    //删除标志置1
			{
				for(k;k<=n;k++)
				{
					zgs[k]=zgs[k+1];    //该数据后的数据逐条向前替代达到删除效果
				}printf("\n成功删除!\n");n--;
				
			} 	
			else 
			{
				printf("\n取消删除!\n");
			}
		}
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int grsds(int n)    //计算个人所得税
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
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main()    //主函数
{
	read();    //读取文件中的数据
	int act;    //定义选择按钮
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
		scanf("%d",&act);    //接收选择按钮 
		getchar(); 
		switch(act)    //根据选择按钮调用函数模块
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
}