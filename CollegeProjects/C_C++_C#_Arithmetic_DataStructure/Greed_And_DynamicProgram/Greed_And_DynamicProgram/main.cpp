#include<iostream>
#include<iomanip>
#include"greed_01bag.h"
#include"greed_AddGas.h"
#include"DP_SelectAD.h"
#include"DP_CarRun.h"
using namespace std;

void main()
{
	int menu=0;
	while(true){
		system("cls");
		cout<<"********** ̰�ķ�����̬�滮�� **********"<<endl;
		cout<<"****  1��̰�ķ���0/1��������        ****"<<endl;
		cout<<"****  2��̰�ķ�:������������        ****"<<endl;
		cout<<"****  3����̬�滮���������ѡȡ     ****"<<endl;
		cout<<"****  4����̬�滮��������������ʻ   ****"<<endl;
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
			{
				/*|------------------��̬�滮���������ѡȡ����-------------------|*/
				char way='0';
				int AD_number=0;
				system("cls");
				cout<<"|--------------- ��̬�滮�� ----------------|"<<endl;
				cout<<"************** �����ѡȡ���� **************"<<endl;//��·����
				cout<<"����������������";
				cin>>AD_number;

				int max_value=0;
				vector<int> *max_path = new vector<int>;
				int *AD_position = new int[AD_number+1];
				int *AD_price = new int[AD_number+1];
				AD_position[0] = 0;
				AD_price[0] = 0;
				int last_position=0;

				cout<<endl;
				cout<<"*************** ������ӷ�ʽ ***************"<<endl;
				cout<<"****  1��������ɣ�                     ****"<<endl;
				cout<<"****  2���ֶ����롣                     ****"<<endl;
				cout<<"********************************************"<<endl;
				cout<<"��ѡ��";
				cin>>way;
				if(way=='1'){
					setPV(AD_position,AD_price,AD_number);
				}
				else{
					for(int i=1;i<=AD_number;i++)
					{
						cout<<"�������"<<i<<"�����λ�ã�";
						cin>>AD_position[i];
						while(AD_position[i]<=last_position){
							cout<<"Error:�¹����λ��Ӧ������һ�������֮�����������"<<last_position<<"��ֵ��"<<endl;
							cout<<"�������"<<i<<"�����λ�ã�";
							cin>>AD_position[i];
						}
						last_position = AD_position[i];
						cout<<"�������"<<i<<"��������棺";
						cin>>AD_price[i];
					}
				}

				cout<<endl<<"******************* ���� *******************"<<endl;
				cout<<"�����λ�ã�";
				for(int i=1;i<=AD_number;i++)
					cout<<setw(2)<<AD_position[i]<<" ";
				cout<<endl<<"��������棺";
				for(int i=1;i<=AD_number;i++)
					cout<<setw(2)<<AD_price[i]<<" ";

				cout<<endl<<endl<<"******************* ��� *******************"<<endl;
				SelectAD(AD_number,AD_position,AD_price,&max_value,max_path);
				cout<<"�����ѡ��";
				for(unsigned int k=0;k<(*max_path).size();k++)
					cout<<setw(2)<<(*max_path)[k]<<" ";
				cout<<endl<<"�����λ�ã�";
				for(unsigned int k=0;k<(*max_path).size();k++)
					cout<<setw(2)<<AD_position[(*max_path)[k]]<<" ";
				cout<<endl<<"��������棺";
				for(unsigned int k=0;k<(*max_path).size();k++)
					cout<<setw(2)<<AD_price[(*max_path)[k]]<<" ";
				cout<<endl<<"��������棺"<<max_value<<endl;

				cout<<endl;
				system("pause");
			}
			
			break;
		case 4:
			{/*|------------------��̬�滮��������������ʻ����-------------------|*/
				char way = '0';
				int check_number = 0;
				int ride_route = 0;
				int cost_addgas = 0;
				int cost_back = 0;
				int cost_addstation = 0;
				system("cls");
				cout<<"|--------------- ��̬�滮�� ----------------|"<<endl;
				cout<<"************** ����������ʻ���� **************"<<endl;//��·����
				cout<<"�����뷽�����񳤶ȣ�";
				cin>>check_number;
				while(check_number<2 || check_number>100)
				{
					cout<<"����������2~100��ֵ��";
					cout<<"�����뷽�����񳤶ȣ�";
					cin>>check_number;
				}
				cout<<"���������������������ʻ��·�̣�";
				cin>>ride_route;
				while(check_number<2 || check_number>10)
				{
					cout<<"����������2~10��ֵ��";
					cout<<"���������������������ʻ��·�̣�";
					cin>>ride_route;
				}
				cout<<"��������ͷѣ�";
				cin>>cost_addgas;
				cout<<"������������������Ҫ���ɵķ��ã�";
				cin>>cost_back;
				cout<<"�����������Ϳ�ķ��ã�";
				cin>>cost_addstation;

				int CarRunResult = 0;
				int *station = new int[check_number*check_number];
				setStation(station,check_number);
				cout<<endl<<"******************** ���� ********************"<<endl;
				cout<<"���񳤶ȣ�"<<check_number<<endl;
				cout<<"������ʻ���·�̣�"<<ride_route<<endl;
				cout<<"���ͷѣ�"<<cost_addgas<<endl;
				cout<<"������ʻ���ã�"<<cost_back<<endl;
				cout<<"�����Ϳ���ã�"<<cost_addstation<<endl;
				cout<<"**************** �Ϳ�ֲ���� ****************"<<endl;
				for(int i=0;i<check_number;i++)
				{
					for(int j=0;j<check_number;j++)
						cout<<station[i*check_number+j]<<" ";
					cout<<endl;
				}
				cout<<endl<<endl<<"******************** ��� ********************"<<endl;
				CarRunResult=getCarRunResult(check_number,ride_route,cost_addgas,cost_back,cost_addstation,station);
				cout<<CarRunResult<<endl;

				cout<<endl;
				system("pause");
			}
			break;
		default:
			break;
		}
	}
}