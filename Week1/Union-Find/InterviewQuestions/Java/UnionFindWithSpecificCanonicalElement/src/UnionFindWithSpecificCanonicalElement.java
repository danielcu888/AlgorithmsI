
public class UnionFindWithSpecificCanonicalElement extends WeightedQuickUnionwithPathCompression {
	private Integer[] max;
	
	public UnionFindWithSpecificCanonicalElement(int N) {
		super(N);
		this.max = new Integer[N];
		for (int i = 0; i < N; ++i) {
			this.max[i] = i;
		}
	}
	
	@Override
	public void join(int p, int q) {
		final int pRoot = this.root(p);
		final int qRoot = this.root(q);
		final int pRootMax = this.max[pRoot];
		final int qRootMax = this.max[qRoot];
	
		if (pRootMax > qRootMax) {
			this.max[qRoot] = pRootMax;
		} else {
			this.max[pRoot] = qRootMax;
		}
		
		super.join(p, q);
	}
	
	public int find(int p) {
		this.validate(p);
		return this.max[this.root(p)];
	}
	
	@Override
	public String toString() {
		String s = super.toString();

		s += "\n";
		
		for (int i : this.max) {
			s += i;
			s += " ";
		}
		
		return s;
	}
}
