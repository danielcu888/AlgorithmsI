

public class WeightQuickUnionWithPathCompressionUF extends QuickUnionUF {

	public WeightQuickUnionWithPathCompressionUF(int N) {
		super(N);
	}
	
	@Override
	public int find(int p) {
		this.validate(p);

		int idp = this.ids[p];
		while (idp != this.ids[idp]) {
			this.ids[idp] = this.ids[this.ids[idp]];
			idp = this.ids[idp];
		}

		return idp;
	}
}
