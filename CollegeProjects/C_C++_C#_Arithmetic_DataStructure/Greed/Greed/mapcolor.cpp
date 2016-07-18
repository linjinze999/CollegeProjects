#include"mapcolor.h"
#include<iostream>
#include<vector>
#include<time.h>
bool MapColor(int number,int *map,int *result,int count,int color,int max_color)//��ɫͼ
{
	bool can=false;
	for(int n=0;n<number;n++)
		result[n]=-1;
	for(int i=0;i<max_color;i++){//����������ɫ
		for(int j=0;j<number;j++){//�������ж���
			if(result[j]==-1){//����δ��ɫ
				can=true;
				for(int n=0;n<number;n++)//����Ƿ��ͻ
					if(map[j*number+n]==1){
						if(result[n]==i){
							can=false;
							break;
						}
					}
				if(can)
					result[j]=i;
			}
		}
	}
	for(int n=0;n<number;n++)
		if(result[n]==-1)
			return false;
	return true;
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