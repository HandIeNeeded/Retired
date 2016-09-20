package edu.cmu.cs.cs214.hw2.operator;

/**
 * A class to calculate absolute value.
 * @author Landy
 *
 */
public class AbsoluteValue implements UnaryOperator {

	@Override
	public double apply(double arg) {
		double result = Math.abs(arg);
		return result;
	}
	@Override
	public String toString(){
		return "abs";
	};
	
}