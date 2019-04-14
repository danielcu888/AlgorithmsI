public class LinkedStackOfStrings {

	private class Node {
		Node(String s_, Node next_) {
			this.s = s_;
			this.next = next_;
		}
		
		String s;
		Node next;
	}
	
	private Node head;
	private int sz;
	
	public LinkedStackOfStrings() {
		this.head = null;
		this.sz = 0;
	}
	
	void push(String item) {
		this.head = new Node(item, this.head);
		++this.sz;
	}
	
	String pop() {
		if (this.isEmpty()) {
			throw new IllegalStateException("Cannot pop empty LinkedStackOfStrings.");
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
	
}
