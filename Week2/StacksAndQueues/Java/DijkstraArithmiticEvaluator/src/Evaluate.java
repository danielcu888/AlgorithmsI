import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.StdIn;

public class Evaluate {
	public static void main(String[] args) {
		
		final Stack<String> operators = new Stack<String>();
		final Stack<Double> operands = new Stack<Double>();
		
		while (!StdIn.isEmpty()) {
			final String s = StdIn.readString();
			if (s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/")) {
				operators.push(s);				
			} else if (s.equals("(")) {
				continue;
			} else if (s.equals(")")) {
				final String op = operators.pop();
				final double d1 = operands.pop();
				final double d2 = operands.pop();
				switch (op.charAt(0)) {
				case '+':					
					operands.push(d1+d2);
					break;
				case '-':
					operands.push(d1-d2);
					break;
				case '*':
					operands.push(d1*d2);
					break;
				case '/':
					if (d2 == 0.0) {
						throw new ArithmeticException("Divide by zero.");
					}
					operands.push(d1/d2);
					break;
				default:
					break;
				}
			} else {
				operands.push(Double.parseDouble(s));
			}
		}
		if (!operators.isEmpty() || operands.size() != 1) {
			throw new IllegalArgumentException("Malformed expression.");
		}
		
		System.out.println("Result: " + operands.pop());
	}
}
