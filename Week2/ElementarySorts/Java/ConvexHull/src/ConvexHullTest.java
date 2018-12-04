import static org.junit.jupiter.api.Assertions.*;

import java.util.LinkedList;

import org.junit.jupiter.api.Test;

class ConvexHullTest {
	/*
	@Test
	void ConvexHullOfSquareWithManyIgnoredPoints() {
		final Point2D[] points = { new Point2D(0.0, 0.0)
				                 , new Point2D(1.0, 0.0)
				                 , new Point2D(1.0, 1.0)
				                 , new Point2D(0.0, 1.0)
				                 , new Point2D(0.12, 0.45)
				                 , new Point2D(0.45, 0.56)
				                 , new Point2D(0.67, 0.12)
				                 //, new Point2D(0.88, 0.49)
				                 //, new Point2D(0.90, 0.19)
				                 //, new Point2D(0.44, 0.44)
				                 //, new Point2D(0.35, 0.5)
				                 //, new Point2D(0.78, 0.22)				                 
				                 };
		
		final ConvexHull ch = new ConvexHull(points);
		final LinkedList<ConvexHullPoint2D> actual = ch.convexHull();
		final Point2D[] expected = {points[1], points[2], points[3], points[0]};
		assertEquals(actual.size(), expected.length);
		
		for (int i = 0; i < actual.size(); ++i)
		{
			assertEquals(actual.get(i).x, expected[i].x);
			assertEquals(actual.get(i).y, expected[i].y);
		}
	}	
	*/
	
	@Test
	void ConvexHullOfSquareWithManyIgnoredPointsFails() {
		final Point2D[] points = { new Point2D(0.0, 0.0)
				                 , new Point2D(1.0, 0.0)
				                 , new Point2D(1.0, 1.0)
				                 , new Point2D(0.0, 1.0)
				                 , new Point2D(0.1, 0.4)
				                 , new Point2D(0.4, 0.5)
				                 , new Point2D(0.6, 0.1)
				                 };
		
		final ConvexHull ch = new ConvexHull(points);
		final LinkedList<ConvexHullPoint2D> actual = ch.convexHull();
		final Point2D[] expected = {points[1], points[2], points[3], points[0]};
		assertEquals(actual.size(), expected.length);
		
		for (int i = 0; i < actual.size(); ++i)
		{
			assertEquals(actual.get(i).x, expected[i].x);
			assertEquals(actual.get(i).y, expected[i].y);
		}
	}	
	
	@Test
	void ConvexHullOfSquareWithSingleIgnoredPoint() {
		final Point2D[] points = { new Point2D(0.0, 0.0)
				                 , new Point2D(1.0, 0.0)
				                 , new Point2D(0.75, 0.5)
				                 , new Point2D(1.0, 1.0)
				                 , new Point2D(0.0, 1.0)
				                 };
		
		final ConvexHull ch = new ConvexHull(points);
		final LinkedList<ConvexHullPoint2D> actual = ch.convexHull();
		final Point2D[] expected = {points[1], points[3], points[4], points[0]};
		
		for (int i = 0; i < actual.size(); ++i)
		{
			assertEquals(actual.get(i).x, expected[i].x);
			assertEquals(actual.get(i).y, expected[i].y);
		}
	}
	
	@Test
	void ConvexHullOfSquare() {
		final Point2D[] points = { new Point2D(0.0, 0.0)
				                 , new Point2D(1.0, 0.0)
				                 , new Point2D(1.0, 1.0)
				                 , new Point2D(0.0, 1.0)
				                 };
		
		final ConvexHull ch = new ConvexHull(points);
		final LinkedList<ConvexHullPoint2D> actual = ch.convexHull();
		final Point2D[] expected = {points[1], points[2], points[3], points[0]};
		
		for (int i = 0; i < actual.size(); ++i)
		{
			assertEquals(actual.get(i).x, expected[i].x);
			assertEquals(actual.get(i).y, expected[i].y);
		}
	}

	

}
