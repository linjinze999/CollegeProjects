#include<iostream>
#include<iomanip>
#include"addgas.h"
#include"bag01.h"
#include"mapcolor.h"
using namespace std;

void main()
{
	int menu=0;
	while(true){
		system("cls");
		cout<<"**************** ̰�ķ� ****************"<<endl;
		cout<<"****  1��0/1��������                ****"<<endl;
		cout<<"****  2��������������               ****"<<endl;
		cout<<"****  3��ͼ��ɫ����                 ****"<<endl;
		cout<<"****************************************"<<endl;
		cout<<"��ѡ��";
		cin>>menu;
		switch(menu){
		case 1:
			{/*|------------------̰�ķ�����������-------------------|*/
				char way='0';
				int goods_number=0;//��Ʒ����
				int bag_vector=0;  //�������

				system("cls");
				cout<<"|----------------- ̰�ķ� ------------------|"<<endl;
				cout<<"**************** 0/1�������� ***************"<<endl;
				cout<<"��������Ʒ������";
				cin>>goods_number;
				cout<<"�����뱳�������";
				cin>>bag_vector;

				int *goods_vector=new int[goods_number];
				int *goods_value=new int[goods_number];
				int *result=new int[goods_number+2];

				cout<<endl;
				cout<<"**************** ������ӷ�ʽ **************"<<endl;
				cout<<"****  1��������ɣ�                     ****"<<endl;
				cout<<"****  2���ֶ����롣                     ****"<<endl;
				cout<<"********************************************"<<endl;
				cout<<"��ѡ��";
				cin>>way;

				if(way=='1')//�����������
					setGoodsVV(goods_value,goods_vector,goods_number,bag_vector);
				else        //�ֶ���������
					for(int i=0;i<goods_number;i++)
					{
						cout<<"�������"<<i+1<<"����Ʒ�����";
						cin>>goods_vector[i];
						cout<<"�������"<<i+1<<"����Ʒ��ֵ��";
						cin>>goods_value[i];
						
					}
				cout<<endl;
				cout<<"****************** ������Ϣ ****************"<<endl;				//��ʾ������Ϣ
				cout<<"**  ��Ʒ��ֵ��";
				for(int i=0;i<goods_number;i++)
					cout<<goods_value[i]<<"  ";
				cout<<endl;
				cout<<"**  ��Ʒ�����";
				for(int i=0;i<goods_number;i++)
					cout<<goods_vector[i]<<"   ";
				cout<<endl;
				cout<<"**  ���������"<<bag_vector;
				getBagResult(goods_value,goods_vector,goods_number,bag_vector,result);	//��ȡ��ѷ���
				cout<<endl;
				cout<<"******************* ��� *******************"<<endl;				//�����ѷ���
				cout<<"**  ��߼�ֵ��"<<result[1]<<endl;
				cout<<"**  ��ʱ�����"<<result[0]<<endl;
				cout<<"**  ������";
				for(int i=0;i<goods_number;i++)
					cout<<result[i+2]<<" ";
				cout<<"��1Ϊѡ�У�0Ϊ��ѡ��"<<endl;
				cout<<"********************************************"<<endl;
				cout<<endl;
				system("pause");
			}
			break;
		case 2:
			{/*|------------------̰�ķ�����������-------------------|*/
				char way='0';
				int station_number = 0;//��������
				int max_distance = 0;

				system("cls");
				cout<<"|----------------- ̰�ķ� ------------------|"<<endl;
				cout<<"************* ����������ʻ���� *************"<<endl;
				cout<<"���������վ������";
				cin>>station_number;
				cout<<"���������Ϳ���ʻ·�̣�";
				cin>>max_distance;

				int *distance = new int[station_number];
				int *result_station = new int[station_number];
				int result_count = 0;

				cout<<endl;
				cout<<"*************** ������ӷ�ʽ ***************"<<endl;
				cout<<"****  1��������ɣ�                     ****"<<endl;
				cout<<"****  2���ֶ����롣                     ****"<<endl;
				cout<<"********************************************"<<endl;
				cout<<"��ѡ��";
				cin>>way;
				if(way=='1')//�����������
					setDistance(distance,station_number,max_distance);
				else		//�ֶ���������
				{
					distance[0] = 0;
					for(int i=1;i<station_number;i++)
					{
						cout<<"�������"<<i<<"������վ����"<<i+1<<"�ľ��룺";
						cin>>distance[i];
					}
				}

				cout<<endl;
				cout<<"******************* ���� *******************"<<endl;
				for(int i=0;i<station_number;i++){  //��ʾ��ͼ
					cout<<distance[i]<<" ";
				}
				
				cout<<endl<<endl;
				cout<<"******************* ��� *******************"<<endl;		//������
				if(AddGasResult(max_distance,station_number,distance,result_station,result_count))
				{
					cout<<"���ͷ�����";
					for(int i = 0; i < station_number; i++)
						cout<<result_station[i]<<" ";
					cout<<endl;
					cout<<"���ټ��ʹ�����"<<result_count<<endl;
				}
				else
					cout<<"Error�����Ϳ���ʻ·�̹�С���޷��ﵽ�յ㡣"<<endl;

				cout<<endl;
				system("pause");
			}
			break;
		case 3:
			{/*|--------------------̰�ķ���ͼ��ɫ����-------------------|*/
				int map_number=0;
				int map_max_color=0;
				system("cls");
				cout<<"|----------------- ̰�ķ� -----------------|"<<endl;
				cout<<"**************** ͼ��ɫ���� ****************"<<endl;
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
				else{		//�ֶ���������
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
						cout<<result[n]+1<<" ";
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