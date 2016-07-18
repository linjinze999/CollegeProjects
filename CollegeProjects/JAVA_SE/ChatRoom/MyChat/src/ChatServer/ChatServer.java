/*
 * ������������ȿ����˷������ٿ����ͻ��˵�½����
 * */
package ChatServer;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.BindException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.util.ArrayList;
import java.util.List;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;




public class ChatServer extends JFrame{
	private ServerSocket ss = null;//������
	private boolean started = false;//�������������
	List<ChatClient> clients = new ArrayList<ChatClient>();//�ͻ����߳�
	List<String> users_name = new ArrayList<String>();//�ͻ����̶߳�Ӧ�ͻ���
	
	private JPanel panel_startServer,panel_server,panel_users,panel_message,panel_sendmessage,panel;
	private JTextArea text_port,text_user,text_sendmessage,text_receivemessage;
	private JLabel label_startServer;
	private JButton button_startServer,button_sendmessage;
	private JComboBox box_sendto;
	
	public void creatServerWindow(){//��ʼ������
		label_startServer = new JLabel("�������˿ں�:");
		label_startServer.setFont(new Font("�������˿ں�", 5,19));
		button_startServer = new JButton("����������");
		text_port = new JTextArea();
		text_port.setText("4444");
		text_port.setPreferredSize(new Dimension(100,25));
		text_port.setBorder(BorderFactory.createLineBorder(Color.gray));
		
		panel_startServer = new JPanel();
		panel_startServer.add(label_startServer);
		panel_startServer.add(text_port);
		panel_startServer.add(button_startServer);
		panel_startServer.setPreferredSize(new Dimension(480,65));
		panel_startServer.setBorder(BorderFactory.createTitledBorder("��������Ϣ"));
		
		panel_server = new JPanel();
		panel_server.setPreferredSize(new Dimension(500,72));
		panel_server.add(panel_startServer);
		
		text_user = new JTextArea();
		text_user.setRows(23);
		text_user.setColumns(13);
		text_user.setEditable(false);
		text_user.setLineWrap(true);
		//text_user.setBorder(BorderFactory.createLineBorder(Color.gray));
		panel_users = new JPanel();
		panel_users.add(new JScrollPane(text_user));
		panel_users.setBorder(BorderFactory.createTitledBorder("�����û�"));
		
		box_sendto = new JComboBox();
		box_sendto.addItem("�����û�");
		box_sendto.setPreferredSize(new Dimension(310,25));
		text_receivemessage = new JTextArea();
		text_receivemessage.setRows(18);
		text_receivemessage.setColumns(28);
		text_receivemessage.setEditable(false);
		text_receivemessage.setLineWrap(true);
		//text_receivemessage.setBorder(BorderFactory.createLineBorder(Color.gray));
		text_sendmessage = new JTextArea();
		text_sendmessage.setRows(3);
		text_sendmessage.setColumns(22);
		text_sendmessage.setLineWrap(true);
		//text_sendmessage.setBorder(BorderFactory.createLineBorder(Color.gray));
		button_sendmessage = new JButton("����");
		button_sendmessage.setPreferredSize(new Dimension(60,53));
		panel_sendmessage = new JPanel();
		panel_sendmessage.add(box_sendto);
		panel_sendmessage.add(new JScrollPane(text_receivemessage));
		panel_sendmessage.add(new JScrollPane(text_sendmessage));
		panel_sendmessage.add(button_sendmessage);
		panel_sendmessage.setPreferredSize(new Dimension(327,400));
		panel_sendmessage.setBorder(BorderFactory.createTitledBorder("������Ϣ"));
		
		panel = new JPanel();
		panel.setLayout(new BorderLayout());
		panel.add(panel_server,BorderLayout.NORTH);
		panel.add(panel_sendmessage,BorderLayout.WEST);
		panel.add(panel_users,BorderLayout.EAST);
		
		this.add(panel);
		this.setVisible(true);
		this.setSize(500, 550);
		this.setLocationRelativeTo(getOwner());
		this.setResizable(false); 
		this.setTitle("������");
		
		this.addWindowListener(new WindowAdapter(){//�رմ����¼�
			public void windowClosing(WindowEvent e) {
				if(started){
					stop();
				}
                System.exit(0);
			}
		});
		
		button_startServer.addActionListener(new ActionListener(){//������������ť�¼�

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(!started){
					start();
				}
				else{
					stop();
				}
			}});
		
		button_sendmessage.addActionListener(new ActionListener(){

			@Override
			public void actionPerformed(ActionEvent arg0) {
				// TODO Auto-generated method stub
				mySend();
			}});
	}
	
	public void start() {//����������
        try {
            ss = new ServerSocket(Integer.parseInt(text_port.getText()));
            started = true;
            button_startServer.setText("ֹͣ������");
            text_receivemessage.setText(text_receivemessage.getText() + "����������" + '\n');
            accept ac=new accept();
            new Thread(ac).start();
        } catch (BindException e) {
        	//text_message.setText(text_message.getText() + "����ʧ�ܣ��˿�ʹ����" + '\n');
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
	
	class accept implements Runnable{//�ں�˽��ܿͻ���
		public accept(){
			
		}
		@Override
		public void run() {
			// TODO Auto-generated method stub
			try {
	        	while (started) {
	                Socket s = ss.accept(); //���տͻ���
	                ChatClient c = new ChatClient(s);
	                new Thread(c).start(); //�����߳�
	            }
	        } catch (IOException e) {
	            e.printStackTrace();
	        }
		}
		
	}
	
	public void stop(){//ֹͣ������
		try {
			started = false;
			ss.close();
			button_startServer.setText("����������");
			text_receivemessage.setText(text_receivemessage.getText() + "ֹͣ������" + '\n');
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void mySend(){//������������Ϣ
		if(started){
			String sendto = box_sendto.getSelectedItem().toString();
			String message = text_sendmessage.getText();
			text_sendmessage.setText("");
			if(sendto.compareTo("�����û�")==0)
			{
				text_receivemessage.setText(text_receivemessage.getText() + " [Ⱥ��] ��������" + message + '\n');
				for (int i = 0; i < clients.size(); i++) {
	                ChatClient c = clients.get(i);
	                c.send("1" + " [Ⱥ��] ��������" + message);
	            }
			}
			else
			{
				text_receivemessage.setText(text_receivemessage.getText() + " [˽��] ��������" + message + '\n');
				for (int i = 0; i < users_name.size(); i++) {
					String un = users_name.get(i);
					if(sendto.compareTo(un)==0){
						ChatClient c = clients.get(i);
	                    c.send("1" + " [˽��] ��������" + message);
	                    break;
					}
	                
	            }
			}
		}
		else{
			text_receivemessage.setText(text_receivemessage.getText() + "Error��������δ������" + '\n');
		}
	}
	
	class ChatClient implements Runnable{//һ���ͻ����߳�(��������������Ϣ���ͻ��˻���ӷ���Ϣ)
		private Socket s;
        DataInputStream dis = null;
        DataOutputStream dos = null;
        boolean bConnected = false;
        boolean exist = false;
        
        public ChatClient(Socket s) {
            this.s = s;
            try {
                dis = new DataInputStream(s.getInputStream());
                dos = new DataOutputStream(s.getOutputStream());
                bConnected = true;
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        void send(String str) {
            try {
                dos.writeUTF(str);
            } catch (SocketException e) {
            	
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
		@Override
		public void run() {
			// TODO Auto-generated method stub
			try {
				String name = dis.readUTF();
				for(int n = 0; n < users_name.size(); n++){
					String nm = users_name.get(n);
					if(name.compareTo(nm)==0){
						exist = true;
					}
				}
				if(exist){//�û����Ѿ�����
					dos.writeUTF("1");
					dis.close();
                    s.close();
                    dos.close();
                    text_receivemessage.setText(text_receivemessage.getText() + name + "�ظ���¼ʧ��" + '\n');//���������ظ�������ʾ
                    bConnected = false;
                    exist = false;
				}
				else{//�û���������
					text_receivemessage.setText(text_receivemessage.getText() + name + "������" + '\n');//��������������ʾ
					box_sendto.addItem(name);//�������������Ͷ���
					text_user.setText(text_user.getText()+ name +'\n');//���������û�
	                clients.add(this); //��ӿͻ���
	                users_name.add(name);
	                for (int i = 0; i < clients.size(); i++) {//���пͻ�����������
                        ChatClient c = clients.get(i);
                        c.send("01"+name);
                    }
	                
	                for(int j=0;j<users_name.size()-1;j++){//���¿ͻ��˷��������û�
	                	send("01" + users_name.get(j));
	                }
	                
					while(bConnected){//���ܿͻ�����Ϣ
						String str = dis.readUTF();
						if(str.startsWith("0")){//�ͻ����˳�
							str = str.substring(1);
							for(int n = 0; n < users_name.size(); n++){
								String nm = users_name.get(n);
								if(str.compareTo(nm)==0){
									clients.get(n).bConnected=false;//�Ƴ��ÿͻ���
									clients.remove(n);
									users_name.remove(n);
									text_receivemessage.setText(text_receivemessage.getText() + str + "������" + '\n');//����������������
									text_user.setText(text_user.getText().replaceFirst(str+'\n', ""));//�������û���ɾ�������û�
									box_sendto.removeItem(str);//�Ƴ����Ͷ���
									str = "00" + str;
									bConnected = false;
									for (int i = 0; i < clients.size(); i++) {//�ͻ��˵���������
				                        ChatClient c = clients.get(i);
				                        c.send(str);
				                    }
									break;
								}
							}
						}
						else{//������Ϣ
							str = str.substring(1);
							String sendto = null;
							int p = str.indexOf(":");
							sendto=String.copyValueOf(str.toCharArray(), 0, p);
							str = str.substring(p+1);
							if(sendto.compareTo("�����û�")==0){//Ⱥ��
								str = " [Ⱥ��] " + str;
								text_receivemessage.setText(text_receivemessage.getText() + str + '\n');
								for (int i = 0; i < clients.size(); i++) {
			                        ChatClient c = clients.get(i);
			                        c.send("1"+str);
			                    }
							}
							else if(sendto.compareTo("������")==0){//˽�ķ�����
								text_receivemessage.setText(text_receivemessage.getText() + " [˽��] " + str + '\n');
								p = str.indexOf(":");
								sendto=String.copyValueOf(str.toCharArray(), 0, p);
								for (int i = 0; i < users_name.size(); i++) {
									String un = users_name.get(i);
									if(sendto.compareTo(un)==0){
										ChatClient c = clients.get(i);
				                        c.send("1" + " [˽��] " + str);
				                        break;
									}
			                        
			                    }
							}
							else{//˽�Ŀͻ���
								for (int i = 0; i < users_name.size(); i++) {
									String un = users_name.get(i);
									if(sendto.compareTo(un)==0){
										ChatClient c = clients.get(i);
				                        c.send("1"+" [˽��] " + str);
				                        break;
									}
			                        
			                    }
								p = str.indexOf(":");
								sendto=String.copyValueOf(str.toCharArray(), 0, p);
								for (int i = 0; i < users_name.size(); i++) {
									String un = users_name.get(i);
									if(sendto.compareTo(un)==0){
										ChatClient c = clients.get(i);
				                        c.send("1"+" [˽��] " + str);
				                        break;
									}
			                        
			                    }
							}
							
						}
						
					}
				}
				
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}finally {
                if (dis != null)
                    if (s != null)
                        try {
                            dis.close();
                            s.close();
                            dos.close();
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
            }
			
		}}
	
	public ChatServer(){//��ĳ�ʼ��
		this.creatServerWindow();
	}
	
	public static void main(String[] args) {
		new ChatServer();
    }
	
}
