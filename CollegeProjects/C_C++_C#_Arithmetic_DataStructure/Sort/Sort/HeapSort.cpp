#include"HeapSort.h"

void HeapAdjust(SqList &H, int s, int m,int &compare,int &move){
	// ��������H.r[s..m]����Ϊ�󶥶�.
	Snode rc=H.R[s];
	int j;
	for(j=2*s; j<=m; j*=2){
		compare++;
		if(j<m && H.R[j].key<=H.R[j+1].key) 
			j++; 
		compare++;
		if(rc.key>=H.R[j].key)
			break;
		H.R[s]=H.R[j];
		move++;
		s=j;
	}
	H.R[s]=rc;
	move++;
};

void HeapSort( SqList &H ,int &compare,int &move){//������
	int i;
	Snode ch;
	compare=move=0;
	for( i=H.length/2; i>0; i--)
		HeapAdjust( H, i, H.length , compare, move);
	for( i=H.length; i>1; i--){  
		ch=H.R[1];
		H.R[1]=H.R[i];
		H.R[i]=ch;
		move+=3;
		HeapAdjust( H, 1, i-1 , compare, move); 
	}
};
