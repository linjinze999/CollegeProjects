package CorbaVote;

/**
* CorbaVote/VoteHolder.java .
* ��IDL-to-Java ������ (����ֲ), �汾 "3.2"����
* ��vote.idl
* 2015��12��29�� ���ڶ� ����05ʱ06��33�� CST
*/

public final class VoteHolder implements org.omg.CORBA.portable.Streamable
{
  public CorbaVote.Vote value = null;

  public VoteHolder ()
  {
  }

  public VoteHolder (CorbaVote.Vote initialValue)
  {
    value = initialValue;
  }

  public void _read (org.omg.CORBA.portable.InputStream i)
  {
    value = CorbaVote.VoteHelper.read (i);
  }

  public void _write (org.omg.CORBA.portable.OutputStream o)
  {
    CorbaVote.VoteHelper.write (o, value);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return CorbaVote.VoteHelper.type ();
  }

}
