import edu.princeton.cs.algs4.StdIn;

public class Permutation {
	public static void main(String[] args) {
		
		final int k = Integer.parseInt(args[0]);

		final RandomizedQueue<String> rq = new RandomizedQueue<String>();
		while (!StdIn.isEmpty()) {
			rq.enqueue(StdIn.readString());
		}
		
		for (int i = 0; i < k; ++i) {
			System.out.println(rq.dequeue());
		}
	}
}
