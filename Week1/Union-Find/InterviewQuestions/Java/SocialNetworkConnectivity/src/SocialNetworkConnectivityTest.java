import static org.junit.jupiter.api.Assertions.*;

import java.io.File;
import java.io.FileNotFoundException;

import org.junit.jupiter.api.Test;

class SocialNetworkConnectivityTest {

	@Test
	void test() throws FileNotFoundException {
		final File logFile = new File("resources/logFile");
		final SocialNetworkConnectivity snc = new SocialNetworkConnectivity(logFile);
		assertEquals(snc.getConnectionTime(), "20-01-1970");
	}
}
