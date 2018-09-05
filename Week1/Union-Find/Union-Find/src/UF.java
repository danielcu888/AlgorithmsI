
public interface UF {
	
	/**
	 * Add connection between two specified nodes.
	 * @param p - first node
	 * @param q - other node.
	 */
	void union(int p, int q);
	
	/**
	 * Determine if specified two nodes are connected.
	 * @param p - first node.
	 * @param q - other node.
	 * @return if p and q are connected.
	 */
	boolean connected(int p, int q);
	
	/**
	 * Return the connected component id of the specified
	 * node.
	 * @param p the node id.
	 * @return the connected component id of p.
	 */
	int find(int p);
	
	/**
	 * Return the number of connected components.
	 * @return The number of connected components.
	 */
	int count();
}
