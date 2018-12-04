import java.util.Comparator;

public class ConvexHullPoint2DComparator implements Comparator<ConvexHullPoint2D> {

	@Override
	public int compare(ConvexHullPoint2D chp1, ConvexHullPoint2D chp2) {
		return chp1.compareTo(chp2);
	}

}
