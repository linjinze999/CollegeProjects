package server;

import org.omg.CORBA.ORB;
import org.omg.CosNaming.NameComponent;
import org.omg.CosNaming.NamingContextExt;
import org.omg.CosNaming.NamingContextExtHelper;
import org.omg.PortableServer.POA;
import org.omg.PortableServer.POAHelper;

import CorbaVote.Vote;
import CorbaVote.VoteHelper;

public class VoteServer {
	public static void main(String[] args){
		try{
            //����һ��ORBʵ�� 
            ORB orb = ORB.init(args, null); 

            //�õ�һ��RootPOA�����ã�������POAManager 
            POA rootpoa = POAHelper.narrow(orb.resolve_initial_references("RootPOA")); 
            rootpoa.the_POAManager().activate(); 

            // create servant and register it with the ORB 
            //����һ��HelloImplʵ����servant������ע�ᵽORB�� 
            VoteImpl voteImpl = new VoteImpl(); 
            voteImpl.setORB(orb); 

            //�ӷ����еõ���������� 
            org.omg.CORBA.Object ref = rootpoa.servant_to_reference(voteImpl); 
            Vote href = VoteHelper.narrow(ref); 

            //�õ�һ�������Ƶ������� 
            org.omg.CORBA.Object objRef = orb.resolve_initial_references("NameService"); 
            // Use NamingContextExt which is part of the Interoperable 
            // Naming Service (INS) specification. 
            NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef); 

            //�������������а�������� 
            String name = "Vote"; 
            NameComponent path[] = ncRef.to_name(name); 
            ncRef.rebind(path, href); 

            System.out.println("VoteServer ready and waiting ..."); 

            //�����̷߳��񣬵ȴ��ͻ��˵ĵ��� 
            orb.run();
            
            //�ȴ�ֹͣ
            System.in.read();
            orb.shutdown(false);
		}catch (Exception e) { 
            System.err.println("ERROR: " + e); 
            e.printStackTrace(System.out);
		}
		System.out.println("VoteServer Exiting ..."); 
	}
}
