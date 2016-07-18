#include<time.h>
#include<iostream>
using namespace std;

int tile=1;

void ChessBoard(int chess[],int chess_length,int tr, int tc, int dr, int dc, int size)//���̸�������
{ 
	if(size == 1)  
    {
        return; 
    }  
    int t = tile++;//L�͹��Ʊ��
    int s = size/2;//�ָ�����  
  
    //�������Ͻ�������  
    if(dr<tr+s && dc<tc+s)//���ⷽ���ڴ�������  
    {  
        ChessBoard(chess,chess_length,tr,tc,dr,dc,s);  
    }  
    else//���ⷽ���ڴ�������
    {
        //�ñ��Ϊt�Ĺ��Ƹ������½�  
		chess[(tr+s-1)*chess_length+(tc+s-1)]=t;
        //�������෽��  
        ChessBoard(chess,chess_length,tr,tc,tr+s-1,tc+s-1,s);  
    }  
  
    //�������Ͻ�������  
    if(dr<tr+s && dc>=tc+s)//���ⷽ���ڴ�������  
    {  
        ChessBoard(chess,chess_length,tr,tc+s,dr,dc,s);  
    }  
    else//���ⷽ���ڴ�������  
    {  
        //�ñ��Ϊt�Ĺ��Ƹ������½�
		chess[(tr+s-1)*chess_length+(tc+s)]=t;
        //�������෽��  
        ChessBoard(chess,chess_length,tr,tc+s,tr+s-1,tc+s,s);  
    }  
  
    //�������½�������  
    if(dr>=tr+s && dc<tc+s)//���ⷽ���ڴ�������  
    {  
        ChessBoard(chess,chess_length,tr+s,tc,dr,dc,s);  
    }  
    else//���ⷽ���ڴ�������  
    {  
        //�ñ��Ϊt�Ĺ��Ƹ������Ͻ�  
		chess[(tr+s)*chess_length+(tc+s-1)]=t;
        //�������෽��  
        ChessBoard(chess,chess_length,tr+s,tc,tr+s,tc+s-1,s);  
    }  
  
    //�������½�������  
    if(dr>=tr+s && dc>=tc+s)//���ⷽ���ڴ�������  
    {  
        ChessBoard(chess,chess_length,tr+s,tc+s,dr,dc,s);  
    }  
    else//���ⷽ���ڴ�������  
    {  
        //�ñ��Ϊt�Ĺ��Ƹ������Ͻ�  
		chess[(tr+s)*chess_length+(tc+s)]=t;
        //�������෽��  
        ChessBoard(chess,chess_length,tr+s,tc+s,tr+s,tc+s,s);  
    }
};

void setPoint(int chess[],int chess_length,int &point_x,int &point_y)//������������
{
	srand((int)time(0));
	int r=rand() % 100;
	r = (r*157) % chess_length;
	int t = (r * 143) % chess_length;
	chess[(r)*chess_length + t] = 0;
	point_x = r;
	point_y = t;
};

void initChess(int chess[],int chess_length)//��ʼ������
{
	memset(chess,-1,chess_length*chess_length);
}