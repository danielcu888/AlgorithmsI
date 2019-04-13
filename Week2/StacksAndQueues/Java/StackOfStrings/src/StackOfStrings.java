import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class StackOfStrings {
	
	private class Item {
		Item(String s_, Item next_) {
			this.s = s_;
			this.next = next_;
		}
		
		String s;
		Item next;
	}
	
	private Item head;
	private int sz;
	
	public StackOfStrings() {
		this.head = null;
		this.sz = 0;
	}
	
	void push(String item) {
		this.head = new Item(item, this.head);
		++this.sz;
	}
	
	String pop() {
		if (this.isEmpty()) {
			throw new IllegalStateException("Cannot pop empty StackOfStrings.");
		}
		final String s = this.head.s;
		this.head = this.head.next;
		return s;
	}
	
	boolean isEmpty() {
		return this.head == null;
	}
	
	int size() {
		return this.sz;
	}
	
	public static void main(String[] args) {
		final StackOfStrings stack = new StackOfStrings();
		while (!StdIn.isEmpty()) {
			final String s = StdIn.readString();
			if (s.equals("-")) {
				StdOut.print(stack.pop());
			} else {
				stack.push(s);
			}
		}
	}
}
