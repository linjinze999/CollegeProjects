#include<iostream>
#include<math.h>
#include<iomanip>
#include"CoverChessboard.h"
#include"ElementSelector.h"
#include"Maximun.h"
using namespace std;

void main()
{
	int menu=0;
	while(true){
		system("cls");
		cout<<"**************** ���η� ****************"<<endl;
		cout<<"****  1��Ԫ��ѡ��                   ****"<<endl;
		cout<<"****  2������Ӷκ�����             ****"<<endl;
		cout<<"****  3�����̸�������               ****"<<endl;
		cout<<"****************************************"<<endl;
		cout<<"��ѡ��";
		cin>>menu;
		switch(menu){
		case 1:
			{/*|------------------Ԫ��ѡ��-------------------|*/
				char way = '0';
				int element_number = 0;	//Ԫ������
				int rank = 0;			//��������

				system("cls");
				cout<<"***************** Ԫ��ѡ�� *****************"<<endl;
				cout<<"������Ԫ��������";
				cin>>element_number;
				cout<<"���������������";
				cin>>rank;
				while(rank>element_number)
				{
					cout<<"Error��ֵ����"<<endl;
					cout<<"���������������";
					cin>>rank;
				}
				int *data = new int[element_number];	//Ԫ������
				int *data2 = new int[element_number];
				int result_value = 0;				//����ֵ
				int result_no = 0;					//����λ��

				cout<<endl;
				cout<<"**************** ������ӷ�ʽ **************"<<endl;
				cout<<"****  1��������ɣ�                     ****"<<endl;
				cout<<"****  2���ֶ����롣                     ****"<<endl;
				cout<<"********************************************"<<endl;
				cout<<"��ѡ��";
				cin>>way;

				if(way=='1')//�����������
					setData(data,element_number);
				else        //�ֶ���������
					for(int i=0;i<element_number;i++)
					{
						cout<<"�������"<<i+1<<"�����ݣ�";
						cin>>data[i];
					}
				cout<<endl<<"******************  ����  ******************"<<endl;		//��ʾԪ������
				for(int i=0;i<element_number;i++)
					cout<<data[i]<<"  ";
				cout<<endl;

				ElementSelect(data,data2,element_number,rank,&result_value,&result_no);

				cout<<endl<<"***************** �������� *****************"<<endl;
				for(int i=0;i<element_number;i++)
					cout<<data2[i]<<"  ";
				cout<<endl;

				cout<<endl<<"****************** ��� ********************"<<endl;//������
				cout<<"������"<<rank<<"��Ԫ��ֵΪ��"<<result_value<<endl;
				cout<<"������"<<rank<<"��Ԫ����ԭ�����е�λ��Ϊ��"<<result_no<<endl;

				cout<<endl;
				system("pause");
			}
			break;
		case 2:
			{/*|------------------����Ӷκ�����-------------------|*/
				char way='0';
				int data_length;//���鳤��

				system("cls");
				cout<<"************** ����Ӷκ����� **************"<<endl;
				cout<<"���������鳤�ȣ�";
				cin>>data_length;

				int *data = new int[data_length];	//��������
				int left = 0;						//�Ӷο�ʼλ��
				int right = 0;						//�Ӷν���λ��

				cout<<endl;
				cout<<"**************** ������ӷ�ʽ **************"<<endl;
				cout<<"****  1��������ɣ�                     ****"<<endl;
				cout<<"****  2���ֶ����롣                     ****"<<endl;
				cout<<"********************************************"<<endl;
				cout<<"��ѡ��";
				cin>>way;
				if(way=='1')//�����������
					setString(data,data_length);
				else		//�ֶ���������
					for(int i=0;i<data_length;i++)
					{
						cout<<"�������"<<i+1<<"�����ݣ�";
						cin>>data[i];
					}

				cout<<endl<<endl;
				cout<<"******************* ���� *******************"<<endl;	//�����������
				for(int i=0;i<data_length;i++)
					cout<<data[i]<<" ";
				cout<<endl;

				int sum = Maximun(data,data_length,left,right);				//�õ����
				cout<<endl<<"******************* ��� *******************"<<endl;	//������
				cout<<"����Ӷκ�Ϊ��"<<sum<<endl;
				cout<<"���Ӷ����䣺["<<left+1<<","<<right+1<<"]"<<endl;
				cout<<"���Ӷ����ݣ�";
				for(int n = left; n <= right;n++)
					cout<<data[n]<<" ";

				cout<<endl<<endl;
				system("pause");
			}
			break;
		case 3:
			{/*|------------------���̸�������-------------------|*/
				char way='0';
				int chess_k = 0;//2^k��kֵ
				system("cls");
				cout<<"*************** ���̸������� ***************"<<endl;
				cout<<"���̸���Ϊ2^k��������kֵ��";
				cin>>chess_k;

				int chess_length = pow((double)2,chess_k);		//���̳���
				int *chess = new int[chess_length*chess_length];//����
				int point_x=0;									//�����x����
				int point_y=0;									//�����y����
				initChess(chess,chess_length);					//��ʼ������

				cout<<endl;
				cout<<"************** ������������� **************"<<endl;
				cout<<"****  1��������ɣ�                     ****"<<endl;
				cout<<"****  2���ֶ����롣                     ****"<<endl;
				cout<<"********************************************"<<endl;
				cout<<"��ѡ��";
				cin>>way;
				if(way=='1')//������������
					setPoint(chess,chess_length,point_x,point_y);
				else		//�ֶ����������
				{
					cout<<"������X���꣺";
					cin>>point_x;
					while(point_x>chess_length){
						cout<<"Error:ֵ����"<<endl;
						cout<<"������X���꣺";
						cin>>point_x;
					}
					cout<<"������Y���꣺";
					cin>>point_y;
					while(point_y>chess_length){
						cout<<"Error:ֵ����"<<endl;
						cout<<"������Y���꣺";
						cin>>point_y;
					}
					chess[(point_x)*chess_length + (point_y)]=0;
				}

				ChessBoard(chess,chess_length,0,0,point_x,point_y,chess_length);	//�õ����
				cout<<endl<<"******************** ���� ******************"<<endl;	//������
				for(int i=0;i<chess_length;i++)
				{
					for(int j=0;j<chess_length;j++)
						cout<<setw(3)<<chess[i*chess_length+j];
					cout<<endl;
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