
import java.util.HashSet;

public class QuickUnionUF implements UF {

	protected int N;
	protected int[] ids;

	protected void validate(int p) {
		if (p < 0 || p >= this.N) {
			throw new IllegalArgumentException("Node " + p + " is out of range.");
		}
	}
	
	protected void validate(int p, int q) {
		this.validate(p);
		this.validate(q);
	}
	
	public QuickUnionUF(int N) {
		if (N <= 0) {
			throw new IllegalArgumentException("Invalid number of nodes: " + N);
		}
		
		this.N = N;
		this.ids = new int[this.N];
		
		for (int i = 0; i < this.N; ++i) {
			ids[i] = i;
		}
	}
		
	@Override
	public void union(int p, int q) {
		this.validate(p, q);

		final int idp = this.find(p);
		final int idq = this.find(q);
		
		if (idp != idq) {
			this.ids[idq] = idp;
		}
	}

	@Override
	public boolean connected(int p, int q) {
		this.validate(p, q);

		return this.find(p) == this.find(q);
	}

	@Override
	public int find(int p) {
		validate(p);

		int idp;
		for (idp = this.ids[p]; idp != this.ids[idp]; idp = this.ids[idp]);
		
		return idp;
	}

	@Override
	public int count() {
		final HashSet<Integer> ccs = new HashSet<Integer>();
		for (int i = 0; i < this.N; ++i) {
			ccs.add(this.find(i));
		}
		
		return ccs.size();
	}

}
