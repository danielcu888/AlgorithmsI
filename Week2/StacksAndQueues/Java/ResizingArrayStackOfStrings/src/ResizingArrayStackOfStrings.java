
public class ResizingArrayStackOfStrings {
	private String[] a;
	private int capacity;
	private int head;
	
	public ResizingArrayStackOfStrings() {
		this.a = new String[1];
		this.capacity = this.a.length;
		this.head = 0;
	}
	
	public boolean isEmpty() {
		return this.head == 0;
	}
	
	public String pop() {
		if (this.isEmpty()) {
			throw new IllegalStateException("Cannot pop empty ResizingArrayStackOfStrings.");
		}
		
		--this.head;
		final String s = this.a[this.head];
		this.a[this.head] = null;
		
		if (this.head == this.capacity/4) {
			final int newCapacity = Math.max(1, this.capacity/2);
			final String[] newA = new String[newCapacity];
			for (int i = 0; i < newCapacity; ++i) {
				newA[i] = this.a[i];
			}

			this.a = newA;
			this.capacity = newCapacity;
		}
		
		return s;
	}
	
	public void push(String s) {
		if (this.head == this.capacity) {
			final int newCapacity = Math.max(1, 2*this.capacity);
			final String[] newA = new String[newCapacity];
			for (int i = 0; i < this.capacity; ++i) {
				newA[i] = this.a[i];
			}
			
			this.capacity = newCapacity;
			this.a = newA;
		}
		
		this.a[head++] = s;
	}
	
	public int size() {
		return this.head;
	}
}
