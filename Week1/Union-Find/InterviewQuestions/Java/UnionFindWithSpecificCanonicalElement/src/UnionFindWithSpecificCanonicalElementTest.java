import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class UnionFindWithSpecificCanonicalElementTest {

	@Test
	void testFind1() {
		final UnionFindWithSpecificCanonicalElement uf
			= new UnionFindWithSpecificCanonicalElement(5);
		
		assertEquals(uf.find(0), 0);
		assertEquals(uf.find(1), 1);
		assertEquals(uf.find(2), 2);
		assertEquals(uf.find(3), 3);
		assertEquals(uf.find(4), 4);
	}

	@Test
	void testFind2() {
		final UnionFindWithSpecificCanonicalElement uf
			= new UnionFindWithSpecificCanonicalElement(5);
		
		uf.join(0, 1);
		
		assertEquals(uf.find(0), 1);
		assertEquals(uf.find(1), 1);
		assertEquals(uf.find(2), 2);
		assertEquals(uf.find(3), 3);
		assertEquals(uf.find(4), 4);
	}

	@Test
	void testFind3() {
		final UnionFindWithSpecificCanonicalElement uf
			= new UnionFindWithSpecificCanonicalElement(5);
		
		uf.join(0, 1);
		uf.join(1, 2);
		
		assertEquals(uf.find(0), 2);
		assertEquals(uf.find(1), 2);
		assertEquals(uf.find(2), 2);
		assertEquals(uf.find(3), 3);
		assertEquals(uf.find(4), 4);
	}

	@Test
	void testFind4() {
		final UnionFindWithSpecificCanonicalElement uf
			= new UnionFindWithSpecificCanonicalElement(5);
		
		uf.join(0, 1);
		uf.join(1, 2);
		uf.join(3, 4);
		
		assertEquals(uf.find(0), 2);
		assertEquals(uf.find(1), 2);
		assertEquals(uf.find(2), 2);
		assertEquals(uf.find(3), 4);
		assertEquals(uf.find(4), 4);
	}

	@Test
	void testFind5() {
		final UnionFindWithSpecificCanonicalElement uf
			= new UnionFindWithSpecificCanonicalElement(5);
		
		uf.join(0, 1);
		uf.join(1, 2);
		uf.join(3, 4);
		uf.join(2, 3);
		
		assertEquals(uf.find(0), 4);
		assertEquals(uf.find(1), 4);
		assertEquals(uf.find(2), 4);
		assertEquals(uf.find(3), 4);
		assertEquals(uf.find(4), 4);
	}
}
