#include<vector>
#include<string>
using namespace std;
bool parser(vector<string> input);//�������ʽ�﷨������
bool ParseList(vector<string> *stack,string FirstWord,string *output,vector<vector<string>> M);//�ݷ��������ջ
void setParseList(vector<vector<string>> *M);//����������
int getNonTerminalPosition(char a);//��ȡ���ս���ڷ������е�λ��
int getTerminalPosition(string a);//��ȡ�ս���ڷ������е�λ��
bool Mystrchr(string s,char c);//�ַ���s���Ƿ����ַ�c