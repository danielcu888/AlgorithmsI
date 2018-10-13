import static org.junit.jupiter.api.Assertions.*;

import java.util.Scanner;

import org.junit.jupiter.api.Test;

class SuccessorWithDeleteTest {

	@Test
	void test() throws Exception {
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		SuccessorWithDelete suc = new SuccessorWithDelete(N);
		
		while(sc.hasNext())
		{
			final String s = sc.next();
			final int x = sc.nextInt();
			if (s.equals("r"))
			{
				suc.remove(x);
			}
			else if(s.equals("s"))
			{
				System.out.println("The successor of " + x + " is " + suc.successor(x));
			}
			
			for(int i = 0; i < N; ++i)
			{
				System.out.print(suc.successor(i) + " ");
			}
			System.out.println();
		}
		
		sc.close();
	}

}
