import static org.junit.jupiter.api.Assertions.*;

import java.util.Iterator;
import java.util.NoSuchElementException;

import org.junit.jupiter.api.Test;

class DequeTest {

	@Test
	void ConstructorTest() {

		final Deque<Integer> d = new Deque<Integer>(); 
		assertTrue(d.isEmpty());
		assertEquals(d.size(), 0);
	}
		
	@Test
	void RemoveFirstThrowsIfEmpty() {
	    assertThrows( NoSuchElementException.class
	    		    , ()->{
	    		    		final Deque<Integer> d = new Deque<Integer>();
	    		    		d.removeFirst();
	    		    	  }
	    		    );
	}
	
	@Test
	void RemoveLastThrowsIfEmpty() {
	    assertThrows( NoSuchElementException.class
	    		    , ()->{
	    		    		final Deque<Integer> d = new Deque<Integer>();
	    		    		d.removeLast();
	    		    	  }
	    		    );
	}
	
	@Test
	void IteratorNextFalseIfEmpty() {
		
		final Deque<Integer> d = new Deque<Integer>(); 
		final Iterator<Integer> iter = d.iterator();
		assertFalse(iter.hasNext());
	}

	@Test
	void IteratorThrowsIfEmpty() {
	    assertThrows( NoSuchElementException.class
    		    , ()->{
    		    		final Deque<Integer> d = new Deque<Integer>();
    		    		final Iterator<Integer> iter = d.iterator();
    		    		iter.next();
    		    	  }
    		    );	
	}
	
	@Test
	void IteratorThrowsIfEmptyWithMessageCheck() {
		try {
    		final Deque<Integer> d = new Deque<Integer>();
    		final Iterator<Integer> iter = d.iterator();
    		iter.next();
		} catch (NoSuchElementException exc) {
			assertEquals(exc.getMessage(), "next: No more Item's.");
		} catch (Exception exc) {
			throw exc;
		}
	}
	
	@Test
	void IteratorRemoveThrows() {
	    assertThrows( UnsupportedOperationException.class
    		    , ()->{
    		    		final Deque<Integer> d = new Deque<Integer>();
    		    		final Iterator<Integer> iter = d.iterator();
    		    		iter.remove();
    		    	  }
    		    );	
	}

	@Test
	void AddFirstSingleItemTest() {

		final Deque<Integer> d = new Deque<Integer>(); 
		d.addFirst(2);
		assertFalse(d.isEmpty());
		assertEquals(d.size(), 1);
		
		final Iterator<Integer> iter = d.iterator();
		assertTrue(iter.hasNext());
		assertEquals(iter.next().intValue(), 2);
		assertFalse(iter.hasNext());
	}

	@Test
	void AddLastSingleItemTest() {

		final Deque<Integer> d = new Deque<Integer>(); 
		d.addLast(2);
		assertFalse(d.isEmpty());
		assertEquals(d.size(), 1);
		
		final Iterator<Integer> iter = d.iterator();
		assertTrue(iter.hasNext());
		assertEquals(iter.next().intValue(), 2);
		assertFalse(iter.hasNext());
	}

	@Test
	void AddFirstTwoItemsTest() {

		final Deque<Integer> d = new Deque<Integer>(); 
		d.addFirst(2);
		d.addFirst(6);
		assertFalse(d.isEmpty());
		assertEquals(d.size(), 2);
		
		final Iterator<Integer> iter = d.iterator();
		assertTrue(iter.hasNext());
		assertEquals(iter.next().intValue(), 6);
		assertTrue(iter.hasNext());
		assertEquals(iter.next().intValue(), 2);
		assertFalse(iter.hasNext());
	}

	@Test
	void AddLastTwoItemsTest() {

		final Deque<Integer> d = new Deque<Integer>(); 
		d.addLast(2);
		d.addLast(6);
		
		assertFalse(d.isEmpty());
		assertEquals(d.size(), 2);
		
		final Iterator<Integer> iter = d.iterator();
		assertTrue(iter.hasNext());
		assertEquals(iter.next().intValue(), 2);
		assertTrue(iter.hasNext());
		assertEquals(iter.next().intValue(), 6);
		assertFalse(iter.hasNext());
	}

	@Test
	void RemoveFirstSingleItemTest() {

		final Deque<Integer> d = new Deque<Integer>(); 
		d.addFirst(2);
		d.removeFirst();
		
		assertTrue(d.isEmpty());
	}

	@Test
	void RemoveLastSingleItemTest() {

		final Deque<Integer> d = new Deque<Integer>(); 
		d.addLast(2);
		d.removeLast();
		
		assertTrue(d.isEmpty());
	}

	@Test
	void RemoveFirstTwoItemsTest() {

		final Deque<Integer> d = new Deque<Integer>(); 
		d.addFirst(2);
		d.addFirst(6);
		d.removeFirst();
		
		final Iterator<Integer> iter = d.iterator();
		assertTrue(iter.hasNext());
		assertEquals(iter.next().intValue(), 2);

		d.removeFirst();
		
		assertTrue(d.isEmpty());
	}

	@Test
	void RemoveLastTwoItemsTest() {

		final Deque<Integer> d = new Deque<Integer>(); 
		d.addLast(100);
		d.addFirst(0);
		d.removeLast();
		
		final Iterator<Integer> iter = d.iterator();
		assertTrue(iter.hasNext());
		assertEquals(iter.next().intValue(), 0);

		d.removeLast();
		
		assertTrue(d.isEmpty());
	}

	@Test
	void AddRemoveManyItemsTest() {

		final Deque<Integer> d = new Deque<Integer>();
		// {}
		d.addFirst(0);
		// {0}
		d.addLast(45);
		// {0,45}
		d.addLast(4);
		// {0,45,4}
		d.addFirst(66);
		// {66,0,45,4}
		d.removeLast();
		// {66,0,45}
		d.addLast(777);
		// {66,0,45,777}
		d.addFirst(9);
		// {9,66,0,45,777}		
		d.removeFirst();
		// {66,0,45,777}		
		d.addLast(45);
		// {66,0,45,777,45}
		d.addFirst(89);
		// {89,66,0,45,777,45}		
		d.addFirst(45);
		// {45,89,66,0,45,777,45}		
		d.addLast(45);
		// {45,89,66,0,45,777,45,45}		
		d.removeFirst();
		// {89,66,0,45,777,45,45}		
		d.removeLast();
		// {89,66,0,45,777,45}		
		
		assertEquals(d.size(), 6);
		
		final Iterator<Integer> iter = d.iterator();
		assertEquals(iter.next().intValue(), 89);
		assertEquals(iter.next().intValue(), 66);
		assertEquals(iter.next().intValue(), 0);
		assertEquals(iter.next().intValue(), 45);
		assertEquals(iter.next().intValue(), 777);
		assertEquals(iter.next().intValue(), 45);
	}
	
}
