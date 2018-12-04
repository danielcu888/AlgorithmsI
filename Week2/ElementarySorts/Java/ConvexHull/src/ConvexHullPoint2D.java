
public class ConvexHullPoint2D extends Point2D implements Comparable<ConvexHullPoint2D> {

	public double angle;
	
	public ConvexHullPoint2D(double x_, double y_) {
		super(x_, y_);
		angle = 0.0;
	}

	public ConvexHullPoint2D(Point2D point_) {
		super(point_.x, point_.y);
		angle = 0.0;
	}

	@Override
	public int compareTo(ConvexHullPoint2D p) {

		if (this.angle > p.angle) {
			return +1;
		}
		
		if (this.angle < p.angle) {
			return -1;
		}
		
		return 0;
	}
} // ! class ConvexHullPoint2D
