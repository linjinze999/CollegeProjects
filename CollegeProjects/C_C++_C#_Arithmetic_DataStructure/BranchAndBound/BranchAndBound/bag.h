#include<string>
struct node//���ڵ���Ϣ
{
	std::string choose;//�����ַ�����01����ʾ��Ʒѡ���硰0100��
	int vector;        //������
	int value;         //����ֵ
	int up_bound;      //����Ͻ�
	int deep;          //������
};
void node_copy(node *node1,node node2);//����node
void node_extend(node *node_left,node *node_right,node extend_node,int *goods_value,int *goods_vector,int *goods_per_value,int bag_vector,int goods_number);//��չ�������ҽ��(���Ͻ����)
void InsertSort(int a[], int n);//�������򣬲��������
void getBagResult(int *goods_value,int *goods_vector,int goods_number,int bag_vector,int *result);//��ȡ��ѷ���
void setGoodsVV(int *goods_value,int *goods_vector,int goods_number,int bag_vector);//������ɼ�ֵ�����

