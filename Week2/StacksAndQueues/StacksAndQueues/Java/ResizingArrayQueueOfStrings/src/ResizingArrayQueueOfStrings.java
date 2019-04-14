
public class ResizingArrayQueueOfStrings {

	private int capacity;
	private String[] a;
	private int head;
	private int tail;
	private int sz;
	
	public ResizingArrayQueueOfStrings() {
		this.capacity = 1;
		this.a = new String[this.capacity];
		this.head = 0;
		this.tail = 0;
		this.sz = 0;
	}
	
	public boolean isEmpty() {
		return this.sz == 0;
	}
	
	private void resize(int newCapacity) {
		newCapacity = Math.max(newCapacity, 1);
		final String[] newA = new String[newCapacity];
		for (int i = this.head, j = 0; i < this.tail; ++i, ++j) {
			newA[j] = this.a[i];
		}
		this.a = newA;
		this.head = 0;
		this.tail = this.sz;
		this.capacity = newCapacity;		
	}
	
	public String dequeue() {
		
		if (this.isEmpty()) {
			throw new IllegalStateException("Cannot dequeue empty ResizingArrayQueueOfStrings");
		}
		
		if (this.sz == this.capacity/4) {
			this.resize(this.capacity/2);
		}

		--this.tail;
		final String s = this.a[this.tail];
		this.a[this.tail] = null;
		--this.sz;
		
		return s;
	}
	
	public void enqueue(String item) {
		
		if (this.sz == capacity) {
			this.resize(2*this.capacity);
		}
		
		this.a[this.tail++] = item;
		++this.sz;
	}
	
	public int size() {
		return this.sz;
	}
}
