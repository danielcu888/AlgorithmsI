import java.util.Collections;
import java.util.LinkedList;

public class ConvexHull {

	// The point collection for which a convex hull
	// is to be found.
	private LinkedList<ConvexHullPoint2D> points;

	// The reference point on the convex hull, taken to
	// be the first point in the returned solution.
	private ConvexHullPoint2D first;

	// The calculated convex hull.
	private LinkedList<ConvexHullPoint2D> convexHull;
	
	/**
	 * 1-parameter constructor.
	 * @param points_ The point collection for which a convex
	 *   hull is to be calculated.
	 */
	public ConvexHull(Point2D[] points_)
	{
		// Validate input:
		
		// 1. Check if at least one point has been supplied.
		if (points_ == null || points_.length == 0) {
			throw new IllegalArgumentException("No points supplied.");
		}
				
		// Check for trivial solutions
		if (points_.length < 3) {
			this.convexHull = new LinkedList<ConvexHullPoint2D>();
			for (Point2D p : points_) {
				this.convexHull.add(new ConvexHullPoint2D(p));
			}
		} else {
		
			// Initialize collection to store duplicate
			// references to input points.
			this.points = new LinkedList<ConvexHullPoint2D>();
	
			// Determine the Point2D with the largest x coordinate.
			double max_x = Double.MIN_VALUE;
			for (Point2D point : points_) {
				if (point.x > max_x) {
					this.points.addFirst(new ConvexHullPoint2D(point));
					max_x = point.x;
				} else {
					this.points.addLast(new ConvexHullPoint2D(point));
				}	
			}
			
			this.first = points.getFirst();
			this.points.removeFirst();
			
			// Calculate the angle between each point and this.first
			for (ConvexHullPoint2D chpoint : this.points)
			{
				chpoint.angle = this.ccwangle(chpoint);
			}
			
			// Sort the points based upon the angle with this.first relative to the y-axis
			Collections.sort(this.points, new ConvexHullPoint2DComparator());
			
			// Add first point to calculated convex hull:
			convexHull = new LinkedList<ConvexHullPoint2D>();
			convexHull.add(this.first);
					
			// Iterate through the sorted list of ConvexHullPoint2D's
			for (int i = 0; i < this.points.size(); ++i) {
				
				if (this.convexHull.size() == 1) {
					// We haven't any additional points. Simply add the next and continue.
					this.convexHull.addLast(this.points.get(i));
				} else {
					boolean valid = false;
					while (!valid && this.convexHull.size() > 1) {
						// Check the validity of the last point added using the next candidate point.
						LineSegment ls1 = new LineSegment( this.convexHull.get(this.convexHull.size()-2)
														 , this.convexHull.getLast()
														 );
						LineSegment ls2 = new LineSegment( this.convexHull.getLast(), this.points.get(i));
						final double vp = Vector2D.vectorProduct(ls1.dir, ls2.dir);
						if (vp > 0.0) {
							valid = true;
							this.convexHull.addLast(this.points.get(i));
						} else {
							this.convexHull.removeLast();
						}
					}
				}
			}
		}
	}
	
	public LinkedList<ConvexHullPoint2D> convexHull() {
		return this.convexHull;
	}
	
	private double ccwangle(ConvexHullPoint2D chp)
	{
		final LineSegment ls1 = new LineSegment(this.first, new Point2D(this.first.x, this.first.y+1.0));
		final LineSegment ls2 = new LineSegment(this.first, chp);
		
		double a = LineSegment.angle(ls1, ls2) * 180.0/Math.PI;
				
		return a;
	}
	
} // ! class ConvexHull
