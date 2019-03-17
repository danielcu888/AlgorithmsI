import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class SearchInBitonicArrayTest {

	@Test
	void test() {
		final int[] a = {-3,-2,-1,0,1,2,3};
		SearchInBitonicArray s = new SearchInBitonicArray(a);
		
		final int i = s.search(0);
		assertEquals(i, 3);
	}

	@Test
	void test1() {
		final int[] a = {-3,-2,-1,0,-1,-2,-3};
		SearchInBitonicArray s = new SearchInBitonicArray(a);
		
		final int i = s.search(-2);
		assertEquals(i, 5);
	}

	@Test
	void test2() {
		final int[] a = {-3,-2,-1,0,-1,-2};
		SearchInBitonicArray s = new SearchInBitonicArray(a);
		
		final int i = s.search(-2);
		
		assertTrue(i == 1 || i == 5);
	}

	@Test
	void test3() {
		final int[] a = {-3,-2,-1,101,99,9,8,2,1};
		SearchInBitonicArray s = new SearchInBitonicArray(a);
				
		assertEquals(s.search(-3), 0);
	}
	
	@Test
	void test4() {
		final int[] a = {-3,-2,-1,101,99,9,8,2,1};
		SearchInBitonicArray s = new SearchInBitonicArray(a);
				
		for (int i = 0; i < a.length; ++i) {
			assertEquals(s.search(a[i]), i);
		}
	}
}
