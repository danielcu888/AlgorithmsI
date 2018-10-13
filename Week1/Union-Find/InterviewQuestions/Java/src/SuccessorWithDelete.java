import java.util.Scanner;

public class SuccessorWithDelete {

	private boolean[] m_removed;
	private int[] m_successor;
	private int[] m_successee;
	
	public SuccessorWithDelete(int N)
	{
		this.m_removed = new boolean[N];
		this.m_successor = new int[N];
		this.m_successee = new int[N];
		
		for(int i = 0; i < N; ++i)
		{
			this.m_successee[i] = i-1;
			this.m_successor[i] = i+1;
			this.m_removed[i] = false;
		}
		m_successor[N-1] = N-1;
		m_successee[0] = -1;
	}
	
	public void remove(int x) throws Exception
	{
		if (!this.m_removed[x])
		{
			if (this.m_successee[x] != -1)
			{
				this.m_successor[this.m_successee[x]] = this.m_successor[x];
			}
			
			if (this.m_successor[x] != x)
			{
				this.m_successee[this.m_successor[x]] = this.m_successee[x];
			}
			else if (this.m_successee[x] != -1)
			{
				this.m_successor[this.m_successee[x]] = this.m_successee[x];
			}
			
			this.m_successor[x] = this.m_successee[x] = -1;
			this.m_removed[x] = true;
		}
		else
		{
			throw new Exception(x + " has already been removed!");
		}
	}
		
	public int successor(int x) throws Exception
	{
		if (!this.m_removed[x])
		{
			return this.m_successor[x];
		}
		else
		{
			throw new Exception(x + " has already been removed!");
		}
	}
}

