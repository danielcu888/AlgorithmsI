import java.util.Iterator;

public class Stack<Item> implements Iterable<Item> {

	private class Node {
		Node next;
		Item item;
		
		Node(Item item_, Node next_) {
			this.item = item_;
			this.next = next_;
		}
	}
	
	private class StackIterator implements Iterator<Item> {

		Node n;
		
		public StackIterator() {
			this.n = head;
		}
		
		@Override
		public boolean hasNext() {
			return n != null;
		}

		@Override
		public Item next() {
			if (!this.hasNext()) {
				throw new IllegalStateException("No more elements.");
			}
			
			final Item item = this.n.item;
			this.n = this.n.next;
			
			return item;
		}
	}
	
	private Node head;
	private int sz;
	
	public Stack() {
		this.head = null;
		this.sz = 0;
	}
	
	public boolean isEmpty() {
		return this.sz == 0;
	}
	
	public Item pop() {
		if (this.isEmpty()) {
			throw new IllegalStateException("Cannot pop an empty Stack.");
		}
		
		final Item item = this.head.item;
		this.head = this.head.next;
		--this.sz;
		
		return item;
	}
	
	public void push(Item item) {
		this.head = new Node(item, this.head);
		++this.sz;
	}
	
	public int size() {
		return this.sz;
	}
	
	@Override
	public Iterator<Item> iterator() {
		return new StackIterator();
	}
}
