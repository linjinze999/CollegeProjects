package Server;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.util.Scanner;

import Rmi.MeetingImpl;

public class Server {
	public static void main(String[] args){
		boolean start = false;
		try{
			MeetingImpl obj=new MeetingImpl();
			LocateRegistry.createRegistry(9000);//ע�������
            Naming.bind("//localhost:9000/RmiMeeting", obj);//�󶨶���
            start = true;
			System.out.println("�������󶨶���ɹ�");
			System.in.read();
		}catch (Exception e) {
			System.out.println("��������ʼ�󶨳���");
		}finally{
			if(start){
				try {
					Naming.unbind("//localhost:9000/RmiMeeting");//�����
					start = false;
					System.out.println("�������������ɹ�");
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}
	}
}



