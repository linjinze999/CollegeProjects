#include <iostream>
#include <string>
#include <math.h>
#include "ClassCity.h"
using namespace std;

List::List(){
    head = new Node;
	head->next = NULL;
	tail = head;
};
void List::Insert(){//���ӳ���
	int exist = 0;
	Node *q;
    Node *p = new Node; 
	cout<<"�������������:"; 
	cin>>p->Name ; 
	for(q = head->next;q != NULL;q = q->next){//�ж��Ƿ��Ѵ��ڸó�����
	    if(!strcmp(q->Name,p->Name)) 
		{ 
			exist = 1;
			break; 
		}
	}
	if(exist == 1){//�Ѵ��ڵĳ�������Ч
	    cout<<"�˳������Ѵ��ڣ�����ʧ�ܡ�"<<endl;
	}
	else{//������Ϊ���������������
		cout<<"���������X����:";
		cin>>p->x ; 
		cout<<"���������Y����:";
		cin>>p->y ;
		p->next = NULL;
		if(head->next == NULL){
			head->next = p;
		}
		tail->next = p;
		tail = tail->next;
		cout<<"���ӳɹ���"<<endl;
	}
};
void List::Delete(){//ɾ������
	Node *p,*t;
	int exist = 0;
	char name[20];    
	cout<<"��������Ҫɾ���ĳ��е�����:"; 
	cin>>name ;
	for(p = head;p->next != NULL;p = p->next){//�ҵ�������ɾ��
	    if(!strcmp(p->next->Name,name)) 
		{ 
			t = p->next; 
			p->next = t->next; 
			delete(t); 
			cout<<"ɾ���ɹ�!"<<endl;
			exist = 1;
			break; 
		}
	}
	if (exist == 0){//�Ҳ��������������ʾ
	    cout<<"�鲻���˳��С�"<<endl;
	}
};
void List::Search(){//��ѯ����
    Node *p;
	int exist = 0;
	char name[20];    
	cout<<"��������Ҫ��ѯ�ĳ��е�����:"; 
	cin>>name ;
	for(p = head->next;p != NULL;p = p->next){//�ҵ������������������
	    if(!strcmp(p->Name,name)) 
		{ 
			cout<<"��"<<p->Name<<"��"<<"������Ϊ("<<p->x<<','<<p->y<<')'<<endl;
			exist = 1;
			break; 
		}
	}
	if (exist == 0){//�Ҳ��������������ʾ
	    cout<<"�鲻���˳��С�"<<endl;
	}
};
void List::Change(){//���³�����Ϣ
	Node *p;
	int exist = 0;
	char name[20];    
	cout<<"�������Ҫ�޸ĵĳ��е�����:"; 
	cin>>name ;
	for(p = head->next;p != NULL;p = p->next){//�ҵ�������ı�ó�����Ϣ
	    if(!strcmp(p->Name,name)) 
		{ 
			cout<<"�������µĳ������ƣ�";
			cin>>p->Name ; 
	        cout<<"�������µĳ���X����:";
	        cin>>p->x ; 
	        cout<<"�������µĳ���Y����:";
	        cin>>p->y ;
			cout<<"�޸���ɣ�"<<endl;
			exist = 1;
			break; 
		}
	}
	if (exist == 0){//�Ҳ��������������ʾ
	    cout<<"�鲻���˳��С�"<<endl;
	}
};
void List::Nearcity(){//��ѯĳ�㸽���ĳ���
	char name[20]; 
	Node *p; 
	double x,y;
	int NearCityExist = 0;
	double SD; 
	double RD; 
	cout<<"���������ĵ��x����:"; 
	cin>>x; 
	cout<<"���������ĵ��y����:"; 
	cin>>y; 
	cout<<"�������ѯ���� :"; 
    cin>>SD; 
	for(p = head->next; p != NULL; p = p->next){//�������������ĸ�������
		RD = sqrt(((*p).x-x)*((*p).x-x)+((*p).y-y)*((*p).y-y)); 
		if(SD >= RD){
			cout<<p->Name<<":("<<p->x<<','<<p->y<<") �� ";
			NearCityExist = 1;
		}
	}
	if(NearCityExist == 0){//��û�з��������ĸ��������������ʾ
	cout<<"�����ڷ��������ĳ��С�"<<endl;
	}
	else{
	    cout<<endl;
	}
};