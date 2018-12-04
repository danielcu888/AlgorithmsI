
public class LineSegment {

	public final Point2D start;
	public final Point2D end;
	public final Vector2D dir;

	public LineSegment(Point2D start_, Point2D end_) {
		this.start = start_;
		this.end = end_;
		this.dir = new Vector2D(this.end.x - this.start.x, this.end.y - this.start.y);
	}
	
	public static double angle(LineSegment ls1, LineSegment ls2) {
		
		final double sp = Vector2D.vectorProduct(ls1.dir, ls2.dir);
		final double mag1 = ls1.dir.magnitude();
		final double mag2 = ls2.dir.magnitude();
		double ret = Math.asin(sp/mag1/mag2);
		
		return ret;
	}
			
} // ! class LineSegment
