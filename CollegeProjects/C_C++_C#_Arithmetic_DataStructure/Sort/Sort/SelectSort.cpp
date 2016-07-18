#include"SelectSort.h"

int SelectMinKey(SqList L,int i,int &compare,int &move)
{ // ������L.r[i..L.length]��key��С�ļ�¼�����
	int min;
	int j,k;
	k=i;
	min=L.R[i].key;
	for(j=i+1;j<=L.length;j++){
		compare++;
		if(L.R[j].key<min) {
			k=j;
			min=L.R[j].key;
		}
	}
	return k;
};

void SelectSort(SqList &L,int &compare,int &move)
{ // ��ѡ������
	int i,j;
	Snode t;
	compare=move=0;
	for(i=1;i<L.length;++i){ 
		j=SelectMinKey(L,i,compare,move); 
		if(i!=j){ 
			t=L.R[i];
			L.R[i]=L.R[j];
			L.R[j]=t;
			move+=3;
		}
	}
};
