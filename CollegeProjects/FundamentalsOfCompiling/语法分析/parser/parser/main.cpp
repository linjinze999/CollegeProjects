#include<iostream>
#include"LA.h"
#include"parser.h"
using namespace std;

void main()
{
	char *FileName=new char[15];
	vector<string> input;
	while(true){
		system("cls");
		cout<<"********************************************"<<endl;
		cout<<"****            �﷨������              ****"<<endl;
		cout<<"****       (����������ʽ���﷨)       ****"<<endl;
		cout<<"********************************************"<<endl;
		cout<<"�������ļ�����";
		cin>>FileName;
		while(!LexicalAnalyser(FileName,&input)){
			cout<<"Error:�޷��򿪸��ļ���(����ļ������󣬻��Ƿ�����Ӻ�׺)"<<endl;
			cout<<"�����������ļ�����";
			cin>>FileName;;
		}
		system("cls");
		if(!parser(input))
			cout<<"����:�ñ��ʽ�����������ʽ��"<<endl<<endl;
		else
			cout<<"�ɹ�:�ñ��ʽ���������ʽ��"<<endl<<endl;
		system("pause");
	}
}
