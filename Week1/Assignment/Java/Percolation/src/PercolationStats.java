import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

/**
 * A class to perform independent trial percolation
 * experiments on an n-by-n grid, and provide the
 * resulting statistics.
 *
 */
public class PercolationStats {
	
	private double[] threshold;
	
	/** 
	 * Perform a specified number of independent trial
	 * experiments on an n-by-n grid.
	 * @param n The specified grid dimension.
	 * @param trials The specified number of trials.
	 */
	public PercolationStats(int n, int trials) {
		if (n < 1) {
			throw new IllegalArgumentException(
					"Grid dimension " + n + " must be > 0."
			);
		}
		
		if (trials < 1) {
			throw new IllegalArgumentException(
					"Number of trials " + trials + " must be > 0."
			);			
		}
		
		this.threshold = new double[trials];
		
		Percolation p;
		for (int trial = 0; trial < trials; ++trial) {
			
			p = new Percolation(n);
			
			while (!p.percolates()) {
				
				final int row = StdRandom.uniform(n);
				final int col = StdRandom.uniform(n);
				
				p.open(row+1, col+1);
			}
			
			this.threshold[trial] = (double)p.numberOfOpenSites()/(double)(n*n);
		}
	}
	
	/**
	 * Return The sample mean of the percolation threshold.
	 * @return The sample mean of the percolation threshold.
	 */
	public double mean() {
		return StdStats.mean(this.threshold);
	}
	
	/**
	 * Return the sample standard deviation of percolation
	 * threshold.
	 * @return The sample standard deviation of percolation
	 *         threshold.
	 */
	public double stddev() {
		return StdStats.stddev(this.threshold);
	}
	
	/**
	 * Return the lower bound of the 95% confidence interval.
	 * @return The lower bound of the 95% confidence interval.
	 */
	public double confidenceLo() {
		return this.mean() - 1.96/Math.sqrt(this.threshold.length);
	}

	/**
	 * Return the upper bound of the 95% confidence interval.
	 * @return The upper bound of the 95% confidence interval.
	 */	
	public double confidenceHi() {
		return this.mean() + 1.96/Math.sqrt(this.threshold.length);
	}
	
    /** Takes two command-line arguments n and T,                            
     * performs T independent computational experiment                      
     * on an n-by-n grid, and prints the sample mean,                                              
     * sample standard deviation, and the 95% confidence                    
     * interval for the percolation threshold.
     */
    public static void main(String[] args) {
		
		if (args.length != 2) {
			throw new IllegalArgumentException(
					"Usage: <Grid dim> <#trials>"
			);
		}
		
		final int n = Integer.valueOf(args[0]);
		final int trials = Integer.valueOf(args[1]);
		
		final PercolationStats stats = new PercolationStats(n, trials);
		
		StdOut.println("mean                    = " + stats.mean());
		StdOut.println("stddev                  = " + stats.stddev());
		StdOut.println( "95% confidence interval = ["
		              + stats.confidenceLo() + ", "
				      + stats.confidenceHi() + "]"
				      );
    }
}