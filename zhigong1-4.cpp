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
void read()    //��ȡְ����������
{
	 FILE *fp;
     if((fp=fopen("gz.dat","rb"))==NULL)
     {
          printf("���ܴ��ļ�\n");
		  getch();
          exit(1);
     }
	 //rewind(fp);
	 for(int i=0; i<999; i++)  //�жϼ�������
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
	 printf("����������Ϊ��%d\n",n);
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
		//fwrite(&zgs[i],sizeof(struct zggz),1,fp);
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
	printf("����      ����      ��λ����      н������       ְ�����      ��Ч����     Ӧ������      ��������˰      ʵ������\n");
	for(int i=0;i<999;i++)
	{	
		printf("%s\t %s\t %8.2f\t  %8.2f  %8.2f\t %8.2f\t  %8.2f\t   %8.2f\t  %8.2f\t\n",zgs[i].num,zgs[i].name,zgs[i].wage_gw,zgs[i].wage_xj,zgs[i].wage_zw,zgs[i].wage_jx,zgs[i].wage_yf,zgs[i].taxfee,zgs[i].wage_sf);
		if(strcmp(zgs[i+1].num,jieshu)==0) break;
	}
}
void modify()
{
	char gonghao[20];
	printf("\n������ְ�����:");
	//zg=zgs;
	gets(gonghao);
	for(int i=0; i<999; i++)  
	{
		if(strcmp(zgs[i].num,gonghao)==0)
		{
			printf("������ְ����Ϣ:\n");
			//scanf("%s %s %f %f %f %f %f %f %f\n",zg->num,zg->name,&(zg->wage_gw),&(zg->wage_xj),&(zg->wage_zw),&(zg->wage_jx),&(zg->wage_yf),&(zg->taxfee),&(zg->wage_sf));
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
			printf("Ӧ�����ʣ�");
			scanf("%f",&(zgs[i].wage_yf));
			printf("��������˰��");
			scanf("%f",&(zgs[i].taxfee));
			printf("ʵ�����ʣ�");
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
	 printf("���ܴ� \n"); 
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
	/*printf("Ӧ�����ʣ�");
	scanf("%f",&(zgs[n].wage_yf));*/
	zgs[n].wage_yf=zgs[n].wage_gw+zgs[n].wage_xj+zgs[n].wage_zw+zgs[n].wage_jx;
	printf("��������˰��");
	scanf("%f",&(zgs[n].taxfee));
	printf("ʵ�����ʣ�");
	scanf("%f",&(zgs[n].wage_sf));
	//fwrite(&zgs[2],sizeof(struct zggz),1,fp);
	fprintf(fp,"%s %s %f %f %f %f %f %f %f",zgs[n].num,zgs[n].name,zgs[n].wage_gw,zgs[n].wage_xj,zgs[n].wage_zw,zgs[n].wage_jx,zgs[n].wage_yf,zgs[n].taxfee,zgs[n].wage_sf);
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
			printf("%s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n",zgs[i].num,zgs[i].name,zgs[i].wage_gw,zgs[i].wage_xj,zgs[i].wage_zw,zgs[i].wage_jx,zgs[i].wage_yf,zgs[i].taxfee,zgs[i].wage_sf);
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