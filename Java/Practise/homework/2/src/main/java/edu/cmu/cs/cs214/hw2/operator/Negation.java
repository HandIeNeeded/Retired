package edu.cmu.cs.cs214.hw2.operator;

/**
 * A class to calculate negation.
 * @author Landy
 *
 */
public class Negation implements UnaryOperator {

	@Override
	public double apply(double arg) {
		double result = - arg;
		return result;
	}
	@Override
	public String toString(){
		return "neg";
	};
	
}