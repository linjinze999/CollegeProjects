#include"MapColor.h"
#include<iostream>
#include<vector>
#include<time.h>
bool MapColor(int number,int *map,int *result,int count,int color,int max_color)//���ݷ��ݹ�������ɫͼ
{
	for(int n=0;n<number;n++)//ƥ����ɫ
	{
		if(map[count*number+n]==1)
			if(color==result[n]){
				color++;
				n=-1;
			}
	}
	if(color>max_color)//��ɫֵӦ��С�ڵ��������ɫ��
		return false;
	else{
		result[count]=color;
		if(count>=number)//Ҷ�ڵ�
			return true;
		if(MapColor(number,map,result,count+1,1,max_color))//��һ�ڵ�ɹ�
			return true;
		else
			return MapColor(number,map,result,count,color+1,max_color);//��һ�ڵ�ʧ�ܣ�����
	}
};


void setMap(int count,int *map)//�����������ͼ
{
	srand((int)time(0));
	int r=rand()%100;
	for(int i=0;i<count;i++)
		for(int n=0;n<count;n++){
			if(n==i)
				map[i*count+n]=0;
			else if(n>i){
				map[i*count+n]=r%2;
				map[n*count+i]=r%2;
				r=((r+1)*157)%100;
			}
		}
};