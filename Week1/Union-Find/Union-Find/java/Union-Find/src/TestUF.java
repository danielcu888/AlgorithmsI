
class TestData
{
	public TestData(int p, int q, char op) {
		this.p = p;
		this.q = q;
		this.op = op;
	}
	
	public int p;
	public int q;
	public char op;
}

public class TestUF {
		
	private static void validate(UF uf, int p) {
		if (p < 0 || p >= uf.count()) {
			throw new IllegalArgumentException("Node " + p + " is out of range.");
		}
	}
		
	private static String test(UF uf, TestData td) {
		
		final int p = td.p;
		final int q = td.q;
		final char op = td.op;
		
		validate(uf, p);
		validate(uf, q);
		
		String ret = p + " and " + q + ": ";
		if (p != q) {
			switch (op)
			{
			case '+':
				uf.union(p, q);
				ret += "are now connected.";
				break;
			case '?':
				if (uf.connected(p, q))
				{
					ret += uf.find(p);
				}
				else
				{
					ret += "are not connected.";
				}
				break;
			default:
				throw new IllegalStateException("Unrecognized operation: " + op);
			}
		}
		
		return ret;
	}

	public static String test(UF uf, TestData[] tds) {
		String result = "";
		for (TestData td : tds) {
			result += TestUF.test(uf, td);
		}
		return result;
	}
}
