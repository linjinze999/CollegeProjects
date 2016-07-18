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
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;




public class ChatServer extends JFrame{
	private ServerSocket ss = null;//������
	private boolean started = false;//�������������
	List<ChatClient> clients = new ArrayList<ChatClient>();//�ͻ����߳�
	List<String> users_name = new ArrayList<String>();//�ͻ����̶߳�Ӧ�ͻ���
	
	private JPanel panel_startServer,panel_users,panel_message,panel;
	private JTextArea text_port,text_user,text_message;
	private JLabel label_startServer;
	private JButton button_startServer;
	
	public void creatServerWindow(){//��ʼ������
		label_startServer = new JLabel("�������˿ںţ�");
		label_startServer.setFont(new Font("�������˿ں�", 5,20));
		button_startServer = new JButton("����������");
		text_port = new JTextArea();
		text_port.setText("4444");
		text_port.setPreferredSize(new Dimension(100,25));
		text_port.setBorder(BorderFactory.createLineBorder(Color.gray));
		
		panel_startServer = new JPanel();
		panel_startServer.add(label_startServer);
		panel_startServer.add(text_port);
		panel_startServer.add(button_startServer);
		panel_startServer.setBorder(BorderFactory.createTitledBorder("��������Ϣ"));
		
		text_user = new JTextArea();
		text_user.setRows(26);
		text_user.setColumns(14);
		text_user.setEditable(false);
		text_user.setBorder(BorderFactory.createLineBorder(Color.gray));
		panel_users = new JPanel();
		panel_users.add(text_user);
		panel_users.setBorder(BorderFactory.createTitledBorder("�����û�"));
		
		text_message = new JTextArea();
		text_message.setRows(26);
		text_message.setColumns(27);
		text_message.setEditable(false);
		text_message.setBorder(BorderFactory.createLineBorder(Color.gray));
		panel_message = new JPanel();
		panel_message.add(text_message);
		panel_message.setBorder(BorderFactory.createTitledBorder("��Ϣ����"));
		
		panel = new JPanel();
		panel.setLayout(new BorderLayout());
		panel.add(panel_startServer,BorderLayout.NORTH);
		panel.add(panel_message,BorderLayout.WEST);
		panel.add(panel_users,BorderLayout.EAST);
		
		this.add(panel);
		this.setVisible(true);
		this.setSize(500, 600);
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
	}
	
	public void start() {//����������
        try {
            ss = new ServerSocket(Integer.parseInt(text_port.getText()));
            text_message.setText(text_message.getText() + "����������" + '\n');
            started = true;
            button_startServer.setText("ֹͣ������");
            accept ac=new accept();
            new Thread(ac).start();
        } catch (BindException e) {
        	text_message.setText(text_message.getText() + "����ʧ�ܣ��˿�ʹ����" + '\n');
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
			ss.close();
			text_message.setText(text_message.getText() + "ֹͣ������" + '\n');
			started = false;
			button_startServer.setText("����������");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	class ChatClient implements Runnable{//һ���ͻ����߳�
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
					text_message.setText(text_message.getText() + name + "������ʧ��" + '\n');//������������ʧ����ʾ
					dos.writeUTF("1");
					dis.close();
                    s.close();
                    dos.close();
                    bConnected = false;
                    exist = false;
				}
				else{//�û���������
					text_message.setText(text_message.getText() + name + "������" + '\n');//��������������ʾ
					text_user.setText(text_user.getText()+ name +'\n');
	                clients.add(this); //��ӿͻ���
	                users_name.add(name);
	                for (int i = 0; i < clients.size(); i++) {//���пͻ�����������
                        ChatClient c = clients.get(i);
                        c.send("01"+name);
                    }
	                
	                for(int j=0;j<users_name.size();j++){//���¿ͻ��˷��������û�
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
									text_message.setText(text_message.getText() + str + "������" + '\n');//����������������
									text_user.setText(text_user.getText().replaceFirst(str+'\n', ""));
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
								for (int i = 0; i < clients.size(); i++) {
			                        ChatClient c = clients.get(i);
			                        c.send("1"+str);
			                    }
							}
							else{//˽��
								for (int i = 0; i < users_name.size(); i++) {
									String un = users_name.get(i);
									if(sendto.compareTo(un)==0){
										ChatClient c = clients.get(i);
				                        c.send("1"+str);
				                        break;
									}
			                        
			                    }
								p = str.indexOf(":");
								sendto=String.copyValueOf(str.toCharArray(), 0, p);
								for (int i = 0; i < users_name.size(); i++) {
									String un = users_name.get(i);
									if(sendto.compareTo(un)==0){
										ChatClient c = clients.get(i);
				                        c.send("1"+str);
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
	
	public ChatServer(){
		this.creatServerWindow();
	}
	
	public static void main(String[] args) {
		new ChatServer();
    }
	
}
