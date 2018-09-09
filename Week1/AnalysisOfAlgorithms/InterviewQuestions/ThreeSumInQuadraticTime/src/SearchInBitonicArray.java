public class SearchInBitonicArray {
	
	private static int findMax(int[] ba) {
		
		if (ba.length >= 3) {
			int lo = 0;
			int hi = ba.length-1;
			
			while (lo <= hi) {
				
				final int mid = (lo+hi)/2;
				
				final int lv = ba[mid-1];
				final int rv = ba[mid+1];
				final int v = ba[mid];
				
				if (v > lv) {				
					if (v > rv) {
						return mid;
					} else {
						// solution is in right half
						lo = mid+1;
					}
				} else {
					// solution is in left half
					hi = mid-1;
				}
			}
		}

		throw new IllegalArgumentException("Array is nit bitonic.");
	}
	
	private static int binarySearch(int[] a, int x, int lo, int hi) {
		
		while (lo <= hi) {
			
			final int mid = (lo+hi)/2;
			final int v = a[mid];
			
			if (x == v) {
				return mid;
			}
			
			if (v < x) {
				// solution in right half
				lo = mid+1;
			} else {
				// solution in left half
				hi = mid-1;
			}
		}
		
		return -1;
	}
	
	public static boolean search(int[] ba, int x) {
		
		// Find partition element.
		final int max_idx = SearchInBitonicArray.findMax(ba);

		// Search left partition for x.
		int idx = SearchInBitonicArray.binarySearch(ba, x, 0, max_idx);
		if (idx != -1) {
			System.out.println("Solution: " + idx);
			return true;
		}
		
		// Search right partition for x.
		idx = SearchInBitonicArray.binarySearch(ba, x, max_idx, ba.length-1);
		if (idx != -1) {
			System.out.println("Solution: " + idx);
			return true;
		} 
		
		// x not found.
		System.out.println("No solution found!");
		return false;
	}
	
	public static void main(String[] args) {
		final int[] ba = {0,2,3,4,5,6,7,8,10,8,6,5,4,3,2};
		SearchInBitonicArray.search(ba, 6);
	}
}
