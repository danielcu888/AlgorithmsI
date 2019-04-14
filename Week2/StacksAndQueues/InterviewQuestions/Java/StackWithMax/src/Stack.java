import java.util.Iterator;

public class Stack<T extends Comparable> implements Iterable<T> {

	private class Node {
		T val;
		Node next;
		T max;
		
		Node(T val_, Node next_, T max_) {
			this.val = val_;
			this.next = next_;
			this.max = max_;
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
	
	public T pop() {
		if (this.isEmpty()) {
			throw new IllegalStateException("Cannot pop an empty Stack.");
		}
		
		final T ret = this.head.val;
		this.head = this.head.next;
		--this.sz;
		
		return ret;
	}
	
	public void push(T t) {
		this.head = new Node( t
				            , this.head
				            , (!this.isEmpty() && t.compareTo(this.head.val) < 0) ? this.head.val : t
				            );
		++this.sz;
	}
	
	public int size() {
		return this.sz;
	}
	
	public T max() {
		if (this.isEmpty()) {
			throw new IllegalStateException("Cannot get max of an empty Stack.");
		}
		
		return this.head.max;
	}
	private class StackIterator implements Iterator<T> {

		private Node n;
		
		public StackIterator() {
			this.n = head;
		}
		
		@Override
		public boolean hasNext() {
			return this.n != null;
		}

		@Override
		public T next() {
			if (!this.hasNext()) {
				throw new IllegalStateException("No more elements.");
			}
			
			final T ret = this.n.val;
			this.n = this.n.next;
			
			return ret;
		}
	}
	
	
	@Override
	public Iterator<T> iterator() {
		return new StackIterator();
	}
}
