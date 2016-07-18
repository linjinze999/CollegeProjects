#include<iostream>
#include"bag.h"
#include"travel_city.h"
#include"wiring.h"
using namespace std;

void main()
{
	int menu=0;
	while(true){
		system("cls");
		cout<<"************** ��֧�޽編 **************"<<endl;
		cout<<"****  1��0/1��������                ****"<<endl;
		cout<<"****  2���������ۻ�Ա����           ****"<<endl;
		cout<<"****  3����·��������               ****"<<endl;
		cout<<"****************************************"<<endl;
		cout<<"��ѡ��";
		cin>>menu;
		switch(menu){
		case 1:
			{/*|------------------0/1��������-------------------|*/
				char way='0';
				int goods_number=0;//��Ʒ����
				int bag_vector=0;  //�������

				system("cls");
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

				system("cls");
				cout<<"***************  0/1��������  **************"<<endl;				//��ʾ������Ϣ
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
				cout<<"********************************************"<<endl;				//�����ѷ���
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
			{/*|------------------�������ۻ�Ա����-------------------|*/
				char way='0';
				int city_number=0;//��������
				int choose=0;

				system("cls");
				cout<<"************* �������ۻ�Ա���� *************"<<endl;
				cout<<"��������и�����";
				cin>>city_number;

				int *city_cost=new int[city_number*city_number];//���м�·�̣����ã�
				int *city_travel_result=new int[city_number];   //��¼���ս��

				cout<<endl;
				cout<<"*************** ������ӷ�ʽ ***************"<<endl;
				cout<<"****  1��������ɣ�                     ****"<<endl;
				cout<<"****  2���ֶ����롣                     ****"<<endl;
				cout<<"********************************************"<<endl;
				cout<<"��ѡ��";
				cin>>way;
				if(way=='1')//�����������
					setCost(city_number,city_cost);
				else		//�ֶ���������
				{      
					int cost;
					for(int i=0;i<city_number;i++)
						for(int n=i;n<city_number;n++)
						{
							if(i==n)
								city_cost[i*city_number+n]=100;
							else
							{
								cout<<"�������"<<i+1<<"���������"<<n+1<<"�����е�·�̣����ã���";
								cin>>cost;
								if(cost<100)
								{
									city_cost[i*city_number+n]=cost;
									city_cost[n*city_number+i]=cost;
								}
								else{
									cout<<"Error:·�̣����ã����˳���һ�٣����������롣"<<endl;
									n--;
								}
							}
						}
				}

				cout<<endl;
				cout<<"******************* ��ͼ *******************"<<endl;
				for(int i=0;i<city_number;i++){  //��ʾ��ͼ
					cout<<"����"<<i+1<<" ";
					for(int n=0;n<city_number;n++){
						if(city_cost[i*city_number+n]==100)
							cout<<"�� ";
						else
							cout<<city_cost[i*city_number+n]<<" ";
					}
					cout<<endl;
				}

				
				cout<<endl;
				cout<<"***************** ������� *****************"<<endl;//ѡ��������
				cout<<"��ѡ��������(1~"<<city_number<<")��";
				cin>>choose;
				while(choose>city_number){
					cout<<"Error:�����б�Ź���������1~"<<city_number<<"��"<<endl;;
					cout<<"��ѡ��������(1~"<<city_number<<")��";
					cin>>choose;
				}

				getTravelResult(city_number,city_cost,city_travel_result,choose);//�õ�·��
				cout<<endl;
				cout<<"******************* ��� *******************"<<endl;		//������
				cout<<"·����";
				for(int i=0;i<city_number;i++)
					cout<<city_travel_result[i]<<" ";
				cout<<endl<<endl;
				system("pause");
			}
			break;
		case 3:
			{/*|------------------��·��������-------------------|*/
				int circuit_number=0;
				system("cls");
				cout<<"************** ��·�������� **************"<<endl;//��·����
				cout<<"�������·������";
				cin>>circuit_number;

				cout<<endl;
				cout<<"*************** ��ֹ����ֵ ***************"<<endl;//��ֹ����ֵ
				int circuit_start[2];
				int circuit_end[2];
				cout<<"�����������X���꣺";
				cin>>circuit_start[0];
				while(circuit_start[0]>=circuit_number){
					cout<<"Error:ֵ����"<<endl;
					cout<<"�����������X���꣺";
					cin>>circuit_start[0];
				}
				cout<<"�����������Y���꣺";
				cin>>circuit_start[1];
				while(circuit_start[1]>=circuit_number){
					cout<<"Error:ֵ����"<<endl;
					cout<<"�����������Y���꣺";
					cin>>circuit_start[1];
				}
				cout<<"�������յ�X���꣺";
				cin>>circuit_end[0];
				while(circuit_end[0]>=circuit_number){
					cout<<"Error:ֵ����"<<endl;
					cout<<"�������յ�X���꣺";
					cin>>circuit_end[0];
				}
				cout<<"�������յ�Y���꣺";
				cin>>circuit_end[1];
				while(circuit_end[1]>=circuit_number){
					cout<<"Error:ֵ����"<<endl;
					cout<<"�������յ�Y���꣺";
					cin>>circuit_end[1];
				}

				std::vector<int> *result=new std::vector<int>;
				getWiring(circuit_number,circuit_start,circuit_end,result);//�õ���·����
				cout<<endl;
				cout<<"******************** ·�� ******************"<<endl;//������
				cout<<"·����";
				for(unsigned int i=0;i<(*result).size();i+=2)
				{
					if((*result)[i] == -1)
					{
						if(i!=((*result).size()-1))
						{
							cout<<endl<<"·����";
							i-=1;
						}
						else
							i-=1;
					}
					else
						cout<<"["<<(*result)[i]<<","<<(*result)[i+1]<<"] ";
				}
				cout<<endl<<endl;
				system("pause");
			}
			break;
		default:
			break;
		}
	}
}