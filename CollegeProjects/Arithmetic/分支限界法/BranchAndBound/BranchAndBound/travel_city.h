#include<string>
#include<vector>
struct city_node//���ڵ���Ϣ
{
	std::string choose;//�����ַ�������ʾ·�̣��硰1324��
	int down_bound;    //����½�
	int deep;          //������
};


void getTravelResult(int city_number,int *city_cost,int *city_travel_result,int choose);//�õ�����·��
void node_copy(city_node *node1,city_node node2);//���ƽ��
void getTwoLineMin(int *city_cost,int lineNo,int city_number,int *min1,int *min2);//�õ�һ���г�������������С��ֵ
void getOneLineMin(int *city_cost,int lineNo,int city_number,int *min,std::string travel,int node_deep);//�õ�һ���г�����ͱ�ѡ��ֵ����С��ֵ
bool getNodeExtend(city_node extend_node,std::vector<city_node> *node_form,int city_number,int *city_cost);//��չ���
void setCost(int city_number,int *city_cost);//������ɳ��м��·�̣����ã�