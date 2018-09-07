import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.StdRandom;

public class PercolationStats {

	// perform trials independent experiments on an n-by-n grid
	public PercolationStats(int n, int trials) {
		if (n < 1) {
			throw new IllegalArgumentException("Invalid grid dimension!");
		}

		if (trials < 1) {
			throw new IllegalArgumentException("Invalid number of trials!");
		}

		m_num_trials = trials;
		m_N = n;
		m_threshold = new double[m_num_trials];
		
		final int num_sites = m_N*m_N;

		for (int trial_idx = 0; trial_idx < m_num_trials; ++trial_idx) {			
			
			Percolation p = new Percolation(m_N);
			
			while(!p.percolates()) {
				final int row = StdRandom.uniform(m_N)+1;
				final int col = StdRandom.uniform(m_N)+1;
				
				p.open(row, col);
			}
			
			final double threshold = (double)p.numberOfOpenSites()/(double)num_sites;
			m_threshold[trial_idx] = threshold;
		}
	}
	
	// sample mean of percolation threshold
	public double mean() {
		return StdStats.mean(m_threshold);
	}
	
	// sample standard deviation of percolation threshold
	public double stddev() {
		return StdStats.stddev(m_threshold);
	}
	
	// low  endpoint of 95% confidence interval
	public double confidenceLo() {
		return mean() - 1.96/Math.sqrt(m_num_trials);
	}
	
	// high endpoint of 95% confidence interval
	public double confidenceHi() {
		return mean() + 1.96/Math.sqrt(m_num_trials);
	}
	
	private double m_threshold[];
	private int m_num_trials;
	private int m_N;
	
	// takes two command-line arguments n and T,
	// performs T independent computational experiment
	// on an n-by-n grid, and
	// prints the sample mean,
	// sample standard deviation, and the 95% confidence
	// interval for the percolation threshold.
	public static void main(String[] args) {
		if (args.length != 2) {
			throw new IllegalArgumentException("Usage: <grid dim> <num trials>");
		}
		
		final int n = Integer.valueOf(args[0]);
		final int trials = Integer.valueOf(args[1]);
		
		PercolationStats stats = new PercolationStats(n, trials);
		
		StdOut.println("mean                    = " + stats.mean());
		StdOut.println("stddev                  = " + stats.stddev());
		StdOut.println("95% confidence interval = [" + stats.confidenceLo() + ", " + stats.confidenceHi() + "]");
	}
	
}