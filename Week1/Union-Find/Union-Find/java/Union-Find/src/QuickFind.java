
public class QuickFind implements UFInterface {

	private Integer[] m_a;
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
	
	private void validate(int p, int q) {
		this.validate(p);
		this.validate(q);
	}
	
	public QuickFind(int N) {
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
		return this.m_a[p] == this.m_a[q];
	}

	@Override
	public void join(int p, int q) {
		this.validate(p, q);
		final int oldRoot = this.m_a[p];
		final int newRoot = this.m_a[q];
		for (int i = 0; i < this.m_N; ++i) {
			if (this.m_a[i] == oldRoot) {
				this.m_a[i] = newRoot;
			}
		}
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
