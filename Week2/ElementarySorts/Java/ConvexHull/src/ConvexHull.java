/**
 * Import declarations.
 */
import java.util.Collections;
import java.util.LinkedList;

/**
 * A class to calculate the convex hull of a specified
 * set of 2D point's.
 */
public class ConvexHull {

	/**
	 * The point collection for which a convex hull is to be found.
	 */
	private LinkedList<ConvexHullPoint2D> points;

	/**
	 * The reference point on the convex hull, taken to
	 * be the first point in the returned solution. 
	 */
	private ConvexHullPoint2D first;

	/**
	 * The calculated convex hull.
	 */
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
			
			// All the points constitute the convex hull.
			this.convexHull = new LinkedList<ConvexHullPoint2D>();
			for (Point2D p : points_) {
				this.convexHull.add(new ConvexHullPoint2D(p));
			}
		} else {
		
			// Initialize collection to store duplicate
			// references to input points so that they may
			// be sorted.
			this.points = new LinkedList<ConvexHullPoint2D>();
	
			// Determine the point with the largest x-coordinate.
			// This extreme point must reside on the convex hull,
			// and other points reside to the left of it meaning
			// that they subtend an angle of [0,pi] with the
			// point, relative to the y-axis.
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
			
			// Remove this.first from the points since we
			// already know its in the convex hull, so add
			// it.
			this.points.removeFirst();
			convexHull = new LinkedList<ConvexHullPoint2D>();
			convexHull.add(this.first);

			// Calculate the angle subtended by each point with
			// this.first, relative to the y-axis. ccw denotes
			// positive angles.
			for (ConvexHullPoint2D chpoint : this.points)
			{
				chpoint.angle = this.ccwangle(chpoint);
			}
			
			// Sort the ConvexHullPoint2D's using their angle field's.
			Collections.sort(this.points, new ConvexHullPoint2DComparator());
								
			// Iterate through the sorted list of ConvexHullPoint2D's
			for (int i = 0; i < this.points.size(); ++i) {
				if (this.convexHull.size() == 1) {
					
					// Simply add the current point and continue,
					// since we haven't added any valid points
					// to the convex hull other than the first.
					this.convexHull.addLast(this.points.get(i));
				} else {
					// We have at least two points in the convex hull.
					
					// Check the validity of the last point added
					// to the convex hull. If valid, add the
					// next candidate point to it, otherwise
					// remove the last point and repeat until
					// we find a valid point or the convex hull
					// has only one point.
					boolean valid = false;
					while (!valid && this.convexHull.size() > 1) {
						
						// Check validity of last point in convex hull,
						// using the next candidate point to be added
						// to it.
						
						// 1. Form line segment using last point and previous
						// point in convex hull.
						final LineSegment ls1 =
								new LineSegment( this.convexHull.get(this.convexHull.size()-2)
											   , this.convexHull.getLast()
											   );
						
						// 2. Form line segment from last point and next
						// candidate point in convex hull.
						final LineSegment ls2 =
								new LineSegment( this.convexHull.getLast()
										       , this.points.get(i)
										       );
						
						// 3. Calculate the vector product ls1 x ls2. If positive,
						// we have a counter clockwise turn. This is because
						// if the angle between adjacent segment's were greater
						// than pi, the end point of the latter segment would
						// have already been processed since it would have
						// a smaller angle field.
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
	
	/**
	 * Returns the convex hull.
	 * @return The convex hull.
	 */
	public LinkedList<ConvexHullPoint2D> convexHull() {
		return this.convexHull;
	}
	
	/**
	 * Returns the angle between the specified LineSegment's.
	 * The result will be in radians, in the range [0,pi].
	 * @param ls1 The first LineSegment.
	 * @param ls2 The second LineSegment.
	 * @return The angle between the specified LineSegment's.
	 */
	private static double angle(LineSegment ls1, LineSegment ls2) {

		final double mag1 = ls1.dir.magnitude();
		if (!(mag1 > 0.0)) {
			return 0.0;
		}
		
		final double mag2 = ls2.dir.magnitude();
		if (!(mag2 > 0.0)) {
			return 0.0;
		}
		
		return Math.acos(Vector2D.scalarProduct(ls1.dir, ls2.dir)/mag1/mag2);		
	}

	/**
	 * Returns the counter clockwise angle subtended by the
	 * specified point, via the first point of the convex
	 * hull, relative to the y-axis. The result is provided
	 * in radians. A negative result implies a clockwise
	 * angle.
	 * @param chp The specified point.
	 * @return The counter clockwise angle subtended by the
	 * specified point, via the first point of the convex
	 * hull, relative to the y-axis.
	 */
	private double ccwangle(ConvexHullPoint2D chp)
	{
		final LineSegment ls1 =
				new LineSegment( this.first
						       , new Point2D(this.first.x, this.first.y+1.0)
						       );
		final LineSegment ls2 = new LineSegment(this.first, chp);
		
		return angle(ls1, ls2) * 180.0/Math.PI;
	}
	
} // ! class ConvexHull
