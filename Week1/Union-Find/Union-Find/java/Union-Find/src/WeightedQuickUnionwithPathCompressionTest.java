import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class WeightedQuickUnionwithPathCompressionTest {

	WeightedQuickUnionwithPathCompression wqupc;
	
	@Test
	void testConstructor() {
		wqupc = new WeightedQuickUnionwithPathCompression(5);
		String actual = wqupc.toString();
		String expected = "0 1 2 3 4 \n1 1 1 1 1 ";
		assertEquals(actual.compareTo(expected), 0);
	}

	@Test
	void testJoin1() {
		wqupc = new WeightedQuickUnionwithPathCompression(5);
		wqupc.join(0, 1);
		String actual = wqupc.toString();
		String expected = "1 1 2 3 4 \n1 2 1 1 1 ";
		assertEquals(actual.compareTo(expected), 0);		
	}
	
	@Test
	void testJoin2() {
		wqupc = new WeightedQuickUnionwithPathCompression(5);
		wqupc.join(0, 1);
		wqupc.join(1, 2);
		String actual = wqupc.toString();
		String expected = "1 1 1 3 4 \n1 3 1 1 1 ";
		assertEquals(actual.compareTo(expected), 0);		
	}
	
	@Test
	void testJoin3() {
		wqupc = new WeightedQuickUnionwithPathCompression(5);
		wqupc.join(0, 1);
		wqupc.join(1, 2);
		wqupc.join(3, 4);
		String actual = wqupc.toString();
		String expected = "1 1 1 4 4 \n1 3 1 1 2 ";
		assertEquals(actual.compareTo(expected), 0);		
	}

	@Test
	void testJoin4() {
		wqupc = new WeightedQuickUnionwithPathCompression(5);
		wqupc.join(0, 1);
		wqupc.join(1, 2);
		wqupc.join(3, 4);
		wqupc.join(3, 2);
		String actual = wqupc.toString();
		String expected = "1 1 1 4 1 \n1 5 1 1 2 ";
		assertEquals(actual.compareTo(expected), 0);		
	}
	
	@Test
	void testRoot() {
		wqupc = new WeightedQuickUnionwithPathCompression(5);
		wqupc.join(0, 1);
		wqupc.join(1, 2);
		wqupc.join(3, 4);
		wqupc.join(3, 2);
		wqupc.connected(3, 0); // Compresses path 3->4->1 to 3->1 and 4->1
		String actual = wqupc.toString();
		String expected = "1 1 1 1 1 \n1 5 1 1 2 ";
		assertEquals(actual.compareTo(expected), 0);		
	}
}