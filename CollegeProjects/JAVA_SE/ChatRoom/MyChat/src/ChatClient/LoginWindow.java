/*
 * �ͻ��˵�½���ͻ������ȿ����˴���
 * */
package ChatClient;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.border.TitledBorder;

public class LoginWindow extends JFrame{
	private JLabel Lable_IP,Lable_Post,Lable_Name;
	private JTextField TextField_IP,TextField_Post,TextField_Name;
	private JButton Button_login,Button_reset;
	private JPanel panel;
	private void createLoginWindow(){//��½����
		Lable_IP = new JLabel("��������");
		Lable_Post = new JLabel("�˿ںţ�");
		Lable_Name = new JLabel("�û�����");
		
		TextField_IP = new JTextField(20);
		TextField_Post = new JTextField(20);
		TextField_Name = new JTextField(20);
		
		TextField_IP.setText("127.0.0.1");
		TextField_Post.setText("4444");
		
		Button_login = new JButton("��½");
		Button_reset = new JButton("����");
		
		Button_login.addActionListener(new ActionListener(){//��½��ť��Ӧ�¼�
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				LoginWindow.this.login();
			}
		});
		
		Button_reset.addActionListener(new ActionListener(){//���谴ť��Ӧ�¼�
			@Override
			public void actionPerformed(ActionEvent arg0) {
				// TODO Auto-generated method stub
				LoginWindow.this.reset();
			}
		});
		
		panel = new JPanel();
		panel.add(Lable_IP);
		panel.add(TextField_IP);
		panel.add(Lable_Post);
		panel.add(TextField_Post);
		panel.add(Lable_Name);
		panel.add(TextField_Name);
		panel.add(Button_login);
		panel.add(Button_reset);
		panel.setBorder(BorderFactory.createTitledBorder(null, "�û���¼", TitledBorder.CENTER, TitledBorder.ABOVE_TOP, new Font(Font.DIALOG, Font.ITALIC, 20), Color.RED));
		
		this.setLocationRelativeTo(getOwner());
		this.setVisible(true);
		this.setSize(330, 200);
		this.add(panel);
		this.setResizable(false); 
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setTitle("�ͻ���");
	}
	
	public void login(){//��½�¼�
		try {
			new LoginWindowConnect(TextField_IP.getText(),Integer.parseInt(TextField_Post.getText()),TextField_Name.getText(),this);
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void reset(){//�����¼�
		TextField_IP.setText("127.0.0.1");
		TextField_Post.setText("4444");
		TextField_Name.setText("");
	}
	
	public LoginWindow(){
		this.createLoginWindow();
	}
	
	public static void main(String[] args){
		new LoginWindow();
	} 
}
