import static org.junit.jupiter.api.Assertions.*;

import java.util.Arrays;
import java.util.Iterator;
import java.util.NoSuchElementException;

import org.junit.jupiter.api.Test;

class RandomizedQueueTest {

	@Test
	void ConstructorTest() {
		final RandomizedQueue<Integer> q =
				new RandomizedQueue<Integer>();
		
		assertTrue(q.isEmpty());
		assertEquals(q.size(), 0);
	}
	
	@Test
	void IsEmptyTrueTest() {
		final RandomizedQueue<Integer> q =
				new RandomizedQueue<Integer>();

		assertTrue(q.isEmpty());
	}
	
	@Test
	void SizeEmptyTest() {
		final RandomizedQueue<Integer> q =
				new RandomizedQueue<Integer>();

		assertEquals(q.size(), 0);
	}
	
	@Test
	void EnqueueTest() {
		final RandomizedQueue<Integer> q =
				new RandomizedQueue<Integer>();
		
		
		q.enqueue(1);
		assertFalse(q.isEmpty());
		assertEquals(q.size(), 1);
	}	
	
	@Test
	void DequeueTest() {
		final RandomizedQueue<Integer> q =
				new RandomizedQueue<Integer>();
		
		
		q.enqueue(1);
		q.dequeue();
		assertTrue(q.isEmpty());
	}
	
	@Test
	void DequeueThrowsIfEmptyTest() {
		
	    assertThrows( NoSuchElementException.class
    		    , ()->{
    		    		final RandomizedQueue<Integer> q =
    		    				new RandomizedQueue<Integer>();
    		    		q.dequeue();
    		    	   }
	    );
	}
	
	
	@Test
	void EnqueueMultipleTest() {
		final RandomizedQueue<Integer> q =
				new RandomizedQueue<Integer>();
		
		q.enqueue(1);
		q.enqueue(1);
		q.enqueue(1);
		q.enqueue(1);
		q.enqueue(1);
		q.enqueue(1);
		q.enqueue(1);
		q.enqueue(1);
		q.enqueue(1);		
		assertFalse(q.isEmpty());
		assertEquals(q.size(), 9);
	}	

	@Test
	void SampleThrowsIfEmptyTest() {
	    assertThrows( NoSuchElementException.class
    		    , ()->{ final RandomizedQueue<Integer> q =
							new RandomizedQueue<Integer>();
    		    		q.sample();
    		    	  }
        );
	}
	
	@Test
	void SampleTest() {
		final RandomizedQueue<Integer> q =
				new RandomizedQueue<Integer>();
		q.enqueue(1);
		q.enqueue(2);
		q.enqueue(3);
		q.enqueue(4);
		
		for (int i = 0; i < 100; ++i) {
			q.sample();
		}
	}
	
	@Test
	void IteratorHasNextFalseEmptyTest() {
		final RandomizedQueue<Integer> q =
				new RandomizedQueue<Integer>();
    		final Iterator<Integer> iter = q.iterator();
    		assertFalse(iter.hasNext());
	}
	
	@Test
	void IteratorThrowsIfEmptyTest() {
	    assertThrows( NoSuchElementException.class
    		    , ()->{ final RandomizedQueue<Integer> q =
							new RandomizedQueue<Integer>();
    		    		final Iterator<Integer> iter = q.iterator();
    		    		iter.hasNext();
    		    		iter.next();
    		    	  }
        );
	}

	@Test
	void IteratorHasNextTest() {
		final RandomizedQueue<Integer> q =
				new RandomizedQueue<Integer>();
    	
		q.enqueue(1);

		final Iterator<Integer> iter = q.iterator();

    	assertTrue(iter.hasNext());
	}
	
	@Test
	void IteratorNextTest() {
		final RandomizedQueue<Integer> q =
				new RandomizedQueue<Integer>();
		
		q.enqueue(1);

		final Iterator<Integer> iter = q.iterator();
    	assertTrue(iter.hasNext());
    	
    	assertEquals(iter.next().intValue(), 1);
	}

	
	@Test
	void IteratorNextMultipleTest() {
		final RandomizedQueue<Integer> q =
				new RandomizedQueue<Integer>();

		for (int i = 0; i < 100; ++i) {
			q.enqueue(i);
		}

		final Integer[] arr = new Integer[100];
		final Iterator<Integer> iter = q.iterator();
    	for (int i = 0; i < 100; ++i)
    	{
    		arr[i] = iter.next();
    	}
    	
    	Arrays.sort(arr);
    	
    	for (int i = 0; i < 100; ++i) {
    		assertEquals(arr[i].intValue(), i);
    	}
	}
}	
