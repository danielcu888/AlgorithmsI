import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class SuccessorWithDeleteTest {

	private SuccessorWithDelete s;
	
	@Test
	void testConstructor() {
		s = new SuccessorWithDelete(7);
		assertEquals(s.successor(0), 1);
		assertEquals(s.successor(1), 2);
		assertEquals(s.successor(2), 3);
		assertEquals(s.successor(3), 4);
		assertEquals(s.successor(4), 5);
		assertEquals(s.successor(5), 6);
		assertEquals(s.successor(6), -1);	
	}

	@Test
	void testWithSingleRemoval() {
		s = new SuccessorWithDelete(7);
		s.remove(2);
		assertEquals(s.successor(0), 1);
		assertEquals(s.successor(1), 3);
		assertEquals(s.successor(2), 3);
		assertEquals(s.successor(3), 4);
		assertEquals(s.successor(4), 5);
		assertEquals(s.successor(5), 6);
		assertEquals(s.successor(6), -1);	
	}

	@Test
	void testWithTwoRemovals() {
		s = new SuccessorWithDelete(7);
		s.remove(2);
		s.remove(3);
		assertEquals(s.successor(0), 1);
		assertEquals(s.successor(1), 4);
		assertEquals(s.successor(2), 4);
		assertEquals(s.successor(3), 4);
		assertEquals(s.successor(4), 5);
		assertEquals(s.successor(5), 6);
		assertEquals(s.successor(6), -1);	
	}

	@Test
	void testWithThreeRemovals() {
		s = new SuccessorWithDelete(7);
		s.remove(2);
		s.remove(3);
		s.remove(0);
		assertEquals(s.successor(0), 1);
		assertEquals(s.successor(1), 4);
		assertEquals(s.successor(2), 4);
		assertEquals(s.successor(3), 4);
		assertEquals(s.successor(4), 5);
		assertEquals(s.successor(5), 6);
		assertEquals(s.successor(6), -1);	
	}

	@Test
	void testWithFourRemovals() {
		s = new SuccessorWithDelete(7);
		s.remove(2);
		s.remove(3);
		s.remove(0);
		s.remove(6);
		assertEquals(s.successor(0), 1);
		assertEquals(s.successor(1), 4);
		assertEquals(s.successor(2), 4);
		assertEquals(s.successor(3), 4);
		assertEquals(s.successor(4), 5);
		assertEquals(s.successor(5), -1);
		assertEquals(s.successor(6), -1);	
	}

	@Test
	void testWithFiveRemovals() {
		s = new SuccessorWithDelete(7);
		s.remove(2);
		s.remove(3);
		s.remove(0);
		s.remove(6);
		s.remove(4);
		assertEquals(s.successor(0), 1);
		assertEquals(s.successor(1), 5);
		assertEquals(s.successor(2), 5);
		assertEquals(s.successor(3), 5);
		assertEquals(s.successor(4), 5);
		assertEquals(s.successor(5), -1);
		assertEquals(s.successor(6), -1);	
	}

	@Test
	void testWithSixRemovals() {
		s = new SuccessorWithDelete(7);
		s.remove(2);
		s.remove(3);
		s.remove(0);
		s.remove(6);
		s.remove(4);
		s.remove(1);
		assertEquals(s.successor(0), 5);
		assertEquals(s.successor(1), 5);
		assertEquals(s.successor(2), 5);
		assertEquals(s.successor(3), 5);
		assertEquals(s.successor(4), 5);
		assertEquals(s.successor(5), -1);
		assertEquals(s.successor(6), -1);	
	}

	@Test
	void testWithAllRemoved() {
		s = new SuccessorWithDelete(7);
		s.remove(2);
		s.remove(3);
		s.remove(0);
		s.remove(6);
		s.remove(4);
		s.remove(1);
		s.remove(5);
		assertEquals(s.successor(0), -1);
		assertEquals(s.successor(1), -1);
		assertEquals(s.successor(2), -1);
		assertEquals(s.successor(3), -1);
		assertEquals(s.successor(4), -1);
		assertEquals(s.successor(5), -1);
		assertEquals(s.successor(6), -1);	
	}
}
