package Client;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.Date;
import java.util.List;

import Rmi.MeetingInfo;
public interface CallBackInterface extends Remote{//�ͻ��ص��ӿ�
	public void getOneSearchResult(String description_label,String start_user,String book_user,Date start_time,Date end_time)throws RemoteException;
}
