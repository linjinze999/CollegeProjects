package moneyChange;

import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;


public class window extends JFrame{
	private urlconnection uc = new urlconnection();
	//private JPanel panel_message;
	private JLabel tip=new JLabel("ѡ��ת������:");
	private JLabel error=new JLabel();
	private JLabel money=new JLabel("�ҵĽ��:");
	private JLabel line=new JLabel("����");
	private JLabel tomoney=new JLabel("ת�����:");
	private JTextField money_t = new JTextField();
	private JTextField tomoney_t = new JTextField();
	private JPanel panel = new JPanel();
	private JPanel panel1 = new JPanel();
	private JPanel panel2 = new JPanel();
	private JPanel panel3 = new JPanel();
	private JPanel panel4 = new JPanel();
	private JPanel panel5 = new JPanel();
	private JComboBox moneyType = new JComboBox();
	private JComboBox tomoneyType = new JComboBox();
	private JButton submit = new JButton("ת��");
	private JButton reset = new JButton("���");
	public void createWindow(){
		moneyType.addItem("�����-CNY");
		moneyType.addItem("��Ԫ-USD");
		moneyType.addItem("ŷԪ-EUR");
		moneyType.addItem("Ӣ��-GBP");
		moneyType.addItem("��Ԫ-JPY");
		moneyType.addItem("�۱�-HKD");
		moneyType.addItem("���ô�Ԫ-CAD");
		moneyType.addItem("�Ĵ�����Ԫ-AUD");
		moneyType.addItem("ӡ��¬��-INR");
		moneyType.addItem("��̨��-TWD");
		moneyType.setPreferredSize(new Dimension(100,30));
		tomoneyType.addItem("��Ԫ-USD");
		tomoneyType.addItem("�����-CNY");
		tomoneyType.addItem("ŷԪ-EUR");
		tomoneyType.addItem("Ӣ��-GBP");
		tomoneyType.addItem("��Ԫ-JPY");
		tomoneyType.addItem("�۱�-HKD");
		tomoneyType.addItem("���ô�Ԫ-CAD");
		tomoneyType.addItem("�Ĵ�����Ԫ-AUD");
		tomoneyType.addItem("ӡ��¬��-INR");
		tomoneyType.addItem("��̨��-TWD");
		tomoneyType.setPreferredSize(new Dimension(100,30));
		panel1.add(tip);
		panel1.add(moneyType);
		panel1.add(line);
		panel1.add(tomoneyType);
		money_t.setPreferredSize(new Dimension(150,30));
		panel2.add(money);
		panel2.add(money_t);
		tomoney_t.setPreferredSize(new Dimension(150,30));
		tomoney_t.setEditable(false);
		panel3.add(tomoney);
		panel3.add(tomoney_t);
		submit.setPreferredSize(new Dimension(90,30));
		reset.setPreferredSize(new Dimension(90,30));
		panel4.add(submit);
		panel4.add(reset);
		error.setPreferredSize(new Dimension(300,30));
		panel5.add(error);
		panel.add(panel1);
		panel.add(panel2);
		panel.add(panel3);
		panel.add(panel4);
		panel.add(panel5);
		this.setLocationRelativeTo(getOwner());
		this.setVisible(true);
		this.setSize(350, 260);
		this.add(panel);
		this.setResizable(false); 
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setTitle("����ת��ϵͳ");
		
		
		reset.addActionListener(new ActionListener(){//��հ�ť�¼�
			@Override
			public void actionPerformed(ActionEvent arg0) {
				// TODO Auto-generated method stub
				try {
					money_t.setText("");
					tomoney_t.setText("");
					error.setText("");
				} catch (Exception e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}});
		submit.addActionListener(new ActionListener(){//ת����ť�¼�
			@Override
			public void actionPerformed(ActionEvent arg0) {
				// TODO Auto-generated method stub
				
				try{
					double mymoney = Double.parseDouble(money_t.getText());
					String waibi = tomoneyType.getSelectedItem().toString().split("-")[1];
					String qian = moneyType.getSelectedItem().toString().split("-")[1];
					try {
						String result=uc.exchangeRate(waibi, qian);
						double rate = Double.parseDouble(result);
						tomoney_t.setText(String.valueOf(mymoney*rate));
					} catch (Exception e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
						error.setText("���󣺲�ѯʧ�ܣ��������������");
					}
				}catch (Exception e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					error.setText("������������ȷ�Ľ�");
				}
				
			}});
	}
	
	public window(){
		this.createWindow();
	}
	
	public static void main(String[] args) {
		new window();
    }
}
