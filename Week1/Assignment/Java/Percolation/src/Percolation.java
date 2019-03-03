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
	
	private final int N;
	private final Site[][] grid;
	private int numOpenSites;
	private final Site topVirtualSite;
	private final WeightedQuickUnionUF uf1;
	private final Site bottomVirtualSite;
	private final WeightedQuickUnionUF uf2;
	
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
		
		// uf1 initially connects the top virtual Site with the Site's
		// of first row. It is always disconnected from the bottom
		// virtual Site. It is required to determine which open Site's
		// are full.
		this.topVirtualSite = new Site(0, 0);
		this.uf1 = new WeightedQuickUnionUF(n*n + 1);
		for (int colIdx = 0; colIdx < n; ++colIdx) {
			this.uf1.union(0, this.grid[0][colIdx].index());
		}
		
		// uf2 initially connects the top virtual Site to the
		// first row of Site's, and initially connects
		// the bottom virtual Site to the bottom row of Site's.
		// It is required to determine if the system is percolating.
		this.bottomVirtualSite = new Site(n, n);
		this.uf2 = new WeightedQuickUnionUF(n*n + 2);
		for (int colIdx = 0; colIdx < n; ++colIdx) {
			this.uf2.union(0, this.grid[0][colIdx].index());
		}
		for (int colIdx = 0; colIdx < n; ++colIdx) {
			this.uf2.union(n*n + 1, this.grid[n-1][colIdx].index());
		}
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
		
		int index() {
			return (this.rowIdx * N) + this.colIdx;
		}
		
		Site[] adjacentSites() {
			
			final Site[] adj = new Site[4];
			
			if (internalIndicesValid(this.rowIdx-1, this.colIdx-1)) {
				adj[0] = grid[this.rowIdx-1][this.colIdx-1];
			}
			
			if (internalIndicesValid(this.rowIdx, this.colIdx-1)) {
				adj[1] = grid[this.rowIdx][this.colIdx-1];
			}
			
			if (internalIndicesValid(this.rowIdx+1, this.colIdx)) {
				adj[0] = grid[this.rowIdx+1][this.colIdx];
			}

			if (internalIndicesValid(this.rowIdx+1, this.colIdx+1)) {
				adj[0] = grid[this.rowIdx+1][this.colIdx+1];
			}

			return adj;
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
	
	private boolean internalIndexValid(int internalIdx) {
		return internalIdx >= 0 && internalIdx < this.N;
	}
	
	private boolean indexValid(int idx) {
		return idx > 0 && idx <= this.N;
	}
	
	private boolean internalIndicesValid(int row, int col) {
		return this.internalIndexValid(row) &&
		       this.internalIndexValid(col);
	}
	
	private void validateInternalIndex(int internalIdx) {
		if (!this.internalIndexValid(internalIdx)) {
			throw new IllegalArgumentException(
					"Internal index " + internalIdx + " is out of range."
			);
		}			
	}
	
	private void validateInternalIndices(int row, int col) {
		this.validateInternalIndex(row);
		this.validateInternalIndex(col);
	}

	private void validateIndex(int idx) {
		if (!this.indexValid(idx)) {
			throw new IllegalArgumentException(
					"Index " + idx + " is out of range."
			);
		}			
	}
	
	private void validateIndices(int row, int col) {
		this.validateIndex(row);
		this.validateIndex(col);
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