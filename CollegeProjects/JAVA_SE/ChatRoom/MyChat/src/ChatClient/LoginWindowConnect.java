/*
 * �ͻ��������ж�
 * */
package ChatClient;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

import javax.swing.JOptionPane;

public class LoginWindowConnect extends Thread{
	private String Name;
	private String IP;
	private int Port;
	private LoginWindow lw;
	private DataInputStream dis;
	private DataOutputStream dos;
	private Socket socket;
	
	public LoginWindowConnect( String IP, int Port,String Name,LoginWindow lw) throws IOException{
		this.IP=IP;
		this.Port=Port;
		this.Name=Name;
		this.lw=lw;
		if(this.isConnect(IP, Port)){//���ӷ�����
			if(!this.isHaveName(Name)){
				lw.setVisible(false);
				new ClientWindow(this,this.Name);//�򿪿ͻ���
			}
			else{//�û����Ѵ���
				dos.close();
	            dis.close();
	            socket.close();
	            JOptionPane.showMessageDialog(lw, "�û����Ѵ��ڣ�����������", "��½���", JOptionPane.ERROR_MESSAGE);
			}
		}
	}
	
	private boolean isConnect(String IP, int Port){//���ӷ�����
		try {
			this.socket = new Socket(IP,Port);
			dis = new DataInputStream(socket.getInputStream());
			dos = new DataOutputStream(socket.getOutputStream());
			return true;
		}catch (Exception e) {
			JOptionPane.showMessageDialog(lw, "���������ܻ�û����, ��ȷ������������", "�޷����ӵ�������", JOptionPane.ERROR_MESSAGE);
			return false;
		} 
	}
	
	private boolean isHaveName(String Name){//�û����Ƿ����
		try {
			dos.writeUTF(Name);
			String str;
			try {
				str = dis.readUTF();
				if(str.compareTo("1")==0)
					return true;
				else
					return false;
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return false;
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return false;
		}		
	}
	
	public Socket getSocket(){
		return this.socket;
	}
	
	public DataInputStream getDis(){
		return this.dis;
	}
	
	public DataOutputStream getDos(){
		return this.dos;
	}
	

}
