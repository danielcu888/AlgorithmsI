import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * 
 * @brief A generic double-ended queue or deque
 *   (pronounced “deck”) that supports the addition
 *   and removal of Item's from either the front or the
 *   back of the data structure. 
 *
 */
public class Deque<Item> implements Iterable<Item> {
	
	// Private data members
	
	private Node head;
	private Node tail;
	private int size;
	
	// Public structors

	/// @brief Default constructor.
	public Deque() {
		
		this.head = null;
		this.tail = null;
		this.size = 0;
	}
	
	// Private nested classes
	
	/// @brief A class to represent the 
	///   Nodes of this Deque.
	private class Node {
		
		Item val;
		Node prev;
		Node next;
		
		Node(Item val, Node prev, Node next) {
			
			this.val = val;
			this.prev = prev;
			this.next = next;
		}
	} // ! class Node
	
	/// @brief A Forward Iterator class used for read only
	///   iteration over the Item's contained in this Deque.
	private class ForwardOutputIterator implements Iterator<Item> {

		Node n;
		
		/// @brief Default Constructor.
		public ForwardOutputIterator() {
			
			this.n = head;
		}

		@Override
		public boolean hasNext() {
			
			return this.n != null;
		}

		@Override
		public Item next() {
			
			if (!this.hasNext()) {
				
				throw new NoSuchElementException("next: No more Item's.");
			}
			
			final Item val = this.n.val;
			this.n = this.n.next;
			
			return val;
		}
		
		@Override
		public void remove() {
			throw new UnsupportedOperationException("remove: Is not supported.");
		}
	} /// ! class ForwardOutputIterator
	
	// Public member functions
	
	/// @brief Return if this Deque is empty.
	/// @return If this Deque is empty.
	public boolean isEmpty() {
		
		return this.size == 0;
	}
	
	/// @brief Return the number of Item's
	///   in this Deque.
	/// @return The number of Item's in this
	///   Deque.
	public int size() {
		
		return this.size;
	}

	/// @brief Add the specified Item to
	///   the front of this Deque.
	/// @param item The Item to be added.
	public void addFirst(Item item) {
		
		if (item == null) {
			throw new IllegalArgumentException("addFirst: Null argument.");
		}
		
		this.head = new Node(item, null, this.head);
				
		if (this.tail == null) {
			
			this.tail = this.head;
		} else {
			this.head.next.prev = this.head;
		}
		
		++this.size;
	}

	/// @brief Add the specified Item to
	///   the back of this Deque.
	/// @param item The Item to be added.
	public void addLast(Item item) {
		
		if (item == null) {
			
			throw new IllegalArgumentException("addLast: Null argument.");
		}
		
		Node n = new Node(item, null, null);
		
		if (this.isEmpty()) {
			
			this.head = this.tail = n;
		} else {
			
			this.tail.next = n;
			this.tail.next.prev = this.tail;
			this.tail = this.tail.next;
		}
		
		++this.size;
	}
	
	/// @brief Remove and return the Item at
	///   the front of this Deque.
	/// @param item The Item at the front of this
	///   Deque.
	public Item removeFirst() {
		
		if (this.isEmpty()) {
			
			throw new NoSuchElementException("removeFirst: Empty Deque.");
		}
	
		final Node n = this.head;
		
		if (this.head == this.tail) {
			
			this.head = this.tail = null;
		} else {
			
			this.head = this.head.next;
			this.head.prev = null;
		}
		
		--this.size;
		
		return n.val;
	}

	/// @brief Remove and return the Item at
	///   the back of this Deque.
	/// @param item The Item at the back of this
	///   Deque.
	public Item removeLast() {
		
		if (this.isEmpty()) {
			
			throw new NoSuchElementException("removeLast: Empty Deque.");			
		}
		
		final Node n = this.tail;
		
		if (this.head == this.tail) {
			
			this.head = this.tail = null;
		} else {
			
			this.tail = this.tail.prev;
			this.tail.next = null;
		}
		
		--this.size;
		
		return n.val;
	}
		
	@Override
	public Iterator<Item> iterator() {
		
		return new ForwardOutputIterator();
	}	
}
