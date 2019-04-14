import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class StackTest {

	@Test
	void test() {
		final Stack<Integer> s = new Stack<Integer>();
		s.push(1);
		assertEquals(s.max().intValue(), 1);
		s.push(2);
		assertEquals(s.max().intValue(), 2);
		s.push(1);
		assertEquals(s.max().intValue(), 2);
		s.push(13);
		assertEquals(s.max().intValue(), 13);
		s.push(4);
		assertEquals(s.max().intValue(), 13);		
	}

}
