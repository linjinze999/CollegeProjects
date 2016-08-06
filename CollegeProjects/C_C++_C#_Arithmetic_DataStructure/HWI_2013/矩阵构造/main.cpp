#include<iostream>
using namespace std;
int main(){
	int a;
    cin>>a;
    int array[20][20]={0};
    int b=0;
    int x=0,y=-1;
    int num=1;
    for(int i=a;i>0;i--){
    	if(b==0){
            for(int n=0;n<i;n++){
                array[x][++y]=num++;
            }
            b=1;
        }else if(b==1){
            for(int n=0;n<i;n++){
                array[++x][--y]=num++;
            }
        	b=2;
        }else{
            for(int n=0;n<i;n++){
                array[--x][y]=num++;
            }
        	b=0;
        }
    }
    for(int i=0;i<a;i++){
    	for(int n=0;n<a-i;n++){
            cout<<array[i][n]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}