
public class SuccessorWithDelete {

	private boolean[] m_removed;
	private int[] m_max;
	private WeightedQuickUnionwithPathCompression m_uf;
	private int m_N;
	
	private void validate(int x) {
		if (x < 0 || x >= this.m_N) {
			throw new IllegalArgumentException("Index " + x + " is outside of valid range [0, " + this.m_N + ").");
		}
	}
	
	public SuccessorWithDelete(int N) {
		
		if (N < 1) {
			throw new IllegalArgumentException("Invalid number of elements.");
		}
		
		this.m_removed = new boolean[N];
		this.m_max = new int[N];
		this.m_uf = new WeightedQuickUnionwithPathCompression(N);
		this.m_N = N;
		
		for (int i = 0; i < N; ++i) {
			this.m_max[i] = i;
		}
	}
	
	public void remove(int x) {
		this.validate(x);
		
		// Update removed flag.
		this.m_removed[x] = true;
		
		if (x > 0) {
			// check if x - 1 is removed.
			if (this.m_removed[x-1]) {
				// join x to x-1's connected component.
				this.m_uf.join(x-1, x);
				
				// x is now the largest in its connected component.
				this.m_max[this.m_uf.root(x)] = x;
			}
		}
		
		if (x < this.m_N-1) {
			// check if x+1 is removed.
			if (this.m_removed[x+1]) {

				// Get max of adjacent component.
				final int adjacentMax = this.m_max[this.m_uf.root(x+1)];
				
				// join x to x+1's connected component.
				this.m_uf.join(x, x+1);
				
				// Set max of x's component to adjacent max.
				this.m_max[this.m_uf.root(x)] = adjacentMax;
			}
		}
	}
	
	public int successor(int x) {
		this.validate(x);
		
		if (x == this.m_N-1) {
			return -1;
		}
		
		if (!this.m_removed[x+1]) {
			return x+1;
		}
		
		final int adjacentRoot = this.m_uf.root(x+1);
		int adjacentMax = this.m_max[adjacentRoot];
		
		final int suc = 1+adjacentMax;
		return suc < this.m_N ? suc : -1;
	}
}
