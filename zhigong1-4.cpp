
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
void read()    //��ȡְ����������
{
	 FILE *fp;
     zg=zgs;
     if((fp=fopen("gz.dat","rb+"))==NULL)
     {
          printf("���ܴ��ļ�\n");
		  getch();
          exit(-1);
     }
	 rewind(fp);
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

	 //printf("%s\n",zgs[6].num );
	 fclose(fp);
	 printf("����������Ϊ��%d\n",n);
}
void write()
{
	FILE *fp; 
 if((fp=fopen("gz.dat","rb"))==NULL) 
 {
	 printf("���ܴ� \n"); 
	 getch();
	 exit(-1); 
 } 
 rewind(fp);
 for(int i=0;i<n;i++)
 {
	 fwrite(&zgs[i],sizeof(struct zggz),1,fp);
 }
 printf("�ɹ�\n");
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
			printf("��");
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
		printf("����   ����   ��λ����  н������   ְ�����   ��Ч����  Ӧ������  ��������˰   ʵ������\n");
	for(int i=0;i<999;i++,zg++)
	{	
		printf("%s %s %f %f %f %f %f %f %f\n",zg->num,zg->name,zg->wage_gw,zg->wage_xj,zg->wage_zw,zg->wage_jx,zg->wage_yf,zg->taxfee,zg->wage_sf);
		if(strcmp(zgs[i+1].num,jieshu)==0) break;
	}
}
void modify()
{
	
	char gonghao[20];
	printf("\n������ְ�����:");
	//zg=zgs;
	gets(gonghao);
	for(int i=0; i<999; i++,zg++)  
	{
		if(strcmp(zgs[i].num,gonghao)==0)
		{
			printf("������ְ����Ϣ:\n");
			//scanf("%s %s %f %f %f %f %f %f %f\n",zg->num,zg->name,&(zg->wage_gw),&(zg->wage_xj),&(zg->wage_zw),&(zg->wage_jx),&(zg->wage_yf),&(zg->taxfee),&(zg->wage_sf));
			printf("���ţ�");
			scanf("%s",zg->num);
			printf("������");
			scanf("%s",zg->name);
			printf("��λ���ʣ�");
			scanf("%f",&(zg->wage_gw));
			printf("н�����ʣ�");
			scanf("%f",&(zg->wage_xj));
			printf("ְ�������");
			scanf("%f",&(zg->wage_zw));
			printf("��Ч���ʣ�");
			scanf("%f",&(zg->wage_jx));
			printf("Ӧ�����ʣ�");
			scanf("%f",&(zg->wage_yf));
			printf("��������˰��");
			scanf("%f",&(zg->taxfee));
			printf("ʵ�����ʣ�");
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
	 printf("���ܴ� \n"); 
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