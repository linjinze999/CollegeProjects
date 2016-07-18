package Client;

import java.io.IOException;
import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

import Rmi.MeetingImpl;
import Rmi.MeetingInfo;
import Rmi.MeetingInterface;

public class Client {
	private static String name = "";
	private static String password = "";
	
	public static void main(String[] args){
		try {
			MeetingInterface obj = (MeetingInterface)Naming.lookup("rmi://localhost:9000/RmiMeeting");
			if(args[0].compareTo("1")==0){//login
				System.out.println("**** �û���¼ ****");
				name=args[1];
				password=args[2];
				System.out.println("�������û���"+name);
				System.out.println("���������룺"+password);
				int islogin = obj.UserLogin(name, password);
				System.out.print("�����");
				switch(islogin){
					case 0:
						System.out.println("Error���������");
						break;
					case 1:
						System.out.println("�û� "+name+" ��¼�ɹ���");
						break;
					case 2:
						System.out.println("Error�������ڸ��û���");
						break;
				}
			}else if(args[0].compareTo("2")==0){//regist
				System.out.println("**** ע���û� ****");
				name=args[1];
				password=args[2];
				System.out.println("�������û���"+name);
				System.out.println("���������룺"+password);
				int islogin = obj.UserRegister(name, password);
				System.out.print("�����");
				switch(islogin){
					case 0:
						System.out.println("Error���û��Ѵ��ڣ�");
						break;
					case 1:
						System.out.println("�û� "+ name +" ע��ɹ���");
						break;
				}
			}else if(args[0].compareTo("3")==0){//add meeting
				System.out.println("**** ��ӻ��� ****");
				String description_label = args[1];
				name = args[2];
				String book_user = args[3];
				Date start_time = getInputDate(args[4],args[5]);
				Date end_time = getInputDate(args[6],args[7]);
				System.out.println("�������ʶ��"+description_label);
				System.out.println("�����뷢���û���"+name);
				System.out.println("������ԤԼ�û���"+ book_user);
				System.out.println("�����뿪ʼʱ�䣺"+args[4]+" "+args[5]);
				System.out.println("���������ʱ�䣺"+args[6]+" "+args[7]);
				int result = obj.MeetingAdd(description_label, name, book_user, start_time, end_time);
				System.out.print("�����");
				switch(result){
					case 0:
						System.out.println("Error���Ҳ����û���δ֪���󣡻����ʧ�ܡ�");
						break;
					case 1:
						System.out.println("���� "+description_label+" �����ɹ���");
						break;
					case 2:
						System.out.println("Error��������ö���Ļ��");
						break;
					case 3:
						System.out.println("Error�������л���ʱ���ͻ��");
						break;
				}
			}else if(args[0].compareTo("4")==0){//search meeting
				System.out.println("**** ��ѯ���� ****");
				CallBackImpl callback = new CallBackImpl();
				name=args[1];
				Date start_time = getInputDate(args[2],args[3]);
				Date end_time = getInputDate(args[4],args[5]);
				System.out.println("�������ѯ�û���"+name);
				System.out.println("�����뿪ʼʱ�䣺"+args[2]+" "+args[3]);
				System.out.println("���������ʱ�䣺"+args[5]+" "+args[5]);
				obj.MeetingSearch(name, start_time, end_time,callback);
				List<MeetingInfo> my_meetings = callback.getMyMeetings();
				System.out.println("�û� "+name+" �Ļ����ѯ�����");
				System.out.println("��� " + "��ǩ " + "���� " + "ԤԼ " + "��ʼʱ��" + '\t' + '\t' + '\t' + " " + "����ʱ��");
				for(int i=0;i<my_meetings.size();i++){
					System.out.println(new String(i+1+"    ") + my_meetings.get(i).getDescriptionLabel() +" "+ my_meetings.get(i).getStartUser() + " " + 
							my_meetings.get(i).getBookUser()+ " " + my_meetings.get(i).getStartTime() + " " + my_meetings.get(i).getEndTime());
				}
			}else if(args[0].compareTo("5")==0){//delete meeting
				System.out.println("**** ɾ������ ****");
				String my_name = args[1];
				String my_password = args[2];
				String description_label = args[3];
				System.out.println("�������û���"+ my_name);
				System.out.println("���������룺"+ my_password);
				System.out.println("�������ǩ��"+ description_label);
				int result = obj.MeetingDelete(description_label, my_name, my_password);
				System.out.print("�����");
				switch(result){
					case 0:
						System.out.println("Error���û����������");
						break;
					case 1:
						System.out.println("���� "+description_label+" ɾ���ɹ���");
						break;
					case 2:
						System.out.println("Error���Ҳ����ñ�ǩ��");
						break;
				}
			}else if(args[0].compareTo("6")==0){//clear meeting
				System.out.println("**** ������� ****");
				String my_name = args[1];
				String my_password = args[2];
				System.out.println("�������û���"+ my_name);
				System.out.println("���������룺"+ my_password);
				int result = obj.MeetingClear(my_name, my_password);
				System.out.print("�����");
				switch(result){
				case 0:
					System.out.println("Error���û����������");
					break;
				case 1:
					System.out.println("�û� "+my_name+" ��������ɹ���");
					break;
				}
			}
			
		} catch (Exception e) {
			System.out.println("Error:�����������ʧ�ܣ�");
		}finally{
			System.out.println("�˳�");
		}
	}
	
	public static Date getInputDate(String str1,String str2){//��ȡ��ȷʱ���ʽ
		Date date = new Date();
		String str=str1+" "+str2;
		SimpleDateFormat sdf=new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		try {
			date = sdf.parse(str);
		} catch (ParseException e) {
			System.out.println("Error�������ʱ���ʽ��");
		}
		return date;
	}
}