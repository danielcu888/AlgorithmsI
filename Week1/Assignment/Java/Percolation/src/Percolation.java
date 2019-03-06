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

    private static final int TOP_VIRTUAL_SITE_INTERNAL_INDEX = 0;

    private final int n;
    private final Site[][] grid;
    private int numOpenSites;
    private final WeightedQuickUnionUF uf1;
    private final WeightedQuickUnionUF uf2;
    private final int bottomVirtualSiteInternalIndex;
    
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
        
        this.n = n;
        this.bottomVirtualSiteInternalIndex = this.n*this.n+1;
        
        this.grid = new Site[this.n][this.n];
        
        for (int rowIdx = 0; rowIdx < this.n; ++rowIdx) {
            this.grid[rowIdx] = new Site[this.n];
        }
        
        for (int rowIdx = 0; rowIdx < this.n; ++rowIdx) {
            for (int colIdx = 0; colIdx < this.n; ++colIdx) {
                this.grid[rowIdx][colIdx] = new Site(rowIdx, colIdx);
            }
        }
        
        this.numOpenSites = 0;
        
        // uf1 initially connects the top virtual Site with the Site's
        // of first row. It is always disconnected from the bottom
        // virtual Site. It is required to determine which open Site's
        // are full.
        this.uf1 = new WeightedQuickUnionUF(this.n*this.n + 1);
        for (int colIdx = 0; colIdx < this.n; ++colIdx) {
            this.uf1.union(0, this.grid[0][colIdx].index());
        }
        
        // uf2 initially connects the top virtual Site to the
        // first row of Site's, and initially connects
        // the bottom virtual Site to the bottom row of Site's.
        // It is required to determine if the system is percolating.
        this.uf2 = new WeightedQuickUnionUF(this.n*this.n + 2);
        for (int colIdx = 0; colIdx < this.n; ++colIdx) {
            this.uf2.union(TOP_VIRTUAL_SITE_INTERNAL_INDEX,
                           this.grid[0][colIdx].index()
                          );
        }
        for (int colIdx = 0; colIdx < this.n; ++colIdx) {
            this.uf2.union(bottomVirtualSiteInternalIndex,
                           this.grid[this.n-1][colIdx].index()
                          );
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

        Site(int rowIdx, int colIdx) {
            this.rowIdx = rowIdx;
            this.colIdx = colIdx;
            this.status = SiteStatus.BLOCKED;
        }        
        
        boolean isBlocked() {
            return this.status == SiteStatus.BLOCKED;
        }
        
        boolean isOpen() {
            return !this.isBlocked();
        }

        boolean isFull() {
            return this.status == SiteStatus.FULL;
        }
        
        int index() {
            return (this.rowIdx * n) + this.colIdx;
        }
    }
    
    private Site[] adjacentSites(int row, int col) {
        
        final Site[] adj = new Site[4];
        
        // NORTH
        if (internalIndicesValid(row-1, col)) {
            adj[0] = grid[row-1][col];
        }
        
        // SOUTH
        if (internalIndicesValid(row+1, col)) {
            adj[1] = grid[row+1][col];
        }
        
        // WEST
        if (internalIndicesValid(row, col-1)) {
            adj[2] = grid[row][col-1];
        }

        // EAST
        if (internalIndicesValid(row, col+1)) {
            adj[3] = grid[row][col+1];
        }

        return adj;
    }
    
    private void fillAdjacentSites(int row, int col) {
        for (Site adj : this.adjacentSites(row, col)) {
            if (adj == null) {
                continue;
            }
            
            if (adj.isFull()) {
                // Adjacent is already FULL, skip.
                continue;
            } else if (adj.isOpen()) {
                // Adjacent is open, hence fill and recursively
                // process its adjacent Sites.
                adj.status = SiteStatus.FULL;
                this.fillAdjacentSites(adj.rowIdx, adj.colIdx);
            }
        }
    }
    
    private int idxToInternalIdx(int idx) {
        return idx-1;
    }
        
    private boolean internalIndexValid(int internalIdx) {
        return internalIdx >= 0 && internalIdx < this.n;
    }
    
    private boolean indexValid(int idx) {
        return idx > 0 && idx <= this.n;
    }
    
    private boolean internalIndicesValid(int row, int col) {
        return this.internalIndexValid(row) &&
               this.internalIndexValid(col);
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
        this.validateIndices(row, col);
        
        // Retrieve internal indices of target Site.
        final int internalRow = this.idxToInternalIdx(row);
        final int internalCol = this.idxToInternalIdx(col);
        
        // Retrieve target Site, s.
        final Site s = this.grid[internalRow][internalCol];
        
        if (s.isOpen()) {
            // Site already open, do nothing.
            return;
        }
        
        // Update status of s to OPEN.
        s.status = SiteStatus.OPEN;
        ++this.numOpenSites;

        // Obtain s's adjacent Sites.
        final Site[] adjs = this.adjacentSites(s.rowIdx, s.colIdx);
                
        // Connect s with its open adjacent Sites.
        // (If s is in the top/bottom row, we already
        // have connected it to the top/bottom virtual
        // Sites in uf1 and uf2 as required.)
        for (Site adj : adjs) {
            if (adj != null && adj.isOpen()) {
                uf1.union(s.index(), adj.index());
                uf2.union(s.index(), adj.index());
            }
        }
        
        // Determine if s should be filled by checking
        // if it is connected with the top virtual Site.
        if (uf1.connected(TOP_VIRTUAL_SITE_INTERNAL_INDEX, s.index())) {
            s.status = SiteStatus.FULL;
            
            // Iterate through s's adjacent Sites, fill
            // any that are open and unfilled, and then
            // recursively do the same for their adjacent
            // Sites.        	
            for (Site adj : adjs) {
                if (adj != null && adj.isOpen() && !adj.isFull()) {
                    adj.status = SiteStatus.FULL;
                    
                    // Recursively process adjacent Sites of adj.
                    this.fillAdjacentSites(adj.rowIdx, adj.colIdx);
                }
            }
        }        
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
        return uf2.connected(TOP_VIRTUAL_SITE_INTERNAL_INDEX,
                             bottomVirtualSiteInternalIndex
                            );
    }
    
    
    @Override
    public String toString() {
        StringBuffer s = new StringBuffer();
        for (int row = 0; row < this.n; ++row) {
            for (int col = 0; col < this.n; ++col) {
                switch (this.grid[row][col].status) {
                case BLOCKED:
                    s.append("B");
                    break;
                case OPEN:
                    s.append("O");                    
                    break;
                case FULL:
                    s.append("F");                    
                    break;
                default:
                    throw new IllegalStateException("Unknown SiteStatus for row: " + row + ", col: " + col);
                }
                s.append(" ");
            }
            s.append("\n");
        }
        return s.toString();
    }
    
}