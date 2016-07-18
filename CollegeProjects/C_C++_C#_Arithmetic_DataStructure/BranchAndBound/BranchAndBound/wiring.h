#include<iostream>
#include<vector>

struct wiring_node//��·�ڵ���Ϣ
{
	int x;					//���x����
	int y;					//���y����
	int bound;				//��㺯��ֵ
	int deep;				//������
	std::vector<int> path;	//·��
};

void getWiring(int circuit_number,int *circuit_start,int *circuit_end,std::vector<int> *result);//�õ���·����
bool wiring_node_extend(wiring_node extend_node,int bound,int *circuit_end,std::vector<wiring_node> *son_node);//��չ���
void wiring_node_copy(wiring_node *node1,wiring_node node2);//��㸴��