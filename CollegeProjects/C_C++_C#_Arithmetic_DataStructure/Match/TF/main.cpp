#include<iostream>
#include<stack>
#include<conio.h>
#include<string>
using namespace std;

void transform(int number,int system){//��numberת��Ϊsystem�������������
	int e;
    stack<int> s;
	while(number){
		s.push(number%system);
		number = number / system;
	}
	while(!s.empty()){
		e = s.top();
		if(e<10)
			cout<<e;
		else
			cout<<(char)(e+'A'-10);
		s.pop();
	}
	cout<<endl;
}
bool isnumber(string s){//�ж��ַ���S�Ƿ���ȫ���������
	for(int i = 0;i < s.length();i++){
	    if(isdigit(s[i]));
		else
			return 0;
	}
	return 1;
}
void main(){
	int number,system;
	string input;
	while(true){
	    cout<<"������һ��ʮ��������";
		cin>>input;
		if(isnumber(input)){
			//�����ʮ��������ȷ
			number=atoi(input.c_str());
			cout<<"������Ҫת���Ľ�������";
			cin>>input;
			if(isnumber(input)){
				//����Ľ�������ȷ
				system=atoi(input.c_str());;
				cout<<"��"<<number<<"��"<<"ת��Ϊ"<<system<<"���ƣ����Ϊ��";
				transform(number,system);//������
				cout<<"�����������>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
				_getch();
				cout<<endl<<endl;
			}
			else{
				//�����ʮ����������
			    cout<<"�����������������룡"<<endl<<endl;
			}
		}
		else{
			//����Ľ���������
		    cout<<"�����������������룡"<<endl<<endl;
		}
	}
}