#include"marry.h"
#include<stdlib.h>
#include<time.h>
int isWomenAgree(int WhichMan,int WhichWoman,int *WomenMark[],int MenMarry[],int WomenMarry[])//ƥ���Ƿ�ɹ�
{
	if(WomenMarry[WhichWoman]==-1)//Ů���޶���
	{
		WomenMarry[WhichWoman]=WhichMan;
		MenMarry[WhichMan]=WhichWoman;
		return -1;
	}
	else
	{
		if(WomenMark[WhichWoman][WomenMarry[WhichWoman]]>=WomenMark[WhichWoman][WhichMan])//���ֵ��ڸ�Ů�����ж���
			return -2;
		else//���ָ��ڸ�Ů�����ж���
		{
			int lost=WomenMarry[WhichWoman];
			WomenMarry[WhichWoman]=WhichMan;
			MenMarry[WhichMan]=WhichWoman;
			MenMarry[lost]=-1;
			return lost;//���ر���̭���˱��
		}
	}

};

int whoIsManWant(int *MenMark[],int rank,int population,int WhichMan)//��ø�����������
{
	int *MarkSort = new int[population];
	int *WomenSort = new int[population];
	for(int i=0;i<population;i++)
		MarkSort[i]=MenMark[WhichMan][i];
	for(int n=0;n<population;n++)
	{
		int max=0;
		int count;
		for(int m=n;m<population;m++)
			if(MarkSort[m]>max)
				max=MarkSort[m];
		for(int m=n;m<population;m++)
			if(MarkSort[m]==max)
			{
				WomenSort[n]=m;
				int temp=MarkSort[n];
				MarkSort[n]=MarkSort[m];
				MarkSort[m]=temp;
				break;
			}		
	}
	return WomenSort[rank];
};

void ManSearch(int *MenMark[],int *WomenMark[],int population,int MenMarry[],int WomenMarry[],int WhichMan,int ManRank[])//��ʼ���
{
	int WhichWoman=whoIsManWant(MenMark,ManRank[WhichMan],population,WhichMan);
	int result=isWomenAgree(WhichMan,WhichWoman,WomenMark,MenMarry,WomenMarry);
	if(result==-2)//ƥ��ʧ�ܣ�����ƥ��
	{
		ManRank[WhichMan]++;
		ManSearch(MenMark,WomenMark,population,MenMarry,WomenMarry,WhichMan,ManRank);
	}
	else if(result==-1)//ƥ��ɹ����Ҹ�Ů��ԭ���޶���
	{
		return;
	}
	else//ƥ��ɹ�����Ů��ԭ���ж���Ϊ��̭����������ƥ��
	{
		ManSearch(MenMark,WomenMark,population,MenMarry,WomenMarry,result,ManRank);
	}
};

void setMark(int *MenMark[],int *WomenMark[],int population)//������ɺøж�
{
	srand((int)time(0));
	int r=rand()%100;
	for(int i=0;i<population;i++)
		for(int n=0;n<population;n++)
		{
			MenMark[i][n]=r;
			r=(r*157)%100;
			WomenMark[i][n]=r;
			r=(r*127)%100;
		}
};

void marry(int *MenMark[],int *WomenMark[],int population,int MenMarry[],int WomenMarry[])//ƥ����
{
	setMark(MenMark,WomenMark,population);
	int *ManRank = new int[population];
	for(int i=0;i<population;i++)
		ManRank[i]=0;
	for(int i=0;i<population;i++)
		ManSearch(MenMark,WomenMark,population,MenMarry,WomenMarry,i,ManRank);
	
}