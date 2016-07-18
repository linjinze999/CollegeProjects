#include<iostream>
using namespace std;

typedef  struct BiTNode{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int SearchNode(BiTree T,int key, int deep){//���ҽ��
	if (T==NULL){ 
		return 0; 
	}
	else {
		if (key==T->data){  
			return deep; 
		}
		else {
			if (key<T->data) 
				return SearchNode(T->lchild, key,deep+1);
			else  
				return SearchNode(T->rchild, key,deep+1);
		}
	}
}

bool InsertNode(BiTree &T,int key){//������
	if(SearchNode(T,key,1)==0){
		if(T==NULL){
			T=(BiTree)malloc(sizeof(BiTNode));
			T->lchild=NULL;
			T->rchild=NULL;
			T->data=key;
			return 1;
		}
		else{
			if(key>T->data)
				return InsertNode(T->rchild,key);
			else
				return InsertNode(T->lchild,key);
		}
	}
	else{
		return 0;
	}
}

void PrintTree(BiTree Boot,int Layer){//��ӡ�����
	int i;
	if(Boot==NULL) return;
	PrintTree(Boot->rchild,Layer+1);
	for(i=0;i<Layer;i++)
		cout<<"   ";
	cout<<Boot->data<<endl;
	PrintTree(Boot->lchild,Layer+1);
}

void CreateBiTree(BiTree &T){
	int number;
	int key;
	cout<<"������������";
	cin>>number;
	for(int n=1;n<=number;n++){
		cout<<"�������"<<n<<"������ֵ:";
		cin>>key;
		if(!InsertNode(T,key)){
			cout<<"�����ظ�������������"<<endl;
			n--;
			continue;
		}
	}
	cout<<"�����ɹ���"<<endl;
	cout<<"��������£�"<<endl;
	PrintTree(T,0);
}

bool DeleteNode(BiTree &T,int key){//ɾ�����
	if(SearchNode(T,key,1)==0)
		return 0;
	else{
		if(T->data==key){
			BiTree s,q;
			if(T->rchild==NULL){//������Ϊ��
				q=T; T=T->lchild; free(q);
			}
			else if(T->lchild==NULL){//������Ϊ��
				q=T; T=T->rchild; free(q);
			}
			else{//����������Ϊ��
				q=T; s=T->lchild;
				while(s->rchild){
					q=s;
					s=s->rchild;
				}
				T->data=s->data;
				if(q!=T)
					q->rchild=s->lchild; 
				else
					q->lchild=s->lchild;
				free(s);
			}
			return 1;
		}
		else if(key>T->data)
			return DeleteNode(T->rchild,key);
		else
			return DeleteNode(T->lchild,key);
	}
}

void InOrderTraverse(BiTree T){//�������
	if(T){
		InOrderTraverse(T->lchild);
		cout<<T->data<<' ';
		InOrderTraverse(T->rchild);
	}
}

void main(){
	int menu=0;
	BiTree T=NULL;
	int key=0;
	int deep=0;
	bool t;
	while(true){
		cout<<"***********************"<<endl;
		cout<<"       ����������      "<<endl;
		cout<<"***********************"<<endl;
		cout<<"1������������������"<<endl;
		cout<<"2������������������"<<endl;
		cout<<"3�����ҽ�㣻"<<endl;
		cout<<"4�������㣻"<<endl;
		cout<<"5��ɾ����㣻"<<endl;
		cout<<"6����ӡ�����"<<endl;
		cout<<"***********************"<<endl;
		cout<<"��ѡ��";
		cin>>menu;
		switch(menu){
		case 1:
			CreateBiTree(T);
			cout<<endl;
			break;
		case 2:
			cout<<"������������";
			InOrderTraverse(T);
			cout<<endl;
			cout<<endl;
			break;
		case 3:
			cout<<"��������ҵĽ��ֵ��";
			cin>>key;
			deep=SearchNode(T,key,1);
			if(deep==0)
				cout<<"�����ڸý�㣡"<<endl;
			else
				cout<<"�ý������Ϊ��"<<deep<<endl;
			cout<<endl;
			break;
		case 4:
			cout<<"���������Ľ��ֵ��";
			cin>>key;
			t=InsertNode(T,key);
			if(t)
				cout<<"����ɹ���"<<endl;
			else
				cout<<"�����ظ�������ʧ�ܣ�"<<endl;
			cout<<endl;
			break;
		case 5:
			cout<<"������Ҫɾ���Ľ��ֵ��";
			cin>>key;
			t=DeleteNode(T,key);
			if(t)
				cout<<"ɾ���ɹ���"<<endl;
			else
				cout<<"ɾ��ʧ�ܣ�δ�ҵ���ֵ��"<<endl;
			cout<<endl;
			break;
		case 6:
			if(T==NULL)
				cout<<"��ӡʧ�ܣ�δ����������������"<<endl;
			else{
				cout<<"��������£�"<<endl;
				PrintTree(T,0);
			}
			cout<<endl;
			break;
		default:
			break;
		}
	}
}