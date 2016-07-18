package CorbaVote;


/**
* CorbaVote/VotePOA.java .
* ��IDL-to-Java ������ (����ֲ), �汾 "3.2"����
* ��vote.idl
* 2015��12��29�� ���ڶ� ����05ʱ06��33�� CST
*/

public abstract class VotePOA extends org.omg.PortableServer.Servant
 implements CorbaVote.VoteOperations, org.omg.CORBA.portable.InvokeHandler
{

  // Constructors

  private static java.util.Hashtable _methods = new java.util.Hashtable ();
  static
  {
    _methods.put ("getList", new java.lang.Integer (0));
    _methods.put ("castVote", new java.lang.Integer (1));
  }

  public org.omg.CORBA.portable.OutputStream _invoke (String $method,
                                org.omg.CORBA.portable.InputStream in,
                                org.omg.CORBA.portable.ResponseHandler $rh)
  {
    org.omg.CORBA.portable.OutputStream out = null;
    java.lang.Integer __method = (java.lang.Integer)_methods.get ($method);
    if (__method == null)
      throw new org.omg.CORBA.BAD_OPERATION (0, org.omg.CORBA.CompletionStatus.COMPLETED_MAYBE);

    switch (__method.intValue ())
    {
       case 0:  // CorbaVote/Vote/getList
       {
         String $result = null;
         $result = this.getList ();
         out = $rh.createReply();
         out.write_string ($result);
         break;
       }

       case 1:  // CorbaVote/Vote/castVote
       {
         String name = in.read_string ();
         this.castVote (name);
         out = $rh.createReply();
         break;
       }

       default:
         throw new org.omg.CORBA.BAD_OPERATION (0, org.omg.CORBA.CompletionStatus.COMPLETED_MAYBE);
    }

    return out;
  } // _invoke

  // Type-specific CORBA::Object operations
  private static String[] __ids = {
    "IDL:CorbaVote/Vote:1.0"};

  public String[] _all_interfaces (org.omg.PortableServer.POA poa, byte[] objectId)
  {
    return (String[])__ids.clone ();
  }

  public Vote _this() 
  {
    return VoteHelper.narrow(
    super._this_object());
  }

  public Vote _this(org.omg.CORBA.ORB orb) 
  {
    return VoteHelper.narrow(
    super._this_object(orb));
  }


} // class VotePOA
