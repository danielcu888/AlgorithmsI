import java.util.Iterator;
import java.util.NoSuchElementException;

import edu.princeton.cs.algs4.StdRandom;

public class RandomizedQueue<T> implements Iterable<T> {

	private int capacity;
	private T[] a;
	private int head; // Points to the first element.
	private int tail; // Points to the next element to be filled.
	private int sz;
	
	/**
	 * @brief Construct an empty RandomizedQueue.
	 */
	public RandomizedQueue() {
		this.capacity = 1;
		this.a = (T[]) new Object[this.capacity];
		this.head = 0;
		this.tail = 0;
		this.sz = 0;
	}
	
	/**
	 * @brief Return if this RandomizedQueue is empty.
	 * @return If this RandomizedQueue is empty.
	 */
	public boolean isEmpty() {
		return this.sz == 0;
	}
	
	/**
	 * @brief Return the number of Object's in this RandomizedQueue.
	 * @return The number of Object's in this RandomizedQueue.
	 */
	public int size() {
		return this.sz;
	}
	
	private void resize(int newCapacity) {
		final T[] newA = (T[]) new Object[newCapacity];
		for (int i = this.head, j = 0; i < this.tail; ++i, ++j) {
			newA[j] = this.a[i];
		}
		this.capacity = newCapacity;
		this.a = newA;
		this.head = 0;
		this.tail = this.sz;
	}
	
	/**
	 * @brief Add the specified Object to the back of this RandomizedQueue.
	 * @param t The Object to be added.
	 * @throws 
	 */
	public void enqueue(T t) {
		if (t == null) {
			throw new IllegalArgumentException("enqueue() - null argument.");
		}
		
		if (this.tail == this.capacity) {
			this.resize(Math.max(1, 2 * this.capacity));
		}
		
		this.a[this.tail++] = t;
		++this.sz;
	}
	
	/**
	 * @brief Return the Object from the front of this RandomizedQueue.
	 * @return The Object from the front of this RandomizedQueue.
	 */
	public T dequeue() {
		if (this.isEmpty()) {
			throw new NoSuchElementException("dequeue() - Empty RandomizedQueue.");
		}
		
		if (this.sz == this.capacity/4) {
			this.resize(Math.max(1, this.capacity/2));
		}
		
		final int ridx = this.head + StdRandom.uniform(this.sz);
		final T ret = this.a[ridx];
		
		this.a[ridx] = this.a[this.tail-1];
		this.a[--this.tail] = null;
		--this.sz;
		
		return ret;
	}
	
	public T sample() {
		if (this.isEmpty()) {
			throw new NoSuchElementException("sample() - Empty RandomizedQueue.");
		}
		
		return this.a[this.head + StdRandom.uniform(this.sz)];
	}
	
	private class RandomizedDequeIterator implements Iterator<T> {

		T[] b;
		int bSize;
		
		public RandomizedDequeIterator() {
			this.b = (T[]) new Object[sz];
			for (int i = head, j = 0; i < tail; ++i, ++j) {
				this.b[j] = a[i];
			}
			this.bSize = sz;
		}
		
		@Override
		public boolean hasNext() {
			return this.bSize > 0;
		}

		@Override
		public T next() {
			if (!this.hasNext()) {
				throw new NoSuchElementException("next() - No more elements.");
			}
			
			final int ridx = StdRandom.uniform(this.bSize);
			final T ret = this.b[ridx];
			this.b[ridx] = this.b[this.bSize-1];
			this.b[this.bSize-1] = null;
			--this.bSize;
			
			return ret;
		}
	}
	
	@Override
	public Iterator<T> iterator() {
		return new RandomizedDequeIterator();
	}
}
