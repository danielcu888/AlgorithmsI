import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

class Site
{
	public Site(int row_idx, int col_idx, int idx) {
		m_open = false;
		m_row_idx = row_idx;
		m_col_idx = col_idx;
		m_idx = idx; 
	}
	
	public void open() {
		m_open = true;
	}
	
	public boolean isOpen() {
		return m_open;
	}
	
	public int row_idx() {
		return m_row_idx;
	}

	public int idx() {
		return m_idx;
	}

	public int col_idx() {
		return m_col_idx;
	}

	private boolean m_open;
	private int m_row_idx;
	private int m_col_idx;
	private int m_idx;
}

public class Percolation {

	// create n-by-n grid, with all sites blocked
	public Percolation(int n)                
	{
		m_N = n;
		m_num_open = 0;
		m_sites = new Site[m_N][m_N];
		int site_idx = 0;
		m_top_vsite = new Site(-1, -1, site_idx++);
		m_uf_full = new WeightedQuickUnionUF(1+m_N*m_N);
		m_uf_perc = new WeightedQuickUnionUF(2+m_N*m_N);
		
		for(int row_idx = 0; row_idx < m_N; ++row_idx) {
			for(int col_idx = 0; col_idx < m_N; ++col_idx) {
				m_sites[row_idx][col_idx] = new Site(row_idx, col_idx, site_idx++);
			}
		}
		m_bottom_vsite = new Site(-1, -1, site_idx);
	}
	
	// open site (row, col) if it is not open already
	public void open(int row, int col)
	{
		validate_coords(row, col);

		final int row_idx = idx(row);
		final int col_idx = idx(col);
				
		Site s = m_sites[row_idx][col_idx];
		if (!s.isOpen()) {
			s.open();
			++m_num_open;
			
			// union open site with its nearest open neighbours
			Site neighbours[] = nearest_neighbours(s);
			for(int i = 0; i < neighbours.length; ++i) {
				if (neighbours[i] != null && neighbours[i].isOpen()) {
					m_uf_full.union(s.idx(), neighbours[i].idx());
					m_uf_perc.union(s.idx(), neighbours[i].idx());
				}
			}
			
			// union with top virtual site if in top row
			if(row_idx == 0) {
				m_uf_full.union(s.idx(), m_top_vsite.idx());
				m_uf_perc.union(s.idx(), m_top_vsite.idx());
			}

			// union with bottom virtual site if in bottom row
			// (NOT FOR m_uf_full).
			if(row_idx == m_N-1) {
				m_uf_perc.union(s.idx(), m_bottom_vsite.idx());
			}			
		}	
	}
	
	// is site (row, col) open?
	public boolean isOpen(int row, int col) {
		validate_coords(row, col);
		return m_sites[idx(row)][idx(col)].isOpen();
	}
	
	// is site (row, col) full?
	public boolean isFull(int row, int col) {
		validate_coords(row, col);
		Site s = m_sites[idx(row)][idx(col)];
		
		return s.isOpen() && m_uf_full.connected(s.idx(), m_top_vsite.idx());
	}
	
	// number of open sites
	public int numberOfOpenSites() {
		return m_num_open;
	}
	
	// does the system percolate?
	public boolean percolates() {
		return m_uf_perc.connected(this.m_top_vsite.idx(), this.m_bottom_vsite.idx());
	}
		
	private boolean valid_idx(int idx) {
		return idx >= 0 && idx < m_N;
	}
	
	private boolean valid_indices(int row_idx, int col_idx) {
		return valid_idx(row_idx) && valid_idx(col_idx);
	}
	
	private boolean valid_coords(int row, int col) {
		if (row-1 < 0 || row -1 > m_N - 1) {
			return false;
		}
		
		if (col-1 < 0 || col-1 > m_N - 1) {
			return false;
		}
		
		return true;
	}
	
	private void validate_coords(int row, int col) {
		if(!valid_coords(row, col)) {
			throw new IllegalArgumentException("Invalid grid coordinates!");
		}
	}
	
	private int idx(int i)
	{
		return i-1;
	}
	
	private Site[] nearest_neighbours(Site s) {
		Site neighbours[] = new Site[4];
		
		final int row_idx = s.row_idx();
		final int col_idx = s.col_idx();
		
		int num_neighbours = 0;
		
		// North
		if (valid_indices(row_idx-1, col_idx)) {
			neighbours[num_neighbours++] = m_sites[row_idx-1][col_idx];
		}
		
		// South
		if (valid_indices(row_idx+1, col_idx)) {
			neighbours[num_neighbours++] = m_sites[row_idx+1][col_idx];
		}
		
		// East
		if (valid_indices(row_idx, col_idx+1)) {
			neighbours[num_neighbours++] = m_sites[row_idx][col_idx+1];
		}
		
		// West
		if (valid_indices(row_idx, col_idx-1)) {
			neighbours[num_neighbours++] = m_sites[row_idx][col_idx-1];
		}
		
		return neighbours;
	}
	
	private int m_N;
	private Site m_sites[][];
	private Site m_top_vsite;
	private Site m_bottom_vsite;
	private WeightedQuickUnionUF m_uf_full;
	private WeightedQuickUnionUF m_uf_perc;
	private int m_num_open;
	
	// test client (optional)
	public static void main(String[] args) {
		Percolation perc = new Percolation(2);
		StdOut.println(perc.numberOfOpenSites());
		StdOut.println(perc.percolates());
		StdOut.println(perc.isFull(1, 1));
		StdOut.println(perc.isFull(1, 2));
		StdOut.println(perc.isFull(2, 1));
		StdOut.println(perc.isFull(2, 2));
		perc.open(1, 1);
		StdOut.println(perc.numberOfOpenSites());
		StdOut.println(perc.percolates());
		StdOut.println(perc.isFull(1, 1));
		StdOut.println(perc.isFull(1, 2));
		StdOut.println(perc.isFull(2, 1));
		StdOut.println(perc.isFull(2, 2));
		perc.open(1, 2);
		StdOut.println(perc.numberOfOpenSites());
		StdOut.println(perc.percolates());
		StdOut.println(perc.isFull(1, 1));
		StdOut.println(perc.isFull(1, 2));
		StdOut.println(perc.isFull(2, 1));
		StdOut.println(perc.isFull(2, 2));
		perc.open(2, 2);
		StdOut.println(perc.numberOfOpenSites());
		StdOut.println(perc.percolates());
		StdOut.println(perc.isFull(1, 1));
		StdOut.println(perc.isFull(1, 2));
		StdOut.println(perc.isFull(2, 1));
		StdOut.println(perc.isFull(2, 2));
	}
}