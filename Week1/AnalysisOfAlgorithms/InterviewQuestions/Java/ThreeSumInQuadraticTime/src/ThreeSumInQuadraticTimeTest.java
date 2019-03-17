import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class ThreeSumInQuadraticTimeTest {

	@Test
	void test1() {
		final int[] a = {-6, -4, -2, 0, 2, 4, 6};
		final ThreeSumInQuadraticTime ts = new ThreeSumInQuadraticTime(a);
		final StringBuilder sb = new StringBuilder();
		for (Triplet t : ts.triplets()) {
			sb.append(t);
			sb.append(", ");
		}
		assertEquals( sb.toString()
				    , "-4 -2 6, " +
		              "-6 0 6, "  +
				      "-6 2 4, "  +
		              "-4 0 4, "  +
				      "-2 0 2, " 
				    );
	}

}
