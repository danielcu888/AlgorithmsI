public class UnionFindWithSpecificCanonicalElement {

	private int[] m_id;
	private int[] m_depth;
	private int[] m_max_in_comp;
	
	public UnionFindWithSpecificCanonicalElement(int N)
	{
		this.m_id = new int[N];
		this.m_depth = new int[N];
		this.m_max_in_comp = new int[N];
		
		for (int i = 0; i < N; ++i)
		{
			this.m_id[i] = i;
			this.m_depth[i] = 1;
			this.m_max_in_comp [i] = i;
		}
	}
	
	private int root(int i)
	{
		while (i != this.m_id[i])
		{
			i = this.m_id[i];
		}
		
		return i;
	}

	public boolean connected(int p, int q)
	{
		return this.root(p) == this.root(q);
	}
	
	public int find(int i)
	{
		return this.m_max_in_comp[this.root(i)];
	}
	
	public void union(int p, int q)
	{
		final int i = this.root(p);
		final int j = this.root(q);
		
		if (i != j)
		{
			if (this.m_depth[i] < this.m_depth[j])
			{
				this.m_id[i] = j;
				this.m_max_in_comp[j] = Math.max(this.m_max_in_comp[i], this.m_max_in_comp[j]);
			}
			else
			{
				this.m_id[j] = i;
				this.m_max_in_comp[i] = Math.max(this.m_max_in_comp[i], this.m_max_in_comp[j]);
				
				if (this.m_depth[i] == this.m_depth[j]) {
					++this.m_depth[i];
				}
			}
		}
	}
	
	public int id(int i)
	{
		return this.m_id[i];
	}
	
	public int depth(int i)
	{
		return this.m_depth[i];
	}		
}