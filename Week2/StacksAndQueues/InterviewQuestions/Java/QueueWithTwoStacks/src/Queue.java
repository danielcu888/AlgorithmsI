import java.util.Iterator;
import java.util.Stack;

public class Queue<Item> implements Iterable<Item> {
	private Stack<Item> current;
	private Stack<Item> front;
	private Stack<Item> back;
	
	public Queue() {
		this.current = this.back;
		this.front = new Stack<Item>();
		this.back = new Stack<Item>();
	}
	
	private void flip() {
		Stack<Item> other;
		if (this.current == this.front) {
			this.current = this.back;
			other = this.front;
		} else {
			this.current = this.front;
			other = this.back;
		}
		
		while (!other.isEmpty()) {
			this.current.push(other.pop());
		}
	}

	public boolean isEmpty() {
		return this.current.isEmpty();
	}
	
	public Item pop() {
		if (this.isEmpty()) {
			throw new IllegalStateException("Cannot pop an empty Queue.");
		}
		
		if (this.current == this.back) {
			this.flip();
		}
		
		return this.current.pop();
	}
	
	public void push(Item item) {
		if (this.current == this.front) {
			this.flip();
		}
		
		this.current.push(item);
	}
	
	public int size() {
		return this.current.size();
	}
	
	@Override
	public Iterator<Item> iterator() {		
		return this.front.iterator();
	}
}
