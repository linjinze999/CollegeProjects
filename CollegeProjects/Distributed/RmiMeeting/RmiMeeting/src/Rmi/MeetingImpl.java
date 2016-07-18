package Rmi;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.LinkedList;
import java.util.List;

import javax.xml.crypto.Data;

import Client.CallBackInterface;

public class MeetingImpl extends UnicastRemoteObject implements MeetingInterface{//RMI�ӿ�ʵ��
	private List<UserInfo> users = new ArrayList<UserInfo>();
	private List<MeetingInfo> meetings = new ArrayList<MeetingInfo>();
	
	public MeetingImpl() throws RemoteException {
		super();
	}

	@Override
	public int UserRegister(String name, String password) throws RemoteException{
		// �û�ע��
		for(int i=0;i<users.size();i++){
			if(name.compareTo(users.get(i).getName())==0){
				return 0;//�û����Ѵ���
			}
		}
		UserInfo new_user = new UserInfo(name,password);
		users.add(new_user);
		return 1;//ע��ɹ�
	}

	@Override
	public int UserLogin(String name, String password) throws RemoteException{
		// �û���¼
		for(int i=0;i<users.size();i++){
			if(name.compareTo(users.get(i).getName())==0){
				if(password.compareTo(users.get(i).getPassword())==0){
					return 1;//��¼�ɹ�
				}
				else
					return 0;//�������
			}
		}
		return 2;//�޸��û�
	}

	@Override
	public int MeetingAdd(String description_label, String start_user,
			String book_user, Date start_time, Date end_time) throws RemoteException{
		// ��ӻ���
		for(int i=0;i<meetings.size();i++){
			if(meetings.get(i).getStartUser().compareTo(start_user)==0){
				if(meetings.get(i).getBookUser().compareTo(book_user)==0)
					return 2;//������ͬ����Ļ���
				else if(meetings.get(i).getStartTime()==start_time && meetings.get(i).getEndTime()==end_time)
					return 3;//ʱ���ͻ
			}
		}
		for(int j=0;j<users.size();j++){
			if(users.get(j).getName().compareTo(book_user)==0){
				MeetingInfo new_meeting = new MeetingInfo(description_label,start_user,book_user,start_time,end_time);
				meetings.add(new_meeting);
				return 1;//��ӻ���ɹ�
			}
		}
		return 0;//�Ҳ����û���δ֪����
	}

	@Override
	public int MeetingDelete(String description_label, String user_name,
			String password) throws RemoteException{
		// ɾ������
		boolean true_userinfo=false;
		for(int i=0;i<users.size();i++){
			if(user_name.compareTo(users.get(i).getName())==0){
				if(password.compareTo(users.get(i).getPassword())==0)
					true_userinfo=true;//�û���������ȷ
			}
		}
		if(true_userinfo){
			for(int i=0;i<meetings.size();i++){
				if(meetings.get(i).getDescriptionLabel().compareTo(description_label)==0 && 
						meetings.get(i).getStartUser().compareTo(user_name)==0){
					meetings.remove(i);
					return 1;//ɾ���ɹ�
				}
			}
			return 2;//�Ҳ����ñ�ǩ
		}
		else
			return 0;//�û����������
	}
	
	@Override
	public int MeetingClear(String user_name, String password) throws RemoteException{
		// �������
		boolean true_userinfo=false;
		for(int i=0;i<users.size();i++){
			if(user_name.compareTo(users.get(i).getName())==0){
				if(password.compareTo(users.get(i).getPassword())==0)
					true_userinfo=true;//�û���������ȷ
			}
		}
		if(true_userinfo){
			for(int i=0;i<meetings.size();i++){
				if(meetings.get(i).getStartUser().compareTo(user_name)==0){
					meetings.remove(i);
					i--;
				}
			}
			return 1;//����ɹ�
		}
		else
			return 0;//�û����������
	}

	@Override
	public void MeetingSearch(String user_name, Date start_time,
			Date end_time, CallBackInterface callback) throws RemoteException{
		// ��ѯ����
		for(int i=0;i<meetings.size();i++){
			if(user_name.compareTo(meetings.get(i).getStartUser())==0 ||
					user_name.compareTo(meetings.get(i).getBookUser())==0){//�ҵ��û�
				if(start_time.compareTo(meetings.get(i).getStartTime())<0 &&
						end_time.compareTo(meetings.get(i).getEndTime())>0){//ȷ��ʱ�䷶Χ
					callback.getOneSearchResult(meetings.get(i).getDescriptionLabel(),meetings.get(i).getStartUser(),
							meetings.get(i).getBookUser(),meetings.get(i).getStartTime(),meetings.get(i).getEndTime());
				}
			}
		}
	}	
}
