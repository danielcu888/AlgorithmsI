import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class EuclidAlgorithmTest {

	@Test
	void test() {
		assertEquals(EuclidAlgorithm.gcd(3, 6), 3);
	}

	
	@Test
	void test1() {
		assertEquals(EuclidAlgorithm.gcd(1902, 456), 6);
	}
}
