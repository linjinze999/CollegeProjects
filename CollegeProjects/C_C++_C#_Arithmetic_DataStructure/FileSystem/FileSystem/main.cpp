#include"FileSystem.h"
using namespace std;
void main(){
	FileSystem fs;
	char *diskname="test";
	fs.make_fs(diskname);
	fs.mount_fs(diskname);
	cout<<"�����ɹ���"<<endl;
	while(true){
		cout<<"****************************************"<<endl;
		cout<<"1�������ļ���"<<endl;
		cout<<"2��ɾ���ļ���"<<endl;
		cout<<"3�����ļ���"<<endl;
		cout<<"4���ر��ļ���"<<endl;
		cout<<"5�����ļ���"<<endl;
		cout<<"6��д�ļ���"<<endl;
		cout<<"7���õ��ļ���С��"<<endl;
		cout<<"8������ƶ���"<<endl;
		cout<<"9����ȡ�ļ���"<<endl;
		cout<<"���ѡ��";
		int ch;
		char *name;
		cin>>ch;
		switch(ch){
		case 1:
			cout<<"�����ļ�����";
			cin>>name;
			if(fs.fs_create(name)==0)
				cout<<"�����ɹ�"<<endl;
			else
				cout<<"����ʧ��"<<endl;
			break;
		case 3:
			cout<<"�����ļ�����";
			cin>>name;
			if(fs.fs_open(name)==0)
				cout<<"�򿪳ɹ�"<<endl;
			else
				cout<<"��ʧ��"<<endl;
			break;
		}
	}
}