import static org.junit.jupiter.api.Assertions.*;

import java.util.Scanner;

import org.junit.jupiter.api.Test;

class UnionFindWithSpecificCanonicalElementTest {

	@Test
	void test()
	{
		final Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		final UnionFindWithSpecificCanonicalElement uf = new UnionFindWithSpecificCanonicalElement(N);
		
		int p;
		int q;
		String s;
		
		for (int i = 0; i < N; ++i)
		{
			s = sc.next();

			if (s.equals("c"))
			{
				p = sc.nextInt();
				q = sc.nextInt();

				if (uf.connected(p, q))
				{
					System.out.println(p + " and " + q + " are connected.");
				}
				else
				{
					System.out.println(p + " and " + q + " are not connected.");					
				}
			}
			else if (s.equals("u"))
			{
				p = sc.nextInt();
				q = sc.nextInt();

				uf.union(p, q);
			}
			else if (s.equals("f"))
			{
				p = sc.nextInt();
				
				System.out.println("The largest element in component containing " + p + " is " + uf.find(p));
			}
			
			for(int j = 0; j < N; ++j)
			{
				System.out.print(uf.id(j) + " ");
			}
			System.out.println();
			for(int j = 0; j < N; ++j)
			{
				System.out.print(uf.depth(j) + " ");
			}
			System.out.println();
			for(int j = 0; j < N; ++j)
			{
				System.out.print(uf.find(j) + " ");
			}
			System.out.println();			
		}
		
		sc.close();
	}		
}
