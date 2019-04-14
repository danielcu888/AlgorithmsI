import edu.princeton.cs.algs4.StdIn;

public class Permutation {
	public static void main(String[] args) {
		
		if (args.length != 1) {
			throw new IllegalArgumentException("usage: Permutation <k>");
		}
		
		final RandomizedQueue<String> q = new RandomizedQueue<String>(); 

		final int k = Integer.parseInt(args[0]);
		
		while(!StdIn.isEmpty()) {
			q.enqueue(StdIn.readString());
		}
		
		for (int i = 0; i < k; ++i) {
			System.out.println(q.dequeue());			
		}
	}
}
