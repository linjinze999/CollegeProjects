#include<iostream>
#include<vector>
#include<time.h>
#include<string>
#include<sstream>
#include"travel_city.h"

void getTravelResult(int city_number,int *city_cost,int *city_travel_result,int choose)//�õ�����·��
{
	std::vector<city_node> PT;//PT��
	city_node *root=new city_node; //���ڵ�
	std::stringstream ss;
	ss<<choose;
	ss>>(*root).choose;
	for(int i=1;i<city_number;i++)
		(*root).choose+="0";
	(*root).deep=0;
	(*root).down_bound=0;
	PT.push_back(*root);

	std::vector<city_node> node_form;
	while(PT.size()>0)
	{
		int extend_node_min_down_bound=1000000;	//PT������С�½�ֵ
		int extend_node_position;				//PT������С�½�����λ��
		for(unsigned int n=0;n < PT.size();n++)	//ȡ�Ͻ����Ľ��Ϊ��չ���
			if(extend_node_min_down_bound>PT[n].down_bound){
				extend_node_position=n;
				extend_node_min_down_bound=PT[n].down_bound;
			}
		city_node *extend_node=new city_node;
		node_copy(extend_node,PT[extend_node_position]);//������չ���
		PT.erase(PT.begin()+extend_node_position);		//ɾ����չ���

		if(getNodeExtend(*extend_node,&node_form,city_number,city_cost)){//��չ���
			for(unsigned int i=0;i<(node_form).size();i++){
				PT.push_back((node_form)[i]);
			}
		}
		else{//Ҷ�ڵ�
			bool best=true;
			for(unsigned int i=0;i<PT.size();i++){//�Ƿ�����
				if((*extend_node).down_bound>PT[i].down_bound)
					best=false;
			}
			if(best){//����
				for(int i=0;i<city_number;i++){
					city_travel_result[i]=(*extend_node).choose[i]-48;
				}
				break;
			}
			else{//��������
				for(unsigned int i=0;i<PT.size();i++){
					if((*extend_node).down_bound<PT[i].down_bound){
						PT.erase(PT.begin()+i);
						i=-1;
					}
				}
			}
		}
		(node_form).clear();
	}

};

void node_copy(city_node *node1,city_node node2)//���ƽ��
{
	(*node1).choose=node2.choose;
	(*node1).deep=node2.deep;
	(*node1).down_bound=node2.down_bound;
}

void getTwoLineMin(int *city_cost,int lineNo,int city_number,int *min1,int *min2)//�õ�һ���г�������������С��ֵ
{
	std::vector<int> line;
	for(int i=0;i<city_number;i++)//ȥ������
	{
		if(i!=lineNo)
			line.push_back(city_cost[lineNo*city_number+i]);
	}
	int MinPosition=-1;
	int MinCost=100;
	for(unsigned int i=0;i<line.size();i++)//�ҵ���Сֵ
	{
		if(line[i]<MinCost){
			MinPosition=i;
			MinCost=line[i];
		}
	}
	*min1=MinCost;
	line.erase(line.begin()+MinPosition);
	MinCost=100;
	for(unsigned int i=0;i<line.size();i++)//�ҵ��ڶ���Сֵ
	{
		if(line[i]<MinCost){
			MinPosition=i;
			MinCost=line[i];
		}
	}
	*min2=MinCost;
};

void getOneLineMin(int *city_cost,int lineNo,int city_number,int *min,std::string travel,int node_deep)//�õ�һ���г�����ͱ�ѡ��ֵ����С��ֵ
{
	int position=-1;
	for(int i=0;i<node_deep+1;i++)//ȥ��·���г���
		if((int)(travel[i]-49)==lineNo){
			position=i;
			break;
		}
	std::vector<int> line;
	if(position==0){
		for(int i=0;i<city_number;i++)
			if(i!=lineNo && i!=((int)travel[1]-49))
				line.push_back(city_cost[lineNo*city_number+i]);
	}
	else{
		for(int i=0;i<city_number;i++)
			if(i!=lineNo && i!=(int)(travel[node_deep-1]-49))
				line.push_back(city_cost[lineNo*city_number+i]);
	}
	int MinPosition=-1;
	int MinCost=100;
	for(unsigned int i=0;i<line.size();i++)//����Сֵ
	{
		if(line[i]<MinCost){
			MinCost=line[i];
			MinPosition=i;
		}
	}
	*min=MinCost;
};

bool getNodeExtend(city_node extend_node,std::vector<city_node> *node_form,int city_number,int *city_cost){//��չ���
	int node_number=city_number-extend_node.deep-1;
	if(node_number>0){
		char no='1';
		for(int i=0;i<node_number;i++)				//�ӽ�����
		{
			city_node *son_node=new city_node;
			(*son_node).deep=extend_node.deep+1;	//������
			(*son_node).choose=extend_node.choose;	//���·��
			bool exist=false;
			for(;(int)(no-48)<=city_number;no++){
				for(int n=0;n<extend_node.deep+1;n++)
					if(no==extend_node.choose[n]){
						exist=true;
						break;
					}
				if(!exist){
					(*son_node).choose[extend_node.deep+1]=no;
					no++;
					break;
				}
				exist=false;
			}
			(*son_node).down_bound=0;				//����½�ֵ
			int min=0;
			for(int m=0;m<(*son_node).deep;m++){
				(*son_node).down_bound += 2*city_cost[((int)(*son_node).choose[m]-49)*city_number+((int)(*son_node).choose[m+1]-49)];
			}
			getOneLineMin(city_cost,((int)(*son_node).choose[0]-49),city_number,&min,(*son_node).choose,(*son_node).deep);
			(*son_node).down_bound += min;
			getOneLineMin(city_cost,((int)(*son_node).choose[(*son_node).deep]-49),city_number,&min,(*son_node).choose,(*son_node).deep);
			(*son_node).down_bound += min;
			int min1=0;
			int min2=0;
			for(int m=0;m<city_number;m++)
			{
				exist=false;
				for(int j=0;j<=(*son_node).deep;j++)
					if(m==((int)(*son_node).choose[j]-49))
						exist=true;
				if(!exist){
					getTwoLineMin(city_cost,m,city_number,&min1,&min2);
					(*son_node).down_bound += (min1+min2);
				}
			}
			(*son_node).down_bound=(*son_node).down_bound/2;
			int remainder=(*son_node).down_bound%2;
			if(remainder>0)
				(*son_node).down_bound+=1;
			(*node_form).push_back(*son_node);
		}
		return true;
	}
	else{
		return false;
	}
	
};

void setCost(int city_number,int *city_cost)//������ɳ��м��·�̣����ã�
{
	srand((int)time(0));
	int r=rand()%9;
	for(int i=0;i<city_number;i++)
		for(int n=i;n<city_number;n++){
			if(n==i)
				city_cost[i*city_number+n]=100;
			else{
				if(r==0)
					r=9;
				city_cost[i*city_number+n]=r;
				city_cost[n*city_number+i]=r;
				r=((r+1)*157)%9;
			}
		}
};