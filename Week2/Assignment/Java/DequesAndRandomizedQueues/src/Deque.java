import java.util.Iterator;
import java.util.NoSuchElementException;

public class Deque<Item> implements Iterable<Item> {

	private class Node {
		Item val;
		Node prev;
		Node next;
		
		Node(Item val_, Node prev_, Node next_) {
			this.val = val_;
			this.prev = prev_;
			this.next = next_;
		}
	}
	
	private Node head;
	private Node tail;
	private int sz;
	
	/**
	 * @brief Default Constructor.
	 */
	public Deque() {
		this.head = null;
		this.tail = null;
		this.sz = 0;
	}
	
	/**
	 * @brief Returns if this Deque is empty.
	 * @return If this Deque is empty.
	 */
	public boolean isEmpty() {
		return this.sz == 0;
	}
	
	/**
	 * @brief Returns the size of this Deque.
	 * @return The size of this Deque.
	 */
	public int size() {
		return this.sz;
	}
	
	/**
	 * @brief Adds the specified Object to the front of this Deque.
	 * @param t The specified Object to be added.
	 * @throws IllegalArgumentException if one attempts to add null.
	 */
	public void addFirst(Item t) {
		if (t == null) {
			throw new IllegalArgumentException("addFirst() - null argument.");
		} else if (this.isEmpty()) {
			this.head = this.tail = new Node(t, null, null);
		} else if (this.head == this.tail) {
			this.head = new Node(t, null, this.head);
			this.tail.prev = this.head;
		} else {
			this.head.prev = new Node(t, null, this.head);
			this.head = this.head.prev;
		}
		
		++this.sz;
	}

	/**
	 * @brief Adds the specified Object to the back of this Deque.
	 * @param t The specified Object to be added.
	 * @throws IllegalArgumentException if one attempts to add null.
	 */
	public void addLast(Item t) {
		if (t == null) {
			throw new IllegalArgumentException("addLast() - null argument.");
		} else if (this.isEmpty()) {
			this.head = this.tail = new Node(t, null, null);
		} else if (this.head == this.tail) {
			this.tail.next = new Node(t, this.tail, null);
			this.tail = this.tail.next;
			this.head.next = this.tail;
		} else {
			this.tail.next = new Node(t, this.tail, null);
			this.tail = this.tail.next;
		}
		
		++this.sz;
	}
	
	/**
	 * @brief Removes and returns the Object at the front of this Deque.
	 * @return The Object at the front of this Deque.
	 * @throws NoSuchElementException If this Deque is empty.
	 */
	public Item removeFirst() {
		if (this.isEmpty()) {
			throw new NoSuchElementException("removeFirst() - empty Deque.");
		}
		
		final Item retVal = this.head.val;

		if (this.head == this.tail) {
			this.head = this.tail = null;
		} else {
			this.head = this.head.next;
			this.head.prev = null;
		}
		
		--this.sz;
		
		return retVal;
	}
	
	/**
	 * @brief Removes and returns the Object at the back of this Deque.
	 * @return The Object at the back of this Deque.
	 * @throws NoSuchElementException If this Deque is empty.
	 */
	public Item removeLast() {
		if (this.isEmpty()) {
			throw new NoSuchElementException("Cannot removeLast() from an empty Deque.");
		}
		
		final Item ret = this.tail.val;
		
		if (this.head == this.tail) {
			this.head = this.tail = null;
		} else {
			this.tail = this.tail.prev;
			this.tail.next = null;
		}
		
		--this.sz;
		
		return ret;
	}
	
	private class DequeIterator implements Iterator<Item> {
		Node n;
		
		DequeIterator() {
			this.n = head;
		}

		@Override
		public boolean hasNext() {
			return this.n != null;
		}

		@Override
		public Item next() {
			if (!this.hasNext()) {
				throw new NoSuchElementException("next() - No more elements.");
			}
			final Item ret = this.n.val;
			this.n = this.n.next;
			return ret;
		}
		
		@Override
		public void remove() {
			throw new UnsupportedOperationException("remove() - not supported.");
		}
	}
	/**
	 * @brief Return an iterator over the Objects in this Deque
	 *    in order from front to end.
	 * @return An iterator over the Objects in this Deque
	 *    in order from front to end.
	 */
	public Iterator<Item> iterator() {
		return new DequeIterator();
	}
}
