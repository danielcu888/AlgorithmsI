import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class SocialNetworkConnectivity {
	
	private String connectionTime = "";
	private boolean connectionTimeFound = false;
	
	private class Entry {
		
		String name1;
		String name2;
		String timeStamp;
		
		Entry(String s) {
			final Scanner sc = new Scanner(s);
			
			try {
				if (!sc.hasNext()) {
					throw new NoSuchElementException("Invalid Entry: name #1 not found.");
				}
				this.name1 = sc.next();
				
				if (!sc.hasNext()) {
					throw new NoSuchElementException("Invalid Entry: name #2 not found.");				
				}			
				this.name2 = sc.next();
	
				if (!sc.hasNext()) {
					throw new NoSuchElementException("Invalid Entry: Timestamp not found.");				
				}			
				this.timeStamp = sc.next();
			} catch (NoSuchElementException exc) {
				sc.close();
			} finally {
				sc.close();
			}
		}		
	}
		
	public SocialNetworkConnectivity(File logFile) 
		throws FileNotFoundException {
		
		if (!logFile.exists()) {
			throw new FileNotFoundException(logFile.getName() + " does not exist.");
		}
				
		final Scanner sc = new Scanner(logFile);
		try {
			int numComponents = Integer.parseInt(sc.nextLine());
			final int numEntries = Integer.parseInt(sc.nextLine());
			
			final WeightedQuickUnionwithPathCompression uf
				= new WeightedQuickUnionwithPathCompression(numComponents);
			
			final HashMap<String, Integer> map = new HashMap<String, Integer>();
			
			for (int i = 0; i < numEntries; ++i) {
				
				final String s = sc.nextLine();
				final Entry entry = new Entry(s);
				
				if (!map.containsKey(entry.name1)) {
					map.put(entry.name1, map.size());
				}
				
				final int p = map.get(entry.name1);
	
				if (!map.containsKey(entry.name2)) {
					map.put(entry.name2, map.size());
				}
				
				final int q = map.get(entry.name2);
				
				if (!uf.connected(p, q)) {
					uf.join(p, q);
					--numComponents;
				}
				
				if (numComponents == 1) {
					this.connectionTime = entry.timeStamp;
					this.connectionTimeFound = true;
					break;
				}
			}
		} catch (NoSuchElementException exc) {
			System.out.println("Improperly formatted log file.");
		} finally {
			sc.close();
		}
	}
	
	public boolean connected() {
		return this.connectionTimeFound;
	}
	
	public String getConnectionTime() {
		if (!this.connected()) {
			throw new IllegalStateException("Connection time not found.");
		}
		
		return this.connectionTime;
	}
}
