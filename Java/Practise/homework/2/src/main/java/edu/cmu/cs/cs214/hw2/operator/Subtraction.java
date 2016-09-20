package edu.cmu.cs.cs214.hw2.operator;

/**
 * A class to calculate subtraction.
 * @author Landy
 *
 */
public class Subtraction implements BinaryOperator {

	@Override
	public double apply(double arg1, double arg2) {
		double result = arg1 - arg2;
		return result;
	}
	@Override
	public String toString(){
		return "-";
	};
	
}
