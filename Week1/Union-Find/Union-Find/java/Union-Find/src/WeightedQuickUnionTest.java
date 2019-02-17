import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class WeightedQuickUnionTest {

	WeightedQuickUnion wqu;
	
	@Test
	void testJoin() {
		wqu = new WeightedQuickUnion(5);
		wqu.join(0, 1);
		wqu.join(1, 2);
		wqu.join(1, 4);
		
		final String actual = wqu.toString();
		final String expected = "1 1 1 3 1 \n1 4 1 1 1 ";
		
		assertEquals(actual.compareTo(expected), 0);		
	}
}
