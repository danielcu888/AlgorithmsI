import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class QuickFindTest {

	private QuickFind qf;
	
	@Test
	void testConstructor() {
		qf = new QuickFind(5);
		final String actual = qf.toString();
		final String expected = "0 1 2 3 4 ";
		assertEquals(actual.compareTo(expected), 0);
	}
	
	@Test
	void testConnected() {
		qf = new QuickFind(5);
		assertTrue(qf.connected(0, 0));
		assertFalse(qf.connected(0, 1));
		assertFalse(qf.connected(0, 2));
		assertFalse(qf.connected(0, 3));
		assertFalse(qf.connected(0, 4));
		assertTrue(qf.connected(1, 1));
		assertFalse(qf.connected(1, 2));
		assertFalse(qf.connected(1, 3));
		assertFalse(qf.connected(1, 4));
		assertTrue(qf.connected(2, 2));		
		assertFalse(qf.connected(2, 3));
		assertFalse(qf.connected(2, 4));
		assertTrue(qf.connected(3, 3));
		assertFalse(qf.connected(3, 4));
		assertTrue(qf.connected(4, 4));
	}

	@Test
	public void testConstructorThrowsException() {
	    assertThrows( IllegalArgumentException.class
	                , ()->{ new QuickFind(-1); }
	                );
	}
	
	@Test
	void testJoin() {
		qf = new QuickFind(5);
		qf.join(0, 3);
		qf.join(1, 4);
		qf.join(0, 2);
		final String actual = qf.toString();
		final String expected = "2 4 2 2 4 ";
		assertEquals(actual.compareTo(expected), 0);
	}
}
