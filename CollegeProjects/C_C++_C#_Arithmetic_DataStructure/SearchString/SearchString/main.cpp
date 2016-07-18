#include <iostream>
#include<string>
#include<conio.h>
using namespace std;

void  search( string  S, string T, int &place,int &times )//��ͨƥ��
{   
	int i =0;
	int j = 0;
	times = 0;
	while ( i < (int)S.length()  &&  j < (int)T.length() ) 	 
	{  
		if ( S[i] == T[j] ) {
			++i ;
			++j ;
		} 	
		else {
			i = i - j + 1;
			j = 0;
		}      	
		times ++;//ѭ������
	}
	if (  j >= (int)T.length() ) //ƥ��λ��
		place = i-T.length()+1;
	else 
		place = -1;
}
void  Get_next( string T, int  next[] ){  //KMP���Ӵ��ַ���Ӧ��next
	int j = 0; 
	int k = -1; 
	next[0]=-1;
	while ( j < (int)T.length() ){  
		if (k == -1 ||  T[j] == T[k] ){
			++j ;
			++k ;
			next[j]=k;	   
    	}
	    else{
			k = next[k]; 
		}

	}
}
void  search_KMP( string  S, string T, int &place,int &times){ //KMPƥ��
	int i = 0; 
	int j = 0;
	times = 0;
	int next[100];
	Get_next(T,next);//�õ��Ӵ���next
	while ( i < (int)S.length()  &&  j < (int)T.length() )
	{ 
		if ( j == -1 || S[i] == T[j] )   { ++i ;  ++j ;  }
		else  j = next[ j ];  
		times++;//ѭ������
	}
	if (  j >= (int)T.length () )  place =  i-T.length()+1;  //ƥ��λ��  
	else place = -1;
}  

void main(){
	int place,times;
	string s,t;
	while(true){
		cout<<"������������";
		cin>>s;
		cout<<"�������Ӵ���";
		cin>>t;
		search(s,t,place,times);//��ͨƥ��
		cout<<"��ͨƥ�䣺"<<endl;
		if(place == -1){
			cout<<"��ƥ�䣬ѭ��������"<<times<<endl;
		}
		else{
			cout<<"ƥ�䣬ƥ��λ��Ϊ��"<<place<<"��ѭ������Ϊ��"<<times<<endl;
		}
		search_KMP(s,t,place,times);
		cout<<"KMPƥ�䣺"<<endl;//KMPƥ��
		if(place == -1){
			cout<<"��ƥ�䣬ѭ��������"<<times<<endl;
		}
		else{
			cout<<"ƥ�䣬ƥ��λ��Ϊ��"<<place<<"��ѭ������Ϊ��"<<times<<endl;
		}
		cout<<"�����������>>>>>>>>>>>>>>>>";
		_getch();
		cout<<endl<<endl;
	}
}

