#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"LA.h"
using namespace std;

//�ؼ���
char *KeyWord[]={"int","bool","char","long","double","include","void","return","for","do","switch","while","case","break",
	"if","else","goto","new","true","false","default","continue"};
//�����
char *Operatornum[]={"+","-","*","/","%","++","+=","--","-=","^","*="};
//�ȽϷ�
char *Comparison[]={">","<",">=","<=","==","!=","<>"};
//�ֽ��
char *Interpunction[]={",",";","(",")","[","]","{","}"};
//�߼������
char *Logical[]={"&&","&","||","|"};
//ע��
char *Note[]={"//","/*","*/"};

//�ַ�����������������
int CharNum,WordNum,LineNum;

//���ű�
vector<char*> variate;

bool LexicalAnalyser(char *FileName)
{
	ifstream f;
	f.open(FileName);/*���ļ�*/
	if(f.is_open())/*���ļ�����*/
	{
		CharNum=0;
		WordNum=0;
		LineNum=0;
		char *line=new char[1024];
		variate.clear();
		
		cout<<endl<<"*******************�Ǻ���*******************"<<endl;
		while(!f.eof())/*��ȡ���ļ�ĩβ*/
		{
			f.getline(line,1024);/*ÿ�ζ�ȡһ��*/
			LineNum+=1;/*����+1*/
			Lexical(line);/*�ʷ�����*/
		}
		f.close();/*�ر��ļ�*/
		cout<<"*******************���ű�*******************"<<endl;
		for(int VNo=0;VNo<variate.size();VNo++)
			cout<<VNo<<" "<<variate[VNo]<<endl;
		cout<<"********************ͳ��********************"<<endl;
		cout<<"���ļ�ӵ�У�"<<LineNum<<"�С�"<<WordNum<<"���ʡ�"<<CharNum<<"�ַ�"<<endl<<endl;
		return true;
	}
	else/*���ļ�������*/
		return false;
}

void Lexical(char *line)/*�ʷ�����*/
{
	int count=0;
	
	while(line[count]!='\0')
			{
				//���Կո��\t
				while(line[count]==' '||line[count]=='	')
					count++;
				//�ո���Ժ������ַ�������
				if(line[count]!='\0')
				{
					//�ж��Ƿ�Ϊ�ؼ��ֻ����
					if((line[count]>='a'&&line[count]<='z')||
						(line[count]>='A'&&line[count]<='Z')||
						line[count]=='_')
					{
						int wordnum=0;
						char *word=new char;
						//�õ�����
						while((line[count]>='a'&&line[count]<='z')||
						(line[count]>='A'&&line[count]<='Z')||
						(line[count]>='0'&&line[count]<='9')||
						line[count]=='_')
						{
							realloc(word,(wordnum+1)*sizeof(char));
							word[wordnum]=line[count];
							wordnum++;
							count++;
							CharNum+=1;
						}
						word[wordnum]=NULL;
						//�ؼ����ж�
						bool isKW=false;
						int KWNo=0;
						while(KeyWord[KWNo])
						{
							//�ǹؼ���
							if(strcmp(KeyWord[KWNo],word)==0)
							{
								cout<<"1 �ؼ��� "<<word<<endl;
								isKW=true;
								break;
							}
							KWNo++;
						}
						//���ǹؼ��֣���Ϊ����
						if(!isKW){
							bool variate_is_exist=false;
							for(int VNo=0;VNo<variate.size();VNo++)//�ַ������Ƿ����и�����
								if(strcmp(variate[VNo],word)==0)
								{
									variate_is_exist=true;
									break;
								}
							if(!variate_is_exist)
								variate.push_back(word);//���뵽�ַ�����
							cout<<"2 ��ʶ�� "<<word<<endl;
						}
						WordNum+=1;
					}
					//�ж��Ƿ�Ϊ��ֵ
					else if(line[count]>='0'&&line[count]<='9')
					{
						char *word=new char;
						int wordnum=0;
						while((line[count]>='0'&&line[count]<='9')||line[count]=='.')
						{
							realloc(word,(wordnum+1)*sizeof(char));
							word[wordnum]=line[count];
							wordnum++;
							count++;
							CharNum+=1;
						}
						word[wordnum]=NULL;
						cout<<"3 ����ֵ "<<word<<endl;
						WordNum+=1;
					}
					//������������ַ��ţ�
					else
					{
						switch(line[count])
						{
						case '+':
							//++
							if(line[count+1]=='+')
							{
								cout<<"4 ����� ++"<<endl;
								count+=2;
								CharNum+=2;
								WordNum+=1;
							}
							//+=
							else if(line[count+1]=='=')
							{
								cout<<"4 ����� +="<<endl;
								count+=2;
								CharNum+=2;
								WordNum+=1;
							}
							//+
							else
							{
								cout<<"4 ����� +"<<endl;
								count+=1;
								CharNum+=1;
								WordNum+=1;
							}
							break;
						case '-':
							//--
							if(line[count+1]=='-')
							{
								cout<<"4 ����� --"<<endl;
								count+=2;
								CharNum+=2;
								WordNum+=1;
							}
							//-=
							else if(line[count+1]=='=')
							{
								cout<<"4 ����� -="<<endl;
								count+=2;
								CharNum+=2;
								WordNum+=1;
							}
							//-
							else
							{
								cout<<"4 ����� -"<<endl;
								count+=1;
								CharNum+=1;
								WordNum+=1;
							}
							break;
						case '=':
							//==
							if(line[count+1]=='=')
							{
								cout<<"5 �ȽϷ� =="<<endl;
								count+=2;
								CharNum+=2;
								WordNum+=1;
							}
							//=
							else
							{
								cout<<"6 ��ֵ�� ="<<endl;
								count+=1;
								CharNum+=1;
								WordNum+=1;
							}
							break;
						case '!':
							//!=
							if(line[count+1]=='=')
							{
								cout<<"5 �ȽϷ� !="<<endl;
								count+=2;
								CharNum+=2;
								WordNum+=1;
							}
							//!
							else
							{
								cout<<"4 ����� !"<<endl;
								count+=1;
								CharNum+=1;
								WordNum+=1;
							}
							break;
						case '>':
							//>=
							if(line[count+1]=='=')
							{
								cout<<"5 �ȽϷ� >="<<endl;
								count+=2;
								CharNum+=2;
								WordNum+=1;
							}
							//>
							else
							{
								cout<<"5 �ȽϷ� >"<<endl;
								count+=1;
								CharNum+=1;
								WordNum+=1;
							}
							break;
						case '<':
							//<=
							if(line[count+1]=='=')
							{
								cout<<"5 �ȽϷ� <="<<endl;
								count+=2;
								CharNum+=2;
								WordNum+=1;
							}
							//<>
							else if(line[count+1]=='>')
							{
								cout<<"5 �ȽϷ� <>"<<endl;
								count+=2;
								CharNum+=2;
								WordNum+=1;
							}
							//<
							else
							{
								cout<<"5 �ȽϷ� <"<<endl;
								count+=1;
								CharNum+=1;
								WordNum+=1;
							}
							break;
						case '*'://*=
							if(line[count+1]=='=')
							{
								cout<<"4 ����� *="<<endl;
								count+=2;
								CharNum+=2;
								WordNum+=1;
							}
							//*
							else
							{
								cout<<"4 ����� *"<<endl;
								count+=1;
								CharNum+=1;
								WordNum+=1;
							}
							break;
						case '%'://%
							cout<<"4 ����� %"<<endl;
							count+=1;
							CharNum+=1;
							WordNum+=1;
							break;
						case '^'://^
							cout<<"4 ����� ^"<<endl;
							count+=1;
							CharNum+=1;
							WordNum+=1;
							break;
						case '|':
							//||
							if(line[count+1]=='|')
							{
								cout<<"7 �߼��� ||"<<endl;
								count+=2;
								CharNum+=2;
								WordNum+=1;
							}
							//|
							else
							{
								cout<<"7 �߼��� |"<<endl;
								count+=1;
								CharNum+=1;
								WordNum+=1;
							}
							break;
						case '&':
							//&&
							if(line[count+1]=='&')
							{
								cout<<"7 �߼��� &&"<<endl;
								count+=2;
								CharNum+=2;
								WordNum+=1;
							}
							//&
							else
							{
								cout<<"7 �߼��� &"<<endl;
								count+=1;
								CharNum+=1;
								WordNum+=1;
							}
							break;
						case '/':
							//"//"
							if(line[count+1]=='/')
							{
								char *word=new char;
								int wordnum=0;
								while(line[count]!='\0')
								{
									realloc(word,(wordnum+1)*sizeof(char));
									word[wordnum]=line[count];
									count++;
									wordnum++;
								}
								word[wordnum]=NULL;
								cout<<"8 ע�ͷ� "<<word<<endl;
							}
							//"/**/"
							else if(line[count+1]=='*')
							{
								char *word=new char;
								int wordnum=0;
								realloc(word,(wordnum+1)*sizeof(char));
								word[wordnum]=line[count];
								count++;wordnum++;
								realloc(word,(wordnum+1)*sizeof(char));
								word[wordnum]=line[count];
								count++;wordnum++;
								while(line[count]!='\0')
								{
									if(line[count]=='*'&&line[count+1]=='/')
									{
										realloc(word,(wordnum+1)*sizeof(char));
										word[wordnum]=line[count];
										count++;wordnum=0;
										realloc(word,(wordnum+1)*sizeof(char));
										word[wordnum]=line[count];
										count++;wordnum=0;
										break;
									}
									realloc(word,(wordnum+1)*sizeof(char));
									word[wordnum]=line[count];
									count++;wordnum=0;
								}
								word[wordnum]=NULL;
								cout<<"8 ע�ͷ� "<<word<<endl;
							}
							//"/"
							else
							{
								cout<<"4 ����� /"<<endl;
								count+=1;
								CharNum+=1;
								WordNum+=1;
							}
							break;
						default://. ; , \  @ ~ ` $ # ( ) [ ] { }
							cout<<"9 �ֽ�� "<<line[count]<<endl;
							count+=1;
							CharNum+=1;
							break;
						}
					}
				}
			}
}