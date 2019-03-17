
public class SearchInBitonicArray {

	private final int[] a;
	private final int N;
	
	public SearchInBitonicArray(int[] a_) {
		this.a = a_;
		this.N = a.length;
	}
		
	private int findMaximumOrValue(int x) {
		int lo = 0;
		int hi = N-1;
		int mid = lo;
		while (lo < hi) {
			mid = (lo + hi)/2;
			final int midVal = a[mid];
			if (midVal == x) {
				return mid;
			}
			
			if (mid == lo) {
				if (midVal > a[lo+1]) {
					return lo;
				} else {
					++lo;
				}
			} else if (mid == hi) {
				if (midVal > a[hi-1]) {
					return hi;
				} else {
					--hi;
				}
			} else {
				if (a[mid-1] > midVal) {
					hi = mid-1;
				} else {
					lo = mid;
					
					if (a[mid+1] < midVal) {
						return mid;
					}
					
					lo = mid+1;
				}
			}	
		}
		
		return lo;
	}
	
	private int searchIncreasingSection(int x, int lo, int hi) {
		while (lo <= hi) {
			final int mid = (lo+hi)/2;
			final int midVal = a[mid];
			if (midVal == x) {
				return mid;
			} else if (x < midVal) {
				hi = mid-1;
			} else {
				lo = mid+1;
			}
		}
		
		return -1;
	}
	
	private int searchDecreasingSection(int x, int lo, int hi) {
		while (lo <= hi) {
			final int mid = (lo+hi)/2;
			final int midVal = a[mid];
			if (midVal == x) {
				return mid;
			} else if (x > midVal) {
				hi = mid-1;
			} else {
				lo = mid+1;
			}
		}
		
		return -1;
	}
	
	public int search(int x) {
		
		// Find maximum or if we find x whilst searching
		// for maximum, return its index.
		final int maxIdx = this.findMaximumOrValue(x);

		// Check if we found the sought value.
		if (x == a[maxIdx]) {
			return maxIdx;
		}
		
		// Search increasing and decreasing sections,
		// starting with the smallest.
		
		int idx = -1;
		
		if (maxIdx < N/2) {
			// Increasing section is smaller.	
			idx = this.searchIncreasingSection(x, 0, maxIdx-1);			
			if (idx != -1) {
				return idx;
			}
			
			idx = this.searchDecreasingSection(x, maxIdx+1, N-1);
			return idx;
		}

		// Decreasing section is smaller.
		idx = this.searchDecreasingSection(x, maxIdx+1, N-1);
		if (idx != -1) {
			return idx;
		}
		
		idx = this.searchIncreasingSection(x, 0, maxIdx-1);
		return idx;
	}
}
