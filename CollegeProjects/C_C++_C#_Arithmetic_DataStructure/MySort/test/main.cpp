#include<iostream>
#include<bitset>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#define ARRAYLENGTH 10000 //�����С
#define BitSize 32 //������ݶ�������ʽ�����λ�����˴��ٶ�Ϊ32λ
using namespace std;

void BInsertSort(int number[]){
	// �۰�����������ڶԱ�
	int i,j,m,low,high;
	for(i=2;i<=ARRAYLENGTH;++i)
	{
		number[0]=number[i];
		low=1;
		high=i-1;
		while(low<=high) { 
			m=(low+high)/2; 
			if (number[0]<number[m])
				high=m-1; 
			else
				low=m+1; 
		}
		for(j=i-1;j>=high+1;--j){
			number[j+1]=number[j]; 
		}
		number[high+1]=number[0];
	}
};

void forming(int number[]){//�����������
	srand(time(0));
	for(int a=0;a<ARRAYLENGTH;a++){
		number[a]= rand()%(ARRAYLENGTH*10);
	}
}

typedef  struct Sign{
	int key;
	struct Sign *next;
} Sign,*SN;//��¼���λ


void main(){
	/**********���㷨**********/
	int *array1=new int[ARRAYLENGTH];
	int *array2=new int[ARRAYLENGTH];//���ڴ������
	int usearray=1;//�����ʹ�õ�����Ϊarray1��array2
	forming(array1);//��������

	clock_t  clockBegin, clockEnd; //��ʱ
	clockBegin = clock();//��ʱ��ʼ

	SN sign,last;//�����ڼ�¼���λ��ͷβָ��
	sign=(SN)malloc(sizeof(Sign));
	last=(SN)malloc(sizeof(Sign));
	sign->key=0;
	last->key= ARRAYLENGTH;//�����С
	sign->next=last;
	last->next=NULL;

	int low,high;//�����´��λ���±�
	int begin,end;//Ҫ���ҵ������±�

	SN use;//��ȡ���λ
	use=(SN)malloc(sizeof(Sign));
	for(int n=0;n<BitSize;n++){//�Ӷ����Ƶ����λ�Ƚ������λ
		use=sign;//��ͷָ�뿪ʼ��ȡ���λ����ָ�����ڼ�¼����ʹ�õ�ָ��
		if(usearray==1){//������array1��
			for(int a=0;a<pow((double)2,(double)n);a++){//��˳��ʹ�����е����鱻���ֿ�������
				begin=low=use->key;//��ʹ�õ�����ʼ�±�
				end=high=use->next->key;//��ʹ�õ���������±�
				if(begin<end-1){//�����ڻ���δ���������
					for(int i=begin;i<end;i++){
						bitset<BitSize>bs(array1[i]);
						if(bs[BitSize-1-n]==1){
							high--;
							array2[high]=array1[i];//bitλΪ1��������������������ʹ�õ������ĩβ
						}
						else{
							array2[low]=array1[i];//bitλΪ0��������������������ʹ�õ�����Ŀ�ͷ
							low++;
						}
					}
				}
				else{//������û��δ��������
					for(int i=begin;i<end;i++){
						array2[i]=array1[i];
					} 
				}
				if(high==use->next->key){//���б��λ���ٲ���
					if(use->next->next)//�����л���ûʹ�ù�������
						use=use->next;
					else//�����ѱ���
						break;
				}
				else{
					SN T;//�����±��λ
					T=(SN)malloc(sizeof(Sign));
					T->key=high;//�±�ֵ
					T->next=use->next;
					use->next=T;
					if(use->next->next->next){//�����л���ûʹ�ù�������(�ǵ������²��������)
						use=use->next->next;
					}
					else//�����ѱ���
						break;
				}

			}
			usearray=2;//����ת����array2
		}
		else{//������array2��
			for(int a=0;a<pow((double)2,(double)n);a++){
				begin=low=use->key;
				end=high=use->next->key;
				if(begin<end-1){
					for(int i=begin;i<end;i++){
						bitset<BitSize>bs(array2[i]);
						if(bs[BitSize-1-n]==1){
							high--;
							array1[high]=array2[i];//�˴���ͬ
						}
						else{
							array1[low]=array2[i];//�˴���ͬ
							low++;
						}
					}
				}
				else{
					for(int i=begin;i<end;i++){
						array1[i]=array2[i];
					}	 
				}
				if(high==use->next->key){
					if(use->next->next)
						use=use->next;
					else
						break;
				}
				else{
					SN T;
					T=(SN)malloc(sizeof(Sign));
					T->key=high;
					T->next=use->next;
					use->next=T;
					if(use->next->next->next){
						use=use->next->next;
					}
					else
						break;
				}
			}
			usearray=1;//����ת����array1��
		}
	}

	clockEnd = clock(); //������ɣ���ʱ����
	if(usearray==1){//��������array1��
		for(int a=0;a<100;a++)
			cout<<array1[a]<<" ";
	}
	else{//��������array2��
		for(int a=0;a<100;a++)
			cout<<array2[a]<<" ";
	}
	cout<<endl<<"���㷨ʱ�䣺"<<clockEnd - clockBegin<<endl;//���ʹ��ʱ��

	/**********�۰��������***********/
	int *number=new int[ARRAYLENGTH];
	forming(number);//��������
	clockBegin = clock();//��ʱ��ʼ
	BInsertSort(number);//�۰��������
	clockEnd = clock(); //��ʱ����
	cout<<endl<<"�۰��������ʱ�䣺"<<clockEnd - clockBegin<<endl;//���ʹ��ʱ��

	int stop;
	cin>>stop;
}