package Rmi;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.ArrayList;
import java.util.Date;
import java.util.LinkedList;
import java.util.List;

import javax.xml.crypto.Data;

import Client.CallBackInterface;

public interface MeetingInterface extends Remote{//RMI�ӿ�
	public int UserRegister(String name,String password)throws RemoteException;//�û�ע��
	public int UserLogin(String name,String password)throws RemoteException;//�û���¼
	public int MeetingAdd(String description_label,String start_user,String book_user,Date start_time,Date end_time)throws RemoteException;//��ӻ���
	public int MeetingDelete(String description_label,String user_name,String password)throws RemoteException;//ɾ������
	public int MeetingClear(String user_name,String password)throws RemoteException;//�������
	public void MeetingSearch(String user_name,Date start_time,Date end_time,CallBackInterface callback)throws RemoteException;//��ѯ����
}
