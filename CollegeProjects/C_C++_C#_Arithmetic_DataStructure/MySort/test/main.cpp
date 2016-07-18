#include<iostream>
#include<bitset>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#define ARRAYLENGTH 10000 //数组大小
#define BitSize 32 //最大数据二进制形式所需的位数，此处假定为32位
using namespace std;

void BInsertSort(int number[]){
	// 折半插入排序，用于对比
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

void forming(int number[]){//随机生成数据
	srand(time(0));
	for(int a=0;a<ARRAYLENGTH;a++){
		number[a]= rand()%(ARRAYLENGTH*10);
	}
}

typedef  struct Sign{
	int key;
	struct Sign *next;
} Sign,*SN;//记录标记位


void main(){
	/**********新算法**********/
	int *array1=new int[ARRAYLENGTH];
	int *array2=new int[ARRAYLENGTH];//用于存放数据
	int usearray=1;//标记所使用的数组为array1或array2
	forming(array1);//生成数据

	clock_t  clockBegin, clockEnd; //计时
	clockBegin = clock();//计时开始

	SN sign,last;//将用于记录标记位的头尾指针
	sign=(SN)malloc(sizeof(Sign));
	last=(SN)malloc(sizeof(Sign));
	sign->key=0;
	last->key= ARRAYLENGTH;//数组大小
	sign->next=last;
	last->next=NULL;

	int low,high;//数据新存放位置下标
	int begin,end;//要查找的区域下标

	SN use;//获取标记位
	use=(SN)malloc(sizeof(Sign));
	for(int n=0;n<BitSize;n++){//从二进制的最高位比较至最低位
		use=sign;//从头指针开始获取标记位，此指针用于记录正在使用的指针
		if(usearray==1){//数据在array1中
			for(int a=0;a<pow((double)2,(double)n);a++){//按顺序使用所有的数组被区分开的区域
				begin=low=use->key;//将使用的区域开始下标
				end=high=use->next->key;//将使用的区域结束下标
				if(begin<end-1){//区域内还有未排序的数据
					for(int i=begin;i<end;i++){
						bitset<BitSize>bs(array1[i]);
						if(bs[BitSize-1-n]==1){
							high--;
							array2[high]=array1[i];//bit位为1的数据置于另外数组中使用的区域的末尾
						}
						else{
							array2[low]=array1[i];//bit位为0的数据置于另外数组中使用的区域的开头
							low++;
						}
					}
				}
				else{//区域内没有未排序数据
					for(int i=begin;i<end;i++){
						array2[i]=array1[i];
					} 
				}
				if(high==use->next->key){//已有标记位不再插入
					if(use->next->next)//数组中还有没使用过的区域
						use=use->next;
					else//数组已遍历
						break;
				}
				else{
					SN T;//插入新标记位
					T=(SN)malloc(sizeof(Sign));
					T->key=high;//下标值
					T->next=use->next;
					use->next=T;
					if(use->next->next->next){//数组中还有没使用过的区域(记得跳过新插入的数据)
						use=use->next->next;
					}
					else//数组已遍历
						break;
				}

			}
			usearray=2;//数据转移至array2
		}
		else{//数据在array2中
			for(int a=0;a<pow((double)2,(double)n);a++){
				begin=low=use->key;
				end=high=use->next->key;
				if(begin<end-1){
					for(int i=begin;i<end;i++){
						bitset<BitSize>bs(array2[i]);
						if(bs[BitSize-1-n]==1){
							high--;
							array1[high]=array2[i];//此处不同
						}
						else{
							array1[low]=array2[i];//此处不同
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
			usearray=1;//数据转移至array1中
		}
	}

	clockEnd = clock(); //排序完成，计时结束
	if(usearray==1){//新数据在array1中
		for(int a=0;a<100;a++)
			cout<<array1[a]<<" ";
	}
	else{//新数据在array2中
		for(int a=0;a<100;a++)
			cout<<array2[a]<<" ";
	}
	cout<<endl<<"新算法时间："<<clockEnd - clockBegin<<endl;//输出使用时间

	/**********折半插入排序***********/
	int *number=new int[ARRAYLENGTH];
	forming(number);//生成数据
	clockBegin = clock();//计时开始
	BInsertSort(number);//折半插入排序
	clockEnd = clock(); //计时结束
	cout<<endl<<"折半插入排序时间："<<clockEnd - clockBegin<<endl;//输出使用时间

	int stop;
	cin>>stop;
}