import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class Member {
	public int id;
	
	public Member(String s) {
		this.id = Integer.parseInt(s);
	}
}

class Connection {
	public Member member1;
	public Member member2; 
	public String time;
	
	public Connection(String s) {
		final Scanner sc = new Scanner(s);
		try {
			this.member1 = new Member(sc.next());
			this.member2 = new Member(sc.next());
			this.time = sc.next();
		} catch (Exception exc) {
			throw new IllegalArgumentException("Invalid input: " + s);
		} finally {
			sc.close();			
		}
	}
	
	
}

class ConnectionReader {

	private Scanner m_scanner;
	
	public ConnectionReader(String filePath) throws FileNotFoundException {
		
		final File f = new File(filePath);
		if (!f.exists() || !f.isFile()) {
			throw new FileNotFoundException(filePath + " is not a valid file path.");
		}
		
		this.m_scanner = new Scanner(filePath);
	}
	
	boolean hasNext() {
		return this.m_scanner.hasNext();
	}
	
	public Connection next() {
		if (!this.hasNext()) {
			throw new IllegalStateException("No more Connections to read.");
		}
		return new Connection(this.m_scanner.nextLine());
	}
	
	protected void finalize() {
		if (this.m_scanner != null) {
			this.m_scanner.close();
		}
	}
}

public class SocialNetworkConnectivity {

	private WeightedQuickUnionUF m_uf;
	private int m_num_components;
	
	public SocialNetworkConnectivity(int N)
	{
		this.m_num_components = N;
		this.m_uf = new WeightedQuickUnionUF(N);
	}
	
	public boolean connected()
	{
		return m_num_components == 1;
	}
	
	void connect(int p, int q)
	{
		if(!m_uf.connected(p, q))
		{
			m_uf.union(p,q);
			--m_num_components;
		}
	}
	
	public static void main(String args[]) throws FileNotFoundException
	{
		final int N = Integer.parseInt(args[0]);
		final SocialNetworkConnectivity snc = new SocialNetworkConnectivity(N);
		
		ConnectionReader cr = new ConnectionReader("logfile.txt");
		
		Connection c = null;
		while (!snc.connected() && !cr.hasNext())
		{
			c = cr.next();
			snc.connect(c.member1.id, c.member2.id);
		}
		
		if (snc.connected())
		{
			System.out.println("All members connected at: " + c.time);
		}
	}
}
