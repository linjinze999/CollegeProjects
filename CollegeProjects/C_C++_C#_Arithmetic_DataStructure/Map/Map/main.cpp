#include<iostream>
#include<queue>
#include<conio.h>
using namespace std;
#define MAX_VEX_NUM 30

typedef struct ArcNode{//��ָ�����һ�������±꼰��һ���ߵ�ָ��
	int adjvex;
	struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode{//�������ݼ���һ���ߵ�ָ��
	char data;
	bool visited;
	ArcNode *FirstArc;
}VNode,AdjList[MAX_VEX_NUM];

struct ALGraph{ //������������
	AdjList vertices;
	int vexnum;
	int arcnum;
}; 

int LocateVex(ALGraph G,char v){//Ѱ��V���±�
	int i=0;
	while(i<G.vexnum && v!=G.vertices[i].data)
		i++;
	if(i<G.vexnum)
		return i;
	else
		return -1;
}

void CreateMap(ALGraph &G){//����ͼ
	cout<<"***��ʼ�����ڽӱ�***"<<endl;
	cout<<"������ͼ�Ķ�����:";
	cin>>G.vexnum;
	cout<<"������ͼ�ı�����";
	cin>>G.arcnum;
	char v1;//��ʼ��
	char v2;//��ֹ��
	int v1locate;//��ʼ����±�
	int v2locate;//��ֹ����±�
	char data;//������Ϣ
	bool redo=0;//������Ϣ�Ƿ��ظ�
	ArcNode *p,*q,*end;
	cout<<"\n***��ʼ����ͼ����Ϣ***"<<endl;
	cout<<"1�����붥����Ϣ:"<<endl;
	for(int i=0;i<G.vexnum;i++){
		cout<<"��"<<i+1<<"�����㣺";
		cin>>data;
		for(int i=0;i<G.vexnum;i++){//������Ϣ�Ƿ��ظ�
			if(data==G.vertices[i].data){
				redo=1;
				break;
			}
		}
		if(!redo){//������Ϣ��ȷ
			G.vertices[i].data=data;
			G.vertices[i].FirstArc=NULL;
			G.vertices[i].visited=0;
		}
		else{//������Ϣ�ظ�
			cout<<"��Ϣ�ظ������������룡"<<endl;
			redo=0;
			i--;
			continue;
		}
		
	}
	cout<<"2���������Ϣ��"<<endl;
	for(int k=1;k<=G.arcnum;k++){
		cout<<"�����"<<k<<"���ߵ���ʼ��:";
		cin>>v1;
		cout<<"�����"<<k<<"���ߵ���ֹ��:";
		cin>>v2;
		v1locate=LocateVex(G,v1);
		v2locate=LocateVex(G,v2);
		if(v1locate!=-1&&v2locate!=-1){//��ʼ����ֹ�����
		    p=new ArcNode;
		    p->adjvex=v2locate;
			p->nextarc=NULL;
			if(G.vertices[v1locate].FirstArc==NULL){
				G.vertices[v1locate].FirstArc=p;
			}
			else{
				for(end=G.vertices[v1locate].FirstArc;end->nextarc;end=end->nextarc);
				end->nextarc=p;
			}
			q=new ArcNode;
		    q->adjvex=v1locate;
		    q->nextarc=NULL;
			if(G.vertices[v2locate].FirstArc==NULL){
				G.vertices[v2locate].FirstArc=q;
			}
			else{
				for(end=G.vertices[v2locate].FirstArc;end->nextarc;end=end->nextarc);
				end->nextarc=q;
			}
		}
		else{//��ʼ�����ֹ�㲻����
		    cout<<"�����������������룡"<<endl;
			k--;
			continue;
		}
	}
	cout<<"�����ɹ���"<<endl;
	cout<<"������ͼ���ڽӱ�����:"<<endl;
	for(int i=0;i<G.vexnum;i++){
		cout<<"G->vertices["<<i<<"] = "<<G.vertices[i].data<<" : ";
		for(ArcNode *p=G.vertices[i].FirstArc;p;p=p->nextarc){
			cout<<p->adjvex<<" ";
		}
		cout<<endl;
	}
}

void DFS(ALGraph &G,int Place){//��ȱ���ĳ���㿪ʼ�����ж���
	G.vertices[Place].visited=1;
	cout<<G.vertices[Place].data<<" ";
	for(ArcNode *p=G.vertices[Place].FirstArc;p;p=p->nextarc){
		if(!G.vertices[p->adjvex].visited)
			DFS(G,p->adjvex);
	}
}
void DFStraverse(ALGraph G,int Place){//��ȱ�������ֹ��ĳ���㿪ʼ��������δ�������Ķ���
	DFS(G,Place);
	for(int i=0;i<G.vexnum;i++){
		if(!G.vertices[i].visited){
			DFS(G,i);
		}
	}
}

void BFS(ALGraph &G,int Place){//��ȱ���ĳ���㿪ʼ�����ж���
	int front;
	queue<int> ARC;
	G.vertices[Place].visited=1;
	cout<<G.vertices[Place].data<<" ";
	ARC.push(Place);
	while(!ARC.empty()){
		front=ARC.front();
		ARC.pop();
		for(ArcNode *p=G.vertices[front].FirstArc;p;p=p->nextarc){
			if(!G.vertices[p->adjvex].visited){
				G.vertices[p->adjvex].visited=1;
				cout<<G.vertices[p->adjvex].data<<" ";
				ARC.push(p->adjvex);
			}
		}
	}
}

void BFStraverse(ALGraph G,int Place){//��ȱ�������ֹ��ĳ���㿪ʼ��������δ�������Ķ���
	BFS(G,Place);
	for(int i=0;i<G.vexnum;i++){
		if(!G.vertices[i].visited){
			BFS(G,i);
		}
	}
}

void DFSside(ALGraph &G,int Place){//��ȱ���ĳ���㿪ʼ�����б�
	G.vertices[Place].visited=1;
	for(ArcNode *p=G.vertices[Place].FirstArc;p;p=p->nextarc){
		if(!G.vertices[p->adjvex].visited)
			cout<<"("<<G.vertices[Place].data<<","<<G.vertices[p->adjvex].data<<") ";
		if(!G.vertices[p->adjvex].visited)
			DFSside(G,p->adjvex);
	}
}

void DFSsidetraverse(ALGraph G,int Place){//��ȱ����ߣ���ֹ��ĳ���㿪ʼ��������δ�������Ķ���
	DFSside(G,Place);
	for(int i=0;i<G.vexnum;i++){
		if(!G.vertices[i].visited){
			DFSside(G,i);
		}
	}
}



void BFSside(ALGraph &G,int Place){//��ȱ���ĳ���㿪ʼ�����ж���
	int front;
	queue<int> ARC;
	G.vertices[Place].visited=1;
	ARC.push(Place);
	while(!ARC.empty()){
		front=ARC.front();
		ARC.pop();
		for(ArcNode *p=G.vertices[front].FirstArc;p;p=p->nextarc){
			if(!G.vertices[p->adjvex].visited){
				G.vertices[p->adjvex].visited=1;
				cout<<"("<<G.vertices[front].data<<","<<G.vertices[p->adjvex].data<<") ";
				ARC.push(p->adjvex);
			}
		}
	}
}

void BFSsidetraverse(ALGraph G,int Place){//��ȱ����ߣ���ֹ��ĳ���㿪ʼ��������δ�������Ķ���
	BFSside(G,Place);
	for(int i=0;i<G.vexnum;i++){
		if(!G.vertices[i].visited){
			BFSside(G,i);
		}
	}
}

void main(){
	int FirstPlace;
	char FirstNodeData;
	ALGraph G;
	CreateMap(G);
	cout<<endl;
H:  cout<<"***��ʼ����***"<<endl;
	cout<<"�����뿪ʼ�����Ķ��㣺";
	cin>>FirstNodeData;
	FirstPlace=LocateVex(G,FirstNodeData);
	if(FirstPlace!=-1){
	    cout<<"1����ȱ������㣺";
	    DFStraverse(G,FirstPlace);
	    cout<<endl;
		cout<<"   ��ȱ����ߣ�";
		DFSsidetraverse(G,FirstPlace);
	    cout<<endl;
	    cout<<"2����ȱ������㣺";
	    BFStraverse(G,FirstPlace);
	    cout<<endl;
		cout<<"   ��ȱ����ߣ�";
	    BFSsidetraverse(G,FirstPlace);
	    cout<<endl;
	    _getch();
	}
	else{//��ʼ�����Ķ��㲻����
		cout<<"�����������������룡"<<endl;
	    goto H;
	}
}