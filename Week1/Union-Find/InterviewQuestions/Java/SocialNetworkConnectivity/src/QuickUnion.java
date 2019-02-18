
public class QuickUnion implements UFInterface {
	protected Integer[] m_a;
	private int m_N;
	
	private void validate(int p) {
		if (p < 0 || p >= this.m_N) {
			throw new IllegalArgumentException(
					"Vertex index " +
					p + 
					" is outside valid range: [0, " +
					this.m_N + "]"
			);
		}
	}
	
	protected void validate(int p, int q) {
		this.validate(p);
		this.validate(q);
	}
	
	protected int root(int p) {
		while (p != this.m_a[p]) {
			p = this.m_a[p];
		}
		
		return p;
	}
	
	public QuickUnion(int N) {
		if (N < 1) {
			throw new IllegalArgumentException(
					"Number of vertices " +
					N +
					" is outside valid range: [1, inf)"
			);
		}
		
		this.m_a = new Integer[N];
		for (int i = 0; i < N; ++i) {
			this.m_a[i] = i;
		}
		
		this.m_N = N;
	}
	
	@Override
	public boolean connected(int p, int q) {
		this.validate(p, q);
		return this.root(p) == this.root(q);
	}

	@Override
	public void join(int p, int q) {
		this.validate(p, q);
		final int pRoot = this.root(p);
		final int qRoot = this.root(q);
		
		this.m_a[pRoot] = this.m_a[qRoot];
	}
	
	@Override
	public String toString() {
		String s = new String();
		for (int i : this.m_a) {
			s += i;
			s += " ";
		}
		return s;
	}	
}
