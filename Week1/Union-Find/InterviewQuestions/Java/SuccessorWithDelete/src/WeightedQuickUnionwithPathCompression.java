
public class WeightedQuickUnionwithPathCompression extends WeightedQuickUnion {

	public WeightedQuickUnionwithPathCompression(int N) {
		super(N);
	}

	@Override
	protected int root(int p) {
		while (this.m_a[p] != p) {
			final int x = this.m_a[p];
			this.m_a[p] = this.m_a[x];
			p = this.m_a[p];
		}
		
		return p;
	}
	
}
