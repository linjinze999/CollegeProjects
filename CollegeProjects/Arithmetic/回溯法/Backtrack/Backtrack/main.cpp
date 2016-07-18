#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include"bag.h"
#include"MapColor.h"
using namespace std;


void main()
{
	int menu=0;
	int NUMBER=0;//������Ʒ����
	int VECTOR=0;//����������
	int map_number=0;//��ͼ��������
	int map_max_color=0;//��ͼɫ������
	while(true){
		system("cls");
		cout<<"***************  ���ݷ� **************"<<endl;
		cout<<"****  1��0/1��������              ****"<<endl;
		cout<<"****  2��ͼ��ɫ����               ****"<<endl;
		cout<<"**************************************"<<endl;
		cout<<"��ѡ��";
		cin>>menu;
		switch(menu)
		{
		case 1:/*|---------------------0/1��������----------------------|*/
			{
				system("cls");
				cout<<"*****************0/1��������****************"<<endl;
				cout<<"��������Ʒ������";
				cin>>NUMBER;
				cout<<"�����뱳�������";
				cin>>VECTOR;

				char way='0';
				cout<<endl;
				cout<<"*****************������ӷ�ʽ***************"<<endl;
				cout<<"****  1��������ɣ�                     ****"<<endl;
				cout<<"****  2���ֶ����롣                     ****"<<endl;
				cout<<"********************************************"<<endl;
				cout<<"��ѡ��";
				cin>>way;
				
				int **allbag=new int *[NUMBER+2];//��¼�������
				int *bag=new int[NUMBER+2];//��¼���
				int *vector=new int[NUMBER];//��¼����Ʒ���
				int *value=new int[NUMBER];//��¼����Ʒ��ֵ
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

				for(int n=0;n<pow((double)2,NUMBER);n++)//��������
				{
					int dtb=n;
					for(int i=NUMBER-1;i>=0;i--)
					{
						goods[i]=dtb % 2;
						dtb=dtb / 2;
					}
					allbag[count]=(int*)malloc((NUMBER+2)*sizeof(int));
					getVV(allbag,value,vector,count,goods,NUMBER);
					if(allbag[count][0]>VECTOR)//����
					{
						int where1=NUMBER-1;
						while(where1>=0 && !goods[where1])
							where1--;
						while(where1>=0 && goods[where1])
							where1--;
						if(where1>=0)
						{
							n=0;
							for(int m=0;m<where1;m++)
								if(goods[m])
									n+=pow((double)2,(NUMBER-1-m));
							n+=pow((double)2,(NUMBER-1-where1));
							n=n-1;
						}
						else
						{
							count++;
							break;
						}
					}
					count++;	
				}
				system("cls");
				cout<<"***************  0/1��������  **************"<<endl;//���������Ʒ����������
				cout<<"**  ��Ʒ��ֵ��";
				for(int i=0;i<NUMBER;i++)
					cout<<value[i]<<"  ";
				cout<<endl<<"**  ��Ʒ�����";
				for(int i=0;i<NUMBER;i++)
					cout<<vector[i]<<"   ";
				cout<<endl<<"**  ���������"<<VECTOR;
				result(allbag,bag,count,VECTOR,NUMBER);//�õ����ս��
				cout<<endl<<"********************************************"<<endl;//������
				cout<<"**  ��߼�ֵ��"<<bag[1]<<endl<<"**  ��ʱ�����"<<bag[0]<<endl;
				cout<<"**  ������";
				for(int i=0;i<NUMBER;i++)
					cout<<bag[i+2]<<" ";
				cout<<"��1Ϊѡ�У�0Ϊ��ѡ��"<<endl;
				cout<<"********************************************"<<endl;
				cout<<endl;
				system("pause");
			}
			break;
		case 2:
			{/*|---------------------ͼ��ɫ����----------------------|*/
				system("cls");
				cout<<"*****************ͼ��ɫ����****************"<<endl;
				cout<<"�������ͼ��������";
				cin>>map_number;
				cout<<"��������ɫ������";
				cin>>map_max_color;

				char way='0';
				cout<<endl;
				cout<<"*****************������ӷ�ʽ***************"<<endl;
				cout<<"****  1��������ɣ�                     ****"<<endl;
				cout<<"****  2���ֶ����롣                     ****"<<endl;
				cout<<"********************************************"<<endl;
				cout<<"��ѡ��";
				cin>>way;

				int *Map=new int[map_number*map_number];
				int *result=new int[map_number];
				memset(result,0,map_number);

				if(way=='1')//�����������
					setMap(map_number,Map);
				else{//�ֶ���������
					int connect;
					for(int i=0;i<map_number;i++)
						for(int n=0;n<map_number;n++){
							if(i==n)
								Map[i*map_number+n]=0;
							else if(n>i){
								cout<<"�������"<<i+1<<"���������"<<n+1<<"����������������";
								cin>>connect;
								Map[i*map_number+n]=connect;
								Map[n*map_number+i]=connect;
							}
						}
				}
				cout<<endl<<"*********************��ͼ*******************"<<endl;
				for(int i=0;i<map_number;i++){//��ʾ��ͼ
					cout<<"����"<<i+1<<" ";
					for(int n=0;n<map_number;n++){
						cout<<Map[i*map_number+n]<<" ";
					}
					cout<<endl;
				}
				cout<<endl<<"*********************���*******************"<<endl;
				if(MapColor(map_number,Map,result,0,1,map_max_color)){//�ɹ����
					cout<<"��ɫ�����";
					for(int n=0;n<map_number;n++)
						cout<<result[n]<<" ";
				}
				else//ʧ�ܽ��
					cout<<"Error:"<<map_max_color<<"��ɫ���޷���ɫ�õ�ͼ��"<<endl;
				cout<<endl<<endl;
				system("pause");
			}
			break;
		default:
			break;
		}
	}
	
}