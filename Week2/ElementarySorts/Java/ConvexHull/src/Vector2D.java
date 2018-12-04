
public class Vector2D {
	
	public final double x;
	public final double y;
	
	public Vector2D(double x_, double y_)
	{
		this.x = x_;
		this.y = y_;
	}
	
	public static double scalarProduct(Vector2D A, Vector2D B)
	{
		return A.x*B.x + A.y*B.y;
	}
	
	public static double vectorProduct(Vector2D A, Vector2D B) {
		return A.x*B.y - A.y*B.x;
	}
	
	public double magnitude()
	{
		return Math.sqrt(this.x*this.x + this.y*this.y);
	}
}
