import java.util.Iterator;

public class Stack<Item> implements Iterable<Item> {

	private int capacity;
	private Item[] a;
	private int head;
	
	private class StackIterator implements Iterator<Item> {

		int i;
		
		public StackIterator() {
			this.i = head;
		}
		
		@Override
		public boolean hasNext() {
			return this.i != 0;
		}

		@Override
		public Item next() {
			if (!this.hasNext()) {
				throw new IllegalStateException("No more elements.");
			}
			
			final Item item = a[--this.i];
			
			return item;
		}
	}
		
	public Stack(int N) {
		if (N <= 0) {
			throw new IllegalArgumentException("Invalid capacity.");
		}
		
		this.capacity = N;
		this.a = (Item[])new Object[this.capacity];
		this.head = 0;
	}
	
	public boolean isEmpty() {
		return this.head == 0;
	}
	
	public Item pop() {
		if (this.isEmpty()) {
			throw new IllegalStateException("Cannot pop an empty Stack.");
		}
		
		--this.head;
		final Item item = this.a[this.head];
		this.a[this.head] = null;
		
		return item;
	}
	
	public void push(Item item) {
		if (this.head == this.capacity) {
			throw new IllegalStateException("Cannot push onto full Stack.");
		}
		
		this.a[this.head++] = item;
	}
	
	public int size() {
		return this.head;
	}
	
	@Override
	public Iterator<Item> iterator() {
		return new StackIterator();
	}
}
