#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;
#define MAX 1024                    //ȫ�̶ֹ����� MAX 1024
typedef struct{                      //����ṹ��
char word[32];
int num;
} wordlist;

wordlist wl[MAX];
int wordnum=0;

void tongji() 
{ 
	char st[32];                          //�����Ա���
	int found;
	char c;
	int i;
	int m=0,n=0,j=0,k=0; 
	FILE *fp;                             // �����ļ�ָ��
	if((fp=fopen("14220105.txt","r"))==NULL)
	exit(1);
	while(fscanf(fp,"%s",st)!=EOF)
	{
		found=0;
		for(i=0;i<wordnum;i++)
		{
			if(strcmp(wl[i].word,st)==0)    //�ַ����Ķ�ȡ
			{
				wl[i].num++;
				found=1;
				break;
			}
		}
		if(!found)
		{
			strcpy(wl[i].word,st);
			wl[i].num=1;
			wordnum++;
		}
	}
	fclose(fp);

	if((fp=fopen("14220105.txt","r"))==NULL)
	exit(1);
	while((c=fgetc(fp))!=EOF) 
	{
		if(c==' ')                          // ���ּ��ո�Ķ�ȡ
			++n;
		else if(c>='0'&&c<='9')
			++j;
		else if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
			++k;
		else ++m;
}
	fclose(fp);
	printf("��ȡ��ϣ�������£�\n");
	printf(" ���� %d\n ��ĸ %d\n �ո� %d\n ���� %d\n",j,k,n,m );// ������

}

void shuru()
{

char str[100];
char letter[52];
int count[52]={0};//��ʼ��������
int i;
int lc=0;//��¼��ĸ����
cout<<"�����ַ���:"<<endl;
scanf("%s",str);

//��ʼ����ĸ��
for(i=0;i<26;i++)
letter[i]='A'+i;
for(i=26;i<52;i++)
letter[i]='a'+i-26;

i=0;

while(str[i]!='\0')//�ַ���δ���� 
{
if(str[i]>='A' && str[i]<='Z')//    д��ĸ
{
count[str[i]-65]++;//����str[i]=='A', 'A'-65����0 count[0]����1
lc++;
}
if(str[i]>='a' && str[i]<='z')//    д��ĸ
{
count[str[i]-97+26]++;//'a'==97,ǰ��26   д �� ��26
lc++;
}
i++;
}
for(i=0;i<52;i++)//��ʾͳ�����
{
if(count[i]!=0)
printf("%c-%d-%3.2f��\n",letter[i],count[i],(float)count[i]/lc*100);
}
}
void xuanzhe()
{
 printf("1.����ͳ��\n");
 printf("2.����ͳ��\n");
 printf("0.�˳�\n");//����˳�
	printf("ѡ��������Ҫ�Ĳ�����");
}
int main()          //������
{     
	int choice;
	do 
      { xuanzhe();	
	scanf("%d",&choice);
	switch(choice)   // switch��������ѭ��ִ��
	{
	case 0:
		return 0;
	case 1:
		tongji();
		break;
	case 2:
		shuru();
		break;
	}
}while(1);
}
