#include<iostream>
#include<conio.h>
#include<stack>
using namespace std;

typedef struct BTnode{//���������
	char data;
	struct BTnode *lchild,*rchild;
}BTnode,*BiTree;

BiTree CreateBiTree(){//����������
	char ch;
	BiTree T;
	cin>>ch;
	if(ch=='#') T=NULL;
	else{
		T = (BiTree)malloc(sizeof(BTnode));
		T->data = ch;
		T->lchild = CreateBiTree();
		T->rchild = CreateBiTree();
	}
	return T;
}

void PreOrderTraverse(BiTree T){//�ݹ��������
	if(T){
		cout<<T->data<<' ';
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

void InOrderTraverse(BiTree T){//�ݹ��������
	if(T){
		InOrderTraverse(T->lchild);
		cout<<T->data<<' ';
		InOrderTraverse(T->rchild);
	}
}

void PostOrderTraverse(BiTree T){//�ݹ�������
	if(T){
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout<<T->data<<' ';
	}
}

void PreOrderTraverse2(BiTree T) //�ǵݹ�ǰ����� 
{
    stack<BiTree> s;
    while(T!=NULL||!s.empty())
    {
        while(T!=NULL)
        {
            cout<<T->data<<" ";
            s.push(T);
            T=T->lchild;
        }
        if(!s.empty())
        {
            T=s.top();
            s.pop();
            T=T->rchild;
        }
    }
}

void InOrderTraverse2(BiTree T)//�ǵݹ��������
{
    stack<BiTree> s;
    while(T!=NULL||!s.empty())
    {
        while(T!=NULL)
        {
            s.push(T);
            T=T->lchild;
        }
        if(!s.empty())
        {
            T=s.top();
            cout<<T->data<<" ";
            s.pop();
            T=T->rchild;
        }
    }    
} 

void PostOrderTraverse2(BiTree T)//�ǵݹ�������
{
    stack<BiTree> s;
    BiTree cur;                      //��ǰ��� 
    BiTree pre=NULL;                 //ǰһ�η��ʵĽ�� 
    s.push(T);
    while(!s.empty())
    {
        cur=s.top();
        if((cur->lchild==NULL && cur->rchild==NULL) ||
           (pre!=NULL && (pre==cur->lchild || pre==cur->rchild)))
        {
            cout<<cur->data<<" ";  //�����ǰ���û�к��ӽ����ߺ��ӽڵ㶼�ѱ����ʹ� 
            s.pop();
            pre=cur; 
        }
        else
        {
            if(cur->rchild!=NULL)
                s.push(cur->rchild);
            if(cur->lchild!=NULL)    
                s.push(cur->lchild);
        }
    }    
}

void PrintTree(BiTree Boot,int Layer)//��������״��ӡ�Ķ������ṹ
{
	int i;
	if(Boot==NULL) return;
	PrintTree(Boot->rchild,Layer+1);
	for(i=0;i<Layer;i++)
		cout<<"   ";
	cout<<Boot->data<<endl;
	PrintTree(Boot->lchild,Layer+1);
}

bool isfull(BiTree T){
	if(T->lchild&&T->rchild){
		if(!isfull(T->lchild)) return 0;
		if(!isfull(T->rchild)) return 0;
		return 1;
	}
	else{
		if(T->lchild==NULL&&T->rchild==NULL) return 1;
		else return 0;
	}

}
void main(){
	BiTree T;
	int layer = 0;
	cout<<"�����������Ԫ�أ���#����ʾ��������";
	T = CreateBiTree();
	cout<<"\nһ���ݹ������"<<endl;
	cout<<"  1������������У�";
	PreOrderTraverse(T);
	cout<<endl;
	cout<<"  2������������У�";
	InOrderTraverse(T);
	cout<<endl;
	cout<<"  3������������У�";
	PostOrderTraverse(T);
	cout<<endl<<endl;
	cout<<"�����ǵݹ������"<<endl;
	cout<<"  1������������У�";
	PreOrderTraverse2(T);
	cout<<endl;
	cout<<"  2������������У�";
	InOrderTraverse2(T);
	cout<<endl;
	cout<<"  3������������У�";
	PostOrderTraverse2(T);
	cout<<endl<<endl;
	cout<<"�����������ṹ����:"<<endl<<endl;
	PrintTree(T,layer);
	cout<<"�ġ��Ƿ�����������";
	if(isfull(T))
		cout<<"��";
	else 
		cout<<"��";
	_getch();
}