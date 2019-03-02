import edu.princeton.cs.algs4.WeightedQuickUnionUF;

/**
 * A class to represent a square grid of sites that
 * can be modified to generate a percolating route
 * from the top to the bottom of the grid, and to
 * provide information on the percolating status
 * of the grid and the status of the individually
 * specified sites constituting it.
 */
public class Percolation {
	
	private int N;
	private Site[][] grid;
	private int numOpenSites;
	
	/**
	 * Create an n-by-n grid, with all sites blocked.
	 * @param n The dimension of the grid to be
	 *        constructed.
	 */
	public Percolation(int n) {
		if (n <= 0) {
			throw new IllegalArgumentException(
					"Grid dimension " + n + " is out of range."
			);
		}
		
		this.N = n;
		this.grid = new Site[n][n];
		
		for (int rowIdx = 0; rowIdx < n; ++rowIdx) {
			this.grid[rowIdx] = new Site[n];
		}
		
		for (int rowIdx = 0; rowIdx < n; ++rowIdx) {
			for (int colIdx = 0; colIdx < n; ++colIdx) {
				this.grid[rowIdx][colIdx] = new Site(rowIdx, colIdx);
			}
		}
		
		this.numOpenSites = 0;
	}

	private enum SiteStatus {
		BLOCKED,
		OPEN,
		FULL
	}
	
	private class Site {
		int rowIdx;
		int colIdx;
		SiteStatus status;

		boolean isBlocked() {
			return this.status == SiteStatus.BLOCKED;
		}
		
		boolean isOpen() {
			return this.status == SiteStatus.OPEN;
		}

		boolean isFull() {
			return this.status == SiteStatus.FULL;
		}
		
		Site(int rowIdx_, int colIdx_) {
			this.rowIdx = rowIdx_;
			this.colIdx = colIdx_;
			this.status = SiteStatus.BLOCKED;
		}
	}

	private int idxToInternalIdx(int idx) {
		return idx-1;
	}
	
	private int internalIdxToIdx(int internalIdx) {
		return internalIdx+1;
	}
	
	private void validateIndex(int idx) {
		if (!(idx > 0 && idx <= this.N)) {
			throw new IllegalArgumentException(
					"Index " + idx + " is out of range."
			);
		}			
	}

	private void validateInternalIndex(int internalIdx) {
		if (!(internalIdx >= 0 && internalIdx < this.N)) {
			throw new IllegalArgumentException(
					"Internal index " + internalIdx + " is out of range."
			);
		}			
	}
	
	private void validateIndices(int row, int col) {
		this.validateIndex(row);
		this.validateIndex(col);
	}

	private void validateInternalIndices(int row, int col) {
		this.validateInternalIndex(row);
		this.validateInternalIndex(col);
	}
	
	/**
	 * Open site (row, col) if it is not open already.
	 * @param row The row of the site to be opened (>= 1).
	 * @param col The column of the site to be opened (>= 1).
	 */
	public void open(int row, int col) {
		// TODO - implement
		throw new UnsupportedOperationException(
				"Percolation.open(int,int) is unimplemented."
		);
	}
	
	/**
	 * Return if the specified site is open.
	 * @param row The row of the specified site (>= 1).
	 * @param col The column of the specified site (>= 1).
	 * @return If the specified site is open.
	 */
	public boolean isOpen(int row, int col) {
		this.validateIndices(row, col);
		return this.grid[this.idxToInternalIdx(row)][this.idxToInternalIdx(col)].isOpen();
	}

	/**
	 * Return if the specified site is full.
	 * @param row The row of the specified site (>= 1).
	 * @param col The column of the specified site (>= 1).
	 * @return If the specified site is full.
	 */
	public boolean isFull(int row, int col) {
		this.validateIndices(row, col);
		return this.grid[this.idxToInternalIdx(row)][this.idxToInternalIdx(col)].isFull();
	}
	
	/**
	 * Return the number of open sites.
	 * @return The number of open sites.
	 */
	public int numberOfOpenSites() {
		return this.numOpenSites;
	}
	
	/**
	 * Return if the system percolates.
	 * @return If the system percolates.
	 */
	public boolean percolates() {
		// TODO - implement
		throw new UnsupportedOperationException(
				"Percolation.percolates() is unimplemented."
		);						
	}
}