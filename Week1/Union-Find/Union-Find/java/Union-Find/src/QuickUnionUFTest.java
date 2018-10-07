
import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class QuickUnionUFTest {

	@Test
	void test() {

		final int N = 10;
		final UF uf = new QuickUnionUF(N);
		
		TestData[] tds = { new TestData(1, 2, '+'),
						   new TestData(2, 3, '+')
						 };

		final String expected = "";
		
		final String actual = TestUF.test(uf, tds);
		
		assertEquals(actual, expected);
	}
}