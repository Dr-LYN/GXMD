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
	void saveone(int i);
void read()    //读取职工工资数据
{
	 FILE *fp;
     if((fp=fopen("gz.dat","rb"))==NULL)
     {
          printf("不能打开文件\n");
		  getch();
          exit(1);
     }
	 //rewind(fp);
	 for(int i=0; i<999; i++)  //判断几条数据
	 {  
		 fscanf(fp,"%s %s %f %f %f %f %f %f %f\n",zgs[i].num,zgs[i].name,&(zgs[i].wage_gw),&(zgs[i].wage_xj),&(zgs[i].wage_zw),&(zgs[i].wage_jx),&(zgs[i].wage_yf),&(zgs[i].taxfee),&(zgs[i].wage_sf));
		 printf("%s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n",zgs[i].num,zgs[i].name,zgs[i].wage_gw,zgs[i].wage_xj,zgs[i].wage_zw,zgs[i].wage_jx,zgs[i].wage_yf,zgs[i].taxfee,zgs[i].wage_sf);
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
		//fwrite(&zgs[i],sizeof(struct zggz),1,fp);
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
			printf("%s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n",zgs[i].num,zgs[i].name,zgs[i].wage_gw,zgs[i].wage_xj,zgs[i].wage_zw,zgs[i].wage_jx,zgs[i].wage_yf,zgs[i].taxfee,zgs[i].wage_sf);
			getch();
			break;	
		}
	

	}
}
void list()
{
	char jieshu[10];
	jieshu[0]=0;
	printf("工号      姓名      岗位工资      薪级工资       职务津贴      绩效工资     应发工资      个人所得税      实发工资\n");
	for(int i=0;i<999;i++)
	{	
		printf("%s\t %s\t %8.2f\t  %8.2f  %8.2f\t %8.2f\t  %8.2f\t   %8.2f\t  %8.2f\t\n",zgs[i].num,zgs[i].name,zgs[i].wage_gw,zgs[i].wage_xj,zgs[i].wage_zw,zgs[i].wage_jx,zgs[i].wage_yf,zgs[i].taxfee,zgs[i].wage_sf);
		if(strcmp(zgs[i+1].num,jieshu)==0) break;
	}
}
void modify()
{
	char gonghao[20];
	printf("\n请输入职工编号:");
	//zg=zgs;
	gets(gonghao);
	for(int i=0; i<999; i++)  
	{
		if(strcmp(zgs[i].num,gonghao)==0)
		{
			printf("请输入职工信息:\n");
			//scanf("%s %s %f %f %f %f %f %f %f\n",zg->num,zg->name,&(zg->wage_gw),&(zg->wage_xj),&(zg->wage_zw),&(zg->wage_jx),&(zg->wage_yf),&(zg->taxfee),&(zg->wage_sf));
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
			printf("应发工资：");
			scanf("%f",&(zgs[i].wage_yf));
			printf("个人所得税：");
			scanf("%f",&(zgs[i].taxfee));
			printf("实发工资：");
			scanf("%f",&(zgs[i].wage_sf));
			getch();write();
			break;	
		}
	}

}

/*void saveone(int i)
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
}*/
void add()
{
	FILE *fp; 
	if((fp=fopen("gz.dat","ab+"))==NULL) 
	{
	 printf("不能打开 \n"); 
	 getch();
	 exit(1); 
	} 
	n=n+1;
	printf("增加第：%d\n",n);
	printf("工号：");
	scanf("%s",zgs[n].num);
	printf("姓名：");
	scanf("%s",zgs[n].name);
	printf("岗位工资：");
	scanf("%f",&(zgs[n].wage_gw));
	printf("薪级工资：");
	scanf("%f",&(zgs[n].wage_xj));
	printf("职务津贴：");
	scanf("%f",&(zgs[n].wage_zw));
	printf("绩效工资：");
	scanf("%f",&(zgs[n].wage_jx));
	/*printf("应发工资：");
	scanf("%f",&(zgs[n].wage_yf));*/
	zgs[n].wage_yf=zgs[n].wage_gw+zgs[n].wage_xj+zgs[n].wage_zw+zgs[n].wage_jx;
	printf("个人所得税：");
	scanf("%f",&(zgs[n].taxfee));
	printf("实发工资：");
	scanf("%f",&(zgs[n].wage_sf));
	//fwrite(&zgs[2],sizeof(struct zggz),1,fp);
	fprintf(fp,"%s %s %f %f %f %f %f %f %f",zgs[n].num,zgs[n].name,zgs[n].wage_gw,zgs[n].wage_xj,zgs[n].wage_zw,zgs[n].wage_jx,zgs[n].wage_yf,zgs[n].taxfee,zgs[n].wage_sf);
}
void del()
{	
	char gonghao[20];
	char c1='0';
	printf("\n请输入要删除的职工编号:");
	gets(gonghao);
	for(int i=0; i<999; i++)  
	{
		if(strcmp(zgs[i].num,gonghao)==0)
		{
			printf("%s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n",zgs[i].num,zgs[i].name,zgs[i].wage_gw,zgs[i].wage_xj,zgs[i].wage_zw,zgs[i].wage_jx,zgs[i].wage_yf,zgs[i].taxfee,zgs[i].wage_sf);
			printf("确定要删除吗？确认按1 :");
			c1=getchar();
			getchar();
			if(c1=='1')
			{
				for(i;i<=n;i++)
				{
					zgs[i]=zgs[i+1];
				}printf("\n成功删除!\n");n--;write();
				
			} 	
			else 
			{
				printf("\n取消删除!\n");
			}
		}
	}
}
int main()
{
	read();
	//write();
	//find();
	//modify();
	list();
	//add();
	//del();
	//grsds()
	return 0;
}