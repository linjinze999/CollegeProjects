#pragma once
#include<iostream>
using namespace std;

typedef  struct {
	int  key;        //��ʾ����ؼ���
	int   otherinfo; //�����¼�е�����������
}  Snode;  

typedef  struct { 
	Snode R[101]; //��Ŵ�����ȫ���¼
	int  length;  //�����¼����
} SqList; 

void setList(SqList &L,int &num);

void Print(SqList L);
