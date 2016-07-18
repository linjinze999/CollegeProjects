#include <string.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

#define HASH_LEN 50 //��ϣ��ĳ��� 
#define M 47 //����
#define NAME_NO 30 //�����ĸ��� 

typedef struct NAME 
{
	char *py; //���ֵ�ƴ��
	int k; //ƴ������Ӧ������
}NAME;
NAME NameList[HASH_LEN]; 

typedef struct hterm //��ϣ��
{
	char *py; //���ֵ�ƴ��
	int k; //ƴ������Ӧ������
	int si; //���ҳ���
}HASH;
HASH HashList[HASH_LEN]; 


void InitNameList()//���ֳ�ʼ�� 
{
	NameList[0].py="wanghao";
	NameList[1].py="baoboyang";
	NameList[2].py="linjinze";
	NameList[3].py="lixueping";
	NameList[4].py="xiaopingguo";
	NameList[5].py="dujiaoshou";
	NameList[6].py="liuyifei";
	NameList[7].py="zhangxinyu";
	NameList[8].py="zhuyida";
	NameList[9].py="zhangxueyuan";
	NameList[10].py="jiangteng";
	NameList[11].py="wanghaotian";
	NameList[12].py="gaojiawei";
	NameList[13].py="chensixuan";
	NameList[14].py="guojianmin";
	NameList[15].py="zhaizexi";
	NameList[16].py="zhaojunyong";
	NameList[17].py="kuangzhenyu";
	NameList[18].py="xuxiao";
	NameList[19].py="caosuo";
	NameList[20].py="liangshengming";
	NameList[21].py="keziqin";
	NameList[22].py="zhangxi";
	NameList[23].py="zhouxin";
	NameList[24].py="chenyuanwei";
	NameList[25].py="lizijian";
	NameList[26].py="panhaoting";
	NameList[27].py="xueyanxing";
	NameList[28].py="yuxuanang";
	NameList[29].py="yansuo";

	char *f;
	int r,s0;

	for (int i=0;i<NAME_NO;i++)
	{
		s0=0;
		f=NameList[i].py;

		for (r=0;*(f+r) != NULL;r++) //����:���ַ����ĸ����ַ�����Ӧ��ASCII����ӣ����õ�������Ϊ��ϣ��Ĺؼ���
			s0=*(f+r)+s0;

		NameList[i].k=s0;
	} 
}

void CreateHashList()//������ϣ�� 
{
	for (int i=0; i<50; i ++)
	{
		HashList[i].py="";
		HashList[i].k=0;
		HashList[i].si=0;
	}
	for (int i=0; i < NAME_NO ; i++)
	{
		int sum=0;
		int adr=(NameList[i].k) % M; //��ϣ����
		int d=adr;
		if(HashList[adr].si==0) //����ͻ
		{
			HashList[adr].k=NameList[i].k;
			HashList[adr].py=NameList[i].py;
			HashList[adr].si=1;
		}
		else //��ͻ 
		{
			do{
				d++; 
				sum=sum+1;
			}while (HashList[d].k!=0);

			HashList[d].k=NameList[i].k;
			HashList[d].py=NameList[i].py;
			HashList[d].si=sum+1;
		}
	}
}


void FindList()//���� 
{ 
	cout<<"������������ƴ��:";
	char name[20]={0}; 
	cin>>name;

	int s0=0;
	for (int r=0;r<20;r++) //��ؼ���
		s0+=name[r]; 

	int sum=1;
	int adr=s0 % M; //ʹ�ù�ϣ����
	int d=adr;

	if(HashList[adr].k==s0) 
		cout<<"����:"<<HashList[d].py<<"  �ؼ���:"<<s0<<"  ���ҳ���Ϊ: 1"<<endl;
	else if (HashList[adr].k==0) 
		cout<<"�޸ü�¼!";
	else
	{
		int g=0;
		do
		{
			d++; 
			sum=sum+1;
			if (HashList[d].k==0)
			{
				cout<<"�޼�¼!"<<endl;
				g=1; 
			}
			if (HashList[d].k==s0)
			{ 
				cout<<"����:"<<HashList[d].py<<"  �ؼ���:"<<s0<<"  ���ҳ���Ϊ: "<<sum<<endl;
				g=1; 
			}
		}while(g==0); 
	} 
}


void Display()//��ʾ��ϣ�� 
{
	cout<<"\n��ַ\t�ؼ���\t\t��������\tH(key)\t\tƴ�� \n";

	for(int i=0; i<50; i++)
	{
		cout<<i;
		cout<<"\t"<<HashList[i].k;
		cout<<"\t\t"<<HashList[i].si;
		cout<<"\t\t"<<(HashList[i].k)%M;
		cout<<"\t\t"<<HashList[i].py;
		cout<<endl;
	}

	float average=0;
	for (int i=0;i <50;i ++)
		if(HashList[i].si!=0)
			average+=HashList[i].si;
	average=average/NAME_NO;
	cout<<"ƽ�����ҳ���:ASL("<<NAME_NO<<")="<<average<<" \n\n";
}


void main(){
	InitNameList(); 
	CreateHashList (); 
	int i=0;
	while(true)
	{
		cout<<"\n------------------------��ϣ��Ľ����Ͳ���----------------------"<<endl;
		cout<<" 1. ��ʾ��ϣ��\n";
		cout<<" 2. ����\n";
		cout<<" 3. �˳�\n";
		cout<<"��ѡ��";
		cin>>i;
		switch(i){
		case 1:
			Display(); 
			break;
		case 2:
			FindList();
			break;
		case 3:
			goto H;
			break;
		default:
			break;
		}
		cout<<endl<<endl;
	}
H:;
}