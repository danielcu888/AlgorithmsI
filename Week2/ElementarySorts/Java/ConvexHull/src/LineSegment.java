
public class LineSegment {

	public final Point2D start;
	public final Point2D end;
	public final Vector2D dir;

	public LineSegment(Point2D start_, Point2D end_) {
		this.start = start_;
		this.end = end_;
		this.dir = new Vector2D(this.end.x - this.start.x, this.end.y - this.start.y);
	}
			
} // ! class LineSegment
