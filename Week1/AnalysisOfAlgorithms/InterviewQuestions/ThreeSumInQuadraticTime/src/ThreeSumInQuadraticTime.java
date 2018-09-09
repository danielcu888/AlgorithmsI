import java.util.Arrays;

public class ThreeSumInQuadraticTime {

	static class Triplet {
		Triplet(int a, int b, int c) {
			this.a = a;
			this.b = b;
			this.c = c;
		}
		
		int a;
		int b;
		int c;
	}
	
	public static Triplet ThreeSum(int[] arr) {
		
		final int N = arr.length;
		
		// Sort input array.
		Arrays.sort(arr);
		
		// Loop over target sum's (negated) until we find a triplet zero-sum.
		
		// Initialize.
		int sum = Integer.MAX_VALUE; // Arbitrary, just needs to be non-zero.
		int a = 0; // Arbitrary
		int b = 0; // Arbitrary
		int c = 0; // Arbitrary
		for (int i = 0; i < N-2 && sum != 0; ++i) {
		
			// Set candidate solution.
			a = i;
			b = i+1;
			c = N-1;
			
			while (b < c) {				
				sum = arr[a] + arr[b] + arr[c];
				if (sum == 0) {
					// Found solution.
					break;
				}
				
				if (sum < 0) {
					// sum too low, increment b.
					++b;
				} else {
					// sum too high, decrement c.
					--c;
				}
			}			
		}
		
		return sum == 0 ? new Triplet(a, b, c) : null;
	}

	public static void main(String[] args) {
		
		final int[] arr = {-20, -17, -15, -12, -4, 0, 1, 2, 32};
		final Triplet t = ThreeSumInQuadraticTime.ThreeSum(arr);
		if (t == null) {
			System.out.println("No solution.");
		} else {
			System.out.println("a: " + t.a + ", b: " + t.b + ", t.c: " + t.c);
		}
	}
	
	
	
}