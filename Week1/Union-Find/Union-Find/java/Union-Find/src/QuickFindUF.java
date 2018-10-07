
import java.util.HashSet;

public class QuickFindUF implements UF {

	private int N;
	private int ids[];
	
	private void validate(int p) {
		if (p < 0 || p >= this.N) {
			throw new IllegalArgumentException("Node " + p + " is out of range.");
		}
	}
	
	private void validate(int p, int q) {
		this.validate(p);
		this.validate(q);
	}
	
	public QuickFindUF(int N) {
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
		final int idq = this.ids[q];
		final int idp = this.ids[p];
		for (int i = 0; i < this.N; ++i) {
			if (this.ids[i] == idq) {
				this.ids[i] = idp;
			}
		}
	}

	@Override
	public boolean connected(int p, int q) {
		this.validate(p, q);
		return this.ids[p] == this.ids[q];
	}

	@Override
	public int find(int p) {
		this.validate(p);
		return this.ids[p];
	}

	@Override
	public int count() {
		final HashSet<Integer> ccs = new HashSet<Integer>();
		for (int i = 0; i < this.N; ++i) {
			ccs.add(this.ids[i]);
		}
		return ccs.size();
	}
}
