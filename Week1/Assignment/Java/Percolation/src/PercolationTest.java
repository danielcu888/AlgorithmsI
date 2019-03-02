import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

class PercolationTest {

	@Test
	void TestConstructor() {
		final int n = 5;
		final Percolation p = new Percolation(n);
	}
	
	@Test
	void TestIsFull() {
		final int n = 5;
		final Percolation p = new Percolation(n);
		for (int row = 1; row <= n; ++row) {
			for (int col = 1; col <= n; ++col) {
				assertTrue(p.isFull(row, col));
			}
		}
	}
	
	@Test
	void TestIsOpen() {
		final int n = 5;
		final Percolation p = new Percolation(n);
		for (int row = 1; row <= n; ++row) {
			for (int col = 1; col <= n; ++col) {
				assertFalse(p.isOpen(row, col));
			}
		}
	}
	
	@Test
	void TestOpen() {
		final int n = 5;
		final Percolation p = new Percolation(n);
		for (int row = 1; row <= n; ++row) {
			for (int col = 1; col <= n; ++col) {
				p.open(row, col);
				assertTrue(p.isOpen(row, col));
			}
		}
	}

	@Test
	void TestNumberOfOpensites() {
		final int n = 5;
		final Percolation p = new Percolation(n);
		int numberOfOpenSites = 0;
		for (int row = 1; row <= n; ++row) {
			for (int col = 1; col <= n; ++col) {
				p.open(row, col);
				++numberOfOpenSites;
				assertEquals(p.numberOfOpenSites(), numberOfOpenSites);
			}
		}
	}

	@Test
	void TestPercolates1() {
		final Percolation p = new Percolation(5);
		p.open(1, 1);
		assertFalse(p.percolates());
		p.open(2, 1);
		assertFalse(p.percolates());
		p.open(3, 1);
		assertFalse(p.percolates());		
		p.open(4, 1);
		assertFalse(p.percolates());		
		p.open(5, 1);
		assertTrue(p.percolates());		
	}

	@Test
	void TestPercolates2() {
		final Percolation p = new Percolation(5);
		p.open(1, 3);
		assertFalse(p.percolates());
		p.open(2, 3);
		assertFalse(p.percolates());
		p.open(3, 3);
		assertFalse(p.percolates());		
		p.open(4, 3);
		assertFalse(p.percolates());		
		p.open(5, 3);
		assertTrue(p.percolates());		
	}

	@Test
	void TestPercolates3() {
		final Percolation p = new Percolation(5);
		p.open(1, 5);
		assertFalse(p.percolates());
		p.open(2, 5);
		assertFalse(p.percolates());
		p.open(3, 5);
		assertFalse(p.percolates());		
		p.open(4, 5);
		assertFalse(p.percolates());		
		p.open(5, 5);
		assertTrue(p.percolates());		
	}
	
	@Test
	void TestPercolates4() {
		final Percolation p = new Percolation(5);
		p.open(1, 1);
		assertFalse(p.percolates());
		p.open(2, 2);
		assertFalse(p.percolates());
		p.open(3, 3);
		assertFalse(p.percolates());		
		p.open(4, 4);
		assertFalse(p.percolates());		
		p.open(5, 5);
		assertTrue(p.percolates());		
	}
	
	@Test
	void TestPercolates5() {
		final Percolation p = new Percolation(5);
		p.open(1, 1);
		assertFalse(p.percolates());
		p.open(2, 2);
		assertFalse(p.percolates());
		p.open(3, 3);
		assertFalse(p.percolates());		
		p.open(4, 2);
		assertFalse(p.percolates());		
		p.open(5, 1);
		assertTrue(p.percolates());		
	}
	
	@Test
	void TestPercolates6() {
		final Percolation p = new Percolation(1);
		p.open(1, 1);
		assertTrue(p.percolates());		
	}

	@Test
	void TestPercolates7() {
		final Percolation p = new Percolation(2);
		p.open(1, 1);
		assertFalse(p.percolates());
		p.open(2, 2);
		assertTrue(p.percolates());		
	}

	@Test
	void TestPercolates8() {
		final Percolation p = new Percolation(2);
		p.open(1, 1);
		assertFalse(p.percolates());
		p.open(2, 1);
		assertTrue(p.percolates());		
	}

	@Test
	void TestPercolates9() {
		final Percolation p = new Percolation(2);
		p.open(1, 1);
		assertFalse(p.percolates());
		p.open(2, 1);
		assertTrue(p.percolates());		
	}

	@Test
	void TestPercolates10() {
		final Percolation p = new Percolation(2);
		p.open(2, 1);
		assertFalse(p.percolates());
		p.open(2, 2);
		assertTrue(p.percolates());		
	}

	@Test
	void TestPercolates11() {
		final Percolation p = new Percolation(2);
		p.open(1, 1);
		assertFalse(p.percolates());
		p.open(1, 2);
		assertFalse(p.percolates());		
		p.open(2, 2);
		assertTrue(p.percolates());		
	}
}
