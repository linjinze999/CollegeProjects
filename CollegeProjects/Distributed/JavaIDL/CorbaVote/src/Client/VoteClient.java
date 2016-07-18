package Client;

import org.omg.CORBA.ORB;
import org.omg.CosNaming.NamingContextExt;
import org.omg.CosNaming.NamingContextExtHelper;

import CorbaVote.Vote;
import CorbaVote.VoteHelper;

public class VoteClient {
	static Vote voteImpl;
	public static void main(String[] args){
		try {
            //����һ��ORBʵ�� 
            ORB orb = ORB.init(args, null); 

            //��ȡ������������ 
            org.omg.CORBA.Object objRef = orb.resolve_initial_references("NameService"); 
            // Use NamingContextExt instead of NamingContext. This is 
            // part of the Interoperable naming Service. 
            NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef); 

            //�������������л�ȡ�ӿ�ʵ�ֶ��� 
            String name = "Vote"; 
            voteImpl = VoteHelper.narrow(ncRef.resolve_str(name)); 

            //���ýӿڶ���ķ��� 
            voteImpl.castVote("candidate1");
        	System.out.println("Ϊ candidate1 ͶƱ��ɣ�");
        	voteImpl.castVote("candidate3");
        	System.out.println("Ϊ candidate3 ͶƱ��ɣ�");
        	voteImpl.castVote("candidate9");
        	System.out.println("Ϊ candidate9 ͶƱ��ɣ�");
        	voteImpl.castVote("candidate1");
        	System.out.println("Ϊ candidate1 ͶƱ��ɣ�");
        	voteImpl.castVote("candidate7");
        	System.out.println("Ϊ candidate7 ͶƱ��ɣ�");
            String[] result = voteImpl.getList().split(";");
        	System.out.println("���յ�Ʊ���������ʾ��");
        	for(int i=0;i<result.length;i++){
        		System.out.println(result[i]);
        	}

		} catch (Exception e) { 
            System.out.println("ERROR : " + e); 
            e.printStackTrace(System.out); 
		}
	}
}
