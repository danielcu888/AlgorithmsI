import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Stack<Item> {
	
	private class Node {
		Node(Item item_, Node next_) {
			this.item = item_;
			this.next = next_;
		}
		
		Item item;
		Node next;
	}
	
	private Node head;
	private int sz;
	
	public Stack() {
		this.head = null;
		this.sz = 0;
	}
	
	void push(Item item) {
		this.head = new Node(item, this.head);
		++this.sz;
	}
	
	Item pop() {
		if (this.isEmpty()) {
			throw new IllegalStateException("Cannot pop empty Stack.");
		}
		final Item s = this.head.item;
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
		final Stack<String> stack = new Stack<String>();
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
