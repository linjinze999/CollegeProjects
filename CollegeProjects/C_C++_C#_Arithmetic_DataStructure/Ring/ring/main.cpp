#include <iostream>
#include <conio.h>
using namespace std;

struct Node{
    int n;//����
	int m;//���
	Node *next;
};

void main(){
	Node *head = new Node;
	head->next = NULL;
	Node *tail;
	tail = head;
	Node *de;
	de = head;
	int population;
	int m;
H:  cout<<"��������������";
	cin>>population;
	if(population < 1 || population > 30){
		cout<<"�����������������룡\n"<<endl;
		goto H;
	}
	else{
		for(int i = 1;i <= population;i++){//Ϊÿ���˸�������ֵ
			Node *p = new Node;
			p->m = i;
		    cout<<"�������"<<i<<"���˵����룺";
			cin>>p->n;
			tail->next = p;
			tail = tail->next;
		}
		head = head->next;//ʹ����β����
		tail->next = head;
		free(de);//�ͷ��ʼ�Ŀսڵ�
		cout<<"������ɣ�\n"<<endl;
		cout<<"��������ʼ���е�mֵ��";
		cin>>m;
		cout<<"����˳��Ϊ��";
		Node *d;
		do{//������
			d = head;
			for(int n = 1;n < m;n++){
				tail = d;
				d = d->next;
			}
			cout<<d->m<<"��";
			m = d->n;
			head = d->next;
			tail->next = head;
			free(d);
			population--;
		}while(population > 0);
	}
	cout<<"\n\n�����������������˳�";
	_getch();
}