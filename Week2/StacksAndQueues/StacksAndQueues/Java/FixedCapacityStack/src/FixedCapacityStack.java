public class FixedCapacityStack<Item> {

		private final Item[] a;
		private int head;
		
		public FixedCapacityStack(int capacity) {
			this.a = (Item[])new Object[capacity];
			this.head = 0;
		}

		public boolean isEmpty() {
			return this.size() == 0;
		}

		public Item pop() {
			if (this.isEmpty()) {
				throw new IllegalStateException("Cannot pop an empty FixedCapacityStack.");
			}
			
			--this.head;
			final Item item = this.a[this.head];
			this.a[this.head] = null;
			return item;
		}
				
		public void push(Item item) {
			a[head++] = item;
		}
		
		public int size() {
			return this.head;
		}
}
