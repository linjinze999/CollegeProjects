/*
 * �ͻ����û���Ϣ���棬�ͻ��������������
 * */
package ChatClient;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.border.Border;

import ChatServer.ChatServer;

public class ClientWindow extends JFrame {
	private JPanel panel_message,panel_users,panel,panel_sendto,panel_send;
	private JLabel label_sendto;
	private JComboBox box_sendto;
	private JTextArea text_receive,text_users,text_send;
	private JButton button_send;
	private boolean connect;
	recvThread r = new recvThread();
	
	private Socket socket;
	private DataInputStream dis;
	private DataOutputStream dos;
	private String name;
	public void creatClientWindow(String Name){//�ͻ��˽���
		label_sendto = new JLabel("���͸�:");
		box_sendto = new JComboBox();
		box_sendto.addItem("�����û�");
		box_sendto.addItem("������");
		box_sendto.setPreferredSize(new Dimension(360,30));
		text_receive = new JTextArea();
		text_receive.setRows(20);
		text_receive.setColumns(30);
		text_receive.setEditable(false);
		text_receive.setLineWrap(true);
		//text_receive.setBorder(BorderFactory.createLineBorder(Color.GRAY));
		text_send = new JTextArea();
		text_send.setRows(3);
		text_send.setColumns(30);
		text_send.setLineWrap(true);
		//text_send.setBorder(BorderFactory.createLineBorder(Color.DARK_GRAY));
		button_send = new JButton("����");
		button_send.setPreferredSize(new Dimension(70,55));
		
		panel_message = new JPanel();
		panel_message.setLayout(new BorderLayout());
		panel_sendto = new JPanel();
		panel_sendto.add(label_sendto);
		panel_sendto.add(box_sendto);
		panel_message.add(panel_sendto,BorderLayout.NORTH);
		panel_message.add(new JScrollPane(text_receive),BorderLayout.CENTER);
		panel_send = new JPanel();
		panel_send.add(new JScrollPane(text_send));
		panel_send.add(button_send);
		panel_message.add(panel_send,BorderLayout.SOUTH);
		panel_message.setBorder(BorderFactory.createTitledBorder("������Ϣ"));
		panel_message.setSize(400,300);
		
		text_users = new JTextArea();
		text_users.setRows(30);
		text_users.setColumns(13);
		text_users.setEditable(false);
		text_users.setLineWrap(true);
		//text_users.setBorder(BorderFactory.createLineBorder(Color.GRAY));
		panel_users = new JPanel();
		panel_users.add(new JScrollPane(text_users));
		panel_users.setBorder(BorderFactory.createTitledBorder("�����û�"));
		//panel_users.setSize((int)0.2*WIDTH, HEIGHT);
		
		panel = new JPanel();
		panel.setLayout(new BorderLayout());
		panel.add(panel_message,BorderLayout.WEST);
		panel.add(panel_users,BorderLayout.EAST);
		this.setLocationRelativeTo(getOwner());
		this.add(panel);
		this.setVisible(true);
		this.setSize(600, 600);
		this.setResizable(false); 
		this.setTitle(Name);
		
		this.addWindowListener(new WindowAdapter(){//�رհ�ť�¼�
			public void windowClosing(WindowEvent e) {
                close();
                System.exit(0);
			}
		});
		
		this.text_send.addKeyListener(new KeyListener(){//Enter��ť�����¼�

			@Override
			public void keyPressed(KeyEvent e) {
				// TODO Auto-generated method stub
				if(KeyEvent.VK_ENTER==e.getKeyCode()){
					try {
						sendMessage();
					} catch (IOException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
			}

			@Override
			public void keyReleased(KeyEvent e) {
				// TODO Auto-generated method stub
				if(KeyEvent.VK_ENTER==e.getKeyCode()){
					text_send.setText("");
				}
			}

			@Override
			public void keyTyped(KeyEvent e) {
				// TODO Auto-generated method stub
				
			}
		});
		button_send.addActionListener(new ActionListener(){//���Ͱ�ť�¼�

			@Override
			public void actionPerformed(ActionEvent arg0) {
				// TODO Auto-generated method stub
				try {
					sendMessage();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}});
		
	}
	public ClientWindow(LoginWindowConnect lwc,String name){
		connect = true;
		this.name = name;
		this.socket = lwc.getSocket();
		this.dis = lwc.getDis();
		this.dos = lwc.getDos();
		this.creatClientWindow(name);
		new Thread(r).start();
		
	}
	
	public void close(){//�ر��¼�
		try {
			connect=false;
			dos.writeUTF("0"+ name);
			socket.close();
			dis.close();
			dos.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	public void sendMessage() throws IOException{//������Ϣ
		String str = "1" + box_sendto.getSelectedItem() + ":" + this.name + ":" + text_send.getText();
		text_send.setText("");
		dos.writeUTF(str);
		dos.flush();
	}
	
	public class recvThread implements Runnable{//������Ϣ

		@Override
		public void run() {
			// TODO Auto-generated method stub
			try {
				while(connect){
					String str;
					str = dis.readUTF();
					dealReceive(str);
				} 
			}catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
	}
	
	public void dealReceive(String str){//���������Ϣ
		if(str.startsWith("1")){//��ϢΪ��������
			String s;
			s = str.substring(1);
			text_receive.setText(text_receive.getText() + s + '\n');
		}
		else{//��ϢΪ�����¼�
			String s;
			s = str.substring(1);
			if(s.startsWith("1")){//���û�����
				s=s.substring(1);
				box_sendto.addItem(s);
				text_users.setText(text_users.getText() + s + '\n');
				text_receive.setText(text_receive.getText() + s + "������" +'\n');
			}
			else{//�û�����
				s=s.substring(1);
				box_sendto.removeItem(s);
				text_users.setText(text_users.getText().replaceFirst(s+'\n', ""));
				text_receive.setText(text_receive.getText() + s + "������" + '\n');
			}
		}
	}
	

	
}
