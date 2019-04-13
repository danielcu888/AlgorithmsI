
public class FixedCapacityStackOfStrings {

		private final String[] a;
		private int head;
		
		public FixedCapacityStackOfStrings(int capacity) {
			this.a = new String[capacity];
			this.head = 0;
		}

		public boolean isEmpty() {
			return this.size() == 0;
		}

		public String pop() {
			if (this.isEmpty()) {
				throw new IllegalStateException("Cannot pop an empty FixedCapacityStackOfStrings.");
			}
			
			--this.head;
			final String s = this.a[this.head];
			this.a[this.head] = null;
			return s;
		}
				
		public void push(String s) {
			a[head++] = s;
		}
		
		public int size() {
			return this.head;
		}
}
