#include<iostream>
#include<iomanip>
#include"parser.h"
using namespace std;
bool parser(vector<string> input)//�������ʽ�﷨������
{
	vector< vector<string> > M;	//������
	setParseList(&M);			//��ʼ��������
	cout<<"*******************************������*********************************"<<endl;
	cout<<left<<setw(7)<<""<<setw(7)<<"id"<<setw(7)<<"num"<<setw(7)<<"("<<setw(7)<<")";
	cout<<setw(7)<<"+"<<setw(7)<<"-"<<setw(7)<<"*"<<setw(7)<<"/"<<setw(7)<<"$"<<endl;
	for(int i=0;i<5;i++)		//���������
	{
		for(int j=0;j<10;j++)
		{
			if(M[i][j].compare("null")==0)
				cout<<setw(7)<<"";
			else
				cout<<setw(7)<<M[i][j];
		}
		cout<<endl;
	}

	vector<string> stack;		//ջ
	stack.push_back("$");
	stack.push_back("E");
	string X;					//ջ������
	string output="";			//���


	cout<<endl<<"********************************���**********************************"<<endl;
	cout<<setw(35)<<"ջ"<<setw(21)<<"����"<<"���"<<endl;
	do{
		string stack_show="";
		string input_show="";
		for(unsigned int i=0;i<stack.size();i++)	//��ʾջ
			stack_show+=stack[i];
		cout<<left<<setw(20)<<stack_show;
		for(unsigned int i=0;i<input.size();i++)	//��ʾ����
			input_show += input[i];
		cout<<right<<setw(31)<<input_show;
		cout<<'\t'<<left<<setw(10)<<output<<endl;	//��ʾ���
		output="";

		X=stack[stack.size()-1];
		if( X.compare("id")==0 || X.compare("num")==0 || X.compare("(")==0 || X.compare(")")==0 || X.compare("$")==0 || 
			X.compare("+")==0 || X.compare("-")==0 || X.compare("*")==0 || X.compare("/")==0 )//XΪ�ս����$
		{
			if(X.compare(input[0])==0)
			{
				stack.pop_back();//��ջ������X
				input.erase(input.begin());//ipǰ��һ��λ��
			}
			else
				return false;

		}
		else//XΪ���ս��
		{
			if(!ParseList(&stack,input[0],&output,M))
				return false;
		}
	}while(stack.size()>0);
	return true;
};

//bool ParseList(vector<string> *stack,string FirstWord,string *output)//�ݷ��������ջ ����2���������ɳ���ʵ�֣�
//{
//	if((*stack)[(*stack).size()-1].compare("E")==0)//M[E,*]
//	{
//		if(FirstWord.compare("id")==0 || FirstWord.compare("num")==0 || FirstWord.compare("(")==0)//M[E,id/num/(] = E->TE'
//		{
//			(*stack).pop_back();
//			(*stack).push_back("E'");
//			(*stack).push_back("T");
//			(*output)="E->TE'";
//			return true;
//		}
//		else
//			return false;
//	}
//	else if((*stack)[(*stack).size()-1].compare("E'")==0)//M[E',*]
//	{
//		if(FirstWord.compare(")")==0 || FirstWord.compare("$")==0)//M[E',)/$] = E'->��
//		{
//			(*stack).pop_back();
//			(*output)="E'->��";
//			return true;
//		}
//		else if(FirstWord.compare("+")==0)//M[E',+] = E'->+TE'
//		{
//			(*stack).pop_back();
//			(*stack).push_back("E'");
//			(*stack).push_back("T");
//			(*stack).push_back("+");
//			(*output)="E'->+TE'";
//			return true;
//		}
//		else if(FirstWord.compare("-")==0)//M[E',-] = E'->-TE'
//		{
//			(*stack).pop_back();
//			(*stack).push_back("E'");
//			(*stack).push_back("T");
//			(*stack).push_back("-");
//			(*output)="E'->-TE'";
//			return true;
//		}
//		else
//			return false;
//	}
//	else if((*stack)[(*stack).size()-1].compare("T")==0)//M[T,*]
//	{
//		if(FirstWord.compare("id")==0 || FirstWord.compare("num")==0 || FirstWord.compare("(")==0)//M[T,id/num/(] = T->FT'
//		{
//			(*stack).pop_back();
//			(*stack).push_back("T'");
//			(*stack).push_back("F");
//			(*output)="T->FT'";
//			return true;
//		}
//		else
//			return false;
//	}
//	else if((*stack)[(*stack).size()-1].compare("T'")==0)//M[T',*]
//	{
//		if(FirstWord.compare(")")==0 || FirstWord.compare("+")==0 || FirstWord.compare("-")==0 || FirstWord.compare("$")==0)//M[T',)/+/-/$] = T'->��
//		{
//			(*stack).pop_back();
//			(*output)="T'->��";
//			return true;
//		}
//		else if(FirstWord.compare("*")==0)//M[T',*] = T'->*FT'
//		{
//			(*stack).pop_back();
//			(*stack).push_back("T'");
//			(*stack).push_back("F");
//			(*stack).push_back("*");
//			(*output)="T'->*FT'";
//			return true;
//		}
//		else if(FirstWord.compare("/")==0)//M[T',/] = T'->/FT'
//		{
//			(*stack).pop_back();
//			(*stack).push_back("T'");
//			(*stack).push_back("F");
//			(*stack).push_back("/");
//			(*output)="T'->/FT'";
//			return true;
//		}
//		else
//			return false;
//	}
//	else if((*stack)[(*stack).size()-1].compare("F")==0)//M[F,*]
//	{
//		if(FirstWord.compare("id")==0)//M[F,id] = F->id
//		{
//			(*stack).pop_back();
//			(*stack).push_back("id");
//			(*output)="F->id";
//			return true;
//		}
//		else if(FirstWord.compare("num")==0)//M[F,num] = F->num
//		{
//			(*stack).pop_back();
//			(*stack).push_back("num");
//			(*output)="F->num";
//			return true;
//		}
//		else if(FirstWord.compare("(")==0)//M[F,(] = F->(E)
//		{
//			(*stack).pop_back();
//			(*stack).push_back(")");
//			(*stack).push_back("E");
//			(*stack).push_back("(");
//			(*output)="F->(E)";
//			return true;
//		}
//		else
//			return false;
//	}
//	else
//		return false;
//};


bool ParseList(vector<string> *stack,string FirstWord,string *output,vector<vector<string>> M)//�ݷ��������ջ
{
	for(unsigned int i=0;i<M.size();i++)
	{
		if((*stack)[(*stack).size()-1].compare(M[i][0])==0)//���ս��λ��
		{
			int p=getTerminalPosition(FirstWord);//�ս��λ��
			if(M[i][p].compare("null")!=0)//����������Ӧλ�����ݲ�Ϊ��
			{
				(*stack).pop_back();
				if(!Mystrchr(M[i][p],(char)'��'))
					for(int j = M[i][p].length()-1; j > 2; j--)
					{
						char pa='a';
						pa=M[i][p][j];
						string pp="";
						pp+=pa;
						if(pp.compare("d")==0)
						{
							(*stack).push_back("id");
							j--;
						}
						else if(pp.compare("m")==0)
						{
							(*stack).push_back("num");
							j-=2;
						}
						else
							(*stack).push_back(pp);
					}
				(*output)=M[i][p];
				return true;//����������Ӧλ������Ϊ��
		
			}
			else
				return false;
			
		}
	}
	return false;
};

void setParseList(vector<vector<string>> *M)//����������
{
	for(int i=0;i<5;i++){//��ʼ��
		vector<string> *ssh=new vector<string>;
		for(int j=0;j<10;j++)
			(*ssh).push_back("null");
		(*M).push_back(*ssh);
	}
	(*M)[0][0]="E";(*M)[1][0]="X";(*M)[2][0]="T";(*M)[3][0]="Y";(*M)[4][0]="F";
	vector<string> grammar(11);//�ķ�
	grammar[0]="E->TX";
	grammar[1]="X->+TX";
	grammar[2]="X->-TX";
	grammar[3]="X->��";
	grammar[4]="T->FY";
	grammar[5]="Y->*FY";
	grammar[6]="Y->/FY";
	grammar[7]="Y->��";
	grammar[8]="F->id";
	grammar[9]="F->num";
	grammar[10]="F->(E)";
	vector<vector<string>> First(11);//first��
	First[0].push_back("id");First[0].push_back("num");First[0].push_back("(");
	First[1].push_back("+");
	First[2].push_back("-");
	First[4].push_back("id");First[4].push_back("num");First[4].push_back("(");
	First[5].push_back("*");
	First[6].push_back("/");
	First[8].push_back("id");
	First[9].push_back("num");
	First[10].push_back("(");
	vector<vector<string>> Follow(11);//follow��
	Follow[0].push_back(")");Follow[0].push_back("$");
	Follow[1].push_back(")");Follow[1].push_back("$");
	Follow[2].push_back(")");Follow[2].push_back("$");
	Follow[3].push_back(")");Follow[3].push_back("$");
	Follow[4].push_back("+");Follow[4].push_back("-");Follow[4].push_back(")");Follow[4].push_back("$");
	Follow[5].push_back("+");Follow[5].push_back("-");Follow[5].push_back(")");Follow[5].push_back("$");
	Follow[6].push_back("+");Follow[6].push_back("-");Follow[6].push_back(")");Follow[6].push_back("$");
	Follow[7].push_back("+");Follow[7].push_back("-");Follow[7].push_back(")");Follow[7].push_back("$");
	Follow[8].push_back("+");Follow[8].push_back("-");Follow[8].push_back(")");Follow[8].push_back("$");Follow[8].push_back("*");Follow[8].push_back("/");
	Follow[9].push_back("+");Follow[9].push_back("-");Follow[9].push_back(")");Follow[9].push_back("$");Follow[9].push_back("*");Follow[9].push_back("/");
	Follow[10].push_back("+");Follow[10].push_back("-");Follow[10].push_back(")");Follow[10].push_back("$");Follow[10].push_back("*");Follow[10].push_back("/");
	for(unsigned int i=0;i<grammar.size();i++)//��������
	{
		if(Mystrchr(grammar[i],(char)'��'))
			for(unsigned int n=0;n<Follow[i].size();n++)
			{
				int a=getNonTerminalPosition(grammar[i][0]);
				int b=getTerminalPosition(Follow[i][n]);
				(*M)[a][b]=grammar[i];
			}
		else
			for(unsigned int n=0;n<First[i].size();n++)
			{
				int a=getNonTerminalPosition(grammar[i][0]);
				int b=getTerminalPosition(First[i][n]);
				(*M)[a][b]=grammar[i];
			}
			
		
	}
};

int getNonTerminalPosition(char a)//��ȡ���ս���ڷ������е�λ��
{
	if(a=='E')
		return 0;
	else if(a=='X')
		return 1;
	else if(a=='T')
		return 2;
	else if(a=='Y')
		return 3;
	else if(a=='F')
		return 4;
	else
		return -1;
}

int getTerminalPosition(string a)//��ȡ�ս���ڷ������е�λ��
{
	if(a.compare("id")==0)
		return 1;
	else if(a.compare("num")==0)
		return 2;
	else if(a.compare("(")==0)
		return 3;
	else if(a.compare(")")==0)
		return 4;
	else if(a.compare("+")==0)
		return 5;
	else if(a.compare("-")==0)
		return 6;
	else if(a.compare("*")==0)
		return 7;
	else if(a.compare("/")==0)
		return 8;
	else if(a.compare("$")==0)
		return 9;
	else
		return -1;
};

bool Mystrchr(string s,char c)//�ַ���s���Ƿ����ַ�c
{
	for(unsigned int i=0;i<s.length();i++)
		if(s[i]==c)
			return true;
	return false;
};

