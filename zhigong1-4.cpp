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
void read()    //��ȡְ����������
{
	 FILE *fp;
     if((fp=fopen("gz.dat","rb"))==NULL)
     {
          printf("���ܴ��ļ�\n");
		  getch();
          exit(1);
     }
	 for(int i=0; i<999; i++)  //�жϼ�������
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
	 //printf("����������Ϊ��%d\n",n);
}
void write()
{
	FILE *fp; 
	if((fp=fopen("gz.dat","wb+"))==NULL) 
	{
	 printf("���ܴ� \n"); 
	 getch();
	 exit(1); 
	} 
	rewind(fp);
	for(int i=0;i<n;i++)
	{
		fprintf(fp,"%s %s %f %f %f %f %f %f %f\n",zgs[i].num,zgs[i].name,zgs[i].wage_gw,zgs[i].wage_xj,zgs[i].wage_zw,zgs[i].wage_jx,zgs[i].wage_yf,zgs[i].taxfee,zgs[i].wage_sf);
	}
	printf("�ɹ�����\n");
	fclose(fp); 
}
void find()
{
	char gonghao[20];
	printf("\n������ְ�����:");
	gets(gonghao);
	for(int i=0; i<999; i++)  
	{
		if(strcmp(zgs[i].num,gonghao)==0)
		{
			printf("����      ����      ��λ����      н������       ְ�����      ��Ч����     Ӧ������      ��������˰      ʵ������\n");
			printf("%s\t %s\t %8.2f\t  %8.2f     %8.2f\t    %8.2f\t  %8.2f\t   %8.2f\t     %8.2f\t\n",zgs[i].num,zgs[i].name,zgs[i].wage_gw,zgs[i].wage_xj,zgs[i].wage_zw,zgs[i].wage_jx,zgs[i].wage_yf,zgs[i].taxfee,zgs[i].wage_sf);
			getch();
			break;	
		}
	

	}
}
void list()
{
	char jieshu[10];
	jieshu[0]=0;
	printf("����      ����      ��λ����      н������       ְ�����      ��Ч����     Ӧ������      ��������˰      ʵ������\n");
	for(int i=0;i<999;i++)
	{	
		printf("%s\t %s\t %8.2f\t  %8.2f     %8.2f\t    %8.2f\t  %8.2f\t   %8.2f\t     %8.2f\t\n",zgs[i].num,zgs[i].name,zgs[i].wage_gw,zgs[i].wage_xj,zgs[i].wage_zw,zgs[i].wage_jx,zgs[i].wage_yf,zgs[i].taxfee,zgs[i].wage_sf);
		if(strcmp(zgs[i+1].num,jieshu)==0) break;
	}
}
void modify()
{
	char gonghao[20];
	printf("\n������ְ�����:");
	gets(gonghao);
	for(int i=0; i<999; i++)  
	{
		if(strcmp(zgs[i].num,gonghao)==0)
		{
			printf("������ְ����Ϣ:\n");
			printf("���ţ�");
			scanf("%s",zgs[i].num);
			printf("������");
			scanf("%s",zgs[i].name);
			printf("%s",zgs[i].name);
			printf("��λ���ʣ�");
			scanf("%f",&(zgs[i].wage_gw));
			printf("н�����ʣ�");
			scanf("%f",&(zgs[i].wage_xj));
			printf("ְ�������");
			scanf("%f",&(zgs[i].wage_zw));
			printf("��Ч���ʣ�");
			scanf("%f",&(zgs[i].wage_jx));
			zgs[i].wage_yf=zgs[i].wage_gw+zgs[i].wage_xj+zgs[i].wage_zw+zgs[i].wage_jx;
			grsds(i);
			zgs[i].wage_sf=zgs[i].wage_yf-zgs[i].taxfee;
			getch();write();
			break;	
		}
	}

}
void add()
{
	FILE *fp; 
	if((fp=fopen("gz.dat","ab+"))==NULL) 
	{
	 printf("���ܴ� \n"); 
	 getch();
	 exit(1); 
	} 
	n=n+1;
	printf("���ӵڣ�%d\n",n);
	printf("���ţ�");
	scanf("%s",zgs[n].num);
	printf("������");
	scanf("%s",zgs[n].name);
	printf("��λ���ʣ�");
	scanf("%f",&(zgs[n].wage_gw));
	printf("н�����ʣ�");
	scanf("%f",&(zgs[n].wage_xj));
	printf("ְ�������");
	scanf("%f",&(zgs[n].wage_zw));
	printf("��Ч���ʣ�");
	scanf("%f",&(zgs[n].wage_jx));
	zgs[n].wage_yf=zgs[n].wage_gw+zgs[n].wage_xj+zgs[n].wage_zw+zgs[n].wage_jx;
	grsds(n);
	zgs[n].wage_sf=zgs[n].wage_yf-zgs[n].taxfee;
	fprintf(fp,"%s %s %f %f %f %f %f %f %f\n",zgs[n].num,zgs[n].name,zgs[n].wage_gw,zgs[n].wage_xj,zgs[n].wage_zw,zgs[n].wage_jx,zgs[n].wage_yf,zgs[n].taxfee,zgs[n].wage_sf);
}
void del()
{	
	char gonghao[20];
	char c1='0';
	printf("\n������Ҫɾ����ְ�����:");
	gets(gonghao);
	for(int i=0; i<999; i++)  
	{
		if(strcmp(zgs[i].num,gonghao)==0)
		{
			printf("����      ����      ��λ����      н������       ְ�����      ��Ч����     Ӧ������      ��������˰      ʵ������\n");
			printf("%s\t %s\t %8.2f\t  %8.2f     %8.2f\t    %8.2f\t  %8.2f\t   %8.2f\t     %8.2f\t\n",zgs[i].num,zgs[i].name,zgs[i].wage_gw,zgs[i].wage_xj,zgs[i].wage_zw,zgs[i].wage_jx,zgs[i].wage_yf,zgs[i].taxfee,zgs[i].wage_sf);
			printf("ȷ��Ҫɾ����ȷ�ϰ�1 :");
			c1=getchar();
			getchar();
			if(c1=='1')
			{
				for(i;i<=n;i++)
				{
					zgs[i]=zgs[i+1];
				}printf("\n�ɹ�ɾ��!\n");n--;write();
				
			} 	
			else 
			{
				printf("\nȡ��ɾ��!\n");
			}
		}
	}
}
int grsds(int n)
{
		if(zgs[n].wage_yf<=500)
			zgs[n].taxfee=zgs[n].wage_yf*0.05;
		else if(zgs[n].wage_yf>=500&&zgs[n].wage_yf<=2000)
			zgs[n].taxfee=zgs[n].wage_yf*0.1;
		else if(zgs[n].wage_yf>=2000&&zgs[n].wage_yf<=5000)
			zgs[n].taxfee=zgs[n].wage_yf*0.15;
		else if(zgs[n].wage_yf>=5000&&zgs[n].wage_yf<=20000)
			zgs[n].taxfee=zgs[n].wage_yf*0.2;
		else if(zgs[n].wage_yf>=20000&&zgs[n].wage_yf<=40000)
			zgs[n].taxfee=zgs[n].wage_yf*0.25;
		else if(zgs[n].wage_yf>=40000&&zgs[n].wage_yf<=60000)
			zgs[n].taxfee=zgs[n].wage_yf*0.30;
		else if(zgs[n].wage_yf>=60000&&zgs[n].wage_yf<=80000)
			zgs[n].taxfee=zgs[n].wage_yf*0.35;
		else if(zgs[n].wage_yf>=80000&&zgs[n].wage_yf<=100000)
			zgs[n].taxfee=zgs[n].wage_yf*0.40;
		else if(zgs[n].wage_yf>=100000)
			zgs[n].taxfee=zgs[n].wage_yf*0.45;
		return 0;
}
int main()
{
	read();
	int act;
	while(1)
	{
		printf("\t\t###   ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ   ###\n\n");
		printf("\t\t��ѡ��< 1 - 7 > :\n");
		printf("\t\t==================================================================\n");
		printf("\t\t|           1.��ѯְ�����ʼ�¼                                   |\n");
		printf("\t\t|           2.�޸�ְ�����ʼ�¼                                   |\n");
		printf("\t\t|           3.���ְ�����ʼ�¼                                   |\n");
		printf("\t\t|           4.ɾ��ְ�����ʼ�¼                                   |\n");
		printf("\t\t|           5.�������ݵ��ļ�                                     |\n");
		printf("\t\t|           6.���ְ�����ʼ�¼                                   |\n");
		printf("\t\t|           7.�˳�ϵͳ                                           |\n");
		printf("\t\t==================================================================\n");
		printf("\t\t���ѡ����:");break;

	}
	while(1)
	{
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
		default:printf("\n��������������ѡ��\n"); 
		} 
		printf("\n����������");

	}
	//write();
	//find();
	//modify();
	//list();
	//add();
	//del();
}