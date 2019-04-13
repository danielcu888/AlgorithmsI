
public class QueueOfStrings {
	
	private class Node {

		Node(String s_) {
			this.s = s_;
			this.next = null;
		}
		
		String s;
		Node next;
	}
	
	private Node head;
	private Node tail;
	private int sz;
	
	public QueueOfStrings() {
		this.head = this.tail = null;
		this.sz = 0;
	}
	
	public void enqueue(String item) {
		if (this.isEmpty()) {
			this.head = this.tail = new Node(item);
		}
		
		this.tail.next = new Node(item);
		this.tail = this.tail.next;
		
		++this.sz;		
	}
	
	public String dequeue() {
		if (this.isEmpty()) {
			throw new IllegalStateException("Cannot dequeue an empty QueueOfStrings.");
		}
		
		final String s = this.head.s;
		if (this.size() == 1) {
			this.head = this.tail = null;
		} else {
			this.head = this.head.next;
		}
		
		--this.sz;
		
		return s;
	}
	
	public boolean isEmpty() {
		return this.sz == 0;
	}
	
	public int size() {
		return this.sz;
	}
}
