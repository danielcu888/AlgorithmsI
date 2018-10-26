import java.util.Iterator;
import java.util.NoSuchElementException;
import edu.princeton.cs.algs4.StdRandom;

public class RandomizedQueue<Item> implements Iterable<Item> {

	private Item[] a;
	private int tail;
	
	public RandomizedQueue() {
		this.a = null;
		this.tail = 0;
	}
	
	public boolean isEmpty() {
		return this.tail == 0;
	}
	
	public int size() {
		return this.tail;
	}
	
	public void enqueue(Item item) {

		if (item == null) {
			throw new IllegalArgumentException("enqueue: Null Item.");
		}
		
		if (this.tail == a.length) {
			Item[] new_a = (Item[]) new Object[Math.max(2*a.length, 1)];
			for (int i = 0; i < a.length; ++i) {
				new_a[i] = a[i];
			}
			this.a = new_a;
		}
		
		this.a[this.tail++] = item;
	}
	
	public Item dequeue() {
		
		if (this.isEmpty()) {
			throw new NoSuchElementException("dequeue: Empty RandomizedQueue.");
		}
		
		final int idx = StdRandom.uniform(this.tail);
		final Item val = this.a[idx];
		--this.tail;
		if (this.tail > 0)
		{
			this.a[idx] = this.a[this.tail-1];
		}
		
		return val;
	}
	
	public Item sample()
	{
		if (this.isEmpty()) {
			throw new NoSuchElementException("sample: Empty RandomizedQueue.");
		}
		
		return this.a[edu.princeton.cs.algs4.StdRandom.uniform(this.tail)];
	}
	
	private class RandomIterator<Item> implements Iterator<Item>
	{
		int iter_tail;
		Item[] iter_a;
		
		RandomIterator() {
			this.iter_tail = tail;
			this.iter_a = (Item[]) new Object[this.iter_tail];
			for (int i = 0; i < tail; ++i) {
				this.iter_a[i] = (Item) a[i];
			}
		}
		
		@Override
		public boolean hasNext() {
			return this.iter_tail > 0;
		}

		@Override
		public Item next() {
			if (!this.hasNext()) {
				throw new NoSuchElementException("next: No more Items.");
			}
			
			final int idx = StdRandom.uniform(this.iter_tail);
			final Item val = this.iter_a[idx];
			if (this.iter_tail > 0)
			{
				this.iter_a[idx] = this.iter_a[this.iter_tail-1];
			}
			--this.iter_tail;
			
			return val;
		}
		
		@Override
		public void remove() {
			throw new UnsupportedOperationException("remove: Unsupported.");
		}
		
	}
	
	@Override
	public Iterator<Item> iterator() {
		return new RandomIterator<Item>();
	}

}
