#include<iostream>	
#include<stack> 
#include<string>
#include<conio.h>
using namespace std; 
bool isbrace(string s){//�ж��ַ����Ƿ�ȫ���������
	for(int i = 0;i<s.length();i++){
		if(s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']' || s[i] == '{' || s[i] == '}');
		else return 0;
	}
	return 1;
}
bool ismatch(string s){//�ж�s�������Ƿ�ƥ��
	stack<char> st;
	st.empty();
	for(int i = 0;i<s.length();i++){ 
		if(s[i] == '('|| s[i] == '[' || s[i] == '{') st.push(s[i]); //����������ջ
		else { 
			if(s[i] == ']') {
				//�������ſ��Ƿ���ջ������ƥ��
				if(!st.empty()){
					//����������ջ��ʱֱ�ӷ���false
					if(st.top() != '[') { 
						return 0; 
					} 
					else st.pop(); 
				}
				else return 0;
			} 
			if(s[i] == ')') {
				if(!st.empty()){
					if(st.top()!='(') {
						return 0;
					} 
					else st.pop(); 
				}
				else return 0;
			} 
			if(s[i] == '}') {
				if(!st.empty()){
					if(st.top()!='{') {
						return 0;
					} 
					else st.pop(); 
				}
				else return 0;
			} 
		} 
	}
	if(st.empty()) return 1;
	else return 0;
}
void main() { 
	string S;
	while(true){
		cout<<"������Ҫƥ������ţ�";
		cin>>S; 
		if(isbrace(S)){
			//�ַ���ȫ���������
			if(ismatch(S)) 
				//�ַ�������ƥ����ȷ
				cout<<"��������ƥ�䣡"<<endl;
			else 
				//�ַ�������ƥ�����
				cout<<"�������Ų�ƥ�䣡"<<endl;
		} 	 
		else{
			//�ַ�����ȫ���������
			cout<<"�����ַ����Ƿ���"<<endl; 
		}
		cout<<"\n�����������>>>>>>>>>>>>>>>>>>>"; 
		_getch(); 
		cout<<endl<<endl; 
	}
}
