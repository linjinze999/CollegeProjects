#include<time.h>
#include<iostream>
#include"greed_01bag.h"
void getBagResult(int *goods_value,int *goods_vector,int goods_number,int bag_vector,int *result)//��ȡ��ѷ���
{
	for(int i=0;i<goods_number+2;i++)//��ʼ�����
		result[i]=0;
	int *goods_per_value=new int[2*goods_number];//���棨��ֵ/�����ֵ����ţ���ŷ�������ӡ
	for(int i=0;i<goods_number;i++)
	{
		goods_per_value[i*2]=i;
		goods_per_value[i*2+1]=goods_value[i]/goods_vector[i];
	}
	InsertSort(goods_per_value,goods_number);	//���򣬲��������
	
	for(int i=0;i<goods_number;i++)
	{
		int no = goods_per_value[2*i];
		if(bag_vector>=goods_vector[no])
		{
			result[0] += goods_vector[no];
			result[1] += goods_value[no];
			result[no+2] = 1;
			bag_vector = bag_vector-goods_vector[no];
		}
	}
};

void InsertSort(int *a, int n)//�������򣬲��������
{
    for(int i= 3; i<n*2; i+=2){
        if(a[i] > a[i-2]){
            int j= i-2;
            int x = a[i];
			int no=a[i-1];
			a[i-1] = a[i-3];
            a[i] = a[i-2];
            while((j > -1) && (x > a[j])){
                a[j+2] = a[j];
				a[j+1] = a[j-1];
                j=j-2;
            }
            a[j+2] = x;
			a[j+1] = no;
        }
    }
};

void setGoodsVV(int *goods_value,int *goods_vector,int goods_number,int bag_vector)//������ɼ�ֵ�����
{
	srand((int)time(0));
	int r=rand()%100;
	for(int i=0;i<goods_number;i++)
		{
			if(r==0)
				r=59;
			goods_value[i]=r;
			r=(r*157)%bag_vector;
			if(r==0)
				r=59%bag_vector;
			goods_vector[i]=r;
			r=(r*161)%100;
		}
};