
public class WeightedQuickUnion extends QuickUnion {

	protected Integer[] m_sz;
	
	public WeightedQuickUnion(int N) {
		super(N);
		this.m_sz = new Integer[N];
		for (int i = 0; i < N; ++i) {
			this.m_sz[i] = 1;
		}
	}
	
	@Override
	public void join(int p, int q) {
		this.validate(p, q);
		final int pRoot = this.root(p);
		final int qRoot = this.root(q);
		
		final int pSize = this.m_sz[pRoot];
		final int qSize = this.m_sz[qRoot];
		
		if (pSize <= qSize) {
			super.join(pRoot, qRoot);
			this.m_sz[qRoot] += this.m_sz[pRoot];
		} else {			
			super.join(qRoot, pRoot);
			this.m_sz[pRoot] += this.m_sz[qRoot];
		}	
	}
	
	@Override
	public String toString() {
		String s = new String();
		for (int i : this.m_a) {
			s += i;
			s += " ";
		}
		
		s += "\n";
		
		for (int i : this.m_sz) {
			s += i;
			s += " ";
		}
		
		return s;
	}
}
