import java.lang.*;
import java.util.*;

class Node
{
	public int data;
	public Node next;
	
	public Node(int value)
	{
		data = value;
		next = null;
	}
}

class SLL
{
	public Node Head;
	
	public void SLL()
	{
		Head = null;
	}
	
	public void InsertFirst(int no)
	{
		Node newn = new Node(no);
		if(Head==null)
		{
			Head=newn;
		}
		else
		{
			newn.next=Head;
			Head=newn;
		}
	}
	
	public void InsertLast(int no)
	{
		Node newn = new Node(no);
		if(Head==null)
		{
			Head=newn;
		}
		else
		{
			Node temp = Head;
			while(temp.next != null)
			{
				temp=temp.next;
			}
			temp.next=newn;
		}
	}
	
	public void DeleteFirst()
	{
		if(Head==null)
		{
			return;
		}
		else
		{
			Head = Head.next;
		}
	}
	
	public void DeleteLast()
	{
		if(Head==null)
		{
			return;
		}
		else
		{
			if(Head.next==null)
			{
				Head=null;
			}
			else
			{
				Node temp = Head;
				while(temp.next.next!=null)
				{
					temp=temp.next;
				}
				temp.next=null;
			}
		}
	}
	
	public void Display()
	{
		Node temp = Head;
		while(temp!=null)
		{
			System.out.print(temp.data+" ");
			temp=temp.next;
		}
		System.out.println();
	}
	
	public int count()
	{
		int size=0;
		Node temp = Head;
		while(temp!=null)
		{
			size++;
			temp=temp.next;
		}
		return size;
	}
	
	public void InsertAtPos(int no,int pos)
	{
		int size=count();
		if(pos<=0 || pos>size+1)
		{
			return;
		}
		if(pos==(size+1))
		{
			InsertLast(no);
		}
		else if(pos==1)
		{
			InsertFirst(no);
		}
		else
		{
			Node temp = Head;
			for(int i=1;i<pos-1;i++)
			{
				temp=temp.next;
			}
			Node newn = new Node(no);
			newn.next=temp.next;
			temp.next=newn;
		}
	}
	
	public void DeleteAtPos(int pos)
	{
		int size=count();
		if(pos<=0 || pos>size)
		{
			return;
		}
		if(pos==size)
		{
			DeleteLast();
		}
		else if(pos==1)
		{
			DeleteFirst();
		}
		else
		{
			Node temp = Head;
			for(int i=1;i<pos-1;i++)
			{
				temp=temp.next;
			}
			temp.next=temp.next.next;
		}
	}
}

class demo
{
	public static void main(String args[])
	{
		SLL obj = new SLL();
		int ch=1;
		while(ch!=0)
		{
			Scanner sobj = new Scanner(System.in);
			System.out.println("Menu:");
			System.out.println("1.Insert First");
			System.out.println("2.Insert Last");
			System.out.println("3.Display");
			System.out.println("4.Delete First");
			System.out.println("5.Delete Last");
			System.out.println("6.Insert at pos");
			System.out.println("5.Delete at pos");
			System.out.println("0.Exit");
			System.out.println("Enter your choice");
			ch =sobj.nextInt();
			int value=0;
			
			switch(ch)
			{
				case 1:
					System.out.println("Enter element");
					value=sobj.nextInt();
					obj.InsertFirst(value);
					break;
				case 2:
					System.out.println("Enter element");
					value=sobj.nextInt();
					obj.InsertLast(value);
					break;
				case 4:
					obj.DeleteFirst();
					break;
				case 5:
					obj.DeleteLast();
					break;
				case 3:
					obj.Display();
					break;
				case 6:
					System.out.println("Enter element");
					value=sobj.nextInt();
					System.out.println("Enter position");
					int pos=sobj.nextInt();
					obj.InsertAtPos(value,pos);
					break;
				case 7:
					System.out.println("Enter position");
					int pos1=sobj.nextInt();
					obj.DeleteAtPos(pos1);
					break;
				case 0:
					break;
			}
		}
	}
}
