import static org.junit.jupiter.api.Assertions.*;

import java.util.Scanner;

import org.junit.jupiter.api.Test;

class StackOfStringsTest {

	@Test
	void test() {
		final StackOfStrings stack = new StackOfStrings();
		final String tobe = "to be or not to - be - - that - - - is";
		final StringBuilder sb = new StringBuilder();
		final Scanner sc = new Scanner(tobe);
		while (sc.hasNext()) {
			final String s = sc.next();
			if (s.equals("-")) {
				sb.append(stack.pop() + " ");
			} else {
				stack.push(s);
			}
		}
		sc.close();
		
		final String actual = sb.toString();
		final String expected = "to be not that or be ";
		assertEquals(expected, actual);
	}
}
