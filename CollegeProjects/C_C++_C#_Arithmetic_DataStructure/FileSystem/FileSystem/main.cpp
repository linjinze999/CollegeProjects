#include"FileSystem.h"
using namespace std;
void main(){
	FileSystem fs;
	char *diskname="test";
	fs.make_fs(diskname);
	fs.mount_fs(diskname);
	cout<<"创建成功！"<<endl;
	while(true){
		cout<<"****************************************"<<endl;
		cout<<"1、创建文件；"<<endl;
		cout<<"2、删除文件；"<<endl;
		cout<<"3、打开文件；"<<endl;
		cout<<"4、关闭文件；"<<endl;
		cout<<"5、读文件；"<<endl;
		cout<<"6、写文件；"<<endl;
		cout<<"7、得到文件大小；"<<endl;
		cout<<"8、光标移动；"<<endl;
		cout<<"9、截取文件；"<<endl;
		cout<<"你的选择：";
		int ch;
		char *name;
		cin>>ch;
		switch(ch){
		case 1:
			cout<<"输入文件名：";
			cin>>name;
			if(fs.fs_create(name)==0)
				cout<<"创建成功"<<endl;
			else
				cout<<"创建失败"<<endl;
			break;
		case 3:
			cout<<"输入文件名：";
			cin>>name;
			if(fs.fs_open(name)==0)
				cout<<"打开成功"<<endl;
			else
				cout<<"打开失败"<<endl;
			break;
		}
	}
}