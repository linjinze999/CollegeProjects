#include<iostream>
#include"LA.h"
using namespace std;

void main()
{
	char *FileName=new char[15];
	while(true){
		system("cls");
		cout<<"********************************************"<<endl;
		cout<<"****            �ʷ�������              ****"<<endl;
		cout<<"****   (�����ı��ַ�����������������)   ****"<<endl;
		cout<<"********************************************"<<endl;
		cout<<"�������ļ�����";
		cin>>FileName;
		while(!LexicalAnalyser(FileName)){
			cout<<"Error:�޷��򿪸��ļ���(����ļ������󣬻��Ƿ�����Ӻ�׺)"<<endl;
			cout<<"�����������ļ�����";
			cin>>FileName;;
		}
		system("pause");
	}
}
