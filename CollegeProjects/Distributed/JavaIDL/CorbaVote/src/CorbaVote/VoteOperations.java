package CorbaVote;


/**
* CorbaVote/VoteOperations.java .
* ��IDL-to-Java ������ (����ֲ), �汾 "3.2"����
* ��vote.idl
* 2015��12��29�� ���ڶ� ����05ʱ06��33�� CST
*/

public interface VoteOperations 
{
  String getList ();
  void castVote (String name);
} // interface VoteOperations
