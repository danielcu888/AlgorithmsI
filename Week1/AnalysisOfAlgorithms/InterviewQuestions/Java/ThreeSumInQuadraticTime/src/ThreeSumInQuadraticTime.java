import java.util.Arrays;
import java.util.HashSet;

class Triplet {
	private final int a;
	private final int b;
	private final int c;
	private final String key;
	
	Triplet(int a_, int b_, int c_) {
		this.a = a_;
		this.b = b_;
		this.c = c_;
		this.key = Integer.toString(this.a) + " " +
			       Integer.toString(this.b) + " " +
			       Integer.toString(this.c);
	}
	
	@Override
	public String toString() {
		return this.key;
	}
	
	@Override
	public boolean equals(Object other) {
		if (other instanceof Triplet) {
			return this.key.compareTo(((Triplet)other).key) == 0;
		}

		return false;
	}
	
	@Override
	public int hashCode() {
		return this.key.hashCode();
	}
}

public class ThreeSumInQuadraticTime {

	private final int N;
	private final int[] a;
	private final HashSet<Triplet> triplets;
	
	public ThreeSumInQuadraticTime(int[] a_) {
		
		this.a = a_;
		this.N = a.length;
		this.triplets = new HashSet<Triplet>();
		
		Arrays.sort(this.a);
		
		for (int i = 0; i < this.N; ++i) {
			
			int leftIdx = 0;
			int rightIdx = N-1;
			
			while (leftIdx < rightIdx) {
				if (leftIdx == i) {
					++leftIdx;
				} else if (rightIdx == i) {
					--rightIdx;
				}
				
				final int sum = this.a[leftIdx] + this.a[rightIdx] + this.a[i];
				if (sum > 0) {
					--rightIdx;
				} else if (sum < 0) {
					++leftIdx;
				} else {
					final int[] tripletElements
						= {this.a[i], this.a[leftIdx], this.a[rightIdx]};
					Arrays.sort(tripletElements);					
					this.triplets.add(new Triplet( tripletElements[0]
		                                         , tripletElements[1]
		                                         , tripletElements[2]
		                                         )
							         );					
					--rightIdx;
				}
			}
		}
	}
	
	public Iterable<Triplet> triplets() {
		return this.triplets;
	}
}
