
public class WeightedQuickUnionUF extends QuickUnionUF {

	private int[] depth;
	
	public WeightedQuickUnionUF(int N) {
		super(N);
		
		this.depth = new int[this.N];
		for (int i = 0; i <  this.N; ++i) {
			this.depth[i] = 1;
		}
	}
	
	@Override
	public void union(int p, int q) {
		this.validate(p, q);

		final int idp = this.find(p);
		final int idq = this.find(q);
		
		final int dp = this.depth[idp];
		final int dq = this.depth[idq];
		
		boolean equal = false;
		if (dp == dq) {
			equal = true;
		}
		
		if (idp != idq) {
			if (dp > dq) {
				this.ids[idq] = idp;
				if (equal) {
					++this.depth[idp];
				}
			} else {
				this.ids[idp] = idq;
				if (equal) {
					++this.depth[idq];
				}
			}
		}
	}
}
