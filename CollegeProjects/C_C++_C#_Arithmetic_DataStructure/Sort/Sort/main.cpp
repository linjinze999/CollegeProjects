#include<iostream>
#include"BInsertSort.h"
#include"BubbleSort.h"
#include"HeapSort.h"
#include"InsertSort.h"
#include"MergeSort.h"
#include"QuitSort.h"
#include"SelectSort.h"
#include"ShellSort.h"
#include"List.h"
using namespace std;

void main(){
	SqList L1,L2;
	int data=12345;
	setList(L1,data);
	L2=L1;
	int choose;
	int compare,move;
	compare=move=0;
	while(true){
		cout<<"*********************************"<<endl;
		cout<<"*\t1����ӡԭʼ���ݣ�\t*"<<endl;
		cout<<"*\t2�����������㷨�Ƚϣ�\t*"<<endl;
		cout<<"*\t3�������������ݣ�\t*"<<endl;
		cout<<"*********************************"<<endl;
		cout<<"��ѡ��";
		cin>>choose;
		switch(choose){
		case 1:
			Print(L1);
			cout<<endl<<endl;
			break;
		case 2:
			cout<<"1��ֱ�Ӳ�������"<<endl;
			InsertSort(L1,compare,move);
			Print(L1);
			cout<<endl<<"�Ƚϴ�����"<<compare<<endl<<"�ƶ�������"<<move<<endl<<endl;
			L1=L2;
			compare=move=0;

			cout<<"2���۰��������"<<endl;
			BInsertSort(L1,compare,move);
			Print(L1);
			cout<<endl<<"�Ƚϴ�����"<<compare<<endl<<"�ƶ�������"<<move<<endl<<endl;
			L1=L2;
			compare=move=0;

			cout<<"3��ϣ������"<<endl;
			int a[1];
			a[0]=5;
			ShellSort(L1,a,1,compare,move);
			Print(L1);
			cout<<endl<<"�Ƚϴ�����"<<compare<<endl<<"�ƶ�������"<<move<<endl<<endl;
			L1=L2;
			compare=move=0;

			cout<<"4����������"<<endl;
			bubble_sort(L1,compare,move);
			Print(L1);
			cout<<endl<<"�Ƚϴ�����"<<compare<<endl<<"�ƶ�������"<<move<<endl<<endl;
			L1=L2;
			compare=move=0;

			cout<<"5����������"<<endl;
			QSort(L1,1,L1.length,compare,move);
			Print(L1);
			cout<<endl<<"�Ƚϴ�����"<<compare<<endl<<"�ƶ�������"<<move<<endl<<endl;
			L1=L2;
			compare=move=0;

			cout<<"6����ѡ������"<<endl;
			SelectSort(L1,compare,move);
			Print(L1);
			cout<<endl<<"�Ƚϴ�����"<<compare<<endl<<"�ƶ�������"<<move<<endl<<endl;
			L1=L2;
			compare=move=0;

			cout<<"7��������"<<endl;
			HeapSort(L1,compare,move);
			Print(L1);
			cout<<endl<<"�Ƚϴ�����"<<compare<<endl<<"�ƶ�������"<<move<<endl<<endl;
			L1=L2;
			compare=move=0;

			cout<<"8���鲢����"<<endl;
			MergeSort(L1,compare,move);
			Print(L1);
			cout<<endl<<"�Ƚϴ�����"<<compare<<endl<<"�ƶ�������"<<move<<endl<<endl;
			L1=L2;
			compare=move=0;

			break;
		case 3:
			setList(L1,data);
			L2=L1;
			cout<<"���ɳɹ���"<<"���������£�"<<endl;
			Print(L1);
			cout<<endl<<endl;
			break;
		default:
			break;
		}
	}
}



  