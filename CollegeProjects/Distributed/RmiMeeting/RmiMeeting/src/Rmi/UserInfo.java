package Rmi;

public class UserInfo {//�û���Ϣ
	private String name = "client";//�û���
	private String password = "client";//�û�����
	
	public UserInfo(String name, String password){
		//��ʼ��
		this.setName(name);
		this.setPassword(password);
	}
	//getter
	public String getName(){
		return this.name;
	}
	
	public String getPassword(){
		return this.password;
	}
	//setter
	public void setName(String name){
		this.name = name;
	}
	
	public void setPassword(String password){
		this.password = password;
	}
}
