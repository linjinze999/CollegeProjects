#include<iostream>
#include<stdlib.h>
#include<math.h>
#include"bag.h"
#include"marry.h"

using namespace std;


void main()
{
	int menu=0;
	int POPULATION=0;//����ƥ�����
	int NUMBER=0;//0/1������Ʒ����
	int VECTOR=0;//0/1����������
	while(true){
		system("cls");
		cout<<"*****************������***************"<<endl;
		cout<<"**** 1��0/1�������⣻             ****"<<endl;
		cout<<"**** 2������ƥ���㷨��            ****"<<endl;
		cout<<"**************************************"<<endl;
		cout<<"��ѡ�񷽰���";
		cin>>menu;
		switch(menu)
		{
		case 1:/*-------------------0/1��������-------------------*/
			{
				char way='0';
				system("cls");
				cout<<"*****************0/1��������****************"<<endl;
				cout<<"��������Ʒ������";
				cin>>NUMBER;
				cout<<"�����뱳�������";
				cin>>VECTOR;

				cout<<endl<<"*****************������ӷ�ʽ***************"<<endl;
				cout<<"****  1��������ɣ�                     ****"<<endl;
				cout<<"****  2���ֶ����롣                     ****"<<endl;
				cout<<"********************************************"<<endl;
				cout<<"��ѡ��";
				cin>>way;
				
				int **allbag=new int*[NUMBER+2];//��¼�������
				int *bag=new int[NUMBER+2];//��¼���
				int *vector=new int[NUMBER];//��¼��Ʒ���
				int *value=new int[NUMBER];//��¼��Ʒ��ֵ
				int count=0;
				int *goods=new int[NUMBER];//����

				if(way=='1')//�����������
					setVV(value,vector,NUMBER,VECTOR);
				else//�ֶ���������
					for(int i=0;i<NUMBER;i++)
					{
						cout<<"�������"<<i+1<<"����Ʒ��ֵ��";
						cin>>value[i];
						cout<<"�������"<<i+1<<"����Ʒ�����";
						cin>>vector[i];
					}

				system("cls");
				for(int n=0;n<pow((double)2,NUMBER);n++)//�������
				{
					int dtb=n;
					for(int i=0;i<NUMBER;i++)
					{
						goods[i]=dtb % 2;
						dtb=dtb / 2;
					}
					allbag[count]=(int*)malloc((NUMBER+2)*sizeof(int));
					getVV(allbag,value,vector,count,goods,NUMBER);
					count++;	
				}
				cout<<"***************  0/1��������  **************"<<endl;
				cout<<"**  ��Ʒ��ֵ��";
				for(int i=0;i<NUMBER;i++)
					cout<<value[i]<<"  ";
				cout<<endl<<"**  ��Ʒ�����";
				for(int i=0;i<NUMBER;i++)
					cout<<vector[i]<<"   ";
				cout<<endl<<"**  ���������"<<VECTOR;
				result(allbag,bag,count,VECTOR,NUMBER);//���ս��
				cout<<endl<<"********************************************"<<endl;
				cout<<"**  ��߼�ֵ��"<<bag[1]<<endl<<"**  ��ʱ�����"<<bag[0]<<endl;
				cout<<"**  ������";
				for(int i=0;i<NUMBER;i++)
					cout<<bag[i+2]<<" ";
				cout<<"��1Ϊѡ�У�0Ϊ��ѡ��"<<endl;
				cout<<"********************************************"<<endl;
				cout<<endl;
				system("pause");
				break;
			}
		case 2:/*-------------------����ƥ������-------------------*/
			{
				system("cls");
				cout<<"**************����ƥ���㷨************"<<endl;
				cout<<"������ƥ�������";
				cin>>POPULATION;
				int **MenMark=new int*[POPULATION];//��¼������Ů����ӡ���	
				int **WomenMark=new int*[POPULATION];//��¼Ů����������ӡ���
				for(int n=0;n<POPULATION;n++)
				{
					MenMark[n]=(int*)malloc(POPULATION*sizeof(int));
					WomenMark[n]=(int*)malloc(POPULATION*sizeof(int));
				}
				int *MenMarry=new int[POPULATION];//��¼�����Ķ���
				int *WomenMarry=new int[POPULATION];//��¼Ů���Ķ���
				for(int i=0;i<POPULATION;i++)
				{
					MenMarry[i]=-1;
					WomenMarry[i]=-1;
				}

				marry(MenMark,WomenMark,POPULATION,MenMarry,WomenMarry);//�õ����
				cout<<endl<<"************������Ů������************"<<endl<<"      ";
				for(int i=0;i<POPULATION;i++)
					cout<<"Ů��"<<i+1<<" ";
				cout<<endl;
				for(int i=0;i<POPULATION;i++)
				{
					cout<<"����"<<i+1<<" ";
					for(int n=0;n<POPULATION;n++)
					{
						cout<<MenMark[i][n]<<"    ";
						if(MenMark[i][n]<10)
							cout<<" ";
					}
					cout<<endl;
				}
				cout<<endl<<"************Ů������������************"<<endl<<"      ";
				for(int i=0;i<POPULATION;i++)
					cout<<"����"<<i+1<<" ";
				cout<<endl;
				for(int i=0;i<POPULATION;i++)
				{
					cout<<"Ů��"<<i+1<<" ";
					for(int n=0;n<POPULATION;n++)
					{
						cout<<WomenMark[i][n]<<"    ";
						if(WomenMark[i][n]<10)
							cout<<" ";
					}
					cout<<endl;
				}
				cout<<endl<<"****************����ƥ��**************"<<endl;
				cout<<"****     �������    Ů�����     ****"<<endl;
				for(int i=0;i<POPULATION;i++)
					cout<<"****     "<<i+1<<"           "<<MenMarry[i]+1<<"            ****"<<endl;

				cout<<endl<<"****************Ů��ƥ��**************"<<endl;
				cout<<"****     Ů�����    �������     ****"<<endl;
				for(int i=0;i<POPULATION;i++)
					cout<<"****     "<<i+1<<"           "<<WomenMarry[i]+1<<"            ****"<<endl;
				cout<<endl;
				system("pause");
				break;
			}
		default:
			break;
		}
	}
}